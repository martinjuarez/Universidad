//
// Created by michel on 02/04/2017.
//

#ifndef ACTIVIDAD01_USUARIO_H
#define ACTIVIDAD01_USUARIO_H

#include <iostream>
#include "Fecha.h"
using namespace std;
class Usuario
{
    friend ostream&operator<<(ostream &out, Usuario &usuario){
        out << "Nombre: " << usuario.nombre << endl
            << "Apellidos: " << usuario.apellidos << endl
            << "Correo: " << usuario.correo << endl
            << "Password: " << usuario.password << endl
            << "Id: " << usuario.id << endl
            << "Registro: " << usuario.registro << endl
            << "Nacimiento: " << usuario.fechaNacimiento << endl;

    }
private:
    string nombre;
    string apellidos;
    string correo;
    string password;
    string id;
    Fecha registro;
    Fecha fechaNacimiento;
public:
    Usuario(){};
    const string &getNombre() const {
        return nombre;
    }

    void setNombre(const string &nombre) {
        Usuario::nombre = nombre;
    }

    const string &getApellidos() const {
        return apellidos;
    }

    void setApellidos(const string &apellidos) {
        Usuario::apellidos = apellidos;
    }

    const string &getCorreo() const {
        return correo;
    }

    void setCorreo(const string &correo) {
        Usuario::correo = correo;
    }

    const string &getPassword() const {
        return password;
    }

    void setPassword(const string &password) {
        Usuario::password = password;
    }

    const string &getId() const {
        return id;
    }

    void setId(const string &id) {
        Usuario::id = id;
    }

    const Fecha &getRegistro() const {
        return registro;
    }

    void setRegistro(const Fecha &registro) {
        Usuario::registro = registro;
    }

    const Fecha &getFechaNacimiento() const {
        return fechaNacimiento;
    }

    void setFechaNacimiento(const Fecha &fechaNacimiento) {
        Usuario::fechaNacimiento = fechaNacimiento;
    }
};
#endif //ACTIVIDAD01_USUARIO_H
