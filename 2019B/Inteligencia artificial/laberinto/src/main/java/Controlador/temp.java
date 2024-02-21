package Controlador;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
// aqui se usan pruebas de codigos para su posible insercion
public class temp {
    public void leer(){
        File archivo = new File("C:\\Users\\marti\\Desktop\\mapas proyecto 1\\MapaProyecto1.txt");
        int filas=15,columnas=15,j,k,m=0,n;
        int[][] laberinto = new int[15][15];
        int[] arcoiris = new int[15];
        Boolean o = false;
        try {
            BufferedReader entrada = new BufferedReader(new FileReader(archivo));
            String lectura;
            String[] arraytemp;
            for(j=0;j<filas;j++){
                lectura = entrada.readLine();
                arraytemp= lectura.split(",");
                if(m==0){
                    arcoiris[m]=Integer.parseInt(arraytemp[m]);
                    m++;
                }
                for(k=0;k<columnas;k++){
                    laberinto[j][k]= Integer.parseInt(arraytemp[k]);
                    if(arcoiris[m-1]!=Integer.parseInt(arraytemp[k])){
                        n=0;
                        while(n<m){
                            if(arcoiris[n]==Integer.parseInt(arraytemp[k])){
                                o =true;
                                break;
                            }
                            n++;
                        }
                        if(o == false){
                            arcoiris[m]=Integer.parseInt(arraytemp[k]);
                            m++;   
                        }
                        o=false;
                    }
                }
            }
            entrada.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(temp.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(temp.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void main(String args[]){
        temp a = new temp();
        a.leer();
    }
}