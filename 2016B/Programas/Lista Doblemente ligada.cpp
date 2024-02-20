#include <iostream>
using namespace std;
struct nodo
{
	int dato;
	nodo *siguiente;
	nodo *anterior;
	nodo()
	{
		dato=0;
		siguiente=NULL;
		anterior=NULL;
	}
};
bool vacia(nodo *y)
{
	if(y==NULL){
		return true;
	}
	else{
		return false;
	}
}

nodo* agregar_al_final(nodo *y){
	nodo *temp=new nodo();
	if(vacia(y)){
		y=temp;
		cout<<"Dame un dato:";
		cin>>temp->dato;
	}else{
        while(y->siguiente!=NULL){
            y=y->siguiente;
        }
        y->siguiente=temp;
        temp->anterior=y;
        cout<<"Dame un dato:";
        cin>>temp->dato;
	}
	while(y->anterior=NULL){
		y=y->anterior;
	}
	return y;
}
/**parte verde
y->siguiente=new nodo;
y->dato=10;
y->siguiente->anterior=y;
nodo* agregar_al_principio(nodo *y)
*/
nodo* insertar(nodo *y){
	nodo *temp=new nodo();
	if(vacia(y)){
		cout<<"Dame un dato:";
		cin>>temp->dato;
		y=temp;
	}
	else{
		while(y->anterior!=NULL){
			y=y->anterior;
		}
		temp->siguiente=y;
		y->anterior=temp;
		cout<<"Dame un dato:";
		cin>>temp->dato;
		y=temp;
	}
	return y;
}
nodo* agregar_en_medio(nodo *y,int pos){
    nodo *temp=new nodo;
    if(vacia(y)&&pos==1){
        y=temp;
        cout<<"Dame un dato:";
        cin>>y->dato;
    }else if(vacia(y)){
        while(y->anterior!=NULL){
            y=y->anterior;
        }
        int pos_actual=1;
        while(pos_actual!=pos){
            y=y->siguiente;
            pos_actual++;
        }
        y->siguiente=temp;
        temp->anterior=y;
        cout<<"Dame un dato:";
        cin>>temp->dato;
        while(y->anterior!=NULL){
        y=y->anterior;
        }
    }
}
nodo* mostrar_todo(nodo *y){
    if(vacia(y)){
        cout<<"La lista esta vacia"<<endl;
    }else{
        while(y->anterior!=NULL){
            y=y->anterior;
        }
        cout<<"Lista"<<endl;
        while(y->siguiente!=NULL){
            cout<<y->dato<<endl;
            y=y->siguiente;
        }
        cout<<y->dato<<endl;
    }
}
/**
nodo* buscar_dato(nodo *lista,string dato)
{
    nodo *p;
    p=lista;
    while(p->siguiente!=NULL)
    {
        if(//no este vacia && // encontrar p->nombre=dato)
            p=p->siguiente;
    }
    return (bus)
}
*/
/**
temp->siguiente=bus->siguiente;
    temp->anterior=bus;
    if(bus->siguiente!=NULL)
    {
        bus->siguiente=temp;
    }
    bus->siguiente=temp;
*/


/**
x=x->siguiente;
delete(x->anterior);
x->anterior=NULL;
*/
int main()
{
	nodo *x=NULL;
	char opc;
	do{
	    cout<<"0...................Salir"<<endl;
	    cout<<"1...................Insertar"<<endl;
        cout<<"2...................Insertar al final"<<endl;
        cout<<"3...................Insertar en medio"<<endl;
        cout<<"4...................Mostrar todo"<<endl;
	    cout<<"Dame una opcion:";
	    cout<<endl;
	    cin>>opc;
	    switch(opc){
	        case'1':
	            cout<<endl;
	            x=insertar(x);
	            break;
	        case'2':
	            cout<<endl;
	            x=agregar_al_final(x);
	            break;
	        case'3':
	            cout<<endl;
	            int p;
	            cout<<"Dame la posicion:";
	            cin>>p;
	            x=agregar_en_medio(x,p);
	            break;
	        case'4':
	            cout<<endl;
	            mostrar_todo(x);
	            break;
	        case'0':
	            cout<<"Pa que me cierras :v"<<endl;
                break;
	        default:
                cout<<endl;
                cout<<"Error"<<endl;
                break;
	    }
	    cout<<endl;
	}while(opc!='0');
	return 0;
}
