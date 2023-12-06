#include <stdio.h>
#include <iostream>
#include <random>
#include <ctime>
#include "Aplicacao.h"
#include "Pacote_m.h"
#include "inet/common/packet/Packet.h"
#include "inet/linklayer/common/MacAddressTag_m.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/linklayer/common/MacAddress.h"
#include "inet/common/Protocol.h"

Define_Module(Aplicacao);

float Aplicacao::randomNumber(int min, int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distribuicao(min, max);

    return distribuicao(gen);
}

int receivedPackages[18]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void Aplicacao::initialize(){
    sink = par("sink").boolValue();
    if(!sink){
        numero = par("numero").intValue();
            cont++;
            Pacote *pct = new Pacote();
            pct->setNodo_origem(numero);
            pct->setNumero_msg(cont);
            pct->setTemperature(Aplicacao::randomNumber(23,29));
            pct->setMoisture(Aplicacao::randomNumber(50,59));
            pct->setAir(Aplicacao::randomNumber(40,60));

            auto enders = pct->addTag<inet::MacAddressReq>();
            enders->setDestAddress(inet::MacAddress::BROADCAST_ADDRESS);
            pct->addTag<inet::PacketProtocolTag>()->setProtocol(&inet::Protocol::unknown);
            scheduleAt(simTime() + (Aplicacao::randomNumber(0,600)) , pct);
    }

}

void Aplicacao::handleMessage(cMessage *msg){
    if (msg->isSelfMessage()) {
        send(msg,"outNIC");
        cont++;
        Pacote *novo = new Pacote();
        novo->setNodo_origem(numero);
        novo->setNumero_msg(cont);

        novo->setTemperature(Aplicacao::randomNumber(23,29));
        novo->setMoisture(Aplicacao::randomNumber(50,59));
        novo->setAir(Aplicacao::randomNumber(40,60));

        auto enders = novo->addTag<inet::MacAddressReq>();
        enders->setDestAddress(inet::MacAddress::BROADCAST_ADDRESS);
        novo->addTag<inet::PacketProtocolTag>()->setProtocol(&inet::Protocol::unknown);
        scheduleAt(simTime()+600, novo);
    }else if(sink == true){
        Pacote *pct = check_and_cast<Pacote *>(msg);
        receivedPackages[pct->getNodo_origem()] = receivedPackages[pct->getNodo_origem()] + 1;
        EV << "*********** Nodo: " << numero << " Pacote recebido de "
                   << pct->getNodo_origem() << " numero: " << pct->getNumero_msg()
                   << " Temperatura: " << pct->getTemperature() << " Umidade do solo: "
                   << pct->getMoisture() << " Umidade relativa: " << pct->getAir() << "\n";
        delete(msg);
    }
}
void Aplicacao::finish(){
    if(sink == true){
        int i;
        for(i=0;i<18;i++){
            EV<<"Pacotes recebidos do Nodo "<<i<<": "<<receivedPackages[i]<<"\n";
        }
    }
}









