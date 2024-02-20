#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <Math.h>
#include <stdlib.h>
#include <stdio.h>
#include "cifradohill.h"

#define DIMENSION 3

using namespace std;

char alf[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int Cifrado::inversoMultiplicativo(int n, int a){
     int d,x,y,inver;
	 int *p1=&d;
	 int *p2=&x;
	 int *p3=&y;
     metodoEuclidesExtendido(a,n,p1,p2,p3);
     if(d>1){
     	return 0;
     }
     else{
     	if(x<0){
     		inver=n+x;
     	}
     	else{
     		inver=x;
     	}
     }
     return(inver);
}

int Cifrado::matrizPrincipal(char letra, char matriz[5][5]){
        for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
        if(letra == matriz[i][j]){
                  return 1;
            }
       }
    }
    return -1;
}

int Cifrado::metodoCalcularDeterminante(int a[][26], int orden){
    int det=0;
    int aux1[26][26];
    int aux2[26][26];


	if(orden==1)
   	return a[0][0];

   for(int i=0;i<orden;i++)
     {
      if(i%2==0)
       {for(int y=0;y<orden;y++)
       	 for(int x=0;x<orden;x++)
          	if(x<i)
      	 		aux1[x][y]=a[x][y+1];
            else
               aux1[x][y]=a[x+1][y+1];

      	 det=det+a[i][0]*metodoCalcularDeterminante(aux1,orden-1);
       }
      else
       {for(int y=0;y<orden;y++)
       	 for(int x=0;x<orden;x++)
          	if(x<i)
      	 		aux2[x][y]=a[x][y+1];
            else
               aux2[x][y]=a[x+1][y+1];

      	det=det-a[i][0]*metodoCalcularDeterminante(aux2,orden-1);
       }
      }
   return det;
}

int Cifrado::metodoInvertible(int matriz[][26], int d){
    int det=metodoCalcularDeterminante(matriz,d);
	cout<<"\tDeterminante: "<<det<<endl;
	if(det<0){
		det=-1*det;
	}

	if(det%2==0 || det%13==0){
		return 0;
	}
	else{
		return 1;
	}
}

double Cifrado::laDeterminante(double matriz[][26], int d){
    double det;
    if(d==2)
    {
        det=(matriz[0][0]*matriz[1][1])-(matriz[1][0]*matriz[0][1]);
        return det;
    }
    double suma=0;
    for(int i=0; i<d; i++){
    double nm[d-1][26];
        for(int j=0; j<d; j++){
            if(j!=i){
                for(int k=1; k<d; k++){
                int indice=-1;
                if(j<i)
                indice=j;
                else if(j>i)
                indice=j-1;
                nm[indice][k-1]=matriz[j][k];
                }
            }
        }
        if(i%2==0)
        suma+=matriz[i][0] * laDeterminante(nm,(d-1));
        else
        suma-=matriz[i][0] * laDeterminante(nm,(d-1));
    }
    return suma;
}

bool Cifrado::validarPalabra(char palabra[], int n){
    int cont = 0;
	cout<<"\t"<<palabra<<endl;
	cout<<"\t"<<n<<endl;
	for(int i=0;i<n;i++){
		if(palabra[i]!=49 || palabra[i]!=48){
			return false;
		}
	}
	return true;
}

void Cifrado::metodoEuclidesExtendido(int a, int b, int* q1, int* q2, int* q3){
    int d,x,y,x1,x2,y1,y2,q,r;
    if(b==0){
        d=a;
        x=1;
        y=0;
    }
    x1=0;
    x2=1;
    y1=1;
    y2=0;
    while(b>0){
        q=a/b;
        r=a-(q*b);
        x=x2-(q*x1);
        y=y2-(q*y1);
        a=b;
        b=r;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }
    d=a;
    x=x2;
    y=y2;
    *q1=d;
    *q2=x;
    *q3=y;
}

void Cifrado::llenadoDeMatriz(char clave[], char matriz[5][5]){
    int fila=0;
    int columna=0;
    int aux;
    for(int i=0;i<strlen(clave);i++){
         aux = matrizPrincipal(clave[i],matriz);
         if(aux==-1&&clave[i]!=106){
              if(columna==5){
                  fila++;
                  columna=0;
              }
		        matriz[fila][columna]=clave[i];
		        columna++;
         }
    }
    for(int j=0;j<strlen(alf);j++){
        aux = matrizPrincipal(alf[j],matriz);
        if(aux==-1&&alf[j]!=106){
              if(columna==5){
                  fila++;
                  columna=0;
              }
		        matriz[fila][columna]=alf[j];
		        columna++;
         }
    }
}

void Cifrado::acomodarMensaje(char m2[], char m[]){
    	int j=0;
	for(int i=0;i<strlen(m);i++){
		if(m[i]!=32){
		   m2[j]=m[i];
		   j++;
		}
	}
	m2[j]='\0';
	int i=0;
	j=1;
	while(j<=strlen(m2)){
		if(m2[i]==m2[j]){
			for(int k=strlen(m2)+1;k>j;k--){
				m2[k]=m2[k-1];
			}
			m2[j]='x';
		}
		i=i+2;
		j=j+2;
	}

	if(strlen(m2)%2!=0){
		m2[strlen(m2)+1]='\0';
		m2[strlen(m2)]='x';
	}
}

void Cifrado::quitarLosEspacios(char m2[], char m[], int d){
    int j=0;
	for(int i=0;i<strlen(m);i++){
		if(m[i]!=32){
		   m2[j]=m[i];
		   j++;
		}
	}
	m2[j]='\0';

	while(strlen(m2)%d!=0){
		m2[strlen(m2)+1]='\0';
		m2[strlen(m2)]='x';
	}
}

void Cifrado::seMultiplica(int matriz[][26], int indices[], int d){
    int indices_aux[d];
	for(int i=0;i<d;i++){
		int aux=0;
		for(int j=0;j<d;j++){
			aux=(matriz[i][j]*indices[j])+aux;
		}
		indices_aux[i]=aux%26;
	}
	for(int i=0;i<d;i++){
		indices[i]=indices_aux[i];
	}
}

void Cifrado::matrizDeCofactores(double matriz[][26], int d){
    double nm[d][d];
    for(int i=0;i<d;i++) {
        for(int j=0;j<d;j++) {
            double det[d-1][26];
            double detValor;
            for(int k=0;k<d;k++) {
                if(k!=i) {
                    for(int l=0;l<d;l++) {
                        if(l!=j) {
                        int indice1=k<i ? k : k-1 ;
                        int indice2=l<j ? l : l-1 ;
                        det[indice1][indice2]=matriz[k][l];
                        }
                    }
                }
            }
            detValor=laDeterminante(det,d-1);
            nm[i][j]=detValor * (double)pow(-1, i+j+2);
        }
    }
    for(int i=0;i<d;i++)
        for(int j=0;j<d;j++)
   			 matriz[i][j]=nm[i][j];
}

void Cifrado::matrizTranspuesta(double matriz[][26], int d){
        double nuevam[d][d];
    for(int i=0; i<d; i++)
    {
        for(int j=0; j<d; j++)
            nuevam[i][j]=matriz[j][i];
    }
    for(int i=0;i<d;i++)
        for(int j=0;j<d;j++)
   			 matriz[i][j]=nuevam[i][j];
}

void Cifrado::matrizAdjunta(double matriz[][26], int d){
    matrizDeCofactores(matriz, d);
    matrizTranspuesta(matriz, d);
}

void Cifrado::matrizInversa(double matriz[][26], int d){
	double det;
	det= 1/ laDeterminante(matriz,d);
	matrizAdjunta(matriz,d);
}

void Cifrado::seMultiplicaLaMatriz(double n, double matriz[][26], int d){
        for(int i=0;i<d;i++)
        for(int j=0;j<d;j++)
        matriz[i][j]*=n;
}

void Cifrado::encryptHill()
{
	char m[100];
	fflush(stdin);
	cout<<"\tIngrese mensaje a cifrar:";
	cin.getline(m,100);
	if(DIMENSION >= 26){
        cout << "\tHay elementos dentro del cifrado que no son validos" << endl;
        cout << "\tIntentelo de nuevo";
	}else{
        cout << "\tEl cifrado contiene elementos suficientes"<< endl;
	}

	fflush(stdin);
	char m2[100];

	do{
		cout<<"\tNumero Entero: "<< DIMENSION;

	}while(DIMENSION<0||DIMENSION>25);
	quitarLosEspacios(m2,m,DIMENSION);
	cout<<"\t"<<m2<<endl;

	int matriz[26][26];
	cout<<"\tLlenado de la matriz: "<<endl;
	do{
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				do{
					matriz[i][j]=(rand()%25)+1;
                    cout<< "\t" << matriz[i][j];

				}while(matriz[i][j]<0||matriz[i][j]>25);

			}
			cout <<endl;
		}

	}while(metodoInvertible(matriz,DIMENSION)==0);

	int indices[100];
	int k=0;
	int l=0;

	for(int i=0; i<strlen(m2);i++){
			for(int j=0;j<strlen(alf);j++){
				if(m2[i]==alf[j]){
					 indices[k]=j;
				}
			}
			k++;
			if(k%DIMENSION==0){
				seMultiplica(matriz,indices,DIMENSION);
				for(int i=0;i<DIMENSION;i++){
					m2[l]=alf[indices[i]];
					l++;
				}
				k=0;
			}
	}

	cout<<"\tEl mensaje cifrado es:";
	int conta=0;
	for(int i=0;i<strlen(m2);i++){
		cout<<""<<m2[i];
		conta++;
		if(conta%DIMENSION==0){
			cout<<" ";
		}
	}
	cout<<endl<<endl;
}

void Cifrado::desEncryptHill()
{
	char m[100];
	fflush(stdin);
	cout<<"\tIngrese mensaje a descifrar:";
	cin.getline(m,100);
		if(DIMENSION >= 26){
        cout << "\tHay elementos dentro del cifrado que no son validos" << endl;
        cout << "\tIntentelo de nuevo";
	}else{
        cout << "\tEl cifrado contiene elementos suficientes"<< endl;
	}

	fflush(stdin);
	char m2[100];

	do{
		cout<<"\tIngrese un numero entero : "<< DIMENSION;

	}while(DIMENSION<0||DIMENSION>25);
	quitarLosEspacios(m2,m,DIMENSION);

	double matriz[26][26];
	cout<<"\tLlenado de la matriz: "<<endl;

		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				do{
					cin>>matriz[i][j];
					cout<<"\tIngrese elemento ["<<i<<"]["<<j<<"]:"<<matriz[i][j]<<endl;
				}while(matriz[i][j]<0||matriz[i][j]>25);
			}
		}

	int matriz_aux[26][26];
	for(int i=0;i<DIMENSION;i++){
        for(int j=0;j<DIMENSION;j++){
				matriz_aux[i][j]=(int)matriz[i][j];
			}
		}

	int deter = metodoCalcularDeterminante(matriz_aux,DIMENSION);
	deter = inversoMultiplicativo(26,deter%26);
	matrizInversa(matriz,DIMENSION);
	for(int i=0;i<DIMENSION;i++)
		for(int j=0;j<DIMENSION;j++){
			matriz[i][j]=matriz[i][j]*deter;
		}

	int matriz_aux2[26][26];
	for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				matriz_aux2[i][j]=(int)matriz[i][j];
			}
		}
	for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				if(matriz_aux2[i][j]<0){
					while(matriz_aux2[i][j]<0){
						matriz_aux2[i][j]=matriz_aux2[i][j]+26;
					}
				}
				else{
					matriz_aux2[i][j]=matriz_aux2[i][j]%26;
				}
			}
	}
	cout<<endl;

	for(int i=0;i<DIMENSION;i++)
		for(int j=0;j<DIMENSION;j++)
			{
				cout<<"\t"<<matriz_aux2[i][j];
				if(j==DIMENSION-1){
					cout<<endl;
				}
			}

	int indices[100];
	int k=0;
	int l=0;
	for(int i=0; i<strlen(m2);i++){
			for(int j=0;j<strlen(alf);j++){
				if(m2[i]==alf[j]){
					 indices[k]=j;

				}
			}
			k++;
			if(k%DIMENSION==0){
				seMultiplica(matriz_aux2,indices,DIMENSION);
				for(int i=0;i<DIMENSION;i++){
					m2[l]=alf[indices[i]];
					l++;
				}
				k=0;
			}
	}
	cout<<"\tLa palabra des-cifrada es:";
	int conta=0;
	for(int i=0;i<strlen(m2);i++){
		cout<<m2[i];
		conta++;

	 }
	cout<<endl<<endl;
}
void Cifrado::matrizLlave(){
    char org[100],cif[100];
    int indices[100],matriz[26][26];
	int k=0;
    fflush(stdin);
    cout<<"\tIngrese el mensaje original:";
    cin.getline(org,100);
    cout<<"\tIngrese el mensaje cifrado:";
    cin.getline(cif,100);
	char m2[100];
	fflush(stdin);
	quitarLosEspacios(m2,org,DIMENSION);
	for(int i=0; i<strlen(m2);i++){
			for(int j=0;j<strlen(alf);j++){
				if(m2[i]==alf[j]){
					 indices[k]=j;
				}
			}
			cout<<endl;
			k++;
	}
	k=0;
	for(int i=0;i<strlen(m2)/DIMENSION;i++){
        for(int j=0;j<DIMENSION;j++){
            matriz[i][j]=indices[k];
            cout<< "\t" <<matriz[i][j];
            k++;
        }
        cout<<endl;
    }
    cout<<endl;
	quitarLosEspacios(m2,cif,DIMENSION);
	k=0;
	for(int i=0; i<strlen(m2);i++){
			for(int j=0;j<strlen(alf);j++){
				if(m2[i]==alf[j]){
					 indices[k]=j;
				}
			}
			k++;
	}
	k=0;
	for(int i=0;i<strlen(m2)/DIMENSION;i++){
        for(int j=3;j<DIMENSION*2;j++){
            matriz[i][j]=indices[k];
            cout<< "\t" <<matriz[i][j];
            k++;
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<strlen(m2)/DIMENSION;i++){
        for(int j=0;j<DIMENSION*2;j++){
            cout<< "\t" <<matriz[i][j];
            k++;
        }
        cout<<endl;
    }
    /**
    if(matriz[0][0]==1){
        for(int i=1;i<strlen(m2)/DIMENSION;i++){
            for(int j=0;j<DIMENSION*2;j++){
                matriz[i][j]=matriz[i][j]-matriz[i][j]*matriz[0][j];
            }
        }
    }else if(matriz[0][0]%2!=0 && matriz[0][0]%13!=0){
        inversoMultiplicativo(26,matriz[0][0]%26);
        for(int i=1;i<strlen(m2)/DIMENSION;i++){
            for(int j=0;j<DIMENSION*2;j++){
                matriz[i][j]=matriz[i][j]-matriz[i][j]*matriz[0][j];
            }
        }
    }else{
        bool bandera=false;
        int j=0;
        int opc;
        int aux;
        do{
            if(matriz[j][0]==1){
                bandera=true;
                opc=1;
            }else if(matriz[0][j]%2==0 && matriz[0][j]%13!=0){
                bandera=true;
                opc=2;
            }else{
                j++;
            }
        }while(bandera==true);
        if(opc==1){
            for(int i=0;i<DIMENSION*2;i++){
                aux=matriz[j][i];
                matriz[j][i]=matriz[0][i];
                matriz[0][i]=aux;
            }
        }else if(opc==2){
            for(int i=0;i<DIMENSION*2;i++){
                aux=matriz[j][i];
                matriz[j][i]=matriz[0][i];
                matriz[0][i]=aux;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<strlen(m2)/DIMENSION;i++){
        for(int j=0;j<DIMENSION*2;j++){
            cout<< "\t" <<matriz[i][j];
            k++;
        }
        cout<<endl;
    }*/
}
void Cifrado::pantallaPrincipal()
{
    system("color 9f");
    char opc;
    char opc2;
    char opc3;
	do{
		cout<<"\t-Menu Principal-:"<<endl;
		cout<<"\t(1). Metodo de Hill"<<endl;
		cout<<"\t(2). Salir"<<endl;
		cout<<"\tEliga una Opcion:";
		cin>>opc;

		switch(opc){
			case '1': system("cls");
					do{
						cout<<"\t-Menu Secundario-"<<endl;
						cout<<"\t(1). Cifrar"<<endl;
						cout<<"\t(2). Descrifrar"<<endl;
						cout<<"\t(3). Salir"<<endl;
						cout<<"\tElig una Opcion:";
						cin>>opc2;
						switch(opc2){
							case '1': encryptHill(); break;
							case '2':
							    do{
                                    cout<<"\tMenu desencriptado"<<endl;
                                    cout<<"\t(1). Con matriz llave"<<endl;
                                    cout<<"\t(2). Sin matriz llave"<<endl;
                                    cout<<"\t(3). Salir"<<endl;
                                    cout<<"\tEliga una Opcion:";
                                    cin>>opc3;
                                    switch(opc3){
                                        case '1': desEncryptHill(); break;
                                        case '2': matrizLlave(); break;
                                    }
                                }while(opc3!='3');
                                system("cls");
                                break;
						}
					}while(opc2!='3');
					system("cls");
					break;

		}
	}while(opc!='2');
	getch();
}
