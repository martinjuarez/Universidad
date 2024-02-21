#include <iostream>
#include <Grafo.h>

using namespace std;

string validar_numero1()
{
    string numero;
    int i=0;
    int tope=0;
    char caracter;
    caracter = getch();
    numero="";
    while(caracter!= 13)
    {
       if(caracter!=8)
       {
            if(tope<16)
            {
                if(caracter>47&&caracter<58)
                {
                    numero.push_back(caracter);
                    //system("cls");
                    cout << numero[i];
                    i++;
                    tope++;
                }
                else if(caracter==32)
                {
                    numero.push_back(caracter);
                    //system("cls");
                    cout << numero[i];
                    i++;
                    tope++;
                }
            }
       }
       else
        {
			if (numero.length() > 0)
            {
				cout << "\b \b";
				numero= numero.substr(0, numero.length() - 1);
				i--;
				tope--;
			}
		}
        caracter=getch();
    }
    return numero;
}


int main()
{
    grafo G;
    G.inicializar();
    char opc;
    do{
        system("cls");
        cout<<"\n\t\t\t\t-----.GRAFO.-----"<<endl;
        cout<<"\n   1) CAPTURAR\n   2) MOSTRAR MATRIZ DE ADYACENCIA\n   3) GUARDAR EN EL DISCO\n   4) CARGAR DEL DISCO\n   5) MODIFICAR\n   6) ELIMINAR\n   7) RECORRIDO EN ANCHURA(COLA)\n   8) RECORRIDO EN PROFUNDIDAD(PILA)\n   9) RUTA EN ANCHURA(COLA)\n   10) RUTA EN PROFUNDIDAD\n   0) SALIR\nINGRESA UNA OPCCION: ";
        opc=atoi(validar_numero1().c_str());
        switch(opc)
        {
        case 1:
            system("cls");
            G.capturar();
            system("pause");
            break;
        case 2:
            system("cls");
            G.mostrar();
            system("pause");
            break;
        case 3:
            system("cls");
            G.guardar_a_disco();
            cout<<"\n\n   REGISTRO GUARDADO\n\n"<<endl;
            system("pause");
            break;
        case 4:
            system("cls");
            G.cargar_del_disco();
            system("pause");
            break;
        case 5:
            system("cls");
            G.modificar();
            system("pause");
            break;
        case 6:
            system("cls");
            G.eliminar();
            system("pause");
            break;
        case 7:
            system("cls");
            G.recorrido_de_anchura();
            system("pause");
            break;
        case 8:
            system("cls");
            G.recorrido_de_profundidad();
            system("pause");
            break;
        case 9:
            system("cls");
            G.ruta_anchura();
            system("pause");
            break;
        case 10:
            system("cls");
            G.ruta_profundidad();
            system("pause");
            break;
        }
    }while(opc!=0);
    return 0;
}
