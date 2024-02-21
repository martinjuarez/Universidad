#include "Menu.h"

Menu::Menu()
{
    name="---";
}
Menu::~Menu() {}

void Menu::save()
{
    ofstream escribir(name+".txt");
    escribir.write((char*)&g,sizeof(g));
    escribir.close();
}

void Menu::addVert()
{
    string n;

    cout<<"Cuantos vertices tiene?: ";
    do
    {
        cin>>g.cant;
        cin.ignore();
        if(g.cant>10||g.cant<1)
            cout<<"Ingrese un valor valido (1-10): ";

    }
    while(g.cant>10||g.cant<1);

    for(size_t i=0; i<g.cant; i++)
    {
        cout<<"Ingrese el nombre del vertice "<<i+1<<": ";
        getline(cin,n);
        for(int j=0; j<20; j++)
            g.v[i].nombre[j]=n[j];
        g.v[i].activo=true;
    }
}

void Menu::addAris()
{
    string origen,destino;
    int o,d;
    char adar;

    cout<<"Desea agregar aristas?(y/n): ";
    do
    {
        cin>>adar;
        cin.ignore();
        if(adar=='y'||adar=='Y')
        {
            cout<<"Nueva arista"<<endl;
            do
            {
                cout<<"Ingrese el nombre del nodo origen: ";
                getline(cin,origen);
                for(o=0; o<10; o++)
                {
                    if(origen==g.v[o].nombre)
                        break;
                }
                if(o==10)
                    cout<<"El vertice no existe, intente de nuevo"<<endl;
                else
                    break;
            }
            while(true);

            do
            {
                cout<<"Ingrese el nombre del nodo destino: ";
                getline(cin,destino);
                for(d=0; d<10; d++)
                {
                    if(destino==g.v[d].nombre)
                        break;
                }
                if(d==10)
                    cout<<"El vertice no existe, intente de nuevo"<<endl;
                else
                    break;
            }
            while(true);
            g.a[o][d].conexion=true;
            if(g.pond)
            {
                cout<<"Ingrese el peso de la arista: ";
                cin>>g.a[o][d].peso;
                cin.ignore();
            }
            if(!g.dir)
                g.a[d][o]=g.a[o][d];
        }
        else if(adar=='n'||adar=='N')
        {
            cout<<"No se agregaron aristas"<<endl;
            break;
        }
        else
            cout<<"Elija Y o N: ";
        cout<<"Desea agregar una nueva arista? (y/n): ";
    }
    while(adar!='n'&&adar!='N');
}

void Menu::NewGraph()
{
    char p;
    Grafo tmp;
    g=tmp;
    cout<<"Ingrese el nombre del grafo: ";
    getline(cin,name);

    ifstream t(name+".txt");
    if(t.is_open())
    {
        cout<<"Ya existe este grafo. ";
        t.close();
        return;
    }

    cout<<"Es un grafo ponderado? (y/n): ";
    do
    {
        cin>>p;
        if(p=='y'||p=='Y')
            g.pond=true;
        else if(p=='n'||p=='N')
            g.pond=false;
        else
            cout<<"Seleccione Y o N: ";
    }
    while(p!='y'&&p!='Y'&&p!='n'&&p!='N');

    cout<<"Es un grafo dirigido? (y/n): ";
    do
    {
        cin>>p;
        if(p=='y'||p=='Y')
            g.dir=true;
        else if(p=='n'||p=='N')
            g.dir=false;
        else
            cout<<"Seleccione Y o N: ";
    }
    while(p!='y'&&p!='Y'&&p!='n'&&p!='N');

    addVert();
    addAris();
    save();
}

void Menu::ShowMeYourMoves()
{
    size_t i,j;

    string name;
    cout<<"nombre del grafo: ";
    getline(cin,name);
    ifstream leer(name+".txt");
    if(!leer.is_open())
        cout<<"No se encontro el grafo. ";
    else
    {
        leer.read((char*)&g,sizeof(g));
        leer.close();
        //cout<<"direccion: "<<g.dir<<" Ponderacion: "<<g.pond<<endl;
        for(i=0; i<g.cant; i++)
            cout<<"\t"<<g.v[i].nombre;
        cout<<endl<<endl;
        for(i=0; i<g.cant; i++)
        {
            cout<<g.v[i].nombre;
            for(j=0; j<g.cant; j++)
            {
                if(g.a[i][j].conexion)
                    cout<<"\tV";
                else
                    cout<<"\tF";
            }
            cout<<endl;
            if(g.pond)
            {
                for(j=0; j<g.cant; j++)
                    cout<<"\t"<<g.a[i][j].peso;
                cout<<endl;
            }
        }
    }
}

void Menu::editVert()
{
    string vedt,n;
    char r;
    size_t i,j;

    system("cls");
    cout<<"ingrese el nombre del vertice que desea modificar: ";
    getline(cin,vedt);
    for(i=0; i<g.cant; i++)
    {
        if(vedt==g.v[i].nombre)
        {
            cout<<"Desea eliminarlo? (y/n): ";
            do
            {
                cin>>r;
                cin.ignore();
////////////////////////////////////////////////////////////////////////////////////////
                if(r=='y'||r=='Y')
                {
                    for(j=i; j<10; j++)
                        g.v[j]=g.v[j+1];
                    for(size_t k=0; k<g.cant; k++)
                    {
                        for(j=i; j<g.cant; j++)
                        {
                            g.a[j][k]=g.a[j+1][k+1];
                            cout<<g.v[k].nombre<<", "<<g.v[j].nombre<<": "<<g.a[j][k].peso<<endl;
                        }
                    }
                    g.cant--;
                    save();
                    cin.get();
                    break;
                }
////////////////////////////////////////////////////////////////////////////////////////
                else if(r=='n'||r=='N')
                {
                    cout<<"Modificar vertice"<<endl;
                    cout<<"Nuevo nombre: ";
                    getline(cin,n);
                    for(j=0; j<20; j++)
                        g.v[i].nombre[j]=n[j];
                    break;
                }
                else
                    cout<<"Elija una opcion valida (y/n): ";
            }
            while(r!='y'&&r!='Y'&&r!='n'&&r!='N');
        }
    }
/////////////////////////////////////////////////////////////////////////////////////
    if(i==g.cant&&r!='Y'&&r!='y')
    {
        char w;
        cout<<"no se encontro el vertice. Desea agregarlo? (y/n): ";
        while(true)
        {
            cin>>w;
            cin.ignore();
            if(w=='y'||w=='Y')
            {
                for(j=0; j<20; j++)
                    g.v[i+1].nombre[j]=vedt[j];
                g.v[i+1].activo=true;
                g.cant++;
                break;
            }
            else if(w=='n'||w=='N')
                break;
            else
                cout<<"ingrese una opcion valida (y/n): ";
        }
    }
}

/*void Menu::editVert()
{
    string vedt,n;
    char r;
    int i,j;

    system("cls");
    cout<<"ingrese el nombre del vertice que desea modificar: ";
    getline(cin,vedt);
    for(i=0; i<g.cant; i++)
    {
        if(vedt==g.v[i].nombre)
        {
            cout<<"Desea eliminarlo? (y/n): ";
            do
            {
                cin>>r;
                cin.ignore();
                if(r=='y'||r=='Y')
                {
                    for(j=i; j<10; j++)
                        g.v[j]=g.v[j+1];

                    for(int k=i; k<10; k++)
                    {
                        for(j=0; j<10; j++)
                        {
                            g.a[k][j]=g.a[k][j+1];
                            if(!g.dir)
                                g.a[j][k]=g.a[k][j];
                        }
                    }
                    i--;
                    g.cant--;
                    break;
                }
                else if(r=='n'||r=='N')
                {
                    cout<<"Modificar vertice"<<endl;
                    cout<<"Nuevo nombre: ";
                    getline(cin,n);
                    for(j=0; j<20; j++)
                        g.v[i].nombre[j]=n[j];
                    break;
                }
                else
                    cout<<"Elija una opcion valida (y/n): ";
            }
            while(r!='y'&&r!='Y'&&r!='n'&&r!='N');
        }
    }

    if(i==g.cant&&r!='Y'&&r!='y')
    {
        char w;
        cout<<"no se encontro el vertice. Desea agregarlo? (y/n): ";
        while(true)
        {
            cin>>w;
            cin.ignore();
            if(w=='y'||w=='Y')
            {
                for(j=0; j<20; j++)
                    g.v[i+1].nombre[j]=vedt[j];
                g.v[i+1].activo=true;
                g.cant++;
                break;
            }
            else if(w=='n'||w=='N')
                break;
            else
                cout<<"ingrese una opcion valida (y/n): ";
        }
    }
    save();
}*/

void Menu::rec_an(Vertice v)
{
    Cola<Vertice> cola;
    Lista<Vertice> visitados;
    Vertice actual;
    Vertice origen;

    origen=v;
}

void Menu::menu()
{
    char opc;

    do
    {
        system ("cls");
        cout<<"1) Agregar Grafo     "<<endl;
        cout<<"2) Mostrar Grafo     "<<endl;
        cout<<"3) Modificar Grafo   "<<endl;
        cout<<"4) Recorrer Grafo    "<<endl;
        cout<<"5) Turn this shit off"<<endl;
        cin>>opc;
        cin.ignore();

        switch(opc)
        {
        case '1':
            NewGraph();
            break;
        case '2':
            ShowMeYourMoves();
            break;
        case '3':
        {
            cout<<"ingresa el nombre del grafo a modificar: ";
            getline(cin,name);
            ifstream leer(name+".txt");
            if(!leer.is_open())
                cout<<"No se encontro el grafo. ";
            else
            {
                leer.read((char*)&g,sizeof(g));
                leer.close();
                char op;
                do
                {
                    system("cls");
                    cout<<"Que desea modificar?"<<endl;
                    cout<<"1) Vertices"<<endl;
                    cout<<"2) Aristas"<<endl;
                    cout<<"3) Eliminar grafo"<<endl;
                    cout<<"4) volver"<<endl;
                    cin>>op;
                    cin.ignore();
                    switch(op)
                    {
                    case '1':
                        cout<<"editar"<<endl;//editVert();
                        break;
                    case '2':
                        cout<<"editar"<<endl;//editAris();
                        break;
                    case '3':
                    {
                        char str[50];
                        int q;
                        for(q=0; q<46; q++)
                        {
                            str[q]=name[q];
                            if(name[q]=='\0')
                                break;
                        }
                        str[q]='.';
                        str[q+1]='t';
                        str[q+2]='x';
                        str[q+3]='t';
                        remove(str);
                        break;
                    }
                    break;
                    case '4':
                        break;
                    default:
                        cout<<"elije una opcion valida. ";
                    }
                }
                while(op!='4'&&op!='3');
            }
        }
        break;
        case '4':
        {
            cout<<"Ingrese el nombre del grafo que desea recorrer: ";
            getline(cin,name);
            ifstream file(name+".txt");
            if(!file.is_open())
                cout<<"No existe el grafo. "<<endl;
            else
            {
                file.read((char*)&g, sizeof(g));

                string ori;
                cout<<"introduce el vertice de origen: ";
                getline(cin,ori);
                for(size_t a; a<g.cant; a++)
                {
                    if(g.v[a].nombre==ori)
                    {
                        rec_an(g.v[a]);
                        break;
                    }
                }

                cout<<"recorrido"<<endl;
                //rec_an();
            }
        }
        break;
        case '5':
            break;
        default:
            cout<<"seas mamon, nomas hay dos opciones >:v "<<endl;
        }
        cout<<"Presione ENTER para continuar...";
        cin.get();
    }
    while (opc!='5');
}
