#include "Empleados.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <time.h>


using namespace std;
Empleados::Empleados()
{
    //ctor
}
Empleados::~Empleados()
{
    //dtor
}
void Empleados::ClearScreen()
{
system("CLS");
}
void Empleados::Altas()
{
    srand( time(NULL) );
    ClearScreen();
    Empleado empleado;
    cout<<"\t\tAGREGAR A UN NUEVO EMPLEADO"<<endl<<endl<<endl;
    int i;
    ofstream escribir;
    ifstream revisar;
    string codigoaux;
    bool existe= false;

    escribir.open("Empleados.txt",ios::app);
    revisar.open("Empleados.txt");
    if(escribir.is_open())
    {

            cout<<"INGRESE EL NOMBRE DEL CLIENTE:          "<<endl;
            cin>>empleado.nombre;
            cout<<"INGRESE EL APELLIDO DEL CLIENTE:        "<<endl;
            cin>>empleado.apellido;
            cout<<"INGRESE EL SEXO DEL CLIENTE:            "<<endl;
            cin>>empleado.sexo;
            cout<<"INGRESE LA DIRECCION DEL CLIENTE:       "<<endl;
            cin>>empleado.direccion;
            cout<<"INGRESE LA CIUDAD DEL CLIENTE:          "<<endl;
            cin>>empleado.ciudad;
            cout<<"INGRESE EL TELEFONO DEL CLIENTE:        "<<endl;
            cin>>empleado.telefono;
            cout<<"INGRESE EL PAIS DE ORIGEN DEL CLIENTE:  "<<endl;
            cin>>empleado.pais_origen;

             char cod_final[5]={empleado.nombre[0],empleado.nombre[1]};
            cod_final[2]=48+rand()%(58-48);
            cod_final[3]=48+rand()%(58-48);
            cod_final[4]=48+rand()%(58-48);
            cod_final[5] = '\0';
            cout<<"CODIGO FINAL:"<<cod_final<<endl;
             fflush(stdin);

            escribir<<empleado.cod_final<<"|"<<empleado.nombre<<"|"<<empleado.apellido<<"|"<<empleado.sexo<<"|"<<empleado.direccion<<"|"<<empleado.ciudad<<"|"<<empleado.telefono<<"|"<<empleado.pais_origen<<"|"<<activo<<"|";
            cout<<"\t\t REGISTRO AGREGADO EXITOSAMENTE          "<<endl;
            cout<<"\t\t ENTER PARA REGRESAR EL MENU PRINCIPAL.  "<<endl;
            system("pause");

    }
    else
    {
        cout<<"No se puede abrir el Archivo\n"<<endl;
    }

    escribir.close();
    revisar.close();
}

void Empleados::Bajas()
{
    cout<<"¡Hello world!";
}

void Empleados::Modificaciones()
{
    ClearScreen();
    Empleado empleado;
    cout<<"ACTUALIZACION DE LOS REGISTROS"<<endl<<endl;
    int i;
    ofstream auxMod;
    ifstream leer_mod;
    char    mod            [50];
    char    auxicodigo     [5];
    char    auxinombre     [20];
    char    auxiapellido   [40];
    char    auxisexo       [2];
    char    auxidireccion  [45];
    char    auxiciudad     [32];
    char    auxitelefono   [12];
    char    auxipais_origen[15];
    bool esta= false;
    bool existe;

    auxMod.open("Auxiliar_Modificar.txt",ios::app);
    leer_mod.open("Empleados.txt");

    if(auxMod.is_open() && leer_mod.is_open())
    {
        cout<<"Ingrese el Codigo del Empleado a Modificar:"<<endl;
        cin>>mod;
        while(!leer_mod.eof())
        {

           i=0;
            do
            {
                leer_mod.read((char*)&empleado.codigo[i],1);
                i++;
            }
            while(empleado.codigo[i-1]!='|'&&!leer_mod.eof());
            empleado.codigo[i-1]='\0';


            i=0;
            do
            {
                leer_mod.read((char*)&empleado.nombre[i],1);
                i++;
            }
            while(empleado.nombre[i-1]!='|'&&!leer_mod.eof());
            empleado.nombre[i-1]='\0';


            i=0;
            do
            {
                leer_mod.read((char*)&empleado.apellido[i],1);
                i++;
            }
            while(empleado.apellido[i-1]!='|'&&!leer_mod.eof());
            empleado.apellido[i-1]='\0';


            i=0;
            do
            {
                leer_mod.read((char*)&empleado.sexo[i],1);
                i++;
            }
            while(empleado.sexo[i-1]!='|'&&!leer_mod.eof());
            empleado.sexo[i-1]='\0';


            i=0;
            do
            {
                leer_mod.read((char*)&empleado.direccion[i],1);
                i++;
            }
            while(empleado.direccion[i-1]!='|'&&!leer_mod.eof());
            empleado.direccion[i-1]='\0';



            i=0;
            do
            {
                leer_mod.read((char*)&empleado.ciudad[i],1);
                i++;
            }
            while(empleado.ciudad[i-1]!='|'&&!leer_mod.eof());
            empleado.ciudad[i-1]='\0';


            i=0;
            do
            {
                leer_mod.read((char*)&empleado.telefono[i],1);
                i++;
            }
            while(empleado.telefono[i-1]!='|'&&!leer_mod.eof());
            empleado.telefono[i-1]='\0';

            i=0;
            do
            {
                leer_mod.read((char*)&empleado.pais_origen[i],1);
                i++;
            }
            while(empleado.pais_origen[i-1]!='|'&&!leer_mod.eof());
            empleado.pais_origen[i-1]='\0';

            i=0;
            do
            {
                leer_mod.read((char*)&activo[i],1);
                i++;
            }
            while(activo[i-1]!='|'&&!leer_mod.eof());
            activo[i-1]='\0';
            if(leer_mod.eof())
                break;

            if(strcmp(mod,empleado.nombre)==0 && strcmp(activo,auxAc)==0)
            {
                esta=true;
               // cout<<"\t\tCODIGO DEL EMPLEADO:        "<<empleado.codigo     <<endl;
                cout<<"\t\tNOMBRE DEL CLIENTE:        "<<empleado.nombre     <<endl;
                cout<<"\t\tAPELLIDO DEL CLIENTE:      "<<empleado.apellido   <<endl;
                cout<<"\t\tSEXO DEL CLIENTE:          "<<empleado.sexo       <<endl;
                cout<<"\t\tDIRECCION DEL CLIENTE:     "<<empleado.direccion  <<endl;
                cout<<"\t\tCIUDAD DEL CLIENTE:        "<<empleado.ciudad     <<endl;
                cout<<"\t\tTELEFONO DEL CLIENTE:      "<<empleado.telefono   <<endl;
                cout<<"\t\tPAIS ORIGEN DEL CLIENTE:   "<<empleado.pais_origen<<endl<<endl;
                int op;

                    //cout<<"\t\t1.Modificar el codigo del Empleado        "<<endl;
                    cout<<"\t\t2.Modificar el nombre del Cliente        "<<endl;
                    cout<<"\t\t3.Modificar el apellido del cliente      "<<endl;
                    cout<<"\t\t4.Modificar el sexo del cliente          "<<endl;
                    cout<<"\t\t5.Modificar la direccion del cliente     "<<endl;
                    cout<<"\t\t6.Modificar la ciudad del cliente        "<<endl;
                    cout<<"\t\t7.Modificar el telefono del cliente      "<<endl;
                    cout<<"\t\t8.Modificar el pais de origen del cliente"<<endl<<endl;
                    cout<<"\t\t9.Ninguno"<<endl;
                    cin>>op;
                    switch(op)
                    {
                    case 1:
                           cout<<"Ingrese el nuevo codigo:      "<<endl;
                           cin>>empleado.codigo;
                           cout<<"DATO MODIFICADO CORRECTAMENTE"<<endl;
                           system("pause");
                        break;
                        case 2:
                            cout<<"Ingrese el nuevo Nombre:      "<<endl;
                            cin>>empleado.nombre;
                            cout<<"DATO MODIFICADO CORRECTAMENTE"<<endl;
                            system("pause");
                            break;
                        case 3:
                            cout<<"Ingrese el nuevo Apellido: "<<endl;
                            cin>>empleado.apellido;
                            cout<<"DATO MODIFICADO CORRECTAMENTE"<<endl;
                            system("pause");
                            break;
                        case 4:
                            cout<<"Ingrese el nuevo Sexo:     "<<endl;
                            cin>>empleado.sexo;
                            cout<<"DATO MODIFICADO CORRECTAMENTE"<<endl;
                            system("pause");
                            break;
                        case 5:
                            cout<<"Ingrese la nueva Direccion: "<<endl;
                            cin>>empleado.direccion;
                            cout<<"DATO MODIFICADO CORRECTAMENTE"<<endl;
                            system("pause");
                            break;
                        case 6:
                            cout<<"Ingrese la nueva Ciudad: "<<endl;
                            cin>>empleado.ciudad;
                            cout<<"DATO MODIFICADO CORRECTAMENTE"<<endl;
                            system("pause");
                            break;
                        case 7:
                            cout<<"Ingrese el nuevo Telefono: "<<endl;
                            cin>>empleado.telefono;
                            cout<<"DATO MODIFICADO CORRECTAMENTE"<<endl;
                            system("pause");
                            break;
                        case 8:
                            cout<<"Ingrese el nuevo Pais de Origen: "<<endl;
                            cin>>empleado.pais_origen;
                            cout<<"DATO MODIFICADO CORRECTAMENTE"<<endl;
                            system("pause");
                            break;
                        case 9:
                            break;
                        }
                        auxMod<<empleado.codigo<<"|"<<empleado.nombre<<"|"<<empleado.apellido<<"|"<<empleado.sexo<<"|"<<empleado.direccion<<"|"<<empleado.ciudad<<"|"<<empleado.telefono<<"|"<<empleado.pais_origen<<"|"<<activo<<"|";
                }
                else
                {
                    auxMod<<empleado.codigo<<"|"<<empleado.nombre<<"|"<<empleado.apellido<<"|"<<empleado.sexo<<"|"<<empleado.direccion<<"|"<<empleado.ciudad<<"|"<<empleado.telefono<<"|"<<empleado.pais_origen<<"|"<<activo<<"|";
                }
            }
        }
        else
        {
            cout<<"No se pudo abrir el archivo"<<endl;
        }

        auxMod.close();
        leer_mod.close();

        remove("Empleados.txt");
        rename("Auxiliar_Modificar.txt","Empleados.txt");
}

void Empleados::Consultas()
{
    Empleados emp;
    emp.ClearScreen();
    int opc1;
    cout<<"\t\tINGRESE UNA OPCION   :       "<<endl<<endl;
    cout<<"\t\t1.CONSULTA INDIVIDUAL:       "<<endl;
    cout<<"\t\t2.CONSULTA GENERAL   :       "<<endl<<endl;
    cout<<"\t\t0.REGRESAR AL MENU PRINCIPAL:"<<endl;
    cout<<"\t\t";cin>>opc1;
    switch(opc1)
    {
     case 1:emp.ConsultaIndividual();
            break;
     case 2:emp.ConsultaGeneral();
            break;
     case 0:return;
            break;
    }
}

void Empleados::ConsultaIndividual()
{
    srand( time(NULL) );
    ClearScreen();
    Empleado empleado;
    cout<<"\t\tCONSULTA INDIVIDUAL:"<<endl;
    int i;
    char bus[50];
    bool encontrado=false;


    ifstream busqueda;
    busqueda.open("Empleados.txt");


    if(busqueda.is_open())
    {

        cout<<"INGRESE EL NOMBRE DEL CLIENTE A CONSULTAR"<<endl;
        cin>>bus;
        while(!busqueda.eof())
        {

            i=0;
            do
            {
                busqueda.read((char*)&empleado.codigo[i],1);
                i++;
            }
            while(empleado.codigo[i-1]!='|'&&!busqueda.eof());
            empleado.codigo[i-1]='\0';


            i=0;
            do
            {
                busqueda.read((char*)&empleado.nombre[i],1);
                i++;
            }
            while(empleado.nombre[i-1]!='|'&&!busqueda.eof());
            empleado.nombre[i-1]='\0';

            i=0;
            do
            {
                busqueda.read((char*)&empleado.apellido[i],1);
                i++;
            }
            while(empleado.apellido[i-1]!='|'&&!busqueda.eof());
            empleado.apellido[i-1]='\0';


            i=0;
            do
            {
                busqueda.read((char*)&empleado.sexo[i],1);
                i++;
            }
            while(empleado.sexo[i-1]!='|'&&!busqueda.eof());
            empleado.sexo[i-1]='\0';


            i=0;
            do
            {
                busqueda.read((char*)&empleado.direccion[i],1);
                i++;
            }
            while(empleado.direccion[i-1]!='|'&&!busqueda.eof());
            empleado.direccion[i-1]='\0';


            i=0;
            do
            {
                busqueda.read((char*)&empleado.ciudad[i],1);
                i++;
            }
            while(empleado.ciudad[i-1]!='|'&&!busqueda.eof());
            empleado.ciudad[i-1]='\0';


            i=0;
            do
            {
                busqueda.read((char*)&empleado.telefono[i],1);
                i++;
            }
            while(empleado.telefono[i-1]!='|'&&!busqueda.eof());
            empleado.telefono[i-1]='\0';

            i=0;
            do
            {
                busqueda.read((char*)&empleado.pais_origen[i],1);
                i++;
            }
            while(empleado.pais_origen[i-1]!='|'&&!busqueda.eof());
            empleado.pais_origen[i-1]='\0';


            i=0;
            do
            {
                busqueda.read((char*)&activo[i],1);
                i++;
            }
            while(activo[i-1]!='|'&&!busqueda.eof());
            activo [i-1] = '\0';
            if(busqueda.eof()) break;


            if(strcmp(bus,empleado.nombre)==0 and strcmp(activo,auxAc) ==0)
            {
                encontrado=true;
                //cout<<"\t\tNUMERO DE REGISTRO:         "<<empleado.cont     <<endl;
                cout<<"\t\tNOMBRE DEL CLIENTE:        "<<empleado.nombre     <<endl;
                cout<<"\t\tAPELLIDO DEL CLIENTE:      "<<empleado.apellido   <<endl;
                cout<<"\t\tSEXO DEL CLIENTE:          "<<empleado.sexo       <<endl;
                cout<<"\t\tDIRECCION DEL CLIENTE:     "<<empleado.direccion  <<endl;
                cout<<"\t\tCIUDAD DEL CLIENTE:        "<<empleado.ciudad     <<endl;
                cout<<"\t\tTELEFONO DEL CLIENTE:      "<<empleado.telefono   <<endl;
                cout<<"\t\tPAIS ORIGEN DEL CLIENTE:   "<<empleado.pais_origen<<endl;
                char cod_final[5]={empleado.nombre[0],empleado.nombre[1]};
                cod_final[2]=48+rand()%(58-48);
                cod_final[3]=48+rand()%(58-48);
                cod_final[4]=48+rand()%(58-48);
                cod_final[5] = '\0';
                cout<<"\t\tCODIGO FINAL:               "<<cod_final<<endl<<endl<<endl;
                fflush(stdin);
            }
            if(busqueda.eof())
            break;
        }
        if(encontrado==false)
        {
            cout<<"NO SE ENCONTRO AL EMPLEADO"<<endl;
        }
         system("pause");
    }
    else
    {
        cout<<"EL ARCHIVO NO ESTA"<<endl;
    }
    busqueda.close();
}

void Empleados::ConsultaGeneral()
{
    srand( time(NULL) );
    ClearScreen();
    Empleado empleado;
    cout<<"\t\t\t\tCONSULTA GENERAL"<<endl<<endl;
    int i;
    ifstream leer;
    leer.open("Empleados.txt",ios::app);
    if(leer.good())
    {
        while(!leer.eof())
        {
            i=0;
            do
            {
                leer.read((char*)&empleado.codigo[i],1);
                i++;
            }
            while(empleado.codigo[i-1]!='|'&&!leer.eof());
            empleado.codigo[i-1]='\0';


            i=0;
            do
            {
                leer.read((char*)&empleado.nombre[i],1);
                i++;
            }
            while(empleado.nombre[i-1]!='|'&&!leer.eof());
            empleado.nombre[i-1]='\0';


            i=0;
            do
            {
                leer.read((char*)&empleado.apellido[i],1);
                i++;
            }
            while(empleado.apellido[i-1]!='|'&&!leer.eof());
            empleado.apellido[i-1]='\0';


            i=0;
            do
            {
                leer.read((char*)&empleado.sexo[i],1);
                i++;
            }
            while(empleado.sexo[i-1]!='|'&&!leer.eof());
            empleado.sexo[i-1]='\0';


            i=0;
            do
            {
                leer.read((char*)&empleado.direccion[i],1);
                i++;
            }
            while(empleado.direccion[i-1]!='|'&&!leer.eof());
            empleado.direccion[i-1]='\0';



            i=0;
            do
            {
                leer.read((char*)&empleado.ciudad[i],1);
                i++;
            }
            while(empleado.ciudad[i-1]!='|'&&!leer.eof());
            empleado.ciudad[i-1]='\0';


            i=0;
            do
            {
                leer.read((char*)&empleado.telefono[i],1);
                i++;
            }
            while(empleado.telefono[i-1]!='|'&&!leer.eof());
            empleado.telefono[i-1]='\0';

            i=0;
            do
            {
                leer.read((char*)&empleado.pais_origen[i],1);
                i++;
            }
            while(empleado.pais_origen[i-1]!='|'&&!leer.eof());
            empleado.pais_origen[i-1]='\0';

            i=0;
            do
            {
                leer.read((char*)&activo[i],1);
                i++;
            }
            while(activo[i-1]!='|'&&!leer.eof());
            activo[i-1]='\0';
            if(leer.eof())
                break;
                if(leer.eof())
                break;

            if(strcmp(activo,auxAc)==0)
            {

                //cout<<"\t\tCODIGO DEL EMPLEADO:        "<<empleado.cont     <<endl;

                cout<<"\t\tNOMBRE DEL CLIENTE:        "<<empleado.nombre     <<endl;
                cout<<"\t\tAPELLIDO DEL CLIENTE:      "<<empleado.apellido   <<endl;
                cout<<"\t\tSEXO DEL CLIENTE:          "<<empleado.sexo       <<endl;
                cout<<"\t\tDIRECCION DEL CLIENTE:     "<<empleado.direccion  <<endl;
                cout<<"\t\tCIUDAD DEL CLIENTE:        "<<empleado.ciudad     <<endl;
                cout<<"\t\tTELEFONO DEL CLIENTE:      "<<empleado.telefono   <<endl;
                cout<<"\t\tPAIS ORIGEN DEL CLIENTE:   "<<empleado.pais_origen<<endl;
                char cod_final[5]={empleado.nombre[0],empleado.nombre[1]};
                cod_final[2]=48+rand()%(58-48);
                cod_final[3]=48+rand()%(58-48);
                cod_final[4]=48+rand()%(58-48);
                cod_final[5] = '\0';
                cout<<"\t\tCODIGO FINAL:              "<<cod_final<<endl<<endl<<endl;
                fflush(stdin);
            }

        }

    }

    else
    {
        cout<<"NO EXISTE EL ARCHIVO"<<endl;
    }
    system("pause");
    leer.close();
}

void Empleados::EliminacionLogica()
{
   ClearScreen();
   Empleado empleado;
   cout<<"\t\tELIMINACION LOGICA DE REGISTROS:"<<endl;
   ofstream auxMod;
        ifstream leer_mod;
        char mod[50];
        int i;
        bool esta= false;

        auxMod.open("Auxiliar_Modificar.txt",ios::out);
        leer_mod.open("Empleados.txt",ios::in);

        if(auxMod.is_open() && leer_mod.is_open())
        {
            cout<<"Ingrese el Nombre del CLIENTE a Desactivar:"<<endl;
            cin>>mod;
            while(!leer_mod.eof())
            {
                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.codigo[i],1);
                    i++;
                }
                while(empleado.codigo[i-1]!='|'&&!leer_mod.eof());
                empleado.codigo [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.nombre[i],1);
                    i++;
                }
                while(empleado.nombre[i-1]!='|'&&!leer_mod.eof());
                empleado.nombre [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.apellido[i],1);
                    i++;
                }
                while(empleado.apellido[i-1]!='|'&&!leer_mod.eof());
                empleado.apellido [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.sexo[i],1);
                    i++;
                }
                while(empleado.sexo[i-1]!='|'&&!leer_mod.eof());
                empleado.sexo [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.direccion[i],1);
                    i++;
                }
                while(empleado.direccion[i-1]!='|'&&!leer_mod.eof());
                empleado.direccion [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.ciudad[i],1);
                    i++;
                }
                while(empleado.ciudad[i-1]!='|'&&!leer_mod.eof());
                empleado.ciudad [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.telefono[i],1);
                    i++;
                }
                while(empleado.telefono[i-1]!='|'&&!leer_mod.eof());
                empleado.telefono [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.pais_origen[i],1);
                    i++;
                }
                while(empleado.pais_origen[i-1]!='|'&&!leer_mod.eof());
                empleado.pais_origen [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&activo[i],1);
                    i++;
                }
                while(activo[i-1]!='|'&&!leer_mod.eof());
                activo [i-1] = '\0';
                if(leer_mod.eof()) break;

                if(strcmp(mod,empleado.nombre)==0 && strcmp(activo,auxAc)==0)
                {
                    esta=true;
                //cout<<"\t\tCODIGO      DEL EMPLEADO:     "<<empleado.codigo     <<endl;
                cout<<"\t\tNOMBRE      DEL CLIENTE:     "<<empleado.nombre     <<endl;
                cout<<"\t\tAPELLIDO    DEL CLIENTE:     "<<empleado.apellido   <<endl;
                cout<<"\t\tSEXO        DEL CLIENTE:     "<<empleado.sexo       <<endl;
                cout<<"\t\tDIRECCION   DEL CLIENTE:     "<<empleado.direccion  <<endl;
                cout<<"\t\tCIUDAD      DEL CLIENTE:     "<<empleado.ciudad     <<endl;
                cout<<"\t\tTELEFONO    DEL CLIENTE:     "<<empleado.telefono   <<endl;
                cout<<"\t\tPAIS ORIGEN DEL CLIENTE:     "<<empleado.pais_origen<<endl<<endl;


                    cout<<"DATO DESACTIVADO"<<endl;
                    auxMod<<empleado.codigo<<"|"<<empleado.nombre<<"|"<<empleado.apellido<<"|"<<empleado.sexo<<"|"<<empleado.direccion<<"|"<<empleado.ciudad<<"|"<<empleado.telefono<<"|"<<empleado.pais_origen<<"|"<<inAct<<"|";
                    system("pause");
                }
                else if(strcmp(mod,empleado.nombre)==0 && strcmp(activo,auxAc)!=0)
                {
                    esta=true;

                //cout<<"\t\tCODIGO      DEL EMPLEADO:     "<<empleado.codigo     <<endl;
                cout<<"\t\tNOMBRE      DEL CLIENTE:     "<<empleado.nombre     <<endl;
                cout<<"\t\tAPELLIDO    DEL CLIENTE:     "<<empleado.apellido   <<endl;
                cout<<"\t\tSEXO        DEL CLIENTE:     "<<empleado.sexo       <<endl;
                cout<<"\t\tDIRECCION   DEL CLIENTE:     "<<empleado.direccion  <<endl;
                cout<<"\t\tCIUDAD      DEL CLIENTE:     "<<empleado.ciudad     <<endl;
                cout<<"\t\tTELEFONO    DEL CLIENTE:     "<<empleado.telefono   <<endl;
                cout<<"\t\tPAIS ORIGEN DEL CLIENTE:     "<<empleado.pais_origen<<endl<<endl;


                    cout<<"DATO ACTIVADO"<<endl;
                    auxMod<<empleado.codigo<<"|"<<empleado.nombre<<"|"<<empleado.apellido<<"|"<<empleado.sexo<<"|"<<empleado.direccion<<"|"<<empleado.ciudad<<"|"<<empleado.telefono<<"|"<<empleado.pais_origen<<"|"<<auxAc<<"|";
                    system("pause");
                }
                else
                {
                    auxMod<<empleado.codigo<<"|"<<empleado.nombre<<"|"<<empleado.apellido<<"|"<<empleado.sexo<<"|"<<empleado.direccion<<"|"<<empleado.ciudad<<"|"<<empleado.telefono<<"|"<<empleado.pais_origen<<"|"<<activo<<"|";
                }
            }
        }
        else
        {
            cout<<"No se puede abrir el Archivo"<<endl;
        }

        if(esta==false)
        {
            cout<<"El Codigo Ingresado No existe: "<<mod<<endl;

        }

        auxMod.close();
        leer_mod.close();

        remove("Empleados.txt");
        rename("Auxiliar_Modificar.txt","Empleados.txt");
}

void Empleados::MostrarLugaresDisp()
{
    ClearScreen();
    Empleado empleado;
    cout<<"\t\t\t\tCONSULTA DE LUGARES DISPONIBLES:"<<endl<<endl;
    int i;
    ifstream leer;
    leer.open("Empleados.txt",ios::app);
    if(leer.good())
    {
        while(!leer.eof())
        {

            i=0;
            do
            {
                leer.read((char*)&empleado.codigo[i],1);
                i++;
            }
            while(empleado.codigo[i-1]!='|'&&!leer.eof());
            empleado.codigo[i-1]='\0';


            i=0;
            do
            {
                leer.read((char*)&empleado.nombre[i],1);
                i++;
            }
            while(empleado.nombre[i-1]!='|'&&!leer.eof());
            empleado.nombre[i-1]='\0';


            i=0;
            do
            {
                leer.read((char*)&empleado.apellido[i],1);
                i++;
            }
            while(empleado.apellido[i-1]!='|'&&!leer.eof());
            empleado.apellido[i-1]='\0';


            i=0;
            do
            {
                leer.read((char*)&empleado.sexo[i],1);
                i++;
            }
            while(empleado.sexo[i-1]!='|'&&!leer.eof());
            empleado.sexo[i-1]='\0';


            i=0;
            do
            {
                leer.read((char*)&empleado.direccion[i],1);
                i++;
            }
            while(empleado.direccion[i-1]!='|'&&!leer.eof());
            empleado.direccion[i-1]='\0';



            i=0;
            do
            {
                leer.read((char*)&empleado.ciudad[i],1);
                i++;
            }
            while(empleado.ciudad[i-1]!='|'&&!leer.eof());
            empleado.ciudad[i-1]='\0';


            i=0;
            do
            {
                leer.read((char*)&empleado.telefono[i],1);
                i++;
            }
            while(empleado.telefono[i-1]!='|'&&!leer.eof());
            empleado.telefono[i-1]='\0';

            i=0;
            do
            {
                leer.read((char*)&empleado.pais_origen[i],1);
                i++;
            }
            while(empleado.pais_origen[i-1]!='|'&&!leer.eof());
            empleado.pais_origen[i-1]='\0';

            i=0;
            do
            {
                leer.read((char*)&activo[i],1);
                i++;
            }
            while(activo[i-1]!='|'&&!leer.eof());
            activo[i-1]='\0';
            if(leer.eof())
                break;
                if(leer.eof())
                break;

            if(strcmp(activo,inAct)==0)
            {
                //cout<<"\t\tCODIGO DEL EMPLEADO:        "<<empleado.codigo     <<endl;
                cout<<"\t\tNOMBRE DEL CLIENTE:        "<<empleado.nombre     <<endl;
                cout<<"\t\tAPELLIDO DEL CLIENTE:      "<<empleado.apellido   <<endl;
                cout<<"\t\tSEXO DEL CLIENTE:          "<<empleado.sexo       <<endl;
                cout<<"\t\tDIRECCION DEL CLIENTE:     "<<empleado.direccion  <<endl;
                cout<<"\t\tCIUDAD DEL CLIENTE:        "<<empleado.ciudad     <<endl;
                cout<<"\t\tTELEFONO DEL CLIENTE:      "<<empleado.telefono   <<endl;
                cout<<"\t\tPAIS ORIGEN DEL CLIENTE:   "<<empleado.pais_origen<<endl<<endl;
            }

        }

    }

    else
    {
        cout<<"NO EXISTE EL ARCHIVO"<<endl;
    }
    system("pause");
    leer.close();
}

void Empleados::Activacion()
{
        ClearScreen();
        Empleado empleado;
        ofstream auxMod;
        ifstream leer_mod;
        char mod[50];
        int i;
        bool esta= false;

        auxMod.open("Auxiliar_Modificar.txt",ios::out);
        leer_mod.open("Empleados.txt",ios::in);

        if(auxMod.is_open() && leer_mod.is_open())
        {
            cout<<"ACTIVACION DE UN REGISTRO ELIMINADO LOGICAMENTE"<<endl<<endl<<endl;
            cout<<"Ingrese el Nombre del CLIENTE Desactivado:"<<endl;
            cin>>mod;
            while(!leer_mod.eof())
            {
                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.codigo[i],1);
                    i++;
                }
                while(empleado.codigo[i-1]!='|'&&!leer_mod.eof());
                empleado.codigo [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.nombre[i],1);
                    i++;
                }
                while(empleado.nombre[i-1]!='|'&&!leer_mod.eof());
                empleado.nombre[i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.apellido[i],1);
                    i++;
                }
                while(empleado.apellido[i-1]!='|'&&!leer_mod.eof());
                empleado.apellido [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.sexo[i],1);
                    i++;
                }
                while(empleado.sexo[i-1]!='|'&&!leer_mod.eof());
                empleado.sexo [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.direccion[i],1);
                    i++;
                }
                while(empleado.direccion[i-1]!='|'&&!leer_mod.eof());
                empleado.direccion [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.ciudad[i],1);
                    i++;
                }
                while(empleado.ciudad[i-1]!='|'&&!leer_mod.eof());
                empleado.ciudad [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.telefono[i],1);
                    i++;
                }
                while(empleado.telefono[i-1]!='|'&&!leer_mod.eof());
                empleado.telefono [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&empleado.pais_origen[i],1);
                    i++;
                }
                while(empleado.pais_origen[i-1]!='|'&&!leer_mod.eof());
                empleado.pais_origen [i-1] = '\0';

                i=0;
                do
                {
                    leer_mod.read((char*)&activo[i],1);
                    i++;
                }
                while(activo[i-1]!='|'&&!leer_mod.eof());
                activo [i-1] = '\0';
                if(leer_mod.eof()) break;

                if(strcmp(mod,empleado.nombre)==0 && strcmp(activo,auxAc)!=0)
                {
                esta=true;
                //cout<<"\t\tCODIGO      DEL EMPLEADO:     "<<empleado.codigo     <<endl;
                cout<<"\t\tNOMBRE      DEL CLIENTE:     "<<empleado.nombre     <<endl;
                cout<<"\t\tAPELLIDO    DEL CLIENTE:     "<<empleado.apellido   <<endl;
                cout<<"\t\tSEXO        DEL CLIENTE:     "<<empleado.sexo       <<endl;
                cout<<"\t\tDIRECCION   DEL CLIENTE:     "<<empleado.direccion  <<endl;
                cout<<"\t\tCIUDAD      DEL CLIENTE:     "<<empleado.ciudad     <<endl;
                cout<<"\t\tTELEFONO    DEL CLIENTE:     "<<empleado.telefono   <<endl;
                cout<<"\t\tPAIS ORIGEN DEL CLIENTE:     "<<empleado.pais_origen<<endl<<endl;

                    cout<<"DATO ACTIVADO"<<endl;
                    auxMod<<empleado.codigo<<"|"<<empleado.nombre<<"|"<<empleado.apellido<<"|"<<empleado.sexo<<"|"<<empleado.direccion<<"|"<<empleado.ciudad<<"|"<<empleado.telefono<<"|"<<empleado.pais_origen<<"|"<<auxAc<<"|";
                }
                else
                {
                     auxMod<<empleado.codigo<<"|"<<empleado.nombre<<"|"<<empleado.apellido<<"|"<<empleado.sexo<<"|"<<empleado.direccion<<"|"<<empleado.ciudad<<"|"<<empleado.telefono<<"|"<<empleado.pais_origen<<"|"<<activo<<"|";
                }
            }
        }
        else
        {
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        }

        if(esta==false)
        {
            cout<<"No Existe ese CLIENTE:"<<mod<<endl;

        }

        auxMod.close();
        leer_mod.close();
        system("pause");

        remove("Empleados.txt");
        rename("Auxiliar_Modificar.txt","Empleados.txt");
}

