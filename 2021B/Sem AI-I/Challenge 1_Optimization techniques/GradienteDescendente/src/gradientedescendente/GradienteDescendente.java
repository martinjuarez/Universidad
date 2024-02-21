/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gradientedescendente;

import java.text.DecimalFormat;
import java.util.Random;

/**
 *
 * @author marti
 */
public class GradienteDescendente {

    private double objective(double x){
        return Math.pow(x,2);
    }
    
    private double derivative(double x){
        return x * 2;
    }
    
    private void gradiente_descendente(){
        Random rand = new Random();
        DecimalFormat df = new DecimalFormat("#.00000");
        double gradient, solution_eval;
        double step_size = 0.1;
        double solution = (0 + ( 2 - 0 ) * rand.nextFloat())-1;
        for(int x=0;x < 30;x++){
            gradient = derivative(solution);
            solution = solution - step_size * gradient;
            solution_eval = objective(solution);
            System.out.println(">"+x+" f("+df.format(solution)+") = "+df.format(solution_eval));
        }   
    }
    
    public static void main(String[] args) {
        GradienteDescendente a = new GradienteDescendente();
        a.gradiente_descendente();
    }
    
}
