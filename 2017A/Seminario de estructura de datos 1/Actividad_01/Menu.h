//
// Created by michel on 02/04/2017.
//

#ifndef ACTIVIDAD01_MENU_H
#define ACTIVIDAD01_MENU_H

#include <iostream>
#include <sstream>

#include "arreglo.h"
#include "Usuario.h"
using namespace std;
class Menu {
private:
    arreglo<Usuario> usuarios;
    void pedirFecha(Fecha &f);
    unsigned int buscar_id();

    void pedirNombre(Usuario &s);
    void pedirApellidos(Usuario &s);
    void pedirCorreo(Usuario &s);
    void pedirPassword(Usuario &s);
    void pedirId(Usuario &s);
    void pedirFechaRegistro(Usuario &s);
    void pedirFechaNacimiento(Usuario &s);


public:
    Menu();
    void registrar();
    void mostrar();
    void eliminar();

    void modificar();

    void buscar();
};


#endif //ACTIVIDAD01_MENU_H
