#include <iostream>
#include <string.h>
#include "util.h"
#include "Operaciones_de_Grafos.h"
//#include "Operaciones_de_Listas_Arreglos.h"
#include "Operaciones_de_Listas_Punteros.h"
#include "Tipos_y_Constantes.h"

#define NUM_VERTICES 5

template <class EtiquetaVertice,class EtiquetaArco>
void dijkstra(Grafo<EtiquetaVertice,EtiquetaArco>* grafo);

int main()
{
    Grafo<int,int>* grafo=new Grafo<int,int>(NUM_VERTICES);
    cout << "Insertando arcos en el grafo..." << endl;
    grafo->insertaArco(10,grafo->dameVertice(1),grafo->dameVertice(2));
    grafo->insertaArco(30,grafo->dameVertice(1),grafo->dameVertice(4));
    grafo->insertaArco(100,grafo->dameVertice(1),grafo->dameVertice(5));
    grafo->insertaArco(50,grafo->dameVertice(2),grafo->dameVertice(3));
    grafo->insertaArco(10,grafo->dameVertice(3),grafo->dameVertice(5));
    grafo->insertaArco(20,grafo->dameVertice(4),grafo->dameVertice(3));
    grafo->insertaArco(60,grafo->dameVertice(4),grafo->dameVertice(5));
    cout << "Ejecutando algoritmo de Dijkstra..." << endl;
    dijkstra(grafo);
    pausar();
    delete grafo;
    pausar();
    return 0;
}

template<class TipoElemento>
void Lista<TipoElemento>::imprimeLista(){
    posicion p,q;
    int cuentaLineas=0;
    cout << "Lista " << dameNombre() << endl;
    for(p=primero(),q=fin();p!=q;p=siguiente(p)){
        cout << recupera(p) << endl;
        cuentaLineas++;
        if (cuentaLineas%MAX_LINEAS_POR_PAGINA==0){
            pausar();
        }
    }
}

template<class TipoElemento>
bool Lista<TipoElemento>::mismo(TipoElemento x,TipoElemento y){
    return x==y;
}

template<class EtiquetaVertice,class EtiquetaArco>
Vertice<EtiquetaVertice>* encuentraVerticeMinimo(Lista<Vertice<EtiquetaVertice>*>& verticesFaltantes,
                                                 EtiquetaArco distancias[]){
    Vertice<EtiquetaVertice>* verticeMinimo,*verticePosible;
    EtiquetaArco distanciaMinima,distanciaPosible;
    posicion i,j;
    i=verticesFaltantes.primero();
    j=verticesFaltantes.fin();
    verticeMinimo=verticesFaltantes.recupera(i);
    distanciaMinima=distancias[verticeMinimo->numVertice-1];
    for(i=verticesFaltantes.siguiente(i);i!=j;i=verticesFaltantes.siguiente(i)){
        verticePosible=verticesFaltantes.recupera(i);
        distanciaPosible=distancias[verticePosible->numVertice-1];
        if ((distanciaMinima==ETIQUETA_NULA) ||
            (distanciaPosible!=ETIQUETA_NULA && distanciaPosible<distanciaMinima)){
            distanciaMinima=distanciaPosible;
            verticeMinimo=verticePosible;
        }
        //else seguir buscando
    }
    return verticeMinimo;
}

template<class EtiquetaVertice,class EtiquetaArco>
EtiquetaArco encuentraDistanciaMinima(Vertice<EtiquetaVertice>* v,Vertice<EtiquetaVertice>* w,
    EtiquetaArco distancias[],Grafo<EtiquetaVertice,EtiquetaArco>* grafo,int rutaCorta[]){
    EtiquetaArco dist1,dist2;
    if ((dist1=distancias[w->numVertice-1])!=ETIQUETA_NULA){
        dist2=grafo->etiquetaArco(w,v);
        if (dist2==ETIQUETA_NULA){
            dist1=ETIQUETA_NULA;  //distancia combinada es infinita
        }
        else{
            dist1+=dist2;
        }
    }
    if ((dist2=distancias[v->numVertice-1])!=ETIQUETA_NULA){
        if (dist1==ETIQUETA_NULA || dist2<dist1){
            dist1=dist2;
        }
        else{
            rutaCorta[v->numVertice]=w->numVertice;
        }
    }
    return dist1;
}

template<class EtiquetaVertice,class EtiquetaArco,class TipoElemento>
void imprimeDistancias(Lista<TipoElemento>& verticesVerificados,Vertice<EtiquetaVertice>* verticeInspeccionado,
                       EtiquetaArco distancias[]){
    posicion p,q;
    int i=0;
    cout << "\t\t{";
    for(p=verticesVerificados.primero(),q=verticesVerificados.anterior(verticesVerificados.fin());
    p!=q;p=verticesVerificados.siguiente(p)){
        cout << verticesVerificados.recupera(p)->numVertice << ",";
        i++;
    }
    cout << verticesVerificados.recupera(p)->numVertice << "}" ;
    for(;i<NUM_VERTICES;i++){
        cout << "  ";
    }
    if (verticeInspeccionado==VERTICE_NULO){
        cout << "\t-";
    }
    else cout << "\t" << verticeInspeccionado->numVertice;
    for(i=1;i<NUM_VERTICES;i++){
        if (distancias[i]==ETIQUETA_NULA){
            cout << "\tinf";
        }
        else{
            cout << "\t" << distancias[i];
        }
    }
    cout << endl;
}

void imprimeRutaCorta(int ruta[]){
    Lista<int> camino;
    int i,j;
    posicion p;

    cout << "Ruta mas corta hacia..." << endl;
    for(i=2;i<=NUM_VERTICES;i++){
        cout << i << ": ";
        for(j=i;j>1;){
            camino.inserta(ruta[j],camino.primero());
            j=ruta[j];
        }
        while(!camino.estaVacia()){
            p=camino.primero();
            cout << camino.recupera(p) << ",";
            camino.suprime(p);
        }
        cout << i << endl;
    }
}

template<class EtiquetaVertice,class EtiquetaArco>
void dijkstra(Grafo<EtiquetaVertice,EtiquetaArco>* grafo){
    Lista<Vertice<EtiquetaVertice>*> verticesPorVerificar,verticesVerificados;
    Vertice<EtiquetaVertice> *verticeInspeccionado,*v;
    int rutaCorta[NUM_VERTICES+1];
    EtiquetaArco distancias[NUM_VERTICES];
    posicion p,q;
    tipo_indice i;



    verticeInspeccionado=grafo->dameVertice(1);
    verticesVerificados.inserta(verticeInspeccionado,verticesVerificados.fin());
    for(i=2;i<=NUM_VERTICES;i++){
        v=grafo->dameVertice(i);
        distancias[i-1]=grafo->etiquetaArco(verticeInspeccionado,v);
        verticesPorVerificar.inserta(v,verticesPorVerificar.fin());
        rutaCorta[i]=verticeInspeccionado->numVertice;
    }
    cout << "Iteracion\tS\t\tw";
    for(i=2;i<=NUM_VERTICES;i++){
        cout << "\tD[" << i << "]";
    }
    cout << endl << "inicial";
    verticeInspeccionado=VERTICE_NULO;
    imprimeDistancias(verticesVerificados,verticeInspeccionado,distancias);
    for(i=1;i<NUM_VERTICES;i++){
        verticeInspeccionado=encuentraVerticeMinimo(verticesPorVerificar,distancias);
        verticesVerificados.inserta(verticeInspeccionado,verticesVerificados.fin());
        verticesPorVerificar.suprime(verticesPorVerificar.localiza(verticeInspeccionado));
        for(p=verticesPorVerificar.primero(),q=verticesPorVerificar.fin();p!=q;
        p=verticesPorVerificar.siguiente(p)){
            v=verticesPorVerificar.recupera(p);
            distancias[v->numVertice-1]=encuentraDistanciaMinima(v,verticeInspeccionado,distancias,grafo,
                                                   rutaCorta);
        }
        cout << i;
        imprimeDistancias(verticesVerificados,verticeInspeccionado,distancias);
    }
    imprimeRutaCorta(rutaCorta);
}
