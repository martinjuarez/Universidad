//import com.sun.javaws.util.JfxHelper;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class mapaCobertura extends JFrame {
    private JPanel panelMapa;
    private JButton regresarButton;
    private JLabel mapa;
    private JLabel agenda;
    Frame frame;

    public mapaCobertura(String colonia) {
        frame = this;
        this.setContentPane(this.panelMapa);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.pack();
        ImageIcon image = new ImageIcon(
                getClass().getResource(
                        "/img/"+colonia+".png" ));
        mapa.setIcon(image);
        regresarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                seleccionZona zona = new seleccionZona();
                zona.setVisible(true);
                frame.setVisible(false);
            }
        });
    }
}