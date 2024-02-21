package Ventanas;

import Modelo.usuarios;
import Modelo.hash;
import controlador.SqlUsuarios;
import static Ventanas.Interfaz.frmReg;
import javax.swing.JOptionPane;

public class registro extends javax.swing.JFrame {

    
    public registro() {
        initComponents();
        this.setLocationRelativeTo(null);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Usuario = new javax.swing.JLabel();
        Nombre = new javax.swing.JLabel();
        Edad = new javax.swing.JLabel();
        Domicilio = new javax.swing.JLabel();
        Correo = new javax.swing.JLabel();
        Contraseña = new javax.swing.JLabel();
        Telefono = new javax.swing.JLabel();
        Confirmar = new javax.swing.JLabel();
        txtUsuario = new javax.swing.JTextField();
        txtNombre = new javax.swing.JTextField();
        txtEdad = new javax.swing.JTextField();
        txtDomicilio = new javax.swing.JTextField();
        txtEmail = new javax.swing.JTextField();
        txtTelefono = new javax.swing.JTextField();
        txtContraseña = new javax.swing.JPasswordField();
        txtConfirmar = new javax.swing.JPasswordField();
        Guardar = new javax.swing.JButton();
        Icono = new javax.swing.JLabel();
        Wallpaper = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setPreferredSize(new java.awt.Dimension(930, 602));
        setSize(new java.awt.Dimension(0, 0));
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        Usuario.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Usuario.setForeground(new java.awt.Color(255, 255, 255));
        Usuario.setText("Usuario:");
        getContentPane().add(Usuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(290, 50, -1, -1));

        Nombre.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Nombre.setForeground(new java.awt.Color(255, 255, 255));
        Nombre.setText("Nombre:");
        getContentPane().add(Nombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(290, 100, -1, -1));

        Edad.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Edad.setForeground(new java.awt.Color(255, 255, 255));
        Edad.setText("Edad:");
        getContentPane().add(Edad, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 150, -1, -1));

        Domicilio.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Domicilio.setForeground(new java.awt.Color(255, 255, 255));
        Domicilio.setText("Domicilio:");
        getContentPane().add(Domicilio, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 200, -1, -1));

        Correo.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Correo.setForeground(new java.awt.Color(255, 255, 255));
        Correo.setText("Email:");
        getContentPane().add(Correo, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 250, -1, -1));

        Contraseña.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Contraseña.setForeground(new java.awt.Color(255, 255, 255));
        Contraseña.setText("Contraseña:");
        getContentPane().add(Contraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 350, -1, -1));

        Telefono.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Telefono.setForeground(new java.awt.Color(255, 255, 255));
        Telefono.setText("Telefono:");
        getContentPane().add(Telefono, new org.netbeans.lib.awtextra.AbsoluteConstraints(280, 300, -1, -1));

        Confirmar.setFont(new java.awt.Font("Arial", 1, 24)); // NOI18N
        Confirmar.setForeground(new java.awt.Color(255, 255, 255));
        Confirmar.setText("Confirmar contraseña:");
        getContentPane().add(Confirmar, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 410, -1, -1));
        getContentPane().add(txtUsuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 50, 370, 30));

        txtNombre.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txtNombreActionPerformed(evt);
            }
        });
        getContentPane().add(txtNombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 100, 370, 30));
        getContentPane().add(txtEdad, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 150, 370, 30));
        getContentPane().add(txtDomicilio, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 200, 370, 30));
        getContentPane().add(txtEmail, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 250, 370, 30));
        getContentPane().add(txtTelefono, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 300, 370, 30));
        getContentPane().add(txtContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 350, 370, 30));
        getContentPane().add(txtConfirmar, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 410, 370, 30));

        Guardar.setBackground(new java.awt.Color(153, 153, 255));
        Guardar.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        Guardar.setText("Guardar");
        Guardar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                GuardarActionPerformed(evt);
            }
        });
        getContentPane().add(Guardar, new org.netbeans.lib.awtextra.AbsoluteConstraints(680, 470, 100, -1));
        getContentPane().add(Icono, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        Wallpaper.setForeground(new java.awt.Color(255, 102, 102));
        Wallpaper.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/descarga.jpg"))); // NOI18N
        getContentPane().add(Wallpaper, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, -3, -1, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void txtNombreActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txtNombreActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_txtNombreActionPerformed

    private void GuardarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_GuardarActionPerformed
        SqlUsuarios modSQL = new SqlUsuarios();
        usuarios mod = new usuarios();

        String pass = new String(txtContraseña.getPassword());
        String passcon = new String(txtConfirmar.getPassword());
        if (txtUsuario.getText().equals("") || txtNombre.getText().equals("") || txtEdad.getText().equals("") || txtDomicilio.getText().equals("") || txtEmail.getText().equals("") || txtTelefono.getText().equals("")) {
            JOptionPane.showMessageDialog(null, "Hay campos vacios, debe llenar todos los campos");
        }else{
            if (pass.equals(passcon)) {
                if (modSQL.existeUsuario(txtUsuario.getText()) == 0) {
                    if (modSQL.esNumero(txtEdad.getText())) {
                        if (modSQL.esNumero(txtTelefono.getText())) {
                            if (modSQL.esEmail(txtEmail.getText())) {
                                String nuevoPass = hash.sha1(pass);
                                int edad = Integer.parseInt(txtEdad.getText());
                                mod.setUsuario(txtUsuario.getText());
                                mod.setNombre(txtNombre.getText());
                                mod.setEdad(edad);
                                mod.setDomicilio(txtDomicilio.getText());
                                mod.setCorreo_electronico(txtEmail.getText());
                                mod.setTelefono(txtTelefono.getText());
                                mod.setPassword(nuevoPass);
                                mod.setId_tipo(3);
                                if (modSQL.registrar(mod)) {
                                    JOptionPane.showMessageDialog(null, "Registro Guardado");
                                    limpiar();
                                } else {
                                    JOptionPane.showMessageDialog(null, "Error al guardar ");
                                }
                            } else {
                                JOptionPane.showMessageDialog(null, "El correo electronico no es valido ");
                            }
                        } else {
                            JOptionPane.showMessageDialog(null, "El campo telefono debe contener numeros");
                        }
                    } else {
                        JOptionPane.showMessageDialog(null, "El campo edad debe contener numeros");
                    }
                } else {
                    JOptionPane.showMessageDialog(null, "El usuario ya existe");
                }        
            } else {
                JOptionPane.showMessageDialog(null, "Las contraseñas no coinciden");
            }
        }
    }//GEN-LAST:event_GuardarActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        frmReg = null;
    }//GEN-LAST:event_formWindowClosing

    private void limpiar() {
        txtUsuario.setText("");
        txtNombre.setText("");
        txtEdad.setText("");
        txtDomicilio.setText("");
        txtEmail.setText("");
        txtTelefono.setText("");
        txtContraseña.setText("");
        txtConfirmar.setText("");
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
            java.util.logging.Logger.getLogger(registro.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(registro.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(registro.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(registro.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new registro().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Confirmar;
    private javax.swing.JLabel Contraseña;
    private javax.swing.JLabel Correo;
    private javax.swing.JLabel Domicilio;
    private javax.swing.JLabel Edad;
    private javax.swing.JButton Guardar;
    private javax.swing.JLabel Icono;
    private javax.swing.JLabel Nombre;
    private javax.swing.JLabel Telefono;
    private javax.swing.JLabel Usuario;
    private javax.swing.JLabel Wallpaper;
    private javax.swing.JPasswordField txtConfirmar;
    private javax.swing.JPasswordField txtContraseña;
    private javax.swing.JTextField txtDomicilio;
    private javax.swing.JTextField txtEdad;
    private javax.swing.JTextField txtEmail;
    private javax.swing.JTextField txtNombre;
    private javax.swing.JTextField txtTelefono;
    private javax.swing.JTextField txtUsuario;
    // End of variables declaration//GEN-END:variables
}