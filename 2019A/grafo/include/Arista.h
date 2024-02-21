#ifndef ARISTA_H
#define ARISTA_H

#include <iostream>

using namespace std;

class Arista
{
    public:
        Arista()
        {
            conexion=false;
            peso=0;
        }
        ~Arista(){}

        bool conexion;
        int peso;
};

#endif // ARISTA_H
