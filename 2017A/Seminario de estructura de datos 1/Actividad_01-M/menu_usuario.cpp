#include "menu_usuario.h"

void menu_usuario::pedirFecha(Fecha &f)
{
    int aux;

    cout << "Dia: ";
    cin>> aux;
    cin.ignore(10000,'\n');
    f.setDia(aux);

    cout << "Mes: ";
    cin>> aux;
    cin.ignore(10000,'\n');
    f.setMes(aux);

    cout << "Anio: ";
    cin>> aux;
    cin.ignore(10000,'\n');
    f.setYear(aux);
}

unsigned int menu_usuario::buscar_id()
{
    string aux;

    cout << "Id de Usuario: ";
    getline(cin, aux);

    unsigned int tamano = usuarios.tamano();
    unsigned int i = 0;

    while (i < tamano){
        if(usuarios[i].getID() == aux)
            break;
        i++;
    }
    return i;
}

void menu_usuario::pedirNombre(Usuario &a)
{
    string aux;
    cout << "Nombre: ";
    getline(cin, aux);
    a.setNombre(aux);
}

void menu_usuario::pedirApellidos(Usuario &a)
{
    string aux;
    cout << "Apellidos: ";
    getline(cin, aux);
    a.setApellidos(aux);
}

void menu_usuario::pedirFechaNacimiento(Usuario &a)
{
    string aux;
    Fecha aux_fecha;

    cout << "Fecha de Nacimiento" << endl;
    pedirFecha(aux_fecha);
    a.setFecha_Nacimiento(aux_fecha);
}

void menu_usuario::pedirCorreo(Usuario &a)
{
    string aux;
    cout << "Correo: ";
    getline(cin, aux);
    a.setCorreo(aux);
}

void menu_usuario::pedirPassword(Usuario &a)
{
    string aux;
    cout << "Password: ";
    getline(cin, aux);
    a.setPassword(aux);
}

void menu_usuario::pedirFechaRegistro(Usuario &a)
{
    string aux;
    Fecha aux_fecha;

    cout << "Fecha de Registro" << endl;
    pedirFecha(aux_fecha);
    a.setFecha_Registro(aux_fecha);
}

void menu_usuario::pedirId(Usuario &a)
{
    string aux;
    cout << "Id: ";
    getline(cin, aux);
    a.setID(aux);
}

menu_usuario::menu_usuario()
{
    string op;
    while (true)
    {
        cout << "0) Salir" << endl;
        cout << "1) Registrar" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Eliminar" << endl;
        cout << "4) Modificar" << endl;
        cout << "5) Buscar" << endl;
        cout << "Dame la opcion que deseas realizar: " << endl;
        getline(cin, op);

        if(op == "1"){
            Registrar_Nuevo_Usuario();
        }
        else if(op == "2"){
            Mostrar_Usuarios();
        }
        else if(op == "3"){
            Eliminar_Usuario();
        }
        else if(op == "4"){
            Modicar_Usuario();
        }
        else if(op == "5"){
            Buscar();
        }

        else{
            break;
        }
    }
}

void menu_usuario::Registrar_Nuevo_Usuario()
{
    Usuario a;
    pedirNombre(a);
    pedirApellidos(a);
    pedirFechaNacimiento(a);
    pedirCorreo(a);
    pedirPassword(a);
    pedirFechaRegistro(a);
    pedirId(a);
    usuarios.insertar_ultimo(a);
}

void menu_usuario::Mostrar_Usuarios()
{
    unsigned int tamano = usuarios.tamano();
    unsigned int i = 0;

    while(i < tamano ){
        cout << usuarios[i];
        cout << endl;
        i = i + 1;
    }
}

void menu_usuario::Eliminar_Usuario()
{
    unsigned int pos = buscar_id();

    if(pos == usuarios.tamano()){
        cout << "No existe el usuario con el id " << pos << endl;
    } else{
        usuarios.eliminar(pos);
    }
}

void menu_usuario::Modicar_Usuario()
{
    unsigned int pos = buscar_id();
    if(pos == usuarios.tamano())
    {
        cout << "No existe el usuario con el id " << pos << endl;
    } else{
        string opc;

        cout << "Elige la opcion que deseas modificar" << endl;
        cout << " 1) Nombre" << endl;
        cout << " 2) Apellidos" << endl;
        cout << " 3) Fecha de Nacimiento" << endl;
        cout << " 4) Correo" << endl;
        cout << " 5) Password" << endl;
        cout << " 6) Fecha de Registro" << endl;
        cout << " 7) Id" << endl;
        getline(cin, opc);

        if("1" == opc)
        {
            pedirNombre(usuarios[pos]);
        }
        else if("2" == opc )
        {
            pedirApellidos(usuarios[pos]);
        }
        else if("3" == opc)
        {
            pedirFechaNacimiento(usuarios[pos]);
        }
        else if("4" == opc)
        {
            pedirCorreo(usuarios[pos]);
        }
        else if("5" == opc)
        {
            pedirPassword(usuarios[pos]);
        }
        else if("6" == opc)
        {
            pedirFechaRegistro(usuarios[pos]);
        }
        else if("7" == opc)
        {
            pedirId(usuarios[pos]);
        }
        else if("0" == opc)
        {

        }
    }
}

void menu_usuario::Buscar()
{
    unsigned int pos = buscar_id();

    if(pos == usuarios.tamano()){
        cout << "No existe el usuario con el id " << pos << endl;
    } else{
        cout << usuarios[pos];
    }
}
