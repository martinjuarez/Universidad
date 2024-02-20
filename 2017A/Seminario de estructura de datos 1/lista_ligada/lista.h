#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

template <class T>
class Nodo
{
    template <class>
    friend class Lista;
private:
    T dato;
    Nodo *sig;
public:
    Nodo(const T &d, Nodo<T> *s = nullptr)
    {
        dato = d;
        sig = s;
    }
};
template <class T>
class Lista
{
private:
    Nodo<T> *raiz;
    unsigned int num_ele;
public:
    Lista();
    bool vacio();
    void insertar_inicio(const T &d);
    void insertar_final(const T &d);
    void insertar_posicion(const T &d, const T &dato);
    void eliminar_inicio();
    void eliminar_final();

    void mostrar();
};
template <class T>
Lista<T>::Lista()
{
    raiz = nullptr;
    num_ele = 0;
}

template<class T>
bool Lista<T>::vacio()
{
    return raiz == nullptr;
}

template<class T>
void Lista<T>::insertar_inicio(const T &d)
{
    if(vacio()){
        Nodo<T> *nuevo = new Nodo<T>(d);
        raiz = nuevo;
    }
    else{
        Nodo<T> *nuevo = new Nodo<T>(d, raiz);
        raiz = nuevo;
    }
    num_ele++;
}

template<class T>
void Lista<T>::insertar_final(const T &d)
{
    if(vacio()){
        Nodo<T> *nuevo = new Nodo<T>(d);
        raiz = nuevo;
    }
    else{
        Nodo<T> *nuevo = new Nodo<T>(d);
        Nodo<T> *temp = raiz;
        while(temp->sig != nullptr){
            temp = temp->sig;
        }
        temp->sig = nuevo;
    }
    num_ele++;
}

template<class T>
void Lista<T>::insertar_posicion(const T &d , const T &dato)
{
    if(vacio())
    {
        throw out_of_range("No se puede insertar en posicion necesitas al menos un elemento en la lista");
    }
    else{
        Nodo<T> *aux = new Nodo<T>(dato);
        Nodo<T> *temp = raiz;
        bool band = false;
        while(temp->dato != aux->dato){
            if(temp->dato == aux->dato)
            {
                band = true;
                aux->sig = temp;
            }
            temp = temp->sig;
        }
        Nodo<T> *nuevo = new Nodo<T>(d,temp);
        temp->sig = nuevo;
        aux->sig = nuevo;
    }
    num_ele++;
}

template<class T>
void Lista<T>::eliminar_inicio()
{
    if(vacio())
        throw out_of_range("Lista Vacia");
    else
    {
        Nodo<T> *temp = raiz;
        raiz = raiz->sig;
        delete temp;
        num_ele--;
    }
}

template<class T>
void Lista<T>::eliminar_final()
{
    if(vacio()){
        throw out_of_range("Lista vacia");
    }
    if(raiz->sig == nullptr){
        delete raiz;
        raiz = nullptr;
        num_ele--;
    }
    else{
        Nodo<T> *temp = raiz;
        while(temp->sig->sig != nullptr) {
            temp = temp->sig;
        }
        delete temp->sig;
        temp->sig = nullptr;
        num_ele--;
    }
}

template<class T>
void Lista<T>::mostrar()
{
    Nodo<T>*temp = raiz;
    while(temp != nullptr){
        cout << temp->dato;
        if(temp->sig != nullptr)
            cout << "=>";
        temp = temp->sig;
    }
}

#endif // LISTA_H
