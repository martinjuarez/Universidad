#ifndef LISTA_H
#define LISTA_H

#define MAX 5
#include <iostream>
using namespace std;

template <class T>
class lista
{
public:
    lista();
    void agregar(T dato);
    void agregar_posicion(T dato, unsigned int posicion);
    void eliminar (int posicion);
    T getValor(unsigned int posicion);
    unsigned int getTamano();
    bool llena();
    bool vacia();
private:
    T arreglo[MAX];
    unsigned int indice;
};

template <class T>
lista<T>::lista()
{
    indice = 0;
}
template <class T>
void lista<T>::agregar(T dato)
{
    arreglo[indice] = dato;
    indice++;
}

template <class T>
void lista<T>::agregar_posicion(T dato, unsigned int posicion)
{
    int aux=indice;
    while(posicion<aux){
    arreglo[aux]=arreglo[aux-1];
    aux--;
    }
    arreglo[posicion]=dato;
    indice++;

}

template <class T>
void lista<T>::eliminar(int posicion)
{
    for(unsigned int i= posicion;i<indice;i++){
        arreglo[i]=arreglo[i+1];
    }
    indice --;
}

template <class T>
T lista<T>::getValor(unsigned int posicion)
{
    return arreglo[posicion];
}

template <class T>
unsigned int lista<T>::getTamano()
{
    return indice;
}
template <class T>
bool lista<T>::llena()
{
    return indice == MAX ? true : false;
}
template <class T>
bool lista<T>::vacia()
{
    return indice == 0 ? true : false;
}

#endif // LISTA_H
