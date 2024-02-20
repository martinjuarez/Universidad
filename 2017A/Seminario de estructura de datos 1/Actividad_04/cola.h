#ifndef COLA_H
#define COLA_H
#include "lista.h"

template<class T>
class cola{
friend class menu_prestamos;
private:
    lista<T> Cola;
public:
    cola();
    void encolar(const T &d);
    void desencolar();
    T& frente();
    T& final();};

template <class T>
cola<T>::cola(){}

template<class T>
void cola<T>::encolar(const T &d){
    Cola.insertar_final(d);}

template<class T>
void cola<T>::desencolar(){
    Cola.eliminar_inicio();}

template<class T>
T &cola<T>::frente(){
    return Cola.frente();}

template<class T>
T &cola<T>::final(){
    return Cola.final();}

#endif // COLA_H
