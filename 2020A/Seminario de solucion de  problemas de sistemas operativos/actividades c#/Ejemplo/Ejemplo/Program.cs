using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo
{
    class Program
    {
        static void Main(string[] args)
        {
            Segmento[] arregloSegmentos = new Segmento[32];

            for(int i = 0; i < 32; i++ )
            {
                arregloSegmentos[i] = new Segmento(0,"");
            }

            List<Proceso> procesosGenerados = new List<Proceso>();

            procesosGenerados.Add(new Proceso(1, 1));
            procesosGenerados.Add(new Proceso(2, 4));
            procesosGenerados.Add(new Proceso(3, 6));
            procesosGenerados.Add(new Proceso(4, 3));
            procesosGenerados.Add(new Proceso(5, 1));



            string lista = procesosGenerados.ToString();

            Console.WriteLine(lista[0]);

            Console.ReadKey();

            /*
            int totalDeSegmentos = 32;
            int marcosDisponibles = 8;
            int segmentoEnTabla = 0;
            int indiceProcesosGen = 0;

            int numeroDeMarcosAUsar = 0;
            int numeroDeSegmentosAUsar = 0;
            int segmentosUsados = 0;
            int numeroDeProcesosPermitidos = 0;

            while (indiceProcesosGen < procesosGenerados.Count)
            {
                numeroDeMarcosAUsar = procesosGenerados[indiceProcesosGen].Tamanio / 4;

                if (numeroDeMarcosAUsar <= marcosDisponibles)
                {
                    if (procesosGenerados[indiceProcesosGen].Tamanio % 4 == 0)
                    {
                        numeroDeSegmentosAUsar = numeroDeMarcosAUsar * 4;
                        segmentosUsados = 0;

                        while (segmentoEnTabla < totalDeSegmentos)
                        {
                            if (segmentosUsados < numeroDeSegmentosAUsar)
                            {
                                arregloSegmentos[segmentoEnTabla].Id = procesosGenerados[indiceProcesosGen].Id;
                                segmentosUsados++;
                                segmentoEnTabla++;
                            }
                            else
                            {
                                break;
                            }
                        }


                        marcosDisponibles -= numeroDeMarcosAUsar;
                        numeroDeProcesosPermitidos++;
                    }
                    else
                    {
                        numeroDeSegmentosAUsar = numeroDeMarcosAUsar * 4;
                        int numeroDeSegmentosResiduales = procesosGenerados[indiceProcesosGen].Tamanio % 4;
                        numeroDeSegmentosAUsar += numeroDeSegmentosResiduales;
                        segmentosUsados = 0;

                        while (segmentoEnTabla < totalDeSegmentos)
                        {
                            if (segmentosUsados < numeroDeSegmentosAUsar)
                            {
                                arregloSegmentos[segmentoEnTabla].Id = procesosGenerados[indiceProcesosGen].Id;
                                segmentosUsados++;
                                segmentoEnTabla++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        segmentoEnTabla += (4 - numeroDeSegmentosResiduales);

                        marcosDisponibles -= numeroDeMarcosAUsar;
                        numeroDeProcesosPermitidos++;
                    }
                }
                else
                {
                    break;
                }

                for(int i = 0; i < arregloSegmentos.Length; i++)
                {
                    if( i%4== 0)
                    {
                        Console.Write("\t");
                    }

                    if (i % 8 == 0)
                    {
                        Console.Write("\n");
                    }

                    Console.Write(arregloSegmentos[i].Id.ToString() + " ");
                    
                   
                }

                Console.ReadKey();
                Console.Write("\n");

                indiceProcesosGen++;
            }
            */

           
        }
    }
}
