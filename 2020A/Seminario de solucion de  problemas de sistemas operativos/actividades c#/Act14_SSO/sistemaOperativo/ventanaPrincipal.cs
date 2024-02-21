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
        PictureBox[] picturesBoxes = new PictureBox[128];
        Label[] labels = new Label[128];
        Segmento[] arregloSegmentos = new Segmento[128];

        int numeroDeQuantum = 0;
        int cantidadDeProcesosAEjecutar = 0;
        int contadorGlobal = 0;
        string teclaPresionada;
        int totalDeSegmentos = 128;
        int marcosDisponibles = 32;
        int segmentoEnTabla = 0;
        int numeroDeMarcosAUsar = 0;
        int numeroDeSegmentosAUsar = 0;
        int segmentosUsados = 0;
        bool segementoLibreUsado = false;

        public ventanaPrincipal()
        {
            InitializeComponent();
            this.KeyPreview = true;

            Control[] matchesPictures;
            Control[] matchesLabels;
            for (int i = 0; i < 128; i++)
            {
                matchesPictures = this.Controls.Find("pictureBox0" + (i + 1).ToString(), true);
                if (matchesPictures.Length > 0 && matchesPictures[0] is PictureBox)
                {
                    picturesBoxes[i] = (PictureBox)matchesPictures[0];
                    picturesBoxes[i].Image = Image.FromFile(@"blanco.png");
                }

                matchesLabels = this.Controls.Find("labelSegmento" + (i + 1).ToString(), true);
                if (matchesLabels.Length > 0 && matchesLabels[0] is Label)
                {
                    labels[i] = (Label)matchesLabels[0];
                    labels[i].Text = "-";
                }
            }

            for (int i = 0; i < 128; i++)
            {
                arregloSegmentos[i] = new Segmento(-1, "", false);
            }
        }

        void dibujaTabla()
        {
            for (int i = 0; i < 128; i++)
            {
                switch (arregloSegmentos[i].obtenColor())
                {
                    case "ROJO":
                        picturesBoxes[i].Image = Image.FromFile(@"rojo.png");
                        if (arregloSegmentos[i].obtenIdProceso() != -1)
                            labels[i].Text = arregloSegmentos[i].obtenIdProceso().ToString();
                        else
                            labels[i].Text = "-";
                        break;
                    case "AZUL":
                        picturesBoxes[i].Image = Image.FromFile(@"azul.png");
                        if (arregloSegmentos[i].obtenIdProceso() != -1)
                            labels[i].Text = arregloSegmentos[i].obtenIdProceso().ToString();
                        else
                            labels[i].Text = "-";
                        break;
                    case "MORADO":
                        picturesBoxes[i].Image = Image.FromFile(@"morado.png");
                        if (arregloSegmentos[i].obtenIdProceso() != -1)
                            labels[i].Text = arregloSegmentos[i].obtenIdProceso().ToString();
                        else
                            labels[i].Text = "-";
                        break;
                    case "BLANCO":
                        picturesBoxes[i].Image = Image.FromFile(@"blanco.png");
                        if (arregloSegmentos[i].obtenIdProceso() != -1)
                            labels[i].Text = arregloSegmentos[i].obtenIdProceso().ToString();
                        else
                            labels[i].Text = "-";
                        break;
                }
            }
        }

        void actualizaTabla(Proceso proceso)
        {
            segementoLibreUsado = false;
            for (int segmento = 0; segmento < 128; segmento++)
            {
                if (proceso.obtenerEstado() == "LISTO" || proceso.obtenerEstado() == "BLOQ")
                {
                    if (arregloSegmentos[segmento].obtenIdProceso() == proceso.obtenerId())
                    {
                        arregloSegmentos[segmento].fijaColor(proceso.obtenerEstado(),
                                                              proceso.obtenerBanEjecutando());
                    }
                }
                else if (proceso.obtenerEstado() == "T-NORMAL" || proceso.obtenerEstado() == "T-ERROR")
                {
                    if (arregloSegmentos[segmento].obtenIdProceso() == proceso.obtenerId())
                    {
                        arregloSegmentos[segmento].fijaColor(proceso.obtenerEstado(),
                                                              proceso.obtenerBanEjecutando());
                        arregloSegmentos[segmento].fijaIdProceso(-1);

                        if (segmento % 4 == 0)
                            marcosDisponibles++;
                    }
                }
            }
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

        int calculaNuevosProcesos(List<Proceso> procesosGenerados, int indiceProcesosGen)
        {
            int numeroDeProcesosPermitidos = 0;

            while (indiceProcesosGen < procesosGenerados.Count)
            {
                numeroDeMarcosAUsar = procesosGenerados[indiceProcesosGen].obtenerTamanio() / 4;

                if (procesosGenerados[indiceProcesosGen].obtenerTamanio() % 4 != 0)
                    numeroDeMarcosAUsar++;

                if (numeroDeMarcosAUsar <= marcosDisponibles)
                {
                    Console.WriteLine("--PROCESO NUMERO: " + indiceProcesosGen.ToString());
                    Console.WriteLine("ID Proceso: " + procesosGenerados[indiceProcesosGen].obtenerId().ToString());
                    Console.WriteLine("Numero de Marcos Necesarios: " + numeroDeMarcosAUsar.ToString());
                    Console.WriteLine("Numeros de Marcos Disponibles: " + marcosDisponibles.ToString());
                    Console.WriteLine("Tamanio: " + procesosGenerados[indiceProcesosGen].obtenerTamanio().ToString());
                    Console.Write("\n");


                    if (procesosGenerados[indiceProcesosGen].obtenerTamanio() % 4 == 0)
                    {
                        numeroDeSegmentosAUsar = numeroDeMarcosAUsar * 4;
                        segmentosUsados = 0;

                        int inicioDeMarco = 0;
                        int factor = 0;

                        while (inicioDeMarco <= 124 && segmentosUsados < numeroDeSegmentosAUsar)
                        {
                            inicioDeMarco = factor * 4;
                            if (arregloSegmentos[inicioDeMarco].obtenIdProceso() == -1)
                            {
                                while (segmentosUsados < numeroDeSegmentosAUsar)
                                {
                                    if (arregloSegmentos[inicioDeMarco + segmentosUsados].obtenIdProceso() == -1)
                                    {
                                        arregloSegmentos[inicioDeMarco + segmentosUsados]
                                        .fijaIdProceso(procesosGenerados[indiceProcesosGen].obtenerId());

                                        arregloSegmentos[inicioDeMarco + segmentosUsados]
                                        .fijaColor(procesosGenerados[indiceProcesosGen].obtenerEstado(),
                                                   procesosGenerados[indiceProcesosGen].obtenerBanEjecutando());
                                        segmentosUsados++;
                                    }
                                    else
                                    {
                                        numeroDeSegmentosAUsar -= segmentosUsados;
                                        segmentosUsados = 0;
                                        break;
                                    }
                                }
                            }
                            factor++;
                        }

                        marcosDisponibles -= numeroDeMarcosAUsar;
                        numeroDeProcesosPermitidos++;
                    }
                    else
                    {
                        numeroDeSegmentosAUsar = (procesosGenerados[indiceProcesosGen].obtenerTamanio() / 4) * 4;
                        int numeroDeSegmentosResiduales = procesosGenerados[indiceProcesosGen].obtenerTamanio() % 4;
                        numeroDeSegmentosAUsar += numeroDeSegmentosResiduales;
                        segmentosUsados = 0;

                        int inicioDeMarco = 0;
                        int factor = 0;

                        while (inicioDeMarco <= 124 && segmentosUsados < numeroDeSegmentosAUsar)
                        {
                            inicioDeMarco = factor * 4;
                            if (arregloSegmentos[inicioDeMarco].obtenIdProceso() == -1)
                            {
                                while (segmentosUsados < numeroDeSegmentosAUsar)
                                {
                                    if (arregloSegmentos[inicioDeMarco + segmentosUsados].obtenIdProceso() == -1)
                                    {
                                        arregloSegmentos[inicioDeMarco + segmentosUsados]
                                        .fijaIdProceso(procesosGenerados[indiceProcesosGen].obtenerId());

                                        arregloSegmentos[inicioDeMarco + segmentosUsados]
                                        .fijaColor(procesosGenerados[indiceProcesosGen].obtenerEstado(),
                                                   procesosGenerados[indiceProcesosGen].obtenerBanEjecutando());
                                        segmentosUsados++;
                                    }
                                    else
                                    {
                                        numeroDeSegmentosAUsar -= segmentosUsados;
                                        segmentosUsados = 0;
                                        break;
                                    }
                                }
                            }
                            factor++;
                        }

                        segmentoEnTabla += (4 - numeroDeSegmentosResiduales);
                        marcosDisponibles -= numeroDeMarcosAUsar;
                        numeroDeProcesosPermitidos++;
                    }
                }
                else
                {
                    break;
                }

                indiceProcesosGen++;
            }

            Console.WriteLine("Numeros de Marcos Disponibles: " + marcosDisponibles.ToString());
            Console.WriteLine("Ubicacion de Segmento: " + segmentoEnTabla.ToString());
            Console.WriteLine("Procesos Permitidos: " + numeroDeProcesosPermitidos.ToString());
            Console.WriteLine("PROCESOS PERMITIDOS: " + numeroDeProcesosPermitidos.ToString());

            return numeroDeProcesosPermitidos;
        }

        async Task ejecutarEnMemoria(List<Proceso> procesosGenerados)
        {
            List<Proceso> procesoEjecutando = new List<Proceso>();
            string[] ESTADOS_PROCESO = new string[] { "NUEVO", "LISTO", "BLOQ", "T-NORMAL", "T-ERROR" };
            int indiceListaProcesosListos = 0;
            int limiteDeMemoria = calculaNuevosProcesos(procesosGenerados, 0);

            while ((indiceListaProcesosListos < procesosGenerados.Count) && (indiceListaProcesosListos < limiteDeMemoria))
            {
                Proceso procesoNuevo = new Proceso();
                procesoNuevo = procesosGenerados[indiceListaProcesosListos];
                procesoNuevo.fijarEstado(ESTADOS_PROCESO[1]);
                procesoNuevo.fijarTiempoDeLlegada(contadorGlobal);
                procesoNuevo.fijarBanderaTiempoDeLlegada(false);
                procesoEjecutando.Add(procesoNuevo);

                actualizaTabla(procesoEjecutando[indiceListaProcesosListos]);
                dibujaTabla();

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
            bool banSuspendeProceso = false;
            bool banRetornaProcesoSuspendido = false;

            int procesosNuevosPendientes = procesosGenerados.Count - indiceListaProcesosListos;
            labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString();
            labelProcesosNuevosPendientesMostrar.Refresh();

            if (indiceListaProcesosListos < procesosGenerados.Count)
            {
                labelIDProcesoNuevoIng.Text = procesosGenerados[indiceListaProcesosListos].obtenerId().ToString();
                labelTamNueIng.Text = procesosGenerados[indiceListaProcesosListos].obtenerTamanio().ToString();
            }
            else
            {
                labelIDProcesoNuevoIng.Text = "";
                labelTamNueIng.Text = "";
            }

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
                    case "T":
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
                    case "S":
                        {
                            banSuspendeProceso = true;
                        }
                        break;
                    case "R":
                        {
                            banRetornaProcesoSuspendido = true;
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
                            listViewProLis.SubItems.Add(procesoEjecutando[indProListo].obtenerTamanio().ToString());
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

                                actualizaTabla(procesoEjecutando[indProBlo]);
                                dibujaTabla();
                            }
                            else
                            {
                                int tiempoTraBloqueado = procesoEjecutando[indProBlo].obtenerTiempoTranscurridoBloquedo() + 1;
                                procesoEjecutando[indProBlo].fijarTiempoTranscurridoBloqueado(tiempoTraBloqueado);

                                ListViewItem listViewLisPedNue = new ListViewItem(procesoEjecutando[indProBlo].obtenerId().ToString());
                                listViewLisPedNue.SubItems.Add(procesoEjecutando[indProBlo].obtenerTiempoTranscurridoBloquedo().ToString());
                                listViewLisPedNue.SubItems.Add(procesoEjecutando[indProBlo].obtenerTamanio().ToString());
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
                        listViewProEnEje.SubItems.Add(procesoEjecutando[i].obtenerTamanio().ToString());
                        listViewProcesoEnEjecucion.Items.Add(listViewProEnEje);
                        listViewProcesoEnEjecucion.Refresh();

                        actualizaTabla(procesoEjecutando[i]);
                        dibujaTabla();

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

                            actualizaTabla(procesoEjecutando[i]);
                            dibujaTabla();

                            procesoEjecutando.RemoveAt(i);
                            if (indiceListaProcesosListos < procesosGenerados.Count)
                            {
                                int canProcesosCalculados = calculaNuevosProcesos(procesosGenerados, indiceListaProcesosListos);
                                if (canProcesosCalculados > 0)
                                {
                                    int j = 0;
                                    int posicionInsertar = 0;

                                    while (j < procesoEjecutando.Count)
                                    {
                                        if (procesoEjecutando[j].obtenerEstado() != "BLOQ")
                                            posicionInsertar++;
                                        else
                                            break;

                                        j++;
                                    }

                                    int numProcesosInsertados = 0;
                                    while (numProcesosInsertados < canProcesosCalculados)
                                    {
                                        Proceso nuevoProceso = new Proceso();
                                        nuevoProceso = procesosGenerados[indiceListaProcesosListos];
                                        nuevoProceso.fijarEstado(ESTADOS_PROCESO[1]);
                                        nuevoProceso.fijarBanderaTiempoDeLlegada(false);
                                        nuevoProceso.fijarTiempoDeLlegada(contadorGlobal);
                                        procesoEjecutando.Insert(posicionInsertar, procesosGenerados[indiceListaProcesosListos]);

                                        actualizaTabla(nuevoProceso);
                                        dibujaTabla();

                                        indiceListaProcesosListos++;
                                        posicionInsertar++;
                                        numProcesosInsertados++;
                                    }
                                }
                            }

                            tamanioDeMemoria = procesoEjecutando.Count;
                            limiteDeListView = procesoEjecutando.Count;

                            contadorProcesosTerminados++;

                            if (procesoEjecutando.Count != 0)
                            {
                                segundo = 0;
                                segundo = procesoEjecutando[i].obtenerTiempoTranscurrido();
                                actualizaTabla(procesoEjecutando[i]);
                                dibujaTabla();
                            }

                            procesosNuevosPendientes = procesosGenerados.Count - indiceListaProcesosListos;
                            labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString();
                            labelProcesosNuevosPendientesMostrar.Refresh();

                            if (indiceListaProcesosListos < procesosGenerados.Count)
                            {
                                labelIDProcesoNuevoIng.Text = procesosGenerados[indiceListaProcesosListos].obtenerId().ToString();
                                labelTamNueIng.Text = procesosGenerados[indiceListaProcesosListos].obtenerTamanio().ToString();
                            }
                            else
                            {
                                labelIDProcesoNuevoIng.Text = "";
                                labelTamNueIng.Text = "";
                            }

                            banderaError = false;
                        }
                        else if (banderaInterrupcion)
                        {
                            procesoEjecutando[i].fijarEstado(ESTADOS_PROCESO[2]);
                            procesoEjecutando[i].fijarBanEjecutando(false);

                            actualizaTabla(procesoEjecutando[i]);
                            dibujaTabla();

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

                            actualizaTabla(procesoEjecutando[i]);
                            dibujaTabla();
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

                            actualizaTabla(procesoEjecutando[i]);
                            dibujaTabla();

                            procesoEjecutando.RemoveAt(i);
                            if (indiceListaProcesosListos < procesosGenerados.Count)
                            {
                                int canProcesosCalculados = calculaNuevosProcesos(procesosGenerados, indiceListaProcesosListos);
                                if (canProcesosCalculados > 0)
                                {
                                    int j = 0;
                                    int posicionInsertar = 0;

                                    while (j < procesoEjecutando.Count)
                                    {
                                        if (procesoEjecutando[j].obtenerEstado() != "BLOQ")
                                            posicionInsertar++;
                                        else
                                            break;

                                        j++;
                                    }

                                    int numProcesosInsertados = 0;
                                    while (numProcesosInsertados < canProcesosCalculados)
                                    {
                                        Proceso nuevoProceso = new Proceso();
                                        nuevoProceso = procesosGenerados[indiceListaProcesosListos];
                                        nuevoProceso.fijarEstado(ESTADOS_PROCESO[1]);
                                        nuevoProceso.fijarBanderaTiempoDeLlegada(false);
                                        nuevoProceso.fijarTiempoDeLlegada(contadorGlobal);
                                        procesoEjecutando.Insert(posicionInsertar, procesosGenerados[indiceListaProcesosListos]);

                                        actualizaTabla(nuevoProceso);
                                        dibujaTabla();

                                        indiceListaProcesosListos++;
                                        posicionInsertar++;
                                        numProcesosInsertados++;
                                    }
                                }
                            }

                            tamanioDeMemoria = procesoEjecutando.Count;
                            limiteDeListView = procesoEjecutando.Count;

                            contadorProcesosTerminados++;

                            if (procesoEjecutando.Count != 0)
                            {
                                segundo = 0;
                                segundo = procesoEjecutando[i].obtenerTiempoTranscurrido();
                                actualizaTabla(procesoEjecutando[i]);
                                dibujaTabla();
                            }

                            procesosNuevosPendientes = procesosGenerados.Count - indiceListaProcesosListos;
                            labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString();
                            labelProcesosNuevosPendientesMostrar.Refresh();

                            if (indiceListaProcesosListos < procesosGenerados.Count)
                            {
                                labelIDProcesoNuevoIng.Text = procesosGenerados[indiceListaProcesosListos].obtenerId().ToString();
                                labelTamNueIng.Text = procesosGenerados[indiceListaProcesosListos].obtenerTamanio().ToString();
                            }
                            else
                            {
                                labelIDProcesoNuevoIng.Text = "";
                                labelTamNueIng.Text = "";
                            }
                        }
                        else if (tamanioDeMemoria > -1)
                        {
                            if (segundo == procesoEjecutando[i].obtenerParadasQuantum()[paradaQuantumActual])
                            {
                                procesoEjecutando[i].fijarIndiceParadasQuantum(paradaQuantumActual + 1);
                                procesoEjecutando[i].fijarEstado(ESTADOS_PROCESO[1]);
                                procesoEjecutando[i].fijarBanEjecutando(false);

                                actualizaTabla(procesoEjecutando[i]);
                                dibujaTabla();

                                int j = 0;
                                int posicionInsertar = 0;

                                while (j < tamanioDeMemoria)
                                {
                                    if (procesoEjecutando[j].obtenerEstado() != "BLOQ")
                                        posicionInsertar++;
                                    else
                                        break;

                                    j++;
                                }

                                procesoEjecutando.Insert(posicionInsertar, procesoEjecutando[i]);
                                procesoEjecutando.RemoveAt(i);

                                segundo = 0;
                                segundo = procesoEjecutando[i].obtenerTiempoTranscurrido();

                                actualizaTabla(procesoEjecutando[i]);
                                dibujaTabla();
                            }
                            else
                            {
                                segundo++;
                            }
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

                        int canProcesosCalculados = calculaNuevosProcesos(procesosGenerados, indiceListaProcesosListos);
                        if (canProcesosCalculados > 0)
                        {
                            int j = 0;
                            int posicionInsertar = 0;

                            while (j < procesoEjecutando.Count)
                            {
                                if (procesoEjecutando[j].obtenerEstado() != "BLOQ")
                                    posicionInsertar++;
                                else
                                    break;

                                j++;
                            }

                            int numProcesosInsertados = 0;
                            while (numProcesosInsertados < canProcesosCalculados)
                            {
                                Proceso nuevoProceso = new Proceso();
                                nuevoProceso = procesosGenerados[indiceListaProcesosListos];
                                nuevoProceso.fijarEstado(ESTADOS_PROCESO[1]);
                                nuevoProceso.fijarBanderaTiempoDeLlegada(false);
                                nuevoProceso.fijarTiempoDeLlegada(contadorGlobal);
                                procesoEjecutando.Insert(posicionInsertar, procesosGenerados[indiceListaProcesosListos]);

                                actualizaTabla(nuevoProceso);
                                dibujaTabla();

                                indiceListaProcesosListos++;
                                posicionInsertar++;
                                numProcesosInsertados++;
                            }


                            segundo = 0;
                            segundo = procesoEjecutando[i].obtenerTiempoTranscurrido();

                            tamanioDeMemoria = procesoEjecutando.Count;
                            limiteDeListView = procesoEjecutando.Count;
                        }
                        else
                        {
                            procesosNuevosPendientes++;
                            labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString();
                            labelProcesosNuevosPendientesMostrar.Refresh();
                        }

                        if (indiceListaProcesosListos < procesosGenerados.Count)
                        {
                            labelIDProcesoNuevoIng.Text = procesosGenerados[indiceListaProcesosListos].obtenerId().ToString();
                            labelTamNueIng.Text = procesosGenerados[indiceListaProcesosListos].obtenerTamanio().ToString();
                        }
                        else
                        {
                            labelIDProcesoNuevoIng.Text = "";
                            labelTamNueIng.Text = "";
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

                await Task.Delay(700);
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
            int tamanio = 0;

            numeroUno = rnd.Next(0, 200);
            operadorMatematico = lisOpe[rnd.Next(0, 6)];
            numeroDos = rnd.Next(0, 200);
            id = rnd.Next(0, 200);
            tme = rnd.Next(5, 11);
            tamanio = rnd.Next(16, 28);

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
            procesoGenerado.fijarTamanio(tamanio);

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
                case "T":
                    teclaPresionada = "T";
                    break;
                default:
                    teclaPresionada = "";
                    break;
            }
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {

        }
    }
}
