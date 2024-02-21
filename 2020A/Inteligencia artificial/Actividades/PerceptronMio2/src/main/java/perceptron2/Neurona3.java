package perceptron2;

import java.util.Random;

public class Neurona3 {
    int limCon=0, limCar=0; //limite de Coincide y No coincide
    char coincide[] = new char[56]; 
    char caracteres[] = new char[56];
    private String dato;
    int totalAxon;//total del limite del axon(palabra donde se busca)
    int totalCon;//total del limite de base de conocimiento(palabra que dicta si hay coincidencias)
    private Neurona1 n1;
    private Neurona2 n2;

    public Neurona3() {
        n1 = new Neurona1();
        n2 = new Neurona2();
        totalCon = n2.necesario();
    }

    public void Axon(String dato) {
        this.dato = dato;
    }

    public String getAxon() {
        return dato;
    }
    
    public boolean aprender(char c){
        int x=0,y=0;
        boolean band = false;
        while(x < limCar && band == false){
            if(caracteres[x] == c){
                band = true;
            }
            x++;
        }
        if(band == false){
            while(y < limCon && band == false){
                if(coincide[y] == c){
                    band = true;
                }
                y++;
            }
        }
        return band;
    }
    
    public void Platica() throws InterruptedException {
        String respuesta = "";
        totalAxon = dato.length();
        n1.Axon(dato);   
        n1.CaracterRandom();
        char c = n1.getAxon();
        Thread.sleep(1000);
        n2.BuscaCaracter(c);
        if(aprender(c) == true){
            Platica();
        }
        System.out.println("[Neurona 1]  Tienes el Caracter: " + c);
        if (n2.getAxon() == 0) {
            respuesta = "No hay Coincidencias";
            caracteres[limCar]=c;
            limCar++;
        } else {
            respuesta = "Si hay Coincidencias";
            caracteres[limCar]=c;
            coincide[limCon]=c;
            limCon++;
            limCar++;
        }
        System.out.println("[Neurona 2] Caracter encontrados: " + respuesta);
        Thread.sleep(1000);
        if(totalAxon != limCar && limCon != totalCon){
            Platica();
        }
        if(totalAxon == limCar){
            System.out.println("No se encontro la palabra");
            System.exit(0);
        }
        if(limCon == totalCon){
            System.out.println("Se encontro la palabra");
            System.exit(0);
        }
    }
}