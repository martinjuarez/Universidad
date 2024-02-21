package Ventanas;

import Modelo.Ejemplares;
import controlador.SqlEjemplares;
import javax.swing.JOptionPane;

public class ejemplar extends javax.swing.JFrame {

    public ejemplar() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Titulo = new javax.swing.JLabel();
        Ejemplar = new javax.swing.JLabel();
        Disponibilidad = new javax.swing.JLabel();
        Fecha = new javax.swing.JLabel();
        Id_usuario = new javax.swing.JLabel();
        Isbn = new javax.swing.JLabel();
        Field1 = new javax.swing.JTextField();
        Field2 = new javax.swing.JTextField();
        Field3 = new javax.swing.JTextField();
        Field4 = new javax.swing.JTextField();
        Field5 = new javax.swing.JTextField();
        Guardar = new javax.swing.JButton();
        Modificar = new javax.swing.JButton();
        Eliminar = new javax.swing.JButton();
        Limpiar = new javax.swing.JButton();
        Buscar = new javax.swing.JButton();
        wall = new javax.swing.JLabel();

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
        getContentPane().add(Titulo, new org.netbeans.lib.awtextra.AbsoluteConstraints(360, 60, -1, -1));

        Ejemplar.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Ejemplar.setForeground(new java.awt.Color(255, 255, 255));
        Ejemplar.setText("No. Ejemplar:");
        getContentPane().add(Ejemplar, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 110, -1, -1));

        Disponibilidad.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Disponibilidad.setForeground(new java.awt.Color(255, 255, 255));
        Disponibilidad.setText("Disponibilidad:");
        getContentPane().add(Disponibilidad, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 170, -1, -1));

        Fecha.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Fecha.setForeground(new java.awt.Color(255, 255, 255));
        Fecha.setText("Fecha Disponible:");
        getContentPane().add(Fecha, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 230, -1, -1));

        Id_usuario.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Id_usuario.setForeground(new java.awt.Color(255, 255, 255));
        Id_usuario.setText("Id usuario:");
        getContentPane().add(Id_usuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 290, -1, -1));

        Isbn.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Isbn.setForeground(new java.awt.Color(255, 255, 255));
        Isbn.setText("Isbn:");
        getContentPane().add(Isbn, new org.netbeans.lib.awtextra.AbsoluteConstraints(180, 350, -1, -1));
        getContentPane().add(Field1, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 110, 240, 30));
        getContentPane().add(Field2, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 170, 240, 30));
        getContentPane().add(Field3, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 230, 240, 30));
        getContentPane().add(Field4, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 290, 240, 30));
        getContentPane().add(Field5, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 350, 240, 30));

        Guardar.setBackground(new java.awt.Color(153, 153, 255));
        Guardar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Guardar.setText("Guardar");
        Guardar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                GuardarActionPerformed(evt);
            }
        });
        getContentPane().add(Guardar, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 450, -1, -1));

        Modificar.setBackground(new java.awt.Color(153, 153, 255));
        Modificar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Modificar.setText("Modificar");
        Modificar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ModificarActionPerformed(evt);
            }
        });
        getContentPane().add(Modificar, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 450, -1, -1));

        Eliminar.setBackground(new java.awt.Color(153, 153, 255));
        Eliminar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Eliminar.setText("Eliminar");
        Eliminar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EliminarActionPerformed(evt);
            }
        });
        getContentPane().add(Eliminar, new org.netbeans.lib.awtextra.AbsoluteConstraints(370, 450, -1, -1));

        Limpiar.setBackground(new java.awt.Color(153, 153, 255));
        Limpiar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Limpiar.setText("Limpiar");
        Limpiar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LimpiarActionPerformed(evt);
            }
        });
        getContentPane().add(Limpiar, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 450, -1, -1));

        Buscar.setBackground(new java.awt.Color(153, 153, 255));
        Buscar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Buscar.setText("Buscar");
        Buscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BuscarActionPerformed(evt);
            }
        });
        getContentPane().add(Buscar, new org.netbeans.lib.awtextra.AbsoluteConstraints(570, 350, 120, -1));

        wall.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/descarga.jpg"))); // NOI18N
        getContentPane().add(wall, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void ModificarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ModificarActionPerformed
        Ejemplares a = new Ejemplares();
        SqlEjemplares b = new SqlEjemplares();

        a.setNum_ejem(Integer.parseInt(Field1.getText()));
        a.setDisponibilidad(Field2.getText());
        a.setFecha_disponibildad(Field3.getText());
        a.setId_usuario(Integer.parseInt(Field4.getText()));
        a.setIsbn(Integer.parseInt(Field5.getText()));

        if (b.modificar(a)) {
            JOptionPane.showMessageDialog(null, "Registro Modificado");
            limpiar();
        } else {
            JOptionPane.showMessageDialog(null, "Error al Modificar");
            limpiar();
        }
    }//GEN-LAST:event_ModificarActionPerformed

    private void EliminarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EliminarActionPerformed
        Ejemplares a = new Ejemplares();
        SqlEjemplares b = new SqlEjemplares();

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
        Ejemplares a = new Ejemplares();
        SqlEjemplares b = new SqlEjemplares();

        a.setNum_ejem(Integer.parseInt(Field1.getText()));

        if (b.buscar(a)) {
            Field1.setText(String.valueOf(a.getNum_ejem()));
            Field2.setText(a.getDisponibilidad());
            Field3.setText(a.getFecha_disponibildad());
            Field4.setText(String.valueOf(a.getId_usuario()));
            Field5.setText(String.valueOf(a.getIsbn()));
        } else {
            JOptionPane.showMessageDialog(null, "No se encontro el registro");
            limpiar();
        }
    }//GEN-LAST:event_BuscarActionPerformed

    private void GuardarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_GuardarActionPerformed
        Ejemplares a = new Ejemplares();
        SqlEjemplares b = new SqlEjemplares();
        a.setDisponibilidad(Field2.getText());
        a.setFecha_disponibildad(Field3.getText());
        a.setId_usuario(Integer.parseInt(Field4.getText()));
        a.setIsbn(Integer.parseInt(Field5.getText()));

        if (b.registrar(a)) {
            JOptionPane.showMessageDialog(null, "Registro Guardado");
            limpiar();
        } else {
            JOptionPane.showMessageDialog(null, "Error al Guardar");
            limpiar();
        }
    }//GEN-LAST:event_GuardarActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
       Home.frmEjem = null;
    }//GEN-LAST:event_formWindowClosing
    
    public void limpiar() {
        Field1.setText("");
        Field2.setText("");
        Field3.setText("");
        Field4.setText("");
        Field5.setText("");
    }
    
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ejemplar().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    public javax.swing.JButton Buscar;
    private javax.swing.JLabel Disponibilidad;
    public javax.swing.JLabel Ejemplar;
    public javax.swing.JButton Eliminar;
    private javax.swing.JLabel Fecha;
    public javax.swing.JTextField Field1;
    public javax.swing.JTextField Field2;
    public javax.swing.JTextField Field3;
    public javax.swing.JTextField Field4;
    public javax.swing.JTextField Field5;
    public javax.swing.JButton Guardar;
    private javax.swing.JLabel Id_usuario;
    private javax.swing.JLabel Isbn;
    public javax.swing.JButton Limpiar;
    public javax.swing.JButton Modificar;
    public javax.swing.JLabel Titulo;
    private javax.swing.JLabel wall;
    // End of variables declaration//GEN-END:variables
}
