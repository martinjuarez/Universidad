#include <iostream>
using namespace std;
void triangulo(int *x,int *y)
{
    int respuesta;
    respuesta= *x * *y/2;
    cout<<"El area es:"<<respuesta<<endl;
}
void circulo(int *z)
{
    int respuesta;
    float pi= 3.1416;
    respuesta= pi * (*z * *z);
    cout<<"El area es:"<<respuesta<<endl;
}
void cuadrado(int *w)
{
    float respuesta;
    respuesta= *w * *w;
    cout<<"El area es:"<<respuesta<<endl;
}
int main()
{
    int a,b,r,l;
    string op;


    while(true){
        cout<<"1)............Triangulo"<<endl;
        cout<<"2)............Circulo"<<endl;
        cout<<"3)............Cuadrado"<<endl;
        cout<<"4)............Salir"<<endl;
        getline(cin,op);
        if(op=="1")
        {
            cout<<"Triangulo"<<endl;
            cout<<"Dame la altura:";
            cin>>a;
            cin.ignore(10000,'\n');
            cout<<"Dame la base:";
            cin>>b;
            cin.ignore(10000,'\n');
            triangulo(&a,&b);
            cout<<"Oprime enter para continuar..."<<endl;
            cin.ignore(10000,'\n');
        }
        else if(op=="2")
        {
            cout<<"Circulo"<<endl;
            cout<<"Dame el radio:";
            cin>>r;
            cin.ignore(10000,'\n');
            circulo(&r);
            cout<<"Oprime enter para continuar..."<<endl;
            cin.ignore(10000,'\n');
        }
        else if(op=="3")
        {
            cout<<"Cuadrado"<<endl;
            cout<<"Dame el lado:";
            cin>>l;
            cin.ignore(10000,'\n');
            cuadrado(&l);
            cout<<"Oprime enter para continuar..."<<endl;
            cin.ignore(10000,'\n');
        }
        else if(op=="4")
        {
            break;
        }
    }
    return 0;
}
