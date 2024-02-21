/* Lee secuencia de campos delimitadores */
#include <stdio.h>
#include <io.h>

#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fcntl.h>
#include <process.h>
#define SOLOLECT 0
#define DELIM_CAR '|'
int leecampo(int fd,char cad[]);

void main()
{
    int fd,n;
    char cad[30],c;
    char nomarch[15];
    int cont_campos;
    printf("\n\tCon este programa puedes ver los datos de tus amigos\n");
    printf("\n\tque va han sido guardados en un archivo.\n");
    printf("\t     Digita el nombre del archivo que quieres ver:");
    gets(nomarch);
    if((fd=open(nomarch,SOLOLECT)) <0)
    {
        printf("Error en la apertura del archivo\n");
        exit(1);
    }
        cont_campos = 0;
        printf("\n\t Los amigos que se encuentran en este archivo son:\n");
        while((n=leecampo(fd,cad))>0)
    printf("\t\t Campo # %3d: %s\n",++cont_campos,cad);
    getch();
    close(fd);
}


int leecampo(int fd,char cad[])
{
    int i;
    char c;

    i=0;
    while(read(fd,&c,1)>0 && (c!= DELIM_CAR))
        cad[i++]=c;
    cad[i]='\0';
    return(i);
}
