#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
int main()
{
    char opc;
    do{
        cout<<".....:::::Esqueleto:::::......"<<endl;
        cout<<"1.-Extraer de un archivo"<<endl;
        cout<<"2.-Extraer en tiempo real"<<endl;
        cout<<"3.-Salir del programa"<<endl;
        cout<<"Que opcion deseas tomar: "<<endl;
        cin>>opc;
        switch(opc)
        {
            case '1':
                cout<<"En desarrollo"<<endl;
                break;
            case '2':
                cout<<"En desarrollo"<<endl;
                break;
            case '3':
                cout<<"Fin del programa"<<endl;
                break;
            default:
                cout<<"Error"<<endl;
                break;
        }
    }while(opc != '3');
    return 0;
}
