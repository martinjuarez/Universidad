package Perceptron;

public class main {

    PerceptronA A;
    PerceptronB B;

    public main(){
        A = new PerceptronA();
        B = new PerceptronB();
        A.set("BHDGTVRMÑN");
        A.getCaracter();
        B.BuscarLetra(A.get());
        System.out.println("Silaba: " + B.getSilaba());
    }

    public static void main(String[] args){
        new main();
    }
}
