using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Windows.Input;

namespace sistemaOperativo
{
    public partial class ventanaPrincipal : Form
    {
        Random rnd = new Random();
        Quantum quantum = new Quantum();

        int numeroDeQuantum = 0;
        int cantidadDeProcesosAEjecutar = 0;
        int contadorGlobal = 0;
        string teclaPresionada;

        public ventanaPrincipal()
        {
            InitializeComponent();
            this.KeyPreview = true;
        }

        private void listView3_SelectedIndexChanged(object sender, EventArgs e)
        {

        }


        public bool esNumero(string comprueba)
        {
            double Numero;
            if (comprueba == null)
                return false;
            return Double.TryParse(comprueba, System.Globalization.NumberStyles.Any, System.Globalization.NumberFormatInfo.InvariantInfo, out Numero);
        }

        private void textBoxCantidadDeProcesos_TextChanged(object sender, EventArgs e)
        {
            TextBox textBoxNumero = (TextBox)sender;

            if (!esNumero(textBoxNumero.Text))
            {
                textBoxNumero.Text = String.Empty;
            }
        }

        private void botonIniciarProcesos_Click(object sender, EventArgs e)
        {
            string numeroDeProcesosEnCadena = textBoxCantidadDeProcesos.Text;
            string numeroDeQuantumEnCadena = textBoxQuantum.Text;

            if (numeroDeProcesosEnCadena == "")
            {
                MessageBox.Show("¡Ingrese la Cantidad de Procesos!");
            }
            else if (numeroDeQuantumEnCadena == "")
            {
                MessageBox.Show("¡Ingrese el Quantum!");
            }
            else if (cantidadDeProcesosAEjecutar >= 1 && cantidadDeProcesosAEjecutar <= 100)
            {
                MessageBox.Show("Debe ser un número mayor o igual a 0 y menor o igual a 30");
            }
            else
            {
                cantidadDeProcesosAEjecutar = Convert.ToInt32(numeroDeProcesosEnCadena);
                numeroDeQuantum = Convert.ToInt32(numeroDeQuantumEnCadena);

                textBoxCantidadDeProcesos.Enabled = false;
                textBoxQuantum.Enabled = false;
                botonIniciarProcesos.Enabled = false;
                botonLimpiar.Enabled = false;
                textBoxCantidadDeProcesos.Text = "";

                generarProcesos();
            }
        }

        bool validarOperacionConCero(int numero1, string opeMate, int numero2)
        {
            if (opeMate == "/" || opeMate == "%" || opeMate == "MOD")
            {
                try
                {
                    Console.WriteLine(numero1 / numero2);
                    return true;
                }
                catch (DivideByZeroException)
                {
                    Console.WriteLine("Division of {0} by zero.", numero1);
                    return false;
                }
            }
            else
            {
                return true;
            }
        }

        bool existeId(int idBuscado, ref List<Proceso> lisProcesosGenerados)
        {
            var resultado = lisProcesosGenerados.Find(proceso => proceso.obtenerId() == idBuscado);
            if (resultado == null)
                return false;
            else
                return true;
        }

        async Task ejecutarEnMemoria(List<Proceso> procesosGenerados)
        {
            Proceso[] procesoEjecutando = new Proceso[4];
            string[] ESTADOS_PROCESO = new string[] { "NUEVO", "LISTO", "BLOQ", "T-NORMAL", "T-ERROR" };
            int indiceListaProcesosListos = 0;
            int limiteDeMemoria = 4;

            while ((indiceListaProcesosListos < procesosGenerados.Count) && (indiceListaProcesosListos < limiteDeMemoria))
            {
                procesoEjecutando[indiceListaProcesosListos] = procesosGenerados[indiceListaProcesosListos];
                procesoEjecutando[indiceListaProcesosListos].fijarEstado(ESTADOS_PROCESO[1]);
                procesoEjecutando[indiceListaProcesosListos].fijarTiempoDeLlegada(contadorGlobal);
                procesoEjecutando[indiceListaProcesosListos].fijarBanderaTiempoDeLlegada(false);

                indiceListaProcesosListos++;
            }

            procesoEjecutando[0].fijarBanEjecutando(true);

            int tamanioDeMemoria = indiceListaProcesosListos;
            int contadorProcesosTerminados = 0;
            int i = 0;
            int segundo = 0;
            int limiteDeListView = indiceListaProcesosListos;

            int numero1 = 0;
            int numero2 = 0;
            int resOpe = 0;
            int paradaQuantumActual = 0;

            bool banderaPausaYContinua = true;
            bool banderaError = false;
            bool banderaInterrupcion = false;
            bool banderaProcesoNuevo = false;
            bool banderaBloquesDeControlDeProcesos = false;

            int procesosNuevosPendientes = procesosGenerados.Count - indiceListaProcesosListos;
            labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString();
            labelProcesosNuevosPendientesMostrar.Refresh();

            while (contadorProcesosTerminados < procesosGenerados.Count)
            {
                switch (teclaPresionada)
                {
                    case "E":
                        {
                            if (banderaPausaYContinua)
                            {
                                banderaInterrupcion = true;
                            }
                        }
                        break;
                    case "W":
                        {
                            if (banderaPausaYContinua)
                            {
                                banderaError = true;
                            }
                        }
                        break;
                    case "N":
                        {
                            if (banderaPausaYContinua)
                            {
                                banderaProcesoNuevo = true;
                            }
                        }
                        break;
                    case "B":
                        {
                            if (banderaPausaYContinua)
                            {
                                banderaBloquesDeControlDeProcesos = true;
                                banderaPausaYContinua = false;
                            }
                        }
                        break;
                    case "P":
                        {
                            banderaPausaYContinua = false;
                        }
                        break;
                    case "C":
                        {
                            banderaPausaYContinua = true;
                            listViewBloqueConProcesos.Items.Clear();
                        }
                        break;
                }
                teclaPresionada = "";

                if (banderaPausaYContinua)
                {
                    labelContadorGlobalImprime.Text = contadorGlobal.ToString();
                    labelContadorGlobalImprime.Refresh();
                    contadorGlobal++;

                    listViewProcesosListos.Items.Clear();
                    listViewProcesosListos.Refresh();

                    for (int indProListo = 1; indProListo < limiteDeListView; indProListo++)
                    {
                        if (procesoEjecutando[indProListo].obtenerEstado() == ESTADOS_PROCESO[1])
                        {
                            ListViewItem listViewProLis = new ListViewItem(procesoEjecutando[indProListo].obtenerId().ToString());
                            listViewProLis.SubItems.Add(procesoEjecutando[indProListo].obtenerTiempoMaximoEstimado().ToString());
                            listViewProLis.SubItems.Add(procesoEjecutando[indProListo].obtenerTiempoTranscurrido().ToString());
                            listViewProcesosListos.Items.Add(listViewProLis);
                            listViewProcesosListos.Refresh();
                        }
                    }

                    listViewProcesosBloqueados.Items.Clear();
                    listViewProcesosBloqueados.Refresh();

                    for (int indProBlo = 0; indProBlo < limiteDeListView; indProBlo++)
                    {
                        if (procesoEjecutando[indProBlo].obtenerEstado() == ESTADOS_PROCESO[2])
                        {
                            if (procesoEjecutando[indProBlo].obtenerTiempoTranscurridoBloquedo() == 9)
                            {
                                procesoEjecutando[indProBlo].fijarEstado(ESTADOS_PROCESO[1]);
                                procesoEjecutando[indProBlo].fijarTiempoTranscurridoBloqueado(0);
                            }
                            else
                            {
                                int tiempoTraBloqueado = procesoEjecutando[indProBlo].obtenerTiempoTranscurridoBloquedo() + 1;
                                procesoEjecutando[indProBlo].fijarTiempoTranscurridoBloqueado(tiempoTraBloqueado);

                                ListViewItem listViewLisPedNue = new ListViewItem(procesoEjecutando[indProBlo].obtenerId().ToString());
                                listViewLisPedNue.SubItems.Add(procesoEjecutando[indProBlo].obtenerTiempoTranscurridoBloquedo().ToString());
                                listViewProcesosBloqueados.Items.Add(listViewLisPedNue);
                                listViewProcesosBloqueados.Refresh();
                            }
                        }
                    }

                    if (procesoEjecutando[i].obtenerEstado() == ESTADOS_PROCESO[1])
                    {
                        numero1 = 0;
                        numero2 = 0;
                        resOpe = 0;
                        paradaQuantumActual = 0; 

                        numero1 = procesoEjecutando[i].obtenerNumeroUno();
                        numero2 = procesoEjecutando[i].obtenerNumeroDos();
                        procesoEjecutando[i].fijarResultadoDeOperacion(0);
                        paradaQuantumActual = procesoEjecutando[i].obtenerIndiceParadasQuantum();


                        switch (procesoEjecutando[i].obtenerOperadorMatematico())
                        {
                            case "+":
                                procesoEjecutando[i].fijarResultadoDeOperacion(numero1 + numero2);
                                break;
                            case "-":
                                procesoEjecutando[i].fijarResultadoDeOperacion(numero1 - numero2);
                                break;
                            case "*":
                                procesoEjecutando[i].fijarResultadoDeOperacion(numero1 * numero2);
                                break;
                            case "/":
                                procesoEjecutando[i].fijarResultadoDeOperacion(numero1 / numero2);
                                break;
                            case "%":
                                resOpe = (numero1 * numero2) / 100;
                                procesoEjecutando[i].fijarResultadoDeOperacion(resOpe);
                                break;
                            case "MOD":
                                procesoEjecutando[i].fijarResultadoDeOperacion(numero1 % numero2);
                                break;
                            case "RAIZ":
                                resOpe = Convert.ToInt32(Math.Pow(numero2, (1 / (double)numero1)));
                                procesoEjecutando[i].fijarResultadoDeOperacion(resOpe);
                                break;
                        }

                        procesoEjecutando[i].fijarTiempoRestante(procesoEjecutando[i].obtenerTiempoMaximoEstimado() - segundo);
                        procesoEjecutando[i].fijarTiempoTranscurrido(segundo);
                        procesoEjecutando[i].fijarTiempoDeServicio(procesoEjecutando[i].obtenerTiempoTranscurrido());
                        procesoEjecutando[i].fijarBanEjecutando(true);

                        if (procesoEjecutando[i].obtenerBanderaRespuesta() == false)
                        {
                            procesoEjecutando[i].fijarBanderaRespuesta(true);
                            procesoEjecutando[i].fijarTiempoDeRespuesta(procesoEjecutando[i].obtenerTiempoDeLlegada(), contadorGlobal);
                        }

                        listViewProcesoEnEjecucion.Items.Clear();
                        listViewProcesoEnEjecucion.Refresh();
                        ListViewItem listViewProEnEje = new ListViewItem(procesoEjecutando[i].obtenerId().ToString());
                        listViewProEnEje.SubItems.Add(procesoEjecutando[i].obtenerOpeMatematica());
                        listViewProEnEje.SubItems.Add(procesoEjecutando[i].obtenerTiempoMaximoEstimado().ToString());
                        listViewProEnEje.SubItems.Add(procesoEjecutando[i].obtenerTiempoTranscurrido().ToString());
                        listViewProEnEje.SubItems.Add(procesoEjecutando[i].obtenerTiempoRestante().ToString());
                        listViewProcesoEnEjecucion.Items.Add(listViewProEnEje);
                        listViewProcesoEnEjecucion.Refresh();

                        if (banderaError)
                        {
                            procesoEjecutando[i].fijarEstado(ESTADOS_PROCESO[4]);
                            procesoEjecutando[i].fijarBanEjecutando(false);
                            procesoEjecutando[i].fijarTiempoDeFinalizacion(contadorGlobal);
                            procesoEjecutando[i].fijarTiempoDeRetorno(procesoEjecutando[i].obtenerTiempoDeFinalizacion(),
                                                                      procesoEjecutando[i].obtenerTiempoDeLlegada());
                            procesoEjecutando[i].fijarTiempoDeEspera(procesoEjecutando[i].obtenerTiempoDeRetorno()
                                                                     - procesoEjecutando[i].obtenerTiempoDeServicio());

                            ListViewItem listViewProTer = new ListViewItem(procesoEjecutando[i].obtenerId().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerOpeMatematica());
                            listViewProTer.SubItems.Add("ERROR");
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeLlegada().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeFinalizacion().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeServicio().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeEspera().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeRetorno().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeRespuesta().ToString());
                            listViewProcesosTerminados.Items.Add(listViewProTer);
                            listViewProcesosTerminados.Refresh();

                            for (int l = 0; l < tamanioDeMemoria; l++)
                            {
                                if (l != (tamanioDeMemoria - 1))
                                {
                                    procesoEjecutando[l] = procesoEjecutando[l + 1];
                                }
                            }

                            if (indiceListaProcesosListos < procesosGenerados.Count)
                            {
                                procesoEjecutando[tamanioDeMemoria - 1] = procesosGenerados[indiceListaProcesosListos];
                                procesoEjecutando[tamanioDeMemoria - 1].fijarEstado(ESTADOS_PROCESO[1]);

                                if (procesoEjecutando[tamanioDeMemoria - 1].obtenerBanderaTiempoDeLlegada())
                                {
                                    procesoEjecutando[tamanioDeMemoria - 1].fijarBanderaTiempoDeLlegada(false);
                                    procesoEjecutando[tamanioDeMemoria - 1].fijarTiempoDeLlegada(contadorGlobal);
                                }

                                indiceListaProcesosListos++;
                            }
                            else
                            {
                                if (procesoEjecutando[i].obtenerBanderaTiempoDeLlegada())
                                {
                                    procesoEjecutando[i].fijarBanderaTiempoDeLlegada(false);
                                    procesoEjecutando[i].fijarTiempoDeLlegada(contadorGlobal);
                                }

                                tamanioDeMemoria--;
                                limiteDeListView--;
                            }

                            contadorProcesosTerminados++;
                            segundo = 0;
                            segundo = procesoEjecutando[i].obtenerTiempoTranscurrido();

                            procesosNuevosPendientes = procesosGenerados.Count - indiceListaProcesosListos;
                            labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString();
                            labelProcesosNuevosPendientesMostrar.Refresh();

                            banderaError = false;
                        }
                        else if (banderaInterrupcion)
                        {
                            procesoEjecutando[i].fijarEstado(ESTADOS_PROCESO[2]);
                            procesoEjecutando[i].fijarBanEjecutando(false);

                            Proceso auxiliar = procesoEjecutando[i];

                            for (int l = 0; l < tamanioDeMemoria; l++)
                            {
                                if (l != (tamanioDeMemoria - 1))
                                {
                                    procesoEjecutando[l] = procesoEjecutando[l + 1];
                                }
                            }

                            procesoEjecutando[tamanioDeMemoria - 1] = auxiliar;
                            segundo = 0;
                            segundo = procesoEjecutando[i].obtenerTiempoTranscurrido();
                            banderaInterrupcion = false;
                        }
                        else if (segundo == procesoEjecutando[i].obtenerTiempoMaximoEstimado())
                        {
                            procesoEjecutando[i].fijarEstado(ESTADOS_PROCESO[3]);
                            procesoEjecutando[i].fijarBanEjecutando(false);
                            procesoEjecutando[i].fijarTiempoDeFinalizacion(contadorGlobal);
                            procesoEjecutando[i].fijarTiempoDeRetorno(procesoEjecutando[i].obtenerTiempoDeFinalizacion(),
                                                                      procesoEjecutando[i].obtenerTiempoDeLlegada());
                            procesoEjecutando[i].fijarTiempoDeEspera(procesoEjecutando[i].obtenerTiempoDeRetorno()
                                                                     - procesoEjecutando[i].obtenerTiempoDeServicio());

                            ListViewItem listViewProTer = new ListViewItem(procesoEjecutando[i].obtenerId().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerOpeMatematica());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerResultadoDeOperacion());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeLlegada().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeFinalizacion().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeServicio().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeEspera().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeRetorno().ToString());
                            listViewProTer.SubItems.Add(procesoEjecutando[i].obtenerTiempoDeRespuesta().ToString());
                            listViewProcesosTerminados.Items.Add(listViewProTer);
                            listViewProcesosTerminados.Refresh();

                            for (int l = 0; l < tamanioDeMemoria; l++)
                            {
                                if (l != (tamanioDeMemoria - 1))
                                {
                                    procesoEjecutando[l] = procesoEjecutando[l + 1];
                                }
                            }

                            if (indiceListaProcesosListos < procesosGenerados.Count)
                            {
                                procesoEjecutando[tamanioDeMemoria - 1] = procesosGenerados[indiceListaProcesosListos];
                                procesoEjecutando[tamanioDeMemoria - 1].fijarEstado(ESTADOS_PROCESO[1]);
                                if (procesoEjecutando[tamanioDeMemoria - 1].obtenerBanderaTiempoDeLlegada())
                                {
                                    procesoEjecutando[tamanioDeMemoria - 1].fijarBanderaTiempoDeLlegada(false);
                                    procesoEjecutando[tamanioDeMemoria - 1].fijarTiempoDeLlegada(contadorGlobal);
                                }
                                indiceListaProcesosListos++;
                            }
                            else
                            {
                                if (procesoEjecutando[i].obtenerBanderaTiempoDeLlegada())
                                {
                                    procesoEjecutando[i].fijarBanderaTiempoDeLlegada(false);
                                    procesoEjecutando[i].fijarTiempoDeLlegada(contadorGlobal);
                                }

                                tamanioDeMemoria--;
                                limiteDeListView--;
                            }

                            contadorProcesosTerminados++;
                            segundo = 0;
                            segundo = procesoEjecutando[i].obtenerTiempoTranscurrido();

                            procesosNuevosPendientes = procesosGenerados.Count - indiceListaProcesosListos;
                            labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString();
                            labelProcesosNuevosPendientesMostrar.Refresh();
                        }
                        else if( segundo == procesoEjecutando[i].obtenerParadasQuantum()[paradaQuantumActual] )
                        {
                            procesoEjecutando[i].fijarIndiceParadasQuantum(paradaQuantumActual + 1);
                            procesoEjecutando[i].fijarEstado(ESTADOS_PROCESO[1]);
                            procesoEjecutando[i].fijarBanEjecutando(false);

                            Proceso auxiliar = procesoEjecutando[i];

                            for (int l = 0; l < tamanioDeMemoria; l++)
                            {
                                if (l != (tamanioDeMemoria - 1))
                                {
                                    procesoEjecutando[l] = procesoEjecutando[l + 1];
                                }
                            }

                            procesoEjecutando[tamanioDeMemoria - 1] = auxiliar;
                            segundo = 0;
                            segundo = procesoEjecutando[i].obtenerTiempoTranscurrido();
                        }
                        else
                        {
                            segundo++;
                        }
                    }
                    else
                    {
                        int indiceMemoria = 0;
                        bool banderaProcesoListoEncontrado = false;

                        while (indiceMemoria < tamanioDeMemoria)
                        {
                            if (procesoEjecutando[indiceMemoria].obtenerEstado() == ESTADOS_PROCESO[1])
                            {
                                banderaProcesoListoEncontrado = true;
                                break;
                            }
                            indiceMemoria++;
                        }

                        if (banderaProcesoListoEncontrado)
                        {
                            Proceso auxiliar = procesoEjecutando[indiceMemoria];

                            for (int posMemoria = indiceMemoria; posMemoria > 0; posMemoria--)
                            {
                                procesoEjecutando[posMemoria] = procesoEjecutando[posMemoria - 1];
                            }

                            procesoEjecutando[i] = auxiliar;

                            segundo = 0;
                            segundo = procesoEjecutando[i].obtenerTiempoTranscurrido();
                        }
                        else
                        {
                            listViewProcesoEnEjecucion.Items.Clear();
                            listViewProcesoEnEjecucion.Refresh();
                        }
                    }


                    if (banderaProcesoNuevo)
                    {
                        procesosGenerados.Add(nuevoProceso(ref procesosGenerados));
                        bool banderaEspacioMemoria = false;
                        bool banderaProcesoBloqueado = false;

                        if (tamanioDeMemoria < limiteDeMemoria)
                        {
                            for (int indiceMemoria = 0; indiceMemoria < tamanioDeMemoria; indiceMemoria++)
                            {
                                if (procesoEjecutando[indiceMemoria].obtenerEstado() == ESTADOS_PROCESO[2])
                                {
                                    banderaEspacioMemoria = true;
                                    tamanioDeMemoria++;

                                    for (int posMemoria = tamanioDeMemoria - 1; posMemoria > indiceMemoria; posMemoria--)
                                    {
                                        procesoEjecutando[posMemoria] = procesoEjecutando[posMemoria - 1];
                                    }

                                    procesoEjecutando[indiceMemoria] = procesosGenerados[indiceListaProcesosListos];
                                    procesoEjecutando[indiceMemoria].fijarEstado(ESTADOS_PROCESO[1]);
                                    procesoEjecutando[indiceMemoria].fijarTiempoDeLlegada(contadorGlobal);
                                    procesoEjecutando[indiceMemoria].fijarBanderaTiempoDeLlegada(false);

                                    if (indiceMemoria == 0)
                                    {
                                        segundo = 0;
                                        segundo = procesoEjecutando[indiceMemoria].obtenerTiempoTranscurrido();
                                    }

                                    banderaProcesoBloqueado = true;
                                    break;
                                }
                            }

                            if (banderaProcesoBloqueado == false)
                            {
                                procesoEjecutando[tamanioDeMemoria] = procesosGenerados[indiceListaProcesosListos];
                                procesoEjecutando[tamanioDeMemoria].fijarEstado(ESTADOS_PROCESO[1]);
                                procesoEjecutando[tamanioDeMemoria].fijarTiempoDeLlegada(contadorGlobal);
                                procesoEjecutando[tamanioDeMemoria].fijarBanderaTiempoDeLlegada(false);


                                if (tamanioDeMemoria == 0)
                                {
                                    segundo = 0;
                                    segundo = procesoEjecutando[tamanioDeMemoria].obtenerTiempoTranscurrido();
                                }
                            }

                            if (banderaEspacioMemoria == false)
                            {
                                tamanioDeMemoria++;
                            }

                            indiceListaProcesosListos++;
                            limiteDeListView++;
                        }
                        else
                        {
                            procesosNuevosPendientes++;
                            labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString();
                            labelProcesosNuevosPendientesMostrar.Refresh();
                        }

                        banderaProcesoNuevo = false;
                    }

                }

                if (banderaBloquesDeControlDeProcesos == true && banderaPausaYContinua == false)
                {
                    foreach (Proceso bcpDeProceso in procesosGenerados)
                    {
                        if (bcpDeProceso.obtenerEstado() == ESTADOS_PROCESO[0])
                        {
                            ListViewItem listViewBcpPro = new ListViewItem(bcpDeProceso.obtenerId().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerEstado());
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add("");
                            listViewBloqueConProcesos.Items.Add(listViewBcpPro);
                            listViewBloqueConProcesos.Refresh();
                        }
                        else if (bcpDeProceso.obtenerEstado() == ESTADOS_PROCESO[3])
                        {
                            ListViewItem listViewBcpPro = new ListViewItem(bcpDeProceso.obtenerId().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerEstado());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerOpeMatematica());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerResultadoDeOperacion());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeLlegada().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeFinalizacion().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeRetorno().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeEspera().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeServicio().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeRespuesta().ToString());
                            listViewBloqueConProcesos.Items.Add(listViewBcpPro);
                            listViewBloqueConProcesos.Refresh();
                        }
                        else if (bcpDeProceso.obtenerEstado() == ESTADOS_PROCESO[4])
                        {
                            ListViewItem listViewBcpPro = new ListViewItem(bcpDeProceso.obtenerId().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerEstado());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerOpeMatematica());
                            listViewBcpPro.SubItems.Add("ERROR");
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeLlegada().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeFinalizacion().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeRetorno().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeEspera().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeServicio().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeRespuesta().ToString());
                            listViewBloqueConProcesos.Items.Add(listViewBcpPro);
                            listViewBloqueConProcesos.Refresh();
                        }
                        else if (bcpDeProceso.obtenerEstado() == ESTADOS_PROCESO[2])
                        {
                            bcpDeProceso.fijarTiempoDeFinalizacion(contadorGlobal);
                            bcpDeProceso.fijarTiempoDeRetorno(bcpDeProceso.obtenerTiempoDeFinalizacion(), bcpDeProceso.obtenerTiempoDeLlegada());
                            bcpDeProceso.fijarTiempoDeEspera((bcpDeProceso.obtenerTiempoDeRetorno() - 1) - bcpDeProceso.obtenerTiempoDeServicio());

                            ListViewItem listViewBcpPro = new ListViewItem(bcpDeProceso.obtenerId().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerEstado());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerOpeMatematica());
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeLlegada().ToString());
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeEspera().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeServicio().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeRespuesta().ToString());
                            listViewBloqueConProcesos.Items.Add(listViewBcpPro);
                            listViewBloqueConProcesos.Refresh();
                        }
                        else if (bcpDeProceso.obtenerEstado() == ESTADOS_PROCESO[1] && bcpDeProceso.obtenerBanEjecutando() == false)
                        {
                            bcpDeProceso.fijarTiempoDeFinalizacion(contadorGlobal);
                            bcpDeProceso.fijarTiempoDeRetorno(bcpDeProceso.obtenerTiempoDeFinalizacion(), bcpDeProceso.obtenerTiempoDeLlegada());
                            bcpDeProceso.fijarTiempoDeEspera((bcpDeProceso.obtenerTiempoDeRetorno() - 1) - bcpDeProceso.obtenerTiempoDeServicio());

                            ListViewItem listViewBcpPro = new ListViewItem(bcpDeProceso.obtenerId().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerEstado());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerOpeMatematica());
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeLlegada().ToString());
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeEspera().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeServicio().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeRespuesta().ToString());
                            listViewBloqueConProcesos.Items.Add(listViewBcpPro);
                            listViewBloqueConProcesos.Refresh();
                        }
                        else if (bcpDeProceso.obtenerEstado() == ESTADOS_PROCESO[1] && bcpDeProceso.obtenerBanEjecutando() == true)
                        {
                            bcpDeProceso.fijarTiempoDeFinalizacion(contadorGlobal);
                            bcpDeProceso.fijarTiempoDeRetorno(bcpDeProceso.obtenerTiempoDeFinalizacion(), bcpDeProceso.obtenerTiempoDeLlegada());
                            bcpDeProceso.fijarTiempoDeEspera((bcpDeProceso.obtenerTiempoDeRetorno() - 1) - bcpDeProceso.obtenerTiempoDeServicio());

                            ListViewItem listViewBcpPro = new ListViewItem(bcpDeProceso.obtenerId().ToString());
                            listViewBcpPro.SubItems.Add("EJEC");
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerOpeMatematica());
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeLlegada().ToString());
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add("");
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeEspera().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeServicio().ToString());
                            listViewBcpPro.SubItems.Add(bcpDeProceso.obtenerTiempoDeRespuesta().ToString());
                            listViewBloqueConProcesos.Items.Add(listViewBcpPro);
                            listViewBloqueConProcesos.Refresh();
                        }
                    }
                    banderaBloquesDeControlDeProcesos = false;
                }

                await Task.Delay(800);
            }

            listViewProcesosListos.Items.Clear();
            listViewProcesosListos.Refresh();

            listViewProcesoEnEjecucion.Items.Clear();
            listViewProcesoEnEjecucion.Refresh();

            botonLimpiar.Enabled = true;
        }

        Proceso nuevoProceso(ref List<Proceso> listaProcesosGenerados)
        {
            int numeroUno = 0;
            string operadorMatematico = "";
            int numeroDos = 0;
            int id = 0;
            int tme = 0;
            string[] lisOpe = new string[] { "*", "-", "*", "/", "%", "MOD", "RAIZ" };

            numeroUno = rnd.Next(0, 200);
            operadorMatematico = lisOpe[rnd.Next(0, 6)];
            numeroDos = rnd.Next(0, 200);
            id = rnd.Next(0, 200);
            tme = rnd.Next(5, 11);

            while (!(tme > 0))
            {
                tme = rnd.Next(5, 11);
            }

            while (!validarOperacionConCero(numeroUno, operadorMatematico, numeroDos))
            {
                numeroUno = rnd.Next(0, 200);
                operadorMatematico = lisOpe[rnd.Next(0, 6)];
                numeroDos = rnd.Next(0, 200);
            }

            while (existeId(id, ref listaProcesosGenerados))
            {
                id = rnd.Next(0, 200);
            }

            Proceso procesoGenerado = new Proceso();
            procesoGenerado.fijarNumeroUno(numeroUno);
            procesoGenerado.fijarOperadorMatematico(operadorMatematico);
            procesoGenerado.fijarNumeroDos(numeroDos);
            procesoGenerado.fijarId(id);
            procesoGenerado.fijarTiempoMaximoEstimado(tme);
            procesoGenerado.fijarParadasQuantum(quantum.calcularParadas(numeroDeQuantum, procesoGenerado.obtenerTiempoMaximoEstimado()));

            return procesoGenerado;
        }

        void generarProcesos()
        {
            List<Proceso> listaProcesosGenerados = new List<Proceso>();

            for (int i = 1; i <= cantidadDeProcesosAEjecutar; i++)
            {
                listaProcesosGenerados.Add(nuevoProceso(ref listaProcesosGenerados));
            }

            ejecutarEnMemoria(listaProcesosGenerados);
        }

        private void botonAgregarProceso_Click(object sender, EventArgs e)
        {

        }

        private void textBoxIdDelProceso_TextChanged(object sender, EventArgs e)
        {
            TextBox textBoxId = (TextBox)sender;

            if (!esNumero(textBoxId.Text))
            {
                textBoxId.Text = String.Empty;
            }
        }

        private void textBoxTieMaxEst_TextChanged(object sender, EventArgs e)
        {
            TextBox textBoxTieMaxEst = (TextBox)sender;

            if (!esNumero(textBoxTieMaxEst.Text))
            {
                textBoxTieMaxEst.Text = String.Empty;
            }
        }

        private void textBoxNumeroUno_TextChanged(object sender, EventArgs e)
        {
            TextBox textBoxNumeroUno = (TextBox)sender;

            if (!esNumero(textBoxNumeroUno.Text))
            {
                textBoxNumeroUno.Text = String.Empty;
            }
        }

        private void textBoxNumeroDos_TextChanged(object sender, EventArgs e)
        {
            TextBox textBoxNumeroDos = (TextBox)sender;

            if (!esNumero(textBoxNumeroDos.Text))
            {
                textBoxNumeroDos.Text = String.Empty;
            }
        }

        private void textBoxQuantum_TextChanged(object sender, EventArgs e)
        {
            TextBox textBoxQuantum = (TextBox)sender;

            if (!esNumero(textBoxQuantum.Text))
            {
                textBoxQuantum.Text = String.Empty;
            }
        }

        private void botonLimpiar_Click(object sender, EventArgs e)
        {
            textBoxCantidadDeProcesos.Enabled = true;
            textBoxQuantum.Enabled = true;
            textBoxQuantum.Text = "";
            botonIniciarProcesos.Enabled = true;
            listViewProcesosTerminados.Items.Clear();
            labelContadorGlobalImprime.Text = "-------------";
            labelProcesosNuevosPendientesMostrar.Text = "-------------";
            cantidadDeProcesosAEjecutar = 0;
            contadorGlobal = 0;
            MessageBox.Show("¡Todo ha sido limpiado!");
        }

        private void listViewProcesosEnEjecucion_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void labelContadorGlobal_Click(object sender, EventArgs e)
        {

        }

        private void labelContadorGlobalImprime_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void ventanaPrincipal_Load(object sender, EventArgs e)
        {

        }

        private void ventanaPrincipal_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode.ToString())
            {
                case "E":
                    teclaPresionada = "E";
                    break;
                case "W":
                    teclaPresionada = "W";
                    break;
                case "P":
                    teclaPresionada = "P";
                    break;
                case "C":
                    teclaPresionada = "C";
                    break;
                case "N":
                    teclaPresionada = "N";
                    break;
                case "B":
                    teclaPresionada = "B";
                    break;
                default:
                    teclaPresionada = "";
                    break;
            }
        }
    }
}
