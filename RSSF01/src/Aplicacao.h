#ifndef __RSSF01_APLICACAO_H_
#define __RSSF01_APLICACAO_H_

#include <omnetpp.h>

using namespace omnetpp;


class Aplicacao : public cSimpleModule
{
  private:
    int cont = 0;
    int numero;
    bool sink;
    double temperature;
    double moisture;
    double air;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual float randomNumber(int min, int max);
};

#endif
