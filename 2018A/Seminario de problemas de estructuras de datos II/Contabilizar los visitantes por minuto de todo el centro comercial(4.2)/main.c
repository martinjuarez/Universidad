#include <stdio.h> ///Libreria basica para antrada y salida
#include <stdlib.h> ///Libreria para el uso de rand()
#include <conio.h>
#include <string.h>
#include <io.h>
#include<time.h> ///Libreria para uso de time()
struct Visit_Ent
{
    char Fecha[11];
    char Id_Sensor[9];
    int NRE;
    long Hora;
};
struct Compra
{
    char Fecha[11];
    char Id_Cup[21];
    int Piso;
    long Hora;
    int NRC;
};
struct Id_Sensor
{
    char Id_Depart[6];
    int NP;
};
struct Id_Cup
{
    char Tel[11];
    int NCup;
    long monto;
};
struct Id_Depart
{
    int Piso;
    int CanT;
    int cajero;
};
int main()
{
    int hora = time(NULL);
    ///Semilla de rand()
    srand(hora);
    ///Descriptores
    int des,des2,des3,des4,des5;
    ///TOL
    int ToL,i=1;
    ///Visit_Ent
    struct Visit_Ent A;
    char buffer[11];
    strcpy(A.Fecha,"22/02/2018");
    A.Fecha[11]='\0';
    strcpy(A.Id_Sensor,"25807020");
    A.Id_Sensor[9]='\0';
    A.NRE = (rand()%999)+1;
    A.Hora = (rand()%24)+1;
    /*
    printf("Fecha: %s \n",A.Fecha);
    printf("Id_Sensor: %s \n",A.Id_Sensor);
    printf("NRE: %d \n",A.NRE);
    printf("Hora: %d \n",A.Hora);
    ///char buffreg[sizeof(A.Fecha)];
    ///char buffreg2[sizeof(A)];
    */
    ///Compra
    struct Compra B;
    strcpy(B.Fecha,"22/02/2018");
    B.Fecha[11]='\0';
    strcpy(B.Id_Cup,"33508564329508957000");
    B.Id_Cup[21]='\0';
    B.Piso = (rand()%3)+1;
    B.Hora = (rand()%24)+1;
    B.NRC = (rand()%9999)+1;
    /*
    printf("Fecha: %s \n",B.Fecha);
    printf("Id_Cup: %s \n",B.Id_Cup);
    printf("Piso: %d \n",B.Piso);
    printf("Hora: %d \n",B.Hora);
    printf("NRC: %d \n",B.NRC);
    */
    ///Id_Sensor
    struct Id_Sensor C;
    strcpy(C.Id_Depart,"12341");
    C.Id_Depart[6]='\0';
    C.NP = (rand()%300)+1;
    /*
    printf("Id_Depart: %s \n",C.Id_Depart);
    printf("NP: %d \n",C.NP);
    */
    ///Id_Cup
    struct Id_Cup D;
    strcpy(D.Tel,"3324033372");
    D.Tel[11]='\0';
    D.NCup = (rand()%999)+1;
    D.monto =(rand()%30000)+1;
    /*
    printf("Tel: %s \n",D.Tel);
    printf("NCUP: %d \n",D.NCup);
    printf("Monto: %d \n",D.monto);
    */
    ///Id_Depart
    struct Id_Depart E;
    E.Piso = (rand()%3)+1;
    E.CanT = (rand()%400)+1;
    E.cajero = (rand()%1)+1;
    /*
    printf("Piso: %d \n",E.Piso);
    printf("CanT: %d \n",E.CanT);
    printf("Cajero: %d \n",E.cajero);
    */
    /*
    ///des
    des=open("C:\\Users\\Usuario\\Desktop\\Practica4\\archivo1.txt",2);
    if(des>0)
    {
        lseek(des,0,2);
        write(des,&A,sizeof(A));
        close(des);
    }
    else
        printf("\nError en la apertura(archivo 1)");
    ///des2
    des2=open("C:\\Users\\Usuario\\Desktop\\Practica4\\archivo2.txt",2);
    if(des2>0)
    {
        lseek(des2,0,2);
        write(des2,&B,sizeof(B));
        close(des2);
    }
    else
        printf("\nError en la apertura(archivo 2)");
    ///des3
    des3=open("C:\\Users\\Usuario\\Desktop\\Practica4\\archivo3.txt",2);
    if(des3>0)
    {
        lseek(des3,0,2);
        write(des3,&C,sizeof(C));
        close(des3);
    }
    else
        printf("\nError en la apertura(archivo 3)");
    ///des4
    des4=open("C:\\Users\\Usuario\\Desktop\\Practica4\\archivo4.txt",2);
    if(des4>0)
    {
        lseek(des4,0,2);
        write(des4,&D,sizeof(D));
        close(des4);
    }
    else
        printf("\nError en la apertura(Archivo 4)");
    ///des5
    des5=open("C:\\Users\\Usuario\\Desktop\\Practica4\\archivo5.txt",2);
    if(des5>0)
    {
        lseek(des5,0,2);
        write(des5,&A,sizeof(A));
        close(des5);
    }
    else
        printf("\nError en la apertura(archivo 5)");
    */
    //////////////////////////////////////////////////////////////////////////////////////
    ///Lectura
    printf("Dame la fecha a delimitar(DD/MM/AAAA):");
    gets(buffer);
    buffer[11]='\0';
    des=open("C:\\Users\\Usuario\\Desktop\\Practica4\\archivo1.txt",2);
    if(des>0)
    {
        ToL = read(des,&A,sizeof(A));
        while(ToL > 0)
        {
            if(buffer == A.Fecha)
            {
                printf("%d ",i);
                printf("Fecha: %s ",A.Fecha);
                printf("Id_Sensor: %s ",A.Id_Sensor);
                printf("NRE: %d ",A.NRE);
                printf("Hora: %l \n");
                i=i+1;
            }
            ToL = read(des,buffer,10);
        }
        close(des);
    }
    else
        printf("\nError en la apertura(archivo 1)");
    return 0;
}
