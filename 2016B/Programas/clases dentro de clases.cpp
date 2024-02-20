#include <iostream>
using namespace std;
class dimension_1{
    public:
        int a;
        void saludar(){
            cout<<"Hola has entrado a una dimesion"<<endl;
        }
        class dimension_2{
            public:
                int b;
                void alentar(){
                    cout<<"Has entrado a otra dimension"<<endl;
                }
                class dimension_3{
                    public:
                        int c;
                        void nivel_3(){
                            cout<<"Estas en el nivel 3"<<endl;
                        }
                        class dimension_4{
                            public:
                                int d;
                                void desalentar(){
                                    cout<<"Desde este punto ya no hay regreso"<<endl;
                                }
                                class dimension_5{
                                    public:
                                        int e;
                                        void nivel_5(){
                                            cout<<"Estas en el nivel 5"<<endl;
                                        }
                                        class dimension_6{
                                            public:
                                                int f;
                                                void mitad(){
                                                    cout<<"Llevas un poco mas de la mitad"<<endl;
                                                }
                                                class dimension_7{
                                                    public:
                                                        int g;
                                                        void ya_casi(){
                                                            cout<<"Ya casi se acaba tu tormento"<<endl;
                                                        }
                                                        class dimension_8{
                                                            public:
                                                                int h;
                                                                void nivel_8(){
                                                                    cout<<"Estas en el nivel 8"<<endl;
                                                                }
                                                                class dimension_9{
                                                                    public:
                                                                        int i;
                                                                        void ya_mero(){
                                                                            cout<<"Estas a un paso de terminar"<<endl;
                                                                        }
                                                                        class dimension_10{
                                                                            public:
                                                                                int j;
                                                                                void terminar(){
                                                                                    cout<<"Has terminado"<<endl;
                                                                                }
                                                                        };
                                                                };
                                                        };
                                                };
                                        };
                                };
                        };
                };
        };
};
int main(){
    char a;
    while(1==1){
        cout<<"Menu"<<endl;
        cout<<"1..............................Nivel 3"<<endl;
        cout<<"2..............................Nivel 5"<<endl;
        cout<<"3..............................Nivel 8"<<endl;
        cout<<"Ingresa el numero de la opcion que deseas:"<<endl;
        cin>>a;
        cin.ignore(10000,'\n');
        switch(a){
            case '1':
                dimension_1::dimension_2::dimension_3 c;
                c.nivel_3();
                break;
            case '2':
                dimension_1::dimension_2::dimension_3::dimension_4::dimension_5 e;
                e.nivel_5();
                break;
            case '3':
                dimension_1::dimension_2::dimension_3::dimension_4::dimension_5::dimension_6::dimension_7::dimension_8 h;
                h.nivel_8();
                break;
            default:
                cout<<"ERROR"<<endl;
        }
    }
return 0;
}
