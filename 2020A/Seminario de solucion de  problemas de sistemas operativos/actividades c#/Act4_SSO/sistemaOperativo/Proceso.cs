using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sistemaOperativo
{
    public class Proceso
    {
        int numeroUno = 0;
        string operadorMatematico = "";
        int numeroDos = 0;
        int id = 0;
        int tiempoMaximoEstimado = 0;
        int resultadoDeOperacion = 0;
        int tiempoTranscurrido = 0;
        int tiempoRestante = 0;

        public Proceso()
        {
           
        }
        
        public int obtenerNumeroUno()
        {
            return numeroUno;
        }

        public string obtenerOperadorMatematico()
        {
            return operadorMatematico;
        }

        public int obtenerNumeroDos()
        {
            return numeroDos;
        }

        public int obtenerId()
        {
            return id;
        }

        public int obtenerTiempoMaximoEstimado()
        {
            return tiempoMaximoEstimado;
        }

        public int obtenerResultadoDeOperacion()
        {
            return resultadoDeOperacion;
        }

        public int obtenerTiempoTranscurrido()
        {
            return tiempoTranscurrido;
        }

        public int obtenerTiempoRestante()
        {
            return tiempoRestante;
        }

        public void fijarNumeroUno(int _numeroUno)
        {
            numeroUno = _numeroUno;
        }

        public void fijarOperadorMatematico(string _operadorMatematico)
        {
            operadorMatematico = _operadorMatematico;
        }

        public void fijarNumeroDos(int _numeroDos)
        {
            numeroDos = _numeroDos;
        }

        public void fijarId(int _id)
        {
            id = _id;
        }

        public void fijarTiempoMaximoEstimado(int _tiempoMaximoEstimado)
        {
            tiempoMaximoEstimado = _tiempoMaximoEstimado;
        }

        public void fijarResultadoDeOperacion(int _resultadoDeOperacion)
        {
            resultadoDeOperacion = _resultadoDeOperacion;
        }

        public void fijarTiempoTranscurrido(int _tiempoTranscurrido)
        {
            tiempoTranscurrido = _tiempoTranscurrido;
        }

        public void fijarTiempoRestante(int _tiempoRestante)
        {
            tiempoRestante = _tiempoRestante;
        }
    }
}
