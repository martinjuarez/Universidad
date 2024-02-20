#include "lista.h"
#include  <iostream>
void lista::inicializar()
{
    h=NULL;
}
void lista::vacio()
{
    nodo *aux;
    if(h==NULL)
    {
        cout<<"La lista esta vacia"<<endl;
    }
    else
    {
        cout<<"La lista esta llena"<<endl;
    }
}
void lista::insertar(int e)
{
    nodo *tmp=new nodo;
    tmp->sig=NULL;
    tmp->dato=e;
    if(h==NULL)
    {
        h=tmp;
    }
    else
    {
        tmp->sig=h;
        h=tmp;
    }
}
void lista::insertarFinal(int e)
{
    nodo *tmp=new nodo;
    nodo *aux=h;
    tmp->sig=NULL;
    tmp->dato=e;
    if(aux==NULL)
    {
        h=tmp;
    }
    else
    {
        while(aux->sig!=NULL)
        {
            aux=aux->sig;
        }
        aux->sig=tmp;
    }
}
void lista::mostrar()
{
    nodo *aux;
    aux=h;
    if(aux==NULL)
    {
        cout<<"Error lista vacia"<<endl;
    }
    else
    {
        cout<<"Lista:"<<endl;
        while(aux!=NULL)
        {
            cout<<aux->dato<<endl;
            aux=aux->sig;
        }
    }
}
void lista::mostrarElemento(int e)
{
    nodo *aux;
    aux=h;
    bool band =true;
    if(h==NULL)
    {
        cout<<"Error lista vacia"<<endl;
    }
    else
    {
        while(aux!=NULL && band==true)
        {
            if(aux->dato==e)
            {
                cout<<"Elemento:"<<aux->dato<<endl;
                band=false;
            }
            else
            {
                aux=aux->sig;
            }
            if(aux==NULL)
            {
                cout<<"Elemento no encontrado"<<endl;
            }
        }
    }
}
void lista::buscar(int e)
{
    nodo *aux;
    aux=h;
    bool band= true;
    if(h==NULL)
    {
        cout<<"Error lista vacia"<<endl;;
    }
    else
    {
        while(aux!=NULL && band==true)
        {
            if(aux->dato==e)
            {
                band = false;
                cout<<"Si esta en la lista"<<endl;
            }
            else
            {
                aux=aux->sig;
            }
            if(aux==NULL)
            {
                cout<<"No esta en la lista"<<endl;
            }
        }
    }
}
void lista::anterior(int e)
{
    nodo *aux;
    nodo *ant;
    bool band=true;
    aux=h;
    ant=NULL;
    if(h==NULL)
    {
        cout<<"Error lista vacia"<<endl;
    }
    else
    {
        while(aux!=NULL&&band==true)
        {
            if(aux->dato==e)
            {
                band=false;
            }
            else
            {
                ant=aux;
                aux=aux->sig;
            }
        }
        if(aux==NULL)
        {
            cout<<"No se puede encontrar la direccion"<<endl;
        }
        else
        {
            if(ant==NULL)
            {
                cout<<"La direccion anterior es NULL"<<endl;
            }
            else
            {
                cout<<"Direccion anterior:"<<'\r'<<ant<<endl;
            }
        }
    }
}
void lista::siguiente(int e)
{
    nodo *aux;
    bool band=true;
    aux=h;
    if(h==NULL)
    {
        cout<<"Error lista vacia"<<endl;
    }
    else
    {
        while(aux!=NULL&&band==true)
        {
            if(aux->dato==e)
            {
                band=false;
            }
            else
            {
                aux=aux->sig;
            }
        }
        if(aux==NULL)
        {
            cout<<"La direccion siguiente es NULL"<<endl;
        }
        else
        {
            cout<<"Direccion anterior:"<<aux->sig<<endl;
        }
    }
}
void lista::eliminar(int e)
{
    nodo *aux;
    nodo *ant;
    bool band=true;
    aux=h;
    ant=NULL;
    if(h==NULL)
    {
        cout<<"Error lista vacia"<<endl;
    }
    else
    {
        while(aux!=NULL&&band==true)
        {
            if(aux->dato==e)
            {
                band=false;
            }
            else
            {
                ant=aux;
                aux=aux->sig;
            }
        }
        if(aux==h)
        {
            h=aux->sig;
            delete(aux);
        }
        else if(aux==NULL)
        {
            cout<<"No hay nada";
        }
        else
        {
            ant->sig=aux->sig;
            delete(aux);
        }
    }
}
void lista::menu()
{
    int opc,e;
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
    do
    {
        cout<<"* Escribe la opcion que deseas realizar:";
        cin>>opc;
        cout<<'\n';
        cin.ignore(10000,'\n');
        switch (opc)
        {
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
            cout<<"Dame el dato que deseas insertar"<<endl;
            cin>>e;
            lista::insertar(e);
            cout<<'\n';
            break;
        case 4:
            cout<<"Dame el dato que deseas insertar al final"<<endl;
            cin>>e;
            lista::insertarFinal(e);
            cout<<'\n';
            break;
        case 5:
            lista::mostrar();
            cout<<'\n';
            break;
        case 6:
            cout<<"Dame el dato que deseas mostrar"<<endl;
            cin>>e;
            lista::mostrarElemento(e);
            cout<<'\n';
            break;
        case 7:
            cout<<"Dame el dato que deseas Buscar"<<endl;
            cin>>e;
            lista::buscar(e);
            cout<<'\n';
            break;
        case 8:
            cout<<"Dame el dato que deseas eliminar"<<endl;
            cin>>e;
            lista::eliminar(e);
            cout<<'\n';
            break;
        case 9:
            cout<<"Dame el dato para mostrate la direccion del dato anterior:";
            cin>>e;
            lista::anterior(e);
            cout<<'\n';
            break;
        case 10:
            cout<<"Dame el dato para mostrate la direccion del dato siguiente:";
            cin>>e;
            lista::siguiente(e);
            cout<<'\n';
        default:
            cout<<"Opcion incorrecta"<<endl;
        }
    }
    while(opc!=0);
}
