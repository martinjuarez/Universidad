#ifndef USUARIO_H
#define USUARIO_H
#include <fecha.h>
#include <iostream>
using namespace std;

class Usuario
{
    friend ostream&operator<<(ostream &out, Usuario &usuario){
        out << "Nombre: " << usuario.Nombre << endl
            << "Apellidos: " << usuario.Apellidos << endl
            << "Nacimiento: " << usuario.Fecha_Nacimiento<< endl
            << "Correo: " << usuario.Correo << endl
            << "Password: " << usuario.Password << endl
            << "Registro: " << usuario.Fecha_Registro << endl
            << "Id: " << usuario.ID << endl;

    }
private:
    string Nombre;
    string Apellidos;
    Fecha Fecha_Nacimiento;
    string Correo;
    string Password;
    Fecha Fecha_Registro;
    string ID;
public:
    usuario();
    string getNombre() const;
    void setNombre(const string &value);
    string getApellidos() const;
    void setApellidos(const string &value);
    Fecha getFecha_Nacimiento() const;
    void setFecha_Nacimiento(const Fecha &value);
    string getCorreo() const;
    void setCorreo(const string &value);
    string getPassword() const;
    void setPassword(const string &value);
    Fecha getFecha_Registro() const;
    void setFecha_Registro(const Fecha &value);
    string getID() const;
    void setID(const string &value);
};

#endif // USUARIO_H
