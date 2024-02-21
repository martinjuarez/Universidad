package Perceptron;

import java.util.Random;

public class PerceptronA {

    private String letra;
    private int posicion;
    private Random r;
    private String cadena;

    public PerceptronA() {
        r = new Random();
        this.posicion = r.nextInt(10);
    }

    public void set(String cadena) {
        this.cadena = cadena;
    }

    public void getCaracter() {
        this.letra = cadena.substring(this.posicion, this.posicion+1);
    }

    public String get() {
        return this.letra;
    }
}
