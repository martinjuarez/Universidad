using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo
{
    public class Proceso
    {
        int id;
        int tamanio;

        public Proceso(int id, int tamanio)
        {
            this.id = id;
            this.tamanio = tamanio;
        }

        public int Id 
        {
            get { return id; }
            set { id = value; }
        }

        public int Tamanio
        {
            get { return tamanio; }
            set { tamanio = value; }
        }
    }
}
