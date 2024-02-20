#ifndef LISTA_H
#define LISTA_H
#include  <iostream>
using namespace std;
class nodo{
    public:
        string nombre;
        string tipo;
        nodo *sig;
        friend class lista;
};
class lista
{
    public:
        nodo *raiz;
        void inicializar();
        void mostrar();
        void insertar(string e,string f);
        void insertarFinal(string e,string f);
        void buscar(string e,string f);
        void eliminar(string e,string f);
        void mostrarElemento(string e,string f);
        void vacio();
        void anterior(string e,string f);
        void siguiente(string e,string f);
        void menu();
};

#endif // LISTA_H
