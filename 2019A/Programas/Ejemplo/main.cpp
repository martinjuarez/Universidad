#include <iostream>
using namespace std;

int main(){
    string a, b, c = "Martin", d = "Lentes";
    int con = 0;
    cout<<"Usuario: ";
    getline(cin,a);
    cout<<endl;
    cout<<"Contraseña: ";
    getline(cin,b);
    cout<<endl;
    con++;
    while(a != c || b != d){
        if(con == 3){
            cout<<"Fallaste adios"<<endl;
            break;
        }
        cout<<"Campos erroneos"<<endl;
        cout<<endl;
        cout<<"Usuario: ";
        getline(cin,a);
        cout<<endl;
        cout<<"Contraseña: ";
        getline(cin,b);
        cout<<endl;
        con++;
    }
    if(a == c && b == d){
        cout<<"Bienvenido"<<endl;
    }
    return 0;
}
