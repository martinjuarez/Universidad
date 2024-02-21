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
        "Nombre:",
        "Apellido Paterno:",
        "Apellido Materno:",
        "Sexo(F|M):",
        "Estado:",
        "Dia de nacimiento(DD):",
        "Mes de nacimiento(MM):",
        "Anio de nacimiento(AAAA):",
        ""
    };
void main()
{
    char respuestas[50];
    char temp[50];
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
    printf("\n\n%s",solicitud[0]);
    gets(respuestas);
    nomarch[0] = respuestas[0];
    nomarch[1] = respuestas[1];
    while(strlen(respuestas)>0)
    {
        buffreg[0]='\0';
        temp[0]='\0';
        campo_a_buffreg(temp,respuestas);
        for(i=1;*solicitud[i]!='\0';i++)
        {
            printf("%s",solicitud[i]);
            gets(respuestas);
            switch(i){
                case 1:
                    nomarch[2] = respuestas[0];
                    nomarch[3] = respuestas[1];
                    break;
                case 2:
                    nomarch[4] = respuestas[0];
                    break;
                case 3:
                    nomarch[5] = respuestas[0];
                    break;
                case 4:
                    nomarch[6] = respuestas[0];
                    nomarch[7] = respuestas[1];
                    break;
                case 5:
                    nomarch[8] = respuestas[0];
                    nomarch[9] = respuestas[1];
                    strcat(respuestas,"/");
                    strcat(temp,respuestas);
                    break;
                case 6:
                    strcat(respuestas,"/");
                    strcat(temp,respuestas);
                    break;
                case 7:
                    nomarch[10] = respuestas[0];
                    nomarch[11] = respuestas[1];
                    break;
            }
            if(i!= 5 && i != 6){
                campo_a_buffreg(temp,respuestas);
            }
        }
        campo_a_buffreg(buffreg,nomarch);
        campo_a_buffreg(buffreg,temp);
        long_reg = strlen(buffreg);
        write(fd,buffreg,long_reg);
        printf("\n\n%s",solicitud[0]);
        gets(respuestas);
    }
    close(fd);
}
