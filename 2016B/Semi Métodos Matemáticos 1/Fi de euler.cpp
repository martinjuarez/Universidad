#include <iostream>
using namespace std;
int* primos;

int phi_euler()
{
   primos[2] = primos[23]=1;
   return 0;
}

int main()
{
   primos = (int*)malloc((1000000)*sizeof(int)); // antes de cualquier operacion que use primos
   // ..
   primos[2] = primos[23]=1;
   free((void*)primos); // cuando no se va a usar mas y antes de salir
   return 0;
}
