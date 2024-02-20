#include <iostream>
using namespace std;
class lista_pila{
    public:
    class nodo_pila{
        public:
        nodo_pila *siguiente;
        int elemento;
        nodo_pila(int x){
            elemento=x;
            siguiente=NULL;
        }
    };
    nodo_pila *cima;
        lista_pila(){
            cima=NULL;
        }
    void insertar(int nuevo){
        nodo_pila *y;
        y= new nodo_pila(nuevo);
        y->siguiente=cima;
        cima=y;
    }
    void mostrar_cima(){
        nodo_pila *aux;
        aux=cima;
        cout<<"Cima:"<<aux->elemento<<endl;
    }
    void vacio(){
        if(cima==NULL){
            cout<<"Lista vacia"<<endl;
        }else{
            cout<<"Lista llena"<<endl;
        }
    }
    void eliminar(){
    }
};
int main(){
    lista_pila p;
    /*int nuevo;
    cout<<"Dato:";
    cin>>nuevo;
    */
    p.insertar(1);
    p.insertar(2);
    p.insertar(3);
    p.mostrar_cima();
    p.vacio();
    return 0;
}
