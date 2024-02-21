package Ventanas;

import Modelo.autores;
import controlador.SqlAutores;
import javax.swing.JOptionPane;

public class autor extends javax.swing.JFrame {

    public autor() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Titulo = new javax.swing.JLabel();
        Id_usuario = new javax.swing.JLabel();
        Nombre = new javax.swing.JLabel();
        Nacionalidad = new javax.swing.JLabel();
        Field1 = new javax.swing.JTextField();
        Field2 = new javax.swing.JTextField();
        Field3 = new javax.swing.JTextField();
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
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        Titulo.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        Titulo.setForeground(new java.awt.Color(255, 102, 102));
        getContentPane().add(Titulo, new org.netbeans.lib.awtextra.AbsoluteConstraints(360, 50, -1, -1));

        Id_usuario.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Id_usuario.setForeground(new java.awt.Color(255, 255, 255));
        Id_usuario.setText("Id autor:");
        getContentPane().add(Id_usuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(160, 110, -1, -1));

        Nombre.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Nombre.setForeground(new java.awt.Color(255, 255, 255));
        Nombre.setText("Nombre:");
        getContentPane().add(Nombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(160, 170, -1, -1));

        Nacionalidad.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Nacionalidad.setForeground(new java.awt.Color(255, 255, 255));
        Nacionalidad.setText("Nacionalidad:");
        getContentPane().add(Nacionalidad, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 230, -1, -1));
        getContentPane().add(Field1, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 110, 340, 30));
        getContentPane().add(Field2, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 170, 340, 30));
        getContentPane().add(Field3, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 230, 340, 30));

        Guardar.setBackground(new java.awt.Color(153, 153, 255));
        Guardar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Guardar.setText("Guardar");
        Guardar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                GuardarActionPerformed(evt);
            }
        });
        getContentPane().add(Guardar, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 420, -1, -1));

        Modificar.setBackground(new java.awt.Color(153, 153, 255));
        Modificar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Modificar.setText("Modificar");
        Modificar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ModificarActionPerformed(evt);
            }
        });
        getContentPane().add(Modificar, new org.netbeans.lib.awtextra.AbsoluteConstraints(280, 420, -1, -1));

        Eliminar.setBackground(new java.awt.Color(153, 153, 255));
        Eliminar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Eliminar.setText("Eliminar");
        Eliminar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EliminarActionPerformed(evt);
            }
        });
        getContentPane().add(Eliminar, new org.netbeans.lib.awtextra.AbsoluteConstraints(450, 420, -1, -1));

        Limpiar.setBackground(new java.awt.Color(153, 153, 255));
        Limpiar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Limpiar.setText("Limpiar");
        Limpiar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LimpiarActionPerformed(evt);
            }
        });
        getContentPane().add(Limpiar, new org.netbeans.lib.awtextra.AbsoluteConstraints(610, 420, -1, -1));

        Buscar.setBackground(new java.awt.Color(153, 153, 255));
        Buscar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Buscar.setText("Buscar");
        Buscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BuscarActionPerformed(evt);
            }
        });
        getContentPane().add(Buscar, new org.netbeans.lib.awtextra.AbsoluteConstraints(440, 270, 170, -1));

        Wallpaper.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/descarga.jpg"))); // NOI18N
        getContentPane().add(Wallpaper, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void GuardarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_GuardarActionPerformed
        autores a = new autores();
        SqlAutores b = new SqlAutores();
        a.setNombre(Field2.getText());
        a.setNacionalidad(Field3.getText());

        if (b.registrar(a)) {
            JOptionPane.showMessageDialog(null, "Registro Guardado");
            limpiar();
        } else {
            JOptionPane.showMessageDialog(null, "Error al Guardar");
            limpiar();
        }
    }//GEN-LAST:event_GuardarActionPerformed

    private void ModificarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ModificarActionPerformed
        autores a = new autores();
        SqlAutores b = new SqlAutores();

        a.setId_autor(Integer.parseInt(Field1.getText()));
        a.setNombre(Field2.getText());
        a.setNacionalidad(Field3.getText());

        if (b.modificar(a)) {
            JOptionPane.showMessageDialog(null, "Registro Modificado");
            limpiar();
        } else {
            JOptionPane.showMessageDialog(null, "Error al Modificar");
            limpiar();
        }
    }//GEN-LAST:event_ModificarActionPerformed

    private void EliminarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EliminarActionPerformed
        autores a = new autores();
        SqlAutores b = new SqlAutores();

        a.setId_autor(Integer.parseInt(Field1.getText()));

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
        autores a = new autores();
        SqlAutores b = new SqlAutores();

        a.setNombre(Field2.getText());

        if (b.buscar(a)) {
            Field1.setText(String.valueOf(a.getId_autor()));
            Field2.setText(a.getNombre());
            Field3.setText(a.getNacionalidad());
        } else {
            JOptionPane.showMessageDialog(null, "No se encontro el registro");
            limpiar();
        }
    }//GEN-LAST:event_BuscarActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        Home.frmAut = null;
    }//GEN-LAST:event_formWindowClosing

    public void limpiar() {
        Field1.setText("");
        Field2.setText("");
        Field3.setText("");
    }
    
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new autor().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    public javax.swing.JButton Buscar;
    public javax.swing.JButton Eliminar;
    public javax.swing.JTextField Field1;
    public javax.swing.JTextField Field2;
    public javax.swing.JTextField Field3;
    public javax.swing.JButton Guardar;
    public javax.swing.JLabel Id_usuario;
    public javax.swing.JButton Limpiar;
    public javax.swing.JButton Modificar;
    private javax.swing.JLabel Nacionalidad;
    private javax.swing.JLabel Nombre;
    public javax.swing.JLabel Titulo;
    private javax.swing.JLabel Wallpaper;
    // End of variables declaration//GEN-END:variables
}
