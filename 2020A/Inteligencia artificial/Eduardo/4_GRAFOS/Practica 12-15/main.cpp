#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <Grafo_dinamico.h>
using namespace std;

string validar_nombre()
{
    string nombre;
    int i=0;
    int tope=0;
    char caracter;
    caracter = getch();
    nombre="";
    while(caracter!= 13)
    {
       if(caracter!=8)
       {
            if(tope<36)
            {
                if((caracter>64&&caracter<91)||(caracter>96&&caracter<123))
                {
                    nombre.push_back(caracter);
                    //system("cls");
                    cout << nombre[i];
                    i++;
                    tope++;
                }
                else if(caracter==32)
                {
                    nombre.push_back(caracter);
                    //system("cls");
                    cout << nombre[i];
                    i++;
                    tope++;
                }
            }
       }
       else
        {
			if (nombre.length() > 0)
            {
				cout << "\b \b";
				nombre = nombre.substr(0, nombre.length() - 1);
				i--;
				tope--;
			}
		}
        caracter=getch();
    }

    return nombre;

}
string validar_numero()
{
    string numero;
    int i=0;
    int tope=0;
    char caracter;
    caracter = getch();
    numero="";
    while(caracter!= 13)
    {
       if(caracter!=8)
       {
            if(tope<16)
            {
                if(caracter>47&&caracter<58)
                {
                    numero.push_back(caracter);
                    //system("cls");
                    cout << numero[i];
                    i++;
                    tope++;
                }
                else if(caracter==32)
                {
                    numero.push_back(caracter);
                    //system("cls");
                    cout << numero[i];
                    i++;
                    tope++;
                }
            }
       }
       else
        {
			if (numero.length() > 0)
            {
				cout << "\b \b";
				numero= numero.substr(0, numero.length() - 1);
				i--;
				tope--;
			}
		}
        caracter=getch();
    }

    return numero;
}

int main()
{
    int n=0,opc, peso;
    string origen, destino, nombre;
    Grafo G;
    G.iniciar_Ver();
    do{
        system("cls");
        cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
        cout<<"\n   1) INSERTAR VERTICE"<<endl;
        cout<<"\n   2) INSERTAR ARISTA"<<endl;
        cout<<"\n   3) MOSTRAR LISTA DE ADYACENCIA"<<endl;
        cout<<"\n   4) ELIMINAR VERTICE"<<endl;
        cout<<"\n   5) ELIMINAR ARISTA"<<endl;
        cout<<"\n   6) GUARDAR AL DISCO"<<endl;
        cout<<"\n   7) CARGAR DEL DISCO"<<endl;
        cout<<"\n   8) MODIFICAR UN VERTICE"<<endl;
        cout<<"\n   9) MODIFICAR UNA ARISTA"<<endl;
        cout<<"\n   10) RECORRIDO EN ANCHURA"<<endl;
        cout<<"\n   11) RECORRIDO EN PROFUNDIDAD"<<endl;
        cout<<"\n   12) PRIMERO EN ANCHURA"<<endl;
        cout<<"\n   13) PRIMERO EN PROFUNDIDAD"<<endl;
        cout<<"\n   14) PRIMERO EL MEJOR"<<endl;
        cout<<"\n   0) SALIR"<<endl;
        cout<<"\n   INGRESE UNA OPCCION: ";
        opc=atoi(validar_numero().c_str());cout<<"\n";
        switch(opc)
        {
        case 1:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            cout<<"\n\n   Introduce el nombre del vertice: ";
            fflush(stdin);
            nombre=validar_nombre();cout<<"\n";
            if(G.buscar_ver(nombre)==NULL)
            {
                G.capturar_Ver(nombre);
                cout<<"\n\n\n   Vertice agregado correctamente\n\n"<<endl;
            }
            else
                cout<<"\n EL VERTICE YA FUE REGISTRADO"<<endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            cout<<"\n\n   Inserta el vertice origen: ";
            fflush(stdin);
            origen=validar_nombre();cout<<"\n";
            cout<<"\n   Inserta el vertice destino: ";
            fflush(stdin);
            destino=validar_nombre();cout<<"\n";
            if(G.buscar_ver(origen)==NULL || G.buscar_ver(destino)==NULL)
                cout<<"\n\n   ALGUNO DE LOS VERTICES NO EXISTE\n\n"<<endl;
            else
            {
                cout<<"\n   Inserta el peso de la arista: ";
                peso=atoi(validar_numero().c_str());cout<<"\n";
                G.capturar_Aris(G.buscar_ver(origen), G.buscar_ver(destino), peso);
                G.capturar_Aris(G.buscar_ver(destino), G.buscar_ver(origen), peso);
            }
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----\n\n"<<endl;
            if(G.vacia_Ver())
                cout<<"\n\n   ERROR NO HAY VERTICES\n\n"<<endl;
            else
                G.mostrar_Grafo();
            cout<<"\n\n\n";
            system("pause");
            break;
        case 4:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            if(G.vacia_Ver())
                cout<<"\n\n   ERROR NO HAY VERTICES\n\n"<<endl;
            else
            {
                cout<<"\n\n   Inserta el nombre del vertice a borrar: ";
                fflush(stdin);
                nombre=validar_nombre();cout<<"\n";
                if(G.buscar_ver(nombre)==NULL)
                    cout<<"\n   EL VERTICE NO EXISTE\n\n"<<endl;
                else
                    G.eliminar_Ver(G.buscar_ver(nombre));
                cout<<"\n   VERTICE ELIMINADO\n\n"<<endl;
            }
            system("pause");
            break;
        case 5:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            if(G.vacia_Ver())
                cout<<"\n\n   ERROR NO HAY VERTICES\n\n"<<endl;
            else
            {
                cout<<"\n\n   Ingrese el vertice origen:  ";
                fflush(stdin);
                origen=validar_nombre();cout<<"\n";
                cout<<"\n   Ingrese el vertice destino:  ";
                fflush(stdin);
                destino=validar_nombre();cout<<"\n";
                if(G.buscar_ver(origen)==NULL || G.buscar_ver(destino)==NULL)
                    cout<<"\n\n   ALGUNO DE LOS VERTICES NO EXISTE\n\n"<<endl;
                else
                {
                    G.eliminar_Aris(G.buscar_ver(origen), G.buscar_ver(destino));
                    cout<<"\n   ARISTE ELIMINADA\n\n"<<endl;
                }
                system("pause");
            }
            break;
        case 6:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            G.guardar_a_disco();
            cout<<"\n\n   REGISTRO GUARDADO CORRECTAMENTE!\n\n"<<endl;
            system("pause");
            break;
        case 7:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            G.cargar_del_disco();
            cout<<"\n\n   REGISTRO CARGADO CORRECTAMENTE!\n\n"<<endl;
            system("pause");
            break;
        case 8:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            cout<<"\n\n   ingrese el nombre del vertice a modificar: ";
            fflush(stdin);
            nombre=validar_nombre();cout<<"\n";
            if(G.buscar_ver(nombre)==NULL)
                cout<<"\n   EL VERTICE NO EXISTE\n\n"<<endl;
            else
                G.modificar_vertice(nombre);
            cout<<"\n\n";
            system("pause");
            break;
        case 9:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            cout<<"\n\n   Ingrese el nombre del vertice origen: ";
            fflush(stdin);
            origen=validar_nombre();cout<<"\n";
            cout<<"\n   Ingrese el nombre del vertice destino: ";
            fflush(stdin);
            destino=validar_nombre();cout<<"\n";
            if(G.buscar_ver(origen)==NULL || G.buscar_ver(destino)==NULL)
                    cout<<"\n\n   ALGUNO DE LOS VERTICES NO EXISTE\n\n"<<endl;
            else
                G.modificar_arista(G.buscar_ver(origen), G.buscar_ver(destino));
            cout<<"\n\n";
            system("pause");
            break;
        case 10:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            cout<<"\n\n   Ingrese el nombre del vertice origen: ";
            fflush(stdin);
            origen=validar_nombre();cout<<"\n   ";
            if(G.buscar_ver(origen)==NULL)
                cout<<"\n   EL VERTICE NO EXISTE\n\n"<<endl;
            else
                G.recorrido_anchura(G.buscar_ver(origen));
            cout<<"\n\n";
            system("pause");
            break;
        case 11:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            cout<<"\n\n   Ingrese el nombre del vertice origen: ";
            fflush(stdin);
            origen=validar_nombre();cout<<"\n   ";
            if(G.buscar_ver(origen)==NULL)
                cout<<"\n   EL VERTICE NO EXISTE\n\n"<<endl;
            else
                G.recorrido_profundidad(G.buscar_ver(origen));
            cout<<"\n\n";
            system("pause");
            break;
        case 12:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            cout<<"\n\n   Ingrese el nombre del vertice origen: ";
            fflush(stdin);
            origen=validar_nombre();cout<<"\n";
            cout<<"\n   Ingrese el nombre del vertice destino: ";
            fflush(stdin);
            destino=validar_nombre();cout<<"\n   ";
            if(G.buscar_ver(origen)==NULL || G.buscar_ver(destino)==NULL)
                    cout<<"\n\n   ALGUNO DE LOS VERTICES NO EXISTE\n\n"<<endl;
            else
                G.primero_en_anchura(G.buscar_ver(origen), G.buscar_ver(destino));
            cout<<"\n\n";
            system("pause");
            break;
        case 13:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            cout<<"\n\n   Ingrese el nombre del vertice origen: ";
            fflush(stdin);
            origen=validar_nombre();cout<<"\n";
            cout<<"\n   Ingrese el nombre del vertice destino: ";
            fflush(stdin);
            destino=validar_nombre();cout<<"\n   ";
            if(G.buscar_ver(origen)==NULL || G.buscar_ver(destino)==NULL)
                    cout<<"\n\n   ALGUNO DE LOS VERTICES NO EXISTE\n\n"<<endl;
            else
                G.primero_en_profundidad(G.buscar_ver(origen), G.buscar_ver(destino));
            cout<<"\n\n";
            system("pause");
            break;
        case 14:
            system("cls");
            cout<<"\n\t\t\t-----.GRAFO DINAMICO.-----"<<endl;
            cout<<"\n\n   Ingrese el nombre del vertice origen: ";
            fflush(stdin);
            origen=validar_nombre();cout<<"\n";
            cout<<"\n   Ingrese el nombre del vertice destino: ";
            fflush(stdin);
            destino=validar_nombre();cout<<"\n   ";
            if(G.buscar_ver(origen)==NULL || G.buscar_ver(destino)==NULL)
                    cout<<"\n\n   ALGUNO DE LOS VERTICES NO EXISTE\n\n"<<endl;
            else
                G.primero_el_mejor(G.buscar_ver(origen), G.buscar_ver(destino));
            cout<<"\n\n";
            system("pause");
            break;
        }
    }while(opc!=0);
    return 0;
}
