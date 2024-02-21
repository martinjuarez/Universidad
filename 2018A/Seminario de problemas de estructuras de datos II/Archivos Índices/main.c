#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct Visit_Ent
{
    char Fecha[11];
    char Id_Sensor[9];
    int NRE;
    long Hora;
};
struct Visit_Ent A;
/* estructura autoreferenciada */
struct nodoArbol
{
    struct nodoArbol *ptrIzq;
    char Fecha[11];
    int NRR;
    struct nodoArbol *prtDer;
};
typedef struct nodoArbol NodoArbol; /* sinónimo de la estructura nodoArbol */
typedef NodoArbol *ptrNodoArbol; /* sinónimo de NodoArbol* */

/* prototipos */

void insertaNodo(ptrNodoArbol *ptrArbol, int valor,char value[]);
void inOrden(ptrNodoArbol ptrArbol);
void preOrden(ptrNodoArbol ptrArbol,int fd);
void postOrden(ptrNodoArbol ptrArbol);
void inOrdenC(ptrNodoArbol ptrArbol);
void leerIndice(ptrNodoArbol ptrArbol,int fd);
/* la función main comienza la ejecución del programa */
int main()
{
     int des,des2;
     int cont;
     ptrNodoArbol ptrRaiz = NULL; /* árbol inicialemnte vacío */
     des=open("C:\\Users\\marti\\Desktop\\Archivos Índices\\archivo1.txt",2);
     des2=creat("C:\\Users\\marti\\Desktop\\Archivos Índices\\Indice.txt",0755);
     if(des2<0)
        {
            printf("Fin del programa\n");
            exit(1);
        }
     if(des>0)
     {
         cont=0;
             while(read(des,&A,sizeof(A))>0)
             {
                 insertaNodo(&ptrRaiz,cont,A.Fecha);
                 cont=cont+1;
             }
             //printf("Orden por registro de entrada\n");
             /* recorre el árbol en preorden */
             printf("El recorrido en preorden(Arbol) es:\n");
             preOrden(ptrRaiz,des2);
             close(des2);
             des2=open("C:\\Users\\marti\\Desktop\\Archivos Índices\\Indice.txt",2);
             ptrNodoArbol temp = NULL;
             leerIndice(temp,des2);
             /* recorre el árbol en in inorden */
             //printf("\nEl recorrido inorden es:\n");
             //inOrden(ptrRaiz);
             /* recorre el árbol en postOrden */
             //printf("\nEl recorrido en postOrden es:\n");
             //postOrden(ptrRaiz);
     }
     else
        printf("Error");
    close(des);
     return 0;
}
/* inserta un nodo dentro del árbol */
void insertaNodo( ptrNodoArbol *ptrArbol, int valor,char value[])
{
    /* si el árbol está vacío */
    if (*ptrArbol == NULL)
    {
        *ptrArbol = malloc(sizeof(NodoArbol));
        /* si la memoria está asignada, entonces asigna el dato */
        if (*ptrArbol != NULL)
        {
            strcpy((*ptrArbol)->Fecha,value);
            (*ptrArbol)->NRR = valor;
            (*ptrArbol)->ptrIzq = NULL;
            (*ptrArbol)->prtDer = NULL;
        }else{
            printf("no se inserto %s. No hay memoria disponible.n", value);
        }
    }else{
        /* el dato a insertar es menor que el dato en el nodo actual */
        if (strcmp(A.Fecha,(*ptrArbol)->Fecha)<0){
            insertaNodo(&((*ptrArbol)->ptrIzq), valor,value);
        }else if(strcmp(A.Fecha,(*ptrArbol)->Fecha)>0){
            insertaNodo(&((*ptrArbol)->prtDer), valor,value);
        }else{
            insertaNodo(&((*ptrArbol)->ptrIzq), valor,value);
        }
    }
}
/* comienza el recorrido inorden del árbol */
void inOrden(ptrNodoArbol ptrArbol)
{
    /* si el árbol no está vacío, entonces recórrelo */
    if(ptrArbol != NULL)
    {
        inOrden(ptrArbol->ptrIzq);
        printf("%3d ", ptrArbol->NRR);
        printf("%s\n", ptrArbol->Fecha);
        inOrden(ptrArbol->prtDer);
    }
}
/* comienza el recorrido preorden del árbol */
void preOrden(ptrNodoArbol ptrArbol,int fd)
{
    /* si el árbol no está vacío, entonces recórrelo */
    if(ptrArbol != NULL)
    {
        printf("%s ", ptrArbol->Fecha);
        printf("%3d\n", ptrArbol->NRR);
        /*write(fd,&ptrArbol->Fecha,sizeof(ptrArbol->Fecha));
        write(fd,&ptrArbol->NRR,sizeof(ptrArbol->NRR));*/
        write(fd,&ptrArbol,sizeof(ptrArbol));
        preOrden(ptrArbol->ptrIzq,fd);
        preOrden(ptrArbol->prtDer,fd);
    }
 /*
 if (ptrArbol != NULL) {
 printf("%3d ", ptrArbol->NRR);
 printf("%s\n", ptrArbol->Fecha);
 preOrden(ptrArbol->ptrIzq);
 preOrden(ptrArbol->prtDer);
 }*/
        //close(des2);
 //}
}
/* comienza el recorrido postOrden del árbol */
void postOrden(ptrNodoArbol ptrArbol)
{
    /* si el árbol no está vacío, entonces recórrelo */
    if(ptrArbol != NULL)
    {
        postOrden(ptrArbol->ptrIzq);
        postOrden(ptrArbol->prtDer);
        printf("%3d ", ptrArbol->NRR);
        printf("%s\n", ptrArbol->Fecha);
    }
}
void leerIndice(ptrNodoArbol ptrArbol,int fd)
{
    if(fd>0)
    {
        printf("El recorrido en preorden(Lectura indice) es:\n");
        while(read(fd,&ptrArbol,sizeof(ptrArbol))>0)
            {
                printf("%s ", ptrArbol->Fecha);
                printf("%3d\n", ptrArbol->NRR);
            }
    }
}
///0 es igual,numero negativo si cadena1 es menor a cadena2, numero positivo mayor a 0 si cadena1 es mayor que cadena 2
///Pagina del codigo original del arbol:  https://www.codejobs.biz/es/blog/2013/07/02/estructura-de-datos-en-c-arboles
