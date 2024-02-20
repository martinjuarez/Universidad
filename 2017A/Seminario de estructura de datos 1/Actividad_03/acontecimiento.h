#ifndef ACONTECIMIENTO_H
#define ACONTECIMIENTO_H
#include <iostream>
#include "Fecha.h"
using namespace std;

template <class T>
class Acontecimiento
{
private:
    string Id;
    string Acontecimiento;
    Fecha fecha_acontecimiento;

public:
    Acontecimiento();
};
template <class T>
Acontecimiento<T>::Acontecimiento()
{

}


#endif // ACONTECIMIENTO_H
