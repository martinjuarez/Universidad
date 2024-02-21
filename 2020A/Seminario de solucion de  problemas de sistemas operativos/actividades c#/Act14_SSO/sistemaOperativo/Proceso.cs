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
        string operacionMatematica = "";
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
        int tamanio = 0;
        
        string estado = "NUEVO";

        bool banderaRespuesta = false;
        bool banderaDeTiempoLlegada = true;
        bool banEjecutando = false;

        List<int> paradasQuantum = new List<int>();
        int indiceParadasQuantum = 0;

        public Proceso()
        {
           
        }

        public int obtenerTamanio()
        {
            return tamanio;
        }

        public void fijarTamanio(int _tamanio)
        {
            tamanio = _tamanio;
        }

        public void fijarParadasQuantum(List<int> _paradasQuantum)
        {
            paradasQuantum = _paradasQuantum;
        }

        public List<int> obtenerParadasQuantum()
        {
            return paradasQuantum;
        }

        public void fijarIndiceParadasQuantum(int _indiceParadasQuantum)
        {
            if ( _indiceParadasQuantum < paradasQuantum.Count )
            {
                indiceParadasQuantum = _indiceParadasQuantum;
            }
        }

        public int obtenerIndiceParadasQuantum()
        {
            return indiceParadasQuantum;
        }

        public void fijarBanEjecutando(bool _banEjecutando)
        {
            banEjecutando = _banEjecutando;
        }

        public bool obtenerBanEjecutando()
        {
            return banEjecutando;
        }

        public string obtenerOpeMatematica()
        {
            operacionMatematica = obtenerNumeroUno().ToString() +
                                  obtenerOperadorMatematico() +
                                  obtenerNumeroDos().ToString();
            return operacionMatematica;
        }

        public void fijarResultado(string _operacionMatematica)
        {
            operacionMatematica = _operacionMatematica;
        }

        public bool obtenerBanderaRespuesta()
        {
            return banderaRespuesta;
        }

        public void fijarBanderaRespuesta(bool _banderaRespuesta)
        {
            banderaRespuesta = _banderaRespuesta;
        }

        public bool obtenerBanderaTiempoDeLlegada()
        {
            return banderaDeTiempoLlegada;
        }

        public void fijarBanderaTiempoDeLlegada(bool _banderaDeTiempoLlegada)
        {
            banderaDeTiempoLlegada = _banderaDeTiempoLlegada;
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

        public string obtenerResultadoDeOperacion()
        {
            return resultadoDeOperacion.ToString();
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
        
        public string obtenerEstado()
        {
            return estado;
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
            tiempoDeRetorno = tiempoDeFinalizacion - tiempoDeLlegada;
        }

        public void fijarTiempoDeServicio(int _tiempoDeServicio)
        {
            tiempoDeServicio = _tiempoDeServicio;
        }

        public void fijarTiempoDeEspera(int _tiempoDeEspera)
        {
            if( _tiempoDeEspera== -1 )
            { _tiempoDeEspera = 0; }

            tiempoDeEspera = _tiempoDeEspera;
        }

        public void fijarTiempoDeRetorno(int _tiempoDeFinalizacion, int _tiempoDeLlegada)
        {
            tiempoDeRetorno = _tiempoDeFinalizacion - _tiempoDeLlegada;
        }

        public void fijarTiempoDeRespuesta(int _tiempoDeLlegada, int contadorGlobal)
        {
            tiempoDeRespuesta = contadorGlobal - _tiempoDeLlegada;
        }

        public void fijarTiempoTranscurridoBloqueado(int _tiempoTranscurridoBloqueado)
        {
            tiempoTranscurridoBloqueado = _tiempoTranscurridoBloqueado;
        }

        public void fijarEstado(string _estado)
        {
            estado = _estado;
        }
    }
}
