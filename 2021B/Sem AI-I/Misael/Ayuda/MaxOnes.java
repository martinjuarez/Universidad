/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ga;

/**
 *
 * @author faith
 */
public class MaxOnes {

    public static void main(String[] args) {
        int populationSize = 30;
        double mutationRate = 0.001;
        double crossoverRate = 0.95;
        int elitismCount = 0;
        int chromosomeLength = 10;
        GeneticAlgorithm ga = new GeneticAlgorithm(populationSize, mutationRate, crossoverRate, elitismCount);
        Population population = ga.initPopulation(chromosomeLength);
        int generation = 1;

        ga.evalPopulation(population);

        while (!ga.isTerminationConditionMet(population)) {
            printGenerationData(generation, population);
            
            population = ga.crossoverPopulation(population);

            population = ga.mutatePopulation(population);

            ga.evalPopulation(population);

            generation++;
        }

        printGenerationData(generation, population);

        System.out.println("Found solution in " + generation + " generations");
        System.out.println("Best solution: " + population.getFittest(0).toString());
    }

    public static void printGenerationData(int generation, Population population) {
        double populationFitness = population.getPopulationFitness();
        System.out.println("Generation:" + generation);
        System.out.println("Population fitness: " + populationFitness);

        System.out.println("Chromosomes:");
        for(Individual individual : population.getIndividuals()) {
            double individualFitness = individual.getFitness();
            double proportionateFitness = (individualFitness * 100) / populationFitness;
            System.out.println(individual.toString() + " | Fitness: " + individual.getFitness()  + " | Proportionate fitness value: " + proportionateFitness + "%");
        }       
        
        System.out.println();
    }
}
