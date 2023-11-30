package rssf01.simulations;
import inet.physicallayer.wireless.ieee802154.packetlevel.Ieee802154NarrowbandScalarRadioMedium;
import rssf01.Sensor;

network rede02
{
    @display("bgb=500,500");
    submodules:
        radioMedium: Ieee802154NarrowbandScalarRadioMedium {
            @display("p=0,0");
        }
        nodo0: Sensor {
            @display("p=15,15");
        }
        nodo1: Sensor {
            @display("p=30,15");
        }
        nodo2: Sensor {
            @display("p=45,15");
        }
        nodo3: Sensor {
            @display("p=15,30");
        }
        nodo4: Sensor {
            @display("p=30,30");
        }
        nodo5: Sensor {
            @display("p=45,30");
        }
        nodo6: Sensor {
            @display("p=15,45");
        }
        nodo7: Sensor {
            @display("p=30,45");
        }
        nodo8: Sensor {
            @display("p=45,45");
        }
        nodo9: Sensor {
            @display("p=60,15");
        }
        nodo10: Sensor {
            @display("p=75,15");
        }
        nodo11: Sensor {
            @display("p=90,15");
        }
        nodo12: Sensor {
            @display("p=60,30");
        }
        nodo13: Sensor {
            @display("p=75,30");
        }
        nodo14: Sensor {
            @display("p=90,30");
        }
        nodo15: Sensor {
            @display("p=60,45");
        }
        nodo16: Sensor {
            @display("p=75,45");
        }
        nodo17: Sensor {
            @display("p=90,45");
        }
         nodo18: Sensor {
            @display("p=45,22.5");
        }
        connections allowunconnected:
}

