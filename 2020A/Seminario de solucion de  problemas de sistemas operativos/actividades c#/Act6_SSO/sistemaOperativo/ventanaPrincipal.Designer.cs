namespace sistemaOperativo
{
    partial class ventanaPrincipal
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBoxCantidadDeProcesos = new System.Windows.Forms.TextBox();
            this.labelCantidadDeProcesos = new System.Windows.Forms.Label();
            this.botonIniciarProcesos = new System.Windows.Forms.Button();
            this.labelProcesosListos = new System.Windows.Forms.Label();
            this.listViewProcesosListos = new System.Windows.Forms.ListView();
            this.columnHeaderID = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderTME = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderTieTra = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.listViewProcesoEnEjecucion = new System.Windows.Forms.ListView();
            this.columnHeaderIdentificador = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderOPE = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderTieMaxEst = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderTT = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderTR = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.labelProcesosEnEjecucion = new System.Windows.Forms.Label();
            this.listViewProcesosTerminados = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.labelProcesosTerminados = new System.Windows.Forms.Label();
            this.botonLimpiar = new System.Windows.Forms.Button();
            this.labelProcesosNuevosPendientesMostrar = new System.Windows.Forms.Label();
            this.labelProcesosNuevosPedientes = new System.Windows.Forms.Label();
            this.labelContadorGlobalImprime = new System.Windows.Forms.Label();
            this.labelContadorGlobal = new System.Windows.Forms.Label();
            this.listViewProcesosBloqueados = new System.Windows.Forms.ListView();
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.labelProcesosBloqueados = new System.Windows.Forms.Label();
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader8 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader9 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader10 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader11 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SuspendLayout();
            // 
            // textBoxCantidadDeProcesos
            // 
            this.textBoxCantidadDeProcesos.Location = new System.Drawing.Point(702, 14);
            this.textBoxCantidadDeProcesos.Name = "textBoxCantidadDeProcesos";
            this.textBoxCantidadDeProcesos.Size = new System.Drawing.Size(96, 20);
            this.textBoxCantidadDeProcesos.TabIndex = 1;
            this.textBoxCantidadDeProcesos.TextChanged += new System.EventHandler(this.textBoxCantidadDeProcesos_TextChanged);
            // 
            // labelCantidadDeProcesos
            // 
            this.labelCantidadDeProcesos.AutoSize = true;
            this.labelCantidadDeProcesos.Location = new System.Drawing.Point(585, 17);
            this.labelCantidadDeProcesos.Name = "labelCantidadDeProcesos";
            this.labelCantidadDeProcesos.Size = new System.Drawing.Size(114, 13);
            this.labelCantidadDeProcesos.TabIndex = 10;
            this.labelCantidadDeProcesos.Text = "Cantidad de Procesos:";
            // 
            // botonIniciarProcesos
            // 
            this.botonIniciarProcesos.Location = new System.Drawing.Point(822, 14);
            this.botonIniciarProcesos.Name = "botonIniciarProcesos";
            this.botonIniciarProcesos.Size = new System.Drawing.Size(102, 23);
            this.botonIniciarProcesos.TabIndex = 11;
            this.botonIniciarProcesos.Text = "Iniciar Procesos";
            this.botonIniciarProcesos.UseVisualStyleBackColor = true;
            this.botonIniciarProcesos.Click += new System.EventHandler(this.botonIniciarProcesos_Click);
            // 
            // labelProcesosListos
            // 
            this.labelProcesosListos.AutoSize = true;
            this.labelProcesosListos.Location = new System.Drawing.Point(75, 137);
            this.labelProcesosListos.Name = "labelProcesosListos";
            this.labelProcesosListos.Size = new System.Drawing.Size(81, 13);
            this.labelProcesosListos.TabIndex = 12;
            this.labelProcesosListos.Text = "Procesos Listos";
            // 
            // listViewProcesosListos
            // 
            this.listViewProcesosListos.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeaderID,
            this.columnHeaderTME,
            this.columnHeaderTieTra});
            this.listViewProcesosListos.GridLines = true;
            this.listViewProcesosListos.Location = new System.Drawing.Point(30, 162);
            this.listViewProcesosListos.Name = "listViewProcesosListos";
            this.listViewProcesosListos.Size = new System.Drawing.Size(156, 322);
            this.listViewProcesosListos.TabIndex = 14;
            this.listViewProcesosListos.UseCompatibleStateImageBehavior = false;
            this.listViewProcesosListos.View = System.Windows.Forms.View.Details;
            // 
            // columnHeaderID
            // 
            this.columnHeaderID.Text = "ID";
            this.columnHeaderID.Width = 50;
            // 
            // columnHeaderTME
            // 
            this.columnHeaderTME.Text = "TME";
            this.columnHeaderTME.Width = 50;
            // 
            // columnHeaderTieTra
            // 
            this.columnHeaderTieTra.Text = "TT";
            this.columnHeaderTieTra.Width = 50;
            // 
            // listViewProcesoEnEjecucion
            // 
            this.listViewProcesoEnEjecucion.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeaderIdentificador,
            this.columnHeaderOPE,
            this.columnHeaderTieMaxEst,
            this.columnHeaderTT,
            this.columnHeaderTR});
            this.listViewProcesoEnEjecucion.GridLines = true;
            this.listViewProcesoEnEjecucion.Location = new System.Drawing.Point(36, 37);
            this.listViewProcesoEnEjecucion.Name = "listViewProcesoEnEjecucion";
            this.listViewProcesoEnEjecucion.Size = new System.Drawing.Size(265, 63);
            this.listViewProcesoEnEjecucion.TabIndex = 16;
            this.listViewProcesoEnEjecucion.UseCompatibleStateImageBehavior = false;
            this.listViewProcesoEnEjecucion.View = System.Windows.Forms.View.Details;
            this.listViewProcesoEnEjecucion.SelectedIndexChanged += new System.EventHandler(this.listViewProcesosEnEjecucion_SelectedIndexChanged);
            // 
            // columnHeaderIdentificador
            // 
            this.columnHeaderIdentificador.Text = "ID";
            this.columnHeaderIdentificador.Width = 40;
            // 
            // columnHeaderOPE
            // 
            this.columnHeaderOPE.Text = "OPE";
            this.columnHeaderOPE.Width = 70;
            // 
            // columnHeaderTieMaxEst
            // 
            this.columnHeaderTieMaxEst.Text = "TME";
            this.columnHeaderTieMaxEst.Width = 50;
            // 
            // columnHeaderTT
            // 
            this.columnHeaderTT.Text = "TT";
            this.columnHeaderTT.Width = 50;
            // 
            // columnHeaderTR
            // 
            this.columnHeaderTR.Text = "TR";
            this.columnHeaderTR.Width = 50;
            // 
            // labelProcesosEnEjecucion
            // 
            this.labelProcesosEnEjecucion.AutoSize = true;
            this.labelProcesosEnEjecucion.Location = new System.Drawing.Point(122, 17);
            this.labelProcesosEnEjecucion.Name = "labelProcesosEnEjecucion";
            this.labelProcesosEnEjecucion.Size = new System.Drawing.Size(111, 13);
            this.labelProcesosEnEjecucion.TabIndex = 15;
            this.labelProcesosEnEjecucion.Text = "Proceso en Ejecución";
            this.labelProcesosEnEjecucion.Click += new System.EventHandler(this.label1_Click);
            // 
            // listViewProcesosTerminados
            // 
            this.listViewProcesosTerminados.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader6,
            this.columnHeader7,
            this.columnHeader8,
            this.columnHeader9,
            this.columnHeader10,
            this.columnHeader11});
            this.listViewProcesosTerminados.GridLines = true;
            this.listViewProcesosTerminados.Location = new System.Drawing.Point(345, 162);
            this.listViewProcesosTerminados.Name = "listViewProcesosTerminados";
            this.listViewProcesosTerminados.Size = new System.Drawing.Size(677, 322);
            this.listViewProcesosTerminados.TabIndex = 18;
            this.listViewProcesosTerminados.UseCompatibleStateImageBehavior = false;
            this.listViewProcesosTerminados.View = System.Windows.Forms.View.Details;
            this.listViewProcesosTerminados.SelectedIndexChanged += new System.EventHandler(this.listView3_SelectedIndexChanged);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "ID";
            this.columnHeader1.Width = 45;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "OPE";
            this.columnHeader2.Width = 90;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "RES";
            this.columnHeader3.Width = 90;
            // 
            // labelProcesosTerminados
            // 
            this.labelProcesosTerminados.AutoSize = true;
            this.labelProcesosTerminados.Location = new System.Drawing.Point(610, 135);
            this.labelProcesosTerminados.Name = "labelProcesosTerminados";
            this.labelProcesosTerminados.Size = new System.Drawing.Size(109, 13);
            this.labelProcesosTerminados.TabIndex = 17;
            this.labelProcesosTerminados.Text = "Procesos Terminados";
            // 
            // botonLimpiar
            // 
            this.botonLimpiar.Enabled = false;
            this.botonLimpiar.Location = new System.Drawing.Point(702, 62);
            this.botonLimpiar.Name = "botonLimpiar";
            this.botonLimpiar.Size = new System.Drawing.Size(96, 41);
            this.botonLimpiar.TabIndex = 24;
            this.botonLimpiar.Text = "Limpiar Todo";
            this.botonLimpiar.UseVisualStyleBackColor = true;
            this.botonLimpiar.Click += new System.EventHandler(this.botonLimpiar_Click);
            // 
            // labelProcesosNuevosPendientesMostrar
            // 
            this.labelProcesosNuevosPendientesMostrar.AutoSize = true;
            this.labelProcesosNuevosPendientesMostrar.Location = new System.Drawing.Point(534, 78);
            this.labelProcesosNuevosPendientesMostrar.Name = "labelProcesosNuevosPendientesMostrar";
            this.labelProcesosNuevosPendientesMostrar.Size = new System.Drawing.Size(43, 13);
            this.labelProcesosNuevosPendientesMostrar.TabIndex = 30;
            this.labelProcesosNuevosPendientesMostrar.Text = "------------";
            // 
            // labelProcesosNuevosPedientes
            // 
            this.labelProcesosNuevosPedientes.AutoSize = true;
            this.labelProcesosNuevosPedientes.BackColor = System.Drawing.SystemColors.Control;
            this.labelProcesosNuevosPedientes.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.labelProcesosNuevosPedientes.Location = new System.Drawing.Point(380, 76);
            this.labelProcesosNuevosPedientes.Name = "labelProcesosNuevosPedientes";
            this.labelProcesosNuevosPedientes.Size = new System.Drawing.Size(152, 15);
            this.labelProcesosNuevosPedientes.TabIndex = 29;
            this.labelProcesosNuevosPedientes.Text = "Procesos Nuevos Pendientes:";
            // 
            // labelContadorGlobalImprime
            // 
            this.labelContadorGlobalImprime.AutoSize = true;
            this.labelContadorGlobalImprime.Location = new System.Drawing.Point(515, 50);
            this.labelContadorGlobalImprime.Name = "labelContadorGlobalImprime";
            this.labelContadorGlobalImprime.Size = new System.Drawing.Size(43, 13);
            this.labelContadorGlobalImprime.TabIndex = 28;
            this.labelContadorGlobalImprime.Text = "------------";
            this.labelContadorGlobalImprime.Click += new System.EventHandler(this.labelContadorGlobalImprime_Click);
            // 
            // labelContadorGlobal
            // 
            this.labelContadorGlobal.AutoSize = true;
            this.labelContadorGlobal.BackColor = System.Drawing.SystemColors.Control;
            this.labelContadorGlobal.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.labelContadorGlobal.Location = new System.Drawing.Point(380, 50);
            this.labelContadorGlobal.Name = "labelContadorGlobal";
            this.labelContadorGlobal.Size = new System.Drawing.Size(88, 15);
            this.labelContadorGlobal.TabIndex = 27;
            this.labelContadorGlobal.Text = "Contador Global:";
            this.labelContadorGlobal.Click += new System.EventHandler(this.labelContadorGlobal_Click);
            // 
            // listViewProcesosBloqueados
            // 
            this.listViewProcesosBloqueados.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader4,
            this.columnHeader5});
            this.listViewProcesosBloqueados.GridLines = true;
            this.listViewProcesosBloqueados.Location = new System.Drawing.Point(214, 162);
            this.listViewProcesosBloqueados.Name = "listViewProcesosBloqueados";
            this.listViewProcesosBloqueados.Size = new System.Drawing.Size(105, 322);
            this.listViewProcesosBloqueados.TabIndex = 32;
            this.listViewProcesosBloqueados.UseCompatibleStateImageBehavior = false;
            this.listViewProcesosBloqueados.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "ID";
            this.columnHeader4.Width = 50;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "TTB";
            this.columnHeader5.Width = 50;
            // 
            // labelProcesosBloqueados
            // 
            this.labelProcesosBloqueados.AutoSize = true;
            this.labelProcesosBloqueados.Location = new System.Drawing.Point(211, 135);
            this.labelProcesosBloqueados.Name = "labelProcesosBloqueados";
            this.labelProcesosBloqueados.Size = new System.Drawing.Size(110, 13);
            this.labelProcesosBloqueados.TabIndex = 31;
            this.labelProcesosBloqueados.Text = "Procesos Bloqueados";
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "T. Llegada";
            this.columnHeader6.Width = 70;
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "T. Finalización";
            this.columnHeader7.Width = 80;
            // 
            // columnHeader8
            // 
            this.columnHeader8.Text = "T. Servicio";
            this.columnHeader8.Width = 64;
            // 
            // columnHeader9
            // 
            this.columnHeader9.Text = "T. Espera";
            // 
            // columnHeader10
            // 
            this.columnHeader10.Text = "T. Retorno";
            this.columnHeader10.Width = 70;
            // 
            // columnHeader11
            // 
            this.columnHeader11.Text = "T. Respuesta";
            this.columnHeader11.Width = 79;
            // 
            // ventanaPrincipal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1034, 513);
            this.Controls.Add(this.listViewProcesosBloqueados);
            this.Controls.Add(this.labelProcesosBloqueados);
            this.Controls.Add(this.labelProcesosNuevosPendientesMostrar);
            this.Controls.Add(this.labelProcesosNuevosPedientes);
            this.Controls.Add(this.labelContadorGlobalImprime);
            this.Controls.Add(this.labelContadorGlobal);
            this.Controls.Add(this.botonLimpiar);
            this.Controls.Add(this.listViewProcesosTerminados);
            this.Controls.Add(this.labelProcesosTerminados);
            this.Controls.Add(this.listViewProcesoEnEjecucion);
            this.Controls.Add(this.labelProcesosEnEjecucion);
            this.Controls.Add(this.listViewProcesosListos);
            this.Controls.Add(this.labelProcesosListos);
            this.Controls.Add(this.botonIniciarProcesos);
            this.Controls.Add(this.labelCantidadDeProcesos);
            this.Controls.Add(this.textBoxCantidadDeProcesos);
            this.MaximizeBox = false;
            this.Name = "ventanaPrincipal";
            this.Text = "Sistemas Operativos";
            this.Load += new System.EventHandler(this.ventanaPrincipal_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.ventanaPrincipal_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox textBoxCantidadDeProcesos;
        private System.Windows.Forms.Label labelCantidadDeProcesos;
        private System.Windows.Forms.Button botonIniciarProcesos;
        private System.Windows.Forms.Label labelProcesosListos;
        private System.Windows.Forms.ListView listViewProcesosListos;
        private System.Windows.Forms.ColumnHeader columnHeaderID;
        private System.Windows.Forms.ColumnHeader columnHeaderTME;
        private System.Windows.Forms.ListView listViewProcesoEnEjecucion;
        private System.Windows.Forms.Label labelProcesosEnEjecucion;
        private System.Windows.Forms.ListView listViewProcesosTerminados;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.Label labelProcesosTerminados;
        private System.Windows.Forms.Button botonLimpiar;
        private System.Windows.Forms.ColumnHeader columnHeaderTieTra;
        private System.Windows.Forms.ColumnHeader columnHeaderIdentificador;
        private System.Windows.Forms.ColumnHeader columnHeaderOPE;
        private System.Windows.Forms.ColumnHeader columnHeaderTieMaxEst;
        private System.Windows.Forms.ColumnHeader columnHeaderTT;
        private System.Windows.Forms.ColumnHeader columnHeaderTR;
        private System.Windows.Forms.Label labelProcesosNuevosPendientesMostrar;
        private System.Windows.Forms.Label labelProcesosNuevosPedientes;
        private System.Windows.Forms.Label labelContadorGlobalImprime;
        private System.Windows.Forms.Label labelContadorGlobal;
        private System.Windows.Forms.ListView listViewProcesosBloqueados;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.Label labelProcesosBloqueados;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.ColumnHeader columnHeader8;
        private System.Windows.Forms.ColumnHeader columnHeader9;
        private System.Windows.Forms.ColumnHeader columnHeader10;
        private System.Windows.Forms.ColumnHeader columnHeader11;
    }
}

