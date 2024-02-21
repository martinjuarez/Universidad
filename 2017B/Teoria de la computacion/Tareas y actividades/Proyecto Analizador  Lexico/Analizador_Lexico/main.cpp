#include <iostream>
using namespace std;
class Automata{
    public:
        char cadena[15];
        string estados;
        string aux;
        void transiciones(){
            estados = "Estados->1";
            cout<<"Ingrese una cadena: "<<endl;
            cin.getline(cadena,14);
            if(cadena[0]>='0' && cadena[0]<='9'){
                aux = "->2";
                estados = estados + aux;
                if(cadena[1]=='\0'){
                   cout<<"Entero sin signo"<<endl;
                   cout<<endl;
                }
                if(cadena[1]>='0' && cadena[1]<='9'){
                    aux = "->3";
                    estados = estados + aux;
                    if(cadena[2]=='\0'){
                       cout<<"Entero sin signo"<<endl;
                       cout<<endl;
                    }
                    if(cadena[2]>='0' && cadena[2]<='9'){
                        aux = "->4";
                        estados = estados + aux;
                        if(cadena[3]=='\0'){
                           cout<<"Entero sin signo"<<endl;
                           cout<<endl;
                        }
                        if(cadena[3]>='0' && cadena[3]<='9'){
                            aux = "->5";
                            estados = estados + aux;
                            if(cadena[4]=='\0'){
                               cout<<"Entero sin signo"<<endl;
                               cout<<endl;
                            }
                            if(cadena[4]=='h'){
                                aux = "->9";
                                estados = estados + aux;
                                cout<<"Hexadecimal"<<endl;
                                cout<<endl;
                            }if(cadena[4]>='0' && cadena[4]<='9'){
                                aux = "->10";
                                estados = estados + aux;
                                int a=5;
                                while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                    aux = "->10";
                                    estados = estados + aux;
                                    a++;
                                }
                                if(cadena[a]=='\0'){
                                   cout<<"Entero sin signo"<<endl;
                                   cout<<endl;
                                }
                                if(cadena[a]=='.'){
                                    aux = "->11";
                                    estados = estados + aux;
                                    a++;
                                    if(cadena[a]>='0' && cadena[a]<='9'){
                                        aux = "->12";
                                        estados = estados + aux;
                                        if(cadena[a]=='\0'){
                                            cout<<"Real sin signo"<<endl;
                                            cout<<endl;
                                        }
                                        while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                            aux = "->12";
                                            estados = estados + aux;
                                            a++;
                                            if(cadena[a]=='\0'){
                                                cout<<"Real sin signo"<<endl;
                                                cout<<endl;
                                            }
                                        }
                                        if(cadena[a]=='e'){
                                            aux = "->13";
                                            estados = estados + aux;
                                            a++;
                                            if(cadena[a]=='+'||cadena[a]=='-'){
                                                aux = "->14";
                                                estados = estados + aux;
                                                a++;
                                                if(cadena[a]>='0' && cadena[a]<='9'){
                                                    aux = "->15";
                                                    estados = estados + aux;
                                                    a++;
                                                    while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                                        aux = "->15";
                                                        estados = estados + aux;
                                                        a++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                if(cadena[a]=='e'){
                                    aux = "->13";
                                    estados = estados + aux;
                                    a++;
                                    if(cadena[a]=='+'||cadena[a]=='-'){
                                        aux = "->14";
                                        estados = estados + aux;
                                        a++;
                                        if(cadena[a]>='0' && cadena[a]<='9'){
                                            aux = "->15";
                                            estados = estados + aux;
                                            if(cadena[a]=='\0'){
                                                cout<<"Exponencial entero sin signo"<<endl;
                                                cout<<endl;
                                            }
                                            a++;
                                            while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                                aux = "->15";
                                                estados = estados + aux;
                                                a++;
                                                if(cadena[a]=='\0'){
                                                    cout<<"Exponencial entero sin signo"<<endl;
                                                    cout<<endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }else if(cadena[4]=='.'){
                                aux = "->11";
                                estados = estados + aux;
                                if(cadena[5]>='0' && cadena[5]<='9'){
                                    aux = "->12";
                                    estados = estados + aux;
                                    if(cadena[5]=='\0'){
                                        cout<<"Real sin signo"<<endl;
                                        cout<<endl;
                                    }
                                    int a=6;
                                    while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                        aux = "->12";
                                        estados = estados + aux;
                                        a++;
                                        if(cadena[a]=='\0'){
                                            cout<<"Real sin signo"<<endl;
                                            cout<<endl;
                                        }
                                    }
                                    if(cadena[a]=='e'){
                                        aux = "->13";
                                        estados = estados + aux;
                                        a++;
                                        if(cadena[a]=='+'||cadena[a]=='-'){
                                            aux = "->14";
                                            estados = estados + aux;
                                            a++;
                                            if(cadena[a]>='0' && cadena[a]<='9'){
                                                aux = "->15";
                                                estados = estados + aux;
                                                if(cadena[a]=='\0'){
                                                    cout<<"Exponencial real"<<endl;
                                                    cout<<endl;
                                                }
                                                while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                                    aux = "->15";
                                                    estados = estados + aux;
                                                    a++;
                                                    if(cadena[a]=='\0'){
                                                        cout<<"Exponencial real"<<endl;
                                                        cout<<endl;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }else if(cadena[4]=='e'){
                                aux = "->13";
                                estados = estados + aux;
                                if(cadena[5]=='+'||cadena[5]=='-'){
                                    aux = "->14";
                                    estados = estados + aux;
                                    if(cadena[6]>='0' && cadena[6]<='9'){
                                        aux = "->15";
                                        estados = estados + aux;
                                        if(cadena[6]=='\0'){
                                            cout<<"Exponencial entero"<<endl;
                                            cout<<endl;
                                        }
                                        int a=7;
                                        while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                            aux = "->15";
                                            estados = estados + aux;
                                            a++;
                                            if(cadena[a]=='\0'){
                                                cout<<"Exponencial entero"<<endl;
                                                cout<<endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }else if(cadena[3]=='A'||cadena[3]=='B'||cadena[3]=='C'||cadena[3]=='D'||cadena[3]=='E'||cadena[3]=='F'){
                            aux = "->8";
                            estados = estados + aux;
                            if(cadena[4]=='h'){
                                aux = "->9";
                                estados = estados + aux;
                                cout<<"Hexadecimal"<<endl;
                                cout<<endl;
                            }
                        }else if(cadena[3]=='.'){
                            aux = "->11";
                            estados = estados + aux;
                            if(cadena[4]>='0' && cadena[4]<='9'){
                                aux = "->12";
                                estados = estados + aux;
                                if(cadena[4]=='\0'){
                                    cout<<"Real sin signo"<<endl;
                                    cout<<endl;
                                }
                                int a=5;
                                while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                    aux = "->12";
                                    estados = estados + aux;
                                    a++;
                                    if(cadena[a]=='\0'){
                                        cout<<"Real sin signo"<<endl;
                                        cout<<endl;
                                    }
                                }
                                if(cadena[a]=='e'){
                                    aux = "->13";
                                    estados = estados + aux;
                                    a++;
                                    if(cadena[a]=='+'||cadena[a]=='-'){
                                        aux = "->14";
                                        estados = estados + aux;
                                        a++;
                                        if(cadena[a]>='0' && cadena[a]<='9'){
                                            aux = "->15";
                                            estados = estados + aux;
                                            if(cadena[a]=='\0'){
                                                cout<<"Exponencial real"<<endl;
                                                cout<<endl;
                                            }
                                            a++;
                                            while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                                aux = "->15";
                                                estados = estados + aux;
                                                a++;
                                                if(cadena[a]=='\0'){
                                                    cout<<"Exponencial real"<<endl;
                                                    cout<<endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }else if(cadena[3]=='e'){
                            aux = "->13";
                            estados = estados + aux;
                            if(cadena[4]=='+' || cadena[4]=='-'){
                                aux = "->14";
                                estados = estados + aux;
                                if(cadena[5]>='0' && cadena[5]<='9'){
                                    aux = "->15";
                                    estados = estados + aux;
                                    if(cadena[5]=='\0'){
                                        cout<<"Exponencial entero"<<endl;
                                        cout<<endl;
                                    }
                                    int a=6;
                                    while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                        aux = "->15";
                                        estados = estados + aux;
                                        a++;
                                        if(cadena[a]=='\0'){
                                            cout<<"Exponencial entero"<<endl;
                                            cout<<endl;
                                        }
                                    }
                                }
                            }
                        }
                    }else if(cadena[2]=='A'||cadena[2]=='B'||cadena[2]=='C'||cadena[2]=='D'||cadena[2]=='E'||cadena[2]=='F'){
                        aux = "->7";
                        estados = estados + aux;
                        if((cadena[3]=='A'||cadena[3]=='B'||cadena[3]=='C'||cadena[3]=='D'||cadena[3]=='E'||cadena[3]=='F')||(cadena[3]>='0' && cadena[3]<='9')){
                            aux = "->8";
                            estados = estados + aux;
                            if(cadena[4]=='h'){
                                aux = "->9";
                                estados = estados + aux;
                                cout<<"Hexadecimal"<<endl;
                                cout<<endl;
                            }
                        }
                    }else if(cadena[2]=='.'){
                        aux = "->11";
                        estados = estados + aux;
                        if(cadena[3]>='0' && cadena[3]<='9'){
                            aux = "->12";
                            estados = estados + aux;
                            if(cadena[3]=='\0'){
                                cout<<"Real sin signo"<<endl;
                                cout<<endl;
                            }
                            int a=3;
                            while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                aux = "->12";
                                estados = estados + aux;
                                a++;
                                if(cadena[a]=='\0'){
                                    cout<<"Real sin signo"<<endl;
                                    cout<<endl;
                                }
                            }
                            if(cadena[a]=='e'){
                                aux = "->13";
                                estados = estados + aux;
                                a++;
                                if(cadena[a]=='+'||cadena[a]=='-'){
                                    aux = "->14";
                                    estados = estados + aux;
                                    a++;
                                    if(cadena[a]>='0' && cadena[a]<='9'){
                                        aux = "->15";
                                        estados = estados + aux;
                                        if(cadena[a]=='\0'){
                                            cout<<"Exponencial real"<<endl;
                                            cout<<endl;
                                        }
                                        while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                            aux = "->15";
                                            estados = estados + aux;
                                            a++;
                                            if(cadena[a]=='\0'){
                                                cout<<"Exponencial real"<<endl;
                                                cout<<endl;
                                            }

                                        }
                                    }
                                }
                            }
                        }
                    }else if(cadena[2]=='e'){
                        aux = "->13";
                        estados = estados + aux;
                        if(cadena[3]=='+'||cadena[3]=='-'){
                            aux = "->14";
                            estados = estados + aux;
                            if(cadena[4]>='0'||cadena[4]<='9'){
                                aux = "->15";
                                estados = estados + aux;
                                if(cadena[4]=='\0'){
                                    cout<<"Exponencial entero"<<endl;
                                    cout<<endl;
                                }
                                int a=4;
                                while((cadena[a]>='0'||cadena[a]<='9')&&a<15){
                                    aux = "->15";
                                    estados = estados + aux;
                                    a++;
                                    if(cadena[a]=='\0'){
                                        cout<<"Exponencial entero"<<endl;
                                        cout<<endl;
                                    }
                                }
                            }
                        }
                    }
                }else if(cadena[1]=='A'||cadena[1]=='B'||cadena[1]=='C'||cadena[1]=='D'||cadena[1]=='E'||cadena[1]=='F'){
                    aux = "->6";
                    estados = estados + aux;
                    if((cadena[2]=='A'||cadena[2]=='B'||cadena[2]=='C'||cadena[2]=='D'||cadena[2]=='E'||cadena[2]=='F')||(cadena[2]>='0' && cadena[2]<='9')){
                        aux = "->7";
                        estados = estados + aux;
                        if((cadena[3]=='A'||cadena[3]=='B'||cadena[3]=='C'||cadena[3]=='D'||cadena[3]=='E'||cadena[3]=='F')||(cadena[3]>='0' && cadena[3]<='9')){
                            aux = "->8";
                            estados = estados + aux;
                            if(cadena[4]=='h'){
                                aux = "->9";
                                estados = estados + aux;
                                cout<<"Hexadecimal"<<endl;
                                cout<<endl;
                            }
                        }
                    }
                }else if(cadena[1]=='.'){
                    aux = "->11";
                    estados = estados + aux;
                    if(cadena[2]>='0' && cadena[2]<='9'){
                        aux = "->12";
                        estados = estados + aux;
                        if(cadena[3]=='\0'){
                            cout<<"Exponencial real"<<endl;
                            cout<<endl;
                        }
                        int a=3;
                        while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                            aux = "->12";
                            estados = estados + aux;
                            a++;
                            if(cadena[a]=='\0'){
                                cout<<"Real sin signo"<<endl;
                                cout<<endl;
                            }
                        }
                        if(cadena[a]=='e'){
                            aux = "->13";
                            estados = estados + aux;
                            a++;
                            if(cadena[a]=='+'||cadena[a]=='-'){
                                aux = "->14";
                                estados = estados + aux;
                                a++;
                                if(cadena[a]>='0' && cadena[a]<='9'){
                                    aux = "->15";
                                    estados = estados + aux;
                                    if(cadena[a]=='\0'){
                                        cout<<"Exponencial real"<<endl;
                                        cout<<endl;
                                    }
                                    while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                        aux = "->15";
                                        estados = estados + aux;
                                        a++;
                                        if(cadena[a]=='\0'){
                                            cout<<"Exponencial real"<<endl;
                                            cout<<endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }else if(cadena[1]=='e'){
                    aux = "->13";
                    estados = estados + aux;
                    if(cadena[2]=='+' || cadena[2]=='-'){
                        aux = "->14";
                        estados = estados + aux;
                        if(cadena[3]>='0' && cadena[3]<='9'){
                            aux = "->15";
                            estados = estados + aux;
                            cout<<"Yes"<<endl;
                            if(cadena[4]=='\0'){
                                cout<<"Exponencial entero"<<endl;
                                cout<<endl;
                            }
                            int a=4;
                            while((cadena[a]>='0' && cadena[a]<='9') && a<15){
                                aux = "->15";
                                estados = estados + aux;
                                a++;
                                if(cadena[a]=='\0'){
                                    cout<<"Exponencial entero"<<endl;
                                    cout<<endl;
                                }
                            }
                        }
                    }
                }
                cout<<estados<<endl;
            }else if((cadena[0]>='a'&&cadena[0]<='z')||(cadena[0]>='A'&&cadena[0]<='Z')||(cadena[0]>='0'&&cadena[0]<='1')||cadena[0]=='_'){
                aux = "->16";
                estados = estados + aux;
                if(cadena[1]=='\0'){
                    cout<<"Identificador"<<endl;
                    cout<<endl;
                }
                int a = 0;
                while((cadena[a]>='a'&&cadena[a]<='z')||(cadena[a]>='A'&&cadena[a]<='Z')||(cadena[a]>='0'&&cadena[a]<='1')||(cadena[a]=='_'&&a<15)){
                    aux = "->16";
                    estados = estados + aux;
                    a++;
                     if(cadena[a]=='\0'){
                        cout<<"Identificador"<<endl;
                        cout<<endl;
                    }
                }
                cout<<estados<<endl;
            }else if(cadena[0]=='+' || cadena[0]=='-'){
                aux = "->17";
                estados = estados + aux;
                ///aqui va lo copeado|
                if(cadena[1]=='\0'){
                   cout<<"Operador Aritmetico"<<endl;
                   cout<<endl;
                }
                if(cadena[2]=='\0'){
                    cout<<"Entero con signo"<<endl;
                    cout<<endl;
                }
                cout<<estados<<endl;
            }else if(cadena[0]=='&'){
                aux = "->18";
                estados = estados + aux;
                if(cadena[1]=='&'){
                    aux = "->19";
                    estados = estados + aux;
                }
                cout<<"Operador Logico"<<endl;
                cout<<estados<<endl;
                cout<<endl;
            }else if(cadena[0]=='*' || cadena[0]=='/' || cadena[0]=='^' || cadena[0]=='%'){
                aux = "->19";
                estados = estados + aux;
                cout<<"Operador Aritmetico"<<endl;
                cout<<estados<<endl;
                cout<<endl;
            }else if(cadena[0]=='|'){
                aux = "->20";
                estados = estados + aux;
                if(cadena[1]=='|'){
                    aux = "->19";
                    estados = estados + aux;
                }
                cout<<"Operador Logico"<<endl;
                cout<<estados<<endl;
            }else if(cadena[0]=='>' || cadena[0]=='<' || cadena[0]=='=' || cadena[0]=='!'){
                aux = "->21";
                estados = estados + aux;
                if(cadena[1]=='='){
                    aux = "->19";
                    estados = estados + aux;
                }
                cout<<"Operador Logico"<<endl;
                cout<<estados<<endl;
                cout<<endl;
            }else{
                cout<<"Caracter invalido"<<endl;
                cout<<estados<<endl;
                cout<<endl;
            }
        }
};
int main()
{
    Automata A;
    char op;
    do{
        cout<<endl;
        cout<<"Analizador lexico"<<endl;
        cout<<"1........Ingresar una cadena"<<endl;
        cout<<"2........Salir"<<endl;
        cin>>op;
        cin.ignore(10000,'\n');
        cout<<endl;
        switch(op){
            case '1':
                A.transiciones();
                break;
            case '2':
                break;
            default:
                cout<<"Error intentalo de nuevo"<<endl;
                break;
        }
    }while(op!='2');
    return 0;
}
