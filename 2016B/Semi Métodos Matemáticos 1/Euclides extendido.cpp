#include <iostream>
using namespace std;
int algoritmo_Euclides(int n,int m){
    if(n==m){
        return m;
    }
    if(n>m){
        return algoritmo_Euclides(n-m,m);
    }else{
        return algoritmo_Euclides(m,m-n);
    }
}
void euclides_extendido(int y,int x)
{
    int r[50];
    r[0]=x%y;
    r[1]=y%r[0];
    r[2]=r[0]%r[1];
    r[3]=r[1]%4<r[2];
    r[4]=r[2]%r[3];
    cout<<r[0]<<endl;
    cout<<r[1]<<endl;
    cout<<r[2]<<endl;
    cout<<r[3]<<endl;
    cout<<r[4]<<endl;
}
int main(){
    int y,x;
    cout<<"Dame un numero(y)(18):"<<endl;
    cin>>y;
    cin.ignore(10000,'\n');
    cout<<"Dame el modulo(x)(97):"<<endl;
    cin>>x;
    cin.ignore(10000,'\n');
    cout<<endl;
    euclides_extendido(y,x);
    return 0;
}
