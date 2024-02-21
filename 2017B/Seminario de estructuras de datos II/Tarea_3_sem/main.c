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
int mayusculas(char cadent[],char cadsal[])
{
    while (*cadsal++ =(*cadent >='a' && *cadent <='z') ? *cadent & 0x5F : *cadent)
        cadent++;
    return(0);
}
char *solicitud[]=
{
    "\n\tDigita los datos que se te piden\n"
    "Nombre:",
    "Apellido Paterno:",
    "Apellido Materno:",
    "Sexo(F|M):",
    "Estado:",
    "Dia de nacimiento(DD):",
    "Mes de nacimiento(MM):",
    "Anio de nacimiento(AAAA):",
    "Enter para continuar\n",
    ""
};
int main()
{
    char respuestas[50];
    char temp[50];
    char nomarch[15];
    char llave[20];
    char rfc[15];
    char llave_bus[30];
    char llave_enc[30];
    int ARCH_ENT;
    int fd;
    int i;
    int r;
    int long_reg;
    int opc;
    srand(getpid());
    printf("\n\n\tProporcione el nombre del archivo que quiere crear:");
    gets(nomarch);
    if((fd=creat(nomarch,PMODE))<0)
    {
        printf("error en apertura del archivo, fin del programa :v");
        exit(1);
    }
    do{
        printf("1.-Guardar Registros\n");
        printf("2.-Buscar Registros\n");
        printf("3.-Salir Del Programa\n");
        scanf("\n%d",&opc);
        fflush(stdin);
        switch(opc){
            case 1:
                printf("\n\n%s",solicitud[0]);
                gets(respuestas);
                llave[0] = respuestas[0];
                llave[1] = respuestas[1];
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
                                llave[2] = respuestas[0];
                                llave[3] = respuestas[1];
                                break;
                            case 2:
                                llave[4] = respuestas[0];
                                break;
                            case 3:
                                llave[5] = respuestas[0];
                                break;
                            case 4:
                                llave[6] = respuestas[0];
                                llave[7] = respuestas[1];
                                break;
                            case 5:
                                llave[8] = respuestas[0];
                                llave[9] = respuestas[1];
                                strcat(respuestas,"/");
                                strcat(temp,respuestas);
                                break;
                            case 6:
                                strcat(respuestas,"/");
                                strcat(temp,respuestas);
                                break;
                            case 7:
                                llave[10] = respuestas[0];
                                llave[11] = respuestas[1];
                                break;
                            case 8:
                                r=0;
                                r=(rand()%900)+1;
                                itoa(r,respuestas,10);
                                llave[12] = respuestas[0];
                                llave[13] = respuestas[1];
                                llave[14] = respuestas[2];
                                llave[15] = '\0';
                                break;
                        }
                        if(i!= 5 && i != 6){
                            campo_a_buffreg(temp,respuestas);
                        }
                    }
                    mayusculas(llave,rfc);
                    campo_a_buffreg(buffreg,rfc);
                    campo_a_buffreg(buffreg,temp);
                    long_reg = strlen(buffreg);
                    write(fd,buffreg,long_reg);
                    break;
                }
            case 2:
                if(ARCH_ENT=open(nomarch,2)<0);{
                    printf("Error en la apertura\n");
                    exit(1);
                }
                break;
            case 3:
                break;
            default:
                printf("Esa opcion no existe\n");
                break;
        }
    }while(opc != 3);
    close(fd);
    return 0;
}
