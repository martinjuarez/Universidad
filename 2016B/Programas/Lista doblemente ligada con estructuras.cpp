#include <iostream>
using namespace std;
struct nodo
{
    int elemento;
    nodo *siguiente;
    nodo *anterior;
};
bool vacio(nodo *x)
{
    if(x->anterior==NULL&&x->siguiente==NULL){
        return 1;
    }else{
        return 0;
    }
}
/*void cuantos(nodo *x){
    int n=0;
    while(x->siguiente!=NULL){
        n++;
    }
    return n;
}*/
nodo *insertar(nodo *y)
{
    nodo *temp;
    temp=new nodo;
    if(vacio(y)){
        cout<<"Ingrese el dato:";
        cin>>temp->elemento;
        cout<<"Primer elemento"<<endl;
        temp->siguiente=NULL;
        temp

    }
}
int main()
{
    nodo *lista=NULL;
    int opcion=0;
    cout<<"Ingresa la opcion"<<endl;
    cin>>opcion;
    if (opcion)
    {
        insertar(lista);
    }
    lista=insertar(lista);
    return 0;
}
