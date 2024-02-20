#include <iostream>
using namespace std;

int suma(int *x, int *b)
{
    return *x + *b;
}
void suma(int *x, int *b,int *res)
{
    *res= *x + *b;
}

int main()
{

    int a=10;
    int *b=&a;

    cout<<&a<<" "<<*b<<endl;

    b = new int;
    *b= 20;

    cout<< b <<" "<< *b << endl;

    cout<< suma(&a, b)<<endl;

    int r;
    suma(&a, b, &r);
    cout<< r <<endl;

    return 0;
}
