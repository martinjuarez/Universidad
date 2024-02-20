#ifndef LISTA_H
#define LISTA_H
using namespace std;
class nodo{
    public:
        int dato;
        nodo *sig;
};
class lista
{
    public:
        nodo *h;
        void inicializar();
        void mostrar();
        void insertar(int e);
        void insertarFinal(int e);
        void buscar(int e);
        void eliminar(int e);
        void mostrarElemento(int e);
        void vacio();
        void anterior(int e);
        void siguiente(int e);
        void menu();
};

#endif // LISTA_H
