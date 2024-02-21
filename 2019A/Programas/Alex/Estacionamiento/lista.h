#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include  <iostream>
using namespace std;
class vehiculo{
    public:
        string placas;
        string hora_entrada;
        string hora_salida;
        int cobro;
        vehiculo *sig;
        friend class estacionamiento;
};
class estacionamiento{
    public:
        vehiculo *raiz = NULL;
        string obtener_hora();
        int cobro(string a, string b);
        void agregar_vehiculo(string placas, string hora_entrada);
        void ver_vehiculos();
        void egresar_vehiculos(string placas);
        void menu();
};
#endif // LISTA_H_INCLUDED
