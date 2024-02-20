#include <iostream>
#include <fstream>
using namespace std;
class obra
{
    public:
    char nombre[35];
    char tipo[35];
    char autor[35];
    char etapa[35];
    void capturar()
    {
        cout<<"Dame el nombre de la obra:"<<endl;
        fflush(stdin);
        cin.getline(nombre,35);
        cout<<"Dame el tipo de la obra:"<<endl;
        cin.getline(tipo,35);
        cout<<"Dame el autor de la obra:"<<endl;
        cin.getline(autor,35);
        cout<<"Dame la etapa de la obra:"<<endl;
        cin.getline(etapa,35);
        ofstream Archivo("ObraSec.txt",ios::app);
        Archivo<<nombre<<'|'<<tipo<<'|'<<autor<<'|'<<etapa<<'|';
        Archivo.close();
    }
    void mostrar()
    {
        int i;
        ifstream Lectura("ObraSec.txt");
        if(!Lectura.good()){
            cout<<"No existe el archivo o ah sido movido"<<endl;
        }else{
            while(!Lectura.eof()){
            i=0;
            do{
            Lectura.read((char *)&nombre[i],1);
            if(Lectura.eof())break;
            i++;
            }while(nombre[i-1]!='|');
            nombre[i-1]='\0';
            if(Lectura.eof())break;
                ///
            i=0;
            do{
            Lectura.read((char *)&tipo[i],1);
            if(Lectura.eof())break;
            i++;
            }while(tipo[i-1]!='|');
            tipo[i-1]='\0';
            if(Lectura.eof())break;
                ///
            i=0;
            do{
            Lectura.read((char *)&autor[i],1);
            if(Lectura.eof())break;
            i++;
            }while(autor[i-1]!='|');
            autor[i-1]='\0';
            if(Lectura.eof())break;
                ///
            i=0;
            do{
            Lectura.read((char *)&etapa[i],1);
            if(Lectura.eof())break;
            i++;
            }while(etapa[i-1]!='|');
            etapa[i-1]='\0';
            if(Lectura.eof())break;
                ///
            cout<<endl<<"Nombre:"<<nombre<<endl<<"Tipo:"<<tipo<<endl<<"Autor:"<<autor<<endl<<"Etapa:"<<etapa<<endl;
            }
        }
        Lectura.close();
        cout<<endl;
    }
    int buscar()
    {
        int g;
        char b[35];
        ifstream Lectura("ObraSec.txt");
        if(!Lectura.good()){
            cout<<"No existe el archivo o ah sido movido"<<endl;
        }else{
            cout<<"Dame el nombre de la obra: ";
            cin.getline(b,35);
            g=0;
            while(g<35){
                if(b==nombre)
                    {
                        return 1;
                    }
                g++;
            }
        }
        Lectura.close();
        cout<<endl;
    }
    void menu()
    {
        int g;
        char opc;
        do{
            cout<<"1..........Ingresar"<<endl;
            cout<<"2..........Mostrar todo"<<endl;
            cout<<"3..........Buscar"<<endl;
            cout<<"4..........Salir"<<endl;
            cin>>opc;
            cin.ignore(10000,'\n');
            switch(opc)
            {
                case '1':
                    capturar();
                    break;
                case '2':
                    mostrar();
                    break;
                case '3':
                    if(buscar()){
                        cout<<"No se encontro el archivo"<<endl;
                    }else{
                        cout<<"Archivo encontrado"<<endl;
                    }
                    break;
                case '4':
                    break;
            }
        }while(opc!='4');
    }
};
int main()
{
    obra a;
    a.menu();
    return 0;
}
