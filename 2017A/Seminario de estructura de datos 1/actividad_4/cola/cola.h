#ifndef COLA_H
#define COLA_H
#include "lista.h"

template<class t>
class cola{
friend class menu_prestamos;
private:
    lista<t> Cola;
public:
    cola();
    void encolar(const t &d);
    void desencolar();
    t& frente();
    t& final();};

template <class t>
cola<t>::cola(){}

template<class t>
void cola<t>::encolar(const t &d){
    Cola.insertar_final(d);}

template<class t>
void cola<t>::desencolar(){
    Cola.eliminar_inicio();}

template<class t>
t &cola<t>::frente(){
    return Cola.frente();}

template<class t>
t &cola<t>::final(){
    return Cola.final();}

#endif // COLA_H
