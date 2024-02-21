#ifndef MONEDAS_H_INCLUDED
#define MONEDAS_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

int denominacion[] = {1, 2, 5, 10, 20, 50};
int n = sizeof(denominacion)/sizeof(denominacion[0]);

class monedas{
    public:
        void minimo(int V);
};


#endif // MONEDAS_H_INCLUDED
