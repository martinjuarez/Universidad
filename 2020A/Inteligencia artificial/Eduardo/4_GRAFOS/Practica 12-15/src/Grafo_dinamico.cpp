#include "Grafo_dinamico.h"

void Grafo::iniciar_Ver()
{
    primero=NULL;
}
bool Grafo::vacia_Ver()
{
    if(primero==NULL)
        return true;
    else
        return false;
}
Vertice* Grafo::buscar_ver(string nom)
{
    Vertice *aux;
    aux=primero;
    while(aux)
    {
        if(aux->nombre==nom)
            return aux;
        else
            aux=aux->sig;
    }
return aux;
}
void Grafo::capturar_Ver(string nombre)
{
    Vertice *aux=new Vertice;
    aux->sig=NULL;
    aux->aris=NULL;
    aux->nombre=nombre;
    if(vacia_Ver())
    {
        primero=aux;
    }
    else
    {
        Vertice *temp=primero;
        while(temp->sig)
        {
            temp=temp->sig;
        }
        temp->sig=aux;
    }
}
void Grafo::capturar_Aris(Vertice *origen, Vertice *destino, int peso)
{
    Arista *aux=new Arista;
            aux->peso=peso;
            aux->sig=NULL;
            aux->vert=destino;
    if(origen->aris==NULL)
    {
        origen->aris=aux;
    }
    else
    {
        Arista *temp=origen->aris;
        while(temp->sig)
        {
            temp=temp->sig;
        }
        temp->sig=aux;
    }
}

void Grafo::mostrar_Grafo()
{
    Vertice *aux;
    aux=primero;
    Arista *temp;
    while(aux)
    {
        cout<<aux->nombre;
        temp=aux->aris;
        while(temp)
        {
            cout<<" -> "<<temp->vert->nombre<<":"<<temp->peso;
            temp=temp->sig;
        }
        cout<<endl;
        aux=aux->sig;
    }
}
void Grafo::eliminar_Ver(Vertice *aux)
{
    Vertice *actual, *ant;
    Arista *temp;

    actual = primero;

    while(actual != NULL)
    {
        temp = actual->aris;

        while(temp != NULL)
        {
            if(temp->vert == aux)
            {
                eliminar_Aris(actual, temp->vert);
                break;
            }
            temp = temp->sig;
        }

        actual = actual->sig;

    }

    actual = primero;

    if (primero == aux)
    {
        primero = primero->sig;
        delete(actual);
    }
    else
    {
        while(actual != aux)
        {
            ant=actual;
            actual=actual->sig;
        }
        ant->sig=actual->sig;
        delete(actual);
    }
}
void Grafo::eliminar_Aris(Vertice* origen, Vertice* destino)
{
    Arista *actual, *ant;

    actual = origen->aris;

    if(actual==NULL)
        cout<<"NO HAY ARISTAS"<<endl;
    else if(actual->vert == destino)
    {
        origen->aris = actual->sig;
        delete(actual);
    }
    else
    {
        int band=0;
        while(actual != NULL)
        {
            if(actual->vert == destino)
            {
                band =1;
                ant->sig = actual->sig;
                delete(actual);
                cout << "\n\tEliminada..." << endl;
                break;
            }
            ant = actual;
            actual = actual->sig;
        }
        if(band==0)
        {
            cout<<"NO HAY ARISTA"<<endl;
        }
    }
}
void Grafo::cargar_del_disco()
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

            capturar_Ver(vertice);

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

                capturar_Aris(buscar_ver(origen),buscar_ver(destino),peso);
            }

    }
    leer.close();
    leer2.close();

    remove("aristas.txt");
    remove("vertices.txt");
}

void Grafo::guardar_a_disco()
{
    ofstream escribir("vertices.txt", ios::app);
    ofstream escribir2("aristas.txt", ios::app);
    Vertice *aux, *vertaux=primero;
    Arista *arisaux;
    if(vacia_Ver())
    {
        cout<< "GRAFO SIN DATOS" << endl;
    }
    else
    {
        aux = primero;
        if(escribir.good())
        {
            while(aux !=NULL)
                  {
                      escribir<<aux->nombre<< " ";
                      aux = aux->sig;
                  }
            while(vertaux != NULL)
            {
                arisaux = vertaux->aris;
                while(arisaux != NULL)
                {
                    escribir2<< vertaux->nombre<< " "<<arisaux->vert->nombre<< " " <<arisaux->peso<< " ";
                    arisaux = arisaux->sig;
                }
                vertaux = vertaux->sig;
            }
        }
    }
    primero = NULL;
    escribir2.close();
    escribir.close();
}
void Grafo::modificar_vertice(string nombre)
{
    string nuevo;
    Vertice *aux;
    aux = primero;
    while(aux!=NULL)
    {
        if(aux->nombre==nombre)
        {
            cout<<"\n   Ingresa el nuevo nombre: ";
            fflush(stdin);
            getline(cin,nuevo);
            aux->nombre=nuevo;
            break;
        }
        else
        {
        aux=aux->sig;
        }
    }
}

void Grafo::modificar_arista(Vertice* origen, Vertice* destino)
{
    int peso;
    Arista *actual;
    actual = origen->aris;
    if(actual==NULL)
        cout<<"EL VERTICE NO TIENE ARISTAS"<<endl;
    else if(actual->vert == destino)
    {
        cout<<"Ingresa el nuevo peso de la arista:  ";
        cin>>peso;
        actual->peso = peso;
        cout<<endl;
    }
    else
    {
        int band=0;
        while(actual != NULL)
        {
            if(actual->vert == destino)
            {
                band =1;
                cout<<"Ingrese el nuevo peso de la arista:  ";
                cin >> peso;
                actual->peso = peso;
                cout << endl;
                break;
            }
            actual = actual->sig;
        }
        if(band==0)
            cout<<"NO HAY CONECCION ENTRE ESTOS DOS VERTICES"<<endl;
    }
}

void Grafo::recorrido_anchura(Vertice* origen)
{
    Vertice *actual;
    int band, band2;
    queue<Vertice*> cola;
    list<Vertice*> lista;
    list<Vertice*>::iterator i;
    cola.push(origen);

    while(!cola.empty())
    {
        band=0;
        actual=cola.front();
        cola.pop();

        for(i=lista.begin(); i!=lista.end(); i++)
        {
            if(*i==actual)
                band=1;
        }
        if(band==0)
        {
            cout<<actual->nombre<<", ";
            lista.push_back(actual);

            Arista *aux;
            aux=actual->aris;
            while(aux!=NULL)
            {
                band2=0;
                for(i=lista.begin(); i!=lista.end(); i++)
                {
                    if(aux->vert==*i)
                        band2=1;
                }
                if(band2==0)
                    cola.push(aux->vert);
                aux=aux->sig;
            }
        }
    }
}

void Grafo::recorrido_profundidad(Vertice* origen)
{
    Vertice *actual;
    int band, band2;
    stack<Vertice*> pila;
    list<Vertice*> lista;
    list<Vertice*>::iterator i;

    pila.push(origen);

    while(!pila.empty())
    {
        band=0;
        actual=pila.top();
        pila.pop();

        for(i=lista.begin(); i!=lista.end(); i++)
        {
            if(*i==actual)
                band=1;
        }
        if(band==0)
        {
            cout<<actual->nombre<<", ";
            lista.push_back(actual);

            Arista *aux;
            aux=actual->aris;

            while(aux!=NULL)
            {
                band2=0;
                for(i=lista.begin(); i!=lista.end(); i++)
                {
                    if(*i==aux->vert)
                        band2=0;
                }
                if(band2==0)
                    pila.push(aux->vert);
                aux=aux->sig;
            }
        }
    }
}

void Grafo::primero_en_anchura(Vertice* origen, Vertice* destino)
{
    int band, band2, band3=0;
    Vertice *actual, *destinoactual;
    Arista *aux;
    typedef pair<Vertice*, Vertice*> PilaPar;
    queue<Vertice*> cola;
    stack<PilaPar>pila;
    list<Vertice*> lista;
    list<Vertice*>::iterator i;

    cola.push(origen);

    while(!cola.empty())
    {
        band=0;
        actual=cola.front();
        cola.pop();
        for(i=lista.begin(); i!=lista.end(); i++)
        {
            if(actual==*i)
                band=1;
        }
        if(band==0)
        {
            if(actual==destino)
            {
                band3=1;
                destinoactual=destino;

                while(!pila.empty())
                {
                    cout<<destinoactual->nombre<<" <- ";
                    while(!pila.empty() && pila.top().second != destinoactual)
                    {
                        pila.pop();
                    }
                    if(!pila.empty())
                    {
                        destinoactual=pila.top().first;
                    }
                }
            }

            lista.push_back(actual);

            aux=actual->aris;
            while(aux!=NULL)
            {
                band2=0;
                for(i=lista.begin(); i!=lista.end(); i++)
                {
                    if(*i==aux->vert)
                        band2=1;
                }
                if(band2==0)
                {
                    cola.push(aux->vert);
                    pila.push(PilaPar(actual,aux->vert));
                }
                aux=aux->sig;
            }
        }
    }

if(band3==0)
    cout<<"No existe ruta entre esos dos vertices"<<endl;
}

void Grafo::primero_en_profundidad(Vertice* origen, Vertice* destino)
{
    int band, bandera2, bandfinal = 0;
    Vertice *actual, *destino_actual;
    Arista *aux;
    typedef pair<Vertice*, Vertice*> par_ver;
    stack<Vertice*> pila;
    list<Vertice*> lista;
    stack<par_ver> pila_pares;
    list<Vertice*>::iterator i;
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

        aux = actual->aris;

        while(aux != NULL)
        {
            bandera2 = 0;
            for(i=lista.begin();i!=lista.end();i++)
            {
                if(aux->vert == *i)
                {
                    bandera2 = 1;
                }
            }
            if(bandera2 == 0)
            {
                pila.push(aux->vert);
                pila_pares.push(par_ver(actual, aux->vert));
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

bool comparacion_mejor(pair <Vertice*, int> uno , pair <Vertice*, int> dos)
{
    return uno.second < dos.second;
}

void Grafo::primero_el_mejor(Vertice* origen, Vertice* destino)
{
    int costo_actual=0, bandera1, bandera2=0, bandera3, costo=0;
    Arista *aux;
    Vertice *actual, *destino_actual;
    typedef pair<Vertice*, int> ver_costo;
    typedef pair<Vertice*, Vertice*> par_ver;
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

            bandera2 = 1;
            destino_actual = destino;

            while(!pila.empty())
            {
                cout <<" <- "<< destino_actual->nombre;

                while(!pila.empty()&& pila.top().second != destino_actual)
                {
                    pila.pop();
                }

                if(!pila.empty())
                {
                    destino_actual = pila.top().first;
                }
            }
            cout<<"COSTO TOTAL: "<<costo_actual<<endl;
            break;
        }

        aux = actual->aris;

        while(aux != NULL)
        {
            bandera1 = 0;
            costo_actual = costo_actual + aux->peso;

            for(i=lista_costos.begin(); i!=lista_costos.end(); i++)
            {
                if(aux->vert == i->first)
                {

                    bandera1 = 1;
                    if(costo_actual < i->second)
                    {
                        (*i).second = costo_actual;

                       for(j=lista_costos_ordenada.begin(); j!=lista_costos_ordenada.end(); j++)
                       {
                           if(j->first == aux->vert);
                           {
                               (*j).second = costo_actual;
                           }
                       }
                       lista_costos_ordenada.sort(comparacion_mejor);
                       pila.push(par_ver(actual, aux->vert));
                       costo_actual = costo_actual - aux->peso;
                    }
                }
            }

            if(bandera1 == 0)
            {
                lista_costos.push_back(ver_costo(aux->vert,costo_actual));
                lista_costos_ordenada.push_back(ver_costo(aux->vert, costo_actual));
                lista_costos_ordenada.sort(comparacion_mejor);
                pila.push(par_ver(actual, aux->vert));


                costo_actual = costo_actual - aux->peso;
            }

            aux = aux->sig;
        }
    }

    if(bandera2 == 0)
    {
        cout << "RUTA IMPOSIBLE..." << endl;
    }
}


