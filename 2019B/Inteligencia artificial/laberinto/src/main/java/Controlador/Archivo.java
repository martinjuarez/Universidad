package Controlador;

import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.swing.JOptionPane;

/**
 *
 * @author marti
 */
public class Archivo {
    //public void leerArchivo(File archivo)
    public Boolean detectarArchivo(Matriz temp){
        //Esta funcion es la que detecta errores en el archivo
        File archivo=temp.getRuta(); //obtiene la ruta del archivo pot medio del objeto de tipo matriz
        Boolean error=false;
        Pattern pat=Pattern.compile("^(\\d+\\,)+\\d+$(\\n|\\b)?(\\b)"); // la expresion regular para detectar errores
        int filas=0, columnas=0;
        try{
            BufferedReader entrada = new BufferedReader(new FileReader(archivo));
            String lectura;
            lectura = entrada.readLine();
            String[] arraytemp = lectura.split(",");
            columnas = arraytemp.length;
            //En esta parte se leen las lineas del archivo y se separan los tipos de terreno en un arreglo por un delimitador que es una coma
            //tambien hay variables que almacenan las columnas y los renglones del archivo para la futura creacion de la matriz
            while(lectura != null){
                //aqui linea por linea se verifica que tenga buena sintaxis y que no exeda los limites de filas y columnas
                Matcher mat = pat.matcher(lectura);
                if (mat.matches() == false) {
                        JOptionPane.showMessageDialog(null, "Sintaxis invalida en el archivo");
                        error = true;
                        break;
                }
                if(columnas > 15){
                        JOptionPane.showMessageDialog(null, "El numero de columnas exedido deben ser 15 o menos");
                        error = true;
                        break;
                }
                lectura = entrada.readLine();
                if (lectura != null){
                        mat = pat.matcher(lectura);
                        arraytemp = lectura.split(",");
                }
                if (mat.matches() == false) {
                        JOptionPane.showMessageDialog(null, "Sintaxis invalida en el archivo");
                        error = true;
                        break;
                }
                if(columnas != arraytemp.length){
                        JOptionPane.showMessageDialog(null, "Numero de columnas distintas en una fila");
                        error = true;
                        break;
                }
                if(filas > 14){
                        JOptionPane.showMessageDialog(null, "Numero de filas exedido deben ser 15 o menos");
                        error = true;
                        break;
                }
                filas++;
            }
            entrada.close();
        } catch (FileNotFoundException ex){
            ex.printStackTrace();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        // Se envian las variables a el objeto de tipo matriz para guardar los resultados y usarlos en otras funciones
        temp.setColumnas(columnas);
        temp.setFilas(filas);
        return error;
    }
    //public void matrizArchivo(File archivo) throws FileNotFoundException, IOException{
    //esta funcion crea la matriz libre de errores y detecta los tipos de terreno(ids) que hay
    public void matrizArchivo(Matriz temp) throws FileNotFoundException, IOException{
        int columnas = temp.getColumnas();
        int filas = temp.getFilas();
        int j,k,m=0,n;
        int[][] laberinto = new int[filas][columnas];
        int[] arcoiris = new int[10];
        String lectura;
        String[] arraytemp; 
        Boolean o=false;
        BufferedReader entrada = new BufferedReader(new FileReader(temp.getRuta()));
        //la parte de crear una matriz es facil solo se recorre con  fors pero la de detectar nuevos ids es un poco revoltoso
        //pero es lo mismo se detecta se agrega se detecta un nuevo id lo compara haber si no ha sido agregado y si no lo agrega
        for(j=0;j<filas;j++){
            lectura = entrada.readLine();
            arraytemp = lectura.split(",");
            if(m==0){
                arcoiris[m]=Integer.parseInt(arraytemp[m]);
                m++;
            }
            for(k=0;k<columnas;k++){
                laberinto[j][k]= Integer.parseInt(arraytemp[k]);
                if(arcoiris[m-1]!= Integer.parseInt(arraytemp[k]) && m<10){
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
        temp.setIds(m);
        temp.setColores(arcoiris);
        temp.setMatriz(laberinto);
    }
    /*
    public static void main(String args[]) throws IOException{
        Archivo a = new Archivo();
        File archivo = new File("C:\\Users\\marti\\Desktop\\ia\\lab.txt");
        a.matrizArchivo(archivo);
        a.leerArchivo(archivo);
    }
    */
}