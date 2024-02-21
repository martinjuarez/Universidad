using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sistemaOperativo
{
    public class Quantum
    {
       
        public Quantum()
        {

        }

        public List<int> calcularParadas(int quantum, int tiempoMaximoEstimado)
        {
            List<int> paradas = new List<int>();
            int numeroParadas = 0;

            if ( quantum >= tiempoMaximoEstimado )
            {
                paradas.Add(tiempoMaximoEstimado);
            }
            else
            {
                numeroParadas = tiempoMaximoEstimado / quantum;
                for( int i = 1; i <= numeroParadas; i++)
                {
                    paradas.Add( i * quantum );
                }

                paradas.Add( tiempoMaximoEstimado % quantum );
            }

            return paradas;
        }

    }
}
