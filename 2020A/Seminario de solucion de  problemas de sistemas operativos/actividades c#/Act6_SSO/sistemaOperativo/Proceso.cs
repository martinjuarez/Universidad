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
        int tiempoDeLlegada = 0;
        int tiempoDeFinalizacion = 0;
        int tiempoDeServicio = 0;
        int tiempoDeEspera = 0;
        int tiempoDeRetorno = 0;
        int tiempoDeRespuesta = 0;
        int tiempoTranscurridoBloqueado = 0;
        bool estadoActivoBloqueado = true;
        bool estadoTerminado = false;
        bool estadoRespuesta = false;
        bool estadoTTL = true;

        public Proceso()
        {
           
        }

        public bool obtenerEstadoRespuesta()
        {
            return estadoRespuesta;
        }

        public void fijarEstadoRespuesta(bool _estadoRespuesta)
        {
            estadoRespuesta = _estadoRespuesta;
        }

        public bool obtenerEstadoTTL()
        {
            return estadoTTL;
        }

        public void fijarEstadoTTL(bool _estadoTTL)
        {
            estadoTTL = _estadoTTL;
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

        public int obtenerTiempoDeLlegada()
        {
            return tiempoDeLlegada;
        }

        public int obtenerTiempoDeFinalizacion()
        {
            return tiempoDeFinalizacion;
        }

        public int obtenerTiempoDeServicio()
        {
            return tiempoDeServicio;
        }

        public int obtenerTiempoDeEspera()
        {
            return tiempoDeEspera;
        }

        public int obtenerTiempoDeRetorno()
        {
            return tiempoDeRetorno;
        }

        public int obtenerTiempoDeRespuesta()
        {
            return tiempoDeRespuesta;
        }

        public int obtenerTiempoTranscurridoBloquedo()
        {
            return tiempoTranscurridoBloqueado;
        }

        public bool obtenerEstadoActivoBloqueado()
        {
            return estadoActivoBloqueado;
        }

        public bool obtenerEstadoTerminado()
        {
            return estadoTerminado;
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

        public void fijarTiempoDeLlegada(int _tiempoDeLlegada)
        {
            tiempoDeLlegada = _tiempoDeLlegada;
        }

        public void fijarTiempoDeFinalizacion(int _tiempoDeFinalizacion)
        {
            tiempoDeFinalizacion = _tiempoDeFinalizacion;
        }

        public void fijarTiempoDeServicio(int _tiempoDeServicio)
        {
            tiempoDeServicio = _tiempoDeServicio;
        }

        public void fijarTiempoDeEspera(int _tiempoDeEspera)
        {
            tiempoDeEspera = _tiempoDeEspera;
        }

        public void fijarTiempoDeRetorno(int _tiempoDeRetorno)
        {
            tiempoDeRetorno = _tiempoDeRetorno;
        }

        public void fijarTiempoDeRespuesta(int _tiempoDeRespuesta)
        {
            tiempoDeRespuesta = _tiempoDeRespuesta;
        }

        public void fijarTiempoTranscurridoBloqueado(int _tiempoTranscurridoBloqueado)
        {
            tiempoTranscurridoBloqueado = _tiempoTranscurridoBloqueado;
        }

        public void fijarEstadoActivoBloqueado(bool _estadoActivoBloqueado)
        {
            estadoActivoBloqueado = _estadoActivoBloqueado;
        }

        public void fijarEstadoTerminado(bool _estadoTerminado)
        {
            estadoTerminado = _estadoTerminado;
        }
    }
}
