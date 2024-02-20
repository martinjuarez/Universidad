//
// Created by michel on 02/04/2017.
//

#ifndef ACTIVIDAD01_FECHA_H
#define ACTIVIDAD01_FECHA_H

#include <iostream>
using namespace std;
class Fecha
{
private:
    int dia;
    int mes;

private:
    int anio;

public:
    Fecha(){};
    Fecha(int dia, int mes, int anio){
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }
    friend ostream& operator<<(ostream &out, Fecha &fecha){
        out << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;

        return out;
    }
    int getDia() const {
        return dia;
    }

    int getMes() const {
        return mes;
    }

    int getAnio() const {
        return anio;
    }

    void setDia(int dia) {
        Fecha::dia = dia;
    }

    void setMes(int mes) {
        Fecha::mes = mes;
    }

    void setAnio(int anio) {
        Fecha::anio = anio;
    }
};

#endif //ACTIVIDAD01_FECHA_H
