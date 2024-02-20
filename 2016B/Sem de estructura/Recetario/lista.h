#ifndef LISTA_H
#define LISTA_H


class Nodo
{
 public:
    string Nombre_rec;
    float ingrediente;
    nodo *sig;
    nodo *ant;
    nodo()
    {
        sig=NULL;
        ant=NULL;
    }
};
class Lista{
public:
    nodo *Receta;
    void inicializar();
    void vacia();
    void insertar();
    void mostrar();
    void buscar();
};
