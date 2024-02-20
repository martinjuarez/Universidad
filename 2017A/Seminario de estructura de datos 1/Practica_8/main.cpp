#include <iostream>
using namespace std;
#define Max 8
class grafo{
public:
    char vertices[Max];
    int matriz[Max][Max];
    int cont=0;
    grafo()
    {
        int a=0,b;
        while(a<Max)
        {
            b=0;
            while(b<Max)
            {
                matriz[a][b]=0;
                b++;
            }
            a++;
        }
    }
    void ingresar_vertice()
    {
        if(cont<Max)
        {
            cout<<"Ingresa el nombre del vertice:";
            cin>>vertices[cont];
            cin.ignore(10000,'\n');
            cout<<endl;
            cont++;
        }
        else
        {
            cout<<"El grafo esta lleno"<<endl;
            cout<<endl;
        }
    }
    int buscar(char a)
    {
        int c=0;
        int r;
        bool flag=false;
        while(c<cont)
        {
            if(vertices[c]==a)
            {
                flag=true;
                r=c;
            }
            c++;
        }
        if(flag==false)
        {
            return 9;
        }
        else
        {
            return r;
        }

    }
    void ingresar_aristas()
    {

        char temp;
        char temp2;
        int c;
        string opc;
        cout<<"Ingresa el nombre del vertice que sera el origen:";
        cin>>temp;
        cin.ignore(10000,'\n');
        if(buscar(temp)!=9)
        { 
            cout<<"Ingresa el nombre del vertice que sera el destino:";
            cin>>temp2;
            cin.ignore(10000,'\n');
            if(buscar(temp2)!=9)
            {
                cout<<"Ingresa el costo:";
                cin>>c;
                cin.ignore(10000,'\n');
                matriz[buscar(temp)][buscar(temp2)]=c;
            }
            else
            {
                cout<<"El vertice no existe"<<endl;
                do{
                    cout<<"1.............Crear un vertice nuevo"<<endl;
                    cout<<"2.............Salir de la opcion"<<endl;
                    cout<<"Ingresa una opcion:";
                    getline(cin,opc);
                    if(opc=="1")
                    {
                        ingresar_vertice();
                        ingresar_aristas();
                    }
                    else if(opc=="2")
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Error escriba de nuevo"<<endl;
                    }
                }while(opc!="2");
            }
        }
        else
        {
            cout<<"El vertice no existe"<<endl;
            do{
                cout<<"1.............Crear un vertice nuevo"<<endl;
                cout<<"2.............Salir de la opcion"<<endl;
                cout<<"Ingresa una opcion:";
                getline(cin,opc);
                if(opc=="1")
                {
                    ingresar_vertice();
                    ingresar_aristas();
                }
                else if(opc=="2")
                {
                    break;
                }
                else
                {
                    cout<<"Error escriba de nuevo"<<endl;
                }
            }while(opc!="2");
        }
        cout<<endl;
    }
    void mostrar_vertice()
    {
        int a=0;
        while(a<cont)
        {
            cout<<"Vertice "<<a<<":"<<vertices[a]<<endl;
            a++;
        }
    }
    void matriz_adyacencia()
    {
        int a=0,b;
        while(a<cont)
        {
            cout<<"  "<<vertices[a];
            a++;
        }
        cout<<endl;
        a=0;
        while(a<cont)
        {
            cout<<vertices[a];
            b=0;
            while(b<cont)
            {
                cout<<" "<<matriz[a][b]<<" ";
                b++;
            }
            cout<<endl;
            a++;
        }
        cout<<endl;
    }

    void menu(){
        grafo();
        string opc;
        cout<<'\t'<<"Menu"<<endl;
        cout<<"1....................... Ingresar Vertice"<<endl;
        cout<<"2....................... Ingresar Arista"<<endl;
        cout<<"3....................... Imprimir matriz adyacencia"<<endl;
        cout<<"4....................... Recorrido de anchura"<<endl;
        cout<<"5....................... Recorrido de profundidad"<<endl;
        cout<<"6....................... Salir"<<endl;
        do{
            cout<<"* Escribe la opcion que deseas realizar:";
            getline(cin,opc);
            cout<<'\n';
            if(opc=="1")
            {
                ingresar_vertice();
            }
            else if(opc=="2")
            {
                ingresar_aristas();
            }
            else if(opc=="3")
            {
                matriz_adyacencia();
            }
            else if(opc=="4")
            {
                mostrar_vertice();
            }
            else if(opc=="5")
            {
                break;
            }
            else if(opc=="6")
            {
                break;
            }
            else
            {
                cout<<"Opcion incorrecta"<<endl;
                cout<<endl;
            }
       }while(opc!="6");
    }
};
int main()
{
    grafo A;
    A.menu();
    return 0;
}
