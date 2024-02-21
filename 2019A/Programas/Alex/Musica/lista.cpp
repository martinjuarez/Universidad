#include "lista.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void musica::agregar_cancion(string nombre, string autor, string album){
    ofstream Archivo("Canciones.txt",ios::app);
    Cancion *tmp = new Cancion;
    tmp->sig = NULL;
    tmp->nombre = nombre;
    tmp->autor = autor;
    tmp->album = album;
    if(raiz == NULL){
        raiz = tmp;
        tam = 1;
        pos = new Cancion*[10];
        pos[tam-1] = raiz;
        Archivo<<tmp->nombre<<'|'<<tmp->autor<<'|'<<tmp->album<<'|';
        Archivo.close();
    }else{
        tmp->sig = raiz;
        raiz = tmp;
        tam++;
        pos[tam-1] = raiz;
        Archivo<<tmp->nombre<<'|'<<tmp->autor<<'|'<<tmp->album<<'|';
        Archivo.close();
    }
}

void musica::ver_canciones(){
    Cancion *aux, *aux2;
    aux = raiz;
    int n=0;
    if(aux == NULL){
        cout<<"Lista de canciones vacia"<<endl;
        cout<<'\n';
    }else{
        cout<<'\t'<<'\t'<<"Lista"<<endl;
        cout<<'\n';
        while(aux != NULL){
            aux2 = pos[n];
            cout<<"Nombre: "<<aux->nombre<<endl;
            cout<<"Autor: "<<aux->autor<<endl;
            cout<<"Album: "<<aux->album<<endl;
            cout<<"Memoria: "<<aux<<endl;
            cout<<"Pos: "<<aux2<<endl;
            cout<<'\n';
            aux = aux->sig;
            n++;
        }
    }
}

void musica::buscar_canciones(string nombre){
    Cancion *aux,*aux1;
    aux = raiz;
    bool band = false;
    char aux3[nombre.length() + 1];
    strcpy(aux3, nombre.c_str());
    int inf = 0, sup = tam-1, centro;
    if(raiz == NULL){
        cout<<"Error lista vacia"<<endl;
        cout<<'\n';
    }else{
        while(inf <= sup && band != true){
            centro = ((sup - inf) / 2) + inf;
            aux1 = pos[centro];
            char aux2[aux1->nombre.length() + 1];
            strcpy(aux2, aux1->nombre.c_str());
            cout<<"Aux->nombre: "<<aux1->nombre<<endl;
            if(aux1->nombre == aux3){
                cout<<"Nombre: "<<aux->nombre<<endl;
                cout<<"Autor: "<<aux->autor<<endl;
                cout<<"Album: "<<aux->album<<endl;
                cout<<'\n';
                band = true;
            }else if(strcmp(aux2,aux3)<0){
                sup = centro - 1;
            }else{
                inf = centro + 1;
            }
        }
        if(band == false){
            cout<<"No esta en la lista"<<endl;
            cout<<'\n';
        }
    }
}
void musica::eliminar_canciones(string nombre)
{
    Cancion *aux;
    Cancion *ant;
    bool band = true;
    aux = raiz;
    ant = NULL;
    if(raiz == NULL){
        cout<<"Error lista vacia"<<endl;
        cout<<'\n';
    }else{
        while(aux != NULL && band == true){
            if(aux->nombre == nombre){
                band = false;
            }else{
                ant = aux;
                aux = aux->sig;
            }
        }
        if(aux == raiz){
            raiz = aux->sig;
            delete(aux);
            cout<<"Eliminado"<<endl;
            cout<<'\n';
        }else if(aux == NULL){
            cout<<"No existe"<<endl;
            cout<<'\n';
        }else{
            ant->sig = aux->sig;
            delete(aux);
            cout<<"Eliminado"<<endl;
            cout<<'\n';
        }
    }
}
void musica::recuperar(){
    ifstream Lectura("Canciones.txt");
    char a [50];
    char b [50];
    char c [50];
    int n;
    if(!Lectura.good()){
        cout<<"Error al cargar el archivo"<<endl;
    }else{
        Lectura.seekg(0, ios::end);
        n = Lectura.tellg();
        if(n>0){
            Lectura.seekg(0, ios::beg);
            do{
                Cancion *tmp = new Cancion;
                tmp->sig = NULL;
                if(raiz == NULL){
                    n=0;
                    do{
                        Lectura.read((char *)&a[n],1);
                        if(Lectura.eof()) break;
                        n++;
                    }while(a[n-1] != '|');
                    a[n-1]='\0';
                    if(Lectura.eof()) break;
                    n=0;
                    do{
                        Lectura.read((char *)&b[n],1);
                        if(Lectura.eof()) break;
                        n++;
                    }while(b[n-1] != '|');
                    b[n-1]='\0';
                    n=0;
                    do{
                        Lectura.read((char *)&c[n],1);
                        if(Lectura.eof()) break;
                        n++;
                    }while(c[n-1] != '|' && !Lectura.eof());
                    c[n-1]='\0';
                    tmp->nombre = a;
                    tmp->autor = b;
                    tmp->album = c;
                    raiz = tmp;
                    tam = 0;
                    pos = new Cancion*[10];
                    pos[tam] = raiz;
                    tam++;
                }else{
                    n=0;
                    do{
                        Lectura.read((char *)&a[n],1);
                        if(Lectura.eof()) break;
                        n++;
                    }while(a[n-1] != '|');
                    a[n-1]='\0';
                    if(Lectura.eof()) break;
                    n=0;
                    do{
                        Lectura.read((char *)&b[n],1);
                        if(Lectura.eof()) break;
                        n++;
                    }while(b[n-1] != '|');
                    b[n-1]='\0';
                    n=0;
                    do{
                        Lectura.read((char *)&c[n],1);
                        if(Lectura.eof()) break;
                        n++;
                    }while(c[n-1] != '|' && !Lectura.eof());
                    c[n-1]='\0';
                    tmp->nombre = a;
                    tmp->autor = b;
                    tmp->album = c;
                    tmp->sig = raiz;
                    raiz = tmp;
                    pos[tam] = raiz;
                    tam++;
                }
            }while(!Lectura.eof());

        }else{
            cout<<"Archivo vacio"<<endl;
        }
    }
    Lectura.close();
}
void musica::bubblesort(){
    Cancion *actual, *siguiente;
    actual = raiz;
    string aux1,aux2,aux3;
    int modif = 0, n = 0;
    while(actual->sig != NULL){
        siguiente = actual->sig;
        while(siguiente != NULL){
            char aux4[actual->nombre.length() + 1],aux5[siguiente->nombre.length() + 1];
            strcpy(aux4, actual->nombre.c_str());
            strcpy(aux5, siguiente->nombre.c_str());
            if(strcmp(aux4,aux5) > 0){
                aux1 = siguiente->nombre;
                aux2 = siguiente->autor;
                aux3 = siguiente->album;
                siguiente->nombre = actual->nombre;
                siguiente->autor = actual->autor;
                siguiente->album = actual->album;
                actual->nombre = aux1;
                actual->autor = aux2;
                actual->album = aux3;
                modif = 1;
            }
            siguiente = siguiente->sig;
        }
        if(modif == 0)
            break;
        pos[n] = actual;
        actual = actual->sig;
        siguiente = actual->sig;
        n++;
    }
    pos[n] = actual;
}
void musica::menu(){
    musica::recuperar();
    musica::bubblesort();
    string nombre,autor,album;
    cout<<"Tam: "<<tam<<endl;
    char opc;
    cout<<'\t'<<"Menu"<<endl;
    cout<<"1.......................... Agregar cancion"<<endl;
    cout<<"2.......................... Ver canciones"<<endl;
    cout<<"3.......................... Buscar cancion"<<endl;
    cout<<"4.......................... Eliminar cancion"<<endl;
    cout<<"5.......................... Salir"<<endl;
    do{
        cout<<"Dame el numero de la opcion que deseas realizar: ";
        cin>>opc;
        cout<<'\n';
        cin.ignore(10000,'\n');
        switch(opc){
            case '1':
                cout<<"Introdusca el nombre de la cancion: ";
                getline(cin,nombre);
                cout<<'\n';
                cout<<"Introdusca el autor de la cancion: ";
                getline(cin,autor);
                cout<<'\n';
                cout<<"Introdusca el album al que pertenece: ";
                getline(cin,album);
                cout<<'\n';
                musica::agregar_cancion(nombre,autor,album);
                musica::bubblesort();
                break;
            case '2':
                musica::ver_canciones();
                break;
            case '3':
                cout<<"Introdusca el nombre de la cancion a buscar: ";
                getline(cin,nombre);
                cout<<'\n';
                musica::buscar_canciones(nombre);
                break;
            case '4':
                cout<<"Introdusca el nombre de la cancion a eliminar: ";
                getline(cin,nombre);
                cout<<'\n';
                musica::eliminar_canciones(nombre);
                break;
            case '5':
                cout<<"Adios vaquero!!!"<<endl;
                break;
            default:
                cout<<"Numero erroneo, por favor digita un numero correcto"<<endl;
                cout<<'\n';
        }
    }while(opc!='5');
}
