#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Vertice.h"
#include "Arista.h"

using namespace std;

class Grafo
{
    public:
        Grafo()
        {
            pond=false;
            cant=10;
        }
        ~Grafo(){}

        bool pond;
        bool dir;
        size_t cant;
        Vertice v[10];
        Arista a[10][10];
};

#endif // GRAFO_H
