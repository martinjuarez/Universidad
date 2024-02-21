package perceptron2;

import java.util.Random;

public class Neurona3 {
    private String dato;
    private Neurona1 n1;
    private Neurona2 n2;

    public Neurona3() {
        n1 = new Neurona1();
        n2 = new Neurona2();
    }

    public void Axon(String dato) {
        this.dato = dato;
    }

    public String getAxon() {
        return dato;
    }

    public void Platica() throws InterruptedException {
        String respuesta = "";
        n1.Axon(dato);
        n1.CaracterRandom();
        char c = n1.getAxon();
        System.out.println("[Neurona 1]  Tienes el Caracter: " + c);
        Thread.sleep(1000);
        n2.BuscaCaracter(c);
        if (n2.getAxon() == 0) {
            respuesta = "No hay Coincidencias";
        } else {
            respuesta = "Si hay Coincidencias";
        }
        System.out.println("[Neurona 2] Caracter encontrados: " + respuesta);
        Thread.sleep(1000);
        Platica();
    }
}