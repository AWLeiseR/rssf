#include <stdio.h>
#include "Aplicacao.h"
#include "Pacote_m.h"
#include "inet/common/packet/Packet.h"
#include "inet/linklayer/common/MacAddressTag_m.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/linklayer/common/MacAddress.h"
#include "inet/common/Protocol.h"

Define_Module(Aplicacao);

void Aplicacao::initialize()
{
    numero = par("numero").intValue();
    cont++;
    Pacote *pct = new Pacote();
    pct->setNodo_origem(numero);
    pct->setNumero_msg(cont);
    pct->setValor(valor);
    auto enders = pct->addTag<inet::MacAddressReq>();
    enders->setDestAddress(inet::MacAddress::BROADCAST_ADDRESS);
    pct->addTag<inet::PacketProtocolTag>()->setProtocol(&inet::Protocol::unknown);
    scheduleAt(simTime() + (numero+1) , pct);
}

void Aplicacao::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        send(msg,"outNIC");
        cont++;
        Pacote *novo = new Pacote();
        novo->setNodo_origem(numero);
        novo->setNumero_msg(cont);
        novo->setValor(valor);
        auto enders = novo->addTag<inet::MacAddressReq>();
        enders->setDestAddress(inet::MacAddress::BROADCAST_ADDRESS);
        novo->addTag<inet::PacketProtocolTag>()->setProtocol(&inet::Protocol::unknown);
        scheduleAt(simTime()+2, novo);
    } else {
        Pacote *pct = check_and_cast<Pacote *>(msg);
        EV << "*********** Nodo: " << numero << " Pacote recebido de "
           << pct->getNodo_origem() << " numero: " << pct->getNumero_msg()
           << " valor: " << pct->getValor() << "\n";
        delete(msg);
    }
}










