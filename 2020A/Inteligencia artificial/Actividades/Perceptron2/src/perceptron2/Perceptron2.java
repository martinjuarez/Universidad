package perceptron2;

public class Perceptron2 {

    Neurona3 n3;

    public Perceptron2() throws InterruptedException {
        n3 = new Neurona3();
        n3.Axon("abcdefghijklmnopq");
        n3.Platica();
    }

    public static void main(String[] args) throws InterruptedException {
        new Perceptron2();
    }
}
