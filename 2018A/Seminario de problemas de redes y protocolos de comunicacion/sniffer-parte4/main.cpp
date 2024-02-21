#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;

string binario(int ex){
    int numero=ex;
    int a=0;
    string binario = "";
    if(numero>0){
        while(numero>0){
            if(numero%2 == 0){
                binario = "0"+binario;
            }else{
                binario = "1"+binario;
            }
            numero= (int)numero/2;
            a++;
        }
    }else if(numero == 0){
        while(a<8){
            binario="0"+binario;
            a++;
        }
    }
    while(a<8){
        binario="0"+binario;
        a++;
    }
    return binario;
}

unsigned long HexToDec(char hex[]){
  char *hexstr;
  int length = 0;
  const int base = 16;     // Base of Hexadecimal Number
  unsigned long decnum = 0;
  int i;

  // Now Find the length of Hexadecimal Number
  for (hexstr = hex; *hexstr != '\0'; hexstr++){
      length++;
    }

  // Now Find Hexadecimal Number
  hexstr = hex;
  for (i = 0; *hexstr != '\0' && i < length; i++, hexstr++) {
      // Compare *hexstr with ASCII values
      if (*hexstr >= 48 && *hexstr <= 57) {  // is *hexstr Between 0-9
          decnum += (((int)(*hexstr)) - 48) * pow(base, length - i - 1);
        }
      else if ((*hexstr >= 65 && *hexstr <= 70))  {  // is *hexstr Between A-F
          decnum += (((int)(*hexstr)) - 55) * pow(base, length - i - 1);
        }
      else if (*hexstr >= 97 && *hexstr <= 102) {  // is *hexstr Between a-f
          decnum += (((int)(*hexstr)) - 87) * pow(base, length - i - 1);
        }
      else {
            cout<<"Numero Hexadecimal Invalido\n";
        }
    }
  return decnum;
}
class Ethernet ///Clase para la cabecera de Ethernet
{
public:
    unsigned long decnum[114];
    int cont=0,cont1=0,cont2=0;
    long protocolo;
    char temp[9];
    char temp1[13];///Direccion origen
    char temp2[13];///Direccion destino
    char temp3[5];///Tipo de servicio
    char temp4[3];///Version
    char temp5[2];
    char temp6[5];
    int flag,flag1;
    string bin;
    void decod_fich()///Funcion para extraer y decodificar
    {
        ifstream Lectura("Trama.txt");
        if(!Lectura.good())
        {
            cout<<"No existe el archivo o ah sido movido"<<endl;
        }
        else
        {
            Lectura.read((char *)&temp1,12);
            temp1[12]='\0';
            cout<<"\tTrama Ethernet"<<endl;
            cout<<"Direccion origen(Hex):"<<temp1<<endl;
            while(temp1[cont]!='\0')
            {
                if(cont1==2)
                {
                   temp[2]='\0';
                   decnum[cont2]=HexToDec(temp);
                   cont1=0;
                   cont2++;
                }
                temp[cont1]=temp1[cont];
                cont++;
                cont1++;
            }
            decnum[cont2]=HexToDec(temp);
            cont2++;
            cout<<"Direccion Origen(Dec):"<<decnum[0]<<"."<<decnum[1]<<"."<<decnum[2]<<"."<<decnum[3]<<"."<<decnum[4]<<"."<<decnum[5]<<endl;
            Lectura.read((char *)&temp2,12);
            temp2[12]='\0';
            cout<<"Direccion destino(Hex):"<<temp2<<endl;
            cont=0;
            cont1=0;
            while(temp2[cont]!='\0')
            {
                if(cont1==2)
                {
                   temp[2]='\0';
                   decnum[cont2]=HexToDec(temp);
                   cont1=0;
                   cont2++;
                }
                temp[cont1]=temp2[cont];
                cont++;
                cont1++;
            }
            decnum[cont2]=HexToDec(temp);
            cont2++;
            cout<<"Direccion Origen(Dec):"<<decnum[6]<<"."<<decnum[7]<<"."<<decnum[8]<<"."<<decnum[9]<<"."<<decnum[10]<<"."<<decnum[11]<<endl;
            Lectura.read((char *)&temp3,4);
            temp3[4]='\0';
            cout<<"Tipo de servicio(Hex):"<<temp3<<endl;
            cont=0;
            cont1=0;
            while(temp3[cont]!='\0')
            {
                if(cont1==2)
                {
                   temp[2]='\0';
                   decnum[cont2]=HexToDec(temp);
                   cont1=0;
                   cont2++;
                }
                temp[cont1]=temp3[cont];
                cont++;
                cont1++;
            }
            decnum[cont2]=HexToDec(temp);
            cont2++;
            //cout<<"Tipo de servicio(Dec):"<<decnum[12]<<" "<<decnum[13]<<endl;
            if(strcmp(temp3,"0200")==0)
            {
                cout<<"Tipo de protocolo: programa potencialmente no deseado"<<endl;
            }else if(strcmp(temp3,"0800")==0)
            {
                cout<<"Tipo de protocolo: IP\tInternet Protocol version 4 (IPv4)"<<endl;
                flag=1;
            }else if(strcmp(temp3,"0806")==0)
            {
                cout<<"Tipo de protocolo: ARP\tAddress Resolution Protocol (ARP)"<<endl;
                flag=2;
            }else if(strcmp(temp3,"8035")==0)
            {
                cout<<"Tipo de protocolo: RARP"<<endl;
            }else if(strcmp(temp3,"86DD")==0 || strcmp(temp3,"86dd")==0)
            {
                cout<<"Tipo de protocolo: IPv6"<<endl;
            }else if(strcmp(temp3,"8863")==0 || strcmp(temp3,"8864")==0)
            {
                cout<<"Tipo de protocolo: PPPoE"<<endl;
            }else if(strcmp(temp3,"8847")==0 || strcmp(temp3,"8848")==0)
            {
                cout<<"Tipo de protocolo: MPLS"<<endl;
            }else if(strcmp(temp3,"8000")==0)
            {
                cout<<"Tipo de protocolo: IS-IS"<<endl;
            }else if(strcmp(temp3,"8809")==0)
            {
                cout<<"Tipo de protocolo: LACP"<<endl;
            }else if(strcmp(temp3,"888E")==0 || strcmp(temp3,"888e")==0)
            {
                cout<<"Tipo de protocolo: 802.1x"<<endl;
            }else{
                cout<<"Error protocolo desconocido o invalido"<<endl;
            }
            if(flag==1)
            {
                cout<<"\t     IP"<<endl;
                Lectura.read((char *)&temp4,2);
                temp4[2]='\0';
                temp5[1]='\0';
                temp5[0]=temp4[0];
                cout<<"Version y Longitud(Hex):"<<temp4<<endl;
                cont=0;
                cont1=0;
                while(temp5[cont]!='\0')
                {
                    temp[cont1]=temp5[cont];
                    temp[1]='\0';
                    decnum[cont2]=HexToDec(temp);
                    cont2++;
                    cont++;
                }
                if(decnum[14]==4){
                   cout<<"Version:("<<temp4[0]<<") IP version 4"<<endl;
                }else{
                   cout<<"Version:("<<temp4[0]<<") IP version 6"<<endl;
                }
                temp5[0]=temp4[0];
                cont=0;
                cont1=0;
                while(temp5[cont]!='\0')
                {
                    temp[cont1]=temp5[cont];
                    temp[1]='\0';
                    decnum[cont2]=HexToDec(temp);
                    cont2++;
                    cont++;
                }
                //cout<<"Longitud:"<<(decnum[15]*32)/8<<" bytes"<<endl;
                Lectura.read((char *)&temp4,2);
                cout<<"Tipo de servicio(Hex): "<<temp4<<endl;
                cont=0;
                cont1=0;
                while(temp4[cont]!='\0')
                {
                    if(cont1==2)
                    {
                       temp[2]='\0';
                       decnum[cont2]=HexToDec(temp);
                       cont1=0;
                       cont2++;
                    }
                    temp[cont1]=temp4[cont];
                    cont++;
                    cont1++;
                }
                decnum[cont2]=HexToDec(temp);
                cout<<"Precedencia: ";
                bin=binario(decnum[cont2]);
                temp6[0]=bin.at(0);
                temp6[1]=bin.at(1);
                temp6[2]=bin.at(2);
                temp6[3]='\0';
                if(strcmp(temp6,"000")==0){
                    cout<<"Rutina"<<endl;
                }else if(strcmp(temp6,"001")==0){
                    cout<<"Prioridad"<<endl;
                }else if(strcmp(temp6,"010")==0){
                    cout<<"Inmediato"<<endl;
                }else if(strcmp(temp6,"011")==0){
                    cout<<"Flash"<<endl;
                }else if(strcmp(temp6,"100")==0){
                    cout<<"Flash override"<<endl;
                }else if(strcmp(temp6,"101")==0){
                    cout<<"Critico"<<endl;
                }else if(strcmp(temp6,"110")==0){
                    cout<<"Control de red(Internetwork control)"<<endl;
                }else if(strcmp(temp6,"111")==0){
                    cout<<"Control de red(Network control)"<<endl;
                }
                temp6[0]=bin.at(3);
                temp6[1]=bin.at(4);
                temp6[2]=bin.at(5);
                temp6[3]=bin.at(6);
                temp6[4]='\0';
                cout<<"TOS Tipo de servicio: ";
                if(strcmp(temp6,"1000")==0){
                    cout<<"Minimizar retardo"<<endl;
                }else if(strcmp(temp6,"0100")==0){
                    cout<<"Maximizar la intensidad de flujo"<<endl;
                }else if(strcmp(temp6,"0010")==0){
                    cout<<"Maximizar la fiabilidad"<<endl;
                }else if(strcmp(temp6,"0001")==0){
                    cout<<"Minimizar el coste monetario"<<endl;
                }else if(strcmp(temp6,"0000")==0){
                    cout<<"Servicio normal"<<endl;
                }
                cont2++;
                Lectura.read((char *)&temp3,4);
                cout<<"Longitud Total Del Paquete(Hex):"<<temp3<<endl;
                cont=0;
                cont1=0;
                while(temp3[cont]!='\0')
                {
                    if(cont1==2)
                    {
                       temp[2]='\0';
                       decnum[cont2]=HexToDec(temp);
                       cont1=0;
                       cont2++;
                    }
                    temp[cont1]=temp3[cont];
                    cont++;
                    cont1++;
                }
                decnum[cont2]=HexToDec(temp);
                cout<<"Longitud: "<<decnum[cont2]<<" bytes"<<endl;
                cont2++;
                Lectura.read((char *)&temp3,4);
                cout<<"Identificacion(Hex): "<<temp3<<endl;
                Lectura.read((char *)&temp4,2);
                cout<<"Banderas(Hex):"<<temp4<<endl;
                cont=0;
                cont1=0;
                while(temp4[cont]!='\0')
                {
                    if(cont1==2)
                    {
                       temp[2]='\0';
                       decnum[cont2]=HexToDec(temp);
                       cont1=0;
                       cont2++;
                    }
                    temp[cont1]=temp4[cont];
                    cont++;
                    cont1++;
                }
                decnum[cont2]=HexToDec(temp);
                bin=binario(decnum[cont2]);
                cont2++;
                temp6[0]=bin.at(0);
                temp6[1]=bin.at(1);
                temp6[2]=bin.at(2);
                temp6[3]='\0';
                if(temp6[1]=='0'){
                    cout<<"DF No fragmentar(Don't Fragment): Se permite la fragmentacion"<<endl;
                }else{
                    cout<<"DF No fragmentar(Don't Fragment): No se permite la fragmentacion"<<endl;
                }
                if(temp6[2]=='0'){
                    cout<<"MF Mas fragmentos(More fragments): Ultimo fragmento del datagrama"<<endl;
                }else{
                    cout<<"MF Mas fragmentos(More fragments): No es el ultimo fragmento del datagrama"<<endl;
                }
                Lectura.read((char *)&temp4,2);
                //cout<<"Desplazamiento de la fragmentacion: "<<endl;
                Lectura.read((char *)&temp4,2);
                cont=0;
                cont1=0;
                while(temp4[cont]!='\0')
                {
                    if(cont1==2)
                    {
                       temp[2]='\0';
                       decnum[cont2]=HexToDec(temp);
                       cont1=0;
                       cont2++;
                    }
                    temp[cont1]=temp4[cont];
                    cont++;
                    cont1++;
                }
                decnum[cont2]=HexToDec(temp);
                cout<<"Tiempo de vida: "<<decnum[cont2]<<" s"<<endl;
                cont2++;
                Lectura.read((char *)&temp4,2);
                cout<<"Protocolo(Hex): "<<temp4<<endl;
                cont=0;
                cont1=0;
                while(temp4[cont]!='\0')
                {
                    if(cont1==2)
                    {
                       temp[2]='\0';
                       decnum[cont2]=HexToDec(temp);
                       cont1=0;
                       cont2++;
                    }
                    temp[cont1]=temp4[cont];
                    cont++;
                    cont1++;
                }
                decnum[cont2]=HexToDec(temp);
                switch(decnum[cont2]){
                    case 1:
                        cout<<"ICMP (Internet Control Message Protocol)"<<endl;
                    break;
                    case 2:
                        cout<<"IGMP (Internet Group Management Protocol)"<<endl;
                    break;
                    case 3:
                        cout<<"GGP (Gateway-to-Gateway Protocol)"<<endl;
                    break;
                    case 4:
                        cout<<"IP (IP encapsulation)"<<endl;
                    break;
                    case 5:
                        cout<<"Flujo(Stream)"<<endl;
                    break;
                    case 6:
                        cout<<"TCP (Transmission Control)"<<endl;
                        flag1=1;
                    break;
                    case 8:
                        cout<<"EGP (Exterior Gateway Protocol)"<<endl;
                    break;
                    case 9:
                        cout<<"PIRP (Private Interior Routing Protocol)"<<endl;
                    break;
                    case 17:
                        cout<<"UDP (User Datagram)"<<endl;
                        flag1=2;
                    break;
                    case 89:
                        cout<<"OSPF (Open Shortest Path First)"<<endl;
                    break;
                    default:
                        cout<<"Protocolo desconocido"<<endl;
                        break;
                }
                Lectura.read((char *)&temp3,4);
                cout<<"Checksum(Hex): "<<temp3<<endl;
                Lectura.read((char *)&temp1,8);
                temp1[8]='\0';
                cout<<"Direccion IP origen(Hex): "<<temp1<<endl;
                cont=0;
                cont1=0;
                while(temp1[cont]!='\0')
                {
                    if(cont1==2)
                    {
                       temp[2]='\0';
                       decnum[cont2]=HexToDec(temp);
                       cont1=0;
                       cont2++;
                    }
                    temp[cont1]=temp1[cont];
                    cont++;
                    cont1++;
                }
                decnum[cont2]=HexToDec(temp);
                cout<<decnum[cont2-3]<<"."<<decnum[cont2-2]<<"."<<decnum[cont2-1]<<"."<<decnum[cont2]<<endl;
                cont2++;
                Lectura.read((char *)&temp1,8);
                cout<<"Direccion IP Destino(Hex): "<<temp1<<endl;
                cont=0;
                cont1=0;
                while(temp1[cont]!='\0')
                {
                    if(cont1==2)
                    {
                       temp[2]='\0';
                       decnum[cont2]=HexToDec(temp);
                       cont1=0;
                       cont2++;
                    }
                    temp[cont1]=temp1[cont];
                    cont++;
                    cont1++;
                }
                decnum[cont2]=HexToDec(temp);
                cout<<decnum[cont2-3]<<"."<<decnum[cont2-2]<<"."<<decnum[cont2-1]<<"."<<decnum[cont2]<<endl;
                cont2++;
                if(flag1==1)
                {
                    cout<<"\t       TCP"<<endl;
                    Lectura.read((char *)&temp3,4);
                    cout<<"Direccion de puerto de origen(Hex):"<<temp3<<endl;
                    Lectura.read((char *)&temp3,4);
                    cout<<"Direccion de puerto de destino(Hex):"<<temp3<<endl;
                    Lectura.read((char *)&temp1,8);
                    cout<<"Numero de secuencia(Hex): "<<temp1<<endl;
                    Lectura.read((char *)&temp1,8);
                    cout<<"Numero de confirmacion(Hex): "<<temp1<<endl;
                    Lectura.read((char *)&temp4,2);
                    cout<<"Longitud de la cabecera(Hex): "<<temp4<<endl;
                    Lectura.read((char *)&temp4,2);
                    cout<<"URG, ACK, PSH, RST, SYN, FIN(Hex): "<<temp4<<endl;
                    Lectura.read((char *)&temp3,4);
                    cout<<"Tamano de la ventana(Hex): "<<temp3<<endl;
                    Lectura.read((char *)&temp3,4);
                    cout<<"Checksum(Hex):"<<temp3<<endl;
                    Lectura.read((char *)&temp3,4);
                    cout<<"Punteto Urgente(Hex): "<<temp3<<endl;
                    Lectura.read((char *)&temp2,6);
                    temp2[6]='\0';
                    cout<<"Opciones y relleno(Hex): "<<temp2<<endl;
                }else if(flag1==2)
                {
                    cout<<"\t       UDP"<<endl;
                    Lectura.read((char *)&temp3,4);
                    cout<<"Puerto de origen(Hex):"<<temp3<<endl;
                    Lectura.read((char *)&temp3,4);
                    cout<<"Puerto destino(Hex):"<<temp3<<endl;
                    Lectura.read((char *)&temp3,4);
                    cout<<"Longitud(Hex):"<<temp3<<endl;
                    Lectura.read((char *)&temp3,4);
                    cout<<"Checksum(Hex):"<<temp3<<endl;
                }
            }else if(flag==2)
            {
                cout<<"\t       ARP"<<endl;
                Lectura.read((char *)&temp3,4);
                cout<<"Hardware Type(Hex): "<<temp3<<endl;
                Lectura.read((char *)&temp3,4);
                cout<<"Protocol Type(Hex): "<<temp3<<endl;
                Lectura.read((char *)&temp4,2);
                temp4[2]='\0';
                cout<<"Hardware size(Hex): "<<temp4<<endl;
                Lectura.read((char *)&temp4,2);
                cout<<"Protocol size(Hex): "<<temp4<<endl;
                Lectura.read((char *)&temp3,4);
                cout<<"Operacion(Hex): "<<temp3;
                if(strcmp(temp6,"0001")==0){
                    cout<<"\tPeticion"<<endl;
                }else{
                    cout<<"\tRespuesta"<<endl;
                }
                Lectura.read((char *)&temp1,12);
                cout<<"Sender MAC address(Hex): "<<temp1<<endl;
                temp[8]='\0';
                Lectura.read((char *)&temp,8);
                cout<<"Sender IP address(Hex): "<<temp<<endl;
                Lectura.read((char *)&temp1,12);
                cout<<"Target MAC address(Hex): "<<temp1<<endl;
                Lectura.read((char *)&temp,8);
                cout<<"Target IP address(Hex): "<<temp<<endl;
            }
            Lectura.close();
        }
    }
};
int main()
{
    Ethernet A;
    char opc;
    do{
        cout<<".....:::::Sniffer:::::......"<<endl;
        cout<<".....::::::::Menu:::::::......"<<endl;
        cout<<"1.-Extraer de un archivo"<<endl;
        cout<<"2.-Salir del programa"<<endl;
        cout<<"Que opcion deseas tomar: "<<endl;
        cin>>opc;
        //system("cls");
        switch(opc)
        {
            case '1':
                A.decod_fich();
                break;
            case '2':
                cout<<"Fin del programa"<<endl;
                break;
            default:
                cout<<"Error"<<endl;
                break;
        }

    }while(opc != '2');
    return 0;
}
