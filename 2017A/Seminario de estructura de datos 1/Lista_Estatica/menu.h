#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;
#include "lista.h"
#include <sstream>
class Menu
{
public:
    Menu();
    void agregar();
    void agregar_pos();
    void mostrar();
    void eliminar();
    int leerInt();
private:
    Lista<int> l;
};





#endif // MENU_H
