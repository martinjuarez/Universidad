#include <iostream>
#include "lista.h"
using namespace std;

int main(int argc, char *argv[])
{
    Lista<string> listaDoble;
    listaDoble.insertar_inicio("Lunes");
    listaDoble.insertar_inicio("Domingo");
    listaDoble.insertar_final("Martes");
    listaDoble.insertar_final("Miercoles");
    listaDoble.mostrar();
    cout << endl;
    listaDoble.mostrar_inverso();
    cout << endl;
    cout << "Frente: " << listaDoble.frente() << " Final: " << listaDoble.final() << endl;
    cout << listaDoble.posicion(0) << endl;
    cout<<"Posicion negativa -4 "<<endl;
    cout << listaDoble.posicion_negativa(-4) << endl;
    cout<<"Posicion negativa -2 "<<endl;
    cout << listaDoble.posicion_negativa(-2) << endl;

    return 0;
}
