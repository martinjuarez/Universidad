
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

    String lote, nombre, operacion, numPrograma;
    int tiempo, loteP;

    public boolean esOperacion(String ope) {
        Pattern pattern = Pattern.compile("^\\d{1}(\\+|\\-|\\*|\\/|\\%|\\^)\\d{1}$");
        Matcher mather = pattern.matcher(ope);
        return mather.find();
    }

    public void iniciar() {
        Lista b = new Lista();
        Scanner scan = new Scanner(System.in);
        int c = 0, d = 1, procesos;
        System.out.print("Numero de procesos: ");
        procesos = Integer.parseInt(scan.nextLine());
        loteP = procesos / 4;
        if (procesos % 4 != 0) {
            loteP++;
        }
        while (c < procesos) {
            lote = "Lote " + String.valueOf(d);
            System.out.print("Nombre del programador: ");
            nombre = scan.nextLine();
            do {
                System.out.print("Operacion a realizar: ");
                operacion = scan.nextLine();
                if (esOperacion(operacion) == false) {
                    System.out.println("Operacion invalida");
                }
            } while (esOperacion(operacion) == false);
            do {
                System.out.print("Tiempo maximo estimado: ");
                tiempo = Integer.parseInt(scan.nextLine());
                if (tiempo <= 0) {
                    System.out.println("El tiempo estimado debe ser mayor a 0");
                }
            } while (tiempo <= 0);
            if (b.esVacio() == true) {
                System.out.print("Numero de programa: ");
                numPrograma = scan.nextLine();
            } else {
                do {
                    System.out.print("Numero de programa: ");
                    numPrograma = scan.nextLine();
                } while (b.buscar(numPrograma) == true);
            }
            b.agregar(loteP, lote, nombre, operacion, tiempo, numPrograma);
            c++;
            if (c % 4 == 0) {
                d++;
                loteP--;
            }
        }
        b.mostrar();
    }

    public static void main(String[] args) {
        long Star = System.currentTimeMillis();
        Main principal = new Main();
        principal.iniciar();
        long end = System.currentTimeMillis();
        long res = end - Star;
        Vista Principal = new Vista();
        System.out.println("Contador global: " + res / 1000);
    }
}