package Ventanas;

import controlador.SqlLibros;
import Modelo.libros;
import javax.swing.JOptionPane;

public class libro extends javax.swing.JFrame {

    public libro() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Titulo = new javax.swing.JLabel();
        Isbn = new javax.swing.JLabel();
        Nombre = new javax.swing.JLabel();
        Genero = new javax.swing.JLabel();
        Editorial = new javax.swing.JLabel();
        Field1 = new javax.swing.JTextField();
        Field2 = new javax.swing.JTextField();
        Field3 = new javax.swing.JTextField();
        Field4 = new javax.swing.JTextField();
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
        getContentPane().add(Titulo, new org.netbeans.lib.awtextra.AbsoluteConstraints(360, 60, -1, -1));

        Isbn.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Isbn.setForeground(new java.awt.Color(255, 255, 255));
        Isbn.setText("Isbn:");
        getContentPane().add(Isbn, new org.netbeans.lib.awtextra.AbsoluteConstraints(160, 120, -1, -1));

        Nombre.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Nombre.setForeground(new java.awt.Color(255, 255, 255));
        Nombre.setText("Nombre: ");
        getContentPane().add(Nombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 180, -1, -1));

        Genero.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Genero.setForeground(new java.awt.Color(255, 255, 255));
        Genero.setText("Genero:");
        getContentPane().add(Genero, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 240, -1, -1));

        Editorial.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Editorial.setForeground(new java.awt.Color(255, 255, 255));
        Editorial.setText("Editorial:");
        getContentPane().add(Editorial, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 300, -1, -1));
        getContentPane().add(Field1, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 120, 230, 30));
        getContentPane().add(Field2, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 180, 230, 30));
        getContentPane().add(Field3, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 240, 230, 30));
        getContentPane().add(Field4, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 300, 230, 30));

        Guardar.setBackground(new java.awt.Color(153, 153, 255));
        Guardar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Guardar.setText("Guardar");
        Guardar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                GuardarActionPerformed(evt);
            }
        });
        getContentPane().add(Guardar, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 410, -1, -1));

        Modificar.setBackground(new java.awt.Color(153, 153, 255));
        Modificar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Modificar.setText("Modificar");
        Modificar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ModificarActionPerformed(evt);
            }
        });
        getContentPane().add(Modificar, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 410, -1, -1));

        Eliminar.setBackground(new java.awt.Color(153, 153, 255));
        Eliminar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Eliminar.setText("Eliminar");
        Eliminar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EliminarActionPerformed(evt);
            }
        });
        getContentPane().add(Eliminar, new org.netbeans.lib.awtextra.AbsoluteConstraints(420, 410, -1, -1));

        Limpiar.setBackground(new java.awt.Color(153, 153, 255));
        Limpiar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Limpiar.setForeground(new java.awt.Color(51, 51, 51));
        Limpiar.setText("Limpiar");
        Limpiar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                LimpiarActionPerformed(evt);
            }
        });
        getContentPane().add(Limpiar, new org.netbeans.lib.awtextra.AbsoluteConstraints(560, 410, -1, -1));

        Buscar.setBackground(new java.awt.Color(153, 153, 255));
        Buscar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Buscar.setText("Buscar");
        Buscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BuscarActionPerformed(evt);
            }
        });
        getContentPane().add(Buscar, new org.netbeans.lib.awtextra.AbsoluteConstraints(530, 300, 130, -1));

        Wallpaper.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/descarga.jpg"))); // NOI18N
        Wallpaper.setRequestFocusEnabled(false);
        getContentPane().add(Wallpaper, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents
        
    private void BuscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_BuscarActionPerformed
        libros a = new libros();
        SqlLibros b = new SqlLibros();
        
        a.setNombre(Field2.getText());

        if (b.buscar(a)) {
            Field1.setText(String.valueOf(a.getIsbn()));
            Field2.setText(a.getNombre());
            Field3.setText(a.getGenero());
            Field4.setText(a.getEditorial());
        } else {
            JOptionPane.showMessageDialog(null, "No se encontro el registro");
            limpiar();
        }
    }//GEN-LAST:event_BuscarActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        Home.frmLib = null;
    }//GEN-LAST:event_formWindowClosing

    private void GuardarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_GuardarActionPerformed
        libros a = new libros();
        SqlLibros b = new SqlLibros();
        a.setNombre(Field2.getText());
        a.setGenero(Field3.getText());
        a.setEditorial(Field4.getText());

        if (b.registrar(a)) {
            JOptionPane.showMessageDialog(null, "Registro Guardado");
            limpiar();
        } else {
            JOptionPane.showMessageDialog(null, "Error al Guardar");
            limpiar();
        }
    }//GEN-LAST:event_GuardarActionPerformed

    private void ModificarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ModificarActionPerformed
        libros a = new libros();
        SqlLibros b = new SqlLibros();
        
        a.setIsbn(Integer.parseInt(Field1.getText()));
        a.setNombre(Field2.getText());
        a.setGenero(Field3.getText());
        a.setEditorial(Field4.getText());

        if (b.modificar(a)) {
            JOptionPane.showMessageDialog(null, "Registro Modificado");
            limpiar();
        } else {
            JOptionPane.showMessageDialog(null, "Error al Modificar");
            limpiar();
        }
    }//GEN-LAST:event_ModificarActionPerformed

    private void EliminarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EliminarActionPerformed
        libros a = new libros();
        SqlLibros b = new SqlLibros();
        
        a.setIsbn(Integer.parseInt(Field1.getText()));

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
    
    public void limpiar() {
        Field1.setText("");
        Field2.setText("");
        Field3.setText("");
        Field4.setText("");
    }

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new libro().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    public javax.swing.JButton Buscar;
    private javax.swing.JLabel Editorial;
    public javax.swing.JButton Eliminar;
    public javax.swing.JTextField Field1;
    public javax.swing.JTextField Field2;
    public javax.swing.JTextField Field3;
    public javax.swing.JTextField Field4;
    private javax.swing.JLabel Genero;
    public javax.swing.JButton Guardar;
    public javax.swing.JLabel Isbn;
    public javax.swing.JButton Limpiar;
    public javax.swing.JButton Modificar;
    private javax.swing.JLabel Nombre;
    public javax.swing.JLabel Titulo;
    private javax.swing.JLabel Wallpaper;
    // End of variables declaration//GEN-END:variables
}