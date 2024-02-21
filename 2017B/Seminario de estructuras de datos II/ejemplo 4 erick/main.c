#include <io.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fcntl.h>
#include <process.h>

#define SOLOLECT 0
#define DELIM_CAR "|"

int leecampo(int fd, char cad[]);

int main ()
{
    int fd,n;
    char cad[30];
    char nomarch[15];
    int cont_campos;

    system("cls");
    printf("\n\t Con Este Programa puedes ver los datos de los que son tus amigos");
    printf("\n\t que ya han sido guardados en un archivo. \n");
    printf("\t Digita el nombre del archivo que quieres ver:");
    gets(nomarch);
    if((fd=open(nomarch,SOLOLECT))<0)
    {
        printf("Errar En La Apertura Del Archivo");
        exit(1);
        //
    }
    cont_campos=0;
    printf("\n\t Los Amigos Que Se Encuentran En Este Archivo Son:\n\t");
    while((n=leecampo(fd,cad))>0)
    {

        printf("\t\t Campo # %3d: %s\n",++cont_campos,cad);
        getch();
        close(fd);
    }
}

int leecampo(int fd, char cad[])
{
    int i;
    char c;

    i=0;
    while((read(fd,&c,1)>0) && (c!=DELIM_CAR))
        cad[i++]=c;
    cad[i]='\0';
    return(1);
}
