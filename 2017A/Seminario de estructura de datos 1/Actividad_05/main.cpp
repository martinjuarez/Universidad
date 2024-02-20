#include <iostream>
#include "arbolbinariobusqueda.h"
using namespace std;
class bicicleta{
friend ostream &operator <<(ostream &out,bicicleta &bici){
    out<<"id: "<<bici.getId()<<"\nMetros: "<<bici.getMetros()<<"\nTiempo: "<<bici.getHh()<<":"<<bici.getMm()<<":"<<bici.getSs()<<endl;
    return out;
}
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
    void setSs(unsigned int value);
    bool operator <=(bicicleta &bici)const{
        return getMetros()<=bici.getMetros();
    }
    bool operator >(bicicleta &bici)const{
        return getMetros()>bici.getMetros();
    }
};

class arbol_bici{
private:
    arlbol_binario<bicicleta> abb;
public:
    void registrar(const bicicleta &dato);
    void inorden();
    bool zero();
};

int main(){
    int op;
    arbol_bici ab;
    while (true) {
    cout<<"0) Salir\n1) Registrar\n2) Inorden"<<endl;
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
        ab.registrar(bici);
        break;
    case 2:
        if(ab.zero())
            cout<<"No hay bicicletas disponibles"<<endl;
        else{
            ab.inorden();
        }
        break;
    case 0: return 0;
    default: cout<<"No hay bicicletas disponibles"<<endl;
    }
    }
}

unsigned int bicicleta::getMetros() const{
    return metros;
}

void bicicleta::setMetros(unsigned int value){
    metros = value;
}

unsigned int bicicleta::getHh() const{
    return hh;
}

void bicicleta::setHh(unsigned int value){
    hh = value;
}

unsigned int bicicleta::getMm() const{
    return mm;
}

void bicicleta::setMm(unsigned int value){
    mm = value;
}

unsigned int bicicleta::getSs() const{
    return ss;
}

void bicicleta::setSs(unsigned int value){
    ss = value;
}

int bicicleta::getId() const{
    return id;
}

void bicicleta::setId(int value){
    id = value;
}

void arbol_bici::registrar(const bicicleta &dato){
    abb.insertar(dato);
}

void arbol_bici::inorden(){
    abb.inorden();
}

bool arbol_bici::zero(){
    return abb.vacia();
}
