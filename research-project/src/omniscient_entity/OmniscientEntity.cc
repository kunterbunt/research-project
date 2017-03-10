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

class OmniscientFeedback : public LteSummaryFeedback {
public:
    OmniscientFeedback(unsigned char cw, unsigned int b, simtime_t lb, simtime_t ub) {
        LteFeedback::LteSummaryFeedback(cw, b, lb, ub);
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
          mConfigTimepoint(0.05)
    {
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
     * @param device The ID of the device whose CQI you are interested in.
     * @param band A band is a logical collection of resource blocks. If numBands==numRbs then you are asking for the x-th resource block's CQI.
     * @param direction Probably either Direction::UL or Direction::DL.
     * @return The channel quality indicator for the channel from this device to the eNodeB in the specified direction and band.
     */
    unsigned short getCqi(MacNodeId device, uint band, Direction direction) {
        if (mAmc == nullptr)
            throw cRuntimeError("OmniscientEntity::getCqi called before the AMC was registered.");
        return mAmc->getFeedback(device, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0, direction).getCqi(0, band);
    }

    /**
     * @param device1 The ID of one of the D2D pair's devices.
     * @param device2 The ID of the other one.
     * @param band A band is a logical collection of resource blocks. If numBands==numRbs then you are asking for the xth resource block's CQI.
     * @return The channel quality indicator for the channel between the two devices on the band.
     */
    unsigned short getCqi(MacNodeId device1, MacNodeId device2, uint band) {
        if (mAmc == nullptr)
            throw cRuntimeError("OmniscientEntity::getCqi called before the AMC was registered. You should call this method after final configuration is done.");
        return mAmc->getFeedbackD2D(device1, Remote::MACRO, TxMode::SINGLE_ANTENNA_PORT0, device2).getCqi(0, band);
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
//      Schedule next update.
        scheduleAt(simTime() + mUpdateInterval, mUpdateNotifyMsg);
    }

    void configure() {
        EV << "OmniscientEntity::configure" << std::endl;
        std::vector<EnbInfo*>* enbInfo = getEnbInfo();
        if (enbInfo->size() == 0)
            throw cRuntimeError("OmniscientEntity::configure can't get AMC pointer because I couldn't find an eNodeB!");
        LteMacEnb *eNodeB = (LteMacEnb*) getMacByMacNodeId(enbInfo->at(0)->id);
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

private:
    LteBinder   *mBinder = nullptr; // LteBinder defined in simulte/src/corenetwork/binder/LteBinder.h
    cMessage    *mUpdateNotifyMsg = nullptr,
                *mConfigMsg = nullptr;
    double      mUpdateInterval,
                mConfigTimepoint;
    LteAmc      *mAmc = nullptr; // LteAmc defined in simulte/src/stack/mac/amc/LteAmc.h

};

Define_Module(OmniscientEntity); // Register_Class also works... what's the difference?
