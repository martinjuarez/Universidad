#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "Grafo.h"
#include "Lista.h"
#include "Pila.h"
#include "Cola.h"
#include "Vertice.h"
#include "Arista.h"

using namespace std;

class Menu
{
    public:
        Menu();
        ~Menu();

        void save();
        void addVert();
        void addAris();
        void NewGraph();
        void ShowMeYourMoves();
        void editVert();
        void editAris();
        void rec_an(Vertice v);
        void rec_pro(Vertice v);
        void rut_an(Vertice o,Vertice d);
        void rut_pro(Vertice o,Vertice d);
        void menu();

    private:
        Grafo g;
        bool dir;
        string name;
};

#endif // MENU_H
