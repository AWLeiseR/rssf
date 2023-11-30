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

package rssf01.simulations;
import inet.physicallayer.wireless.ieee802154.packetlevel.Ieee802154NarrowbandScalarRadioMedium;
import rssf01.Sensor;

network rede01
{
    @display("bgb=500,500");
    submodules:
        radioMedium: Ieee802154NarrowbandScalarRadioMedium {
            @display("p=20,20");
        }
        nodo0: Sensor {
            @display("p=110,50");
        }
        nodo1: Sensor {
            @display("p=240,160");
        }
        nodo2: Sensor {
            @display("p=360,280");
        }
        nodo3: Sensor {
            @display("p=420,390");
        }
    connections allowunconnected:
}

