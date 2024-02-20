#include <iostream>
#include <fstream>
using namespace std;
class indice{
    public:
        char Rfc[13];
        long int Ref;
};
class cliente{
    public:
    indice aux;
    string Nombre;
    string Dom;
    void alta(){
        cout<<"Ingresa el Nombre: ";
        getline(cin,Nombre);
        cout<<"Ingresa el Rfc: ";
        cin.getline(aux.Rfc,13);
        cout<<"Ingrese el domicilio: ";
        getline(cin,Dom);
        ofstream Archivo("Datos.txt",ios::app);
        Archivo<<Nombre<<'|'<<aux.Rfc<<'|'<<Dom<<'|';
        Archivo.close();
    }
    void menu(){
        char opc;
        cout<<'\t'<<"Menu"<<endl;
        cout<<"1....................... Alta cliente"<<endl;
        cout<<"2....................... Mostrar clientes"<<endl;
        cout<<"3....................... Mostrar indices"<<endl;
        cout<<"4....................... Salir"<<endl;
        do{
            cout<<"* Escribe la opcion que deseas realizar:";
            cin>>opc;
            cout<<'\n';
            cin.ignore(10000,'\n');
            switch (opc){
                case '1':
                    alta();
                    break;
                case '2':
                    break;
                case '3':
                    break;
                case '4':
                    break;
                default:
                    cout<<"Opcion incorrecta"<<endl;
            }
        }while(opc!='4');
    }
};
int main()
{
    cliente z;
    z.menu();
    return 0;
}
