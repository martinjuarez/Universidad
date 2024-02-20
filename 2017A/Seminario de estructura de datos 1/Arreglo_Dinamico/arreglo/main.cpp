#include <iostream>
#include "arreglo.h"
using namespace std;

int main()
{
    /*arreglo<int> a;
    arreglo<int> b(30);
    arreglo<int> c(5, 5);
    //cout << c << endl;

    a.insertar_ultimo(4);
    a.insertar_ultimo(2);
    a.insertar_ultimo(60);
    cout<< a << endl;
    cout <<"Insertar en posicion 0"<<endl;
    a.insertar(0,3);
    cout <<"Insertar en posicion 3"<<endl;
//    a.insertar(3,115);

//    a.eliminar_ultimo();
//    cout<< a << endl;
//    a.eliminar(0);
//    cout<< a << endl;
//    c[0] = 0;
//    d[4] = 10;
//    cout << c << endl << d <<endl;


//    arreglo<int> e(a);
//    cout<< a << endl << e << endl;

/*
    cout << "La capacidad de a es: "
         << a.capacidad()
         << " y su tamaño es: "
         << a.tamano()
         <<endl;
    cout << "La capacidad de b es: "
         << b.capacidad()
         << " y su tamaño es: "
         << b.tamano()
         <<endl;
    cout << "La capacidad de c es: "
         << c.capacidad()
         << " y su tamaño es: "
         << c.tamano()
         <<endl;
*/
    arreglo<int> d;
    d.insertar_ultimo(10);
    d.insertar_ultimo(15);
    cout << d << endl;
    cout <<"Insertar en posicion 0"<<endl;
    d.insertar(0,3);
    cout << d <<endl;
    cout <<"Insertar en posicion 3"<<endl;
    d.insertar(2,115);
    cout << d <<endl;
    return 0;
}
