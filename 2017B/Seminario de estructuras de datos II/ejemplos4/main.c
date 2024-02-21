/*LEE UN ARCHIVO, REGISTRO POR REGISTRO,DESPLEGANDO LOS CAMPOS DE CADA UNO DE LOS REGISTROS EN LA PANTALLA    */
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#define TAM_MAX_REG 512
#define SOLOLECT 0
#define DELIM_CAR '|'
int toma_reg (int fd,char buffreg[]);
int toma_campo (char campo[], char buffreg[],short pos_bus,short long_reg);

int main()
{
    int fd, cont_reg,cont_campos;
    int pos_bus, long_reg;
    char nomarch[15];
    char buffreg[TAM_MAX_REG + 1];
    char campo[TAM_MAX_REG + 1];
    printf("Proporcione el nombre de tu archivo a leer: ");
    gets(nomarch);
    if((fd = open(nomarch,SOLOLECT))< 0)
    {
        printf("Error en la apertura del archivo - Fin de Evangelion\n");
        getch();
        exit(1);
    }
    cont_reg = 0;
    pos_bus = 0;
    while((long_reg = toma_reg(fd,buffreg))> 0)
    {
        printf("Registro %d\n", ++cont_reg);
        cont_campos = 0;
        while((pos_bus= toma_campo(campo,buffreg,pos_bus,long_reg))> 0)
            printf("\tCampo %d: %s\n",++cont_campos,campo);
            getch();
    }
    printf("Fin del archivo");
    getch();
    close(fd);
}

int toma_reg(int fd,char buffreg[])
{
    int long_reg;
    if(read(fd,&long_reg,2) == 0)               //Longitud del registro
        return (0);                             //Devuelve 0 si EOF
    long_reg = read(fd,buffreg,long_reg);       //Lee el registro
    return (long_reg);
}
int toma_campo(char campo[], char buffreg[],short pos_bus,short long_reg)
{
    short cpos=0;                               // Posicion en el arreglo "campo"
    if(pos_bus = long_reg)                      // si no hay mas campos que leer
        return(0);                              // devuelve pos_bus de 0

    /* Ciclo de recopilacion */
    while((pos_bus < long_reg) && (campo[cpos++]=buffreg[pos_bus++])!= DELIM_CAR);
    if(campo[cpos - 1] == DELIM_CAR)            // Si el ultimo caracter es un campo
        campo[--cpos] = '\0';                   // Delimitador, reemplaze con nulo
    else
        campo[cpos] ='\0';                      // Asegurese de que el campo no termina con nulo

    return(pos_bus);                            // Devuelve la posicion de inicio del siguiente campo
}
