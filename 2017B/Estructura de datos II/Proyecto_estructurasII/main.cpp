#include <iostream>
#include <fstream>
using namespace std;

struct cliente {
    char codigo[5]; // mascara (formato de captura) CCDDD
    char nombre[20];
    char apellido[2][20];
    char sexo[1];
    char direccion[45];
    char ciudad[32];
    char telefono[12];
    char pais_origen[15];
}datos;

static struct {
    short cont_reg;
    short apt_ini;
    char relleno[1];
}encabezado;

int main()
{
    char a;
    do{
        cout<<"\n\n\n CARTERA DE CLIENTES DEL GRUPO ZARA \n ";
        cout<<"\n\n OPCIONES:\n\n ";
        cout<<"\n1. AGREGAR UN NUEVO CLIENTE\n";
        cout<<"\n2. EXTRAER UN CLIENTE PARA CONSULTAR SUS DATOS\n"; /* Agregar un submenu con las opciones: a) Todos los registros, b) Un sólo registro*/
        cout<<"\n3. BORRAR UN CLIENTE LOGICAMENTE\n";
        cout<<"\n4. ACTUALIZAR LOS DATOS DE UN CLIENTE\n"; /*Agregar un submenu con las opciones: a) Código b) Nombre c) …….*/
        cout<<"\n5. MOSTRAR LA LISTA DE LUGARES DISPONIBLES\n";
        cout<<"\n6. SALIR DEL PROGRAMA\n\n";
        cout<<"DIGITA EL NUMERO DE TU ELECCION: ";
        cin>>a;
        cin.ignore(10000,'\n');
        if(a=='1'){
            cout<<"Nombre del cliente: ";
            cin.getline(datos.nombre,20);

            cout<<"Primer apellido: ";
            cin.getline(datos.apellido[1],20);

            cout<<"Segundo apellido: ";
            cin.getline(datos.apellido[2],20);

            cout<<"Direccion: ";
            cin.getline(datos.direccion,45);

            cout<<"Ciudad: ";
            cin.getline(datos.ciudad,32);

            cout<<"Telefono: ";
            cin.getline(datos.telefono,12);

            cout<<"Pais de origen: ";
            cin.getline(datos.pais_origen,15);

            cout<<"Sexo(F|M): ";
            cin>>datos.sexo;
            cin.ignore(10000,'\n');

            cout<<datos.nombre<<'|'<<datos.apellido[1]<<'|'<<datos.apellido[2]<<'|'<<datos.sexo<<'|'<<datos.direccion<<'|'<<datos.ciudad<<'|'<<datos.telefono<<'|'<<datos.pais_origen<<endl;
            ofstream Archivo("GrupoZARA.txt",ios::app);
            Archivo<<datos.nombre<<'|'<<datos.apellido[1]<<'|'<<datos.apellido[2]<<'|'<<datos.sexo<<'|'<<datos.direccion<<'|'<<datos.ciudad<<'|'<<datos.telefono<<'|'<<datos.pais_origen;
            Archivo.close();
        }else if(a=='2'){
            char b;
            cout<<".................................................."<<endl;
            cout<<"\na) Todos los registros \n";
            cout<<"\nb) Un solo registro \n"<<endl;
            cout<<"Digita la la letra de tu eleccion: ";
            cin>>b;
            if(b=='a'){
            }else if(b=='b'){
            }else{
                cout<<"OPCION NO EXISTENTE"<<endl;
                cout<<".................................................."<<endl;
            }
        }else if(a=='3'){
            cout<<"Bla"<<endl;
        }else if(a=='4'){
            char c;
            cout<<".................................................."<<endl;
            cout<<"\na) Codigo \n"<<endl;
            cout<<"\nb) Nombre \n"<<endl;
            cout<<"\nc) Apellido \n"<<endl;
            cout<<"\nd) Sexo \n"<<endl;
            cout<<"\ne) Direccion \n"<<endl;
            cout<<"\nf) Ciudad \n"<<endl;
            cout<<"\ng) Telefono \n"<<endl;
            cout<<"\nh) Pais de origen \n"<<endl;
            cout<<"Digita la la letra de tu eleccion: ";
            cin>>c;
            if(c=='a'){
            }else if(c=='b'){
            }else if(c=='c'){
            }else if(c=='d'){
            }else if(c=='e'){
            }else if(c=='f'){
            }else if(c=='g'){
            }else if(c=='h'){
            }else{
                cout<<"OPCION NO EXISTENTE"<<endl;
                cout<<".................................................."<<endl;
            }
        }else if(a=='5'){
        }else if(a=='6'){
            cout<<"Fin del programa"<<endl;
        }else{
            cout<<"OPCION NO EXISTENTE"<<endl;
            cout<<".................................................."<<endl;
        }
    }while(a!='6');
    return 0;
}
