#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <stdexcept>
using namespace std;

template <class t>
class nodo{
template <class>
friend class lista;
private:
    t dato;
    nodo <t> *ant;
    nodo <t> *sig;
public:
    nodo(const t &d,nodo<t> *ant = nullptr,nodo<t> *sig = nullptr){
        dato=d;
        this->sig = sig;
        this->ant = ant;}};

template <class t>
class lista{
    template<class>
    friend class cola;
private:
    nodo<t> *head;
    nodo<t> *tail;
    unsigned int num_elem;
public:
    bool vacia();
    void insertar_inicio(const t &d);
    void insertar_final(const t &d);
    void mostar();
    void mostra_invereso();
    void eliminar_inicio();
    void eliminar_final();
    t& frente();
    t& final();
    t& posicion(unsigned int p);
    lista();};

template<class t>
bool lista<t>::vacia(){
    return head==nullptr;}

template<class t>
void lista<t>::insertar_inicio(const t &d){
    if (vacia()){
        nodo<t> *Nodo =new nodo<t>(d);
        head=Nodo;
        tail=Nodo;}
    else{
        nodo<t> *Nodo = new nodo<t>(d,nullptr,head);
        head->ant=Nodo;
        head=Nodo;}
    num_elem++;}

template<class t>
void lista<t>::insertar_final(const t &d){
    if (vacia()){
        nodo<t> *Nodo =new nodo<t>(d);
        head=Nodo;
        tail=Nodo;}
    else{
        nodo<t> *Nodo = new nodo<t>(d,tail,nullptr);
        tail->sig=Nodo;
        tail=Nodo;}
    num_elem++;}

template<class t>
void lista<t>::mostar(){
    nodo<t> *temp =head;
    while(temp!=nullptr){
        cout<<temp->dato;
        if(temp->sig!=nullptr)
            cout<<"=>";
        temp=temp->sig;}}

template<class t>
void lista<t>::mostra_invereso(){
    nodo<t> *temp =tail;
    while(temp!=nullptr){
        cout<<temp->dato;
        if(temp->ant!=nullptr)
            cout<<"<=";
        temp=temp->ant;}}

template<class t>
void lista<t>::eliminar_inicio(){
    if(vacia())
        throw out_of_range("Lista vacia");
    else if(num_elem==1){
        delete head;
        head=tail=nullptr;}
    else{
        nodo<t> *temp =head;
        head=head->sig;
        head->ant=nullptr;
        delete temp;}
    num_elem--;}

template<class t>
void lista<t>::eliminar_final(){
    if(vacia())
        throw out_of_range("Lista vacia");
    else if(num_elem==1){
        delete tail;
        head=tail=nullptr;}
    else{
        nodo<t> *temp=tail;
        tail=tail->ant;
        tail->sig=nullptr;
        delete temp;}
    num_elem--;}

template<class t>
t &lista<t>::frente(){
    if(vacia())
        throw out_of_range("Lista vacia");
    return head->dato;}

template<class t>
t &lista<t>::final(){
    if(vacia())
        throw out_of_range("Lista vacia");
    return tail->dato;}

template<class t>
t &lista<t>::posicion(unsigned int p){
    if(vacia())
        throw out_of_range("lista vacia");
    else if(p<0||p>=num_elem)
        throw out_of_range("No esxiste la posicion");
    else{
        nodo<t> *temp = head;
        unsigned int i=0;;
        while (i<p) {
            temp=temp->sig;
            i++;}
    return temp->dato;}}

template<class t>
lista<t>::lista(){
    head=tail=nullptr;
    num_elem=0;}

#endif // LISTA_H
