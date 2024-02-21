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
public class Individuo {

    private char[] chromosomes;
    private double fitness;
    private double probability;
    private double cumulativeProbabilty;

    public char[] getChromosomes() {
        return chromosomes;
    }

    public void setChromosomes(char[] chromosomes) {
        this.chromosomes = chromosomes;
    }

    public double getFitness() {
        return fitness;
    }

    public void setFitness(double fitness) {
        this.fitness = fitness;
    }

    public double getProbability() {
        return probability;
    }

    public void setProbability(double probability) {
        this.probability = probability;
    }

    public double getCumulativeProbabilty() {
        return cumulativeProbabilty;
    }

    public void setCumulativeProbabilty(double cumulativeProbabilty) {
        this.cumulativeProbabilty = cumulativeProbabilty;
    }
}
