#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha
{
    friend ostream& operator<<(ostream &out, Fecha &fecha){
        out << fecha.dia << "/" << fecha.mes << "/" << fecha.year;
        return out;
    }
private:
    int dia;
    int mes;
    int year;
public:
    Fecha();
    int getDia() const;
    void setDia(int value);
    int getMes() const;
    void setMes(int value);
    int getYear() const;
    void setYear(int value);
};

#endif // FECHA_H
