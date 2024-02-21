package Ventanas;

import Modelo.prestamos;
import controlador.SqlPrestamo;
import javax.swing.JOptionPane;

public class prestamo extends javax.swing.JFrame {

    public prestamo() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Titulo = new javax.swing.JLabel();
        Id_usuario = new javax.swing.JLabel();
        Ejemplar = new javax.swing.JLabel();
        Field1 = new javax.swing.JTextField();
        Field2 = new javax.swing.JTextField();
        Guardar = new javax.swing.JButton();
        Modificar = new javax.swing.JButton();
        Eliminar = new javax.swing.JButton();
        Limpiar = new javax.swing.JButton();
        Buscar = new javax.swing.JButton();
        Wallpaper = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setPreferredSize(new java.awt.Dimension(780, 527));
        setSize(new java.awt.Dimension(0, 0));
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowDeactivated(java.awt.event.WindowEvent evt) {
                formWindowDeactivated(evt);
            }
        });
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        Titulo.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        Titulo.setForeground(new java.awt.Color(255, 102, 102));
        getContentPane().add(Titulo, new org.netbeans.lib.awtextra.AbsoluteConstraints(310, 50, -1, -1));

        Id_usuario.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Id_usuario.setForeground(new java.awt.Color(255, 255, 255));
        Id_usuario.setText("No Ejemplar:");
        getContentPane().add(Id_usuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 110, -1, -1));

        Ejemplar.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Ejemplar.setForeground(new java.awt.Color(255, 255, 255));
        Ejemplar.setText("Id_usaurio:");
        getContentPane().add(Ejemplar, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 180, -1, -1));
        getContentPane().add(Field1, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 110, 220, 30));
        getContentPane().add(Field2, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 180, 220, 30));

        Guardar.setBackground(new java.awt.Color(153, 153, 255));
        Guardar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Guardar.setText("Guardar");
        Guardar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                GuardarActionPerformed(evt);
            }
        });
        getContentPane().add(Guardar, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 280, -1, -1));

        Modificar.setBackground(new java.awt.Color(153, 153, 255));
        Modificar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Modificar.setText("Modificar");
        Modificar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ModificarActionPerformed(evt);
            }
        });
        getContentPane().add(Modificar, new org.netbeans.lib.awtextra.AbsoluteConstraints(260, 280, -1, -1));

        Eliminar.setBackground(new java.awt.Color(153, 153, 255));
        Eliminar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Eliminar.setText("Eliminar");
        Eliminar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EliminarActionPerformed(evt);
            }
        });
        getContentPane().add(Eliminar, new org.netbeans.lib.awtextra.AbsoluteConstraints(420, 280, -1, -1));

        Limpiar.setBackground(new java.awt.Color(153, 153, 255));
        Limpiar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Limpiar.setText("Limpiar");
        Limpiar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LimpiarActionPerformed(evt);
            }
        });
        getContentPane().add(Limpiar, new org.netbeans.lib.awtextra.AbsoluteConstraints(570, 280, -1, -1));

        Buscar.setBackground(new java.awt.Color(153, 153, 255));
        Buscar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Buscar.setText("Buscar");
        Buscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BuscarActionPerformed(evt);
            }
        });
        getContentPane().add(Buscar, new org.netbeans.lib.awtextra.AbsoluteConstraints(550, 180, 120, 30));

        Wallpaper.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/descarga.jpg"))); // NOI18N
        getContentPane().add(Wallpaper, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void GuardarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_GuardarActionPerformed
        prestamos a = new prestamos();
        SqlPrestamo b = new SqlPrestamo();
        a.setNum_ejem(Integer.parseInt(Field1.getText()));
        a.setId_usuario(Integer.parseInt(Field2.getText()));

        if (b.registrar(a)) {
            JOptionPane.showMessageDialog(null, "Registro Guardado");
            limpiar();
        } else {
            JOptionPane.showMessageDialog(null, "Error al Guardar");
            limpiar();
        }
    }//GEN-LAST:event_GuardarActionPerformed

    private void ModificarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ModificarActionPerformed
        prestamos a = new prestamos();
        SqlPrestamo b = new SqlPrestamo();       
        a.setNum_ejem(Integer.parseInt(Field1.getText()));
        a.setId_usuario(Integer.parseInt(Field2.getText()));

        if (b.modificar(a)) {
            JOptionPane.showMessageDialog(null, "Registro Modificado");
            limpiar();
        } else {
            JOptionPane.showMessageDialog(null, "Error al Modificar");
            limpiar();
        }
    }//GEN-LAST:event_ModificarActionPerformed

    private void EliminarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EliminarActionPerformed
        prestamos a = new prestamos();
        SqlPrestamo b = new SqlPrestamo();

        a.setNum_ejem(Integer.parseInt(Field1.getText()));

        if (b.eliminar(a)) {
            JOptionPane.showMessageDialog(null, "Registro Eliminado");
            limpiar();
        } else {
            JOptionPane.showMessageDialog(null, "Error al Eliminar");
            limpiar();
        }
    }//GEN-LAST:event_EliminarActionPerformed

    private void LimpiarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_LimpiarActionPerformed
        limpiar();
    }//GEN-LAST:event_LimpiarActionPerformed

    private void BuscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BuscarActionPerformed
        prestamos a = new prestamos();
        SqlPrestamo b = new SqlPrestamo();

        a.setNum_ejem(Integer.parseInt(Field1.getText()));

        if (b.buscar(a)) {
            Field1.setText(String.valueOf(a.getNum_ejem()));
            Field2.setText(String.valueOf(a.getId_usuario()));
        } else {
            JOptionPane.showMessageDialog(null, "No se encontro el registro");
            limpiar();
        }
    }//GEN-LAST:event_BuscarActionPerformed

    private void formWindowDeactivated(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowDeactivated
        Home.frmPres = null;
    }//GEN-LAST:event_formWindowDeactivated

    public void limpiar() {
        Field1.setText("");
        Field2.setText("");
    }
    
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(prestamo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(prestamo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(prestamo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(prestamo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new prestamo().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    public javax.swing.JButton Buscar;
    public javax.swing.JLabel Ejemplar;
    public javax.swing.JButton Eliminar;
    public javax.swing.JTextField Field1;
    public javax.swing.JTextField Field2;
    public javax.swing.JButton Guardar;
    public javax.swing.JLabel Id_usuario;
    public javax.swing.JButton Limpiar;
    public javax.swing.JButton Modificar;
    public javax.swing.JLabel Titulo;
    private javax.swing.JLabel Wallpaper;
    // End of variables declaration//GEN-END:variables
}