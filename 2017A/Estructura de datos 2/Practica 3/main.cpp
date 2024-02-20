#include <iostream>
#include <fstream>
using namespace std;
class Bebida{
    public:
        char nombre[30];
        char tipo[30];
        char region[30];
        Bebida *sig;
        friend class Catalogo;
};
class Catalogo{
    public:
        Bebida *B=NULL;
        void insertar(){
            Bebida *tmp=new Bebida;
            tmp->sig=NULL;
            cout<<"Nombre:";
            fflush(stdin);
            cin.getline(tmp->nombre,30);
            cout<<"Tipo:";
            cin.getline(tmp->tipo,30);
            cout<<"Region:";
            cin.getline(tmp->region,30);
            if(B==NULL){
                B=tmp;
            }else{
                tmp->sig=B;
                B=tmp;
            }
        }
        void mostrar(){
            Bebida *aux;
            aux=B;
            if(aux==NULL){
                cout<<"Error lista vacia"<<endl;
            }else{
                cout<<"Catalogo:"<<endl;
                while(aux!=NULL){
                    cout<<"Nombre:"<<aux->nombre<<endl;
                    cout<<"Tipo:"<<aux->tipo<<endl;
                    cout<<"Region:"<<aux->region<<endl;
                    aux=aux->sig;
                }
            }
        }
        void guardar(){
            Bebida *aux;
            aux=B;
            int a,b,c;
            a=strlen(aux->nombre);
            b=strlen(aux->tipo);
            c=strlen(aux->region);
            ofstream escribir("Catalogo.txt",ios::app);
            while(aux!=NULL){
                escribir.write(aux->nombre,sizeof(aux->nombre));
                escribir.write(aux->tipo,sizeof(aux->tipo));
                escribir.write(aux->region,sizeof(aux->region));
                aux=aux->sig;
            }
            escribir.close();
            cout<<"Guardado Exitoso"<<endl;
        }
        void menu(){
            char opc;
            cout<<'\t'<<"Menu"<<endl;
            cout<<"1....................... Ingresar"<<endl;
            cout<<"2....................... Mostrar"<<endl;
            cout<<"3....................... Cargar de disco"<<endl;
            cout<<"4....................... Guardar en disco"<<endl;
            cout<<"5....................... Salir"<<endl;
            do{
                cout<<"* Escribe la opcion que deseas realizar:";
                cin>>opc;
                cout<<'\n';
                cin.ignore(10000,'\n');
                switch (opc){
                    case '1':
                        insertar();
                        break;
                    case '2':
                        mostrar();
                        break;
                    case '3':
                        break;
                    case '4':
                        guardar();
                        break;
                    case '5':
                        break;
                    default:
                        cout<<"Opcion incorrecta"<<endl;
                }
            }while(opc!='5');
        }
};
int main()
{
    Catalogo A;
    A.menu();
    return 0;
}
