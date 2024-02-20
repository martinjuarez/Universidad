#include <iostream>
using namespace std;
class nodo{
    public:
        int dato;
        nodo*sig;
        friend class lista;
};
nodo *tmp = new nodo;
class lista{
    public:
        nodo *h;
        void insertarInicio(int e){
        nodo*tmp=new nodo;
        tmp->sig=NULL;
        tmp->dato=e;
        if(h==NULL){
            h=tmp;
            }else{
                tmp->sig=h;
                h=tmp;
            }
        }
        void incializar(){
        h = NULL;
        }
        void mostrartodo(){
            nodo*aux=h;
            while(aux!= NULL){
                cout<<aux->dato<<endl;
                aux=aux->sig;
            }
        }
        void insertar_final(int e){
            nodo*tmp=new nodo;
            nodo*aux=h;
            tmp->sig=NULL;
            tmp->dato=e;
            if(aux==NULL){
                h=tmp;
            }else{
                while(aux->sig!=NULL){
                    aux=aux->sig;
                }
                aux=aux->sig;
            }
        }
};
int main(){
    lista a;
    return 0;
}
