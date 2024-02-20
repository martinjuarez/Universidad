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
int main(){
    int n,m;
    cout<<"Dame a n:"<<endl;
    cin>>n;
    cin.ignore(10000,'\n');
    cout<<"Dame a m:"<<endl;
    cin>>m;
    cin.ignore(1000,'\n');
    cout<<"MCD:"<<algoritmo_Euclides(n,m)<<endl;
    return 0;
}
