#include <iostream>
using namespace std;
class Pila{
    public:
        int arreglo[10],top;
        void push(int dato){
            arreglo[top]=dato;
            top++;
        }
        int pop(){
            top--;
            return arreglo[top];
        }
        int peek(){
            return arreglo[top-1];
        }
        pila(){
            top=0;
        }
};
int main(){
    Pila p;
    int opc
    switch(opc)
    return 0;
}
