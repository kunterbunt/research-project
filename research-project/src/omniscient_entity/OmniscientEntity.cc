//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#include <vector>

#include <omnetpp.h>
#include <LteCommon.h>
#include <LteBinder.h>
#include <LteAmc.h>
#include <LteMacEnb.h>
#include <LteFeedback.h>
// For mobility.
#include <L3AddressResolver.h>
#include <ModuleAccess.h>
#include <IMobility.h>
// For SINR.
#include <LteRealisticChannelModel.h>
#include <LteFeedbackPkt.h>
#include <LteAirFrame.h>
// For feedback computation <-> CQI computation.
#include <LteFeedbackComputationRealistic.h>

/**
 * Derived class exposes otherwise hidden deployer_ member pointer.
 */
class ExposedLteMacEnb : public LteMacEnb {
public:
    LteDeployer* getDeployer() {
        return LteMacEnb::deployer_;
    }
};

/**
 * Derived class exposes otherwise hidden CQI computation.
 */
class ExposedFeedbackComputer : public LteFeedbackComputationRealistic {
public:
    Cqi getCqi(TxMode txmode, double snr) {
        return LteFeedbackComputationRealistic::getCqi(txmode, snr);
    }
};

/**
 * Implements an omniscient network entity that provides access to the following domains:
 *  Current physical device locations
 *  Current device speed
 *  SINR values for UE-UE and UE-BS links in any direction or power level (periodically saved)
 *  Channel Quality Indicators both as reported by the nodes and computed (periodically saved)
 */
class OmniscientEntity : public omnetpp::cSimpleModule {
public:
    OmniscientEntity()
        : mBinder(getBinder()), // getBinder() provided LteCommon.h
          mSnapshotMsg(new cMessage("OmniscientEnity::snapshot")),
          mConfigMsg(new cMessage("OmniscientEntity::config")),
          mUpdateInterval(0.01) // Will be properly set to provided .NED value in initialize()
    {}

    virtual ~OmniscientEntity() {
        if (mMemory != nullptr)
            delete mMemory;
        if (mFeedbackComputer != nullptr)
            delete mFeedbackComputer;
    }

    /**
     * Queries the AMC module for reported CQI value.
     * @param device The device whose CQI you want.
     * @param band The collection of resource blocks you're interested in.
     * @param direction The tranmsission direction, see Direction::x enum.
     * @param antenna See Remote::x enum.
     * @param transmissionMode The transmission mode, see TxMode::x enum.
     * @return The CQI of the device <-> eNodeB channel.
     */
    Cqi getReportedCqi(const MacNodeId device, const uint band, const Direction direction, const Remote antenna, const TxMode transmissionMode) const {
        if (mAmc == nullptr)
            throw cRuntimeError("OmniscientEntity::getCqi called before the AMC was registered with the OmniscientEntity. You should call this method after final configuration is done.");
        return mAmc->getFeedback(device, antenna, transmissionMode, direction).getCqi(0, band);
    }

    /**
     * Queries the AMC module for reported CQI value.
     * @param device The ID of the device whose CQI you are interested in.
     * @param band A band is a logical collection of resource blocks. If numBands==numRbs then you are asking for the x-th resource block's CQI.
     * @param direction Probably either Direction::UL or Direction::DL.
     * @return The channel quality indicator for the channel from this device to the eNodeB in the specified direction and band.
     */
    Cqi getReportedCqi(const MacNodeId device, const uint band, const Direction direction) const {
        return getReportedCqi(device, band, direction, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0);
    }

    /**
     * Queries the AMC module for reported CQI value.
     * @param device1 One side of the D2D transmission.
     * @param device2 The other side of the transmission.
     * @param band The collection of resource blocks you're interested in.
     * @param antenna See Remote::x enum.
     * @param transmissionMode The transmission mode, see TxMode::x enum.
     * @return The CQI of the direct link between device1 and device2.
     */
    Cqi getReportedCqi(const MacNodeId device1, const MacNodeId device2, const uint band, const Remote antenna, const TxMode transmissionMode) const {
        if (mAmc == nullptr)
            throw cRuntimeError("OmniscientEntity::getCqi called before the AMC was registered. You should call this method after final configuration is done.");
        return mAmc->getFeedbackD2D(device1, antenna, transmissionMode, device2).getCqi(0, band);
    }

    /**
     * Convenience method that sets antenna as Remote::MACRO and transmission mode as TxMode::SINGLE_ANTENNA_PORT0
     * @param device1 The ID of one of the D2D pair's devices.
     * @param device2 The ID of the other one.
     * @param band A band is a logical collection of resource blocks. If numBands==numRbs then you are asking for the xth resource block's CQI.
     * @return The channel quality indicator for the channel between the two devices on the band.
     */
    Cqi getReportedCqi(const MacNodeId device1, const MacNodeId device2, const uint band) const {
        return getReportedCqi(device1, device2, band, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0);
    }

    /**
     * Computes the current CQI for the device<->eNodeB link.
     * @param device Device ID.
     * @param transmissionMode See TxMode::x enum.
     * @return device<->eNodeB Channel Quality Indicator.
     */
    Cqi getCqi(const MacNodeId device, const TxMode transmissionMode) const {
        return mFeedbackComputer->getCqi(transmissionMode, getMean(getSINR(device)));
    }

    /**
     * Computes the current CQI for the device<->eNodeB link. Assumes TxMode::SINGLE_ANTENNA_PORT0 transmission mode.
     * @param device Device ID.
     * @return device<->eNodeB Channel Quality Indicator.
     */
    Cqi getCqi(const MacNodeId device) const {
        return getCqi(device, TxMode::SINGLE_ANTENNA_PORT0);
    }

    /**
     * Computes the current CQI for the from<->to link.
     * @param from One side's device ID.
     * @param to Other side's device ID.
     * @param transmissionMode See TxMode::x enum.
     * @return from<->to Channel Quality Indicator.
     */
    Cqi getCqi(const MacNodeId from, const MacNodeId to, const TxMode transmissionMode) const {
        return mFeedbackComputer->getCqi(transmissionMode, getMean(getSINR(from, to)));
    }

    /**
     * Computes the current CQI for the from<->to link. Assumes TxMode::SINGLE_ANTENNA_PORT0 transmission mode.
     * @param from One side's device ID.
     * @param to Other side's device ID.
     * @return from<->to Channel Quality Indicator.
     */
    Cqi getCqi(const MacNodeId from, const MacNodeId to) const {
        return getCqi(from, to, TxMode::SINGLE_ANTENNA_PORT0);
    }

    /**
     * @param from Node ID of one side of the link.
     * @param to Node ID of the other link side.
     * @param simTime The simulation time you're interested in. Due to choice of the resolution it might not be exactly accurate. Won't work for times in the future.
     * @return The saved CQI.
     */
    Cqi getCqi(const MacNodeId from, const MacNodeId to, double simTime) const {
        double sinr = getMean(mMemory->get(simTime, from, to));
        return mFeedbackComputer->getCqi(TxMode::SINGLE_ANTENNA_PORT0, sinr);
    }

    /**
     * @return The CQI as computetd for the given SINR and TxMode::SINGLE_ANTENNA_PORT0.
     */
    Cqi getCqiFromSinr(double sinr) {
        return mFeedbackComputer->getCqi(TxMode::SINGLE_ANTENNA_PORT0, sinr);
    }

    /**
     * @param device The device's node ID.
     * @return The IMobility that describes this node's mobility. See inet/src/inet/mobility/contract/IMobility.h for implementation.
     */
    IMobility* getMobility(const MacNodeId device) const {
        cModule *host = nullptr;
        try {
            UeInfo* ueInfo = getDeviceInfo(device);
            host = ueInfo->ue;
        } catch (const cRuntimeError &e) {
            // Getting the mobility of an eNodeB?
            EnbInfo* enbInfo = getENodeBInfo(device);
            host = enbInfo->eNodeB;
        }
        if (host == nullptr)
            throw cRuntimeError("OmniscientEntity::getMobility couldn't find the device's cModule!");
        IMobility* mobilityModule = check_and_cast<IMobility*>(host->getSubmodule("mobility"));
        if (mobilityModule == nullptr)
            throw cRuntimeError("OmniscientEntity::getMobility couldn't find a mobility module!");
        return mobilityModule;
    }

    /**
     * @param device The device's node ID.
     * @return The device's physical position. Coord.{x,y,z} are publicly available.
     */
    Coord getPosition(const MacNodeId device) const {
      return getMobility(device)->getCurrentPosition();
    }

    /**
     * @param device The device's node ID.
     * @return The device's physical current speed. Coord.{x,y,z} are publicly available.
     */
    Coord getSpeed(const MacNodeId device) const {
        return getMobility(device)->getCurrentSpeed();
    }

    /**
     * @param from The D2D transmitter's ID.
     * @param to The D2D receiver's ID.
     * @param transmissionPower The power level that the node would transmit with.
     * @param direction The transmission direction (see Direction::x enum).
     * @return The SINR value for each band.
     */
    std::vector<double> getSINR(const MacNodeId from, const MacNodeId to, const double transmissionPower, const Direction direction) const {
        UserControlInfo* uinfo = new UserControlInfo();
        uinfo->setFrameType(FEEDBACKPKT);
        uinfo->setIsCorruptible(false);

        uinfo->setSourceId(from);
        uinfo->setD2dTxPeerId(from);

        uinfo->setD2dRxPeerId(to);
        uinfo->setDestId(to);

        uinfo->setDirection(direction);
        uinfo->setTxPower(transmissionPower);
        uinfo->setD2dTxPower(transmissionPower);
        uinfo->setCoord(getPosition(from));

        LteAirFrame* frame = new LteAirFrame("feedback_pkt");
        std::vector<double> SINRs = mChannelModel->getSINR_D2D(frame, uinfo, to, getPosition(to), mENodeBId);
        delete uinfo;
        delete frame;
        return SINRs;
    }

    /**
     * @param from The D2D transmitter's ID.
     * @param to The D2D receiver's ID.
     * @return The SINR value for each band for the D2D channel between the nodes, if it transmits at the transmission power set in the .ini.
     */
    std::vector<double> getSINR(const MacNodeId from, const MacNodeId to) const {
        // Get a pointer to the device's module.
        std::string modulePath = getDeviceInfo(from)->ue->getFullPath() + ".nic.phy";
        cModule *mod = getModuleByPath(modulePath.c_str());
        // From the module we can access its transmission power.
        return getSINR(from, to, mod->par("d2dTxPower").doubleValue(), Direction::D2D);
    }

    /**
     * @param id The node in question's ID.
     * @param transmissionPower The power level that the node would transmit with.
     * @param direction The transmission direction (see Direction::x enum).
     * @return The SINR value for each band for the uplink channel from the node to the eNodeB.
     */
    std::vector<double> getSINR(const MacNodeId id, const double transmissionPower, const Direction direction) const {
        UserControlInfo* uinfo = new UserControlInfo();
        uinfo->setFrameType(FEEDBACKPKT);
        uinfo->setIsCorruptible(false);

        uinfo->setSourceId(id);
        // I am pretty sure that there's a mistake in the simuLTE source code.
        // It incorrectly sets the eNodeB's position for its calculations. I am here setting the UE's position as the eNodeB's,
        // so that the distance is correct which is all that matters. (or maybe this is how you're supposed to do it...)
        uinfo->setCoord(mENodeBPosition);
        uinfo->setDestId(mENodeBId);

        uinfo->setDirection(direction);
        uinfo->setTxPower(transmissionPower);

        LteAirFrame* frame = new LteAirFrame("feedback_pkt");
        std::vector<double> SINRs = mChannelModel->getSINR(frame, uinfo);
        delete uinfo;
        delete frame;
        return SINRs;
    }

    /**
     * @param id The node in question's ID.
     * @return The SINR value for each band for the uplink channel from the node to the eNodeB, if it transmits at the transmission power set in the .ini.
     */
    std::vector<double> getSINR(const MacNodeId id) const {
        // Get a pointer to the device's module.
        std::string modulePath = getDeviceInfo(id)->ue->getFullPath() + ".nic.phy";
        cModule *mod = getModuleByPath(modulePath.c_str());
        // From the module we can access its transmission power.
        return getSINR(id, mod->par("ueTxPower"), Direction::UL);
    }

    /**
     * @return The saved SINR value.
     */
    double getSINR(const MacNodeId from, const MacNodeId to, double simTime) {
        return getMean(mMemory->get(simTime, from, to));
    }

//    std::vector<double> getSINR(const MacNodeId from, const MacNodeId to, double time, const double transmissionPower, const Direction direction) const {
//        // Compute current value.
//        if (time >= NOW) {
//            // UE <-> eNodeB channel.
//            if (to == mENodeBId) {
//                UserControlInfo* uinfo = new UserControlInfo();
//                uinfo->setFrameType(FEEDBACKPKT);
//                uinfo->setIsCorruptible(false);
//
//                uinfo->setSourceId(id);
//                // I am pretty sure that there's a mistake in the simuLTE source code.
//                // It incorrectly sets the eNodeB's position for its calculations. I am here setting the UE's position as the eNodeB's,
//                // so that the distance is correct which is all that matters. (or maybe this is how you're supposed to do it...)
//                uinfo->setCoord(mENodeBPosition);
//                uinfo->setDestId(mENodeBId);
//
//                uinfo->setDirection(direction);
//                uinfo->setTxPower(transmissionPower);
//
//                LteAirFrame* frame = new LteAirFrame("feedback_pkt");
//                std::vector<double> SINRs = mChannelModel->getSINR(frame, uinfo);
//                delete uinfo;
//                delete frame;
//                return SINRs;
//            // UE <-> UE channel.
//            } else {
//                UserControlInfo* uinfo = new UserControlInfo();
//                uinfo->setFrameType(FEEDBACKPKT);
//                uinfo->setIsCorruptible(false);
//
//                uinfo->setSourceId(from);
//                uinfo->setD2dTxPeerId(from);
//
//                uinfo->setD2dRxPeerId(to);
//                uinfo->setDestId(to);
//
//                uinfo->setDirection(direction);
//                uinfo->setTxPower(transmissionPower);
//                uinfo->setD2dTxPower(transmissionPower);
//                uinfo->setCoord(getPosition(from));
//
//                LteAirFrame* frame = new LteAirFrame("feedback_pkt");
//                std::vector<double> SINRs = mChannelModel->getSINR_D2D(frame, uinfo, to, getPosition(to), mENodeBId);
//                delete uinfo;
//                delete frame;
//                return SINRs;
//            }
//        // Retrieve from memory.
//        } else {
//
//        }
//    }

    double getMean(const std::vector<double> values) const {
        double sum = 0.0;
        for (size_t i = 0; i < values.size(); i++)
            sum += values.at(i);
        return (sum / ((double) values.size()));
    }

protected:
    void initialize() override {
        EV << "OmniscientEntity::initialize" << std::endl;
        // This entity is being initialized before a lot of other entities, like the eNodeBs and UEs, are deployed.
        // That's why final configuration needs to take place a bit later.
        mConfigTimepoint = par("configTimepoint").doubleValue();
        mUpdateInterval = par("updateInterval").doubleValue();
        mMemory = new Memory(mUpdateInterval, 15.0, this);
        scheduleAt(mConfigTimepoint, mConfigMsg);
        // Schedule first update.
        scheduleAt(mConfigTimepoint + mUpdateInterval, mSnapshotMsg);
    }

    /**
     * Final configuration at some time point when other network devices are deployed and accessible.
     */
    void configure() {
        EV << "OmniscientEntity::configure" << std::endl;
        // Get the eNodeB.
        std::vector<EnbInfo*>* enbInfo = getEnbInfo();
        if (enbInfo->size() == 0)
            throw cRuntimeError("OmniscientEntity::configure can't get AMC pointer because I couldn't find an eNodeB!");
        // -> its ID -> the node -> cast to the eNodeB class
        mENodeBId = enbInfo->at(0)->id;
        ExposedLteMacEnb *eNodeB = (ExposedLteMacEnb*) getMacByMacNodeId(mENodeBId);
        // -> get the AMC.
        mAmc = eNodeB->getAmc();
        if (mAmc == nullptr)
            throw cRuntimeError("OmniscientEntity::configure couldn't find an AMC.");
        else
            EV << "\tFound AMC." << endl;

        // Remember eNodeB position.
        mENodeBPosition = getPosition(mENodeBId);

        // Get deployer pointer.
        mDeployer = eNodeB->getDeployer();
        if (mDeployer == nullptr)
            throw cRuntimeError("OmniscientEntity::configure couldn't find the deployer.");
        EV << "\tFound deployer." << endl;

        // Print info about all network devices.
        // UEs...
        std::vector<UeInfo*>* ueInfo = getUeInfo();
        EV << "\tThere are " << ueInfo->size() << " UEs in the network: " << std::endl;
        for (size_t i = 0; i < ueInfo->size(); i++)
            EV << "\t\t#" << i << ": has MacNodeId " << ueInfo->at(i)->id << " and OmnetID " << getId(ueInfo->at(i)->id) << std::endl;
        // eNodeB...
        std::vector<EnbInfo*>* EnbInfo = getEnbInfo();
        EV << "\tThere are " << EnbInfo->size() << " EnBs in the network: " << std::endl;
        for (size_t i = 0; i < EnbInfo->size(); i++)
            EV << "\t\t#" << i << ": has MacNodeId " << EnbInfo->at(i)->id << " and OmnetID " << getId(ueInfo->at(i)->id) << std::endl;

        // Get a pointer to the channel model.
        mChannelModel = ueInfo->at(0)->realChan;
        if (mChannelModel != nullptr)
            EV << "\tFound channel model." << std::endl;
        else
            throw cRuntimeError("OmniscientEntity::configure couldn't find a channel model.");

        // Construct a feedback computer.
        mFeedbackComputer = getFeedbackComputation();
        if (mFeedbackComputer == nullptr)
            throw cRuntimeError("OmniscientEntity::configure couldn't construct the feedback computer.");
        else
            EV << "\tConstructed feedback computer." << endl;

        // Testing...
        EV << "SINR_D2D=" << getMean(getSINR(ueInfo->at(0)->id, ueInfo->at(1)->id)) << " SINR=" << getMean(getSINR(ueInfo->at(0)->id)) << std::endl;
        EV << "CQI_reported=" << getReportedCqi(ueInfo->at(0)->id, 0, Direction::UL) << " CQI_calculated=" << getCqi(ueInfo->at(0)->id) << std::endl;
        EV << "CQI_D2D_reported=" << getReportedCqi(ueInfo->at(0)->id, ueInfo->at(1)->id, 0) << " CQI_D2D_calculated=" << getCqi(ueInfo->at(0)->id, ueInfo->at(1)->id) << std::endl;
    }

    void handleMessage(cMessage *msg) {
        EV << "OmniscientEntity::handleMessage" << std::endl;
        if (msg == mSnapshotMsg)
            snapshot();
        else if (msg == mConfigMsg)
            configure();
    }

    /**
     * Takes snapshot of network statistics and puts them into memory.
     */
    void snapshot() {
        EV << "OmniscientEntity::snapshot" << std::endl;
        std::vector<UeInfo*>* ueInfo = getUeInfo();
        // For all UEs...
        for (size_t i = 0; i < ueInfo->size(); i++) {
            MacNodeId from = ueInfo->at(i)->id;
            // Find SINR to the eNodeB (cellular uplink).
            std::vector<double> sinrs_eNodeB = getSINR(from);
            mMemory->put(simTime().dbl(), from, mENodeBId, sinrs_eNodeB);
            // And for all other UEs...
            for (size_t j = 0; j < ueInfo->size(); j++) {
                MacNodeId to = ueInfo->at(j)->id;
                // Ignore link to current node.
                if (from == to)
                    continue;
                // Calculate and save the current SINR for the D2D link.
                std::vector<double> sinrs = getSINR(from, to);
                mMemory->put(simTime().dbl(), from, to, sinrs);
            }
        }

//        EV << "SINR=" << mMemory->get(simTime().dbl(), ueInfo->at(0)->id, ueInfo->at(1)->id) << std::endl;

        // Print current memory.
        EV << mMemory->toString() << std::endl;

        // Schedule next snapshot.
        scheduleAt(simTime() + mUpdateInterval, mSnapshotMsg);
    }

    std::vector<EnbInfo*>* getEnbInfo() const {
        return mBinder->getEnbList();
    }
    std::vector<UeInfo*>* getUeInfo() const {
        return mBinder->getUeList();
    }

    OmnetId getId(const MacNodeId id) const {
        return mBinder->getOmnetId(id);
    }
    MacNodeId getId(const OmnetId id) const {
        return mBinder->getMacNodeIdFromOmnetId(id);
    }

    UeInfo* getDeviceInfo(const MacNodeId device) const {
      std::vector<UeInfo*>* ueInfo = getUeInfo();
      for (size_t i = 0; i < ueInfo->size(); i++) {
        UeInfo* currentInfo = ueInfo->at(i);
        if (currentInfo->id == device)
          return currentInfo;
      }
      throw cRuntimeError("OmniscientEntity::getDeviceInfo can't find the requested device ID!");
    }

    EnbInfo* getENodeBInfo(MacNodeId id) const {
      std::vector<EnbInfo*>* enbInfo = getEnbInfo();
      for (size_t i = 0; i < enbInfo->size(); i++) {
          EnbInfo* currentInfo = enbInfo->at(i);
        if (currentInfo->id == id)
          return currentInfo;
      }
      throw cRuntimeError("OmniscientEntity::getENodeBInfo can't find the requested eNodeB ID!");
    }

    ExposedFeedbackComputer* getFeedbackComputation() const {
        // We're construction the feedback computer from a description.
        // There's REAL and DUMMY. We want REAL.
        std::string feedbackName = "REAL";
        // The four needed parameters will be supplied in this map.
        std::map<std::string, cMsgPar> parameterMap;

        // Each one must be specified in the OmniscientEntity.ned.
        // @TODO Parse the channel.xml instead because that's the values we want.
        cMsgPar targetBler("targetBler");
        targetBler.setDoubleValue(par("targetBler"));
        parameterMap["targetBler"] = targetBler;

        cMsgPar lambdaMinTh("lambdaMinTh");
        lambdaMinTh.setDoubleValue(par("lambdaMinTh"));
        parameterMap["lambdaMinTh"] = lambdaMinTh;

        cMsgPar lambdaMaxTh("lambdaMaxTh");
        lambdaMaxTh.setDoubleValue(par("lambdaMaxTh"));
        parameterMap["lambdaMaxTh"] = lambdaMaxTh;

        cMsgPar lambdaRatioTh("lambdaRatioTh");
        lambdaRatioTh.setDoubleValue(par("lambdaRatioTh"));
        parameterMap["lambdaRatioTh"] = lambdaRatioTh;

        // Taken from simulte/src/stack/phy/layer/LtePhyEnb.cc line 415.
        return ((ExposedFeedbackComputer*) new LteFeedbackComputationRealistic(
                targetBler, mDeployer->getLambda(), lambdaMinTh, lambdaMaxTh,
                lambdaRatioTh, mDeployer->getNumBands()));
    }

    /**
     * @param vec Vector holding values.
     * @param name Name for values, e.g. UE_SINR
     * @return e.g. UE_SINR[0]=12 UE_SINR[1]=42
     */
    std::string vectorToString(const std::vector<double>& vec, const std::string& name) const {
        std::string description = "";
        for (size_t i = 0; i < vec.size(); i++)
            description += name + "[" + std::to_string(i) + "]=" + std::to_string(vec.at(i)) + " ";
        return description;
    }

private:
    LteBinder   *mBinder = nullptr;
    cMessage    *mSnapshotMsg = nullptr,
                *mConfigMsg = nullptr;
    double      mUpdateInterval,
                mConfigTimepoint;
    LteAmc      *mAmc = nullptr;
    LteRealisticChannelModel    *mChannelModel = nullptr;
    MacNodeId mENodeBId;
    ExposedFeedbackComputer *mFeedbackComputer = nullptr;
    LteDeployer *mDeployer = nullptr;
    Coord mENodeBPosition;

    /**
     * The OmniscientEntity's memory holds information values that update periodically.
     */
    class Memory {
    public:
        Memory(double resolution, double maxSimTime, OmniscientEntity *parent)
                : mResolution(resolution), mMaxSimTime(maxSimTime), mParent(parent),
                  mTimepoints((unsigned int) (maxSimTime / resolution)) {}
        virtual ~Memory() {}

        /**
         * @param Point in time when the SINR was computed.
         * @param sinr SINR value.
         */
        void put(const double time, const MacNodeId from, const MacNodeId to, const std::vector<double> sinrs) {
            double position = (time / mResolution);
            if (position >= mTimepoints.size()) {
                std::string err = "OmniscientEntity::Memory::put Position " + std::to_string(position) + " > maxPosition " + std::to_string(mTimepoints.size()) + "\n";
                throw cRuntimeError(err.c_str());
            }
//            EV_STATICCONTEXT;
//            EV << "OmniscientEntity::Memory::put(time=" << time << ", from=" << from << ", to=" << to << ", sinr=" << sinr << ") pos=" << position << std::endl;
            Timepoint *timepoint = &(mTimepoints.at(position));
            timepoint->put(from, to, sinrs);
        }

        /**
         * @return A <to, sinr> map holding the values of all SINRs to all devices.
         */
        const std::map<MacNodeId, std::vector<double>>* get(const double time, const MacNodeId from) const {
            double position = time / mResolution;
            if (position >= mTimepoints.size()) {
                std::string err = "OmniscientEntity::Memory::get Position " + std::to_string(position) + " > maxPosition " + std::to_string(mTimepoints.size()) + "\n";
                throw cRuntimeError(err.c_str());
            }
//            EV_STATICCONTEXT;
//            EV << "OmniscientEntity::Memory::get(" << time << ", " << from << ")" << std::endl;
            const Timepoint* timepoint = &(mTimepoints.at(position));
            const std::map<MacNodeId, std::vector<double>>* map = nullptr;
            try {
                map = timepoint->get(from);
            } catch (const cRuntimeError& err) {
                throw; // Forward exception.
            }

            return map;
        }

        std::vector<double> get(const double time, const MacNodeId from, const MacNodeId to) const {
//            EV_STATICCONTEXT;
//            EV << "OmniscientEntity::Memory::get(" << time << ", " << from << ", " << to << ")" << std::endl;
            const std::map<MacNodeId, std::vector<double>>* sinrMap = nullptr;
            try {
                sinrMap = Memory::get(time, from);
            } catch (const cRuntimeError& err) {
                throw;
            }
            return sinrMap->at(to);
        }

        /**
         * @return A string representation of all saved values up to the current moment in time.
         */
        std::string toString() {
            std::string description = "";
            std::vector<UeInfo*>* ueInfo = mParent->getUeInfo();
            for (SimTime time(mParent->mConfigTimepoint + mParent->mUpdateInterval); time <= NOW; time += mResolution) {
                description += "Time " + std::to_string(time.dbl()) + ":\n";
                // Go through all channel starting points...
                for (size_t i = 0; i < ueInfo->size(); i++) {
                    MacNodeId from = ueInfo->at(i)->id;
                    // Find statistics to eNodeB.
                    std::vector<double> sinrs_eNodeB;
                    try {
                        sinrs_eNodeB = get(time.dbl(), from, mParent->mENodeBId);
                    } catch (const cRuntimeError& err) {
                        throw cRuntimeError(std::string("OmniscientEntity::Memory::toString() encountered an exception when it tried to fetch a saved entry: " + std::string(err.what())).c_str());
                    }
                    description += "UE[" + std::to_string(from) + "]\n\t\t-> eNodeB CQI=" + std::to_string(mParent->getCqiFromSinr(mParent->getMean(sinrs_eNodeB))) + " " + mParent->vectorToString(sinrs_eNodeB, "SINR") + "\n";
                    // And do the same for all UE end points...
                    for (size_t j = 0; j < ueInfo->size(); j++) {
                        MacNodeId to = ueInfo->at(j)->id;
                        if (from == to)
                            continue;
                        std::vector<double> sinrs;
                        try {
                            sinrs = get(time.dbl(), from, to);
                        } catch (const cRuntimeError& err) {
                            throw cRuntimeError(std::string("OmniscientEntity::Memory::toString() encountered an exception when it tried to fetch a saved entry: " + std::string(err.what())).c_str());
                        }
                        description += "\t\t-> UE[" + std::to_string(to) + "] CQI=" + std::to_string(mParent->getCqiFromSinr(mParent->getMean(sinrs))) + " " + mParent->vectorToString(sinrs, "SINR") + "\n";
                    }
                }
            }
            return description;
        }

    private:
        /** The update resolution. Memory will hold 1 timepoint entry every mResolution simulation time steps. */
        const double mResolution;
        const double mMaxSimTime;
        OmniscientEntity *mParent = nullptr;

        /**
         * For each point in time, keep values for every (device, device) pair.
         */
        class Timepoint {
        public:
            Timepoint() {}
            virtual ~Timepoint() {}

            void put(const MacNodeId from, const MacNodeId to, const std::vector<double> sinrs) {
                std::map<MacNodeId, std::vector<double>>& map = mSinrMap[from];
                map[to] = sinrs;
            }
            /**
             * @return A <to, sinrs> map.
             */
            const std::map<MacNodeId, std::vector<double>>* get(const MacNodeId from) const {
                if (mSinrMap.size() == 0) {
                    throw cRuntimeError(std::string("Memory::Timepoint::get(" + std::to_string(from) + ") called but there's no entries for this timepoint.").c_str());
                }
                const std::map<MacNodeId, std::vector<double>>* map = &(mSinrMap.at(from));
                return map;
            }

            const std::map<MacNodeId, std::map<MacNodeId, std::vector<double>>>* get() const {
                return &(mSinrMap);
            }

        protected:
            /**
             * A map that looks like this: <from, <to, sinrs>>.
             */
            std::map<MacNodeId, std::map<MacNodeId, std::vector<double>>> mSinrMap;
        };

        std::vector<Timepoint> mTimepoints;
    };
    OmniscientEntity::Memory *mMemory = nullptr;

};

Define_Module(OmniscientEntity); // Register_Class also works... what's the difference?
