package research_project.simulations;

import inet.networklayer.configurator.ipv4.FlatNetworkConfigurator;
import inet.node.ethernet.Eth1G;
import inet.node.inet.StandardHost;


@license(LGPL);
network LTECell
{
    @display("bgb=795.9,391.65");
    submodules:
        flatNetworkConfigurator: FlatNetworkConfigurator {
            @display("p=107.1,29.4");
        }
        host1: StandardHost {
            @display("p=203.7,179.55");
        }
        host2: StandardHost {
            @display("p=565.95,175.35");
        }
    connections:
        host1.ethg++ <--> Eth1G <--> host2.ethg++;
}

