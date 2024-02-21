// Guzmán Mendoza Oscar Eduardo
#include <bits/stdc++.h>
using namespace std;

// Denominaciones de monedas en pesos Mexicanos
int denominacion[] = {1, 2, 5, 10, 20, 50};
int n = sizeof(denominacion)/sizeof(denominacion[0]);

void minimo(int V)
{
    // Inicializar resultado
    vector<int> respuesta;

    // Recorrido de la denominación
    for (int i=n-1; i>=0; i--)
    {
        // Encontrando las denominaciones
        while (V >= denominacion[i])
        {
           V -= denominacion[i];
           respuesta.push_back(denominacion[i]);
        }
    }

    // Imprimir resultado
    for (int i = 0; i < respuesta.size(); i++)
           cout << respuesta[i] << "  ";
}

// Pos el mein ¿Qué más?
int main()
{
   int n = 197;
   cout << "El cambio minimo de la cantidad " << n << " es de ";
   minimo(n);
   return 0;
}
