#ifndef OPERACIONES_DE_GRAFOS_H_INCLUDED
#define OPERACIONES_DE_GRAFOS_H_INCLUDED

#include <cstdlib>
#include "Tipos_y_Constantes.h"

template<class EtiquetaArco>
class Arco{
public:
    EtiquetaArco etiqueta;
    Arco(EtiquetaArco e){
        etiqueta=e;
    }
    ~Arco(){
        cout << "destruyendo arco con etiqueta " << etiqueta << endl;
    }
};

template <class EtiquetaVertice>
class Vertice{
    static int idSecuencial;
public:
    int numVertice;
    EtiquetaVertice etiqueta;
    Vertice(){
        numVertice=++idSecuencial;
    }
    ~Vertice(){
        cout << "destruyendo vertice " << numVertice << endl;
    }
    void fijaEtiqueta(EtiquetaVertice e){
        etiqueta=e;
    }
    EtiquetaVertice dameEtiqueta(){
        return etiqueta;
    }
};

template <class EtiquetaVertice>
int Vertice<EtiquetaVertice>::idSecuencial=0;

template <class EtiquetaVertice,class EtiquetaArco>
class Grafo{
    Arco<EtiquetaArco>** arcos;
    Vertice<EtiquetaVertice>* vertices;
    int numVertices;
public:
    Grafo(int numVertices);
    ~Grafo();
    Vertice<EtiquetaVertice>* dameVertice(int numVertice);
    void insertaArco(EtiquetaArco x,Vertice<EtiquetaVertice>* v, Vertice<EtiquetaVertice>* w);
    EtiquetaArco suprimeArco(const Vertice<EtiquetaVertice>& v, const Vertice<EtiquetaVertice>& w);
    EtiquetaArco etiquetaArco(Vertice<EtiquetaVertice>* v,Vertice<EtiquetaVertice>* w);
    EtiquetaVertice etiquetaVertice(Vertice<EtiquetaVertice>& v);//porque no manejar const?
    tipo_indice primero(Vertice<EtiquetaVertice>* v);
    tipo_indice siguiente(Vertice<EtiquetaVertice>* v,tipo_indice indice);
    Vertice<EtiquetaVertice>* dameVertice(Vertice<EtiquetaVertice>* v,tipo_indice indice);
    //pendiente insercion y supresion de vertices
};


template <class EtiquetaVertice,class EtiquetaArco>
Grafo<EtiquetaVertice,EtiquetaArco>::Grafo(int numVertices){
    int i,j;
    vertices=new Vertice<EtiquetaVertice>[numVertices];
    arcos=new Arco<EtiquetaArco>*[numVertices*numVertices];
    this->numVertices=numVertices;
    for(i=0;i<numVertices;i++){
        for(j=0;j<numVertices;j++){
            arcos[i*numVertices+j]=ARCO_NULO;
        }
    }
}

template <class EtiquetaVertice,class EtiquetaArco>
Vertice<EtiquetaVertice>* Grafo<EtiquetaVertice,EtiquetaArco>::dameVertice(int numVertice){
    return &vertices[numVertice-1];
}

template <class EtiquetaVertice,class EtiquetaArco>
void Grafo<EtiquetaVertice,EtiquetaArco>::insertaArco(EtiquetaArco x,Vertice<EtiquetaVertice>* v,
                                                       Vertice<EtiquetaVertice>* w){
    arcos[(v->numVertice-1)*numVertices+w->numVertice-1]=new Arco<EtiquetaArco>(x);
}

template <class EtiquetaVertice,class EtiquetaArco>
EtiquetaArco Grafo<EtiquetaVertice,EtiquetaArco>::suprimeArco(const Vertice<EtiquetaVertice>& v,
                                                               const Vertice<EtiquetaVertice>& w){
    Arco<EtiquetaArco> arco=arcos[(v.numVertice-1)*numVertices+w.numVertice-1];
    EtiquetaArco etiqueta=arco->etiqueta;
    delete arco;
    arcos[(v.numVertice-1)*numVertices+w.numVertice-1]=ARCO_NULO;
    return etiqueta;
}

template <class EtiquetaVertice,class EtiquetaArco>
EtiquetaArco Grafo<EtiquetaVertice,EtiquetaArco>::etiquetaArco(Vertice<EtiquetaVertice>* v,
                                                               Vertice<EtiquetaVertice>* w){
    Arco<EtiquetaArco>* arco=arcos[(v->numVertice-1)*numVertices+w->numVertice-1];
    return arco?arco->etiqueta:ETIQUETA_ARCO_NULA;
}

template <class EtiquetaVertice,class EtiquetaArco>
EtiquetaVertice Grafo<EtiquetaVertice,EtiquetaArco>::etiquetaVertice(Vertice<EtiquetaVertice>& v){
    return v.dameEtiqueta();
}

template <class EtiquetaVertice,class EtiquetaArco>
tipo_indice Grafo<EtiquetaVertice,EtiquetaArco>::siguiente(Vertice<EtiquetaVertice>* v,
                                                           tipo_indice indice){
    for(indice++;indice<numVertices;indice++){
        if (arcos[(v->numVertice-1)*numVertices+indice]){
            return indice;
        }
    }
    return VERTICE_NULO;
}

template <class EtiquetaVertice,class EtiquetaArco>
tipo_indice Grafo<EtiquetaVertice,EtiquetaArco>::primero(Vertice<EtiquetaVertice>* v){
    //return siguiente(v,0);
    for(tipo_indice i=0;i<numVertices;i++){
        if (arcos[(v->numVertice-1)*numVertices+i]){
            return i;
        }
    }
    return VERTICE_NULO;
}

template <class EtiquetaVertice,class EtiquetaArco>
Vertice<EtiquetaVertice>* Grafo<EtiquetaVertice,EtiquetaArco>::dameVertice(
    Vertice<EtiquetaVertice>* v,tipo_indice indice){
    return &(vertices[indice]);
}

template <class EtiquetaVertice,class EtiquetaArco>
Grafo<EtiquetaVertice,EtiquetaArco>::~Grafo(){
    Arco<EtiquetaArco>* arco;
    int i,j;
    cout << "destruyendo grafo..." << endl;
    cout << "destruyendo vertices..." << endl;
    delete[] vertices;
    cout << "destruyendo arcos..." << endl;
    for(i=0;i<numVertices;i++){
        for(j=0;j<numVertices;j++){
            if ((arco=arcos[i*numVertices+j])){
                delete arco;
            }
        }
    }
    delete[] arcos;
    cout << "grafo destruido" << endl;
}

#endif // OPERACIONES_DE_COLAS_H_INCLUDED
