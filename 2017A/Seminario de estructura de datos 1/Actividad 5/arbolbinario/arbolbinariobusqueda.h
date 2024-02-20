#ifndef ARLBOL_BINARIO_H
#define ARLBOL_BINARIO_H
#include <iostream>
using namespace std;

template <class t>
class nodo{
template <class>
friend class arlbol_binario;
private:
    nodo<t> *izq;
    nodo<t> *der;
    t dato;
public:
    nodo(const t &dato,nodo<t> *izq = nullptr,nodo<t> *der = nullptr){
        this->dato=dato;
        this->izq=izq;
        this->der=der;}};

template <class t>
class arlbol_binario{
    friend class arbol_bici;
private:
    nodo<t> *raiz;
    void _inorden(nodo<t> *&Nodo);
public:
    arlbol_binario();
    void insertar(const t &dato);
    void inorden();
    bool vacia();};

template<class t>
void arlbol_binario<t>::inorden(){
    _inorden(raiz);}

template<class t>
bool arlbol_binario<t>::vacia(){
    return raiz==nullptr;}

template <class t>
arlbol_binario<t>::arlbol_binario(){
    raiz=nullptr;}

template<class t>
void arlbol_binario<t>::insertar(const t &dato){
    if(vacia()){
        raiz=new nodo<t>(dato);}
    else{
        nodo<t> *temp=raiz;
        while(true){
            if(dato<=temp->dato&&temp->izq==nullptr){
                temp->izq=new nodo<t>(dato);
                break;}
            else if(dato<=temp->dato)
                temp=temp->izq;
            else if(dato>temp->dato&&temp->der==nullptr){
                temp->der=new nodo<t>(dato);
                break;}
            else if(dato>temp->dato)
                temp=temp->der;}}}

template<class t>
void arlbol_binario<t>::_inorden(nodo<t> *&Nodo){
    if(Nodo==nullptr)
        return;
    else{
        _inorden(Nodo->izq);
        cout<<"\n"<<Nodo->dato;
        if(Nodo->der!=nullptr)
            cout<<"   |\n   v";
        else cout<<endl;
        _inorden(Nodo->der);}}

#endif // ARLBOL_BINARIO_H
