package controlador;

import Modelo.ConexionPostgreSQL;
import Modelo.Ejemplares;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class SqlEjemplares extends ConexionPostgreSQL {

    public boolean registrar(Ejemplares ejem) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();

        String sql = "INSERT INTO ejemplar (disponibilidad, fecha_disponibilidad, id_usuario, isbn) VALUES (?, ?, ?, ?)";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setString(1, ejem.getDisponibilidad());
            ps.setString(2, ejem.getFecha_disponibildad());
            ps.setInt(3, ejem.getId_usuario());
            ps.setInt(4, ejem.getIsbn());
            ps.execute();
            return true;
        } catch (SQLException e) {
            System.err.println(e);
            return false;
        } finally {
            try {
                conexion.close();
            } catch (SQLException e) {
                System.err.println(e);
            }
        }
    }

    public boolean modificar(Ejemplares ejem) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();

        String sql = "UPDATE ejemplar SET disponibilidad = ?, fecha_disponibilidad = ?, id_usuario = ?, isbn = ? WHERE num_ejem = ?";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setString(1, ejem.getDisponibilidad());
            ps.setString(2, ejem.getFecha_disponibildad());
            ps.setInt(3, ejem.getId_usuario());
            ps.setInt(4, ejem.getIsbn());
            ps.setInt(5, ejem.getNum_ejem());
            ps.execute();
            return true;
        } catch (SQLException e) {
            System.err.println(e);
            return false;
        } finally {
            try {
                conexion.close();
            } catch (SQLException e) {
                System.err.println(e);
            }
        }
    }

    public boolean eliminar(Ejemplares ejem) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();

        String sql = "DELETE FROM ejemplar WHERE num_ejem = ?";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setInt(1, ejem.getNum_ejem());
            ps.execute();
            return true;
        } catch (SQLException e) {
            System.err.println(e);
            return false;
        } finally {
            try {
                conexion.close();
            } catch (SQLException e) {
                System.err.println(e);
            }
        }
    }

    public boolean buscar(Ejemplares ejem) {

        PreparedStatement ps = null;
        ResultSet rs = null;
        Connection conexion = getConexion();

        String sql = "SELECT * FROM ejemplar WHERE num_ejem = ?";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setInt(1, ejem.getNum_ejem());
            rs = ps.executeQuery();

            if (rs.next()) {
                ejem.setNum_ejem(Integer.parseInt(rs.getString("num_ejem")));
                ejem.setDisponibilidad(rs.getString("disponibilidad"));
                ejem.setFecha_disponibildad(rs.getString("fecha_disponibilidad"));
                ejem.setId_usuario(Integer.parseInt(rs.getString("id_usuario")));
                ejem.setIsbn(Integer.parseInt(rs.getString("isbn")));
                return true;
            }
            return false;
        } catch (SQLException e) {
            System.err.println(e);
            return false;
        } finally {
            try {
                conexion.close();
            } catch (SQLException e) {
                System.err.println(e);
            }
        }
    }

}
