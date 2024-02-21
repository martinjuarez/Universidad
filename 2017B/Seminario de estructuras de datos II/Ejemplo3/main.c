/* Crea el archivo de nombre y direcciones empleando un campo de longitud fija adelante de cada registro*/

#include <stdio.h>
#include <io.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define DELIM_CAD "|"
#define PMODE 0755
#define TAM_MAX_REG 512
#define campo_a_buffreg(br,cad) strcat(br,cad); strcat(br,DELIM_CAD);


char buffreg[TAM_MAX_REG + 1];
char *solicitud[]=
    {
        "\n\tDigita los datos que se te piden, o <ENTER> para salir\n"
        "Apellido:",
        "Nombre:",
        "Direccion:",
        "Ciudad:",
        "Estado:",
        "Cod. Post.:",
        "" /* Cade nusda para terminar el ciclo de solicitud*/
    };
void main()
{
    char respuestas[50];
    char nomarch[15];
    int fd,i;
    int long_reg;
    system("cls");
    printf("\n\n\tProporcione el nombre del archivo que quiere crear:");
    gets(nomarch);
    if((fd=creat(nomarch,PMODE))<0)
    {
        printf("error en apertura del archivo, fin del programa :v");
        exit(1);
    }
    printf("\n\n%s",solicitud[0]);
    gets(respuestas);
    while(strlen(respuestas)>0)
    {
        buffreg[0]='\0';
        campo_a_buffreg(buffreg,respuestas);
        for(i=1;*solicitud[i]!='\0';i++)
        {
            printf("%s",solicitud[i]);
            gets(respuestas);
            campo_a_buffreg(buffreg,respuestas);
        }
        /*Escribe la longitud del registro y el cnontenido del buffer */
        long_reg=strlen(buffreg);
        write(fd,&long_reg,2);
        write(fd,buffreg,long_reg);

        /*Se prepara para los siguientes datos*/
        printf("\n\n%s",solicitud[0]);
        gets(respuestas);
    }
    //Cierre el archivo antes de terminar
    close(fd);
}
