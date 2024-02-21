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
                cantidadDeProcesosAEjecutar = Convert.ToInt32(textBoxCantidadDeProcesos.Text);

                if (cantidadDeProcesosAEjecutar >= 1 && cantidadDeProcesosAEjecutar <= 30)
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

        void ejecutarLotes(List<Proceso> lotAct)
        {
            int numero1 = 0;
            int numero2 = 0;
            int resOpe = 0;
            int posIniItemDeLotPed = 1;
            bool banderaPausaYContinua = true;
            bool banderaError = false;
            bool banderaBreak = false;
            bool banderaInterrupcion = false;

            Proceso procesoExtra = new Proceso();
            lotAct.Add(procesoExtra);
            Proceso[] lote = lotAct.ToArray();
            int tamLote = lote.Length - 1;

            int i = 0;
            while (i < tamLote)
            {
                this.Invoke((MethodInvoker)delegate
                { listViewLotesPendientes.Items.Clear(); });

                for (int indLote = posIniItemDeLotPed; indLote < tamLote; indLote++)
                {
                    ListViewItem listViewLisPedNue = new ListViewItem(lote[indLote].obtenerId().ToString());
                    listViewLisPedNue.SubItems.Add(lote[indLote].obtenerTiempoMaximoEstimado().ToString());
                    listViewLisPedNue.SubItems.Add(lote[indLote].obtenerTiempoTranscurrido().ToString());
                    this.Invoke((MethodInvoker)delegate
                    { listViewLotesPendientes.Items.Add(listViewLisPedNue); });
                }

                posIniItemDeLotPed++;

                int segundo = lote[i].obtenerTie2mpoTranscurrido();
                while (segundo <= lote[i].obtenerTiempoMaximoEstimado())
                {
                    if (banderaPausaYContinua)
                    {
                        this.Invoke((MethodInvoker)delegate
                        { labelContadorGlobalImprime.Text = contadorGlobal.ToString(); });
                        contadorGlobal++;

                        lote[i].fijarTiempoRestante(lote[i].obtenerTiempoMaximoEstimado() - segundo);
                        lote[i].fijarTiempoTranscurrido(segundo);

                        numero1 = 0;
                        numero2 = 0;
                        resOpe = 0;
                        numero1 = lote[i].obtenerNumeroUno();
                        numero2 = lote[i].obtenerNumeroDos();
                        lote[i].fijarResultadoDeOperacion(0);

                        switch (lote[i].obtenerOperadorMatematico())
                        {
                            case "+":
                                lote[i].fijarResultadoDeOperacion(numero1 + numero2);
                                break;
                            case "-":
                                lote[i].fijarResultadoDeOperacion(numero1 - numero2);
                                break;
                            case "*":
                                lote[i].fijarResultadoDeOperacion(numero1 * numero2);
                                break;
                            case "/":
                                lote[i].fijarResultadoDeOperacion(numero1 / numero2);
                                break;
                            case "%":
                                resOpe = (numero1 * numero2) / 100;
                                lote[i].fijarResultadoDeOperacion(resOpe);
                                break;
                            case "MOD":
                                lote[i].fijarResultadoDeOperacion(numero1 % numero2);
                                break;
                            case "RAIZ":
                                resOpe = Convert.ToInt32(Math.Pow(numero2, (1 / (double)numero1)));
                                lote[i].fijarResultadoDeOperacion(resOpe);
                                break;
                        }

                        this.Invoke((MethodInvoker)delegate
                        { listViewProcesosEnEjecucion.Items.Clear(); });

                        ListViewItem listViewProEnEje = new ListViewItem(lote[i].obtenerId().ToString());
                        listViewProEnEje.SubItems.Add(lote[i].obtenerNumeroUno().ToString() +
                                                       lote[i].obtenerOperadorMatematico() +
                                                       lote[i].obtenerNumeroDos().ToString()
                                                      );
                        listViewProEnEje.SubItems.Add(lote[i].obtenerTiempoMaximoEstimado().ToString());
                        listViewProEnEje.SubItems.Add(lote[i].obtenerTiempoTranscurrido().ToString());
                        listViewProEnEje.SubItems.Add(lote[i].obtenerTiempoRestante().ToString());
                        this.Invoke((MethodInvoker)delegate
                        { listViewProcesosEnEjecucion.Items.Add(listViewProEnEje); });

                        segundo++;
                    }

                    switch (teclaPresionada)
                    {
                        case "E":// interrupcion
                            {
                                if (banderaPausaYContinua != false)
                                {
                                    banderaInterrupcion = true;
                                    banderaBreak = true;
                                    if (contadorGlobal != 0)
                                        contadorGlobal--;
                                }
                            }
                            break;
                        case "W":// error
                            {
                                if (banderaPausaYContinua != false)
                                {
                                    banderaError = true;
                                    banderaBreak = true;
                                    if (contadorGlobal != 0)
                                        contadorGlobal--;
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

                    if (banderaBreak)
                    {
                        banderaBreak = false;
                        break;
                    }

                    Thread.Sleep(1000);
                }


                if (banderaError)
                {
                    if (i % 4 == 0 )
                    {
                        ListViewItem lisNueProEje;
                        lisNueProEje = new ListViewItem("---");
                        lisNueProEje.SubItems.Add("INICIO DE LOTE--");
                        this.Invoke((MethodInvoker)delegate
                        {
                            listViewLotesTerminados.Items.Add(lisNueProEje);
                        });
                        //MessageBox.Show("INICIO DE LOTE");
                    }

                    ListViewItem listViewProTer = new ListViewItem(lote[i].obtenerId().ToString());
                    listViewProTer.SubItems.Add(lote[i].obtenerNumeroUno().ToString() +
                                                 lote[i].obtenerOperadorMatematico() +
                                                 lote[i].obtenerNumeroDos().ToString()
                                                );
                    listViewProTer.SubItems.Add("ERROR");
                    this.Invoke((MethodInvoker)delegate
                    { listViewLotesTerminados.Items.Add(listViewProTer); });

                }
                else if (banderaInterrupcion)
                {
                    lote[lote.Length - 1] = lote[i];

                    for (int j = i; j < lote.Length; j++)
                    {
                        if (j != lote.Length - 1)
                            lote[j] = lote[j + 1];
                    }

                    posIniItemDeLotPed--;

                    banderaInterrupcion = false;
                    continue;
                }
                else
                {
                    if (i % 4 == 0 )
                    {
                        ListViewItem lisNueProEje;
                        lisNueProEje = new ListViewItem("---");
                        lisNueProEje.SubItems.Add("INICIO DE LOTE--");
                        this.Invoke((MethodInvoker)delegate
                        {
                            listViewLotesTerminados.Items.Add(lisNueProEje);
                        });
                        //MessageBox.Show("INICIO DE LOTE");
                    }

                    ListViewItem listViewProTer = new ListViewItem(lote[i].obtenerId().ToString());
                    listViewProTer.SubItems.Add(lote[i].obtenerNumeroUno().ToString() +
                                                 lote[i].obtenerOperadorMatematico() +
                                                 lote[i].obtenerNumeroDos().ToString()
                                                );
                    listViewProTer.SubItems.Add(lote[i].obtenerResultadoDeOperacion().ToString());
                    this.Invoke((MethodInvoker)delegate
                    { listViewLotesTerminados.Items.Add(listViewProTer); });
                }


                if (banderaError)
                {
                    banderaError = false;
                }

                i++;
            }

            this.Invoke((MethodInvoker)delegate
            {
                listViewLotesPendientes.Items.Clear();
                listViewProcesosEnEjecucion.Items.Clear();
                botonLimpiar.Enabled = true;
            });
        }

        void crearLotes()
        {
            int tamLis = procesos.Count;
            int totLotExa = tamLis / 4;
            bool banCrerLot = false;
            int totProEje = 1;

            if (totLotExa != 0)
                banCrerLot = true;

            List<Proceso> lotAct = new List<Proceso>();
            lotAct.Clear();
            int i = 0, j = 0;

            while (tamLis != 0)
            {
                totProEje = 0;
                if (banCrerLot)
                {
                    lotAct.Clear();

                    for (j = 0; j < 4; j++)
                    {
                        lotAct.Add(procesos[i]);
                        i++;
                        totProEje++;
                    }
                }
                else
                {
                    lotAct.Clear();

                    for (j = 0; j < tamLis; j++)
                    {
                        lotAct.Add(procesos[i]);
                        i++;
                        totProEje++;
                    }
                }

                if (tamLis != 4)
                {
                    this.Invoke((MethodInvoker)delegate
                    { labelNoLotPenMostrar.Text = totLotExa.ToString(); });
                }
                else
                {
                    this.Invoke((MethodInvoker)delegate
                    { labelNoLotPenMostrar.Text = "0"; });
                }

                ejecutarLotes(lotAct);

                tamLis -= totProEje;
                totLotExa = tamLis / 4;
                if (totLotExa != 0)
                    banCrerLot = true;
                else
                    banCrerLot = false;
            }

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
                    Task.Factory.StartNew(() => { crearLotes(); });
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
            listViewLotesTerminados.Items.Clear();
            labelContadorGlobalImprime.Text = "-------------";
            labelNoLotPenMostrar.Text = "-------------";
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
