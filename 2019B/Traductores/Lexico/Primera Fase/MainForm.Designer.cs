/*
 * Created by SharpDevelop.
 * User: Usuario
 * Date: 21/01/2019
 * Time: 11:10 a. m.
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace Primera_Fase
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.txtDatos = new System.Windows.Forms.TextBox();
			this.lblTipo = new System.Windows.Forms.Label();
			this.lblResultado = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// txtDatos
			// 
			this.txtDatos.Location = new System.Drawing.Point(15, 12);
			this.txtDatos.Name = "txtDatos";
			this.txtDatos.Size = new System.Drawing.Size(142, 20);
			this.txtDatos.TabIndex = 0;
			this.txtDatos.TextChanged += new System.EventHandler(this.txtDatosTextChanged);
			// 
			// lblTipo
			// 
			this.lblTipo.AutoSize = true;
			this.lblTipo.Location = new System.Drawing.Point(15, 43);
			this.lblTipo.Name = "lblTipo";
			this.lblTipo.Size = new System.Drawing.Size(31, 13);
			this.lblTipo.TabIndex = 2;
			this.lblTipo.Text = "Tipo:";
			// 
			// lblResultado
			// 
			this.lblResultado.AutoSize = true;
			this.lblResultado.Location = new System.Drawing.Point(15, 63);
			this.lblResultado.Name = "lblResultado";
			this.lblResultado.Size = new System.Drawing.Size(0, 13);
			this.lblResultado.TabIndex = 3;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(258, 95);
			this.Controls.Add(this.lblResultado);
			this.Controls.Add(this.lblTipo);
			this.Controls.Add(this.txtDatos);
			this.Name = "MainForm";
			this.Text = "Primera Fase";
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.Label lblResultado;
		private System.Windows.Forms.Label lblTipo;
		private System.Windows.Forms.TextBox txtDatos;
	}
}
