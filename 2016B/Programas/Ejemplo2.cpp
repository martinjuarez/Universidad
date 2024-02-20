#include <iostream>
using namespace std;
class nodo{
    public:
        int dato;
        nodo *siguiente;
};
class pila{
    public:
        nodo *inicio;
        pila(){
            inicio=NULL;
        }
        void push(int dato){
            nodo *n;
            n=new nodo();
            n->dato=dato;
            n->siguiente=inicio;
            cout<<"Siguiente:"<<n->siguiente<<endl;
            inicio=n;
        }
        int peek(){
            if(inicio==NULL){
                /* Vacio */
                cout<<"Vacio"<<endl;
                return 0;
            }
            return inicio->dato;
        }
        void pop(){
            if(inicio == NULL){
                /* Vacio */
                cout<<"Vacio"<<endl;
                return;
            }
            nodo *t;
            t = inicio;
            inicio = t->siguiente;
            delete t;
        }
        bool vacia(){
            return (inicio == NULL);
        }
};
int main(){
    pila a;
    nodo b;
    cout<<"Inicio antes de apilar:"<<a.inicio<<endl;
    a.push(4);
    cout<<"Inicio despues de apilar:"<<a.inicio<<endl;
    a.push(5);
    cout<<"Inicio despues del sugundo apilar:"<<a.inicio<<endl;
    a.push(20);
    cout<<"Inicio despues del tercer apilar:"<<a.inicio<<endl;
}
