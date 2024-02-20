#include <iostream>
using namespace std;
class Cuadrado{
    public:
        int lado;
        void area_cuadrado(){
            int area;
            cout<<"Ingresar la medida de los lados:"<<endl;
            cin>>lado;
            cin.ignore(10000,'\n');
            area = lado^2;
            cout<<"El area es:"<<'\n'<<area<<endl;
        }
};
class Triangulo{
    public:
        int base,altura;
        void area_triangulo(){
            int area;
            cout<<"Ingresar la base:"<<endl;
            cin>>base;
            cin.ignore(10000,'\n');
            cout<<"Ingresar la altura:"<<endl;
            cin>>altura;
            cin.ignore(10000,'\n');
            area = base * altura / 2;
            cout<<"El area es:"<<'\n'<<area<<endl;
        }
};
class Circulo{
    public:
        int radio;
        void area_circulo(){
            int area;
            cout<<"Ingresar el radio:"<<endl;
            cin>>radio;
            cin.ignore(10000,'\n');
            area = 3.1416 * radio;
            cout<<"El area es:"<<'\n'<<area<<endl;
        }
};
class Rectangulo{
    public:
        int base,altura;
        void area_rectangulo(){
            int area;
            cout<<"Ingresar la base:"<<endl;
            cin>>base;
            cin.ignore(10000,'\n');
            cout<<"Ingresar la altura:"<<endl;
            cin>>altura;
            cin.ignore(10000,'\n');
            area = base * altura;
            cout<<"El area es:"<<'\n'<<area<<endl;
        }
};
class Figuras{
    public:
        Cuadrado cuadrados[4];
        Triangulo triagulos[4];
        Circulo circulos[4];
        Rectangulo rectangulos[4];
        void menu(){
            int opc,ci,tr,cu,re;
            ci=0;
            tr=0;
            cu=0;
            re=0;
            do{
                cout<<"Menu"<<endl;
                cout<<"1...........Registrar un circulo"<<endl;
                cout<<"2...........Registrar un triangulo"<<endl;
                cout<<"3...........Registrar un cuadrado"<<endl;
                cout<<"4...........Registrar un rectangulo"<<endl;
                cout<<"0...........Salir"<<endl;
                cout<<"Por favor escriba el numero de opcion que desea realizar:";
                cin>>opc;
                cin.ignore(10000,'\n');
                switch(opc){
                    case 1:
                        if(ci<4){
                            circulos[ci].area_circulo();
                            ci++;
                        }else{
                            cout<<"Ya no hay mas espacio"<<endl;
                        }
                        break;
                    case 2:
                        if(tr<4){
                            triagulos[tr].area_triangulo();
                            tr++;
                        }else{
                            cout<<"Ya no hay mas espacio"<<endl;
                        }
                        break;
                    case 3:
                        if(cu<4){
                            cuadrados[cu].area_cuadrado();
                            cu++;
                        }else{
                            cout<<"Ya no hay mas espacio"<<endl;
                        }
                        break;
                    case 4:
                        if(re<4){
                           rectangulos[re].area_rectangulo();
                           re++;
                        }
                        break;
                    case 0:
                        break;
                    default:
                        cout<<"opcion incorrecta"<<endl;
                }
            }while(opc!=0);
        }
};
int main(){
    Figuras F;
    F.menu();
    return 0;
}
