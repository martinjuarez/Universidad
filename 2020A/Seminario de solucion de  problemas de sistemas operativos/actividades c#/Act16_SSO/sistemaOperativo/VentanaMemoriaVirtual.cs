using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace sistemaOperativo
{
    public partial class VentanaMemoriaVirtual : Form
    {
        PictureBox[] picturesBoxes = new PictureBox[128];
        Label[] labels = new Label[128];
        List<Pagina> paginas = new List<Pagina>();

        public VentanaMemoriaVirtual()
        {
            InitializeComponent();
            this.KeyPreview = true;
            limpiaTabla();
        }

        void limpiaTabla()
        {
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
        }

        public void fijaLista(ref List<Pagina> paginas)
        {
            this.paginas = paginas;
        }

        private void VentanaMemoriaVirtual_Load(object sender, EventArgs e)
        {
            limpiaTabla();
            dibujaTabla();
        }

        void dibujaTabla()
        {
            int segmento = 0;
            int segmentosRecorridos = 0;
            int i = 0;
            while(i < paginas.Count)
            {
                segmentosRecorridos = 0;
                while(segmentosRecorridos < paginas[i].NumeroDeSegmentos)
                {
                    picturesBoxes[segmento].Image = Image.FromFile(@"naranja.png");
                    labels[segmento].Text = paginas[i].IdProceso.ToString();
                    segmentosRecorridos++;
                    segmento++;
                }
                i++;
                segmento = i * 4;
            }
        }
        
        private void VentanaMemoriaVirtual_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode.ToString())
            {
                case "C":
                    this.Close();
                    break;
            }
        }
    }
}
