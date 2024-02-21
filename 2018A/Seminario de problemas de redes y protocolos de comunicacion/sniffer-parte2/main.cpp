#include <stdio.h>
#include <io.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
/*
char* conversor(char a[])
{

   ///strtol(buffer,NULL,16);
   ///cout<<"Buffer: "<<(unsigned)strtol(buffer,NULL,10)<<endl;
   while(a[i]!='\0')
   {
       if(a[i]=='0')
       {
           buffer[i]=a[i];
           cout<<"Prueba2:"<<buffer<<endl;
       }
       if(a[i]>='1'&&a[i]<='9')
       {
           k = (int)a[i];
           cout<<"K:"<<k<<endl;
           k = k*16^j;
           memcpy(&k,buffer,sizeof(int));
           cout<<"Prueba3:"<<a<<endl;
       }
       if(a[j]==2)
       {
           j=0;
           if(h!=4)
            buffer[i]='.';
           else
            buffer[i]='/';
            cout<<"Prueba4:"<<a<<endl;
       }
       i++;
       j++;
   }
}
/*
char* conversor(char a[])
{

   ///strtol(buffer,NULL,16);
   ///cout<<"Buffer: "<<(unsigned)strtol(buffer,NULL,10)<<endl;
   while(a[i]!='\0')
   {
       if(a[i]=='0')
       {
           buffer[i]=a[i];
           cout<<"Prueba2:"<<a<<endl;
       }
       if(a[i]>='1'&&a[i]<='9')
       {
           k = (int)a[i];
           cout<<"K:"<<k<<endl;
           k = k*16^j;
           memcpy(&k,buffer,sizeof(int));
           cout<<"Prueba3:"<<a<<endl;
       }
       if(a[j]==2)
       {
           j=0;
           if(h!=4)
            buffer[i]='.';
           else
            buffer[i]='/';
            cout<<"Prueba4:"<<a<<endl;
       }
       i++;
       j++;
   }
}
*/
/*
unsigned long conversor(char hex[])
{
    char *hexstr;
    int length = 0;
    const int base = 16;     // Base of Hexadecimal Number
    unsigned long decnum = 0;
    int i;

    // Now Find the length of Hexadecimal Number
    for (hexstr = hex; *hexstr != '\0'; hexstr++)
    {
	length++;
    }

    // Now Find Hexadecimal Number
    hexstr = hex;
    for (i = 0; *hexstr != '\0' && i < length; i++, hexstr++)
    {
	// Compare *hexstr with ASCII values
	if (*hexstr >= 48 && *hexstr <= 57)   // is *hexstr Between 0-9
	{
	    decnum += (((int)(*hexstr)) - 48) * pow(base, length - i - 1);
	}
	else if ((*hexstr >= 65 && *hexstr <= 70))   // is *hexstr Between A-F
	{
	    decnum += (((int)(*hexstr)) - 55) * pow(base, length - i - 1);
	}
	else if (*hexstr >= 97 && *hexstr <= 102)   // is *hexstr Between a-f
	{
	    decnum += (((int)(*hexstr)) - 87) * pow(base, length - i - 1);
	}
	else
	{
	    cout<<"Invalid Hexadecimal Number \n";

	}
    }
    return decnum;
}
*/
/*
char* conversor(char a[])
{
    int i;
    i = BitConverter.ToInt32(a,0);
    cout<<"i:"<<i<<" "<<"char:"<<a<<endl;
}

char* conversor(char a[])
{
    int i;
    i = strtol(a,&a,10);
    cout<<"i:"<<i<<" "<<"char:"<<a<<endl;
}

char* conversor(char a[])
{
    char *p;
    int number = strtol(a,&p,16);
    cout<<"B"<<number<<endl;
}
*/
class Ethernet ///Clase para la cabecera de Ethernet
{
public:
    char Dir_Org[12];///Direccion origen
    char Dir_Des[12];///Direccion destino
    char Tipo_Ser[4];///Tipo de servicio
    //unsigned long decnum;
    void decod_fich()///Funcion para extraer y decodificar
    {
        ifstream Lectura("Trama.txt",ifstream::binary);
        if(!Lectura.good())
        {
            cout<<"No existe el archivo o ah sido movido"<<endl;
        }
        else
        {
            Lectura.read(Dir_Org,12);
            Dir_Org[12]='\0';
            cout<<"Direccion origen: "<<Dir_Org<<endl;
            //decnum = conversor(Dir_Org);
            //cout<<"Direccion origen(dec): "<<decnum<<endl;
            Lectura.read(Dir_Des,12);
            Dir_Des[12]='\0';
            cout<<"Direccion destino: "<<Dir_Des<<endl;
            //decnum = conversor(Dir_Des);
            //cout<<"Direccion destino(dec): "<<Dir_Des<<endl;
            Lectura.read(Tipo_Ser,4);
            Tipo_Ser[4]='\0';
            cout<<"Tipo de servicio: "<<Tipo_Ser<<endl;
            //decnum = conversor(Tipo_Ser);
            //cout<<"Tipo de servicio(cec): "<<Tipo_Ser<<endl;
        }
        Lectura.close();
    }
};
int main()
{
    string texto="3314326008999929999";
    cout<<sizeof(texto)<<endl;
    char opc;
    do{
        cout<<".....:::::Esqueleto:::::......"<<endl;
        cout<<"1.-Extraer de un archivo"<<endl;
        cout<<"2.-Extraer en tiempo real"<<endl;
        cout<<"3.-Salir del programa"<<endl;
        cout<<"Que opcion deseas tomar: "<<endl;
        cin>>opc;
        switch(opc)
        {
            case '1':
                Ethernet A;
                A.decod_fich();
                break;
            case '2':
                cout<<"En desarrollo"<<endl;
                break;
            case '3':
                cout<<"Fin del programa"<<endl;
                break;
            default:
                cout<<"Error"<<endl;
                break;
        }
    }while(opc != '3');
    return 0;
}
