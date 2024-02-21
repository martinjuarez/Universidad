
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

public class Menu extends JFrame implements ActionListener {

    JTextField txtName;
    JButton btnMostrar;

public Menu() {
        this.setBounds(0, 0, 400, 500);
        this.setLayout(null);
        txtName = new JTextField();
        txtName.setName("txtName");
        txtName.setBounds(10, 20, 190, 20);
        txtName.setVisible(true);
        txtName.setText("");
        add(txtName);

        btnMostrar = new JButton();
        btnMostrar.setText("Mostrar");
        btnMostrar.setVisible(true);
        btnMostrar.setBounds(200, 20, 90, 20);
        btnMostrar.setName("btnMostrar");
        btnMostrar.addActionListener(this);
        add(btnMostrar);
        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnMostrar) {
            txtName.setText("Hola: " + txtName.getText());
        }
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public static void main(String[] args) {
        Menu a = new Menu();
        a.setVisible(true);
    }
}
