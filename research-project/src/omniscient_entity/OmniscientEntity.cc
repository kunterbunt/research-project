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

#include <omnetpp.h>
#include <LteCommon.h>
#include <LteBinder.h>
#include <LteAmc.h>
#include <LteMacEnb.h>
#include <LteFeedback.h>
#include <L3AddressResolver.h>
#include <ModuleAccess.h>
#include <IMobility.h>
#include <vector>

/**
 * Derived Feedback class exposes otherwise hidden members without the need of altering the source code.
 */
class OmniscientFeedback : public LteSummaryFeedback {
public:
    OmniscientFeedback(unsigned char cw, unsigned int b, simtime_t lb, simtime_t ub)
        : LteSummaryFeedback(cw, b, lb, ub) {

    }

    std::vector<std::vector<simtime_t>> getElapsedTimeSinceCqiRefresh() {
        return tCqi_;
    }

};

/**
 * Implements an omniscient network entity that provides access to the following domains:
 *  channel status
 *  CQIs
 *  ...?
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
     * @param device The device whose CQI you want.
     * @param band The collection of resource blocks you're interested in.
     * @param direction The tranmsission direction, see Direction::x enum.
     * @param antenna See Remote::x enum.
     * @param transmissionMode The transmission mode, see TxMode::x enum.
     * @return The CQI of the device <-> eNodeB channel.
     */
    unsigned short getCqi(MacNodeId device, uint band, Direction direction, Remote antenna, TxMode transmissionMode) {
        if (mAmc == nullptr)
            throw cRuntimeError("OmniscientEntity::getCqi called before the AMC was registered with the OmniscientEntity. You should call this method after final configuration is done.");
        return mAmc->getFeedback(device, antenna, transmissionMode, direction).getCqi(0, band);
    }

    /**
     * @param device The ID of the device whose CQI you are interested in.
     * @param band A band is a logical collection of resource blocks. If numBands==numRbs then you are asking for the x-th resource block's CQI.
     * @param direction Probably either Direction::UL or Direction::DL.
     * @return The channel quality indicator for the channel from this device to the eNodeB in the specified direction and band.
     */
    unsigned short getCqi(MacNodeId device, uint band, Direction direction) {
        return getCqi(device, band, direction, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0);
    }

    /**
     * @param device1 One side of the D2D transmission.
     * @param device2 The other side of the transmission.
     * @param band The collection of resource blocks you're interested in.
     * @param antenna See Remote::x enum.
     * @param transmissionMode The transmission mode, see TxMode::x enum.
     * @return The CQI of the direct link between device1 and device2.
     */
    unsigned short getCqi(MacNodeId device1, MacNodeId device2, uint band, Remote antenna, TxMode transmissionMode) {
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
    unsigned short getCqi(MacNodeId device1, MacNodeId device2, uint band) {
        return getCqi(device1, device2, band, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0);
    }

    IMobility* getMobility(MacNodeId device) {
        UeInfo* ueInfo = getDeviceInfo(device);
        cModule *host = ueInfo->ue;
        IMobility* mobilityModule = check_and_cast<IMobility *>(host->getSubmodule("mobility"));
        if (mobilityModule == nullptr)
            throw cRuntimeError("OmniscientEntity::getMobility couldn't find a mobility module!");
        return mobilityModule;
    }

    Coord getPosition(MacNodeId device) {
      return getMobility(device)->getCurrentPosition();
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
        std::vector<EnbInfo*>* enbInfo = getEnbInfo();
        if (enbInfo->size() == 0)
            throw cRuntimeError("OmniscientEntity::configure can't get AMC pointer because I couldn't find an eNodeB!");
        LteMacEnb *eNodeB = (LteMacEnb*) getMacByMacNodeId(enbInfo->at(0)->id);
        EV << "CQIStorage=" << ((char) eNodeB->par("cqiStorage").getType()) << std::endl;
        mAmc = eNodeB->getAmc();
        if (mAmc == nullptr)
            throw cRuntimeError("OmniscientEntity::configure couldn't find an AMC.");
        EV << "\tFound AMC." << endl;

        // Print info about all network devices.
        std::vector<UeInfo*>* ueInfo = getUeInfo();
        EV << "\tThere are " << ueInfo->size() << " UEs in the network: " << std::endl;
        for (size_t i = 0; i < ueInfo->size(); i++)
            EV << "\t\t#" << i << ": has MacNodeId " << ueInfo->at(i)->id << " and OmnetID " << getId(ueInfo->at(i)->id) << std::endl;

        std::vector<EnbInfo*>* EnbInfo = getEnbInfo();
        EV << "\tThere are " << EnbInfo->size() << " EnBs in the network: " << std::endl;
        for (size_t i = 0; i < EnbInfo->size(); i++)
            EV << "\t\t#" << i << ": has MacNodeId " << EnbInfo->at(i)->id << " and OmnetID " << getId(ueInfo->at(i)->id) << std::endl;
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
        EV << "\tUE[0]'s CQI=" << getCqi(ueInfo->at(0)->id, 0, Direction::DL) << std::endl;
        EV << "\tUE[0]-D2D-UE[1] CQI=" << getCqi(ueInfo->at(0)->id, ueInfo->at(1)->id, 0) << std::endl;
        LteSummaryFeedback baseFeedback = mAmc->getFeedback(ueInfo->at(0)->id, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0, Direction::DL);
        OmniscientFeedback *feedback = static_cast<OmniscientFeedback*>(&baseFeedback);
        std::vector<std::vector<simtime_t> > tCqi = feedback->getElapsedTimeSinceCqiRefresh();
        for (size_t i = 0; i < tCqi.size(); i++) {
            for (size_t j = 0; j < tCqi.at(i).size(); j++) {
                EV << "i=" << i << " j=" << j << ": " << tCqi.at(i).at(j) << " and it's at " << getCqi(ueInfo->at(0)->id, i, Direction::DL) << std::endl;
            }
        }

        LteSummaryFeedback baseFeedbackD2D = mAmc->getFeedbackD2D(ueInfo->at(0)->id, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0, ueInfo->at(1)->id);
        OmniscientFeedback *feedbackD2D = static_cast<OmniscientFeedback*>(&baseFeedbackD2D);
        std::vector<std::vector<simtime_t> > tCqiD2D = feedbackD2D->getElapsedTimeSinceCqiRefresh();
        for (size_t i = 0; i < tCqiD2D.size(); i++) {
            for (size_t j = 0; j < tCqiD2D.at(i).size(); j++) {
                EV << "i=" << i << " j=" << j << ": " << tCqiD2D.at(i).at(j) << " and it's at " << getCqi(ueInfo->at(0)->id, ueInfo->at(1)->id, i) << std::endl;
            }
        }
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

private:
    LteBinder   *mBinder = nullptr; // LteBinder defined in simulte/src/corenetwork/binder/LteBinder.h
    cMessage    *mUpdateNotifyMsg = nullptr,
                *mConfigMsg = nullptr;
    double      mUpdateInterval,
                mConfigTimepoint;
    LteAmc      *mAmc = nullptr; // LteAmc defined in simulte/src/stack/mac/amc/LteAmc.h

};

Define_Module(OmniscientEntity); // Register_Class also works... what's the difference?
