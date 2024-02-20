#ifndef CIFRADOHILL_H_INCLUDED
#define CIFRADOHILL_H_INCLUDED

#include <iostream>

class Cifrado{
private:

    int inversoMultiplicativo(int n, int a);
    int matrizPrincipal(char letra,char matriz[5][5]);
    int metodoCalcularDeterminante(int a[][26],int orden);
    int metodoInvertible(int matriz[][26],int d);
    double laDeterminante(double matriz[][26], int d);
    bool validarPalabra(char palabra[], int n);

public:

    void metodoEuclidesExtendido(int a,int b, int *q1, int *q2, int *q3);
    void llenadoDeMatriz(char clave[],char matriz[5][5]);
    void acomodarMensaje(char m2[],char m[]);
    void quitarLosEspacios(char m2[],char m[], int d);
    void seMultiplica(int matriz[][26],int indices[],int d);
    void matrizDeCofactores(double matriz[][26], int d);
    void matrizTranspuesta(double matriz[][26], int d);
    void matrizAdjunta(double  matriz[][26], int d);
    void matrizInversa(double matriz[][26], int d);
    void seMultiplicaLaMatriz(double n, double matriz[][26], int d);
    void encryptHill();
    void desEncryptHill();
    void pantallaPrincipal();
    void matrizLlave();

};

#endif // CIFRADOHILL_H_INCLUDED
