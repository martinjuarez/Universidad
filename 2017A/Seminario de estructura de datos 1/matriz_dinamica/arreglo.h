#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
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
    T &pos(unsigned int p);
    void insertar_ultimo(const T &dato);
    void expandir(unsigned int n);
    void eliminar_ultimo();
    void eliminar(unsigned int p);

    T &operator[](unsigned int p);
    friend ostream& operator <<(ostream &out,
                                arreglo<T> &a)
    {
        for(unsigned int i = 0; i < a.tamano(); i++){
            out << a[i] << endl;
        }
        return out;
    }

    void operator =(arreglo<T> &a){
        this->expandir(a.capacidad());
        this->num_elemetos = a.tamano();

        for(unsigned int i = 0; i < num_elemetos; i++)
            datos[i] = a[i];
    }

private:
    unsigned int capacidad_inicial = 10;
    unsigned int capacidad_actual;
    unsigned int num_elemetos;
    T *datos;
};
template <class T>
arreglo<T>::arreglo()
{
    datos = new T[capacidad_inicial];
    capacidad_actual = capacidad_inicial;
    num_elemetos = 0;
}

template<class T>
arreglo<T>::arreglo(unsigned int n)
{
    datos = new T[n];
    capacidad_actual = n;
    num_elemetos = 0;
}

template<class T>
arreglo<T>::arreglo(unsigned int n, T relleno)
{
    datos = new T[n];
    capacidad_actual = n;
    num_elemetos = n;
    for(unsigned int i = 0; i < capacidad_actual;
        i++)
    {
        datos[i] = relleno;
    }
}

template<class T>
arreglo<T>::arreglo(arreglo<T> &a):
    capacidad_actual(a.capacidad()),
    num_elemetos(a.tamano()),
    datos( new T[num_elemetos])
{
    for(unsigned int i = 0; i < num_elemetos; i++)
        datos[i] = a[i];
}

template<class T>
arreglo<T>::~arreglo()
{
    delete[] datos;
}

template<class T>
unsigned int arreglo<T>::capacidad()
{
    return capacidad_actual;
}

template<class T>
unsigned int arreglo<T>::tamano()
{
    return num_elemetos;
}

template<class T>
T &arreglo<T>::pos(unsigned int p)
{
    if(p < 0 || p >= num_elemetos)
    {
        throw out_of_range("la posicion no existe");
        throw out_of_range
    }
    return datos[p];
}

template<class T>
void arreglo<T>::insertar_ultimo(const T &dato)
{
    if(num_elemetos == capacidad_actual)
    {
        expandir(capacidad_actual*2);
    }
    datos[num_elemetos] = dato;
    num_elemetos++;
}

template<class T>
void arreglo<T>::expandir(unsigned int n)
{
    if(n > capacidad_actual)
    {
        capacidad_actual = n;

        T *temp = new T[n];
        for(unsigned int i = 0; i < num_elemetos;
            i++)
        {
            temp[i] = datos[i];
        }
        delete[] datos;
        datos = temp;
    }
}

template<class T>
void arreglo<T>::eliminar_ultimo()
{
    if(num_elemetos == 0)
        throw out_of_range("Arreglo Vacio");
    else num_elemetos--;

}

template<class T>
void arreglo<T>::eliminar(unsigned int p)
{
    if(p < 0 || p >= num_elemetos)
        throw out_of_range("Posicion no valida");
    else{
        for(unsigned int i = p; i < num_elemetos; i++)
            datos[i] = datos[i+1];
        num_elemetos--;
    }
}

template<class T>
T &arreglo<T>::operator[](unsigned int p)
{
    return pos(p);
}

#endif // ARREGLO_H
