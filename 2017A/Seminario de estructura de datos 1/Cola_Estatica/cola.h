#ifndef COLA_H
#define COLA_H
#include "lista.h"

template<class T>
class cola : public lista<T>
{
public:
    cola();
    void encolar(T dato);
    T head();
    T tail();
    T dequeue();
};


template<class T>
cola<T>::cola()
{
}
template<class T>
void cola<T>::encolar(T dato)
{
    this->agregar();
}
template<class T>
T cola<T>::head()
{
    return this->getValor(this->getTamano()-1);
}
template<class T>
T cola<T>::tail()
{
    return this->getValor(this->getTamano()-1);
}
template<class T>
T cola<T>::dequeue()
{
    T dato =this->getValor(0);
    this->eliminar(0);
    return dato;
}
#endif // COLA_H
