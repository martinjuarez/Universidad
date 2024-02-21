#include <stdio.h>
#include <stdlib.h>
struct Visit_Ent
{
    char Fecha[11];
    char Id_Sensor[9];
    int NRE;
    long Hora;
};
struct Visit_Ent A;
struct Compra
{
    char Fecha[11];
    char Id_Cup[21];
    int Piso;
    long Hora;
    int NRC;
};
struct Compra B;
struct Id_Sensor
{
    char Id_Depart[6];
    int NP;
};
struct Id_Sensor C;
struct Id_Cup
{
    char Tel[11];
    int NCup;
    long monto;
};
struct Id_Cup D;
struct Id_Depart
{
    int Piso;
    int CanT;
    int cajero;
};
struct Id_Depart E;
int main()
{
    char op,op2;
    do{
        printf("\tMenu\n");
        printf("1...............Escribir datos\n");
        printf("2...............Leer datos\n");
        printf("3...............Guardar datos en el arbol\n");
        printf("4...............Leer datos del arbol\n");
        printf("5...............Guardar y leer archivo indice\n");
        printf("6...............Salir\n");
        scanf("%c",&op);
        switch(op)
        {
            case '1':
                do{
                    printf("\tSub-Menu\n");
                    printf("1..........Ingresar datos\n");
                    printf("2..........Generar Random\n");
                    printf("3..........Salir\n");
                    scanf("%c",&op2);
                    switch(op2)
                    {
                        case '1':
                            break;
                        case '2':
                            //Visit_Ent
                            strcpy(A.Fecha,"22/02/2018");
                            A.Fecha[11]='\0';
                            strcpy(A.Id_Sensor,"25807020");
                            A.Id_Sensor[9]='\0';
                            A.NRE = (rand()%999)+1;
                            A.Hora = (rand()%24)+1;
                            //Compra
                            strcpy(B.Fecha,"22/02/2018");
                            B.Fecha[11]='\0';
                            strcpy(B.Id_Cup,"33508564329508957000");
                            B.Id_Cup[21]='\0';
                            B.Piso = (rand()%3)+1;
                            B.Hora = (rand()%24)+1;
                            B.NRC = (rand()%9999)+1;
                            //Id_Sensor
                            strcpy(C.Id_Depart,"12341");
                            C.Id_Depart[6]='\0';
                            C.NP = (rand()%300)+1;
                            //Id_Cup
                            strcpy(D.Tel,"3324033372");
                            D.Tel[11]='\0';
                            D.NCup = (rand()%999)+1;
                            D.monto =(rand()%30000)+1;
                            //Id_Depart
                            E.Piso = (rand()%3)+1;
                            E.CanT = (rand()%400)+1;
                            E.cajero = (rand()%1)+1;
                            break;
                        case '3':
                            break;
                        default:
                            printf("Error\n");
                            break;
                    }
                }while(op!='3');
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            default:
                printf("Error\n");
                break;
        }
    }while(op!='6');
    return 0;
}
