//
// Generated file, do not edit! Created by opp_msgtool 6.0 from Pacote.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "Pacote_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(Pacote)

Pacote::Pacote(const char *name, short kind) : ::inet::Packet(name, kind)
{
}

Pacote::Pacote(const Pacote& other) : ::inet::Packet(other)
{
    copy(other);
}

Pacote::~Pacote()
{
}

Pacote& Pacote::operator=(const Pacote& other)
{
    if (this == &other) return *this;
    ::inet::Packet::operator=(other);
    copy(other);
    return *this;
}

void Pacote::copy(const Pacote& other)
{
    this->nodo_origem = other.nodo_origem;
    this->numero_msg = other.numero_msg;
    this->temperature = other.temperature;
    this->moisture = other.moisture;
    this->air = other.air;
}

void Pacote::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::Packet::parsimPack(b);
    doParsimPacking(b,this->nodo_origem);
    doParsimPacking(b,this->numero_msg);
    doParsimPacking(b,this->temperature);
    doParsimPacking(b,this->moisture);
    doParsimPacking(b,this->air);
}

void Pacote::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::Packet::parsimUnpack(b);
    doParsimUnpacking(b,this->nodo_origem);
    doParsimUnpacking(b,this->numero_msg);
    doParsimUnpacking(b,this->temperature);
    doParsimUnpacking(b,this->moisture);
    doParsimUnpacking(b,this->air);
}

int Pacote::getNodo_origem() const
{
    return this->nodo_origem;
}

void Pacote::setNodo_origem(int nodo_origem)
{
    this->nodo_origem = nodo_origem;
}

int Pacote::getNumero_msg() const
{
    return this->numero_msg;
}

void Pacote::setNumero_msg(int numero_msg)
{
    this->numero_msg = numero_msg;
}

double Pacote::getTemperature() const
{
    return this->temperature;
}

void Pacote::setTemperature(double temperature)
{
    this->temperature = temperature;
}

double Pacote::getMoisture() const
{
    return this->moisture;
}

void Pacote::setMoisture(double moisture)
{
    this->moisture = moisture;
}

double Pacote::getAir() const
{
    return this->air;
}

void Pacote::setAir(double air)
{
    this->air = air;
}

class PacoteDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_nodo_origem,
        FIELD_numero_msg,
        FIELD_temperature,
        FIELD_moisture,
        FIELD_air,
    };
  public:
    PacoteDescriptor();
    virtual ~PacoteDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(PacoteDescriptor)

PacoteDescriptor::PacoteDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Pacote)), "inet::Packet")
{
    propertyNames = nullptr;
}

PacoteDescriptor::~PacoteDescriptor()
{
    delete[] propertyNames;
}

bool PacoteDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Pacote *>(obj)!=nullptr;
}

const char **PacoteDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PacoteDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PacoteDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int PacoteDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_nodo_origem
        FD_ISEDITABLE,    // FIELD_numero_msg
        FD_ISEDITABLE,    // FIELD_temperature
        FD_ISEDITABLE,    // FIELD_moisture
        FD_ISEDITABLE,    // FIELD_air
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *PacoteDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nodo_origem",
        "numero_msg",
        "temperature",
        "moisture",
        "air",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int PacoteDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "nodo_origem") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "numero_msg") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "temperature") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "moisture") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "air") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *PacoteDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_nodo_origem
        "int",    // FIELD_numero_msg
        "double",    // FIELD_temperature
        "double",    // FIELD_moisture
        "double",    // FIELD_air
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **PacoteDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *PacoteDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int PacoteDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Pacote *pp = omnetpp::fromAnyPtr<Pacote>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PacoteDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Pacote *pp = omnetpp::fromAnyPtr<Pacote>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Pacote'", field);
    }
}

const char *PacoteDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Pacote *pp = omnetpp::fromAnyPtr<Pacote>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PacoteDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Pacote *pp = omnetpp::fromAnyPtr<Pacote>(object); (void)pp;
    switch (field) {
        case FIELD_nodo_origem: return long2string(pp->getNodo_origem());
        case FIELD_numero_msg: return long2string(pp->getNumero_msg());
        case FIELD_temperature: return double2string(pp->getTemperature());
        case FIELD_moisture: return double2string(pp->getMoisture());
        case FIELD_air: return double2string(pp->getAir());
        default: return "";
    }
}

void PacoteDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Pacote *pp = omnetpp::fromAnyPtr<Pacote>(object); (void)pp;
    switch (field) {
        case FIELD_nodo_origem: pp->setNodo_origem(string2long(value)); break;
        case FIELD_numero_msg: pp->setNumero_msg(string2long(value)); break;
        case FIELD_temperature: pp->setTemperature(string2double(value)); break;
        case FIELD_moisture: pp->setMoisture(string2double(value)); break;
        case FIELD_air: pp->setAir(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Pacote'", field);
    }
}

omnetpp::cValue PacoteDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Pacote *pp = omnetpp::fromAnyPtr<Pacote>(object); (void)pp;
    switch (field) {
        case FIELD_nodo_origem: return pp->getNodo_origem();
        case FIELD_numero_msg: return pp->getNumero_msg();
        case FIELD_temperature: return pp->getTemperature();
        case FIELD_moisture: return pp->getMoisture();
        case FIELD_air: return pp->getAir();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Pacote' as cValue -- field index out of range?", field);
    }
}

void PacoteDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Pacote *pp = omnetpp::fromAnyPtr<Pacote>(object); (void)pp;
    switch (field) {
        case FIELD_nodo_origem: pp->setNodo_origem(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_numero_msg: pp->setNumero_msg(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_temperature: pp->setTemperature(value.doubleValue()); break;
        case FIELD_moisture: pp->setMoisture(value.doubleValue()); break;
        case FIELD_air: pp->setAir(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Pacote'", field);
    }
}

const char *PacoteDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr PacoteDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Pacote *pp = omnetpp::fromAnyPtr<Pacote>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PacoteDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Pacote *pp = omnetpp::fromAnyPtr<Pacote>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Pacote'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

