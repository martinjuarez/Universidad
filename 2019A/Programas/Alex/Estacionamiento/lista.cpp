#include "lista.h"
#include "monedas.h"
#include <bits/stdc++.h>
#include <Windows.h>
#include <cstdlib>
#include <iostream>

using namespace std;

string estacionamiento::obtener_hora(){
    SYSTEMTIME stBuffer;
    char buffer[9];
    string hora;

    GetLocalTime(&stBuffer);
    GetTimeFormat(LOCALE_SYSTEM_DEFAULT,
                  TIME_FORCE24HOURFORMAT,
                  &stBuffer, "hh':'mm':'ss",
                  buffer,
                  sizeof(buffer));
    hora = buffer;
    return hora;
}

void monedas::minimo(int V){
    // Inicializar resultado
    vector<int> respuesta;

    // Recorrido de la denominación
    for (int i=n-1; i>=0; i--)
    {
        // Encontrando las denominaciones
        while (V >= denominacion[i])
        {
           V -= denominacion[i];
           respuesta.push_back(denominacion[i]);
        }
    }

    // Imprimir resultado
    for (int i = 0; i < respuesta.size(); i++)
           cout << respuesta[i] << "  ";
}

int estacionamiento::cobro(string a, string b){
    string he, me, hs, ms;
    float dh,dm,dt;
    if(b.at(1) == ':'){
        b.at(5) = b.at(4);
        b.at(4) = b.at(3);
        b.at(3) = b.at(2);
        b.at(2) = ':';
        b.at(1) = b.at(0);
        b.at(0) = '0';
    }else if(b.at(4) == ' '){
        b.at(4) = b.at(3);
        b.at(3) = '0';
    }
    he = a.at(0);
    he = he + a.at(1);
    me = a.at(3);
    me = me + a.at(4);
    hs = b.at(0);
    hs = hs + b.at(1);
    ms = b.at(3);
    ms = ms + b.at(4);
    if(ms == me && atoi(hs.c_str()) > atoi(he.c_str())){
        dh = atoi(hs.c_str()) - atoi(he.c_str());
        dh = dh * 20;
        dt = 0;
    }else if(ms == me && atoi(hs.c_str()) < atoi(he.c_str())){
        dh = atoi(hs.c_str()) - (atoi(he.c_str())-1);
        dh = dh + 24;
        dh = dh * 20;
        dt = 0;
    }else if(ms != me && atoi(hs.c_str()) == (atoi(he.c_str())+1)){
        dh = 0;
        dh = dh * 20;
        if(atoi(ms.c_str()) > atoi(me.c_str())){
           dt = (atoi(ms.c_str()) - atoi(me.c_str()));
        }else{
           dt = atoi(ms.c_str()) - (atoi(me.c_str())-1);
           dt = dt + 59;
        }
    }else if(ms != me && atoi(hs.c_str()) != (atoi(he.c_str())+1)){
        if(atoi(hs.c_str()) > atoi(he.c_str())){
            dh = atoi(hs.c_str()) - atoi(he.c_str());
        }else if(atoi(hs.c_str()) < atoi(he.c_str())){
            dh = atoi(hs.c_str()) - (atoi(he.c_str())-1);
            dh = dh + 24;
        }
        dh = dh * 20;
        if(atoi(ms.c_str()) > atoi(me.c_str())){
           dt = (atoi(ms.c_str()) - atoi(me.c_str()));
        }else{
           dt = atoi(ms.c_str()) - (atoi(me.c_str())-1);
           dt = dt + 59;
        }
    }
    dm = (1 * 20);
    dm = dm / 60;
    dm = dm * dt;
    dh = dh + dm;
    return dh;
}
void estacionamiento::agregar_vehiculo(string placas, string hora_entrada){
    vehiculo *tmp = new vehiculo;
    tmp->sig = NULL;
    tmp->placas = placas;
    tmp->hora_entrada = hora_entrada;
    if(raiz == NULL){
        raiz = tmp;
    }else{
        tmp->sig = raiz;
        raiz = tmp;
    }
}

void estacionamiento::ver_vehiculos(){
    vehiculo *aux;
    aux = raiz;
    if(aux == NULL){
        cout<<"Lista de autos vacia"<<endl;
        cout<<'\n';
    }else{
        cout<<'\t'<<'\t'<<"Lista"<<endl;
        cout<<'\n';
        while(aux != NULL){
            cout<<"Placas: "<<aux->placas<<endl;
            cout<<"Hora de entrada: "<<aux->hora_entrada<<endl;
            cout<<'\n';
            aux = aux->sig;
        }
    }
}

void estacionamiento::egresar_vehiculos(string placas){
    int ayudaxD;
    string s;
    bool band = true;
    monedas z;
    vehiculo *aux;
    vehiculo *ant;
    aux = raiz;
    ant = NULL;
    if(raiz == NULL){
        cout<<"Lista de autos vacia"<<endl;
        cout<<'\n';
    }else{
        while(aux != NULL && band == true){
            if(aux->placas == placas){
                band = false;
            }else{
                ant = aux;
                aux = aux->sig;
            }
        }
        if(aux == raiz){
            cout<<"Dame la hora de salida: ";
            getline(cin,s);
            aux->hora_salida = s + ":";
            cout<<"Dame los minutos: ";
            getline(cin,s);
            aux->hora_salida = aux->hora_salida + s + "  ";
            cout<<'\n';
            aux->cobro = cobro(aux->hora_entrada,aux->hora_salida);
            cout<<"Usted debe: "<<aux->cobro<<endl;
            cout<<'\n';
            cout<<"Inserte el billete y/o monedas para pagar: ";
            cin>>ayudaxD;
            cout<<'\n';
            ayudaxD = ayudaxD - aux->cobro;
            cout<< "El cambio de la cantidad " << ayudaxD << " es de: "<<endl;
            z.minimo(ayudaxD);
            cout<<'\n';
            cout<<'\n';
            raiz = aux->sig;
            delete(aux);
            cout<<"Egresado"<<endl;
            cout<<'\n';
        }else if(aux == NULL){
            cout<<"No existe el auto"<<endl;
        }else{
            cout<<"Dame la hora de salida: ";
            getline(cin,s);
            aux->hora_salida = s + ":";
            cout<<"Dame los minutos: ";
            getline(cin,s);
            aux->hora_salida = aux->hora_salida + s + "  ";
            cout<<'\n';
            aux->cobro = cobro(aux->hora_entrada,aux->hora_salida);
            cout<<"Usted debe: "<<aux->cobro<<endl;
            cout<<'\n';
            cout<<"Inserte el billete y/o monedas para pagar: ";
            cin>>ayudaxD;
            cout<<'\n';
            ayudaxD = ayudaxD - aux->cobro;
            cout<< "El cambio de la cantidad " << ayudaxD << " es de: "<<endl;
            z.minimo(ayudaxD);
            cout<<'\n';
            cout<<'\n';
            ant->sig = aux->sig;
            delete(aux);
            cout<<"Egresado"<<endl;
            cout<<'\n';
        }
    }
}
void estacionamiento::menu(){
    string placas, hora;
    char opc;
    cout<<'\t'<<"Menu"<<endl;
    cout<<"1.......................... Agregar vehiculo"<<endl;
    cout<<"2.......................... Ver vehiculos"<<endl;
    cout<<"3.......................... Egresar_vehiculos"<<endl;
    cout<<"4.......................... Salir"<<endl;
    do{
        cout<<"Dame el numero de la opcion que deseas realizar: ";
        cin>>opc;
        cout<<'\n';
        cin.ignore(10000,'\n');
        switch(opc){
            case '1':
                cout<<"Dame las placas del vehiculo: ";
                getline(cin,placas);
                cout<<'\n';
                hora = estacionamiento::obtener_hora();
                estacionamiento::agregar_vehiculo(placas,hora);
                break;
            case '2':
                estacionamiento::ver_vehiculos();
                break;
            case '3':
                cout<<"Dame las placas del vehiculo: ";
                getline(cin,placas);
                cout<<'\n';
                estacionamiento::egresar_vehiculos(placas);
                break;
            case '4':
                cout<<"Adios vaquero!!!"<<endl;
                break;
            default:
                cout<<"Numero erroneo, por favor digita un numero correcto"<<endl;
                cout<<'\n';
        }
    }while(opc!='4');
}
