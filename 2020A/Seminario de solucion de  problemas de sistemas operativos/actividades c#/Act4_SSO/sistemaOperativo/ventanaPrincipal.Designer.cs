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
            this.labelNoDeLotesPendientes = new System.Windows.Forms.Label();
            this.listViewLotesPendientes = new System.Windows.Forms.ListView();
            this.columnHeaderID = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderTME = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderTieTra = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.listViewProcesosEnEjecucion = new System.Windows.Forms.ListView();
            this.columnHeaderIdentificador = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderOPE = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderTieMaxEst = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderTT = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderTR = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.label1 = new System.Windows.Forms.Label();
            this.listViewLotesTerminados = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.label2 = new System.Windows.Forms.Label();
            this.botonLimpiar = new System.Windows.Forms.Button();
            this.labelNoLotPenMostrar = new System.Windows.Forms.Label();
            this.labelNoLotPed = new System.Windows.Forms.Label();
            this.labelContadorGlobalImprime = new System.Windows.Forms.Label();
            this.labelContadorGlobal = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // textBoxCantidadDeProcesos
            // 
            this.textBoxCantidadDeProcesos.Location = new System.Drawing.Point(139, 12);
            this.textBoxCantidadDeProcesos.Name = "textBoxCantidadDeProcesos";
            this.textBoxCantidadDeProcesos.Size = new System.Drawing.Size(96, 20);
            this.textBoxCantidadDeProcesos.TabIndex = 1;
            this.textBoxCantidadDeProcesos.TextChanged += new System.EventHandler(this.textBoxCantidadDeProcesos_TextChanged);
            // 
            // labelCantidadDeProcesos
            // 
            this.labelCantidadDeProcesos.AutoSize = true;
            this.labelCantidadDeProcesos.Location = new System.Drawing.Point(22, 15);
            this.labelCantidadDeProcesos.Name = "labelCantidadDeProcesos";
            this.labelCantidadDeProcesos.Size = new System.Drawing.Size(114, 13);
            this.labelCantidadDeProcesos.TabIndex = 10;
            this.labelCantidadDeProcesos.Text = "Cantidad de Procesos:";
            // 
            // botonIniciarProcesos
            // 
            this.botonIniciarProcesos.Location = new System.Drawing.Point(259, 12);
            this.botonIniciarProcesos.Name = "botonIniciarProcesos";
            this.botonIniciarProcesos.Size = new System.Drawing.Size(102, 23);
            this.botonIniciarProcesos.TabIndex = 11;
            this.botonIniciarProcesos.Text = "Iniciar Procesos";
            this.botonIniciarProcesos.UseVisualStyleBackColor = true;
            this.botonIniciarProcesos.Click += new System.EventHandler(this.botonIniciarProcesos_Click);
            // 
            // labelNoDeLotesPendientes
            // 
            this.labelNoDeLotesPendientes.AutoSize = true;
            this.labelNoDeLotesPendientes.Location = new System.Drawing.Point(278, 199);
            this.labelNoDeLotesPendientes.Name = "labelNoDeLotesPendientes";
            this.labelNoDeLotesPendientes.Size = new System.Drawing.Size(83, 13);
            this.labelNoDeLotesPendientes.TabIndex = 12;
            this.labelNoDeLotesPendientes.Text = "Lotes Pedientes";
            // 
            // listViewLotesPendientes
            // 
            this.listViewLotesPendientes.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeaderID,
            this.columnHeaderTME,
            this.columnHeaderTieTra});
            this.listViewLotesPendientes.GridLines = true;
            this.listViewLotesPendientes.Location = new System.Drawing.Point(23, 226);
            this.listViewLotesPendientes.Name = "listViewLotesPendientes";
            this.listViewLotesPendientes.Size = new System.Drawing.Size(429, 322);
            this.listViewLotesPendientes.TabIndex = 14;
            this.listViewLotesPendientes.UseCompatibleStateImageBehavior = false;
            this.listViewLotesPendientes.View = System.Windows.Forms.View.Details;
            // 
            // columnHeaderID
            // 
            this.columnHeaderID.Text = "ID. del Proceso";
            this.columnHeaderID.Width = 99;
            // 
            // columnHeaderTME
            // 
            this.columnHeaderTME.Text = "Tiempo Máximo Estimado (TME)";
            this.columnHeaderTME.Width = 164;
            // 
            // columnHeaderTieTra
            // 
            this.columnHeaderTieTra.Text = "TT (Tiempo Transcurrido)";
            this.columnHeaderTieTra.Width = 156;
            // 
            // listViewProcesosEnEjecucion
            // 
            this.listViewProcesosEnEjecucion.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeaderIdentificador,
            this.columnHeaderOPE,
            this.columnHeaderTieMaxEst,
            this.columnHeaderTT,
            this.columnHeaderTR});
            this.listViewProcesosEnEjecucion.GridLines = true;
            this.listViewProcesosEnEjecucion.Location = new System.Drawing.Point(51, 107);
            this.listViewProcesosEnEjecucion.Name = "listViewProcesosEnEjecucion";
            this.listViewProcesosEnEjecucion.Size = new System.Drawing.Size(686, 63);
            this.listViewProcesosEnEjecucion.TabIndex = 16;
            this.listViewProcesosEnEjecucion.UseCompatibleStateImageBehavior = false;
            this.listViewProcesosEnEjecucion.View = System.Windows.Forms.View.Details;
            this.listViewProcesosEnEjecucion.SelectedIndexChanged += new System.EventHandler(this.listViewProcesosEnEjecucion_SelectedIndexChanged);
            // 
            // columnHeaderIdentificador
            // 
            this.columnHeaderIdentificador.Text = "ID";
            // 
            // columnHeaderOPE
            // 
            this.columnHeaderOPE.Text = "Operación";
            this.columnHeaderOPE.Width = 141;
            // 
            // columnHeaderTieMaxEst
            // 
            this.columnHeaderTieMaxEst.Text = "TME(Tiempo Máximo Estimado)";
            this.columnHeaderTieMaxEst.Width = 170;
            // 
            // columnHeaderTT
            // 
            this.columnHeaderTT.Text = "TT(Tiempo Transcurrido)";
            this.columnHeaderTT.Width = 138;
            // 
            // columnHeaderTR
            // 
            this.columnHeaderTR.Text = "TR(Tiempo Restante)";
            this.columnHeaderTR.Width = 165;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(364, 80);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(111, 13);
            this.label1.TabIndex = 15;
            this.label1.Text = "Proceso en Ejecución";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // listViewLotesTerminados
            // 
            this.listViewLotesTerminados.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3});
            this.listViewLotesTerminados.GridLines = true;
            this.listViewLotesTerminados.Location = new System.Drawing.Point(468, 226);
            this.listViewLotesTerminados.Name = "listViewLotesTerminados";
            this.listViewLotesTerminados.Size = new System.Drawing.Size(295, 322);
            this.listViewLotesTerminados.TabIndex = 18;
            this.listViewLotesTerminados.UseCompatibleStateImageBehavior = false;
            this.listViewLotesTerminados.View = System.Windows.Forms.View.Details;
            this.listViewLotesTerminados.SelectedIndexChanged += new System.EventHandler(this.listView3_SelectedIndexChanged);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "ID. del Proceso";
            this.columnHeader1.Width = 99;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "Operación";
            this.columnHeader2.Width = 74;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "Resultado";
            this.columnHeader3.Width = 114;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(563, 201);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(91, 13);
            this.label2.TabIndex = 17;
            this.label2.Text = "Lotes Terminados";
            // 
            // botonLimpiar
            // 
            this.botonLimpiar.Enabled = false;
            this.botonLimpiar.Location = new System.Drawing.Point(512, 12);
            this.botonLimpiar.Name = "botonLimpiar";
            this.botonLimpiar.Size = new System.Drawing.Size(96, 41);
            this.botonLimpiar.TabIndex = 24;
            this.botonLimpiar.Text = "Limpiar Todo";
            this.botonLimpiar.UseVisualStyleBackColor = true;
            this.botonLimpiar.Click += new System.EventHandler(this.botonLimpiar_Click);
            // 
            // labelNoLotPenMostrar
            // 
            this.labelNoLotPenMostrar.AutoSize = true;
            this.labelNoLotPenMostrar.Location = new System.Drawing.Point(212, 201);
            this.labelNoLotPenMostrar.Name = "labelNoLotPenMostrar";
            this.labelNoLotPenMostrar.Size = new System.Drawing.Size(43, 13);
            this.labelNoLotPenMostrar.TabIndex = 30;
            this.labelNoLotPenMostrar.Text = "------------";
            // 
            // labelNoLotPed
            // 
            this.labelNoLotPed.AutoSize = true;
            this.labelNoLotPed.BackColor = System.Drawing.SystemColors.Control;
            this.labelNoLotPed.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.labelNoLotPed.Location = new System.Drawing.Point(77, 199);
            this.labelNoLotPed.Name = "labelNoLotPed";
            this.labelNoLotPed.Size = new System.Drawing.Size(129, 15);
            this.labelNoLotPed.TabIndex = 29;
            this.labelNoLotPed.Text = "No. de Lotes Pendientes:";
            // 
            // labelContadorGlobalImprime
            // 
            this.labelContadorGlobalImprime.AutoSize = true;
            this.labelContadorGlobalImprime.Location = new System.Drawing.Point(160, 51);
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
            this.labelContadorGlobal.Location = new System.Drawing.Point(25, 51);
            this.labelContadorGlobal.Name = "labelContadorGlobal";
            this.labelContadorGlobal.Size = new System.Drawing.Size(88, 15);
            this.labelContadorGlobal.TabIndex = 27;
            this.labelContadorGlobal.Text = "Contador Global:";
            this.labelContadorGlobal.Click += new System.EventHandler(this.labelContadorGlobal_Click);
            // 
            // ventanaPrincipal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 574);
            this.Controls.Add(this.labelNoLotPenMostrar);
            this.Controls.Add(this.labelNoLotPed);
            this.Controls.Add(this.labelContadorGlobalImprime);
            this.Controls.Add(this.labelContadorGlobal);
            this.Controls.Add(this.botonLimpiar);
            this.Controls.Add(this.listViewLotesTerminados);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.listViewProcesosEnEjecucion);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listViewLotesPendientes);
            this.Controls.Add(this.labelNoDeLotesPendientes);
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
        private System.Windows.Forms.Label labelNoDeLotesPendientes;
        private System.Windows.Forms.ListView listViewLotesPendientes;
        private System.Windows.Forms.ColumnHeader columnHeaderID;
        private System.Windows.Forms.ColumnHeader columnHeaderTME;
        private System.Windows.Forms.ListView listViewProcesosEnEjecucion;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ListView listViewLotesTerminados;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button botonLimpiar;
        private System.Windows.Forms.ColumnHeader columnHeaderTieTra;
        private System.Windows.Forms.ColumnHeader columnHeaderIdentificador;
        private System.Windows.Forms.ColumnHeader columnHeaderOPE;
        private System.Windows.Forms.ColumnHeader columnHeaderTieMaxEst;
        private System.Windows.Forms.ColumnHeader columnHeaderTT;
        private System.Windows.Forms.ColumnHeader columnHeaderTR;
        private System.Windows.Forms.Label labelNoLotPenMostrar;
        private System.Windows.Forms.Label labelNoLotPed;
        private System.Windows.Forms.Label labelContadorGlobalImprime;
        private System.Windows.Forms.Label labelContadorGlobal;
    }
}

