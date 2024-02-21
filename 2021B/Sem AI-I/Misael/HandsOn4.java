package examples.HandsOn4;

import jade.core.Agent;
import jade.core.AID;
import jade.core.behaviours.*;


public class HandsOn4 extends Agent {


	private Interfaz myGui;  //Objeto de mi interfaz
	

	
	protected void setup() {
	
	myGui = new Interfaz(this);
		
		// Add the behaviour serving queries from buyer agents
		//comportamiento
		addBehaviour(new RegresionLineal());
		
	}
	
	private class RegresionLineal extends OneShotBehaviour{
	
	public void action(){
	
	Regresion_Lineal op = new Regresion_Lineal();
	op.imprimirRegresionAnalitica();
	
	Regresion_Lineal_Gradiente ob2 = new Regresion_Lineal_Gradiente();// aun incompleto 
	ob2.gradienteRegresion();

	
	 myGui.showGui();
		}//Termina action
	} // Termina clase RegresionLineal extends OneShotBehaviour
	
	
	public void CalculaRegresion()
	{
		Regresion_Lineal ob1 = new Regresion_Lineal();
		ob1.CalculaRegresionAnalitica(myGui.numero);

		System.out.println("");
	
	}
	
	
	public class Dataset
	{
		private int[] x = {23,26,30,34,43,48,52,57,58};
		private int[] y = {651,762,856,1063,1190,1298,1421,1440,1518};
		
		
			public int[] GetX()
			{
				return x;
			}
			public int[] GetY()
			{
				return y;
			}
					
	}
	
	
	public class Regresion_Lineal extends Dataset 
	{
		  int sum_xy = 0, sum_x = 0, sum_y = 0, sum_x2 = 0;  
		  double beta0, beta1;
									
			public void CalcularSumatorias()
			{
       			 for(int actual = 0; actual < 9; actual++)
       		 	{
           		 	sum_xy += GetX()[actual] * GetY()[actual];
            		 	sum_x  += GetX()[actual];
            		 	sum_y  += GetY()[actual];
           		 	sum_x2 += Math.pow(GetX()[actual], 2);
       		 	}
			}		
		
			public void CalcularBeta1_Beta0()
			{
				System.out.println("SOLUCION ANALITICA:");
				System.out.println("");
				
				System.out.println("Calculando valor de beta1 (Pendiente)");

				beta1 = (double)(((9 * sum_xy) - (sum_x * sum_y)) / ((9 * sum_x2) - Math.pow(sum_x,2)));   
        			System.out.println("Listo! El valor de beta1 es: " + beta1);
        		
        			System.out.println("Calculando valor de beta0 (Punto de Corte)");				
				beta0 = (double)(((sum_y * sum_x2) - (sum_x * sum_xy))/ ((9 * sum_x2) - Math.pow(sum_x, 2)));

				System.out.println("Listo! El valor de beta0 es: " + beta0);
        			System.out.println("");

			}
			
			public void Beta1_Beta0()
			{
				beta0 = (double)(((sum_y * sum_x2) - (sum_x * sum_xy))/ ((9 * sum_x2) - Math.pow(sum_x, 2)));
				beta1 = (double)(((9 * sum_xy) - (sum_x * sum_y)) / ((9 * sum_x2) - Math.pow(sum_x,2)));  
				
			}
						
			public void CalculaRegresionAnalitica(int _numero)
			{
				CalcularSumatorias();
				Beta1_Beta0();
				System.out.println("Calculado con Valores funcion Analitica");
				System.out.println("Para el Valor " +_numero+" Vale " + (beta0+(beta1*_numero)));	
			}		
		
			public void imprimirRegresionAnalitica()
			{
				CalcularSumatorias();
				CalcularBeta1_Beta0();
			}
			
	}  // End of inner class Regresion_Lineal
	
	public class Regresion_Lineal_Gradiente extends Dataset 
	{
	

	public void gradienteRegresion()
	{
	double num_steps=1000;
	double LearningRate=0.003;
	double criterio=1e-2;
	double b_0=0;
	double b_1=0;
	double b_0_gradient=0;
	double b_1_gradient=0;
	double N=9,N1=2,N2=1;
	double error=0;	
	
	
	
	
	//derivadas:
	for (int j=0; j<9; j++)
	{
	b_0_gradient = b_0_gradient + ( (-N1/N) * (GetY()[j] - (b_0 + b_1 * GetX()[j])) );    // derivada con respecto a beta0
	b_1_gradient = b_1_gradient + ( (-N1/N) * (GetY()[j] - (b_0 + b_1 * GetX()[j])) * GetX()[j] ); //derivada beta1
	}	
	
	
	for (int ii=0; ii<num_steps; ii++)
	{
	
		for (int i=0; i<9; i++)
	{
	error=error + (  (GetY()[i]-(b_0 + b_1*GetX()[i])) * (GetY()[i]-(b_0 + b_1*GetX()[i])) );
	}
	error=error*(N2/N);
	
	if(error<criterio)
	{
	break;
	}
	
	b_0 = b_0 - (LearningRate * b_0_gradient);
	b_1 = b_1 - (LearningRate * b_1_gradient);
			
	

	
	}
	System.out.println("Listo! El valor de beta0 es: " + b_0);
	System.out.println("Listo! El valor de beta1 es: " + b_1);
	System.out.println("Listo! El valor del error es: " + error);
	
	}
	
	
	
	}// End of inner class Regresion_Lineal_Gradiente






/*
	private class Regresion_Lineal_Gradiente extends Regresion_Lineal
	{
		
		private double sum_xy = 0, sum_x = 0, sum_y = 0, sum_x2 = 0;  


			public void CalcularSumatorias()
			{
       			 for(int actual = 0; actual < 9; actual++)
       		 	{
           		 	sum_xy += GetX()[actual] * GetY()[actual];
            		 	sum_x  += GetX()[actual];
            		 	sum_y  += GetY()[actual];
           		 	sum_x2 += Math.pow(GetX()[actual], 2);
       		 	}
			}
			
			public void Beta1_Beta0()
			{
				 beta0 = (double)(((sum_y * sum_x2) - (sum_x * sum_xy))/ ((9 * sum_x2) - Math.pow(sum_x, 2)));
				 beta1 = (double)(((9 * sum_xy) - (sum_x * sum_y)) / ((9 * sum_x2) - Math.pow(sum_x,2)));   
			}
			
			
			
			
			
			public double coste(double _a, double _b)
			{
			double m=9;
			double error=0.0;
			double n=1,n1=9;

				for (int i=0; i<9; i++)
				{
				error=error+((GetY()[i]-(_a + _b*GetX()[i]))*(GetY()[i]-(_a + _b*GetX()[i])));
				}
				error=error*(n/n1);
			return error;
			}
			
			
			
		
			
			public void gradienteRegresion()
			{
			
			double num_steps=10000;
			double LearningRate=0.1;
			double criterio=1e-2;
			double b_0=1;
			double b_1=1;
			double b_0_gradient;
			double b_1_gradient;
			double N=9,N1=2;
			double error=0;
			
			
	
				for (int i=0; i<num_steps; i++)
				{
				b_0_gradient=0;
				b_1_gradient=0;
			
					for (int j=0; j<9; j++)
					{
					b_0_gradient -= (N1/N) * (GetY()[j] - (b_0 + b_1 * GetX()[j]));    // derivada con respecto a beta0
					b_1_gradient -= (N1/N) * (GetY()[j] - (b_0 + b_1 * GetX()[j])) * GetX()[j]; //derivada beta1
					}
				
				
				b_0 = b_0 - (LearningRate * b_0_gradient);
				b_1 = b_1 - (LearningRate * b_1_gradient);
			
				error=coste(b_0_gradient,b_1_gradient);
				if(error<criterio)
				{
				break;
				}
				
				
				}
				//System.out.println("Listo! El valor de beta0 es: " + b_0);
				//System.out.println("Listo! El valor de beta1 es: " + b_1);
				//System.out.println("Listo! El valor del error es: " + error);
				
			}			
					

			
			public void imprimirRegresionGradiente()
			{
				
				//CalculaDescensoGradiente();
				System.out.println("Andamos en eso"); 
				//gradienteRegresion();
			}
			
	}  // End of inner class Regresion_Lineal_Gradiente
*/
}

