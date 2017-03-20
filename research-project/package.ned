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
        int numUeCell = default(1);
        int numUeD2DTx = default(0);
        int numUeD2DRx = default(0);
        @display("i=block/network2;bgb=991,558;bgi=background/budapest");
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
            @display("p=614.4125,59.7;is=n;i=device/server");
        }
        router: Router {
            @display("p=416.65625,135.56876;i=device/smallrouter");
        }
        pgw: PgwStandardSimplified {
            nodeType = "PGW";
            @display("p=614.4125,174.125;is=l");
        }
        eNodeB: eNodeB {
            @display("p=486.30624,258.7;is=vl");
        }
        ueCell[numUeCell]: Ue {
            @display("p=335.8125,344.51874");
        }
        ueD2DTx[numUeD2DTx]: Ue {
            @display("p=608.1937,434.06876");
        }
        ueD2DRx[numUeD2DRx]: Ue {
            @display("p=723.8625,258.7");
        }
        omniscientEntity: OmniscientEntity {
            @display("p=844.5062,84.575");
        }
    connections:
        server.pppg++ <--> Eth10G <--> router.pppg++;
        router.pppg++ <--> Eth10G <--> pgw.filterGate;
        pgw.pppg++ <--> Eth10G <--> eNodeB.ppp;
}
