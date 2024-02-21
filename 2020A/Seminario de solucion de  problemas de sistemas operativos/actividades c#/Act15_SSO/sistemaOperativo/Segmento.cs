using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sistemaOperativo
{
    public class Segmento
    {
        int idProceso;
        string color;

        public Segmento(int _idProceso, string _estado, bool banEjecutando)
        {
            idProceso = _idProceso;
            color = asignaColor(_estado, banEjecutando);
        }

        public void fijaIdProceso(int _idProceso)
        {
            idProceso = _idProceso;
        }

        public int obtenIdProceso()
        {
            return idProceso;
        }

        public void fijaColor(string _estado, bool banEjecutando)
        {
            color = asignaColor(_estado, banEjecutando);
        }

        public string obtenColor()
        {
            return color;
        }

        string asignaColor(string estado, bool banEjecutando)
        {
            string colorAsignado = "";

            if (estado == "LISTO" && banEjecutando)
                colorAsignado = "ROJO";

            else if (estado == "BLOQ")
                colorAsignado = "MORADO";

            else if (estado == "LISTO")
                colorAsignado = "AZUL";
            else
                colorAsignado = "BLANCO";

            return colorAsignado;
        }
    }
}
