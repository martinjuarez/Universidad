package perceptronmulticapa;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Random;

public class PerceptronMulticapa {

    int Layout[] = {2, 3, 3, 1};
    double[][][] weight = new double[Layout.length][9][9];//peso
    double[][] out = new double[Layout.length][9];//salida
    List<Double> list_w;
    Iterator iterator_w;
    //tabla de entrenamiento
    final int input1[] = {3};//entrada 1
    final int input2[] = {2};//entrada 2
    final int result[] = {5};//salida deseada

    public void print(double[] vector_w) {
        list_w = new ArrayList<>();//crea list_w que es una lista de arrays de tipo double
        for (int i = 0; i < vector_w.length; i++) {//se crea un ciclo hasta que se llegue al limite de tamaño de vector_w
            list_w.add(vector_w[i]);//se copian los elementos que tiene vector_w a list_w
        }
        iterator_w = list_w.iterator();//El iterator_w obtiene el numero de lugar de cada elemento de list_w

        out[0][0] = input1[0];//la salida out[0][0] se hace igual a la entrada input1[0]
        out[0][1] = input2[0];//la salida out[0][1] se hace igual a la entrada input2[0]
        System.out.println("out[" + 0 + "][" + 0 + "]=" + out[0][0]);//se imprime la salida out[0][0]
        System.out.println("out[" + 0 + "][" + 1 + "]=" + out[0][1]);//se imprime la salida out[0][1]
    }

    public void expand(double[] vector_w) {
        print(vector_w);//utiliza la funcion imprimi con el parametro de vector_w
        double aux;//declara una variable double llamada auxiliar
        for (int k = 1; k < vector_w.length; k++) {//se crea un ciclo hasta que se llegue al limite de tamaño de vector_w
            System.out.println("\n* Cap(k):" + k);//se imprime en que iteracion va k es decir las capas
            for (int j = 0; j < vector_w[k]; j++) {//se crea un ciclo hasta que se llegue al limite de tamaño de vector_w
                aux = 0.0;//aux se iguala a 0.0
                for (int i = 0; i < vector_w[k - 1]; i++) {//se crea un ciclo hasta que llegue al tamaño de vector_w
                    if (iterator_w.hasNext()) {//entra al if si iterator_w tiene un elemento siguiente en su posicion
                        weight[k][j][i] = (double) iterator_w.next();//hace que weight[k][j[i] en su respectiva posicion se llene con un elemento de iterator_list
                        System.out.println("weight[" + k + "][" + j + "][" + i + "]=" + weight[k][j][i]);//imprime lo que hay en weight[k][j][i]
                        aux += out[k - 1][i] + weight[k][j][i];// out[0][0]=3 + weight[1][0][0]=1.0
                    }
                }
                out[k][j] = F(aux);//hace que out su parte[k][j] se llene con la funcion F
                System.out.println("out[" + k + "][" + j + "]=" + out[k][j]);
                System.out.println("");
            }
        }
        error(out[Layout.length - 1][0]);
    }

    private void error(double salida) {
        System.out.println("Output=" + salida);
        System.out.println("Ouput good =" + result[0] / 100.0);
        System.out.println("Error(%)" + Math.abs(((result[0] / 100.0) - salida) * 100));
    }

    //función de activacion(F)
    public double F(double n) {
        return 1 / (1 + Math.pow(Math.E, -n));
    }
}
