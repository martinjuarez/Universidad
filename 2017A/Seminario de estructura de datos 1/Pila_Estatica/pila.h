#ifndef PILA_H
#define PILA_H

#include "lista.h"

template<class T>
class pila : public lista<T>
{
public:
    pila();
    void push(T dato);
    T pop();
    T top();
};
template<class T>
pila<T>::pila()
{
}
template<class T>
void pila<T>::push(T dato)
{
    this->agregar(dato);
}
template <class T>
T pila<T>::pop()
{
    T dato =this->getValor(this->getTamano()-1);
    this->eliminar(this->getTamano()-1);

    return dato;
}
template <class T>
T pila<T>::top()
{
    return this->getValor(this->getTamano()-1);
}
#endif // PILA_H
