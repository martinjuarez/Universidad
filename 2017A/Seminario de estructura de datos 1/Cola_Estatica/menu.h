#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <sstream>
#include "cola.h"
using namespace std;

template<class T>
class menu
{
public:
    menu();
    void encolar();
    void head();
    void tail();
    void desencolar();
private:
    cola<T> c;
};
template<class T>
menu<T>::menu()
{
    string opc;

    while(true)
    {
        cout<<"* COLA ESTATICA *"<<endl;
        cout<<"1) Encolar (Enqueue)" <<endl;
        cout<<"2) Desencolar (Dequeue)" <<endl;
        cout<<"3) Cabeza (Head)" <<endl;
        cout<<"4) Cola (Tail)" <<endl;
        cout<<"0) Salir" <<endl;

        getline(cin, opc);

        if(opc=="1")
        {
             encolar();
        }
        else if(opc=="2")
        {
             desencolar();
        }
        else if(opc=="3")
        {
             head();
        }
        else if(opc=="4")
        {
            tail();
        }
        else if(opc=="0")
        {
            break;
        }
    }

}
template<class T>
void menu<T>::encolar()
{
    if(!c.llena()){
        string linea;
        T dato;
        cout<<"Escribe el dato: ";
        getline(cin,linea);
        stringstream(linea)>> dato;
        c.agregar(dato);
    }
    else
    {
        cout<<"La cola esta llena"<<endl;
    }
}
template<class T>
void menu<T>::head()
{
    if(!c.vacia())
    {
        cout<<"La cabeza es:"
           <<c.getValor(0)
             <<endl;
    }
    else
    {
        cout<<"La cola esta vacia"<<endl;
    }
}
template<class T>
void menu<T>::tail()
{
    if(!c.vacia())
    {
        string i;
        cout<<"1)............Mostrar la cola de la cola"<<endl;
        cout<<"2)............Mostrar toda la cola"<<endl;
        getline(cin,i);
        if(i=="1")
        {
            cout<<"La cola de la cola es "
               <<c.getValor(c.getTamano() - 1 )
              <<endl;
        }
        else if(i=="2")
        {
            for (unsigned int i=0; i < c.getTamano();i++)
            {
                cout<<"pos "<< i << ":"<<c.getValor(i)<<endl;
            }
        }
    }
    else{
        cout<<"La cola esta vacia"<<endl;
    }
}
template<class T>
void menu<T>::desencolar()
{
    if(!c.vacia())
    {
        cout<<"Se desencolo "<<c.dequeue()<<endl;
    }
    else
    {
        cout<<"La cola esta vacia"<<endl;
    }
}
#endif // MENU_H
