#ifndef ARREGLO_H
#define ARREGLO_H
#include <iostream>
#include <stdexcept>
using namespace std;
template <class T>
class arreglo
{
public:
    arreglo();
    arreglo(unsigned int n);
    arreglo(unsigned int n, T relleno);
    arreglo(arreglo<T> &a);
    ~arreglo();
    unsigned int capacidad();
    unsigned int tamano();
    void expandir(unsigned int n);
    void insertar_ultimo(const T &dato);
    void insertar(unsigned int p, T &dato);
    void eliminar_ultimo();
    void eliminar(unsigned int p);

    T& pos(unsigned int p);
    T& operator[](unsigned int p){
        return pos(p);
    }


    friend ostream &operator <<(ostream &salida,
                               arreglo<T> &a){
        for(unsigned int i = 0; i < a.num_elem; i++)
            salida << a.data[i] << endl;
        return salida;
    }
    void operator=(arreglo<T> &a)
    {
        this->expandir(2*a.capacidad());
        this->num_elem = a.tamano();

        for(unsigned int i = 0; i < num_elem; i++)
            this->data[i] = a[i];
    }

private:
    unsigned int capacidad_inicial = 10;
    unsigned int capacidad_actual;
    unsigned int num_elem;
    T *data;
};
template <class T>
arreglo<T>::arreglo()
{
    data = new T[capacidad_inicial];
    capacidad_actual = capacidad_inicial;
    num_elem = 0;
}
template<class T>
arreglo<T>::arreglo(unsigned int n)
{
    data = new T[n];
    capacidad_actual = n;
    num_elem = 0;
}
template<class T>
arreglo<T>::arreglo(unsigned int n, T relleno)
{
    data = new T[n];
    capacidad_actual = n;
    num_elem = n;
    for(unsigned int i = 0; i < capacidad_actual; i++)
    {
        data[i] = relleno;
    }
}

template<class T>
unsigned int arreglo<T>::capacidad()
{
    return capacidad_actual;
}
template<class T>
unsigned int arreglo<T>::tamano()
{
    return num_elem;
}
template<class T>
T &arreglo<T>::pos(unsigned int p)
{
    if(p < 0 || p >= num_elem)
        throw out_of_range("la posicion no existe");
    return data[p];
}
template<class T>
void arreglo<T>::expandir(unsigned int n)
{
    if(n < capacidad_actual)
        throw runtime_error("Imposible encoger");
    T *temp = new T[n];
    for(unsigned int i = 0; i < num_elem; i++)
        temp[i] = data[i];
    delete[] data;
    data = temp;
    capacidad_actual = n;
}
template<class T>
void arreglo<T>::insertar_ultimo(const T &dato)
{
    if(num_elem == capacidad_actual)
        expandir(2*capacidad_actual);
    data[num_elem] = dato;
    num_elem++;
}
template<class T>
void arreglo<T>::insertar(unsigned int p, T &dato)
{
    if(num_elem == capacidad_actual)
        expandir(2*capacidad_actual);
    pos(p);
    if(p > num_elem)
        throw out_of_range("La casilla esta vacia, no puedes agregar por posicion");
    else
    {
        int aux=num_elem;
        while(p < aux){
            data[aux]= data[aux-1];
            aux--;
        }
        data[p]= dato;
        num_elem++;
    }
}
template<class T>
void arreglo<T>::eliminar_ultimo()
{
    if(num_elem==0)
        throw out_of_range("No existen elementos");
    else{
        num_elem--;
    }
}
template<class T>
void arreglo<T>::eliminar(unsigned int p)
{
    if(p < 0 || p >= num_elem)
        throw out_of_range("La posicion no existe");
    else{
        for(unsigned int i = p; i < num_elem; i++)
            data[i] = data[i+1];
        num_elem--;
    }
}
template<class T>
arreglo<T>::arreglo(arreglo<T> &a):
    capacidad_actual(a.capacidad()),
    num_elem(a.tamano()),
    data(new T[capacidad_actual])
{
    for(unsigned int i = 0; i < num_elem; i++)
    {
        data[i] = a[i];
    }
}

template<class T>
arreglo<T>::~arreglo()
{
    delete[] data;
}
#endif // ARREGLO_H
