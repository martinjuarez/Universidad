#include <iostream>
#include <tins/tins.h>

// secuencia-colaboracion-estado-despliegue-pruebas

using namespace std;
using namespace Tins;

#define MAX_PACKETS 10


bool capturarEthernet(const PDU &);

void readIPv4(const PDU &);
void readIPv6(const PDU &);
void readARP(const PDU &);
void readTCP(const PDU &);
void readUDP(const PDU &);

string whichEtherType(const uint16_t& );

int main()
{
    bool salir = false;
    unsigned int opc;
    int numPaquetes;
    do
    {
        system("clear");
        cout << "\t\t===== Sniffer (Usando libtins) =====" << endl;
        cout << "\t* Nota: Dispositivo que se puso para sniffear es: enp0s3 *" << endl;
        cout << "\t\tElige una opcion." << endl;
        cout << "\t 1.- Capturar Paquetes." << endl;
        cout << "\t 2.- Salir." << endl;
        cout << "Que deseas capturar?: ";
        cin >> opc;
        cin.ignore();

        switch(opc)
        {
        case 1:
            cout << "*capturando " << MAX_PACKETS << " paquetes*" << endl;
            Sniffer("enp3s0").sniff_loop(capturarEthernet);
            break;
        case 2:
            salir = true;
            break;
        default:
            cout << "Opcion desconocida." << endl;
        }

        if(!salir)
        {
            cout << "Presiona Enter para continuar..." << endl;
            cin.ignore();
        }
    }
    while(!salir);
}

///==========================================================================================================

bool capturarEthernet(const PDU &pdu)
{
  const EthernetII &eth = pdu.rfind_pdu<EthernetII>();
  static int i = 1;

  std::cout << "Paquete número: " << i << endl << endl;
  std::cout << "Capa Ethernet:" << endl;
  std::cout << "Dirección Destino: " << eth.dst_addr() << std::endl;
  std::cout << "Dirección Origen: " << eth.src_addr() << std::endl;
  std::cout << "Tipo: " << eth.payload_type() << "\t=>\t" << whichEtherType(eth.payload_type()) << std::endl;
  std::cout << std::endl;
  switch(eth.payload_type()) {
  case 2048:
      readIPv4(pdu);
      break;
  case 2054:
      readARP(pdu);
      break;
  case 34525:
      readIPv6(pdu);
      break;
  }

  cout << endl;

  if (i == MAX_PACKETS) {
      i = 1;
      return false;
  } else {
      i++;
      cout << "__________________________________________"<< endl << endl;
      return true;
  }
}

string whichEtherType(const uint16_t& tipo)
{
    if(tipo == 2048)
    {
        return "IPv4";
    }
    else if (tipo == 2054)
    {
        return "ARP";
    }
    else if(tipo == 32821)
    {
        return "RARP";
    }
    return "Tipo No Conocido";
}

///==========================================================================================================

void readIPv4(const PDU &pdu)
{
  const IP &ip = pdu.rfind_pdu<IP>();
  cout << "Capa IPv4: " << endl;
  cout << "Version: " << unsigned(ip.version()) << endl;
  cout << "Longitud Cabecera: " << unsigned(ip.head_len()) << endl;
  cout << "Tipo de servicio: " << unsigned(ip.tos()) << endl;
  cout << "Longitud total: " << ip.tot_len() << endl;
  cout << "Identificador: " << ip.id() << endl;
  cout << "Flags: " << ip.flags() << endl;
  cout << "Fragmento: " << unsigned(ip.fragment_offset()) << endl;
  cout << "Tiempo de vida: " << unsigned(ip.ttl()) << endl;
  cout << "Protocolo: " << unsigned(ip.protocol()) << endl;
  cout << "Checksum: " << ip.checksum() << endl;
  cout << "Dirección origen: " << ip.src_addr() << endl;
  cout << "Dirección destino: " << ip.dst_addr() << endl;
  cout << endl;
  if (ip.find_pdu<ICMP>()) {
      const ICMP &icmpv4 = pdu.rfind_pdu<ICMP>();
      cout << "Capa ICMPv4: " << endl;
      cout << "Tipo: " << unsigned(icmpv4.type()) << endl;
      cout << "Codigo: " << unsigned(icmpv4.code()) << endl;
      cout << endl;
  }
  if (ip.find_pdu<TCP>()){
      readTCP(pdu);
  }
  if (ip.find_pdu<UDP>()){
      readUDP(pdu);
  }
}


///==========================================================================================================

void readIPv6(const PDU &pdu)
{
  const IPv6 &ip = pdu.rfind_pdu<IPv6>();
  cout << "Capa IPv6: " << endl;
  cout << "Version: " << unsigned(ip.version()) << endl;
  cout << "Clase de Tráfico: " << unsigned(ip.traffic_class()) << endl;
  cout << "Etiqueta de flujo: " << unsigned(ip.flow_label()) << endl;
  cout << "Longitud del campo de datos: " << ip.payload_length() << endl;
  cout << "Cabecera siguiente: " << unsigned(ip.next_header()) << endl;
  cout << "Limite de saltos: " << unsigned(ip.hop_limit()) << endl;
  cout << "Dirección origen: " << ip.src_addr() << endl;
  cout << "Dirección destino: " << ip.dst_addr() << endl;
  if (ip.find_pdu<ICMPv6>()) {
      const ICMPv6 &icmpv6 = pdu.rfind_pdu<ICMPv6>();
      cout << "Capa ICMPv6: " << endl;
      cout << "Tipo: " << unsigned(icmpv6.type());
      cout << "Codigo: " << unsigned(icmpv6.code());
      cout << endl;
  }
  if (ip.find_pdu<TCP>()){
      readTCP(pdu);
  }
  if (ip.find_pdu<UDP>()){
      readUDP(pdu);
  }
}

///==========================================================================================================

void readARP(const PDU &pdu)
{
  const ARP &arp = pdu.rfind_pdu<ARP>();
  cout << "Capa ARP: " << endl;
  cout << "Tipo de hardware: " << arp.hw_addr_format() << endl;
  cout << "Tipo de Protocolo: " << arp.prot_addr_format() << " => " << whichEtherType(arp.prot_addr_format()) << endl;
  cout << "Longitud direccion de hardware en bytes: " << unsigned(arp.hw_addr_length()) << endl;
  cout << "Longitud direccion de protocolo en bytes: " << unsigned(arp.prot_addr_length()) << endl;
  cout << "Codigo de operación: " << arp.opcode() << endl;
  cout << "Dirección hardware del emisor: " << arp.sender_hw_addr() << endl;
  cout << "Dirección IP del emisor: " << arp.sender_ip_addr() << endl;
  cout << "Dirección hardware del receptor: " << arp.target_hw_addr() << endl;
  cout << "Dirección IP del receptor: " << arp.target_ip_addr() << endl;
  cout << endl;
}

void readTCP(const PDU &pdu)
{
    const TCP &tcp = pdu.rfind_pdu<TCP>();
    cout << "CAPA TCP: " << endl;
    cout << "Puerto origen: " << tcp.sport() << endl;
    cout << "Puerto destino: " << tcp.dport() << endl;
    cout << "Numero de Secuencia: " << tcp.seq() << endl;
    cout << "Numero de Reconocimiento: " << tcp.ack_seq() << endl;
    cout << "Ventana: " << tcp.window() << endl;
    cout << "Checksum: " << tcp.checksum() << endl;
    cout << "Puntero Urgente: " << tcp.urg_ptr() << endl;
    cout << endl;
}

void readUDP(const PDU &pdu)
{
    const UDP &udp = pdu.rfind_pdu<UDP>();
    cout << "CAPA UDP: " << endl;
    cout << "Puerto destino: " << udp.dport() << endl;
    cout << "Puerto origen: " << udp.sport() << endl;
    cout << "Longitud: " << udp.length() << endl;
    cout << "Checksum: " << udp.checksum() << endl;
    cout << endl;
}
