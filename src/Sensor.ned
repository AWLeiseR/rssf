package rssf01;
import inet.linklayer.ieee802154.Ieee802154NarrowbandInterface;
import inet.mobility.contract.IMobility;
import inet.power.contract.IEnergyStorage;
import inet.mobility.static.StationaryMobility;
import inet.power.storage.SimpleEpEnergyStorage;

module Sensor
{
    parameters:
        wlan.radio.antenna.mobilityModule = default("^.^.^.mobility");
        wlan.energySourceModule = default("^.energyStorage");
    gates:
        input radioIn;        
        
	submodules:
	    app: Aplicacao;
	    wlan : Ieee802154NarrowbandInterface;
		mobility: <default("StationaryMobility")> like IMobility;
	    energyStorage: <default("SimpleEpEnergyStorage")> like IEnergyStorage;
	connections:
	    app.outNIC --> wlan.upperLayerIn;
	    wlan.upperLayerOut --> app.inNIC;
	    radioIn --> wlan.radioIn;
}
