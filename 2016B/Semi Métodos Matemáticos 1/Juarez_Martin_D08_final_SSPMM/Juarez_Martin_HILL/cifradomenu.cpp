#include <iostream>
#include <stdlib.h>
#include "cifradomenu.h"
#include "cifradohill.h"

using namespace std;

void EncryptMenu::pantallaPrincipal()
{
        int opc,opc2;
	do{
		cout<<"\tMenu:"<<endl;
		cout<<"\t1.- Cifrado de Hill"<<endl;
		cout<<"\t2.- Salir"<<endl;
		cout<<"\tIngrese Opcion:";
		cin>>opc;

		switch(opc){
			case 1: system("cls");
					do{
						cout<<"\tMenu"<<endl;
						cout<<"\t1.- Cifrar"<<endl;
						cout<<"\t2.- Descrifrar"<<endl;
						cout<<"\t3.- Salir"<<endl;
						cout<<"\tIngrese Opcion:";
						cin>>opc2;
						switch(opc2){
							case 1: encryptHill(); break;
							case 2: desEncryptHill(); break;
						}
					}while(opc2!=3);
					system("cls");
					break;

		}
	}while(opc!=2);
	getch();
}

EncryptMenu::EncryptMenu(){
    pantallaPrincipal();
}
