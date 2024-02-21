#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

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

void grafo::inicializar()
{
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            aristas[i][j]=-1;
        }
    }
    for(int i=0; i<20; i++)
    {
        vertice[i] ="falso";
    }
}

int grafo::desplazar_vertice()
{
    for(int i=0; i<20; i++)
    {
        if(vertice[i]=="falso")
        {
            return i;
            i=21;
        }
    }
}

int grafo::tamanio()
{
    int contador=0;
    for(int i=0; i<20; i++)
    {
        if(vertice[i]!="falso")
            contador++;
    }
    return contador;
}

void grafo::cargar_del_disco()
{
    ifstream leer("Grafo.txt");
    if(!leer.good())
        cout<<"\n\n   ARCHIVO NO ENCONTRADO"<<endl;
    else
    {
        while(!leer.eof())
        {
            for(int i=0; i<20; i++)
            {
                for(int j=0; j<20; j++)
                {
                    leer>>aristas[i][j];
                }
            }
            for(int i=0; i<20; i++)
            {
                leer>>vertice[i];
            }
        }
        cout<<"\n\n   REGISTRO CARGADO\n\n"<<endl;
    }
    leer.close();
    remove("Grafo.txt");
}

void grafo::guardar_a_disco()
{
    ofstream escribir("Grafo.txt",ios::app);
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            escribir<<aristas[i][j]<<" ";
        }
    }
    for(int i=0; i<20; i++)
    {
        escribir<<vertice[i]<<" ";
    }
    escribir.close();
}

void grafo::capturar()
{
    char opc;
    int aux_ver=0;
    string ciudad;
    do{
        system("cls");
        cout<<"\n\t\t\t-----.CAPTURAR.-----\n\n"<<endl;
        cout<<"\n   1-INGRESAR UN VERTICE\n   2-INGRESAR UN PESO\n   0-REGRESAR\n   INSERTA UNA OPCCION: ";
        cin>>opc;
        switch (opc)
        {
        case '1':
            system("cls");
            cout<<"\n\t\t\t-----.CAPTURAR.-----\n\n"<<endl;
            if(desplazar_vertice()<20)
            {
                aux_ver=desplazar_vertice();
                cout<<"   Ingresa el nombre del vertice: ";
                fflush(stdin);
                vertice[aux_ver]=validar_nombre();
                cout<<"\n";
            }
            else
            {
                cout<<"   REGISTRO LLENO"<<endl;
                system("pause");
            }
            break;
        case '2':
            system("cls");
            cout<<"\n\t\t\t-----.CAPTURAR.-----\n\n"<<endl;
            int i, j;

            if((tamanio()+1)>2)
            {
                int x=0;
                i=0;
                do{
                    cout<<"   Ingrese el vertice origen: ";
                    fflush(stdin);
                    ciudad=validar_nombre();
                    cout<<"\n";
                    i=buscar_ciudad(ciudad);
                    if(i==21)
                    {
                        cout<<"   VERTICE NO REGISTRADO"<<endl;
                        i=0;
                    }
                    else
                        x=1;
                }while(x!=1);
                x=0;
                j=0;
                do{
                    cout<<"   Ingrese el vertice destino: ";
                    fflush(stdin);
                    ciudad=validar_nombre();
                    cout<<"\n";
                    j=buscar_ciudad(ciudad);
                    if(j==21)
                    {
                        cout<<"   VERTICE NO REGISTRADA"<<endl;
                        j=0;
                    }
                    else
                        x=1;
                }while(x!=1);

                cout<<"   ingrese el peso de la arista: ";
                aristas[i][j]=atoi(validar_numero().c_str());
                cout<<"\n";
            }
            else
            {
                cout<<"   NO HAY SUFICIENTES VERTICES!"<<endl;
                system("pause");
            }

            break;
        }
    }while(opc!='0');
}

void grafo::mostrar()
{
    cout<<"\n\t\t\t-----.MATRIZ DE ADYACENCIA.-----\n\n"<<endl;
    /*for(int i=0; i<20; i++)
    {
        cout<<i<<" "<<vertice[i]<<endl;
    }
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            cout<<aristas[i][j]<<" ";
        }
        cout << endl;
    }*/
    for(int i=0; i<20; i++)
    {
        if(vertice[i]!="falso")
        {
            cout<<"   "<<vertice[i];
            for(int j=0; j<20; j++)
            {
                if(aristas[i][j]>0)
                {
                    cout<<" -> "<<vertice[j]<<":"<<aristas[i][j];
                }
            }
        }
        cout<<"\n\n";
    }
}

void grafo::modificar()
{
    char opc;
    int i=0;
    int x;
    int j=0;
    string aux;
    do{
        system("cls");
        cout<<"\n\t\t\t-----.MODIFICAR.-----"<<endl;
        cout<<"\n   QUE DESCEA MODIFICAR?\n\n   1-NOMBRE DE UN VERTICE\n   2-PESO ENTRE DOS VERTICES\n   0-REGRESAR\n   INGRESA UNA OPCCION: ";
        cin>>opc;
        switch(opc)
        {
        case '1':
            system("cls");
            cout<<"\n\t\t\t-----.MODIFICAR.-----"<<endl;
            x=0;
            do{
            cout<<"   Ingrese el nombre del vertice a modificar: ";
            fflush(stdin);
            aux=validar_nombre();
            i=buscar_ciudad(aux);
            cout<<"\n";
            if(i==21)
            {
                cout<<"   VERTICE NO REGISTRADO"<<endl;
                i=0;
            }
            else
                x=1;
            }while(x!=1);
            cout<<"   Ingrese el nuevo nombre del vertice: ";
            vertice[i]=validar_nombre();
            cout<<"\n";
            break;
        case '2':
            system("cls");
            cout<<"\n\t\t\t-----.MODIFICAR.-----"<<endl;
            x=0;
            do{
            cout<<"   Ingrese el vertice origen: ";
            fflush(stdin);
            aux=validar_nombre();
            i=buscar_ciudad(aux);
            cout<<"\n";
            if(i==21)
            {
                cout<<"   VERTICE NO REGISTRADO"<<endl;
                i=0;
            }
            else
                x=1;
            }while(x!=1);
            j=0;
            x=0;
            do{
            cout<<"  Ingrese el vertice destino: ";
            fflush(stdin);
            aux=validar_nombre();
            j=buscar_ciudad(aux);
            cout<<"\n";
            if(j==21)
            {
                cout<<"   VERTICE NO REGISTRADO"<<endl;
                j=0;
            }
            else
                x=1;
            }while(x!=1);
            if(aristas[i][j]<0)
            {
                cout<<"   NO EXISTE CONEXION ENTRE ESTOS DOS VERTICES"<<endl;
                system("pause");
            }
            else
            {
                cout<<"   Inserte el nuevo peso de la arista: ";
                aristas[i][j]=atoi(validar_numero().c_str());
                cout<<"\n";
            }
            break;
        }
    }while(opc!='0');
}

void grafo::eliminar()
{
    int aux_ver=0;
    string ciudad;
    char opc;
    system("cls");
    cout<<"\n\t\t\t-----.ELIMINAR.-----\n\n"<<endl;
    cout<<"   QUE DESCEA ELIMINAR?\n\n   1-VERTICE\n   2-ARISTA\n   0-SALIR\n   INSERTA UNA OPCCION: ";
    cin>>opc;
    switch(opc)
    {
    case '1':
        system("cls");
        cout<<"\n\t\t\t-----.ELIMINAR.-----\n\n"<<endl;
        cout<<"   Ingresa el nombre del vertice a eliminar: ";
        fflush(stdin);
        ciudad = validar_nombre();
        aux_ver=buscar_ciudad(ciudad);
        cout<<"\n\n\n\n   ";
        if(aux_ver==21)
        {
            cout<<"\n   VERTICE NO REGISTRADO\n\n"<<endl;
            system("pause");
        }
        else
        {
            int k = aux_ver + 1;
                while (k < 20)
                {
                    vertice[k-1] = vertice[k];
                    k++;
                }
                int p;
                for (k=aux_ver+1;k<20;k++)
                {
                    for(p=0;p<20;p++)
                    {
                        aristas[p][k-1] = aristas[p][k];
                    }
                    for(p=0;p<20;p++)
                    {
                        aristas[k-1][p] = aristas[k][p];
                    }
                }
                cout<<"VERTICE Y CONEXIONES ELIMINADAS"<<endl;
        }
        /*cout<<"\n   Ingresa el nombre de la ciudad a eliminar: ";
        fflush(stdin);
        ciudad = validar_nombre();
        aux_ver=buscar_ciudad(ciudad);
        if(aux_ver==21||vertice[aux_ver]=="falso")
        {
            cout<<"\n\n CIUDAD NO REGISTRADA"<<endl;
        }
        else
        {
            vertice[aux_ver]="falso";
            for(int i=0; i<20; i++)
            {
                aristas[aux_ver][i]=0;
                aristas[i][aux_ver]=0;
            }
            cout<<"\n\n   CIUDAD Y CONEXIONES ELIMINADAS\n\n"<<endl;
        }*/
        break;
    case '2':
        system("cls");
        cout<<"\n\t\t\t-----.ELIMINAR.-----\n\n"<<endl;
        int i, j;

        if((tamanio()+1)>2)
        {
            int x=0;
            i=0;
            do{
                cout<<"   Ingrese el vertice origen: ";
                fflush(stdin);
                ciudad=validar_nombre();
                cout<<"\n";
                i=buscar_ciudad(ciudad);
                if(i==21)
                {
                    cout<<"   VERTICE NO REGISTRADO"<<endl;
                    i=0;
                }
                else
                    x=1;
            }while(x!=1);
            x=0;
            j=0;
            do{
                cout<<"   Ingrese el vertice destino: ";
                fflush(stdin);
                ciudad=validar_nombre();
                cout<<"\n";
                j=buscar_ciudad(ciudad);
                if(j==21)
                {
                    cout<<"   VERTICE NO REGISTRADO"<<endl;
                    j=0;
                }
                else
                    x=1;
            }while(x!=1);
            if(aristas[i][j]!=-1)
            {
                cout<<"   CONEXION ELIMINADA "<<endl;;
                aristas[i][j]=-1;
                cout<<"\n";
            }
            else
                cout<<"   NO EXISTE CONEXION ENTRE ESTOS DOS VERTICES"<<endl;
        }
        else
        {
            cout<<"   NO HAY SUFICIENTES VERTICES!"<<endl;
            system("pause");
        }
        break;
    }

}

int grafo::buscar_ciudad(string ciudad)
{
    int i;
    for(i=0; i<20; i++)
    {
        if(vertice[i]==ciudad)
        {
            return i;
            i=21;
        }
    }
return 21;
}

bool grafo::visitado(int hola)
{
    for(int j=0; j<20; j++)
    {
        if(lista_visitados[j] == hola)
            return false;
    }
return true;
}

void grafo::recorrido_de_anchura()
{
    string origen;
    int cola[400];
    int inicio=0;
    int i_visitados=0;
    int fin=0;
    int vertice_actual;
    cout<<"\n\t\t-----.RECORRIDO DE ANCHURA.-----\n\n"<<endl;
    if(tamanio()==0)
    {
        cout<<"   NO HAY REGISTROS GUARDADOS"<<endl;
    }
    else
    {
        for(int i=0; i<400; i++)
            cola[i]=-1;
        for(int i=0; i<20; i++)
            lista_visitados[i]=-1;
        cout<<"   Inserte el vertice origen: ";
        origen=validar_nombre();
        cout<<"\n\n\n  ";
        if(buscar_ciudad(origen)==21)
            cout<<"   VERTICE NO ENCONTRADO"<<endl;
        else
        {
            cola[inicio]=buscar_ciudad(origen);
            while(cola[inicio]!=-1)
            {
                vertice_actual=cola[inicio];
                inicio++;

                if(visitado(vertice_actual))
                {
                    cout<<" -> "<<vertice[vertice_actual];
                    lista_visitados[i_visitados]=vertice_actual;
                    i_visitados++;

                    for(int t=0; t<20; t++)
                    {
                        if(aristas[vertice_actual][t]!=-1)
                        {
                            fin++;
                            cola[fin]=t;
                        }
                    }
                }
            }
        }
    }
cout<<"\n\n\n\n\n"<<endl;
}

void grafo::recorrido_de_profundidad()
{
    string origen;
    int pila[400];
    int i_pila=0;
    int i_visitados=0;
    int aux_i=0;
    int vertice_actual;
    cout<<"\n\t\t\t-----.RECORRIDO DE PROFUNDIDAD.-----\n\n"<<endl;
    if(tamanio()==0)
    {
        cout<<"   NO HAY REGISTROS GUARDADOS"<<endl;
    }
    else
    {
        for(int i=0; i<400; i++)
            pila[i]=-1;
        for(int i=0; i<20; i++)
            lista_visitados[i]=-1;
        cout<<"   Inserte el vertice origen: ";
        origen=validar_nombre();
        cout<<"\n\n\n  ";
        if(buscar_ciudad(origen)==21)
            cout<<"   VERTICE NO ENCONTRADO"<<endl;
        else
        {
            i_pila++;
            pila[i_pila]=buscar_ciudad(origen);

            while(pila[i_pila]>=0)
            {
                vertice_actual=pila[i_pila];
                pila[i_pila]=-1;
                i_pila--;
                if(visitado(vertice_actual)==true)
                {
                    cout<<" -> "<<vertice[vertice_actual];
                    lista_visitados[i_visitados]=vertice_actual;
                    i_visitados++;
                    for(int h=0; h<20; h++)
                    {
                        if(aristas[vertice_actual][h]>=0)
                        {
                            i_pila++;
                            pila[i_pila]=h;
                        }
                    }
                }
            }
        }
    }
cout<<"\n\n\n\n\n"<<endl;
}

void grafo::ruta_anchura()
{
    string origen;
    string destino;
    int destino1;
    int cola[400];
    int inicio=0;
    int i_visitados=0;
    int fin=0;
    int vertice_actual;
    cout<<"\n\t\t-----.RUTA DE ANCHURA.-----\n\n"<<endl;
    if(tamanio()==0)
    {
        cout<<"   NO HAY REGISTROS GUARDADOS"<<endl;
    }
    else
    {
        for(int i=0; i<400; i++)
            cola[i]=-1;
        for(int i=0; i<20; i++)
            lista_visitados[i]=-1;
        int x=0;
        do{
            cout<<"   Inserte el vertice origen: ";
            origen=validar_nombre();
            cout<<"\n\n\n  ";
            if(buscar_ciudad(origen)==21)
                cout<<"   VERTICE NO ENCONTRADO"<<endl;
            else
                x=1;
            cout<<"\n";
        }while(x!=1);
        x=0;
        do{
            cout<<"   Inserte el vertice destino: ";
            destino=validar_nombre();
            cout<<"\n";
            if(buscar_ciudad(destino)==21)
                cout<<"   VERTICE NO ENCONTRADO"<<endl;
            else
                x=1;
        }while(x!=1);
            destino1=buscar_ciudad(destino);
            cola[inicio]=buscar_ciudad(origen);
            while(cola[inicio]!=-1)
            {
                vertice_actual=cola[inicio];
                inicio++;

                if(visitado(vertice_actual))
                {
                    if(vertice_actual==destino1)
                    {
                        cout<<"\n\n   RUTA ENCONTRADA: ";
                        lista_visitados[i_visitados]=vertice_actual;
                            i_visitados++;
                        for(int t=0; t<i_visitados; t++)
                        {
                            cout<<" -> "<<vertice[lista_visitados[t]];
                        }
                        break;
                    }
                    else
                    {
                        lista_visitados[i_visitados]=vertice_actual;
                        i_visitados++;

                        for(int t=0; t<20; t++)
                        {
                            if(aristas[vertice_actual][t]!=-1)
                            {
                                fin++;
                                cola[fin]=t;
                            }
                        }
                    }
                }
            }
    }
cout<<"\n\n\n\n\n"<<endl;
}

void grafo::ruta_profundidad()
{
    string origen;
    string destino;
    int destino1;
    int pila[400];
    int i_pila=0;
    int i_visitados=0;
    int aux_i=0;
    int vertice_actual;
    cout<<"\n\t\t\t-----.RUTA DE PROFUNDIDAD.-----\n\n"<<endl;
    if(tamanio()==0)
    {
        cout<<"   NO HAY REGISTROS GUARDADOS"<<endl;
    }
    else
    {
        for(int i=0; i<400; i++)
            pila[i]=-1;
        for(int i=0; i<20; i++)
            lista_visitados[i]=-1;
        int x=0;
        do{
            cout<<"  Inserte el vertice origen: ";
            origen=validar_nombre();
            cout<<"\n\n ";
            if(buscar_ciudad(origen)==21)
                cout<<"   VERTICE NO ENCONTRADO"<<endl;
            else
                x=1;
        }while(x!=1);
        x=0;
        do{
            cout<<"   Inserte el vertice destino: ";
            destino=validar_nombre();
            cout<<"\n\n\n  ";
            if(buscar_ciudad(destino)==21)
                cout<<"   VERTICE NO ENCONTRADO"<<endl;
            else
                x=1;
            cout<<"\n";
        }while(x!=1);
        destino1=buscar_ciudad(destino);

            i_pila++;
            pila[i_pila]=buscar_ciudad(origen);

            while(pila[i_pila]>=0)
            {
                vertice_actual=pila[i_pila];
                pila[i_pila]=-1;
                i_pila--;
                if(visitado(vertice_actual)==true)
                {

                    if(vertice_actual==destino1)
                    {
                        lista_visitados[i_visitados]=vertice_actual;
                        i_visitados++;
                        cout<<"\n\n   RUTA ENCONTRADA: ";
                        for(int k=0; k<i_visitados; k++)
                        {
                            cout<<" -> "<<vertice[lista_visitados[k]];
                        }
                        break;
                    }
                    else
                    {
                        lista_visitados[i_visitados]=vertice_actual;
                        i_visitados++;
                        for(int h=0; h<20; h++)
                        {
                            if(aristas[vertice_actual][h]>=0)
                            {
                                i_pila++;
                                pila[i_pila]=h;
                            }
                        }
                    }
                }
            }
    }
cout<<"\n\n\n\n\n"<<endl;
}
