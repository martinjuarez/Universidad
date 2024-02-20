#include <iostream>
#include <fstream>
using namespace std;
struct Paqueteria{
    char fecha_rec[11];
    char fech_lim[11];
    char cod_suc[11];
    char cod_cli[11];
    char cod_emp[11];
    int folio;
};
void ingresar(Paqueteria A){
    int codigo
    ofstream escribir("Archivo.txt",ios::app);
    cout<<"Fecha de recepcion(DD/MM/AAAA):";
    cin.getline(A.fecha_rec,11);
    cout<<"Fecha limite de entrega(DD/MM/AAAA):";
    cin.getline(A.fech_lim,11);
    cout<<"Codigo de sucursal:";
    cin.getline(A.cod_suc,11);
    cout<<"Codigo de cliente:";
    cin.getline(A.cod_cli,11);
    cout<<"Codigo de empleado:";
    cin.getline(A.cod_emp,11);
    escribir.seekp(0,escribir.end);
    A.folio=escribir.tellp();
    if(A.folio ==0){
       A.folio=1;
    }else{
        A.folio=(A.folio/sizeof(A))+1;
    }
    escribir.write((char*)&A,sizeof(A));
    escribir.close();
    cout<<'\n';
}
int main()
{
    Paqueteria Express;
    char opc;
    cout<<'\t'<<"Menu"<<endl;
    cout<<"1....................... Ingresar"<<endl;
    cout<<"2....................... Mostrar"<<endl;
    cout<<"3....................... Salir"<<endl;
    do{
            cout<<"* Escribe la opcion que deseas realizar:";
            cin>>opc;
            cout<<'\n';
            cin.ignore(10000,'\n');
            switch (opc){
                case '1':
                    ingresar(Express);
                    break;
                case '2':
                    break;
                case '3':
                    break;
                default:
                    cout<<"Opcion incorrecta"<<endl;
            }
    }while(opc!='3');
    return 0;
}
