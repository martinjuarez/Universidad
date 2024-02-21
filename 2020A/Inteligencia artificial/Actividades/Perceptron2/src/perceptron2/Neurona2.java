package perceptron2;

import java.util.Random;

public class Neurona2 {

    private double TASA_APRENDIZAJE = 0.5d;
    private String dato;
    private String BaseConocimiento = "matematicas";
    private int totalcaracter = 0;
    private Random ran;

    public Neurona2() {
        ran = new Random();
    }

    public void Axon(String dato) {
        this.dato = dato;
    }

    public int getAxon() {
        return this.totalcaracter;
    }

    public void BuscaCaracter(char caracter) {
        totalcaracter = 0;
        for (int x = 0; x < this.BaseConocimiento.length() - 1; x++) {
            if (this.BaseConocimiento.charAt(x) == caracter) {
                totalcaracter += 1;
            }
        }
    }
}
