#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "grafo.h"
#include <stdio.h>
#include <string.h>


using namespace std;

string validar_nombre()
{
    string nombre;
    int i=0;
    char caracter;
    caracter = getch();
    nombre="";
    while(caracter!= 13)
    {
       if(caracter!=8)
       {
            if((caracter>64&&caracter<91)||(caracter>96&&caracter<123))
            {
                nombre.push_back(caracter);
                //system("cls");
                cout << nombre[i];
                i++;
            }
            else if(caracter==32)
            {
                nombre.push_back(caracter);
                //system("cls");
                cout << nombre[i];
                i++;
            }
       }
       else
        {
			if (nombre.length() > 0)
            {
				cout << "\b \b";
				nombre = nombre.substr(0, nombre.length() - 1);
				i--;
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
    char caracter;
    caracter = getch();
    numero="";
    while(caracter!= 13)
    {
       if(caracter!=8)
       {
            if(caracter>47&&caracter<58)
            {
                numero.push_back(caracter);
                //system("cls");
                cout << numero[i];
                i++;
            }
            else if(caracter==32)
            {
                numero.push_back(caracter);
                //system("cls");
                cout << numero[i];
                i++;
            }
       }
       else
        {
			if (numero.length() > 0)
            {
				cout << "\b \b";
				numero= numero.substr(0, numero.length() - 1);
				i--;
			}
		}
        caracter=getch();
    }

    return numero;
}



int main()
{
    grafo g;
    g.initializa();
    string nombre, origen, destino;
    int opcion, peso;
    bool bandera=true;
    do{
        system("cls");
        cout << "\t\t****************GRAFO DINAMICO*************\n\n" << endl;
       cout << "  1)INSERTAR VERTICE" << endl;
       cout << "  2)INSERTAR ARISTA" << endl;
       cout << "  3)MOSTRAR LISTA DE ADYACENCIA" << endl;
       cout << "  4)ELIMINAR ARISTA" << endl;
       cout << "  5)ELIMINAR VERTICE" << endl;
       cout << "  6)GUARDAR EN DISCO" << endl;
       cout << "  7)CARGAR DE DISCO" << endl;
       cout << "  8)MODIFICAR VERTICE" << endl;
       cout << "  9)MODIFICAR ARISTA" << endl;
       cout << "  10)RECORRIDO PROFUNDIDAD" << endl;
       cout << "  11)RECORRIDO ANCHURA" << endl;
       cout << "  12)PRIMERO ANCHURA" << endl;
       cout << "  13)PRIMERO PROFUNDIDAD" << endl;
       cout << "  14)PRIMERO EL MEJOR" << endl;
       cout << "  15)SALIR" << endl;
       cout << "ELIJA OPCION:  ";
       opcion=atoi(validar_numero().c_str());
       fflush(stdin);
       switch(opcion)
       {
       case 1:
           system("cls");
           cout << "\n  INGRESE NOMBRE DEL VERTICE: ";
           getline(cin,nombre);
           if(g.Getvertice(nombre)==NULL)
           {
           g.insertar_vertice(nombre);
           }
           else
           {
            cout << "VERTICE YA REGISTRADO..." << endl;
            system("pause");
           }
        break;
       case 2:
            system("cls");
            fflush(stdin);
            if(g.tamano()>1)
            {
            cout << "\n  INGRESE NOMBRE DEL ORIGEN:  ";
            getline(cin,origen);
            cout << "\n  INGRESE NOMBRE DEL DESTINO:  ";
            getline(cin,destino);
            cout << "\n  INGRESE PESO DE LA ARISTA:  ";
            peso = atoi(validar_numero().c_str());
            if(g.Getvertice(origen)!=NULL && g.Getvertice(destino)!=NULL)
            {
            g.insertar_arista(g.Getvertice(origen),g.Getvertice(destino),peso);
            g.insertar_arista(g.Getvertice(destino),g.Getvertice(origen),peso);
            }
            else
            {
                cout << "\n\n\t\tNO SE ENCONTRARON ESOS VERTICES..." << endl;
                getch();
            }
            }
            else
            {
                cout << "\n\n\t\tNO HAY SUFICIENTES VERTICES..." << endl;
                getch();
            }
        break;
       case 3:
            system("cls");
           g.lista_adyacencia();
           system("pause");
        break;
       case 4:
           system("cls");
           if(g.tamano()>1)
            {
            cout << "\n  INGRESE NOMBRE DEL ORIGEN DE LA ARISTA A ELIMINAR:  ";
            getline(cin,origen);
            cout << "\n  INGRESE NOMBRE DEL DESTINO DE LA ARISTA A ELIMINAR:  ";
            getline(cin,destino);
           g.Eliminar_arista(g.Getvertice(origen),g.Getvertice(destino));
            }
        break;
       case 5:
           system("cls");
           if(g.vacio())
           {
               cout << "GRAFO VACIO..." << endl;
           }
           else
           {
              cout << "\n  INGRESE NOMBRE DEL VERTICE A ELIMINAR:  ";
            getline(cin,nombre);
            if (g.Getvertice(nombre)==NULL)
            {
                cout << "VERTICE NO VALIDO" << endl;
            }
            else
            {
                g.Eliminar_vertice(g.Getvertice(nombre));
            }
           }
        break;
       case 6:
           g.guarar_en_disco();
        break;
       case 7:
           g.cargar_de_disco();
        break;
       case 8:
           system("cls");
           fflush(stdin);
           cout << "INGRESE NOMBRE DEL VERTICE A MODIFICAR" << endl;
           getline(cin,nombre);
           g.modificar(nombre);
        break;
        case 9:
           system("cls");
           fflush(stdin);
           cout << "INGRESE NOMBRE DEL VERTICE ORIGEN DE LA ARISTA A MODIFICAR:  ";
           getline(cin,origen);
           cout << "INGRESE NOMBRE DEL VERTICE DESTINO DE LA ARISTA A MODIFICAR:  ";
           getline(cin,destino);
           g.modificar_aristas(g.Getvertice(origen),g.Getvertice(destino));
        break;
        case 10:
            system("cls");
            cout << "\t\tRECORRIDO PROFUNDIDAD\n\n";
           if(g.vacio())
           {
               cout << "GRAFO SIN DATOS...\n" << endl;
               system("pause");
           }
           else
           {
               cout << "INGREESE VERTICE ORIGEN:  ";
               getline(cin,origen,'\n');
               if(g.Getvertice(origen)==NULL)
               {
                   cout << "VERTICE INEXISTENTE..-" << endl;
                   system("pause");
               }

               else
               {
                   g.recorrido_profundidad(g.Getvertice(origen));
                    cout << endl;
                   system("pause");
               }
           }
           cout << endl;

        break;
        case 11:
            system("cls");
            cout << "\t\tRECORRIDO ANCHURA\n\n";
           if(g.vacio())
           {
               cout << "GRAFO SIN DATOS...\n" << endl;
               system("pause");
           }
           else
           {
               cout << "INGREESE VERTICE ORIGEN:  ";
               getline(cin,origen,'\n');
               if(g.Getvertice(origen)==NULL)
               {
                   cout << "VERTICE INEXISTENTE..-" << endl;
                   system("pause");
               }

               else
               {
                   g.recorrido_anchura(g.Getvertice(origen));
                    cout << endl;
                   system("pause");
               }
           }
           cout << endl;

        break;
        case 12:
            system("cls");
           fflush(stdin);
           cout << "\t\tPRIMERO ANCHURA\n\n";
           cout << "INGRESE NOMBRE DEL VERTICE ORIGEN:  ";
           getline(cin,origen);
           cout << "INGRESE NOMBRE DEL VERTICE DESTINO:  ";
           getline(cin,destino);
           if(g.Getvertice(origen)!=NULL && g.Getvertice(destino)!=NULL)
           {
           g.ruta_anchura(g.Getvertice(origen),g.Getvertice(destino));
            cout << endl;
           }

           else
           {
               cout << "VERTICES INEXISTENTES..." << endl;
           }
           cout << endl;
           system("pause");
            break;
        case 13:
            system("cls");
           fflush(stdin);
           cout << "\t\tPRIMERO PROFUNDIDAD\n\n";
           cout << "INGRESE NOMBRE DEL VERTICE ORIGEN:  ";
           getline(cin,origen);
           cout << "INGRESE NOMBRE DEL VERTICE DESTINO:  ";
           getline(cin,destino);
           if(g.Getvertice(origen)!=NULL && g.Getvertice(destino)!=NULL)
           {
           g.ruda_profundidad(g.Getvertice(origen),g.Getvertice(destino));
            cout << endl;
           }

           else
           {
               cout << "VERTICES INEXISTENTES..." << endl;
           }
           cout << endl;
           system("pause");
            break;
        case 14:
            system("cls");
           fflush(stdin);
           cout << "\t\tPRIMERO EL MEJOR\n\n";
           cout << "INGRESE NOMBRE DEL VERTICE ORIGEN:  ";
           getline(cin,origen);
           cout << "INGRESE NOMBRE DEL VERTICE DESTINO:  ";
           getline(cin,destino);
           cout << endl;
           cout << endl;
           if(g.Getvertice(origen)!=NULL && g.Getvertice(destino)!=NULL)
           {
           g.primero_mejor(g.Getvertice(origen),g.Getvertice(destino));
            cout << endl;
           }

           else
           {
               cout << "VERTICES INEXISTENTES..." << endl;
           }
           cout << endl;
           system("pause");
            break;
       case 15:
           bandera=false;
        break;
       }

    }while(bandera);
    return 0;
}
