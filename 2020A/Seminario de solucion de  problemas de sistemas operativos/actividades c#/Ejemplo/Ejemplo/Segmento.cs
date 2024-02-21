using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejemplo
{
    public class Segmento
    {
        int id;
        string color;

        public Segmento(int id, string color)
        {
            this.id = id;
            this.color = color;
        }

        public int Id
        {
            get { return id; }
            set { id = value; }
        }

        public string Color
        {
            get { return color; }
            set { color = value; }
        }
    }
}
