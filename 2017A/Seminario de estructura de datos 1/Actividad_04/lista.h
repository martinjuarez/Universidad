#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class nodo{
template <class>
friend class lista;
private:
    T dato;
    nodo <T> *ant;
    nodo <T> *sig;
public:
    nodo(const T &d,nodo<T> *ant = nullptr,nodo<T> *sig = nullptr){
        dato=d;
        this->sig = sig;
        this->ant = ant;
    }
};

template <class T>
class lista{
    template<class>
    friend class cola;
private:
    nodo<T> *head;
    nodo<T> *tail;
    unsigned int num_elem;
public:
    bool vacia();
    void insertar_inicio(const T &d);
    void insertar_final(const T &d);
    void mostar();
    void mostra_invereso();
    void eliminar_inicio();
    void eliminar_final();
    T& frente();
    T& final();
    T& posicion(unsigned int p);
    lista();
};

template<class T>
bool lista<T>::vacia(){
    return head==nullptr;
}

template<class T>
void lista<T>::insertar_inicio(const T &d){
    if (vacia()){
        nodo<T> *Nodo =new nodo<T>(d);
        head=Nodo;
        tail=Nodo;
    }
    else{
        nodo<T> *Nodo = new nodo<T>(d,nullptr,head);
        head->ant=Nodo;
        head=Nodo;
    }
    num_elem++;
}

template<class T>
void lista<T>::insertar_final(const T &d){
    if (vacia()){
        nodo<T> *Nodo =new nodo<T>(d);
        head=Nodo;
        tail=Nodo;
    }
    else{
        nodo<T> *Nodo = new nodo<T>(d,tail,nullptr);
        tail->sig=Nodo;
        tail=Nodo;
    }
    num_elem++;
}

template<class T>
void lista<T>::mostar(){
    nodo<T> *temp =head;
    while(temp!=nullptr){
        cout<<temp->dato;
        if(temp->sig!=nullptr)
            cout<<"=>";
        temp=temp->sig;
    }
}

template<class T>
void lista<T>::mostra_invereso(){
    nodo<T> *temp =tail;
    while(temp!=nullptr){
        cout<<temp->dato;
        if(temp->ant!=nullptr)
            cout<<"<=";
        temp=temp->ant;
    }
}

template<class T>
void lista<T>::eliminar_inicio(){
    if(vacia())
        throw out_of_range("Lista vacia");
    else if(num_elem==1){
        delete head;
        head=tail=nullptr;
    }
    else{
        nodo<T> *temp =head;
        head=head->sig;
        head->ant=nullptr;
        delete temp;}
    num_elem--;
}

template<class T>
void lista<T>::eliminar_final(){
    if(vacia())
        throw out_of_range("Lista vacia");
    else if(num_elem==1){
        delete tail;
        head=tail=nullptr;
    }
    else{
        nodo<T> *temp=tail;
        tail=tail->ant;
        tail->sig=nullptr;
        delete temp;
    }
    num_elem--;
}

template<class T>
T &lista<T>::frente(){
    if(vacia())
        throw out_of_range("Lista vacia");
    return head->dato;
}

template<class T>
T &lista<T>::final(){
    if(vacia())
        throw out_of_range("Lista vacia");
    return tail->dato;
}

template<class T>
T &lista<T>::posicion(unsigned int p){
    if(vacia())
        throw out_of_range("lista vacia");
    else if(p<0||p>=num_elem)
        throw out_of_range("No esxiste la posicion");
    else{
        nodo<T> *temp = head;
        unsigned int i=0;;
        while (i<p) {
            temp=temp->sig;
            i++;
        }
    return temp->dato;
    }
}

template<class T>
lista<T>::lista(){
    head=tail=nullptr;
    num_elem=0;
}

#endif // LISTA_H
