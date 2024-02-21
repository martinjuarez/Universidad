#ifndef OPERACIONES_DE_GRAFOS_H_INCLUDED
#define OPERACIONES_DE_GRAFOS_H_INCLUDED

#include <stdlib.h>
#include "Tipos_y_Constantes.h"

class Grafo{
    Arco* arcos;
    int numVertices;
public:
    Grafo(int numVertices);
    ~Grafo();
    void insertaArco(Etiqueta x,Vertice v, Vertice w);
    void suprimeArco(Vertice v, Vertice w);
    Etiqueta etiquetaArco(Vertice v,Vertice w);
};


Grafo::Grafo(int numVertices){
    int i,j;
    arcos=new Arco[numVertices*numVertices];
    this->numVertices=numVertices;
    for(i=0;i<numVertices;i++){
        for(j=0;j<numVertices;j++){
            arcos[i*numVertices+j]=ARCO_NULO;//en objetos es asignar NULL
        }
    }
}

void Grafo::insertaArco(Etiqueta x,Vertice v, Vertice w){
    //en objetos es crear un objeto Arco que guarde una Etiqueta
    arcos[v*numVertices+w]=x;
}

void Grafo::suprimeArco(Vertice v, Vertice w){
    arcos[v*numVertices+w]=ARCO_NULO;
    //en objetos, eliminar el arco y posiblemente devolver la etiqueta y no void
}

Etiqueta Grafo::etiquetaArco(Vertice v,Vertice w){
    //en objetos, se le pide al arco su etiqueta
    return arcos[v*numVertices+w];
}

Grafo::~Grafo(){
    free(arcos);
}

#endif // OPERACIONES_DE_COLAS_H_INCLUDED
