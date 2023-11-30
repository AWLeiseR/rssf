package rssf01.simulations;
import inet.physicallayer.wireless.ieee802154.packetlevel.Ieee802154NarrowbandScalarRadioMedium;
import rssf01.Sensor;

network rede02
{
    @display("bgb=500,500");
    submodules:
        radioMedium: Ieee802154NarrowbandScalarRadioMedium {
            @display("p=10,10");
        }
        nodo0: Sensor {
            @display("p=390,390");
        }
        nodo1: Sensor {
            @display("p=420,420");
        }
        nodo2: Sensor {
            @display("p=480,480");
        }
        connections allowunconnected:
}

