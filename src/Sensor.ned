package rssf01;
import inet.linklayer.ieee802154.Ieee802154NarrowbandInterface;
import inet.mobility.contract.IMobility;
import inet.mobility.static.StationaryMobility;

module Sensor
{
    parameters:
        wlan.radio.antenna.mobilityModule = default("^.^.^.mobility");
        
    gates:
        input radioIn;        
        
	submodules:
	    app: Aplicacao;
	    wlan : Ieee802154NarrowbandInterface;
		mobility: <default("StationaryMobility")> like IMobility;
	    
	connections:
	    app.outNIC --> wlan.upperLayerIn;
	    wlan.upperLayerOut --> app.inNIC;
	    radioIn --> wlan.radioIn;
}
