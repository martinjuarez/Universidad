#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;

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
            }else if(strcmp(temp3,"0806")==0)
            {
                cout<<"Tipo de protocolo: ARP\tAddress Resolution Protocol (ARP)"<<endl;
            }else if(strcmp(temp3,"8035")==0)
            {
                cout<<"Tipo de protocolo: RARP"<<endl;
            }else if(strcmp(temp3,"86DD")==0)
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
            }else if(strcmp(temp3,"888E")==0)
            {
                cout<<"Tipo de protocolo: 802.1x"<<endl;
            }else{
                cout<<"Error protocolo desconocido o invalido"<<endl;
            }
        }
        Lectura.close();
    }
};
int main()
{
    Ethernet A;
    char opc;
    do{
        cout<<".....:::::Esqueleto:::::......"<<endl;
        cout<<".....::::::::Menu:::::::......"<<endl;
        cout<<"1.-Extraer de un archivo"<<endl;
        cout<<"2.-Salir del programa"<<endl;
        cout<<"Que opcion deseas tomar: "<<endl;
        cin>>opc;
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
