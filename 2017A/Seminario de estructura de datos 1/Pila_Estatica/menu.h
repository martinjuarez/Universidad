#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <sstream>
#include "pila.h"

using namespace std;

template <class T>
class menu
{
public:
    menu();
    void apilar();
    void desapilar();
    void tope();
private:
    pila<T> p;
};
template<class T>
menu<T>::menu()
{
    string opc;

    while(true)
    {
        cout<<"* PILA ESTATICA *"<<endl;
        cout<<"1) Apilar" <<endl;
        cout<<"2) Desapilar" <<endl;
        cout<<"3) Tope" <<endl;
        cout<<"0) Salir" <<endl;

        getline(cin, opc);

        if(opc=="1")
        {
            apilar();
        }
        else if(opc=="2")
        {
            desapilar();
        }
        else if(opc=="3")
        {
            tope();
        }
        else if(opc=="0")
        {
            break;
        }
    }

}
template<class T>
void menu<T>::apilar()
{
    if(!p.llena())
    {
        string linea;
        T dato;
        cout<<"Escribe el dato: ";
        getline(cin,linea);

        stringstream(linea)>> dato;
        p.agregar(dato);
    }
    else{
        cout<<"La pila esta llena"<<endl;
    }
}
template<class T>
void menu<T>::desapilar()
{
    if(!p.vacia())
    {
        cout<<"Se desapilo "<<p.pop()<<endl;
    }
    else{
        cout<<"La pila esta vacia"<<endl;
    }
}
template<class T>
void menu<T>::tope()
{
    if(!p.vacia())
    {
        cout<<"El tope de la pila es "
           <<p.getValor(p.getTamano() - 1 )
          <<endl;
    }
    else{
        cout<<"La pila esta vacia"<<endl;
    }
}

#endif // MENU_H
