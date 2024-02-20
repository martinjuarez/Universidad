#include "lista.h"
#include  <iostream>
using namespace std;
void lista::inicializar(){
    raiz=NULL;
}
void lista::vacio(){
    nodo *aux;
    aux=raiz;
    if(raiz==NULL){
        cout<<"Lista vacia"<<endl;
    }else{
       cout<<"Lista con elementos";
    }
}
void lista::insertar(string e,string f){
    nodo *tmp=new nodo; //creas el nodo temporal que cargara los datos recibidos
    tmp->sig=NULL; //se define null por si la raiz esta vacia no apunte a algo raro o con basura
    tmp->nombre=e;
    tmp->tipo=f;
    if(raiz==NULL){
        raiz=tmp; //si la raiz esta vacia tomara lo que se encuentra en temporal
    }else{
        tmp->sig=raiz; // Si la raiz tiene algo, hara que temporal apunte a la direccion actual de raiz
        raiz=tmp;// raiz cargara lo que tiene temporal
    }
}
void lista::insertarFinal(string e,string f){
    nodo *tmp=new nodo;
    nodo *aux=raiz;
    tmp->sig=NULL;
    tmp->nombre=e;
    tmp->tipo=f;
    if(aux==NULL){
        raiz=tmp;
    }else{
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=tmp;
    }
}
void lista::mostrar(){
    nodo *aux;
    aux=raiz;
    if(aux==NULL){
        cout<<"Error lista vacia"<<endl;
    }else{
        cout<<"Lista:"<<endl;
        while(aux!=NULL){
            cout<<"Nombre:"<<aux->nombre<<endl;
            cout<<"Tipo:"<<aux->tipo<<endl;
            aux=aux->sig;
        }
    }
}
void lista::mostrarElemento(string e,string f){
    nodo *aux;
    aux=raiz;
    bool band =true;
    if(raiz==NULL){
        cout<<"Error lista vacia"<<endl;
    }else{
        while(aux!=NULL && band==true){
            if(aux->nombre==e && aux->tipo==f){
                cout<<"Nombre:"<<aux->nombre<<endl;
                cout<<"Tipo:"<<aux->nombre<<endl;
                band=false;
            }else{
                aux=aux->sig;
            }
        if(aux==NULL){
            cout<<"Elemento no encontrado"<<endl;
        }
        }
    }
}
void lista::buscar(string e,string f){
    nodo *aux;
    aux=raiz;
    bool band= true;
    if(raiz==NULL){
        cout<<"Error lista vacia"<<endl;;
    }else{
        while(aux!=NULL && band==true){
            if(aux->nombre==e && aux->tipo==f){
                band = false;
                cout<<"Si esta en la lista"<<endl;
            }else{
                aux=aux->sig;
            }
        if(aux==NULL){
            cout<<"No esta en la lista"<<endl;
            }
        }
    }
}
void lista::anterior(string e,string f){
    nodo *aux;
    nodo *ant;
    bool band=true;
    aux=raiz;
    ant=NULL;
    if(raiz==NULL){
        cout<<"Error lista vacia"<<endl;
    }else{
        while(aux!=NULL&&band==true){
            if(aux->nombre==e && aux->tipo==f){
                band=false;
            }else{
                ant=aux;
                aux=aux->sig;
            }
        }if(aux==NULL){
            cout<<"No se puede encontrar la direccion"<<endl;
        }else{
            if(ant==NULL){
                cout<<"La direccion anterior es NULL"<<endl;
            }else{
                cout<<"Direccion anterior:"<<'\r'<<ant<<endl;
            }
        }
    }
}
void lista::siguiente(string e,string f){
    nodo *aux;
    bool band=true;
    aux=raiz;
    if(raiz==NULL){
        cout<<"Error lista vacia"<<endl;
    }else{
        while(aux!=NULL&&band==true){
            if(aux->nombre==e && aux->tipo==f){
                band=false;
            }else{
                aux=aux->sig;
            }
        }if(aux==NULL){
            cout<<"La direccion siguiente es NULL"<<endl;
        }else{
            cout<<"Direccion anterior:"<<aux->sig<<endl;
        }
    }
}
void lista::eliminar(string e,string f){
    nodo *aux;
    nodo *ant;
    bool band=true;
    aux=raiz;
    ant=NULL;
    if(raiz==NULL){
        cout<<"Error lista vacia"<<endl;
    }else{
        while(aux!=NULL&&band==true){
            if(aux->nombre==e && aux->tipo==f){
                band=false;
            }else{
                ant=aux;
                aux=aux->sig;
            }
        }
        if(aux==raiz){
            raiz=aux->sig;
            delete(aux);
            cout<<"Eliminado";
        }else if(aux==NULL){
            cout<<"No existe";
        }else{
            ant->sig=aux->sig;
            delete(aux);
            cout<<"Eliminado";
        }
    }
}
void lista::menu(){
    string e,f;
    int opc;
    cout<<'\t'<<"Menu"<<endl;
    cout<<"0....................... Salir"<<endl;
    cout<<"1....................... Inicializar"<<endl;
    cout<<"2....................... Vacio"<<endl;
    cout<<"3....................... Insertar"<<endl;
    cout<<"4....................... Insertar Final"<<endl;
    cout<<"5....................... Mostrar Todo"<<endl;
    cout<<"6....................... Mostrar Elemento"<<endl;
    cout<<"7....................... Buscar"<<endl;
    cout<<"8....................... Eliminar"<<endl;
    cout<<"9....................... Anterior"<<endl;
    cout<<"10....................... Siguiente"<<endl;
    do{
        cout<<"* Escribe la opcion que deseas realizar:";
        cin>>opc;
        cout<<'\n';
        cin.ignore(10000,'\n');
        switch (opc){
            case 0:
                break;
            case 1:
                lista::inicializar();
                break;
            case 2:
                lista::vacio();
                cout<<'\n';
                break;
            case 3:
                cout<<"Dame el nombre de la mascota que deseas insertar"<<endl;
                getline(cin,e);
                cout<<"Dame el tipo de mascota que deseas insertar"<<endl;
                getline(cin,f);
                lista::insertar(e,f);
                cout<<'\n';
                break;
            case 4:
                cout<<"Dame el nombre de la mascota que deseas insertar al final"<<endl;
                getline(cin,e);
                cout<<"Dame el tipo de mascota que deseas insertar al final"<<endl;
                getline(cin,f);
                lista::insertarFinal(e,f);
                cout<<'\n';
                break;
            case 5:
                lista::mostrar();
                cout<<'\n';
                break;
            case 6:
                cout<<"Dame el nombre de la mascota que deseas mostrar"<<endl;
                getline(cin,e);
                cout<<"Dame el tipo de mascota que deseas mostrar"<<endl;
                getline(cin,f);
                lista::mostrarElemento(e,f);
                cout<<'\n';
                break;
            case 7:
                cout<<"Dame el nombre de la mascota que deseas buscar"<<endl;
                getline(cin,e);
                cout<<"Dame el tipo de mascota que deseas buscar"<<endl;
                getline(cin,f);
                lista::buscar(e,f);
                cout<<'\n';
                break;
            case 8:
                cout<<"Dame el nombre de la mascota que deseas eliminar"<<endl;
                getline(cin,e);
                cout<<"Dame el tipo de mascota que deseas eliminar"<<endl;
                getline(cin,f);
                lista::eliminar(e,f);
                cout<<'\n';
                break;
            case 9:
                cout<<"Dame el nombre de la mascota para mostrate la direccion de la mascota anterior:"<<endl;
                getline(cin,e);
                cout<<"Dame el tipo de mascota para mostrate la direccion de la mascota anterior"<<endl;
                getline(cin,f);
                lista::anterior(e,f);
                cout<<'\n';
                break;
            case 10:
                cout<<"Dame el nombre de la mascota para mostrate la direccion de la mascota siguiente:"<<endl;
                getline(cin,e);
                cout<<"Dame el tipo de mascota para mostrate la direccion de la mascota siguiente:"<<endl;
                getline(cin,f);
                lista::siguiente(e,f);
                cout<<'\n';
            default:
                cout<<"Opcion incorrecta"<<endl;
        }
    }while(opc!=0);
}
