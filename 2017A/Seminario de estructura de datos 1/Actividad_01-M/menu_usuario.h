#ifndef MENU_USUARIO_H
#define MENU_USUARIO_H
#include <iostream>
#include <sstream>
#include "usuario.h"
#include "arreglo.h"
using namespace std;

class menu_usuario
{
private:
    arreglo<Usuario> usuarios;
    void pedirFecha(Fecha &f);
    unsigned int buscar_id();
    void pedirNombre(Usuario &a);
    void pedirApellidos(Usuario &a);
    void pedirFechaNacimiento(Usuario &a);
    void pedirCorreo(Usuario &a);
    void pedirPassword(Usuario &a);
    void pedirFechaRegistro(Usuario &a);
    void pedirId(Usuario &a);
public:
    menu_usuario();
    void Registrar_Nuevo_Usuario();
    void Mostrar_Usuarios();
    void Eliminar_Usuario();
    void Modicar_Usuario();
    void Buscar();
};

#endif // MENU_USUARIO_H
