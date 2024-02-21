import java.util.logging.Level;
import java.util.logging.Logger;

public class Lista {

    Proceso primero = null;
    Proceso ultimo = null;
    Proceso medio = null;
    public boolean esVacio() {
        return primero == null;
    }
    
    int resultado(String a){
        String b = String.valueOf(a.charAt(0)), c = String.valueOf(a.charAt(2));
        int d = Integer.parseInt(b), e = Integer.parseInt(c);
        int res = 0;
        if(a.charAt(1) == '+'){
            res = d+e;
        }else if(a.charAt(1) == '-'){
            res = d-e;
        }else if(a.charAt(1) == '/'){
            res = d/e;
        }else if(a.charAt(1) == '*'){
            res = d*e;
        }else if(a.charAt(1) == '%'){
            res = d%e;
        }else if(a.charAt(1) == '^'){
            res = (int) Math.pow(d, e);
        }
        return res;
    }
    
    public void agregar(Integer z, String a, String c, Integer d, String e, boolean b) {
        Proceso temp = new Proceso();
        Proceso aux = primero;
        temp.pendientes = z;
        temp.Lote = a;
        temp.operacion = c;
        temp.tiempoMax = d;
        temp.numPrograma = e;
        temp.siguiente = null;
        if (primero == null) {
            primero = temp;
            ultimo = temp;
        } else {
            while (aux.siguiente != null) {
                aux = aux.siguiente;
            }
            aux.siguiente = temp;
            ultimo = temp;
            if(b == true){
                medio = temp;
            }
        }
    }

    public void mostrar() {
        Proceso temp = primero;
        Proceso aux;
        int tem1, tem2;
        
        if (temp == null) {
            System.out.println("Lista vacia");
        } else {
            while (temp != null) {
                temp.res = resultado(temp.operacion);
                System.out.println("Lotes Pendientes: " + temp.pendientes);
                System.out.println("Lote en ejecucion");
                System.out.println("Numero de Programa: " + temp.numPrograma);
                System.out.println("Tiempo: " + temp.tiempoMax + '\n');
                System.out.println("Proceso en ejecucion");
                System.out.println("Operacion: " + temp.operacion);
                System.out.println("Tiempo: " + temp.tiempoMax);
                System.out.println("Numero de Programa: " + temp.numPrograma);
                //System.out.println("Lote: " + temp.Lote);
                tem1 = 0;
                tem2 = temp.tiempoMax;
                System.out.println("Tiempo restante por ejecutar: ");
                System.out.print(tem2);
                while(tem1 < temp.tiempoMax){   
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(Lista.class.getName()).log(Level.SEVERE, null, ex);
                    }
                    tem2--;
                    System.out.print("   \b\b" + tem2);
                    tem1++;
                    
                    
                    /*
                    if(){
                        
                    }
                    */
                }
                temp.listo = true;
                temp = temp.siguiente;
                System.out.println("\n");
                aux = primero;
                System.out.println("Procesos terminados: ");
                while(aux != null && aux.listo == true){
                    System.out.println("Numero de programa: " + aux.numPrograma);
                    System.out.println("Operacion: " + aux.operacion);
                    System.out.println("Resultado: " + aux.res);
                    aux = aux.siguiente;
                }
                System.out.println("\n");
            }
        }
    }

    public boolean buscar(String n) {
        Proceso aux;
        aux = primero;
        boolean band = false;
        if (primero == null) {
            System.out.println("Error lista vacia");
        } else {
            while (aux != null && band == false) {
                if (aux.numPrograma.equals(n) == true) {
                    band = true;
                } else {
                    aux = aux.siguiente;
                }
            }
            /*
            if (band == true) {
                System.out.println("El numero de programa(ID) ya fue usado");
            }
            */
        }
        return band;
    }
    /*
    void QuickSort(Proceso p,Proceso u){
        Proceso pivote = null;
        Proceso central = 
    }
    */
}