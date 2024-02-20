#include <iostream>
using namespace std;
struct persona{
    int edad;
    float e;
    char i;
    int x,*y;
};
int main(){
    int x(5);
    cout<<"Valor x:"<<x<<endl;
    int *a;
    cout<<"Direccion de a:"<<&a<<endl;
    a= new int (6);
    cout<<*a<<endl;
    *a=10;
    cout<<*a<<endl;
    delete a;
    cout<<"Direccion de a:"<<&a<<endl;
    a= NULL;
    cout<<"Valor de a:"<<a<<endl;
    cout<<"Direccion de a:"<<&a<<endl;


    /*persona x,*y,**z;
    y=&x;
    z=&y;
    cout<<"Direccion x:"<<&x<<endl;
    cout<<"Direccion y:"<<&y<<endl;
    cout<<"Direccion z:"<<&z<<endl;
    cout<<"Valor y:"<<y<<endl;
    cout<<"Valor z:"<<z<<endl;
    x.edad=25;
    x.e=1.75;
    x.i='e';
    cout<<"Edad:"<<x.edad<<endl;
    cout<<"Estatura:"<<x.e<<endl;
    cout<<"Idioma:"<<x.i<<endl;
    y->edad=15;
    y->e=1.80;
    y->i='i';
    cout<<"Edad:"<<y->edad<<endl;
    cout<<"Estatura:"<<y->e<<endl;
    cout<<"Idioma:"<<y->i<<endl;
    (*z)->edad=13;
    cout<<"Edad:"<<(*z)->edad<<endl;
    cout<<"Valor de la edad desde x:"<<x.edad<<endl;
    */
    return 0;
}
