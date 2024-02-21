using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sistemaOperativo
{
    public class Pagina
    {
        int idProceso;
        int numeroDeSegmentos;

        public Pagina()
        {
          
        }

        public int IdProceso
        {
            get { return idProceso; }
            set { idProceso = value; }
        }

        public int NumeroDeSegmentos
        {
            get { return numeroDeSegmentos; }
            set { numeroDeSegmentos = value; }
        }
    }
}
