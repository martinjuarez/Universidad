#include <iostream>
#include "lista.h"
using namespace std;


int main(int argc, char *argv[])
{
//    Nodo<string> *a = new Nodo<string>("Jueves");
//    Nodo<string> *b = new Nodo<string>("Miercoles", a);
//    Nodo<string> *c = new Nodo<string>("Martes", b);

    Lista<string> lista;
    cout << lista.vacio() << endl;
    lista.insertar_inicio("Viernes");
    lista.insertar_inicio("Jueves");
    lista.insertar_inicio("Miercoles");
    lista.mostrar();
    cout << endl;
    lista.insertar_final("Sabado");
    lista.insertar_final("Domingo");
    lista.mostrar();
    cout << endl;
    lista.eliminar_inicio();
    lista.mostrar();
    cout << endl;
    lista.eliminar_final();
    lista.mostrar();
    cout << endl;
    lista.insertar_posicion("Miercoles","Jueves");
    lista.mostrar();
    cout << endl;

    return 0;
}
