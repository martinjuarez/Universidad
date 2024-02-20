#ifndef HORA_H
#define HORA_H
#include "time.h"
#include <iostream>
using namespace std;
struct tm *t;
time_t tiempo;
time(&tiempo);
t = localtime(&tiempo);




class Hora
{
private:
    int hora = t->tm_hour;
    int minutos = t->tm_min;
    int segundos = t->tm_sec;
public:
    void mostrar()
    {
        cout << "Hora: " << hora << " Minutos: " << minutos << " Segundos: " << segundos << endl;
    }

};
#endif // HORA_H
