#include <iostream>
using namespace std;
struct receta{
    string ing,pro,nom;
    float tp;
    int *ant, *sig;
};
int main(){
    /* int *y;
    int x[5];
    y=&x[0];
    cout<<"valor de x:"<<endl;
    cin>>x[1];
    cout<<y<<endl;
    return 0;
    */
    /*
    int *x,y;
    x=&y;
    y=5;
    cout<<"Direccion de y:"<<x<<endl;
    cout<<"Direccion de x:"<<&x<<endl;
    cout<<"Valor de y:"<<y<<endl;
    cout<<"Valor de y desde x:"<<*x<<endl;
    */
    receta x,*y;
    y->sig=new int;
    *y->sig=30;
    cout<<"Tiempo de preparacion:"<<*y->sig<<endl;
    /*
    int x(5);
    cout<<"valor x:"<<x<<endl;
    int *a;
    cout<<"direccion de a"<<&a<<endl;
    a= new int (6);
    cout<<*a<<endl;
    *a=10;
    cout<<*a<<endl;
    delete a;
    a= NULL;
    cout<<"valor de a:"<<a<<endl;
    cout<<"Direccion de a:"<<&a<<endl;
    */
}
