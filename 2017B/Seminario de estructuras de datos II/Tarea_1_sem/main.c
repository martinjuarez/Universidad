#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define MAX 20

struct Alumno{
	int codigo;
	char nombre[30];
	char direccion[30];
	int edad;
	char carrera[15];
	char sexo;
}alumnos[MAX];

int main()
{
    int opc,comp;
    int cont = 0;
	do
    {
        printf("1.- Alta \n");
        printf("2.- Baja \n");
        printf("3.- Consulta \n");
        printf( "4.- Modificacion \n");
        printf("5.- Salir \n");
        scanf("%d",&opc);
        fflush(stdin);
        printf("\n");
        switch(opc)
        {
            case 1:
                if(cont<=MAX){
                	printf("Codigo:\n");
                	scanf("%d",&alumnos[cont].codigo);
                	fflush(stdin);
                	printf("Nombre:\n");
                	gets(alumnos[cont].nombre);
                	printf("Direccion:\n");
                	gets(alumnos[cont].direccion);
                	printf("Edad:\n");
                	scanf("%d",&alumnos[cont].edad);
                	fflush(stdin);
                	printf("Carrera:\n");
                	gets(alumnos[cont].carrera);
                	printf("Sexo(F,M):\n");
                	scanf("%c",&alumnos[cont].sexo);
                	printf("\n");
				}
				cont++;
                break;
            case 2:
                if(cont == 0){
                    printf("El registro ya esta vacio\n");
                }else{
                    printf("Dame el regitro que quieras eliminar:\n");
                    scanf("%d",&comp);
                    fflush(stdin);
                    comp--;
                    if(comp > cont){
                        printf("El registro no existe\n");
                    }else{
                        while(comp < cont){
                            alumnos[comp].codigo = alumnos[1+comp].codigo;
                            strcpy(alumnos[comp].nombre,alumnos[1+comp].nombre);
                            strcpy(alumnos[comp].direccion,alumnos[1+comp].direccion);
                            alumnos[comp].edad = alumnos[1+comp].edad;
                            strcpy(alumnos[comp].carrera,alumnos[1+comp].carrera);
                            alumnos[comp].sexo = alumnos[1+comp].sexo;
                            ++comp;
                        }
                        printf("-------baja\n");
                        printf("\n");
                        cont--;
                    }
                }
                break;
            case 3:
                    printf("1.- 1 por 1 \n");
                    printf("2.- Mostrar todo en pantalla \n");
                    scanf("%d",&opc);
                    fflush(stdin);
                    printf("\n");
                    switch (opc){
                    case 1:
                        opc=0;
                        printf("Dame el codigo:\n");
                        scanf("%d",&comp);
                        fflush(stdin);
                        while(comp != alumnos[opc].codigo && opc < MAX){
                            opc++;
                        }
                        if(opc == MAX){
                            printf("\nError ese codigo no existe");
                            printf("\n");
                        }else{
                            printf("Codigo: %d\n",alumnos[opc].codigo);
                            printf("Nombre: %s\n",alumnos[opc].nombre);
                            printf("Direccion: %s\n",alumnos[opc].direccion);
                            printf("Edad: %d\n",alumnos[opc].edad);
                            printf("Carrera: %s\n",alumnos[opc].carrera);
                            printf("Sexo: %c\n",alumnos[opc].sexo);
                            printf("\n");
                        }
                        break;
                    case 2:
                        if(cont == 0){
                            printf("No hay registros\n");
                        }else{
                            opc=0;
                            while(opc < cont){
                                printf("Registro %d.\n",opc+1);
                                printf("Codigo: %d\n",alumnos[opc].codigo);
                                printf("Nombre: %s\n",alumnos[opc].nombre);
                                printf("Direccion: %s\n",alumnos[opc].direccion);
                                printf("Edad: %d\n",alumnos[opc].edad);
                                printf("Carrera: %s\n",alumnos[opc].carrera);
                                printf("Sexo(F,M): %c\n",alumnos[opc].sexo);
                                printf("\n");
                                opc++;
                            }
                        }
                        break;
                    default:
                        printf("Error\n");
                        break;
                    }
                break;
            case 4:
                if(cont == 0){
                    printf("El registro esta vacio\n");
                }else{
                    printf("Dame el regitro que quieras modificar:\n");
                    scanf("%d",&comp);
                    fflush(stdin);
                    comp--;
                    printf("\n");
                    if(comp > cont){
                        printf("El registro no existe\n");
                        printf("\n");
                    }else{
                        printf("1.- Codigo\n");
                        printf("2.- Nombre\n");
                        printf("3.- Direccion\n");
                        printf("4.- Edad\n");
                        printf("5.- Carrera\n");
                        printf("6.- Sexo\n");
                        printf("cual campo quieres modificar: ");
                        scanf("%d",&opc);
                        fflush(stdin);
                        printf("\n");
                        switch(opc){
                        case 1:
                            printf("Codigo:\n");
                            scanf("%d",&alumnos[comp].codigo);
                            fflush(stdin);
                            printf("\n");
                            break;
                        case 2:
                            printf("Nombre:\n");
                            gets(alumnos[comp].nombre);
                            printf("\n");
                            break;
                        case 3:
                            printf("Direccion:\n");
                            gets(alumnos[comp].direccion);
                            printf("\n");
                            break;
                        case 4:
                            printf("Edad:\n");
                            scanf("%d",&alumnos[comp].edad);
                            fflush(stdin);
                            printf("\n");
                            break;
                        case 5:
                            printf("Carrera:\n");
                            gets(alumnos[comp].carrera);
                            printf("\n");
                            break;
                        case 6:
                            printf("Sexo(F,M):\n");
                            scanf("%c",&alumnos[comp].sexo);
                            printf("\n");
                            break;
                        default:
                            printf("Error");
                            printf("\n");
                            break;
                        }
                    }
                }
                break;
            case 5:
                break;
            default:
                printf("Error\n");
                break;
        }
    }while(opc!=5);
    return 0;
}

