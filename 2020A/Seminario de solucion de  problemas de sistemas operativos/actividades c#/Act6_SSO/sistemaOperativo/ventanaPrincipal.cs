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
        List<Proceso> procesos = new List<Proceso>();
        Random rnd = new Random();
        int cantidadDeProcesosAEjecutar = 0;
        int cantidadDeProcesosAgregados = 0;
        int cantidadProcesosFaltantes = 0;
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
            string numeroEnCadena = textBoxCantidadDeProcesos.Text;
            if (numeroEnCadena != "")
            {
                cantidadProcesosFaltantes =
                cantidadDeProcesosAEjecutar = Convert.ToInt32(numeroEnCadena);

                if (cantidadDeProcesosAEjecutar >= 1 && cantidadDeProcesosAEjecutar <= 1000)
                {
                    textBoxCantidadDeProcesos.Enabled = false;
                    botonIniciarProcesos.Enabled = false;
                    textBoxCantidadDeProcesos.Text = "";

                    generarProcesos();
                }
                else
                {
                    MessageBox.Show("Debe ser un número mayor o igual a 0 y menor o igual a 30");
                }
            }
            else
            {
                MessageBox.Show("¡Ingrese un número!");
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

        bool existeId(int idBuscado)
        {
            var resultado = procesos.Find(proceso => proceso.obtenerId() == idBuscado);
            if (resultado == null)
                return false;
            else
                return true;
        }

        void ejecutarEnMemoria(List<Proceso> procesosListos)
        {
            Proceso[] procesoListo = procesosListos.ToArray();
            Proceso[] memoria = new Proceso[4];

            int i = 0;
            while ((i < procesoListo.Length) && (i < 4))
            {
                memoria[i] = procesoListo[i];
                memoria[i].fijarTiempoDeLlegada(contadorGlobal);
                memoria[i].fijarEstadoTTL(false);
                i++;
            }

            int espacioMemoria = i;
            int j = 0;
            int k = 0;
            int segundo = 0;
            int limiteDeListView = i;

            int numero1 = 0;
            int numero2 = 0;
            int resOpe = 0;

            bool banderaPausaYContinua = true;
            bool banderaError = false;
            bool banderaInterrupcion = false;

            int procesosNuevosPendientes = procesoListo.Length - i;
            this.Invoke((MethodInvoker)delegate
            { labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString(); });

               while (j < procesoListo.Length)
               {
                switch (teclaPresionada)
                {
                    case "E":// interrupcion
                        {
                            if (banderaPausaYContinua)
                            {
                                banderaInterrupcion = true;
                               // if (contadorGlobal != 0)
                               //     contadorGlobal--;
                            }
                        }
                        break;
                    case "W":// error
                        {
                            if (banderaPausaYContinua)
                            {
                                banderaError = true;
                             //   if (contadorGlobal != 0)
                             //       contadorGlobal--;
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
                        }
                        break;
                }
                teclaPresionada = "";

                if (banderaPausaYContinua)
                {
                    this.Invoke((MethodInvoker)delegate
                    { labelContadorGlobalImprime.Text = contadorGlobal.ToString(); });
                    contadorGlobal++;

                    this.Invoke((MethodInvoker)delegate
                    { listViewProcesosListos.Items.Clear(); });

                    for (int indProListo = 1; indProListo < limiteDeListView; indProListo++)
                    {
                        if (memoria[indProListo].obtenerEstadoActivoBloqueado() == true)
                        {
                            ListViewItem listViewProLis = new ListViewItem(memoria[indProListo].obtenerId().ToString());
                            listViewProLis.SubItems.Add(memoria[indProListo].obtenerTiempoMaximoEstimado().ToString());
                            listViewProLis.SubItems.Add(memoria[indProListo].obtenerTiempoTranscurrido().ToString());
                            this.Invoke((MethodInvoker)delegate
                            { listViewProcesosListos.Items.Add(listViewProLis); });
                        }
                    }

                    this.Invoke((MethodInvoker)delegate
                    { listViewProcesosBloqueados.Items.Clear(); });

                    for (int indProBlo = 0; indProBlo < limiteDeListView; indProBlo++)
                    {
                        if (memoria[indProBlo].obtenerEstadoActivoBloqueado() == false)
                        {
                            if (memoria[indProBlo].obtenerTiempoTranscurridoBloquedo() == 9)
                            {
                                memoria[indProBlo].fijarEstadoActivoBloqueado(true);
                                memoria[indProBlo].fijarTiempoTranscurridoBloqueado(0);
                            }
                            else
                            {
                                int ttb = memoria[indProBlo].obtenerTiempoTranscurridoBloquedo() + 1;
                                memoria[indProBlo].fijarTiempoTranscurridoBloqueado(ttb);

                                ListViewItem listViewLisPedNue = new ListViewItem(memoria[indProBlo].obtenerId().ToString());
                                listViewLisPedNue.SubItems.Add(memoria[indProBlo].obtenerTiempoTranscurridoBloquedo().ToString());
                                this.Invoke((MethodInvoker)delegate
                                { listViewProcesosBloqueados.Items.Add(listViewLisPedNue); });
                            }
                        }
                    }

                    if (memoria[k].obtenerEstadoActivoBloqueado() == true)
                    {
                        numero1 = 0;
                        numero2 = 0;
                        resOpe = 0;
                        numero1 = memoria[k].obtenerNumeroUno();
                        numero2 = memoria[k].obtenerNumeroDos();
                        memoria[k].fijarResultadoDeOperacion(0);

                        switch (memoria[k].obtenerOperadorMatematico())
                        {
                            case "+":
                                memoria[k].fijarResultadoDeOperacion(numero1 + numero2);
                                break;
                            case "-":
                                memoria[k].fijarResultadoDeOperacion(numero1 - numero2);
                                break;
                            case "*":
                                memoria[k].fijarResultadoDeOperacion(numero1 * numero2);
                                break;
                            case "/":
                                memoria[k].fijarResultadoDeOperacion(numero1 / numero2);
                                break;
                            case "%":
                                resOpe = (numero1 * numero2) / 100;
                                memoria[k].fijarResultadoDeOperacion(resOpe);
                                break;
                            case "MOD":
                                memoria[k].fijarResultadoDeOperacion(numero1 % numero2);
                                break;
                            case "RAIZ":
                                resOpe = Convert.ToInt32(Math.Pow(numero2, (1 / (double)numero1)));
                                memoria[k].fijarResultadoDeOperacion(resOpe);
                                break;
                        }
                        
                        memoria[k].fijarTiempoRestante(memoria[k].obtenerTiempoMaximoEstimado() - segundo);
                        memoria[k].fijarTiempoTranscurrido(segundo);
                        

                        if (memoria[k].obtenerEstadoRespuesta()==false)
                        {
                            memoria[k].fijarEstadoRespuesta(true);
                            memoria[k].fijarTiempoDeRespuesta(contadorGlobal-memoria[k].obtenerTiempoDeLlegada());
                        }

                        this.Invoke((MethodInvoker)delegate
                        { listViewProcesoEnEjecucion.Items.Clear(); });

                        ListViewItem listViewProEnEje = new ListViewItem(memoria[k].obtenerId().ToString());
                        listViewProEnEje.SubItems.Add( memoria[k].obtenerNumeroUno().ToString() +
                                                       memoria[k].obtenerOperadorMatematico() +
                                                       memoria[k].obtenerNumeroDos().ToString()
                                                      );
                        listViewProEnEje.SubItems.Add(memoria[k].obtenerTiempoMaximoEstimado().ToString());
                        listViewProEnEje.SubItems.Add(memoria[k].obtenerTiempoTranscurrido().ToString());
                        listViewProEnEje.SubItems.Add(memoria[k].obtenerTiempoRestante().ToString());
                        this.Invoke((MethodInvoker)delegate
                        { listViewProcesoEnEjecucion.Items.Add(listViewProEnEje); });

                        if (banderaError)
                        {
                            memoria[k].fijarEstadoTerminado(true);

                            ListViewItem listViewProTer = new ListViewItem(memoria[k].obtenerId().ToString());
                            listViewProTer.SubItems.Add( memoria[k].obtenerNumeroUno().ToString() +
                                                         memoria[k].obtenerOperadorMatematico() +
                                                         memoria[k].obtenerNumeroDos().ToString()
                                                        );
                            listViewProTer.SubItems.Add("ERROR");
                            listViewProTer.SubItems.Add(memoria[k].obtenerTiempoDeLlegada().ToString());
                            listViewProTer.SubItems.Add(contadorGlobal.ToString());
                            listViewProTer.SubItems.Add(memoria[k].obtenerTiempoTranscurrido().ToString());
                            int te = (contadorGlobal - memoria[k].obtenerTiempoDeLlegada()) -memoria[k].obtenerTiempoTranscurrido();
                            listViewProTer.SubItems.Add( te.ToString());
                            listViewProTer.SubItems.Add((contadorGlobal-memoria[k].obtenerTiempoDeLlegada()).ToString());
                            listViewProTer.SubItems.Add(memoria[k].obtenerTiempoDeRespuesta().ToString());

                            this.Invoke((MethodInvoker)delegate
                            { listViewProcesosTerminados.Items.Add(listViewProTer); });

                            for (int l = 0; l < espacioMemoria; l++)
                            {
                                if (l != (espacioMemoria - 1))
                                {
                                    memoria[l] = memoria[l + 1];
                                }
                            }

                            if (i < procesoListo.Length)
                            {
                                memoria[espacioMemoria-1] = procesoListo[i];
                                if (memoria[espacioMemoria - 1].obtenerEstadoTTL())
                                {
                                    memoria[espacioMemoria - 1].fijarEstadoTTL(false);
                                    memoria[espacioMemoria - 1].fijarTiempoDeLlegada(contadorGlobal);
                                }

                                i++;
                            }
                            else
                            {
                                if (memoria[k].obtenerEstadoTTL())
                                {
                                    memoria[k].fijarEstadoTTL(false);
                                    memoria[k].fijarTiempoDeLlegada(contadorGlobal);
                                }                                

                                espacioMemoria--;
                                limiteDeListView--;
                            }

                            j++;
                            segundo = 0;
                            segundo = memoria[k].obtenerTiempoTranscurrido();

                            procesosNuevosPendientes = procesoListo.Length - i;
                            this.Invoke((MethodInvoker)delegate
                            { labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString(); });

                            banderaError = false;
                        }
                        else if (banderaInterrupcion)
                        {
                            memoria[k].fijarEstadoActivoBloqueado(false);

                            Proceso auxiliar = memoria[k];

                            for (int l = 0; l < espacioMemoria; l++)
                            {
                                if (l != (espacioMemoria - 1))
                                {
                                    memoria[l] = memoria[l + 1];
                                }
                            }

                            memoria[espacioMemoria - 1] = auxiliar;
                            segundo = 0;
                            segundo = memoria[k].obtenerTiempoTranscurrido();
                            banderaInterrupcion = false;
                        }
                        else if (segundo == memoria[k].obtenerTiempoMaximoEstimado())
                        {
                            memoria[k].fijarEstadoTerminado(true);

                            ListViewItem listViewProTer = new ListViewItem(memoria[k].obtenerId().ToString());
                            listViewProTer.SubItems.Add( memoria[k].obtenerNumeroUno().ToString() +
                                                         memoria[k].obtenerOperadorMatematico() +
                                                         memoria[k].obtenerNumeroDos().ToString()
                                                        );
                            listViewProTer.SubItems.Add(memoria[k].obtenerResultadoDeOperacion().ToString());
                            listViewProTer.SubItems.Add(memoria[k].obtenerTiempoDeLlegada().ToString());
                            listViewProTer.SubItems.Add(contadorGlobal.ToString());
                            listViewProTer.SubItems.Add(memoria[k].obtenerTiempoTranscurrido().ToString());
                            int te = (contadorGlobal - memoria[k].obtenerTiempoDeLlegada()) - memoria[k].obtenerTiempoTranscurrido();
                            listViewProTer.SubItems.Add(te.ToString());
                            listViewProTer.SubItems.Add((contadorGlobal - memoria[k].obtenerTiempoDeLlegada()).ToString());
                            listViewProTer.SubItems.Add(memoria[k].obtenerTiempoDeRespuesta().ToString());

                            this.Invoke((MethodInvoker)delegate
                            { listViewProcesosTerminados.Items.Add(listViewProTer); });

                            for (int l = 0; l < espacioMemoria; l++)
                            {
                                if (l != (espacioMemoria - 1))
                                {
                                    memoria[l] = memoria[l + 1];
                                }
                            }

                            if (i < procesoListo.Length)
                            {
                                memoria[espacioMemoria-1] = procesoListo[i];
                                if (memoria[espacioMemoria - 1].obtenerEstadoTTL())
                                {
                                    memoria[espacioMemoria - 1].fijarEstadoTTL(false);
                                    memoria[espacioMemoria - 1].fijarTiempoDeLlegada(contadorGlobal);
                                }
                                i++;
                            }
                            else
                            {
                                if (memoria[k].obtenerEstadoTTL())
                                {
                                    memoria[k].fijarEstadoTTL(false);
                                    memoria[k].fijarTiempoDeLlegada(contadorGlobal);
                                }

                                espacioMemoria--;
                                limiteDeListView--;
                            }

                            j++;
                            segundo = 0;
                            segundo = memoria[k].obtenerTiempoTranscurrido();

                            procesosNuevosPendientes = procesoListo.Length - i;
                            this.Invoke((MethodInvoker)delegate
                            { labelProcesosNuevosPendientesMostrar.Text = procesosNuevosPendientes.ToString(); });
                        }
                        else
                        {
                            segundo++;
                        }
                    }
                    else
                    {
                        int m = 0;
                        bool banProBloqueadoEnc = false; 

                        while (m < espacioMemoria)
                        {
                            if (memoria[m].obtenerEstadoActivoBloqueado() == true)
                            {
                                banProBloqueadoEnc = true; 
                                break;
                            }
                            m++;
                        }

                        if (banProBloqueadoEnc)
                        {
                            Proceso auxiliar = memoria[m];

                            for (int n = m; n > 0; n--)
                            {
                                memoria[n] = memoria[n - 1];
                            }

                            memoria[k] = auxiliar;

                            segundo = 0;
                            segundo = memoria[k].obtenerTiempoTranscurrido();
                        }
                        else
                        {
                            this.Invoke((MethodInvoker)delegate
                            { listViewProcesoEnEjecucion.Items.Clear(); });
                        }
                    }
                }

                Thread.Sleep(950);
            }


            this.Invoke((MethodInvoker)delegate
            {
                listViewProcesosListos.Items.Clear();
                listViewProcesoEnEjecucion.Items.Clear();
                botonLimpiar.Enabled = true;
            });
        }

        void generarProcesos()
        {
            int numeroUno = 0;
            string operadorMatematico = "";
            int numeroDos = 0;
            int id = 0;
            int tme = 0;
            string[] lisOpe = new string[] { "*", "-", "*", "/", "%", "MOD", "RAIZ" };

            for (int i = 1; i <= cantidadDeProcesosAEjecutar; i++)
            {
                numeroUno = rnd.Next(0, 200);
                operadorMatematico = lisOpe[rnd.Next(0, 6)];
                numeroDos = rnd.Next(0, 200);
                id = rnd.Next(0, 200);
                tme = rnd.Next(5, 14);

                while (!(tme > 0))
                {
                    tme = rnd.Next(5, 14);
                }

                while (!validarOperacionConCero(numeroUno, operadorMatematico, numeroDos))
                {
                    numeroUno = rnd.Next(0, 200);
                    operadorMatematico = lisOpe[rnd.Next(0, 6)];
                    numeroDos = rnd.Next(0, 200);
                }

                while (existeId(id))
                {
                    id = rnd.Next(0, 200);
                }

                Proceso proceso = new Proceso();

                proceso.fijarNumeroUno(numeroUno);
                proceso.fijarOperadorMatematico(operadorMatematico);
                proceso.fijarNumeroDos(numeroDos);
                proceso.fijarId(id);
                proceso.fijarTiempoMaximoEstimado(tme);

                procesos.Add(proceso);

                cantidadDeProcesosAgregados++;

                cantidadProcesosFaltantes--;

                if (cantidadDeProcesosAgregados == cantidadDeProcesosAEjecutar)
                {
                    MessageBox.Show("Iniciando con la Ejecución de Procesos");
                    Task.Factory.StartNew(() => { ejecutarEnMemoria(procesos); });
                }
            }
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

        private void botonLimpiar_Click(object sender, EventArgs e)
        {
            textBoxCantidadDeProcesos.Enabled = true;
            botonIniciarProcesos.Enabled = true;
            botonLimpiar.Enabled = false;
            listViewProcesosTerminados.Items.Clear();
            labelContadorGlobalImprime.Text = "-------------";
            labelProcesosNuevosPendientesMostrar.Text = "-------------";
            procesos.Clear();
            cantidadDeProcesosAEjecutar = 0;
            cantidadDeProcesosAgregados = 0;
            cantidadProcesosFaltantes = 0;
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
                default:
                    teclaPresionada = "";
                    break;
            }
        }
    }
}
