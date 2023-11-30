#ifndef __RSSF01_APLICACAO_H_
#define __RSSF01_APLICACAO_H_

#include <omnetpp.h>

using namespace omnetpp;


class Aplicacao : public cSimpleModule
{
  private:
    int cont = 0;
    int numero;
    double valor = 1.99;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
