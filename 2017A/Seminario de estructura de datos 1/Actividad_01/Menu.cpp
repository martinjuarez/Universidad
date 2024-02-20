//
// Created by michel on 02/04/2017.
//

#include "Menu.h"

Menu::Menu() {

    string op;

    while (true) {
        cout << "####--Usuarios--####" << endl;
        cout << "1) Registrar" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Eliminar" << endl;
        cout << "4) Modificar" << endl;
        cout << "5) Buscar" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if(op == "1"){
            registrar();
        }
        else if(op == "2"){
            mostrar();
        }
        else if(op == "3"){
            eliminar();
        }
        else if(op == "4"){
            modificar();
        }
        else if(op == "5"){
            buscar();
        }

        else{
            break;
        }
    }
}

void Menu::registrar() {

    Usuario s;

    pedirNombre(s);

    pedirApellidos(s);

    pedirCorreo(s);

    pedirPassword(s);

    pedirId(s);

    pedirFechaRegistro(s);

    pedirFechaNacimiento(s);

    usuarios.insertar_ultimo(s);

}

void Menu::pedirFecha(Fecha &f) {
    string temp;
    stringstream ss;
    int tempFecha;

    cout << "Dia: ";
    getline(cin, temp);
    ss << temp;
    ss >> tempFecha;
    f.setDia(tempFecha);

    cout << "Mes: ";
    getline(cin, temp);
    ss << temp;
    ss >> tempFecha;
    f.setMes(tempFecha);

    cout << "Anio: ";
    getline(cin, temp);
    ss << temp;
    ss >> tempFecha;
    f.setAnio(tempFecha);


}

void Menu::mostrar() {
    unsigned int tamano = usuarios.tamano();
    unsigned int i = 0;

    while(i < tamano ){
        cout << usuarios[i];
        cout << endl;
        i = i + 1;
    }
}

void Menu::eliminar() {

    unsigned int pos = buscar_id();

    if(pos == usuarios.tamano()){
        cout << "No existe el usuario con el id " << pos << endl;
    } else{
        usuarios.eliminar(pos);
    }

}

void Menu::modificar() {
    unsigned int pos = buscar_id();

    if(pos == usuarios.tamano()){
        cout << "No existe el usuario con el id " << pos << endl;
    } else{
        string op;

        cout << "**Modificar**" << endl;
        cout << "\t1) Nombre" << endl;
        cout << "\t2) Apellidos" << endl;
        cout << "\t3) Correo" << endl;
        cout << "\t4) Password" << endl;
        cout << "\t5) Id" << endl;
        cout << "\t6) Fecha de Registro" << endl;
        cout << "\t7) Fecha de Nacimiento" << endl;
        getline(cin, op);

        if("1" == op){
            pedirNombre(usuarios[pos]);
        }
        else if("2" == op ){
            pedirApellidos(usuarios[pos]);
        }
        else if("3" == op){
            pedirCorreo(usuarios[pos]);
        }
        else if("4" == op){
            pedirPassword(usuarios[pos]);
        }
        else if("5" == op){
            pedirId(usuarios[pos]);
        }
        else if("6" == op){
            pedirFechaRegistro(usuarios[pos]);
        }
        else if("7" == op){
            pedirFechaNacimiento(usuarios[pos]);
        }
        else if("0" == op){

        }
    }
}

void Menu::buscar() {
    unsigned int pos = buscar_id();

    if(pos == usuarios.tamano()){
        cout << "No existe el usuario con el id " << pos << endl;
    } else{
        cout << usuarios[pos];
    }
}

unsigned int Menu::buscar_id() {
    string temp;

    cout << "Id de Usuario: ";
    getline(cin, temp);

    unsigned int tamano = usuarios.tamano();
    unsigned int i = 0;

    while (i < tamano){
        if(usuarios[i].getId() == temp)
            break;
        i++;
    }
    return i;
}

void Menu::pedirNombre(Usuario &s) {
    string temp;

    cout << "Nombre: ";
    getline(cin, temp);
    s.setNombre(temp);
}

void Menu::pedirApellidos(Usuario &s) {
    string temp;

    cout << "Apellidos: ";
    getline(cin, temp);
    s.setApellidos(temp);
}

void Menu::pedirCorreo(Usuario &s) {
    string temp;

    cout << "Correo: ";
    getline(cin, temp);
    s.setCorreo(temp);
}

void Menu::pedirPassword(Usuario &s) {
    string temp;

    cout << "Password: ";
    getline(cin, temp);
    s.setPassword(temp);
}

void Menu::pedirId(Usuario &s) {
    string temp;

    cout << "Id: ";
    getline(cin, temp);
    s.setId(temp);
}

void Menu::pedirFechaRegistro(Usuario &s) {
    string temp;
    Fecha temp_fecha;

    cout << "**Fecha de Registro**" << endl;
    pedirFecha(temp_fecha);
    s.setRegistro(temp_fecha);
}

void Menu::pedirFechaNacimiento(Usuario &s) {
    string temp;
    Fecha temp_fecha;

    cout << "**Fecha de Nacimiento**" << endl;
    pedirFecha(temp_fecha);
    s.setFechaNacimiento(temp_fecha);
}
