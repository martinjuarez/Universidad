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
    Nodo<T> *sig;
    Nodo<T> *ant;

public:
    Nodo(const T &d, Nodo<T> *ant = nullptr, Nodo<T> *sig = nullptr)
    {
        dato = d;
        this->sig = sig;
        this->ant = ant;
    }
};

template <class T>
class Lista
{
private:
    Nodo<T> *head;
    Nodo<T> *tail;
    unsigned int num_ele;

public:
    Lista();
    bool vacia();
    void insertar_inicio(const T &d);
    void insertar_final(const T &d);
    void mostrar();
    void mostrar_inverso();
    T& frente();
    T& final();
    T& posicion(unsigned int p);
    T& posicion_negativa(unsigned int p);
};

template <class T>
Lista<T>::Lista()
{
    head = tail = nullptr;
    num_ele = 0;
}

template<class T>
bool Lista<T>::vacia()
{
    return head == nullptr;
}

template<class T>
void Lista<T>::insertar_inicio(const T &d)
{
    if(vacia())
    {
        Nodo<T> *nodo = new Nodo<T>(d);
        head = nodo;
        tail = nodo;
    }
    else
    {
        Nodo<T> *nodo = new Nodo<T>(d, nullptr, head);
        head->ant = nodo;
        head = nodo;
    }
    num_ele++;
}

template<class T>
void Lista<T>::insertar_final(const T &d)
{
    if(vacia())
    {
        Nodo<T> *nodo = new Nodo<T>(d);
        head = nodo;
        tail = nodo;
    }
    else
    {
         Nodo<T> *nodo = new Nodo<T>(d, tail,nullptr);
         tail->sig = nodo;
         tail = nodo;
    }
    num_ele++;
}

template<class T>
void Lista<T>::mostrar()
{
    Nodo<T> *temp = head;
    while (temp!=nullptr)
    {
        cout << temp->dato << "=>";
        temp = temp->sig;
    }
}

template<class T>
void Lista<T>::mostrar_inverso()
{
    Nodo<T> *temp = tail;
    while (temp!=nullptr)
    {
        cout << temp->dato << "=>";
        temp = temp->ant;
    }
}

template<class T>
T &Lista<T>::frente()
{
    if(vacia())
        throw out_of_range("Lista vacia");
    return head->dato;
}

template<class T>
T &Lista<T>::final()
{
    if(vacia())
        throw out_of_range("Lista vacia");
    return tail->dato;
}

template<class T>
T &Lista<T>::posicion(unsigned int p)
{
    if(vacia())
        throw out_of_range("Lista vacia");
    else if(p < 0 || p >= num_ele)
        throw out_of_range("No existe la posicion");
    else
    {
        Nodo <T> *temp = head;
        unsigned int i = 0;
        while (i < p) {
           temp = temp->sig;
           i++;
        }
       return temp->dato;
    }
}

template<class T>
T &Lista<T>::posicion_negativa(unsigned int p)
{
    int aux = num_ele * -1 ;
    if(vacia())
        throw out_of_range("Lista vacia");
    else if(p < aux || p == 0 )
        throw out_of_range("No existe la posicion");
    else
    {
        Nodo <T> *temp = head;
        while(aux != p)
        {
           temp = temp->sig;
           aux++;
        }
        return temp->dato;
    }
}

#endif // LISTA_H
