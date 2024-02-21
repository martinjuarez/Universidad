#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class grafo
{
    public:
    int aristas[20][20];
    string vertice [20];
    int lista_visitados[20];
    void capturar();
    void cargar_del_disco();
    void guardar_a_disco();
    void mostrar();
    void modificar();
    void inicializar();
    void eliminar();
    int tamanio();
    int desplazar_vertice();
    int buscar_ciudad(string);
    void recorrido_de_anchura();
    void recorrido_de_profundidad();
    void ruta_anchura();
    void ruta_profundidad();
    bool visitado(int);

};
#endif // GRAFO_H
