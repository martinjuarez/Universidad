#ifndef OPERACIONES_DE_GRAFOS_H_INCLUDED
#define OPERACIONES_DE_GRAFOS_H_INCLUDED

#include <stdlib.h>
#include "Tipos_y_Constantes.h"

#define ARCO_NULO nullptr
#define ETIQUETA_NULA -1
#define VERTICE_NULO nullptr
typedef int tipo_indice;

class Arco{
public:
    Etiqueta etiqueta;
    Arco(Etiqueta e){
        etiqueta=e;
    }
};

class Vertice{
    static int idSecuencial;
public:
    int numVertice;
    Etiqueta etiqueta;
    Vertice(){
        numVertice=++idSecuencial;
    }
    void fijaEtiqueta(Etiqueta e){
        etiqueta=e;
    }
    Etiqueta dameEtiqueta(){
        return etiqueta;
    }
};

int Vertice::idSecuencial=0;

class Grafo{
    Arco** arcos;
    Vertice* vertices;
    int numVertices;
public:
    Grafo(int numVertices);
    ~Grafo();
    Vertice* dameVertice(int numVertice);
    void insertaArco(Etiqueta x,Vertice* v, Vertice* w);
    void suprimeArco(const Vertice& v, const Vertice& w);
    Etiqueta etiquetaArco(Vertice* v,Vertice* w);
    Etiqueta etiquetaVertice(Vertice& v);//porque no se puede manejar con const?
};


Grafo::Grafo(int numVertices){
    int i,j;
    vertices=new Vertice[numVertices];
    arcos=new Arco*[numVertices*numVertices];
    this->numVertices=numVertices;
    for(i=0;i<numVertices;i++){
        for(j=0;j<numVertices;j++){
            arcos[i*numVertices+j]=ARCO_NULO;//en objetos es asignar NULL
        }
    }
}

Vertice* Grafo::dameVertice(int numVertice){
    return &vertices[numVertice-1];
}

void Grafo::insertaArco(Etiqueta x,Vertice* v, Vertice* w){
    //en objetos es crear un objeto Arco que guarde una Etiqueta
    arcos[(v->numVertice-1)*numVertices+w->numVertice-1]=new Arco(x);
}

void Grafo::suprimeArco(const Vertice& v, const Vertice& w){
    delete arcos[v.numVertice-1*numVertices+w.numVertice-1];
    arcos[(v.numVertice-1)*numVertices+w.numVertice-1]=ARCO_NULO;
    //en objetos, eliminar el arco y posiblemente devolver la etiqueta y no void
}

Etiqueta Grafo::etiquetaArco(Vertice* v,Vertice* w){
    Arco* arco=arcos[(v->numVertice-1)*numVertices+w->numVertice-1];
    return arco?arco->etiqueta:ETIQUETA_NULA;
}

Etiqueta Grafo::etiquetaVertice(Vertice& v){
    return v.dameEtiqueta();
}

Grafo::~Grafo(){
    free(arcos);
}

#endif // OPERACIONES_DE_COLAS_H_INCLUDED
