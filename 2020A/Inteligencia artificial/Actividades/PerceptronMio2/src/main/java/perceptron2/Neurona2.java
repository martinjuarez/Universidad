package perceptron2;

import java.util.Random;

public class Neurona2 {

    private double TASA_APRENDIZAJE = 0.5d;
    private String dato;
    private String BaseConocimiento = "aprender";
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

    public int getBase() {
        return this.BaseConocimiento.length();
    }

    public int necesario() {
        char[] comparar = new char[BaseConocimiento.length()];
        int x = 0, y = 0, contador = 0;
        boolean nuevoCaracter, repetido;
        while (x < this.BaseConocimiento.length()) {
            y = 0;
            nuevoCaracter = false;
            repetido = false;
            if (contador == 0) {
                if (BaseConocimiento.charAt(x) != comparar[y]) {
                    nuevoCaracter = true;
                } else {
                    nuevoCaracter = false;
                }
                if (nuevoCaracter == true) {
                    comparar[contador] = BaseConocimiento.charAt(x);
                    contador +=1;
                }
            } else {
                while (y < contador && repetido == false) {
                    if (BaseConocimiento.charAt(x) != comparar[y]) {
                        nuevoCaracter = true;
                    } else {
                        nuevoCaracter = false;
                        repetido = true;
                    }
                    y++;
                }
                if (nuevoCaracter == true) {
                    comparar[contador] = BaseConocimiento.charAt(x);
                    contador += 1;
                }
            }
            x++;
        }
        return contador;
    }

    public void BuscaCaracter(char caracter) {
        totalcaracter = 0;
        for (int x = 0; x < this.BaseConocimiento.length(); x++) {
            if (this.BaseConocimiento.charAt(x) == caracter) {
                totalcaracter += 1;
            }
        }
    }
}
