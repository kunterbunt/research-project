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
 *  SINR values for UE-UE and UE-BS links in any direction or power level (periodically saved and current)
 *  Channel Quality Indicators both as reported by the nodes and computed (periodically saved and current)
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
        if (!mConfigMsg->isScheduled())
            delete mConfigMsg;
        if (!mSnapshotMsg->isScheduled())
            delete mSnapshotMsg;
    }

    /**
     * @param from Channel starting point.
     * @param to Channel end point.
     * @param band A specific band.
     * @param direction Transmission direction.
     * @param antenna
     * @param transmissionMode
     * @return The current CQI as stored by the AMC.
     */
    Cqi getReportedCqi(const MacNodeId from, const MacNodeId to, const uint band, const Direction direction, const Remote antenna, const TxMode transmissionMode) const {
        if (from == to)
            throw cRuntimeError(std::string("OmniscientEntity::getReportedCqi shouldn't be called for from==to!").c_str());
        if (mAmc == nullptr)
            throw cRuntimeError(std::string("OmniscientEntity::getCqi called before the AMC was registered. You should call this method after final configuration is done.").c_str());

        // Cellular link.
        if (from == mENodeBId) {
            return mAmc->getFeedback(to, antenna, transmissionMode, direction).getCqi(0, band);
        } else if (to == mENodeBId) {
            return mAmc->getFeedback(from, antenna, transmissionMode, direction).getCqi(0, band);
        // D2D link.
        } else {
            return mAmc->getFeedbackD2D(from, antenna, transmissionMode, to).getCqi(0, band);
        }
    }

    /**
     * @return The computed CQI.
     */
    Cqi getCqi(const TxMode transmissionMode, const double sinr) const {
        return mFeedbackComputer->getCqi(transmissionMode, sinr);
    }

    /**
     * @param from Channel starting point.
     * @param to Channel end point.
     * @param time Moment in time.
     * @param transmissionMode Transmitter's transmission mode.
     * @return Channel Quality Indicator as computed right now if time>=NOW, or as stored in memory if earlier.
     */
    Cqi getCqi(const MacNodeId from, const MacNodeId to, const SimTime time, const TxMode transmissionMode) const {
        if (from == to)
            throw cRuntimeError(std::string("OmniscientEntity::getCqi shouldn't be called for from==to!").c_str());
        // getSINR handles distinction of computing a current value or querying the memory.
        double meanSINR = getMean(getSINR(from, to, time));
        return getCqi(transmissionMode, meanSINR);
    }


    /**
     * @param from Transmitter ID.
     * @param to Receiver ID.
     * @param time Moment in time.
     * @param transmissionPower The transmitter's transmission power.
     * @param direction The transmission direction.
     * @return If time>=NOW the current value is computed. For earlier moments the memory is queried.
     */
    std::vector<double> getSINR(MacNodeId from, MacNodeId to, const SimTime time, const double transmissionPower, const Direction direction) const {
        if (from == to)
            throw cRuntimeError(std::string("OmniscientEntity::getSINR shouldn't be called for from==to!").c_str());
        // Make sure eNodeB is the target.
        if (from == mENodeBId) {
            MacNodeId temp = from;
            from = to;
            to = temp;
        }
        // Compute current value.
        if (time >= NOW) {
            LteAirFrame* frame = new LteAirFrame("feedback_pkt");
            UserControlInfo* uinfo = new UserControlInfo();
            uinfo->setFrameType(FEEDBACKPKT);
            uinfo->setIsCorruptible(false);
            uinfo->setSourceId(from);
            uinfo->setDirection(direction);
            uinfo->setTxPower(transmissionPower);
            std::vector<double> SINRs;

            // UE <-> eNodeB cellular channel.
            if (to == mENodeBId) {
                // I am pretty sure that there's a mistake in the simuLTE source code.
                // It incorrectly sets the eNodeB's position for its calculations. I am here setting the UE's position as the eNodeB's,
                // so that the distance is correct which is all that matters. (or maybe this is how you're supposed to do it...)
                uinfo->setCoord(mENodeBPosition);
                uinfo->setDestId(mENodeBId);

                SINRs = mChannelModel->getSINR(frame, uinfo);
            // UE <-> UE D2D channel.
            } else {
                uinfo->setCoord(getPosition(from));
                uinfo->setD2dTxPeerId(from);
                uinfo->setD2dRxPeerId(to);
                uinfo->setD2dTxPower(transmissionPower);

                SINRs = mChannelModel->getSINR_D2D(frame, uinfo, to, getPosition(to), mENodeBId);
            }

            delete uinfo;
            delete frame;
            return SINRs;
        // Retrieve from memory.
        } else {
            return mMemory->get(time, from, to);
        }
    }

    /**
     * Determines direction and transmission power automatically.
     * @param from Transmitter ID.
     * @param to Receiver ID.
     * @param time Moment in time.
     * @return If time>=NOW the current value is computed. For earlier moments the memory is queried.
     */
    std::vector<double> getSINR(MacNodeId from, MacNodeId to, SimTime time) const {
        // Make sure eNodeB is the target.
        if (from == mENodeBId) {
            MacNodeId temp = from;
            from = to;
            to = temp;
        }

        // Determine direction.
        Direction dir;
        if (from == mENodeBId)
            dir = Direction::DL; // eNodeB -DL-> UE.
        else if (to == mENodeBId)
            dir = Direction::UL; // UE -UL-> eNodeB.
        else
            dir = Direction::D2D; // UE -D2D-> UE.

        // Determine transmission power because it's not set correctly in a device's associated UeInfo object.
        double transmissionPower;
        std::string modulePath = getDeviceInfo(from)->ue->getFullPath() + ".nic.phy";
        cModule *mod = getModuleByPath(modulePath.c_str()); // Get a pointer to the device's module.
        if (dir == Direction::D2D)
            transmissionPower = mod->par("d2dTxPower");
        else
            transmissionPower = mod->par("ueTxPower");

        return getSINR(from, to, time, transmissionPower, dir);
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
            throw cRuntimeError(std::string("OmniscientEntity::getMobility couldn't find the device's cModule!").c_str());
        IMobility* mobilityModule = check_and_cast<IMobility*>(host->getSubmodule("mobility"));
        if (mobilityModule == nullptr)
            throw cRuntimeError(std::string("OmniscientEntity::getMobility couldn't find a mobility module!").c_str());
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

        // Test the different interfaces.
        MacNodeId from = ueInfo->at(0)->id,
                  to = ueInfo->at(1)->id;
        Cqi cqi_computed_d2d = getCqi(from, to, NOW, TxMode::SINGLE_ANTENNA_PORT0),
            cqi_reported_d2d = getReportedCqi(from, to, 0, Direction::D2D, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0),
            cqi_computed_cellular = getCqi(from, mENodeBId, NOW, TxMode::SINGLE_ANTENNA_PORT0),
            cqi_reported_cellular = getReportedCqi(from, mENodeBId, 0, Direction::UL, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0),
            cqi_computed_cellular2 = getCqi(mENodeBId, to, NOW, TxMode::SINGLE_ANTENNA_PORT0),
            cqi_reported_cellular2 = getReportedCqi(mENodeBId, to, 0, Direction::DL, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0);
        EV << "CQI_computed_d2d=" << cqi_computed_d2d << " CQI_reported_d2d=" << cqi_reported_d2d << std::endl;
        EV << "CQI_computed_cellular=" << cqi_computed_cellular << " CQI_reported_cellular=" << cqi_reported_cellular << std::endl;
        EV << "CQI_computed_cellular2=" << cqi_computed_cellular2 << " CQI_reported_cellular2=" << cqi_reported_cellular2 << std::endl;
        if (cqi_computed_d2d != cqi_reported_d2d || cqi_computed_cellular != cqi_reported_cellular || cqi_computed_cellular2 != cqi_reported_cellular2)
            throw cRuntimeError(std::string("OmniscientEntity::configure didn't find the same values for reported and calculated CQI!").c_str());
        EV << "SINR_mean=" << getMean(getSINR(from, to, NOW)) << std::endl;
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
            std::vector<double> sinrs_eNodeB = getSINR(from, mENodeBId, NOW);
            mMemory->put(NOW, from, mENodeBId, sinrs_eNodeB);
            // And for all other UEs...
            for (size_t j = 0; j < ueInfo->size(); j++) {
                MacNodeId to = ueInfo->at(j)->id;
                // Ignore link to current node.
                if (from == to)
                    continue;
                // Calculate and save the current SINR for the D2D link.
                std::vector<double> sinrs = getSINR(from, to, NOW);
                mMemory->put(NOW, from, to, sinrs);
            }
        }

        // Print current memory.
        EV << mMemory->toString() << std::endl;

        // Schedule next snapshot.
        scheduleAt(NOW + mUpdateInterval, mSnapshotMsg);
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
      throw cRuntimeError(std::string("OmniscientEntity::getDeviceInfo can't find the requested device ID \"" + std::to_string(device) + "\"").c_str());
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
         * @param time Point in time when the SINR was computed.
         * @param sinr SINR value.
         */
        void put(const SimTime time, const MacNodeId from, const MacNodeId to, const std::vector<double> sinrs) {
            double position = (time.dbl() / mResolution);
            if (position >= mTimepoints.size()) {
                std::string err = "OmniscientEntity::Memory::put Position " + std::to_string(position) + " > maxPosition " + std::to_string(mTimepoints.size()) + "\n";
                throw cRuntimeError(err.c_str());
            }
            Timepoint *timepoint = &(mTimepoints.at(position));
            timepoint->put(from, to, sinrs);
        }

        /**
         * @param time Moment in the past you're interested in. Will be rounded to the nearest entry.
         * @param from One channel endpoint.
         * @return A <to, sinrs> map holding the values of all SINRs in all bands to all devices.
         */
        const std::map<MacNodeId, std::vector<double>>* get(const SimTime time, const MacNodeId from) const {
            double position = time.dbl() / mResolution;
            if (position >= mTimepoints.size()) {
                std::string err = "OmniscientEntity::Memory::get Position " + std::to_string(position) + " > maxPosition " + std::to_string(mTimepoints.size()) + "\n";
                throw cRuntimeError(err.c_str());
            }
            const Timepoint* timepoint = &(mTimepoints.at(position));
            const std::map<MacNodeId, std::vector<double>>* map = nullptr;
            try {
                map = timepoint->get(from);
            } catch (const cRuntimeError& err) {
                throw; // Forward exception.
            }

            return map;
        }

        /**
         * @param time Moment in the past you're interested in. Will be rounded to the nearest entry.
         * @param from One channel endpoint.
         * @param to The other channel endpoint.
         * @return SINR values for all bands.
         */
        std::vector<double> get(const SimTime time, const MacNodeId from, const MacNodeId to) const {
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
                    description += "UE[" + std::to_string(from) + "]\n\t\t-> eNodeB CQI=" + std::to_string(mParent->getCqi(TxMode::SINGLE_ANTENNA_PORT0, mParent->getMean(sinrs_eNodeB))) + " " + mParent->vectorToString(sinrs_eNodeB, "SINR") + "\n";
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
                        description += "\t\t-> UE[" + std::to_string(to) + "] CQI=" + std::to_string(mParent->getCqi(TxMode::SINGLE_ANTENNA_PORT0, mParent->getMean(sinrs))) + " " + mParent->vectorToString(sinrs, "SINR") + "\n";
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
             * A map that looks like this: <from, <to, sinrs>>. Only SINRs are kept because CQIs can be computed from them directly.
             */
            std::map<MacNodeId, std::map<MacNodeId, std::vector<double>>> mSinrMap;
        };

        std::vector<Timepoint> mTimepoints;
    };
    OmniscientEntity::Memory *mMemory = nullptr;

};

Define_Module(OmniscientEntity); // Register_Class also works... what's the difference?
