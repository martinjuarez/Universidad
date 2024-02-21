#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
class arista;

using namespace std;

class vertice
{
    vertice *sig;
    arista *adyacente;
    string nombre;
    friend class grafo;
};

class arista
{
    arista *sig;
    vertice *adyacente;
    int peso;
    friend class grafo;
};

class grafo
{
    vertice *h;
    public:
        void initializa();
        bool vacio();
        int tamano();
        vertice *Getvertice(string nombre);
        void insertar_arista(vertice *origen, vertice *destino, int peso);
        void insertar_vertice(string nombre);
        void lista_adyacencia();
        void Eliminar_arista(vertice *origen, vertice *destino);
        void Eliminar_vertice(vertice *ver);
        void guarar_en_disco();
        void cargar_de_disco();
        void modificar(string nombre);
        void modificar_aristas(vertice *origen, vertice *destino);
        void recorrido_anchura(vertice *origen);
        void recorrido_profundidad(vertice *origen);
        void ruta_anchura(vertice *origen, vertice *destino);
        void ruda_profundidad(vertice *origen, vertice *destino);
        void primero_mejor(vertice *origen, vertice *destino);
};

#endif // GRAFO_H
