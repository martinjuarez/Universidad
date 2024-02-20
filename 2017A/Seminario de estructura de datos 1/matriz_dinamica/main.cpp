#include <iostream>
#include <iomanip>
#include "arreglo.h"
using namespace std;

class Persona
{
public:
    int id;
    string nombre;

    friend ostream& operator <<(ostream &salida,Persona &p)
    {
        salida << p.id;
        return salida;
    }
};

int main(int argc, char *argv[])
{
 /*   arreglo<int> fila(4,0);

    arreglo< arreglo<int> > matriz(4, fila);

//    cout << matriz;

    int i = 0;
    for(unsigned int f = 0;
        f < fila.tamano(); f++)
    {
        for(unsigned int col = 0;
            col < matriz[0].tamano(); col++)
        {
            matriz[f][col] = i++;
        }
    }

    for(unsigned int f = 0;
        f < fila.tamano(); f++)
    {
        for(unsigned int col = 0;
            col < matriz[0].tamano(); col++)
        {
            cout <<setw(5) << matriz[f][col];
        }
        cout<<endl;
    }

//    cout << matriz;
*/
 /*   arreglo<Persona> p(4, Persona() );
    arreglo< arreglo<Persona> > m(6, p);
    int i = 10;
    for(unsigned int fila = 0;
        fila < m.tamano(); fila++)
    {
        for(unsigned int col = 0;
            col < m[0].tamano(); col++)
        {
            m[fila][col].id = i++;
        }
    }
    for(unsigned int fila = 0;
        fila < m.tamano(); fila++)
    {
        for(unsigned int col = 0;
            col < m[0].tamano(); col++)
        {
            cout << setw(5) << m[fila][col];
        }
        cout << endl;
    }
*/

    arreglo<Persona*> p(4, NULL);
    arreglo< arreglo<Persona*> > m(5, p);
    int i = 0;
    for(unsigned int fila = 0;
        fila < m.tamano(); fila++)
    {
        for(unsigned int col = 0;
            col < m[0].tamano(); col++)
        {
            Persona *temp = new Persona;
            temp->id = i++;
            m[fila][col] = temp;
        }
    }

    for(unsigned int fila = 0;
        fila < m.tamano(); fila++)
    {
        for(unsigned int col = 0;
            col < m[0].tamano(); col++)
        {
            cout << setw(5) << *m[fila][col];
        }
        cout << endl;
    }

    return 0;
}
