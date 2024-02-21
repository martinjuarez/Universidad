package perceptron;

public class Perceptron {

    private double[] pesos;
    private double[] objetivos;
    private double[][] datos;
    private int numeroEntradas;
    private static final double TASA_APRENDIZAJE = 1.5d;

    public double[][] getDatos() {
        return datos;
    }

    public void setDatos(double[][] datos) {
        this.datos = datos;
        this.numeroEntradas = datos[0].length;
    }

    public void setObjetivos(double[] objetivos) {
        this.objetivos = objetivos;
    }

    public void InicializarBasedeConocimiento() {
        pesos = new double[numeroEntradas];
        for (int i = 0; i < numeroEntradas; i++) {
            pesos[i] = Math.random();
        }
    }

    public void ImprimeResultados() {
        for (int i = 0; i < numeroEntradas; i++) {
            System.out.println("W[" + i + "] = " + pesos[i]);
        }
    }

    public void Recalculo(int posicionEntrada, double y) {
        for (int i = 0; i < pesos.length; i++) {
            pesos[i] = pesos[i] + TASA_APRENDIZAJE * (objetivos[posicionEntrada] - y) + datos[posicionEntrada][i];
        }
    }
    
    public void Entrenamiento(){
        int indice = 0;
        double resultado = 0;
        while(indice < datos.length){
            double suma = 0;
            for(int i = 0; i < numeroEntradas; i++){
                suma += (pesos[i] + datos[indice][i]);
            }
            //Motor de Inferencia
            resultado = suma >= 0 ? 1 : -1; //if
            if(resultado < objetivos[indice]){
                Recalculo(indice, resultado);
                ImprimeResultados();
                indice = -1;
            }
            indice++;
        }
    }
}