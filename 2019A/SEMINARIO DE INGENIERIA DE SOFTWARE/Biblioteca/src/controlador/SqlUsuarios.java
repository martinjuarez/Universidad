package controlador;

import Ventanas.registro;
import Modelo.ConexionPostgreSQL;
import Modelo.usuarios;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.swing.JOptionPane;

public class SqlUsuarios extends ConexionPostgreSQL {

    public boolean registrar(usuarios usr) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();
        String sql = "INSERT INTO usuario (usuario, nombre, edad, domicilio, correo_electronico, telefono, password, id_tipo) values (?,?,?,?,?,?,?,?)";
        try {
            ps = conexion.prepareStatement(sql);
            ps.setString(1, usr.getUsuario());
            ps.setString(2, usr.getNombre());
            ps.setInt(3, usr.getEdad());
            ps.setString(4, usr.getDomicilio());
            ps.setString(5, usr.getCorreo_electronico());
            ps.setString(6, usr.getTelefono());
            ps.setString(7, usr.getPassword());
            ps.setInt(8, usr.getId_tipo());
            ps.execute();
            return true;
        } catch (SQLException ex) {
            Logger.getLogger(registro.class.getName()).log(Level.SEVERE, null, ex);
        }
        return false;
    }

    public int existeUsuario(String usuario) {

        PreparedStatement ps = null;
        ResultSet rs = null;
        Connection conexion = getConexion();
        String sql = "SELECT count(id_usuario) FROM usuario WHERE usuario = ?";
        try {
            ps = conexion.prepareStatement(sql);
            ps.setString(1, usuario);
            rs = ps.executeQuery();

            if (rs.next()) {
                return rs.getInt(1);
            }
            return 1;
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null, e.toString());
            return 1;
        }
    }

    public boolean login(usuarios usr) {

        PreparedStatement ps = null;
        ResultSet rs = null;
        Connection conexion = getConexion();
        String sql = "SELECT u.id_usuario, u.usuario, u.nombre, u.password, u.id_tipo, t.usuario FROM usuario AS u INNER JOIN tipo_usuarios AS t ON u.id_tipo = t.id_role WHERE u.usuario = ?";
        try {
            ps = conexion.prepareStatement(sql);
            ps.setString(1, usr.getUsuario());
            rs = ps.executeQuery();
            if (rs.next()) {
                if (usr.getPassword().equals(rs.getString(4))) {
                    String sqlUPDATE = "UPDATE usuario SET last_session = now()  WHERE id_usuario = ?";
                    ps = conexion.prepareStatement(sqlUPDATE);
                    ps.setInt(1, rs.getInt(1));
                    ps.execute();
                    usr.setId_usuario(rs.getInt(1));
                    usr.setNombre(rs.getString(3));
                    usr.setId_tipo(rs.getInt(5));
                    usr.setUsuario_tipo(rs.getString(6));
                    return true;
                } else {
                    return false;
                }
            }
            return false;
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(null, e.toString());
            return false;
        } finally {
            try {
                conexion.close();
            } catch (SQLException e) {
                JOptionPane.showMessageDialog(null, e.toString());
            }
        }
    }

    public boolean esEmail(String correo) {

        // Patrón para validar el email
        Pattern pattern = Pattern.compile("^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@" + "[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$");

        Matcher mather = pattern.matcher(correo);

        return mather.find();
    }

    public boolean esNumero(String numero) {

        // Patrón para validar el email
        Pattern pattern = Pattern.compile("^[0-9]{1,14}$");

        Matcher mather = pattern.matcher(numero);

        return mather.find();
    }
}
