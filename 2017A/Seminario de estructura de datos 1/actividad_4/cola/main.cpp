#include <iostream>
#include "cola.h"
using namespace std;

class bicicleta{
friend ostream &operator <<(ostream &out,bicicleta &bici){
    out<<"id: "<<bici.getId()<<"\nMetros: "<<bici.getMetros()<<"\nTiempo: "<<bici.getHh()<<":"<<bici.getMm()<<":"<<bici.getSs()<<endl;
    return out;}
private:
    int id;
    unsigned int metros;
    unsigned int hh;
    unsigned int mm;
    unsigned int ss;
public:
    int getId() const;
    void setId(int value);
    unsigned int getMetros() const;
    void setMetros(unsigned int value);
    unsigned int getHh() const;
    void setHh(unsigned int value);
    unsigned int getMm() const;
    void setMm(unsigned int value);
    unsigned int getSs() const;
    void setSs(unsigned int value);};

class menu_prestamos{
private:
    cola<bicicleta> col;
public:
    void llegada(const bicicleta &d);
    bicicleta mostrar;
    void setMostrar();
    bicicleta getMostrar();
    void prestamo();
    bool nada();};

int main(){
    int op;
    menu_prestamos menu;
    while (true) {
    cout<<"0) Salir\n1) Llegada\n2) Disponible\n3) Prestamo"<<endl;
    cin>>op;
    switch (op) {
    case 1:
        bicicleta bici;
        unsigned int e;
        cout<<"Id: ";
        cin>>e;
        bici.setId(e);
        cout<<"Metros recorridos: ";
        cin>>e;
        bici.setMetros(e);
        cout<<"Tiempo de recorrido:\nHoras: ";
        cin>>e;
        bici.setHh(e);
        cout<<"Minutos: ";
        cin>>e;
        bici.setMm(e);
        cout<<"Segundos: ";
        cin>>e;
        bici.setSs(e);
        menu.llegada(bici);
        break;
    case 2:
        if(menu.nada())
            cout<<"No hay bicicletas intentalo mas tarde"<<endl;
        else{
            menu.setMostrar();
            cout<<menu.mostrar;}
        break;
    case 3:
        if(menu.nada())
            cout<<"No hay bicicletas intentalo mas tarde"<<endl;
        else{
            cout<<"La bicicleta a sido prestada"<<endl;
            menu.prestamo();}
        break;
    case 0: return 0;
    default: cout<<"Opcion incorrecta intenta de nuevo"<<endl;}}}

unsigned int bicicleta::getMetros() const{
    return metros;}

void bicicleta::setMetros(unsigned int value){
    metros = value;}

unsigned int bicicleta::getHh() const{
    return hh;}

void bicicleta::setHh(unsigned int value){
    hh = value;}

unsigned int bicicleta::getMm() const{
    return mm;}

void bicicleta::setMm(unsigned int value){
    mm = value;}

unsigned int bicicleta::getSs() const{
    return ss;}

void bicicleta::setSs(unsigned int value){
    ss = value;}

int bicicleta::getId() const{
    return id;}

void bicicleta::setId(int value){
    id = value;}

void menu_prestamos::llegada(const bicicleta &d){
    col.encolar(d);}

void menu_prestamos::setMostrar(){
    mostrar=col.frente();}

bicicleta menu_prestamos::getMostrar(){
    return mostrar;}

void menu_prestamos::prestamo(){
    col.desencolar();}

bool menu_prestamos::nada(){
    return col.Cola.vacia();}
