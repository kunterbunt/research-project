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

network LTECell
{
	parameters:
        @display("i=block/network2;bgb=991,558;bgi=background/budapest");
    @display("bgb=771,473");
    submodules:
        channelControl: LteChannelControl { // Mustn't change this name!
            @display("p=106,33");
        }
        routingRecorder: RoutingTableRecorder {
            @display("p=280,34");
        }
        configurator: IPv4NetworkConfigurator { // Mustn't change this name!
            @display("p=495,34");
            config = xmldoc("networkconfig.xml");
        }
        binder: LteBinder { // Mustn't change this name!
            @display("p=699,34");
        }
        eNodeB: eNodeB {
            @display("p=293,239;is=vl");
        }
        pgw: PgwStandardSimplified {
            nodeType = "PGW";
            @display("p=448,209");
        }
        router: Router {
            @display("p=549,174");
        }
        server: StandardHost {
            @display("p=640,150");
        }
        UETx: Ue {
            @display("p=138,375");
        }
        UERx: Ue {
            @display("p=482,375");
        }
    connections:
        eNodeB.ppp <--> Eth10G <--> pgw.pppg++;
        pgw.filterGate <--> Eth10G <--> router.pppg++;
        router.pppg++ <--> Eth10G <--> server.pppg++;
}
