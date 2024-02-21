/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package solvingequations;

/**
 *
 * @author marti
 */
public class SolvingEquations {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        AlgoritmoGenetico solving = new AlgoritmoGenetico(6, 4,0.1,6);
        solving.GA();
    }
    
}
