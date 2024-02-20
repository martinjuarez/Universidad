#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#define milisegundo 0.001

using namespace std;

int main()
{
    int temp,tam_arreglo;
    int arreglo[500000],a,j,x;
    long double tiempo,promedio;

    clock_t comienzo,fin;

    mt19937 mt(time(0));
    uniform_int_distribution<int> dist(0,50000);

    for (j=0; j<10; j++)
    {
        system("cls");
        promedio=0;
        for (x=0; x<5; x++)
        {
            if (j==0)
                tam_arreglo=100;
            else if(j==1)
                tam_arreglo=500;
            else if(j==2)
                tam_arreglo=1000;
            else if(j==3)
                tam_arreglo=2000;
            else if(j==4)
                tam_arreglo=3000;
            else if(j==5)
                tam_arreglo=5000;
            else if(j==6)
                tam_arreglo=10000;
            else if(j==7)
                tam_arreglo=15000;
            else if(j==8)
                tam_arreglo=20000;
            else
                tam_arreglo=30000;
            for(a=0; a<tam_arreglo; a++)
            {
                arreglo[a]=dist(mt);
            }

            cout<<endl<<"ordenando "<<tam_arreglo<<" elementos..."<<endl;
            cout<<"Prueba #"<<x+1<<endl;
            comienzo=clock();

            ///         Insercion
            int i,j;
            for(i=1;i<tam_arreglo;i++){
                temp = arreglo[i];
                j=i-1;
                while((arreglo[j]>temp)&&(j>=0)){
                    arreglo[j+1]=arreglo[j];
                    j--;
                }
                arreglo[j+1]=temp;
            }
            ///

            fin=clock();

            tiempo=(fin-comienzo)*milisegundo;
            cout<<endl<<"Tiempo de ordenacion: "<<tiempo<<" segundos"<<endl;
            promedio=promedio+tiempo;
        }
        cout<<"promedio en "<<tam_arreglo<<" elementos: "<<promedio/(x+1)<<endl;
        system("pause");
    }

    return 0;
}
