#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include  <iostream>
using namespace std;

class Cancion{
    public:
        string nombre;
        string autor;
        string album;
        Cancion *sig;
        friend class musica;
};

class musica{
    public:
        Cancion *raiz = NULL;
        Cancion ** pos;
        int tam;
        void agregar_cancion(string nombre, string autor, string album);
        void ver_canciones();
        void buscar_canciones(string nombre);
        void eliminar_canciones(string nombre);
        void recuperar();
        void menu();
        void bubblesort();
};
#endif // LISTA_H_INCLUDED
