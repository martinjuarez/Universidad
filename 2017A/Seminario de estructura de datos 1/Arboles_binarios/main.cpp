#include <iostream>
#include "arbolbinariobusqueda.h"
using namespace std;
class Bicicleta
{
public:
    int getId() const;
    void setId(int value);

    unsigned int getMetros() const;
    void setMetros(unsigned int value);

    bool operator<=(  Bicicleta &bici)const
    {
        return getMetros() <= bici.getMetros();
    }

    bool operator >(  Bicicleta &bici) const
    {
        return getMetros() > bici.getMetros();
    }


private:
    int id;
    unsigned int metros;

    friend ostream &operator <<(ostream &out, Bicicleta &bici)
    {
        out << "Id: "      << bici.getId()
            << " Metros: " << bici.getMetros()
            << endl;

        return out;
    }



};

int main(int argc, char *argv[])
{
    Bicicleta a,b,c,d;
    int id;
    cout << "Ingresa el id";
    cin >> id;
    a.setId(id);
    cout << "Metros recorridos";
    unsigned int m;
    cin >> m;
    a.setMetros(m);


    b.setId(2);
    b.setMetros(50);

    c.setId(3);
    c.setMetros(200);

    d.setId(4);
    d.setMetros(0);


    ArbolBinarioBusqueda<Bicicleta> ABB;

    ABB.insertar(a);
    ABB.insertar(b);
    ABB.insertar(c);
    ABB.insertar(d);



    ABB.inorder();
    return 0;
}

int Bicicleta::getId() const
{
return id;
}

void Bicicleta::setId(int value)
{
id = value;
}

unsigned int Bicicleta::getMetros() const
{
return metros;
}

void Bicicleta::setMetros(unsigned int value)
{
metros = value;
}
