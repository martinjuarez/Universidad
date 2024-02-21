#include <iostream>
#include <string>
#include <windows.h>
#include "Empleados.h"

using namespace std;



int main()

{
    bool salir;
    Empleados emp;
    int opc;
    do{
    emp.ClearScreen();
    cout << "\t\t  ZARA           " << endl <<endl <<endl;
        cout << "\t\t CARTERA DE CLIENTES.            " << endl <<endl;
                cout << "\t\t Bienvenido. Elija una opcion     " << endl <<endl <<endl;
    cout << "\t\t1.AGREGAR A UN NUEVO CLIENTE                   " << endl;
    cout << "\t\t2.EXTRAER A UN CLIENTE PARA CONSULTAR SUS DATOS" << endl;
    cout << "\t\t3.BORRAR UN CLIENTE LOGICAMENTE                " << endl;
    cout << "\t\t4.ACTUALIZAR DATOS DE UN CLIENTE               " << endl;
    cout << "\t\t5.MOSTRAR LA LISTA DE LUGARES                  " << endl;
    cout << "\t\t6.ACTIVAR UN REGISTRO ELIMINADO                " << endl;
    cout << "\t\t7.SALIR DEL PROGRAMA                           " << endl;
    cout << "\t\t";cin>>opc;

    switch(opc)
    {
            case 1:emp.Altas();
                   break;
            case 2:emp.Consultas();
                   break;
            case 3:emp.EliminacionLogica();
                   break;
            case 4:emp.Modificaciones();
                   break;
            case 5:emp.MostrarLugaresDisp();
                   break;
            case 6:emp.Activacion();
                   break;
            case 7:exit(0);
                   break;
            default:
                  cout<<"OPCION INCORRECTA INGRESSA DE NUEVO"<< endl;
                  break;
    }
  }while(!salir);
  return 0;

}
