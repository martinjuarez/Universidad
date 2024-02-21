/** LEE UN ARCHIVO, REGISTRO POR REGISTRO, DESPLEGANDO LOS
CAMPOS DE CADA UNO DE LOS REGISTROS EN LA PANTALLA */
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <process.h>
#include <stdlib.h>

#define TAM_MAX_REG 512
#define SOLOLECT 0
#define DELIM_CAR "|"
int toma_reg(int fd, char buffreg[]);
int toma_campo(char campo[],char buffreg[],short pos_bus, short long_reg);
void main(){
    int fd;
    int cont_reg;
    int cont_campos;
    int pos_bus;
    int long_reg;
    char nomarch[15];
    char buffreg[TAM_MAX_REG + 1];
    char campo[TAM_MAX_REG + 1];

    printf("Proporciona el nombre de tu archivo a leer:");
    gets(nomarch);
    if ((fd = open(nomarch,SOLOLECT))< 0){
        printf("Error en la apertura del archivo - Fin de programa\n");
        getch();
        exit(1);
        printf("0aqui\n");
    }
    printf("1aqui\n");
    cont_reg = 0;
    pos_bus = 0;

        while ((long_reg = toma_reg(fd,buffreg))>0)
        {
            printf("2aqui\n");
            printf("Registro %d\n", ++cont_reg);
            cont_campos > 0;
            while((pos_bus=toma_campo(campo,buffreg,pos_bus,long_reg)) > 0)
                printf("3aqui\n");
                printf ("\tCampo %d: %s\n",++cont_campos,campo);
                getch();
        }
        printf("4aqui\n");
        printf("Fin del archivo");
        getch();
        close(fd);
}
int toma_reg(int fd, char buffreg[])
{
    char num[2];
    int long_reg;

    if(read(fd, &num, 2) ==0 )
        return(0);
    sscanf(num, "%d", &long_reg);
    printf("long_rec:%s\n",long_reg);
    read(fd,&buffreg,long_reg);
    return(long_reg);
}
int toma_campo(char campo[],char buffreg[],short pos_bus, short long_reg)
{
    short cpos = 0;
    if(pos_bus == long_reg)
        return (0);

    while((pos_bus < long_reg) && (campo[cpos++] = buffreg[pos_bus++])!= DELIM_CAR);
    if(campo[cpos - 1] == DELIM_CAR)
        campo[--cpos] = '\0';
    else
        campo[cpos] = '\0';
    return (pos_bus);
}
