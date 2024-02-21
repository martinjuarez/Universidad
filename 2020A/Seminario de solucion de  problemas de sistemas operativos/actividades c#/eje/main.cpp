#include <iostream>
#include <conio.h>
using namespace std;

int main(){

    bool bandera = 0, bandera2 = 1;
    while(1){
       if(kbhit()){
         char tecla = getch();

         if(bandera2){
          switch(tecla){
             case 'e':{
               cout << "Interrupcion" << endl;
             }
              break;
             case 'w':{
               cout << "Error" << endl;
             }
              break;
             case 'p':{
               cout << "Pausa" << endl;
               bandera2 = 0;
             }
              break;
             case 'c':{
               cout << "Continua" << endl;
             }
              break;
             case 's':{
               cout << "Salir" << endl;
               bandera = 1;
             }
          }
         }

         if(tecla=='c')
           bandera2 = 1;
       }


       if(bandera)
        break;
    }


    return 0;
}
