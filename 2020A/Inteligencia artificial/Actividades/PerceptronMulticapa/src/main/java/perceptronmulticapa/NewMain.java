package perceptronmulticapa;

import java.util.Random;

public class NewMain {

    double[] vector_w;
    PerceptronMulticapa p;

    public NewMain() {
        int cap = 4;
        vector_w = new double[cap];
        vector_w[0] = 1;//1
        vector_w[1] = 6;//3
        vector_w[2] = 7;//4
        vector_w[3] = 9;//1
        p = new PerceptronMulticapa();//se crea un objeto de tipo PerceptronMulticapa
        p.expand(vector_w);//se utiliza la funcion expand de Perceptron multicapa y se le da de parametro el vector_w
    }

    public static void main(String[] args) {
        new NewMain();
    }
}
