package research_project;

import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.ethernet.Eth10G;
import inet.node.ethernet.Eth10M;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;
import lte.world.radio.ChannelControl;
import lte.corenetwork.binder.LteBinder;
import lte.corenetwork.nodes.Ue;
import lte.corenetwork.nodes.eNodeB;
import lte.world.radio.LteChannelControl;
import lte.epc.PgwStandardSimplified;
import lte.common.omniscientEntity.OmniscientEntity;


network LTECell
{
    parameters:
        int numUeCellPairs = default(0);
        int numUeD2DPairs = default(0);
        //@display("i=block/network2;bgb=991,558;bgi=background/budapest");
    submodules:
        channelControl: LteChannelControl {
            @display("p=50,25;is=s");
        }
        routingRecorder: RoutingTableRecorder {
            @display("p=50,75;is=s");
        }
        configurator: IPv4NetworkConfigurator {
            @display("p=50,125");
            config = xmldoc("demo.xml");
        }
        binder: LteBinder {
            @display("p=50,175;is=s");
        }
        server: StandardHost {
            @display("p=897.9875,94.525;is=n;i=device/server");
        }
        router: Router {
            @display("p=897.9875,180.34375;i=device/smallrouter");
        }
        pgw: PgwStandardSimplified {
            nodeType = "PGW";
            @display("p=896.7437,271.1375;is=l");
        }
        eNodeB: eNodeB {
            @display("p=486.30624,258.7;is=vl");
        }
        ueD2DTx[numUeD2DPairs]: Ue {
            @display("p=608.1937,434.06876");
        }
        ueD2DRx[numUeD2DPairs]: Ue {
            @display("p=723.8625,258.7");
        }
        ueCellTx[numUeCellPairs]: Ue {
            @display("p=369.39374,405.4625");
        }
        ueCellRx[numUeCellPairs]: Ue {
            @display("p=266.1625,221.3875");
        }
        omniscientEntity: OmniscientEntity {
            @display("p=49.75,238.8");
        }
    connections:
        server.pppg++ <--> Eth10G <--> router.pppg++;
        router.pppg++ <--> Eth10G <--> pgw.filterGate;
        pgw.pppg++ <--> Eth10G <--> eNodeB.ppp;
}
