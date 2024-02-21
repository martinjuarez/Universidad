#include <stdio.h>
#include <io.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define DELIM_CAD '|'
#define PMODE 0755
#define TAM_MAX_REG 512
#define campo_a_buffreg(br,cad) strcat(br,cad); strcat(br,DELIM_CAD);

char buffreg[TAM_MAX_REG + 1];
static char *solicitud[] = { "\n\nApellido:    ",
     "Nombre:      ",
     "Direccion:   ",
     "Ciudad:      ",
     "Estado:      ",
     "Cod. Post.:  ",
     "Telefono:    ",
     "Cumpleanos:  ",
     "" };

void main()
{
    int op;
    char respuestas[50];
    char nomarch[15];
    int fd,i;
    int long_reg;
    printf("\n\n\tProporcione el nombre del archivo que quiere crear:");
    gets(nomarch);
    if((fd=creat(nomarch,PMODE))<0)
    {
        printf("error en apertura del archivo, fin del programa :v");
        exit(1);
    }
    do{
        printf ("\n\n\n AGENDA DE MIS AMIGOS FAVORITOS \n ");
        printf("\n\n OPCIONES:\n\n ");
        printf("\n1. AGREGAR UN NUEVO AMIGO\n");
        printf("\n2. EXTRAER UN AMIGO PARA ACTUALIZAR SUS DATOS\n");
        printf("\n3. BORRAR UN AMIGO LOGICAMENTE\n");
        printf("\n4. BORRAR UN AMIGO FISICAMENTE\n");
        printf("\n5. SALIR DEL PROGRAMA\n\n");
        printf("DIGITA EL NUMERO DE TU ELECCION: ");
        scanf("%d",&op);
        fflush(stdin);
        switch(op){
            case 1:
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
                    ///strcat(buffreg,"@");
                    write(fd,buffreg,long_reg);
                }
                break;
            case 2:
                printf("Opcion 2\n");
                break;
            case 3:
                printf("Opcion 3\n");
                break;
            case 4:
                printf("Opcion 4\n");
                break;
            case 5:
                break;
        }
    }while(op != 5);
    close(fd);
}
