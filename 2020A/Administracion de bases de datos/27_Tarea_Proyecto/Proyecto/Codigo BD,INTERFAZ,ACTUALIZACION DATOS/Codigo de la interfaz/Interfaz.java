package Ventanas;
import Modelo.usuarios;
import Modelo.hash;
import controlador.SqlUsuarios;
import javax.swing.JOptionPane;

public class Interfaz extends javax.swing.JFrame {
    public static registro frmReg;
    public Interfaz() {
        initComponents();
        this.setLocationRelativeTo(null);
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Iniciar = new javax.swing.JLabel();
        Usuario = new javax.swing.JLabel();
        Contraseña = new javax.swing.JLabel();
        txtUsuario = new javax.swing.JTextField();
        txtPassword = new javax.swing.JPasswordField();
        Cuenta = new javax.swing.JLabel();
        Enlace = new javax.swing.JLabel();
        Siguiente = new javax.swing.JButton();
        wall = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setAutoRequestFocus(false);
        setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        setPreferredSize(new java.awt.Dimension(930, 602));
        setSize(new java.awt.Dimension(0, 0));
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        Iniciar.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        Iniciar.setForeground(new java.awt.Color(153, 204, 255));
        Iniciar.setText("Iniciar Sesión");
        getContentPane().add(Iniciar, new org.netbeans.lib.awtextra.AbsoluteConstraints(561, 180, -1, -1));

        Usuario.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        Usuario.setForeground(new java.awt.Color(255, 255, 255));
        Usuario.setText("Usuario:");
        getContentPane().add(Usuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 240, -1, -1));

        Contraseña.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        Contraseña.setForeground(new java.awt.Color(255, 255, 255));
        Contraseña.setText("Password:");
        getContentPane().add(Contraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 300, -1, -1));

        txtUsuario.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        txtUsuario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txtUsuarioActionPerformed(evt);
            }
        });
        getContentPane().add(txtUsuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(390, 240, 380, 30));

        txtPassword.setFont(new java.awt.Font("Tahoma", 1, 14)); // NOI18N
        txtPassword.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txtPasswordActionPerformed(evt);
            }
        });
        txtPassword.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                Enter(evt);
            }
            public void keyTyped(java.awt.event.KeyEvent evt) {
                txtPasswordKeyTyped(evt);
            }
        });
        getContentPane().add(txtPassword, new org.netbeans.lib.awtextra.AbsoluteConstraints(390, 300, 380, 30));

        Cuenta.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        Cuenta.setForeground(new java.awt.Color(255, 255, 255));
        Cuenta.setText("¿No tiene una cuenta?");
        getContentPane().add(Cuenta, new org.netbeans.lib.awtextra.AbsoluteConstraints(250, 340, -1, 30));

        Enlace.setFont(new java.awt.Font("Tahoma", 3, 18)); // NOI18N
        Enlace.setForeground(new java.awt.Color(255, 102, 0));
        Enlace.setText("Cree uno aqui");
        Enlace.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                EnlaceMouseClicked(evt);
            }
        });
        getContentPane().add(Enlace, new org.netbeans.lib.awtextra.AbsoluteConstraints(470, 340, 140, 30));

        Siguiente.setBackground(new java.awt.Color(0, 255, 255));
        Siguiente.setFont(new java.awt.Font("Trebuchet MS", 0, 14)); // NOI18N
        Siguiente.setForeground(new java.awt.Color(51, 29, 222));
        Siguiente.setText("Siguiente");
        Siguiente.setBorderPainted(false);
        Siguiente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SiguienteActionPerformed(evt);
            }
        });
        getContentPane().add(Siguiente, new org.netbeans.lib.awtextra.AbsoluteConstraints(639, 344, -1, -1));

        wall.setIcon(new javax.swing.ImageIcon(getClass().getResource("/imagenes/descarga.jpg"))); // NOI18N
        getContentPane().add(wall, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void SiguienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SiguienteActionPerformed
        SqlUsuarios modSQL = new SqlUsuarios();
        usuarios mod = new usuarios();

        String pass = new String(txtPassword.getPassword());
        
        if(!txtUsuario.getText().equals("") && !pass.equals("")){
            String nuevoPass = hash.sha1(pass);
            
            mod.setUsuario(txtUsuario.getText());
            mod.setPassword(nuevoPass);
            
            if(modSQL.login(mod)){
                frmReg = null;
                this.dispose();
                
                Home frmHome = new Home(mod);
                
                frmHome.setVisible(true);
            }else{
                JOptionPane.showMessageDialog(null, "Datos incorrectos");
            }
        }else{
            JOptionPane.showMessageDialog(null, "Debe ingresar sus datos");
        }
    }//GEN-LAST:event_SiguienteActionPerformed

    private void txtUsuarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txtUsuarioActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_txtUsuarioActionPerformed

    private void txtPasswordActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txtPasswordActionPerformed

    }//GEN-LAST:event_txtPasswordActionPerformed

    private void EnlaceMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_EnlaceMouseClicked
        if(frmReg == null){
            frmReg = new registro();
            frmReg.setVisible(true);
        }
    }//GEN-LAST:event_EnlaceMouseClicked

    private void Enter(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_Enter
        // TODO add your handling code here:
    }//GEN-LAST:event_Enter

    private void txtPasswordKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txtPasswordKeyTyped
        // TODO add your handling code here:
    }//GEN-LAST:event_txtPasswordKeyTyped

    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
       
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Interfaz().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Contraseña;
    private javax.swing.JLabel Cuenta;
    private javax.swing.JLabel Enlace;
    private javax.swing.JLabel Iniciar;
    private javax.swing.JButton Siguiente;
    private javax.swing.JLabel Usuario;
    private javax.swing.JPasswordField txtPassword;
    private javax.swing.JTextField txtUsuario;
    private javax.swing.JLabel wall;
    // End of variables declaration//GEN-END:variables
}