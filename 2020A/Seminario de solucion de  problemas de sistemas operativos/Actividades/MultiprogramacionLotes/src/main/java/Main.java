
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

    String lote, operacion, numPrograma;
    int tiempo, loteP, medio;
    boolean m;

    public boolean esOperacion(String ope) {
        Pattern pattern = Pattern.compile("^\\d{1}(\\+|\\-|\\*|\\/|\\%|\\^)\\d{1}$");
        Matcher mather = pattern.matcher(ope);
        return mather.find();
    }

    public int numTrabajo() {
        int numero = (int) (Math.random() * 10) + 1;
        return numero;
    }

    public int temEstimado() {
        int numero;
        do {
            numero = (int) (Math.random() * 10) + 1;
        } while (numero < 5);
        return numero;
    }

    public String genOperacion() {
        int numero, numero2, numero3;
        String operacion;
        numero = (int) (Math.random() * 9) + 1;
        operacion = String.valueOf(numero);
        numero2 = (int) (Math.random() * 5) + 1;
        switch (numero2) {
            case 1:
                operacion = operacion + "+";
                break;
            case 2:
                operacion = operacion + "-";
                break;
            case 3:
                operacion = operacion + "*";
                break;
            case 4:
                operacion = operacion + "/";
                break;
            case 5:
                operacion = operacion + "%";
                break;
            default:
                System.out.println("Error en el switch");
                break;
        }
        numero3 = (int) (Math.random() * 10) + 1;
        operacion = operacion + numero3;
        return operacion;
    }

    public void iniciar() {
        Lista b = new Lista();
        Scanner scan = new Scanner(System.in);
        int c = 0, d = 1, procesos;
        System.out.print("Numero de procesos: ");
        procesos = Integer.parseInt(scan.nextLine());
        loteP = procesos / 3;
        medio = procesos / 2;
        c = procesos;
        while (c != 0) {
            operacion = genOperacion();
            tiempo = temEstimado();
            if (b.esVacio() == true) {
                numPrograma = String.valueOf(numTrabajo());
            } else {
                do {
                    numPrograma = String.valueOf(numTrabajo());
                } while (b.buscar(numPrograma) == true);
            }
            if(c == medio){
                m = true;
            }
            if (c % 3 == 0) {
                loteP--;
            }
            b.agregar(loteP, lote, operacion, tiempo, numPrograma, m);
            c--;
        }
        b.mostrar();
    }

    public static void main(String[] args) {
        long Star = System.currentTimeMillis();
        Main principal = new Main();
        principal.iniciar();
        long end = System.currentTimeMillis();
        long res = end - Star;
        System.out.println("Contador global: " + res / 1000);
    }
}