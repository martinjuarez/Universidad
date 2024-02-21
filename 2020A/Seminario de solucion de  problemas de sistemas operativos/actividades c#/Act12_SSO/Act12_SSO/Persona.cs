using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Act12_SSO
{
    public class Persona
    {
        string estado;
        int numeroBooleanosAColocar;
        int posicionEnBuffer;

        public Persona()
        {
            estado = "DORMIDO";
            numeroBooleanosAColocar = 0;
            posicionEnBuffer = 0;
        }

        public void fijaEstado(string estado)
        { this.estado = estado; }

        public string obtenEstado()
        { return estado; }

        public void fijaNumeroBooleanosAColocar(int numeroBooleanosAColocar)
        { this.numeroBooleanosAColocar = numeroBooleanosAColocar; }

        public int obtenNumeroBooleanosAColocar()
        { return numeroBooleanosAColocar; }

        public void fijaPosicionEnBuffer(int posicionEnBuffer)
        { this.posicionEnBuffer = posicionEnBuffer; }

        public int obtenPosicionEnBuffer()
        { return posicionEnBuffer; }
    }
}
