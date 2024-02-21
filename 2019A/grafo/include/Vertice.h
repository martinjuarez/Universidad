#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
using namespace std;

class Vertice
{
    public:
        Vertice()//{}
        {
            nombre[0]='X';
            for(int i=1;i<20;i++)
                nombre[i]='\0';
            activo=false;
        }
        ~Vertice(){}

        char nombre[20];
        bool activo;
};

#endif // VERTICE_H
