/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package laberinto2;

import java.util.Scanner;

/**
 *
 * @author redes1
 */
public class Laberinto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Escenarios esce = new Escenarios();
        Metodo metodo = new Metodo();

        Scanner lector = new Scanner(System.in);
        int opc;
        int mod = 0;
        do {
            System.out.println("1.-Laberinto 1");
            System.out.println("0.- Salir");
            System.out.print("opcion ->");
            System.out.println("");
            opc = lector.nextInt();
            if (opc != 0) {
                System.out.println("Manual 1");
                System.out.println("Automatico 2");
                mod = lector.nextInt();
            }

            switch (opc) {
                case 0:
                    System.out.println("Fin");
                    break;
                case 1:
                    if (mod == 1) {
                        metodo.Avanzar(esce.escenario(), esce.fila(esce.escenario()), esce.colum(esce.escenario()));
                    } else if(mod == 2){
                        metodo.Auto(esce.escenario(), esce.fila(esce.escenario()), esce.colum(esce.escenario()));
                    } else if(mod == 3){
                        System.out.println("profundidad");
                    } else if(mod == 4){
                        System.out.println("anchura");
                    } else if(mod == 5){
                        System.out.println("estrella");
                    }
                default:
                    System.out.println("Opcion no valida");
            }
        } while (opc != 0);
    }
}
