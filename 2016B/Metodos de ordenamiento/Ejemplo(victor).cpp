#include <iostream>
#include <ctime>
#include <random>
#define milisegundo 0.001

using namespace std;

int main()
{
    int temp;
    int a;
    int b;
    int arreglo[500000];
    double tiempo;
    mt19937 mt(time(0));
    uniform_int_distribution<int> dist(0,1000);
    clock_t comienzo,fin;

    for(a=0,b=10000;a<10000;a++,b--)
    {
        arreglo[a]=b;
        ///cout<<arreglo[a]<<", ";
    }

    cout<<endl<<"ordenando 10000 elementos..."<<endl;
    comienzo=clock();

    ///          burbuja
    for(int i=1; i<10000; i++)
    {
        for(int j=0; j<10000-i; j++)
        {
            if(arreglo[j]>arreglo[j+1])
            {
                temp=arreglo[j+1];
                arreglo[j+1]=arreglo[j];
                arreglo[j]=temp;
            }
        }
    }
    ///

    fin=clock();

    /**for (a=0; a<10000; a++)
        cout<<arreglo[a]<<", ";*/

    tiempo=(fin-comienzo)*milisegundo;
    cout<<endl<<"Tiempo de ordenacion: "<<tiempo<<" segundos"<<endl;

    return 0;
}
