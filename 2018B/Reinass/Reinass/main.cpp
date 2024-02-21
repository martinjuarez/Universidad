#include <iostream>
#define t 4
using namespace std;
void rellenar (int tablero[t][t], int contador[t]){
    int i=0,j=0;
    while (i<t){
        while (j<t){
            tablero[i][j]=0;
            j++;
        }
        i++;
        j=0;
    }
    i=0;
    while(i<t){
        contador[i]=0;
        i++;
    }
}
int main()
{
    cout<<"Tablero 4x4 todas las posibilidades de poner reinas"<<endl;
    cout<<endl;
    int g=0,h=0,i=0,j=0;
    int tablero[t][t];
    int contador[t];
    bool bandera = false;
    rellenar(tablero,contador);
    while(i<t){
        while(j<t){
            if(j==0 && i==0){
                tablero[i][j]=1;
                bandera=true;
                contador[h]=1;
                cout<<"1 ";
                h++;
            }else if(j>0 && i==0){
                tablero[i][j]=1;
                bandera=true;
                while(h<j){
                    cout<<"0 ";
                    h++;
                }
                contador[h]=1;
                cout<<"1 ";
                h++;
            }else{
                while(g<i){
                    while(h<t){
                        cout<<"0 ";
                        h++;
                    }
                    h=0;
                    cout<<endl;
                    g++;
                }
                while(h<j){
                    cout<<"0 ";
                    h++;
                }
                tablero[i][j]=1;
                bandera=true;
                contador[h]=1;
                cout<<"1 ";
                h++;
            }
            while(g<t){
                while(h<t){
                    if(g==0){
                        if(h==0){
                            if(tablero[g][h+1]==0 && tablero[g+1][h+1]==0 && tablero[g+1][h]==0 && bandera == false){
                                tablero[g][h]=1;
                                bandera = true;
                                contador[h]=1;
                                cout<<"1 ";
                            }else{
                                cout<<"0 ";
                            }
                        }else if(h==1 || h==2){
                            if(tablero[g][h-1]==0 && tablero[g][h+1]==0 && tablero[g+1][h-1]==0 && tablero[g+1][h]==0 && tablero[g+1][h+1]==0 && bandera == false){
                                tablero[g][h]=1;
                                bandera = true;
                                contador[h]=1;
                                cout<<"1 ";
                            }else{
                                cout<<"0 ";
                            }
                        }else{
                            if(tablero[g][h-1]==0 && tablero[g+1][h-1]==0 && tablero[g+1][h]==0 && bandera == false){
                                tablero[g][h]=1;
                                bandera = true;
                                contador[h]=1;
                                cout<<"1 ";
                            }else{
                                cout<<"0 ";
                            }
                        }
                    }else if(g==1 || g==2){
                        if(h==0){
                            if(tablero[g-1][h]==0 && tablero[g-1][h+1]==0 && tablero[g][h+1]==0 && bandera == false && contador[h]==0){
                                tablero[g][h]=1;
                                bandera = true;
                                contador[h]=1;
                                cout<<"1 ";
                            }else{
                                cout<<"0 ";
                            }
                        }else if(h==1 || h==2){
                            if(tablero[g-1][h-1]==0 && tablero[g-1][h+1]==0 && tablero[g-1][h]==0 && tablero[g][h-1]==0 && tablero[g][h+1]==0 && tablero[g+1][h-1]==0 && tablero[g+1][h]==0 && tablero[g+1][h+1]==0 && bandera == false && contador[h]==0){
                                tablero[g][h]=1;
                                bandera = true;
                                contador[h]=1;
                                cout<<"1 ";
                            }else{
                                cout<<"0 ";
                            }
                        }else{
                            if(tablero[g-1][h-1]==0 && tablero[g-1][h]==0 && tablero[g][h-1]==0 && tablero[g+1][h-1]==0 && tablero[g+1][h]==0 && bandera == false && contador[h]==0){
                                tablero[g][h]=1;
                                bandera = true;
                                contador[h]=1;
                                cout<<"1 ";
                            }else{
                                cout<<"0 ";
                            }
                        }
                    }else{
                        if(h==0){
                            if(tablero[g][h+1]==0 && tablero[g-1][h+1]==0 && tablero[g-1][h]==0 && bandera == false && contador[h]==0){
                                tablero[g][h]=1;
                                bandera = true;
                                contador[h]=1;
                                cout<<"1 ";
                            }else{
                                cout<<"0 ";
                            }
                        }else if(h==1 || h==2){
                            if(tablero[g][h-1]==0 && tablero[g][h+1]==0 && tablero[g-1][h-1]==0 && tablero[g-1][h]==0 && tablero[g-1][h+1]==0 && bandera == false && contador[h]==0){
                                tablero[g][h]=1;
                                bandera = true;
                                contador[h]=1;
                                cout<<"1 ";
                            }else{
                                cout<<"0 ";
                            }
                        }else{
                            if(tablero[g][h-1]==0 && tablero[g-1][h-1]==0 && tablero[g-1][h]==0 && bandera == false && contador[h]==0){
                                tablero[g][h]=1;
                                bandera = true;
                                contador[h]=1;
                                cout<<"1 ";
                            }else{
                                cout<<"0 ";
                            }
                        }
                    }
                    h++;
                }
                cout<<endl;
                h=0;
                bandera=false;
                g++;
            }
            g=0;
            cout<<endl;
            rellenar(tablero,contador);
            j++;
        }
        j=0;
        cout<<"----------------------------------------------------"<<endl;
        i++;
    }
    return 0;
}
