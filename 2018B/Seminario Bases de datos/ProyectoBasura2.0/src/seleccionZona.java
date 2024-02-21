import entidades.Colonia;
import entidades.Municipio;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class seleccionZona extends JFrame {

    private JPanel PanelPrincipal;
    private JTextField txtColonia;
    private JButton enviarButton;
    private JLabel organica;
    private JLabel inorganica;
    private JLabel reciclable;
    private JTextField txtOrganica;
    private JTextField txtInorganica;
    private JTextField txtReciclable;
    private JComboBox comboBoxMunicipio;
    private JComboBox comboBoxColonia;
    private List<Municipio> municipios;
    private List<Colonia> colonias;
    static JFrame frame;

    //Global
    Connection conexion = null;

    //Script de Conexión a la base de datos
    public void ConexionSQL() {

        try {
            Class.forName("org.postgresql.Driver"); //Driver de base de datos para JAVA y PostgreSQL
            conexion = DriverManager.getConnection("jdbc:postgresql://localhost:5432/reciclaje",
                    "postgres", "212575181");
        } catch (Exception ex) {
            System.out.println("Ocurrio un error: " + ex.getMessage());
        }
        System.out.println("La conexión se realizo con exito!");
    }

    public void obtenerMunicipio(){
        //inicializa lista de municipios
        municipios = new ArrayList<>();
        //Consulta base de datos
        String query = "SELECT id, nombre FROM municipio";
        PreparedStatement preparedStatement;
        try {
            preparedStatement = conexion.prepareStatement(query);
            ResultSet rs = preparedStatement.executeQuery();
            while (rs.next()) {
                //Agregar a lista nuevo municipio
                municipios.add(new Municipio(rs.getInt("id"),rs.getString("nombre")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        for (Municipio municipio: municipios){
            comboBoxMunicipio.addItem(municipio.getNombre());
        }
    }

    public void obtenerColonia(int index){
        int municipio_id = municipios.get(index).getId();

        colonias = new ArrayList<>();
        String query = "SELECT id, nombre, municipio_id FROM colonia WHERE municipio_id = ?";

        PreparedStatement preparedStatement;
        try {
            preparedStatement = conexion.prepareStatement(query);
            preparedStatement.setInt(1,municipio_id);
            ResultSet rs = preparedStatement.executeQuery();
            while (rs.next()) {
                colonias.add(new Colonia(rs.getInt("id"),rs.getString("nombre"), rs.getInt("municipio_id")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        comboBoxColonia.removeAllItems();
        for (Colonia colonia: colonias){
            comboBoxColonia.addItem(colonia.getNombre());
        }
    }

    public seleccionZona() {
        this.setContentPane(this.PanelPrincipal);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.pack();
        ConexionSQL();
        obtenerMunicipio();
        obtenerColonia(0);

        enviarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                int index = comboBoxColonia.getSelectedIndex();
                int colonia_id = colonias.get(index).getId();
                int organica = Integer.parseInt(txtOrganica.getText());
                int inorganica = Integer.parseInt(txtInorganica.getText());
                int reciclable = Integer.parseInt(txtReciclable.getText());

                try {
                    PreparedStatement ps = conexion.prepareStatement
                            ("INSERT INTO cantidad_basura(canorganica , caninorganica , canreciclable, id_colonia) VALUES (? , ?, ?, ?)");
                    ps.setInt(1, organica);
                    ps.setInt(2, inorganica);
                    ps.setInt(3, reciclable);
                    ps.setInt(4, colonia_id);
                    ps.execute();
                    ps.close();
                    String colonia = colonias.get(index).getNombre();
                    mapaCobertura mapa = new mapaCobertura(colonia);

                    mapa.setVisible(true);
                    frame.setVisible(false);
                } catch (SQLException e1) {
                    e1.printStackTrace();
                }
            }

        });
        comboBoxMunicipio.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int index = comboBoxMunicipio.getSelectedIndex();
                obtenerColonia(index);
            }
        });
    }
    public static void main(String[] arg) {
        frame = new JFrame("Recicle life");
        frame.setContentPane(new seleccionZona().PanelPrincipal);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
    }