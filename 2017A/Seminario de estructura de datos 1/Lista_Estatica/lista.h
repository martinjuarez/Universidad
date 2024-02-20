#ifndef LISTA_H
#define LISTA_H
#define MAX 5
#include <iostream>
using namespace std;
template<class T>
class Lista
{
public:
    Lista();
    void agregar(T dato);
    void agregar_pos(T dato,unsigned int posicion);
    void eliminar(unsigned int posicion);
    T getValor(unsigned int posicion);
    unsigned int getTamano();
    bool llena();

private:
    T arreglo[MAX];
    unsigned int indice;
};

template<class T>
Lista<T>::Lista()
{
    indice = 0;
}
template<class T>
void Lista<T>::agregar(T dato)
{
    arreglo [indice] = dato;
    indice++;
}
template<class T>
void Lista<T>::agregar_pos(T dato,unsigned int posicion)
{
    if(posicion>indice){
        cout<<"Error esta casilla esta vacia, no puedes agregar por posicion"<<endl;
        cout<<'\n';
    }
    else{
        int aux=indice;
        while (posicion<aux){
           arreglo[aux]=arreglo[aux-1];
           aux--;
        }
        arreglo [posicion]=dato;
        indice++;
    }
}
template<class T>
void Lista<T>::eliminar(unsigned int posicion)
{
    while (posicion<indice)
    {
        arreglo[posicion]=arreglo[posicion+1];
        posicion++;
    }
    indice--;
}
template<class T>
T Lista<T>::getValor(unsigned int posicion)
{
    return arreglo[posicion];
}
template<class T>
unsigned int Lista<T>::getTamano()
{
    return indice;
}
template<class T>
bool Lista<T>::llena()
{
    return indice == MAX ? true : false;
}

#endif // LISTA_H
