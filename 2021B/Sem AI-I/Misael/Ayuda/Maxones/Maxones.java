/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package maxones;

/**
 *
 * @author marti
 */
public class Maxones {

    /**
     * @param args the command line arguments
     */
        
    public static void main(String[] args) {
        AlgoritmoGenetico maxo = new AlgoritmoGenetico(6, 10,0.1);
        maxo.GA();
    }
}
