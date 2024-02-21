#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdexcept> ///Para lanzar excepciones.

using namespace std;

template<typename T> ///Declaracion de la plantilla
class Lista
{
public:

    Lista<T>():index(0) {}; ///index(0) asigna 0 al atributo index;

    bool empty();
    bool full();
    size_t size();
    void insert(const T &elem);
    void print();
    size_t find(const T &elem);
    void remove(size_t idx);
    T& operator[](size_t idx);


private:
    ///size_t es un entero sin signo.
    static const size_t CAPACITY = 1000;
    T elements[CAPACITY];
    size_t index;
};

template<typename T>
bool Lista<T>::empty()
{
    return index==0;
}

template<typename T>
bool Lista<T>::full()
{
    return index==CAPACITY;
}

template<typename T>
size_t Lista<T>::size()
{
    return index;
}

template<typename T>
void Lista<T>::insert(const T &elem)
{
    if(full())
        throw invalid_argument("Full");

    elements[index]=elem;
    index++;
}

template<typename T>
void Lista<T>::print()
{
    for(size_t i=0; i<index; i++)
        cout<<elements[i]<<endl;
    cout<<endl;
}

template<typename T>
size_t Lista<T>::find(const T &elem)
{
    size_t i;
    for(i=0; i<index; i++)
        if(elements[i]==elem)
            return i;
    if(i==index)
        cout<<"not found"<<endl;
    return index;
}

template<typename T>
void Lista<T>::remove(size_t idx)
{
    if(idx<index)
    {
        for(size_t i=idx; i<index; i++)
            elements[i]=elements[i+1];
        index--;
    }
    else
        cout<<"Imposible eliminar elemento inexistente.";
}

template<typename T>
T& Lista<T>::operator[](size_t idx)
{
    if(empty())
        throw invalid_argument("[] on empty list");
    if(idx>=index)
        throw invalid_argument("[] on non valid position");

    return elements[idx];
}

#endif // LISTA_H
