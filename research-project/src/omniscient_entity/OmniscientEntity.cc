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
 *  Physical device locations
 *  Current device speed
 *  SINR values for UE-UE and UE-BS links in any direction or power level
 *  Channel Quality Indicators both as reported by the nodes and computed for any moment in time
 */
class OmniscientEntity : public omnetpp::cSimpleModule {
public:
    OmniscientEntity()
        : mBinder(getBinder()), // getBinder() provided LteCommon.h
          mUpdateNotifyMsg(new cMessage("OmniscientEnity::collectInfo")),
          mConfigMsg(new cMessage("OmniscientEntity::config")),
          mUpdateInterval(0.01),
          mConfigTimepoint(0.05) {
        // All work is done in init-list.
    }

    virtual ~OmniscientEntity() {}

    void setUpdateInterval(const double value) {
        mUpdateInterval = value;
    }

    double getUpdateInterval() const {
        return mUpdateInterval;
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
    unsigned short getReportedCqi(MacNodeId device, uint band, Direction direction, Remote antenna, TxMode transmissionMode) {
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
    unsigned short getReportedCqi(MacNodeId device, uint band, Direction direction) {
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
    unsigned short getReportedCqi(MacNodeId device1, MacNodeId device2, uint band, Remote antenna, TxMode transmissionMode) {
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
    unsigned short getReportedCqi(MacNodeId device1, MacNodeId device2, uint band) {
        return getReportedCqi(device1, device2, band, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0);
    }

    /**
     * Computes the current CQI for the device<->eNodeB link.
     * @param device Device ID.
     * @param transmissionMode See TxMode::x enum.
     * @return device<->eNodeB Channel Quality Indicator.
     */
    unsigned short getCqi(MacNodeId device, TxMode transmissionMode) {
        return mFeedbackComputer->getCqi(transmissionMode, getMean(getSINR(device)));
    }

    /**
     * Computes the current CQI for the device<->eNodeB link. Assumes TxMode::SINGLE_ANTENNA_PORT0 transmission mode.
     * @param device Device ID.
     * @return device<->eNodeB Channel Quality Indicator.
     */
    unsigned short getCqi(MacNodeId device) {
        return getCqi(device, TxMode::SINGLE_ANTENNA_PORT0);
    }

    /**
     * Computes the current CQI for the from<->to link.
     * @param from One side's device ID.
     * @param to Other side's device ID.
     * @param transmissionMode See TxMode::x enum.
     * @return from<->to Channel Quality Indicator.
     */
    unsigned short getCqi(MacNodeId from, MacNodeId to, TxMode transmissionMode) {
        return mFeedbackComputer->getCqi(transmissionMode, getMean(getSINR(from, to)));
    }

    /**
     * Computes the current CQI for the from<->to link. Assumes TxMode::SINGLE_ANTENNA_PORT0 transmission mode.
     * @param from One side's device ID.
     * @param to Other side's device ID.
     * @return from<->to Channel Quality Indicator.
     */
    unsigned short getCqi(MacNodeId from, MacNodeId to) {
        return getCqi(from, to, TxMode::SINGLE_ANTENNA_PORT0);
    }

    /**
     * @param device The device's node ID.
     * @return The IMobility that describes this node's mobility. See inet/src/inet/mobility/contract/IMobility.h for implementation.
     */
    IMobility* getMobility(MacNodeId device) {
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
    Coord getPosition(MacNodeId device) {
      return getMobility(device)->getCurrentPosition();
    }

    /**
     * @param device The device's node ID.
     * @return The device's physical current speed. Coord.{x,y,z} are publicly available.
     */
    Coord getSpeed(MacNodeId device) {
        return getMobility(device)->getCurrentSpeed();
    }

    /**
     * @param from The D2D transmitter's ID.
     * @param to The D2D receiver's ID.
     * @param transmissionPower The power level that the node would transmit with.
     * @param direction The transmission direction (see Direction::x enum).
     * @return The SINR value for each band.
     */
    std::vector<double> getSINR(MacNodeId from, MacNodeId to, double transmissionPower, Direction direction) {
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
        return SINRs;
    }

    /**
     * @param from The D2D transmitter's ID.
     * @param to The D2D receiver's ID.
     * @return The SINR value for each band for the D2D channel between the nodes, if it transmits at the transmission power set in the .ini.
     */
    std::vector<double> getSINR(MacNodeId from, MacNodeId to) {
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
    std::vector<double> getSINR(MacNodeId id, double transmissionPower, Direction direction) {
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
        return SINRs;
    }

    /**
     * @param id The node in question's ID.
     * @return The SINR value for each band for the uplink channel from the node to the eNodeB, if it transmits at the transmission power set in the .ini.
     */
    std::vector<double> getSINR(MacNodeId id) {
        // Get a pointer to the device's module.
        std::string modulePath = getDeviceInfo(id)->ue->getFullPath() + ".nic.phy";
        cModule *mod = getModuleByPath(modulePath.c_str());
        // From the module we can access its transmission power.
        return getSINR(id, mod->par("ueTxPower"), Direction::UL);
    }

    double getMean(std::vector<double> values) {
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
        scheduleAt(mConfigTimepoint, mConfigMsg);
        // Schedule first update.
        scheduleAt(mConfigTimepoint + mUpdateInterval, mUpdateNotifyMsg);
    }

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

        // Set eNodeB position.
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

        EV << "SINR_D2D=" << getMean(getSINR(ueInfo->at(0)->id, ueInfo->at(1)->id)) << " SINR=" << getMean(getSINR(ueInfo->at(0)->id)) << std::endl;
        EV << "CQI_reported=" << getReportedCqi(ueInfo->at(0)->id, 0, Direction::UL) << " CQI_calculated=" << getCqi(ueInfo->at(0)->id) << std::endl;
        EV << "CQI_D2D_reported=" << getReportedCqi(ueInfo->at(0)->id, ueInfo->at(1)->id, 0) << " CQI_D2D_calculated=" << getCqi(ueInfo->at(0)->id, ueInfo->at(1)->id) << std::endl;
    }

    void handleMessage(cMessage *msg) {
        EV << "OmniscientEntity::handleMessage" << std::endl;
        if (msg == mUpdateNotifyMsg)
            collectInfo();
        else if (msg == mConfigMsg)
            configure();
    }

    void collectInfo() {
        EV << "OmniscientEntity::collectInfo" << std::endl;
        std::vector<UeInfo*>* ueInfo = getUeInfo();
        EV << "\tUE[0]'s CQI=" << getReportedCqi(ueInfo->at(0)->id, 0, Direction::DL) << std::endl;
        EV << "\tUE[0]-D2D-UE[1] CQI=" << getReportedCqi(ueInfo->at(0)->id, ueInfo->at(1)->id, 0) << std::endl;

//      Schedule next update.
        scheduleAt(simTime() + mUpdateInterval, mUpdateNotifyMsg);

        Coord position = getPosition(ueInfo->at(0)->id);
        EV << "Position: " << position.x << "," << position.y << "," << position.z << std::endl;
    }

    std::vector<EnbInfo*>* getEnbInfo() const {
        return mBinder->getEnbList();
    }
    std::vector<UeInfo*>* getUeInfo() const {
        return mBinder->getUeList();
    }

    OmnetId getId(MacNodeId id) {
        return mBinder->getOmnetId(id);
    }
    MacNodeId getId(OmnetId id) {
        return mBinder->getMacNodeIdFromOmnetId(id);
    }

    UeInfo* getDeviceInfo(MacNodeId device) {
      std::vector<UeInfo*>* ueInfo = getUeInfo();
      for (size_t i = 0; i < ueInfo->size(); i++) {
        UeInfo* currentInfo = ueInfo->at(i);
        if (currentInfo->id == device)
          return currentInfo;
      }
      throw cRuntimeError("OmniscientEntity::getDeviceInfo can't find the requested device ID!");
    }

    EnbInfo* getENodeBInfo(MacNodeId id) {
      std::vector<EnbInfo*>* enbInfo = getEnbInfo();
      for (size_t i = 0; i < enbInfo->size(); i++) {
          EnbInfo* currentInfo = enbInfo->at(i);
        if (currentInfo->id == id)
          return currentInfo;
      }
      throw cRuntimeError("OmniscientEntity::getENodeBInfo can't find the requested eNodeB ID!");
    }

    ExposedFeedbackComputer* getFeedbackComputation() {
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

private:
    LteBinder   *mBinder = nullptr;
    cMessage    *mUpdateNotifyMsg = nullptr,
                *mConfigMsg = nullptr;
    double      mUpdateInterval,
                mConfigTimepoint;
    LteAmc      *mAmc = nullptr;
    LteRealisticChannelModel    *mChannelModel = nullptr;
    MacNodeId mENodeBId;
    ExposedFeedbackComputer *mFeedbackComputer = nullptr;
    LteDeployer *mDeployer = nullptr;
    Coord mENodeBPosition;

};

Define_Module(OmniscientEntity); // Register_Class also works... what's the difference?
