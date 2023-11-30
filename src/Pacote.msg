import inet.common.packet.Packet;

cplusplus {{
	#include "inet/common/packet/Packet.h"
}}

packet Pacote extends inet::Packet {    
    int nodo_origem;
    int numero_msg;
    double valor;
}
