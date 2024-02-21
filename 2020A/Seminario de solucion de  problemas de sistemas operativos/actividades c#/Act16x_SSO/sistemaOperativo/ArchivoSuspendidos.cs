using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace sistemaOperativo
{
    public class ArchivoSuspendidos
    {
        int numProcesosSuspendidos;
        string nombreDeArchivo = "";
        List<Proceso> procesosEnArchivo = new List<Proceso>();

        public ArchivoSuspendidos()
        {
            numProcesosSuspendidos = 0;
            nombreDeArchivo = "suspendidos.txt";
        }

        public int NumProcesosSuspendidos()
        {
           return procesosEnArchivo.Count;
        }

        public int posicionProcesoSuspendido(List<Proceso> procesosEjecutando)
        {
            int i = 0;
            int posicionProcesoASuspender = -1;

            if (procesosEjecutando.Count == 1)
            {
                posicionProcesoASuspender = 0;
            }
            else
            {
                while (i < procesosEjecutando.Count)
                {
                    if (procesosEjecutando[i].obtenerEstado() == "BLOQ")
                    {
                        posicionProcesoASuspender = i;
                        break;
                    }
                    i++;
                }
            }

            return posicionProcesoASuspender;
        }

        public void guardaEnDisco(Proceso proceso)
        {
            procesosEnArchivo.Add(proceso);

            using (StreamWriter sw = new StreamWriter(nombreDeArchivo, true))
            {
                {
                    string[] values = {
                        proceso.obtenerId().ToString(),
                        proceso.obtenerNumeroUno().ToString(),
                        proceso.obtenerOperadorMatematico().ToString(),
                        proceso.obtenerOpeMatematica().ToString(),
                        proceso.obtenerNumeroDos().ToString(),
                        proceso.obtenerTiempoMaximoEstimado().ToString(),
                        proceso.obtenerResultadoDeOperacion().ToString(),
                        proceso.obtenerTiempoTranscurrido().ToString(),
                        proceso.obtenerTiempoRestante().ToString(),
                        proceso.obtenerTiempoDeLlegada().ToString(),
                        proceso.obtenerTiempoDeFinalizacion().ToString(),
                        proceso.obtenerTiempoDeServicio().ToString(),
                        proceso.obtenerTiempoDeEspera().ToString(),
                        proceso.obtenerTiempoDeRetorno().ToString(),
                        proceso.obtenerTiempoDeRespuesta().ToString(),
                        proceso.obtenerTiempoTranscurridoBloquedo().ToString(),
                        proceso.obtenerTamanio().ToString(),
                        proceso.obtenerEstado(),
                        proceso.obtenerBanderaRespuesta().ToString(),
                        proceso.obtenerBanderaTiempoDeLlegada().ToString(),
                        proceso.obtenerBanEjecutando().ToString(),
                        proceso.obtenerIndiceParadasQuantum().ToString()
                    };
                    string line = String.Join(",", values);
                    sw.WriteLine(line);
                    sw.Flush();
                }
            }

        }

        public Proceso obtenPrimerProceso()
        {
            return procesosEnArchivo[0];
        }

        public List<Proceso> obtenProcesoEnArchivo()
        {
            List<Proceso> procesoEnCola = new List<Proceso>();
            procesoEnCola.Add(procesosEnArchivo[0]);
            return procesoEnCola;
        }

        public void actualizaLista()
        {
            procesosEnArchivo.RemoveAt(0);
        }

        public void actualizaArchivo()
        {
            if (File.Exists(nombreDeArchivo))
            {
                File.Delete(nombreDeArchivo);
                
                foreach (Proceso p in procesosEnArchivo)
                {
                    using (StreamWriter sw = new StreamWriter(nombreDeArchivo, true))
                    {

                      string[] values = {
                          p.obtenerId().ToString(),
                          p.obtenerNumeroUno().ToString(),
                          p.obtenerOperadorMatematico().ToString(),
                          p.obtenerOpeMatematica().ToString(),
                          p.obtenerNumeroDos().ToString(),
                          p.obtenerTiempoMaximoEstimado().ToString(),
                          p.obtenerResultadoDeOperacion().ToString(),
                          p.obtenerTiempoTranscurrido().ToString(),
                          p.obtenerTiempoRestante().ToString(),
                          p.obtenerTiempoDeLlegada().ToString(),
                          p.obtenerTiempoDeFinalizacion().ToString(),
                          p.obtenerTiempoDeServicio().ToString(),
                          p.obtenerTiempoDeEspera().ToString(),
                          p.obtenerTiempoDeRetorno().ToString(),
                          p.obtenerTiempoDeRespuesta().ToString(),
                          p.obtenerTiempoTranscurridoBloquedo().ToString(),
                          p.obtenerTamanio().ToString(),
                          p.obtenerEstado(),
                          p.obtenerBanderaRespuesta().ToString(),
                          p.obtenerBanderaTiempoDeLlegada().ToString(),
                          p.obtenerBanEjecutando().ToString(),
                          p.obtenerIndiceParadasQuantum().ToString()
                      };

                      string line = String.Join(",", values);
                      sw.WriteLine(line);
                      sw.Flush();
                    }
                }
            }
        }

        ~ArchivoSuspendidos()
        {
            if (File.Exists(nombreDeArchivo))
            {
                File.Delete(nombreDeArchivo);
            }
        }

    }
}
