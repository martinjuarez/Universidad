#include "fecha.h"

int Fecha::getDia() const
{
    return dia;
}

void Fecha::setDia(int value)
{
    dia = value;
}

int Fecha::getMes() const
{
    return mes;
}

void Fecha::setMes(int value)
{
    mes = value;
}

int Fecha::getYear() const
{
    return year;
}

void Fecha::setYear(int value)
{
    year = value;
}

Fecha::Fecha()
{

}
