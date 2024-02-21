#ifndef GRAFO_DINAMICO_H
#define GRAFO_DINAMICO_H
#include <list>
#include <queue>
#include <stack>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
class Arista;
class Vertice
{
    public:
    string nombre;
    Arista *aris;
    Vertice *sig;
    friend class Grafo;
};
class Arista
{
    public:
    int peso;
    Vertice *vert;
    Arista *sig;
    friend class Grafo;
};

class Grafo
{
    public:
    Vertice *primero;
    void capturar_Ver(string);
    void capturar_Aris(Vertice *origen, Vertice *destino, int peso);
    void eliminar_Ver(Vertice *aux);
    void eliminar_Aris(Vertice *origen, Vertice *destino);
    void modificar_vertice(string);
    void modificar_arista(Vertice *origen, Vertice *destino);
    Vertice *buscar_ver(string);
    bool vacia_Ver();
    void iniciar_Ver();
    void mostrar_Grafo();
    void cargar_del_disco();
    void guardar_a_disco();
    void recorrido_anchura(Vertice *origen);
    void recorrido_profundidad(Vertice *origen);
    void primero_en_anchura(Vertice *origen, Vertice *destino);
    void primero_en_profundidad(Vertice *origen, Vertice *destino);
    void primero_el_mejor(Vertice *origen, Vertice *destino);
};
#endif // GRAFO_DINAMICO_H
