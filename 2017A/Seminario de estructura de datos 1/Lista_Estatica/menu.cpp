#include "menu.h"

Menu::Menu()
{
    string op;
    while(true)
    {
        cout<<"Lista Estatica"<<endl;
        cout<<"1) Agregar"<<endl;
        cout<<"2) Mostrar"<<endl;
        cout<<"3) Agregar en posicion"<<endl;
        cout<<"4) Eliminar"<<endl;
        cout<<"0) Salir"<<endl;
        getline(cin,op);

        if(op=="1")
        {
            //pedir datos al usuario
            agregar();
        }
        else if(op=="2")
        {
            //mostrar datos de la lista
            mostrar();
        }
        else if(op=="3"){
            agregar_pos();
        }
        else if(op=="4"){
            eliminar();
        }
        else if(op=="0")
        {
            //salir
            break;
        }
    }
}

void Menu::agregar()
{   if(!l.llena()){
        int valor;
        cout<< "Escribe un entero:"<<endl;
        valor = leerInt();
        l.agregar(valor);
    }else{
        cout<<"La Lista esta llena"<<endl;
    }
}

void Menu::agregar_pos()
{
    if(!l.llena()){
        int valor,posicion,flag=0;
        do{
            cout<< "Escribe un entero:"<<endl;
            valor = leerInt();
            cout<< "Escribe la posicion:"<<endl;
            posicion= leerInt();
            if(posicion>=0 && posicion<MAX){
                flag=1;
            }
            else{
                cout<<"Error.......pon una posicion mayor a 0 y menor a "<<MAX<<endl;
                cout<<'\n';
            }
        }while (flag==0);
        l.agregar_pos(valor,posicion);
    }else{
        cout<<"Error lista llena"<<endl;
        cout<<'\n';
    }
}
void Menu::mostrar()
{
    for (unsigned int i=0; i < l.getTamano();i++)
    {
        cout<<"pos "<< i << ":"<<l.getValor(i)<<endl;
    }
}

void Menu::eliminar()
{
    int posicion,flag=0;
    do{
        cout<< "Escribe la posicion:"<<endl;
        posicion= leerInt();
        if(posicion>=0 && posicion<MAX){
            flag=1;
        }
        else{
            cout<<"Error.......pon una posicion mayor a 0 y menor a "<<MAX<<endl;
            cout<<'\n';
        }
    }while (flag==0);
    l.eliminar(posicion);
}
int Menu::leerInt()
{
    string linea;
    int salida;
    int flag=0;
    while(flag==0)
    {
        getline(cin,linea);
        for(unsigned int i=0; i<linea.length();i++)
        {
            if(! isdigit(linea[i]))
            {
                cout<<"Error, escribe un entero"<<endl;
                flag=0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
    }
    stringstream(linea)>>salida;
    return salida;
}
