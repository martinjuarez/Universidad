#include "grafo.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#include <list>
#include <stack>
#include <queue>

using namespace std;

void grafo::initializa()
{
    h = NULL;
}


bool grafo::vacio()
{
    if (h==NULL)
        return true;
    else
        return false;
}

int grafo::tamano()
{
    int contador = 0;
    vertice *aux = h;
    while(aux!=NULL)
    {
        contador++;
        aux = aux->sig;

    }

    return contador;
}
vertice* grafo::Getvertice(string nombre)
{
    vertice *aux;
    aux=h;
    while(aux!=NULL)
    {
        if(aux->nombre==nombre)
        {
            return aux;
        }
        aux = aux->sig;
    }

    return NULL;
}

void grafo::insertar_arista(vertice* origen, vertice* destino, int peso)
{
    arista *nueva = new arista;
    nueva->peso = peso;
    nueva->sig = NULL;
    nueva->adyacente = NULL;

    arista *aux;

    aux = origen->adyacente;
    if (aux == NULL)
    {
        origen->adyacente = nueva;
        nueva->adyacente = destino;

    }

    else
    {
        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = nueva;
        nueva->adyacente = destino;
    }
}

void grafo::insertar_vertice(string nombre)
{
    vertice *nuevo = new vertice;
    nuevo->nombre = nombre;
    nuevo->sig = NULL;
    nuevo->adyacente = NULL;

    if(vacio())
    {
        h = nuevo;
    }

    else
    {
        vertice *aux;
        aux = h;

        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }

        aux->sig = nuevo;
    }
}

void grafo::lista_adyacencia()
{
    vertice *vertaux;
    arista *arisaux;

    vertaux = h;

    cout << "\tLISTA DE ADYACENCIA\n" << endl;
    while(vertaux != NULL)
    {
        cout << vertaux->nombre ;
        arisaux = vertaux->adyacente;
        while(arisaux != NULL)
        {
            cout << " -> " <<  arisaux->adyacente->nombre << ":" << arisaux->peso;
            arisaux = arisaux->sig;
        }
        vertaux = vertaux->sig;
        cout << "\n" <<endl;
    }
    cout  <<endl;
}

void grafo::Eliminar_arista(vertice *origen, vertice *destino)
{
    arista *actual, *anterior;

    actual = origen->adyacente;

    if(actual==NULL)
    {
        cout << "El vertice origen no tiene aristas..." << endl;
    }

    else if(actual->adyacente == destino)
    {
        origen->adyacente = actual->sig;
        delete(actual);

        cout << "\n\tEliminada..." << endl;
    }

    else
    {
        int band=0;
        while(actual != NULL)
        {
            if(actual->adyacente == destino)
            {
                band =1;
                anterior->sig = actual->sig;
                delete(actual);
                cout << "\n\tEliminada..." << endl;
                break;
            }

            anterior = actual;
            actual = actual->sig;
        }

        if(band==0)
        {
            cout << "Vertices no conectados..." << endl;
        }
    }
}

void grafo::Eliminar_vertice(vertice* ver)
{
    vertice *actual, *anterior;
    arista *aux;

    actual = h;

    while(actual != NULL)
    {
        aux = actual->adyacente;

        while(aux != NULL)
        {
            if(aux->adyacente == ver)
            {
                Eliminar_arista(actual, aux->adyacente);
                break;
            }
            aux = aux->sig;
        }

        actual = actual->sig;

    }

    actual = h;

    if (h == ver)
    {
        h = h->sig;
        delete(actual);
    }
    else
    {
        while(actual != ver)
        {
            anterior = actual;
            actual = actual->sig;
        }

        anterior->sig = actual->sig;
        delete(actual);
    }
}
void grafo::guarar_en_disco()
{
    ofstream escribir("vertices.txt", ios::app);
    ofstream escribir2("aristas.txt", ios::app);
    vertice *aux, *vertaux=h;
    arista *arisaux;
    if(vacio())
    {
        cout << "GRAFO SIN DATOS" << endl;
    }
    else
    {
        aux = h;
        if(escribir.good())
        {
            while(aux !=NULL)
                  {
                      escribir<<aux->nombre<< " ";
                      aux = aux->sig;
                  }
    while(vertaux != NULL)
    {
        arisaux = vertaux->adyacente;
        while(arisaux != NULL)
        {
            escribir2<< vertaux->nombre<< " "<<arisaux->adyacente->nombre<< " " <<arisaux->peso<< " ";
            arisaux = arisaux->sig;
        }
        vertaux = vertaux->sig;
    }
        }
    }
    h = NULL;
    escribir2.close();
    escribir.close();
}

void grafo::cargar_de_disco()
{
    ifstream leer("vertices.txt");
    string vertice;
    string origen, destino;
    int peso;
        if(leer.good())
            {
                while(!leer.eof())
                {
                    leer>>vertice;
                    if(leer.eof())
                        break;

                    insertar_vertice(vertice);

                }

            }

    ifstream leer2("aristas.txt");
        if(leer2.good())
        {
                while(!leer2.eof())
                {
                    leer2>>origen;
                    leer2>>destino;
                    leer2>>peso;

                    if(leer2.eof())
                        break;

                    insertar_arista(Getvertice(origen),Getvertice(destino),peso);
                }

        }
    leer.close();
    leer2.close();

    remove("aristas.txt");
    remove("vertices.txt");
}

void grafo::modificar(string nombre)
{
    string nuevo;
    vertice *aux;
    aux = h;
    while(aux!=NULL)
    {
        if(aux->nombre==nombre)
        {
            cout << "INGRESE NUEVO NOMBRE DEL VERTICE:  " << endl;
            getline(cin,nuevo);
            aux->nombre=nuevo;
            break;
        }
        else
        {
        aux = aux->sig;
        }
    }

    if(aux==NULL)
    {
        cout << "VERTICE NO ENCONTRADO..." << endl;
        system("pause");
    }
}

void grafo::modificar_aristas(vertice *origen, vertice *destino)
{
    arista *actual;

    actual = origen->adyacente;
    int peso;
    if(actual==NULL)
    {
        cout << "El vertice origen no tiene aristas..." << endl;
    }

    else if(actual->adyacente == destino)
    {
        cout << "\n INFRESE NUEVO PESO DE LA ARISTA:  ";
        cin >> peso;
        actual->peso = peso;
        cout << endl;
    }

    else
    {
        int band=0;
        while(actual != NULL)
        {
            if(actual->adyacente == destino)
            {
                band =1;
                cout << "\n INFRESE NUEVO PESO DE LA ARISTA:  ";
                cin >> peso;
                actual->peso = peso;
                cout << endl;
                break;
            }
            actual = actual->sig;
        }

        if(band==0)
        {
            cout << "Vertices no conectados..." << endl;
        }
    }
}

void grafo::recorrido_anchura(vertice *origen)
{
    int band, band2;
    vertice *actual;
    queue<vertice*>cola;
    list<vertice*>lista;
    list<vertice*>::iterator i;

    cola.push(origen);
    while(!cola.empty())
    {
        band = 0;
        actual = cola.front();
        cola.pop();

        for(i=lista.begin(); i!=lista.end();i++)
        {
            if(*i == actual)
            {
                band = 1;
            }
        }

        if(band == 0)
        {
            cout << actual->nombre << ", ";
            lista.push_back(actual);

            arista *aux;
            aux = actual->adyacente;

            while(aux != NULL)
            {
                band2=0;
                for(i=lista.begin(); i!= lista.end();i++)
                {
                    if(*i == aux->adyacente)
                    {
                        band2 = 1;
                    }
                }

                if(band2 == 0)
                {
                    cola.push(aux->adyacente);
                }
                aux = aux->sig;
            }
        }
    }
}

void grafo::recorrido_profundidad(vertice *origen)
{
    int band, band2;
    vertice *actual;
    stack<vertice*>pila;
    list<vertice*>lista;
    list<vertice*>::iterator i;

    pila.push(origen);
    while(!pila.empty())
    {
        band = 0;
        actual = pila.top();
        pila.pop();

        for(i=lista.begin(); i!=lista.end();i++)
        {
            if(*i == actual)
            {
                band = 1;
            }
        }

        if(band == 0)
        {
            cout << actual->nombre << ", ";
            lista.push_back(actual);

            arista *aux;
            aux = actual->adyacente;

            while(aux != NULL)
            {
                band2=0;
                for(i=lista.begin(); i!= lista.end();i++)
                {
                    if(*i == aux->adyacente)
                    {
                        band2 = 1;
                    }
                }

                if(band2 == 0)
                {
                    pila.push(aux->adyacente);
                }
                aux = aux->sig;
            }
        }
    }
}

void grafo::ruta_anchura(vertice *origen, vertice *destino)
{
    int band, band2, band3=0;
    arista *aux;
    vertice *actual, *destino_actual;
    typedef pair<vertice*,vertice*> verticevertice;
    queue<vertice*> cola;
    stack<verticevertice>pila;
    list<vertice*> lista;
    list<vertice*>::iterator i;

    cola.push(origen);

    while(!cola.empty())
    {
        band = 0;
        actual = cola.front();
        cola.pop();

        for(i=lista.begin(); i!= lista.end();i++)
        {
            if(actual == *i)
            {
                band = 1;
            }
        }

        if(band == 0)
        {
            if(actual == destino)
            {
                band3 = 1;
                destino_actual = destino;

                while(!pila.empty())
                {
                    cout << destino_actual->nombre<< "<--";
                    while(!pila.empty() && pila.top().second != destino_actual)
                    {
                        pila.pop();
                    }

                    if(!pila.empty())
                    {
                        destino_actual = pila.top().first;
                    }
                }
            }
            lista.push_back(actual);

            aux = actual->adyacente;
            while(aux != NULL)
            {
                band2 = 0;
                for(i=lista.begin(); i!= lista.end();i++)
                {
                    if(aux->adyacente == *i)
                    {
                        band2 = 1;
                    }
                }
                if(band2 == 0)
                {
                    cola.push(aux->adyacente);
                    pila.push(verticevertice(actual, aux->adyacente));
                }
                aux = aux->sig;
            }
        }
    }

    if(band3 == 0)
    {
        cout << "RUTA IMPOSIBLE..." << endl;
    }
}

void grafo::ruda_profundidad(vertice *origen, vertice *destino)
{
    int band, bandera2, bandfinal = 0;
    vertice *actual, *destino_actual;
    arista *aux;
    typedef pair<vertice*, vertice*> par_ver;
    stack<vertice*> pila;
    list<vertice*> lista;
    stack<par_ver> pila_pares;
    list<vertice*>::iterator i;
    pila.push(origen);

    while(!pila.empty())
    {
        band= 0;
        actual = pila.top();
        pila.pop();

        for(i=lista.begin();i!=lista.end();i++)
        {
            if(actual == *i)
            {
                band = 1;
            }
        }

        if(band==0)
        {
            if(actual == destino)
            {
                bandfinal = 1;
                destino_actual = destino;

                while(!pila_pares.empty())
                {
                    cout << destino_actual->nombre<<"<-";

                    while(!pila_pares.empty() && pila_pares.top().second != destino_actual)
                    {
                        pila_pares.pop();
                    }

                    if(!pila_pares.empty())
                    {
                        destino_actual = pila_pares.top().first;
                    }
                }

            break;
          }

        lista.push_back(actual);

        aux = actual->adyacente;

        while(aux != NULL)
        {
            bandera2 = 0;
            for(i=lista.begin();i!=lista.end();i++)
            {
                if(aux->adyacente == *i)
                {
                    bandera2 = 1;
                }
            }
            if(bandera2 == 0)
            {
                pila.push(aux->adyacente);
                pila_pares.push(par_ver(actual, aux->adyacente));
            }
            aux = aux->sig;
        }

       }
   }

  if(bandfinal == 0)
  {
      cout << "RUTA IMPOSIBLE..." << endl;
  }
}




bool comparacion_mejor(pair <vertice*, int> uno , pair <vertice*, int> dos)
{
    return uno.second < dos.second;
}

void grafo::primero_mejor(vertice* origen, vertice* destino)
{
    int costo_total;
    int costo_actual=0, bandera1, bandera2=0, bandera3;
    arista *aux;
    vertice *actual, *destino_actual;
    typedef pair<vertice*, int> ver_costo;
    typedef pair<vertice*, vertice*> par_ver;
    list<ver_costo> lista_costos;
    list<ver_costo> lista_costos_ordenada;
    stack<par_ver> pila;
    list<ver_costo>::iterator i, j;

    lista_costos.push_back(ver_costo(origen, 0));
    lista_costos_ordenada.push_back(ver_costo(origen, 0));


    while(!lista_costos_ordenada.empty())
    {
        actual = lista_costos_ordenada.front().first;
        costo_actual = lista_costos_ordenada.front().second;
        lista_costos_ordenada.pop_front();

        if(actual == destino)
        {
            costo_total = costo_actual;
            bandera2 = 1;
            destino_actual = destino;

            while(!pila.empty())
            {
                cout << destino_actual->nombre<< " <-";
                while(!pila.empty()&& pila.top().second != destino_actual)
                {
                    pila.pop();
                }

                if(!pila.empty())
                {
                    destino_actual = pila.top().first;
                }


            }

            break;
        }

        aux = actual->adyacente;

        while(aux != NULL)
        {
            bandera1 = 0;
            costo_actual = costo_actual + aux->peso;

            for(i=lista_costos.begin();i!=lista_costos.end();i++)
            {
                if(aux->adyacente == i->first)
                {

                    bandera1 = 1;
                    if(costo_actual < i->second)
                    {
                        (*i).second = costo_actual;

                       for(j=lista_costos_ordenada.begin();j!=lista_costos_ordenada.end();j++)
                       {
                           if(j->first == aux->adyacente);
                           {
                               (*j).second = costo_actual;
                           }
                       }
                       lista_costos_ordenada.sort(comparacion_mejor);
                       pila.push(par_ver(actual, aux->adyacente));
                       costo_actual = costo_actual - aux->peso;
                    }
                }
            }

            if(bandera1 == 0)
            {
                lista_costos.push_back(ver_costo(aux->adyacente,costo_actual));
                lista_costos_ordenada.push_back(ver_costo(aux->adyacente, costo_actual));
                lista_costos_ordenada.sort(comparacion_mejor);
                pila.push(par_ver(actual, aux->adyacente));


                costo_actual = costo_actual - aux->peso;
            }

            aux = aux->sig;

        }
    }

    if(bandera2 == 0)
    {
        cout << "RUTA IMPOSIBLE..." << endl;
    }

    else
    {
        cout << "\n\nCOSTO TOTAL: " <<  costo_total << endl << endl;
    }
}

