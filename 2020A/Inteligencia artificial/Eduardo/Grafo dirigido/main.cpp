#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <list>


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

class grafo
{
    public:
    int aristas[20][20];
    string visitados[20];
    string vertice [20];
    void modificar();
    void capturar();
    void cargar_del_disco();
    void guardar_a_disco();
    void mostrar();
    void generar();
    int recorrer_vertice();
    int buscar_ciudad(string);
    void eliminar();
}G;

int Minimo(int Val1, int Val2)
 {
    int Min = Val1;
    if (Val2 < Min)
    {
        Min = Val2;
    }
    return Min;
}

int nume_Ver()
 {
    int ver = 0;
    for(int i=0;i<20; i++)
    {
        if(G.vertice[i]!= "x")
            ver++;
    }
    return ver;
}

void dijkstra()
{
    int Aux[20], VertInc[20], Ver1, Ver2, Ind1, Ind2, Menor, Band, Origen, num_ver=nume_Ver(), DistMin[400];
    string ciudad;
    for (Ind1 = 0; Ind1 < num_ver; ++Ind1)
    {
        Aux[Ind1]=0;
        VertInc[Ind1]=0;
    }
    cout << "\n\n Ingrese vertice origen: ";
    cin >> ciudad;
    Origen=G.buscar_ciudad(ciudad);

    if(Origen!=21)
    {
    Aux[Origen-1]=1;
    for (Ind1 = 0; Ind1 < num_ver; ++Ind1)
    {
        DistMin[Ind1]= G.aristas[Origen][Ind1];
    }
    for (Ind1 = 0; Ind1 < num_ver; ++Ind1)
    {
        Menor=999;
        for (Ind2 = 1; Ind2 < num_ver; ++Ind2)
        {

            if (DistMin[Ind2] < Menor && !Aux[Ind2])
            {
                Ver1 = Ind2;
                Menor = DistMin[Ind2];
            }
        }
        VertInc[Ind1] = Ver1;
        Aux[Ver1] = 1;

        Ver2 = 1;
        while (Ver2 < num_ver)
        {
            Band = 0;
            Ind2 = 1;
            while (Ind2 < num_ver && !Band)
                if (VertInc[Ind2] == Ver2)
                    Band = 1;
                else
                    Ind2++;
                if (!Band)
                    DistMin[Ver2] = Minimo(DistMin[Ver2],DistMin[Ver1] + G.aristas[Ver1][Ver2]);

            Ver2++;
        }
    }
    }

    for(Ind1=0; Ind1 < num_ver; Ind1++)
    {
        cout << G.vertice[Origen] << "-> " << DistMin[Ind1] << endl;
    }

   system("pause");
}

void primero_mejor()
{

}

bool buscar_visitados(string ciudad)
{
    int i;
    bool band=false;
    for(i=0; i<20; i++)
    {
        if(G.visitados[i]==ciudad)
        {
            band=true;
        }
    }
return band;
}


void grafo::eliminar()
{
    int aux_ver=0;
    string ciudad;
    cout<<"Ingresa el nombre de la ciudad a eliminar: ";
                fflush(stdin);
                ciudad = validar_nombre();
                aux_ver=buscar_ciudad(ciudad);
                if(aux_ver==21)
                {
                    cout<<"\n\n CIUDAD NO REGISTRADA"<<endl;
                    system("pause");
                }
                else
                {
                    int k = aux_ver + 1;

                            while (k < 20)
                            {
                            G.vertice[k-1] = G.vertice[k];
                            k++;
                            }

                            int p;
                            for (k=aux_ver+1;k<20;k++)
                            {
                                for(p=0;p<20;p++)
                                {
                                    G.aristas[p][k-1] = G.aristas[p][k];
                                   // G.aristas[k-1][p] = G.aristas[k][p];
                                }

                                for(p=0;p<20;p++)
                                {
                                  //  G.aristas[p][k-1] = G.aristas[p][k];
                                    G.aristas[k-1][p] = G.aristas[k][p];
                                }
                            }


                }


}

void grafo::modificar()
{
    int opc;
    int aux_ver=0;
    string ciudad;
    do{
        system("cls");
        cout<<"\n\t\t\t-----MODIFICAR-----"<<endl;
        cout<<" 1-MODIFICAR NOMBRE DE UNA UNA CIUDAD" << endl;
        cout <<" 2-MODIFICAR UNA ARISTA" << endl;
        cout << " 3-REGRESAR"<<endl;
        cout << " INSERTA UNA OPCtION: ";
        cin>>opc;
        switch (opc)
        {
        case 1:
            system("cls");
                cout<<"Ingresa el nombre de la ciudad a modificar: ";
                fflush(stdin);
                getline(cin,ciudad);
                aux_ver=buscar_ciudad(ciudad);
                if(aux_ver==21)
                {
                    cout<<"\n\n CIUDAD NO REGISTRADA"<<endl;
                    system("pause");
                }
                else
                {
                cout<<"\n\n Ingresa el nuevo nombre de la ciudad: ";
                fflush(stdin);
                G.vertice[aux_ver]=validar_nombre();
                }

            break;
        case 2:
            system("cls");
            int i, j;
            if((recorrer_vertice()+1)>2)
            {
                bool band=true;
                i=0;
                do{
                    cout<<"\n Ingrese la primera ciudad que desea cambiar el costo: ";
                    fflush(stdin);
                    getline(cin,ciudad);
                    i=buscar_ciudad(ciudad);
                    cout << endl;
                    if(i==21)
                    {
                        cout<<"CIUDAD NO REGISTRADA"<<endl;
                        i=0;
                    }
                    else
                    {
                        band=false;
                    }
                }while(band);

                band=true;
                j=0;
                do{
                    cout<<"\n Ingrese la segunda ciudad que desea cambiar el costo: ";
                    fflush(stdin);
                    getline(cin,ciudad);
                    cout << endl;
                    j=buscar_ciudad(ciudad);
                    if(j==21)
                    {
                        cout<<"CIUDAD NO REGISTRADA"<<endl;
                        j=0;
                    }
                    else
                        band=false;
                }while(band);

                cout<<"ingrese los kilometros de la carretera que las conecta: ";
                G.aristas[i][j]=atoi(validar_numero().c_str());
                cout << endl;

            }
            else
                cout<<"NO HAY SUFICIENTES CIUDADES!"<<endl;
                system("pause");
            break;
        }
    }while(opc!=3);
}


void grafo::generar()
{
    int i,j;
    for( i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            G.aristas[i][j]=999;
        }
    }

    for(i=0; i<20; i++)
    {
        G.vertice[i] ="x";
    }

}

void grafo::cargar_del_disco()
{
    ifstream leer("Grafo.txt");
    if(!leer.good())
        cout<<"ARCHIVO NO ENCONTRADO"<<endl;
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

int grafo::recorrer_vertice()
{
    for(int i=0; i<20; i++)
        {
            if(G.vertice[i]=="x")
            {
                return i;
            }
        }
}

int grafo::buscar_ciudad(string ciudad)
{
    int i;
    for(i=0; i<20; i++)
    {
        if(G.vertice[i]==ciudad)
        {
            return i;
        }
    }
return 21;
}



void recorrido_anchura()
{
    cout << "\t\t----------------------RECORIDO ANCHURA-------------------------\n" << endl;
    list<int> cola;
    string ciudad;
    int k=0, actual=0,p=0;
    cout << "\nIngrese vertice origen: ";
    fflush(stdin);
    getline(cin,ciudad);


    actual=G.buscar_ciudad(ciudad);
    if(actual!=21)
    {
    cola.push_back(actual);

    while(!cola.empty())
    {
        actual = cola.front();
        cola.pop_front();

     if (buscar_visitados(G.vertice[actual])==false)
     {

        G.visitados[p] = G.vertice[actual];
        cout << G.visitados[p] << ", ";
        p++;

     for(k=0;k<20;k++)
     {
        if(G.aristas[actual][k] != 999)
           {
           cola.push_back(k);
           }
     }
     }

    }
    cout << endl;



    cola.clear();

    for(int i=0; i<20; i++)
    {
        G.visitados[i] ="x";
    }
    }

    else
    {
        cout << "VERTICE NO ENCONTRADO" << endl;
    }

    system("pause");


}

void recorrido_profundidad()
{
    cout << "\t\t----------------------RECORIDO PROFUNDIDAD-------------------------\n" << endl;
    list<int> pila;
    string ciudad;
    cout << "\nIngrese vertice origen: ";
    fflush(stdin);
    getline(cin,ciudad);

    int k=0, actual=0,p=0;
    actual=G.buscar_ciudad(ciudad);
    if(actual!=21)
    {
    pila.push_back(actual);

    while(!pila.empty())
    {
        actual = pila.back();
        pila.pop_back();

     if (buscar_visitados(G.vertice[actual])==false)
     {

        G.visitados[p] = G.vertice[actual];
        cout << G.visitados[p] << ", ";
        p++;

     for(k=0;k<20;k++)
     {
        if(G.aristas[actual][k] != 999)
           {
           pila.push_back(k);
           }
     }
     }

    }
    cout << endl;



    pila.clear();

    for(int i=0; i<20; i++)
    {
        G.visitados[i] ="x";
    }
    }

    else
    {
        cout << "VERTICE NO ENCONTRADO" << endl;
    }

    system("pause");

}

void ruta_anchura()
{
    cout << "\t\t----------------------RUTA DE ANCHURA-------------------------\n" << endl;
    list<int> cola;
    string ciudad,ciudad_2;
    int k=0, actual=0,p=0;
    cout << "\nIngrese vertice origen: ";
    fflush(stdin);
    getline(cin,ciudad);
    cout << "\nIngrese vertice destino: ";
    fflush(stdin);
    getline(cin,ciudad_2);

    actual=G.buscar_ciudad(ciudad);
    if(actual!=21)
    {
    cola.push_back(actual);

    while(!cola.empty())
    {
        actual = cola.front();
        cola.pop_front();

     if (buscar_visitados(G.vertice[actual])==false)
     {
         if(G.vertice[actual]==ciudad_2)
         {
        G.visitados[p] = G.vertice[actual];
        cout << G.visitados[p] << ", ";
        p++;
        break;
         }
         else
         {
        G.visitados[p] = G.vertice[actual];
        cout << G.visitados[p] << ", ";
        p++;
         }

     for(k=0;k<20;k++)
     {
        if(G.aristas[actual][k] != 999)
           {
           cola.push_back(k);
           }
     }
     }
    }
    cout << endl;



    cola.clear();

    for(int i=0; i<20; i++)
    {
        G.visitados[i] ="x";
    }
    }

    else
    {
        cout << "VERTICE NO ENCONTRADO" << endl;
    }

    system("pause");


}

void ruta_profundidad()
{
    cout << "\t\t----------------------RUTA DE PROFUNDIDAD-------------------------\n" << endl;
    list<int> pila;
    string ciudad,ciudad_2;
    int k=0, actual=0,p=0;
    cout << "\nIngrese vertice origen: ";
    fflush(stdin);
    getline(cin,ciudad);
    cout << "\nIngrese vertice destino: ";
    fflush(stdin);
    getline(cin,ciudad_2);


    actual=G.buscar_ciudad(ciudad);
    if(actual!=21)
    {
    pila.push_back(actual);

    while(!pila.empty())
    {
        actual = pila.back();
        pila.pop_back();

     if (buscar_visitados(G.vertice[actual])==false)
     {
        if(G.vertice[actual]==ciudad_2)
         {
            G.visitados[p] = G.vertice[actual];
            cout << G.visitados[p] << ", ";
            p++;
            break;
         }
         else
         {

        G.visitados[p] = G.vertice[actual];
        cout << G.visitados[p] << ", ";
        p++;
         }

     for(k=0;k<20;k++)
     {
        if(G.aristas[actual][k] != 999)
           {
           pila.push_back(k);
           }
     }
     }

    }
    cout << endl;



    pila.clear();

    for(int i=0; i<20; i++)
    {
        G.visitados[i] ="x";
    }
    }

    else
    {
        cout << "VERTICE NO ENCONTRADO" << endl;
    }

    system("pause");

}



void grafo::capturar()
{
    int opc;
    int aux_ver=0;
    string ciudad;
    do{
        system("cls");
        cout<<"\n\t\t\t-----.VIAJES.-----"<<endl;
        cout<<" 1-INGRESAR UNA CIUDAD" << endl;
        cout <<" 2-INGRESAR UNA CARRETERA" << endl;
        cout << " 3-REGRESAR"<<endl;
        cout << " NSERTA UNA OPCCION: ";
        opc= atoi(validar_numero().c_str());
        switch (opc)
        {
        case 1:
            system("cls");
            if(recorrer_vertice()<20)
            {
                int p=0;
                aux_ver=recorrer_vertice();
                cout<<"Ingresa el nombre de la ciudad: ";
                fflush(stdin);
                getline(cin,ciudad);
                p=buscar_ciudad(ciudad);
                if(p!=21)
                {
                    cout << "\nCIUDAD YA REGISTRADA..." << endl;
                    system("pause");
                }
                else
                {
                    G.vertice[aux_ver]=ciudad;
                }
            }
            else
                cout<<"REGISTRO LLENO"<<endl;
            break;
        case 2:
            system("cls");
            int i, j;
            if((recorrer_vertice()+1)>2)
            {
                bool band=true;
                i=0;
                do{
                    cout<<"Ingrese la primera ciudad que desea conectar: ";
                    fflush(stdin);
                    getline(cin,ciudad);
                    i=buscar_ciudad(ciudad);
                    cout << endl;
                    if(i==21)
                    {
                        cout<<"CIUDAD NO REGISTRADA"<<endl;
                        i=0;
                    }
                    else
                    {
                        band=false;
                    }
                }while(band);

                band=true;
                j=0;
                do{
                    cout<<"Ingrese la segunda ciudad que desea conectar: ";
                    fflush(stdin);
                    getline(cin,ciudad);
                    cout << endl;
                    j=buscar_ciudad(ciudad);
                    if(j==21)
                    {
                        cout<<"CIUDAD NO REGISTRADA"<<endl;
                        j=0;
                    }
                    else
                        band=false;
                }while(band);

                if(G.aristas[i][j]==999)
                {
                cout<<"ingrese el costo de la arista que las conecta: ";
                G.aristas[i][j]=atoi(validar_numero().c_str());
                cout << endl;
                }
                else
                {
                    cout << "ESA ARISTA YA ESTA REALIZADA..." << endl;
                }

            }
            else
                cout<<"NO HAY SUFICIENTES CIUDADES!"<<endl;
                system("pause");
            break;
        }
    }while(opc!=3);
}

void grafo::mostrar()
{

    cout << "\n\t\tMATRIZ\n\n" << endl;

        for(int i=0; i<20; i++)
        {
            if(G.vertice[i]!="x")
            {
                cout << G.vertice[i];
            for(int j=0; j<20; j++)
            {

                if(G.aristas[i][j]!= 999)
                cout <<"->"<< G.vertice [j]  << ":"<< G.aristas[i][j] << " ";
            }
            cout<<"\n\n";
            }
        }
}


int main()
{
    G.generar();
    int opc;
    do{
        system("cls");
        cout<<"\n\t\t\t-----GRAFO DIRIGIDO PONDERADO-----"<<endl;
        cout<<"  1-CAPTURAR " << endl;
        cout<<"  2-MOSTRAR" <<endl;
        cout<<"  3.MODIFICAR" << endl;
        cout<<"  4.ELIMINAR" << endl;
        cout<<"  5-GUARDAR EN EL DISCO" << endl;
        cout <<"  6-CARGAR DEL DISCO"<<endl;
        cout <<"  7-RECORRIDO DE ANCHURA"<<endl;
        cout <<"  8-RECORRIDO DE PROFUNDIDAD"<<endl;
        cout <<"  9-RUTA DE ANCHURA"<<endl;
        cout <<"  10-RUTA DE PROFUNDIDAD"<<endl;
        cout <<"  11-DIJKSTRA" << endl;
        cout <<"  12-SALIR" << endl;
        cout << " \nELIJA UNA OPCION: ";
        opc= atoi(validar_numero().c_str());
        switch(opc)
        {
        case 1:
            G.capturar();
            break;
        case 2:
            system("cls");
            G.mostrar();
            system("pause");
            break;
        case 3:
            G.modificar();
            break;

        case 4:
            G.eliminar();
            break;
        case 5:
            G.guardar_a_disco();
            break;
        case 6:
            G.cargar_del_disco();
            break;
        case 7:
            system("cls");
            recorrido_anchura();
            fflush(stdin);
            break;
        case 8:
            system("cls");
            recorrido_profundidad();
            fflush(stdin);
            break;
        case 9:
            system("cls");
            ruta_anchura();
            fflush(stdin);
            break;
        case 10:
            system("cls");
            ruta_profundidad();
            fflush(stdin);
            break;
        case 11:
            system("cls");
            dijkstra();
            break;
        }
    }while(opc!=12);

}
