using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace Act12_SSO
{
    public partial class ventanaPrincipal : Form
    {
        string teclaPresionada;
        Random rnd = new Random();
        PictureBox[] picturesBoxes = new PictureBox[40];

        public ventanaPrincipal()
        {
            InitializeComponent();
            this.KeyPreview = true;

            Control[] matches;
            for (int i = 0; i < 40; i++)
            {
                matches = this.Controls.Find("pictureBox" + (i + 1).ToString(), true);
                if (matches.Length > 0 && matches[0] is PictureBox)
                {
                    picturesBoxes[i] = (PictureBox)matches[0];
                    picturesBoxes[i].Image = Image.FromFile(@"vacio.png");
                }
            }
        }

        private void ventanaPrincipal_Load(object sender, EventArgs e)
        {

        }

        async Task iniciarSimulacion()
        {
            Persona productor = new Persona();
            Persona consumidor = new Persona();
            string[] PERSONA = new string[] { "CONSUMIDOR", "PRODUCTOR" };
            string[] ESTADOS = new string[] { "DESPIERTO", "TRABAJANDO", "TRATANDO DE ENTRAR", "DORMIDO" };
            int indicePersona;
            Buffer buffer = new Buffer();

            while (teclaPresionada != "Escape")
            {
                productor.fijaNumeroBooleanosAColocar(rnd.Next(3, 10));
                consumidor.fijaNumeroBooleanosAColocar(rnd.Next(3, 10));
                indicePersona = rnd.Next(0, 2);

                switch (PERSONA[indicePersona])
                {
                    case "CONSUMIDOR":
                        if (buffer.obtenNumeroEspaciosLlenos() > 0)
                        {
                            int i = consumidor.obtenPosicionEnBuffer();

                            if (i == 39)
                            {
                                consumidor.fijaPosicionEnBuffer(0);
                                i = consumidor.obtenPosicionEnBuffer();
                            }

                            int canDePosAMoverse = consumidor.obtenNumeroBooleanosAColocar();
                            int j = 0;

                            if (!buffer.obtenIndiceEn(i))
                            {
                                i++;
                            }

                            while (i < buffer.obtenTAMANIO() && j < canDePosAMoverse)
                            {
                                if (buffer.obtenIndiceEn(i))
                                {
                                    buffer.fijaIndiceEn(i, false);
                                    consumidor.fijaPosicionEnBuffer(i);

                                    
                                    picturesBoxes[i].Image = Image.FromFile(@"vaquero.png");

                                    consumidor.fijaEstado("TRABAJANDO");
                                    labelMostrarEstadoConsumidor.Text = consumidor.obtenEstado();
                                    labelMostrarEstadoConsumidor.Refresh();

                                    await Task.Delay(300);
                                    picturesBoxes[i].Image = Image.FromFile(@"vacio.png");

                                    if (i == 39)
                                    {
                                        consumidor.fijaPosicionEnBuffer(0);
                                        i = consumidor.obtenPosicionEnBuffer();
                                    }
                                    else
                                    {
                                        i++;
                                        j++;
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }

                            consumidor.fijaEstado("DORMIDO");
                            labelMostrarEstadoConsumidor.Text = consumidor.obtenEstado();
                            labelMostrarEstadoConsumidor.Refresh();
                        }
                        else
                        {
                            consumidor.fijaEstado(ESTADOS[2]);
                            labelMostrarEstadoConsumidor.Text = consumidor.obtenEstado();
                            labelMostrarEstadoConsumidor.Refresh();
                        }
                        break;
                    case "PRODUCTOR":
                        if (buffer.obtenNumeroEspaciosVacios() > 0)
                        {
                            int i = productor.obtenPosicionEnBuffer();

                            if (i == 39)
                            {
                                productor.fijaPosicionEnBuffer(0);
                                i = productor.obtenPosicionEnBuffer();
                            }

                            int canDePosAMoverse = productor.obtenNumeroBooleanosAColocar();
                            int j = 0;

                            if (buffer.obtenIndiceEn(i))
                            {
                                i++;
                            }

                            while (i < buffer.obtenTAMANIO() && j < canDePosAMoverse)
                            {
                                if (!buffer.obtenIndiceEn(i))
                                {
                                    buffer.fijaIndiceEn(i, true);
                                    productor.fijaPosicionEnBuffer(i);

                                    

                                    picturesBoxes[i].Image = Image.FromFile(@"vaca.png");

                                    productor.fijaEstado("TRABAJANDO");
                                    labelMostrarEstadoProductor.Text = productor.obtenEstado();
                                    labelMostrarEstadoProductor.Refresh();

                                    await Task.Delay(300);
                                    picturesBoxes[i].Image = Image.FromFile(@"leche.png");

                                    if (i == 39)
                                    {
                                        productor.fijaPosicionEnBuffer(0);
                                        i = productor.obtenPosicionEnBuffer();
                                    }
                                    else
                                    {
                                        i++;
                                        j++;
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }

                            productor.fijaEstado("DORMIDO");
                            labelMostrarEstadoProductor.Text = productor.obtenEstado();
                            labelMostrarEstadoProductor.Refresh();
                        }
                        else
                        {
                            productor.fijaEstado(ESTADOS[2]);
                            labelMostrarEstadoProductor.Text = productor.obtenEstado();
                            labelMostrarEstadoProductor.Refresh();
                        }
                        break;
                }
            }

            this.Close();
        }

        private void botonIniciarSimulacion_Click(object sender, EventArgs e)
        {
            iniciarSimulacion();
        }

        private void ventanaPrincipal_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode.ToString())
            {
                case "Escape":
                    teclaPresionada = "Escape";
                    break;
                default:
                    teclaPresionada = "";
                    break;
            }
        }
    }
}

