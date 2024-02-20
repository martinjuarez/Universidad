#ifndef ARLBOL_BINARIO_H
#define ARLBOL_BINARIO_H
#include <iostream>
using namespace std;

template <class T>
class nodo{
template <class>
friend class arlbol_binario;
private:
    nodo<T> *izq;
    nodo<T> *der;
    T dato;
public:
    nodo(const T &dato,nodo<T> *izq = nullptr,nodo<T> *der = nullptr){
        this->dato=dato;
        this->izq=izq;
        this->der=der;
    }
};

template <class T>
class arlbol_binario{
    friend class arbol_bici;
private:
    nodo<T> *raiz;
    void _inorden(nodo<T> *&Nodo);
public:
    arlbol_binario();
    void insertar(const T &dato);
    void inorden();
    bool vacia();
};

template<class T>
void arlbol_binario<T>::inorden(){
    _inorden(raiz);
}

template<class T>
bool arlbol_binario<T>::vacia(){
    return raiz==nullptr;
}

template <class T>
arlbol_binario<T>::arlbol_binario(){
    raiz=nullptr;
}

template<class T>
void arlbol_binario<T>::insertar(const T &dato){
    if(vacia()){
        raiz=new nodo<T>(dato);
    }
    else{
        nodo<T> *temp=raiz;
        while(true){
            if(dato<=temp->dato&&temp->izq==nullptr){
                temp->izq=new nodo<T>(dato);
                break;
            }
            else if(dato<=temp->dato)
                temp=temp->izq;
            else if(dato>temp->dato&&temp->der==nullptr){
                temp->der=new nodo<T>(dato);
                break;}
            else if(dato>temp->dato)
                temp=temp->der;
        }
    }
}

template<class T>
void arlbol_binario<T>::_inorden(nodo<T> *&Nodo){
    if(Nodo==nullptr)
        return;
    else{
        _inorden(Nodo->izq);
        cout<<"\n"<<Nodo->dato;
        if(Nodo->der!=nullptr)
            cout<<"   |\n   v";
        else cout<<endl;
        _inorden(Nodo->der);
    }
}

#endif // ARLBOL_BINARIO_H
