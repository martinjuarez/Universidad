#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define DELIM_CAD "|"
#define PMODE      0755
#define saca_cad(fd, cad)  write((fd),(cad),strlen(cad)); \
                    write((fd), DELIM_CAD,1);



void main()
{
    char nombre[30],apellido[30],direccion[30],ciudad[20],nomarch[15];
    char estado[15],codigo[9];
    int fd;
    printf("\n\t Este programa guarda los datos de tus amigos favoritos.\n");
    printf("\n\t\tProporciona el nombre del archivo que quiera crear:");
    gets(nomarch); /**/

    if((fd=creat(nomarch, PMODE))<0)
    {
        printf("fin del programa\n");
        exit(1);
    }
    printf("\n\t     Digita los datos de tu amigo y presiona <ENTER>");
    printf("\n\n\tSi quieres guardar datos de mas amigos solo digitalo.\n");
    printf("\n\t         Si ya no quieres solo presiona <ENTER>.\n\nNombre: ");
    gets(nombre);
    saca_cad(fd,nombre);
    while (strlen(nombre)>0)
    {
        printf("Apellido: ");
        gets(apellido);
        saca_cad(fd,apellido);
        printf("Direccion: ");
        gets(direccion);
        saca_cad(fd,direccion);
        printf("Ciudad: ");
        gets(ciudad);
        saca_cad(fd,ciudad);
        printf("Estado: ");
        gets(estado);
        saca_cad(fd,estado);
        printf("Postal: ");
        gets(codigo);
        saca_cad(fd,codigo)

        printf("\n Nombre: ");
        gets(nombre);
        saca_cad(fd,nombre);
    }
    printf("\n\n\n Fin del archivo amigos");
    getch();
    close(fd);

}
