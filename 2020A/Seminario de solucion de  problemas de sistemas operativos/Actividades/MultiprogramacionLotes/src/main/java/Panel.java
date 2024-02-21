
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.swing.JOptionPane;

public class Panel extends javax.swing.JFrame {

    String lote, operacion, numPrograma;
    int tiempo, loteP, medio;
    boolean m;

    public Panel() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        ProcesosLab = new javax.swing.JLabel();
        ProcesosTex = new javax.swing.JTextField();
        ProcesoL = new javax.swing.JLabel();
        ProcesoScr = new javax.swing.JScrollPane();
        ProcesoTab = new javax.swing.JTable();
        LotesL = new javax.swing.JLabel();
        LotesScr = new javax.swing.JScrollPane();
        LotesTab = new javax.swing.JTable();
        TerminadosL = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jButton1 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        ProcesosLab.setText("Numero de procesos: ");

        ProcesoL.setText("Proceso en ejecucion");

        ProcesoTab.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null}
            },
            new String [] {
                "ID", "Tiempo Maximo Estimado", "Operacion"
            }
        ));
        ProcesoScr.setViewportView(ProcesoTab);

        LotesL.setText("Lote pendiente");

        LotesTab.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null},
                {null, null, null},
                {null, null, null}
            },
            new String [] {
                "ID", "Tiempo Maximo Estimado", "Operacion"
            }
        ));
        LotesScr.setViewportView(LotesTab);

        TerminadosL.setText("Procesos terminados");

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null}
            },
            new String [] {
                "ID", "Operacion", "Resultado"
            }
        ));
        jScrollPane1.setViewportView(jTable1);

        jButton1.setText("Iniciar");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(ProcesosLab)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(ProcesosTex, javax.swing.GroupLayout.PREFERRED_SIZE, 89, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jButton1))
                            .addComponent(ProcesoL)
                            .addComponent(LotesL))
                        .addContainerGap(426, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                .addComponent(ProcesoScr, javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(LotesScr, javax.swing.GroupLayout.Alignment.LEADING))
                            .addComponent(TerminadosL)
                            .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(0, 276, Short.MAX_VALUE))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(ProcesosTex, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(ProcesosLab))
                    .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                .addGap(26, 26, 26)
                .addComponent(ProcesoL)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(ProcesoScr, javax.swing.GroupLayout.PREFERRED_SIZE, 46, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(LotesL)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(LotesScr, javax.swing.GroupLayout.PREFERRED_SIZE, 76, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(TerminadosL)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    public boolean esOperacion(String ope) {
        Pattern pattern = Pattern.compile("^\\d{1}(\\+|\\-|\\*|\\/|\\%|\\^)\\d{1}$");
        Matcher mather = pattern.matcher(ope);
        return mather.find();
    }

    public int numTrabajo() {
        int numero = (int) (Math.random() * 10) + 1;
        return numero;
    }

    public int temEstimado() {
        int numero;
        do {
            numero = (int) (Math.random() * 10) + 1;
        } while (numero < 5);
        return numero;
    }

    public String genOperacion() {
        int numero, numero2, numero3;
        String operacion;
        numero = (int) (Math.random() * 9) + 1;
        operacion = String.valueOf(numero);
        numero2 = (int) (Math.random() * 5) + 1;
        switch (numero2) {
            case 1:
                operacion = operacion + "+";
                break;
            case 2:
                operacion = operacion + "-";
                break;
            case 3:
                operacion = operacion + "*";
                break;
            case 4:
                operacion = operacion + "/";
                break;
            case 5:
                operacion = operacion + "%";
                break;
            default:
                System.out.println("Error en el switch");
                break;
        }
        numero3 = (int) (Math.random() * 10) + 1;
        operacion = operacion + numero3;
        return operacion;
    }
    
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        if (!ProcesosTex.getText().equals("")) {
            Lista b = new Lista();
            int c = 0, d = 1, procesos = Procesos.Text.getText();
            loteP = procesos / 3;
            medio = procesos / 2;
            c = procesos;
            while (c != 0) {
                operacion = genOperacion();
                tiempo = temEstimado();
                if (b.esVacio() == true) {
                    numPrograma = String.valueOf(numTrabajo());
                } else {
                    do {
                        numPrograma = String.valueOf(numTrabajo());
                    } while (b.buscar(numPrograma) == true);
                }
                if (c == medio) {
                    m = true;
                }
                if (c % 3 == 0) {
                    loteP--;
                }
                b.agregar(loteP, lote, operacion, tiempo, numPrograma, m);
                c--;
            }
        } else {
            JOptionPane.showMessageDialog(null, "Debe ingresar sus datos");
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Panel().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel LotesL;
    private javax.swing.JScrollPane LotesScr;
    private javax.swing.JTable LotesTab;
    private javax.swing.JLabel ProcesoL;
    private javax.swing.JScrollPane ProcesoScr;
    private javax.swing.JTable ProcesoTab;
    private javax.swing.JLabel ProcesosLab;
    private javax.swing.JTextField ProcesosTex;
    private javax.swing.JLabel TerminadosL;
    private javax.swing.JButton jButton1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable jTable1;
    // End of variables declaration//GEN-END:variables
}
