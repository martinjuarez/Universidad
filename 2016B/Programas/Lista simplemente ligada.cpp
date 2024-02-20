#include <iostream>
using namespace std;
struct nodo{
    int elemento;
    nodo *siguiente;
};
void insertar(nodo *y){
    nodo *temp,*temp_2;
    temp=new nodo;
    if(Vacio(y)){
        y=temp;
        cout<<"Ingresa el dato:";
        cin>>temp->elemento;
        temp->siguiente=NULL;
    }else{
        temp_2=y;
        while(temp_2->siguiente!=NULL){
            temp_2=temp_2->siguiente;
        }
        temp_2->siguiente=temp;
        temp->siguiente=NULL;
        cin>>temp->elemento;
    }
}
bool Vacio(nodo *x){
    if(x==NULL){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    nodo *n=NULL;
    int opc;
    do{
        cout<<'\t'<<"Menu"<<endl;
        cout<<"1...........Insertar"<<endl;
        cout<<"2...........Mostrar"<<endl;
        cout<<"3...........¿Vacia?"<<endl;
        cout<<"Ingresa la opcion que deseas realizar:";
        cin>>opc;
        switch(opc){
            case 1:
                insertar(n);
                break;
            case 2:
                break;
            default:
                cout<<"Error";
        }
    }while(opc!=0);
    return 0;
}
