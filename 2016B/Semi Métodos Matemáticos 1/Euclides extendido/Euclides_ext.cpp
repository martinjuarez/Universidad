#include <iostream>
using namespace std;
void euclides_ext(int a, int b, int *c, int *d, int *e){
    int f=0,g=0;
    if (b==0){
        *c= a;
        *d= 1;
        *e= 0;
    }else{
        euclides_ext(b,a%b,c,d,e);
        f= *d;
        g= *e;
        *d= g;
        *e= f - (a/b)*g;
    }
}
int main()
{
    int a,b,c,d,e;
    cout<<"X: ";
    cin>>a;
    cout<<"Y: ";
    cin>>b;
    euclides_ext(a,b,&c,&d,&e);
    cout<<"mcd = "<<c<<endl;
return 0;
}
