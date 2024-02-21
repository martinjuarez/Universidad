#include <stdio.h>
#include <stdlib.h>
struct Visit_Ent
{
    char Id_Sensor[8];
    int NRE;
    char Fecha[10];
    float Hora;
};
struct Compra
{
    char Id_Cup[12];
    int Piso;
    char Fecha[10];
    int Hora;
    int NRC;
};
struct Id_Sensor
{
    int NP;
    char Id_Depart[5];
};
struct Id_Cup
{
    int NCup;
    double monto;
    char Tel[10];
};
struct Id_Depart
{
    int Piso;
    int CanT;
    int cajero;
};
int main()
{
    int des,des2,des3,des4,des5;
    struct Visit_Ent A;
    strcpy(A.Id_Sensor,"010003200");
    A.NRE= rand() % 200;
    strcpy(A.Fecha,"20/02/2018");
    A.Hora= rand() % 20;
    ///struct Compra B;
    struct Id_Sensor C;
    C.NP = rand() % 300;
    strcpy(C.Id_Depart,"04301");
    struct Id_Cup D;
    D.NCup = rand() % 999;
    D.monto = rand() % 30000;
    strcpy(D.Tel,"3314320608");
    ///struct Id_Depart E;
    des=open("C:\\Users\\Usuario\\Desktop\\Practica4\\archivo1.txt",2);
    if(des>0)
    {
        lseek(des,0,2);
        write(des,&A,sizeof(A));
        close(des);
    }
    else
        printf("\nError en la apertura(archivo 1)");
    des=open("C:\\Users\\Usuario\\Desktop\\Practica4\\archivo3.txt",2);
    if(des3>0)
    {
        lseek(des3,0,2);
        write(des3,&C,sizeof(C));
        close(des3);
    }
    else
        printf("\nError en la apertura(archivo 3)");
    des=open("C:\\Users\\Usuario\\Desktop\\Practica4\\archivo4.txt",2);
    if(des4>0)
    {
        lseek(des4,0,2);
        write(des4,&D,sizeof(D));
        close(des4);
    }
    else
        printf("\nError en la apertura(Archivo 4)");
    return 0;
}
