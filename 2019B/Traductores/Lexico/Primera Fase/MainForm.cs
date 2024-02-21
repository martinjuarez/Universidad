/*
 * Created by SharpDevelop.
 * User: Usuario
 * Date: 21/01/2019
 * Time: 11:10 a. m.
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace Primera_Fase
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		string[] datos = new string [] {"{","}",";","(",")","else","if","do","while","int","string","try","catch","finally","char","double","long","class","void","object","delegate","0","1","2","3","4","5","6","7","8","9"};
		
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		void txtDatosTextChanged(object sender, EventArgs e)
		{
			int pos = -1;
			
			for(int x = 0; x<31; x++){
				if(datos[x] == txtDatos.Text){
					pos = x;
					break;
				}
			}
			
			if(pos == -1 && txtDatos.Text.Length > 0)
				lblResultado.Text = "Caracter Inválido";
			else if(pos>=0 && pos<=4)
				lblResultado.Text = "La cadena corresponde a un simbolo";
			else if(pos>=5 && pos<=20)
				lblResultado.Text = "La cadena corresponde a una palabra reservada";
			else if(pos>=21 && pos<=30)
				lblResultado.Text = "La cadena corresponde a un dígito";
			else if(pos==-1)
				lblResultado.Text = "";
		}
	}
}
