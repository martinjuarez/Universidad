#ifndef ARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_H
#include <iostream>
using namespace std;
template <class T>
class Nodo
{
    template <class>
    friend class ArbolBinarioBusqueda;
private:
    Nodo<T> *izq;
    Nodo<T> *der;
    T dato;

public:
    Nodo(const T &dato,
         Nodo<T> *izq = nullptr,
         Nodo<T> *der = nullptr)
    {
        this->dato = dato;
        this->izq = izq;
        this->der = der;
    }
};
template <class T>
class ArbolBinarioBusqueda
{
private:
    Nodo<T> *raiz;
    void _inorder(Nodo<T> *&nodo);
public:
    ArbolBinarioBusqueda();
    void insertar(const T &dato);
    void inorder();
};
template <class T>
void ArbolBinarioBusqueda<T>::_inorder(Nodo<T> *&nodo)
{
    if(nodo == nullptr)
        return;
    else{
        _inorder(nodo->izq);
        cout << nodo->dato << "=>";
        _inorder(nodo->der);
    }
}
template<class T>
ArbolBinarioBusqueda<T>::ArbolBinarioBusqueda()
{
    raiz = nullptr;
}
template<class T>
void ArbolBinarioBusqueda<T>::insertar(const T &dato)
{
    if(raiz == nullptr)
    {
        raiz = new Nodo<T>(dato);
    }
    else{
        Nodo<T> *temp = raiz;
        while(true){
            if(dato <= temp->dato &&
               temp->izq == nullptr)
            {
                temp->izq = new Nodo<T>(dato);
                break;

            }
            else if(dato <= temp->dato)
            {
                temp = temp->izq;
            }
            else if(dato > temp->dato &&
                    temp->der == nullptr)
            {
                temp->der = new Nodo<T>(dato);
                break;
            }
            else if(dato > temp->dato)
            {
                temp = temp->der;
            }
        }
    }
}
template<class T>
void ArbolBinarioBusqueda<T>::inorder()
{
    _inorder(raiz);
}
#endif // ARBOLBINARIOBUSQUEDA_H
