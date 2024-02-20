#include "usuario.h"

string Usuario::getNombre() const
{
    return Nombre;
}

void Usuario::setNombre(const string &value)
{
    Nombre = value;
}

string Usuario::getApellidos() const
{
    return Apellidos;
}

void Usuario::setApellidos(const string &value)
{
    Apellidos = value;
}

Fecha Usuario::getFecha_Nacimiento() const
{
    return Fecha_Nacimiento;
}

void Usuario::setFecha_Nacimiento(const Fecha &value)
{
    Fecha_Nacimiento = value;
}

string Usuario::getCorreo() const
{
    return Correo;
}

void Usuario::setCorreo(const string &value)
{
    Correo = value;
}

string Usuario::getPassword() const
{
    return Password;
}

void Usuario::setPassword(const string &value)
{
    Password = value;
}

Fecha Usuario::getFecha_Registro() const
{
    return Fecha_Registro;
}

void Usuario::setFecha_Registro(const Fecha &value)
{
    Fecha_Registro = value;
}

string Usuario::getID() const
{
    return ID;
}

void Usuario::setID(const string &value)
{
    ID = value;
}

Usuario::usuario()
{

}
