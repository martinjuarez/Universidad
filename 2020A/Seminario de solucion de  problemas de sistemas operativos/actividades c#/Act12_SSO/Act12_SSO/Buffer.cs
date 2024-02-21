using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Act12_SSO
{
    public class Buffer
    {
        static int TAMANIO = 40;
        bool[] espacios = new bool[TAMANIO];
        int numeroEspaciosVacios;
        int numeroEspaciosLlenos;

        public Buffer()
        {
            inicializar();
            numeroEspaciosVacios = TAMANIO;
            numeroEspaciosLlenos = 0;
        }

        void inicializar()
        {
            for (int i = 0; i < TAMANIO; i++) 
            {
                espacios[i] = false;
            }
        }

        public int obtenTAMANIO()
        {
            return TAMANIO;
        }

        public void fijaNumeroEspaciosVacios(int numeroEspaciosVacios)
        { this.numeroEspaciosVacios = numeroEspaciosVacios; }

        public int obtenNumeroEspaciosVacios()
        { return numeroEspaciosVacios; }

        public void fijaNumeroEspaciosLlenos(int numeroEspaciosLlenos)
        { this.numeroEspaciosLlenos = numeroEspaciosLlenos; }

        public int obtenNumeroEspaciosLlenos()
        { return numeroEspaciosLlenos; }

        public void fijaIndiceEn(int indice, bool valor)
        {
            espacios[indice] = valor;

            if (valor)
            {
                fijaNumeroEspaciosLlenos(numeroEspaciosLlenos + 1);
                fijaNumeroEspaciosVacios(numeroEspaciosVacios - 1);
            }
            else
            {
                fijaNumeroEspaciosLlenos(numeroEspaciosLlenos - 1);
                fijaNumeroEspaciosVacios(numeroEspaciosVacios + 1);
            }
        }

        public bool obtenIndiceEn(int indice)
        { return espacios[indice]; }
    }
}
