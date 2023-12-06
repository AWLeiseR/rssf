//
// Generated file, do not edit! Created by opp_msgtool 6.0 from Pacote.msg.
//

#ifndef __PACOTE_M_H
#define __PACOTE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class Pacote;
#include "inet/common/packet/Packet_m.h" // import inet.common.packet.Packet

// cplusplus {{
	#include "inet/common/packet/Packet.h"
// }}

/**
 * Class generated from <tt>Pacote.msg:7</tt> by opp_msgtool.
 * <pre>
 * packet Pacote extends inet::Packet
 * {
 *     int nodo_origem;
 *     int numero_msg;
 *     //double valor;
 *     double temperature;
 *     double moisture;
 *     double air;
 * }
 * </pre>
 */
class Pacote : public ::inet::Packet
{
  protected:
    int nodo_origem = 0;
    int numero_msg = 0;
    double temperature = 0;
    double moisture = 0;
    double air = 0;

  private:
    void copy(const Pacote& other);

  protected:
    bool operator==(const Pacote&) = delete;

  public:
    Pacote(const char *name=nullptr, short kind=0);
    Pacote(const Pacote& other);
    virtual ~Pacote();
    Pacote& operator=(const Pacote& other);
    virtual Pacote *dup() const override {return new Pacote(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getNodo_origem() const;
    virtual void setNodo_origem(int nodo_origem);

    virtual int getNumero_msg() const;
    virtual void setNumero_msg(int numero_msg);

    virtual double getTemperature() const;
    virtual void setTemperature(double temperature);

    virtual double getMoisture() const;
    virtual void setMoisture(double moisture);

    virtual double getAir() const;
    virtual void setAir(double air);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Pacote& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Pacote& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline Pacote *fromAnyPtr(any_ptr ptr) { return check_and_cast<Pacote*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __PACOTE_M_H

