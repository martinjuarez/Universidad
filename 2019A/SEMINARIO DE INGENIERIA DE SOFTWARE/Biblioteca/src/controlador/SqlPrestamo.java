package controlador;

import Modelo.ConexionPostgreSQL;
import Modelo.prestamos;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class SqlPrestamo extends ConexionPostgreSQL{
    
    public boolean registrar(prestamos pre) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();
        String sql = "INSERT INTO reserva_libro (num_ejem, id_usuario) values (?,?)";
        try {
            ps = conexion.prepareStatement(sql);
            ps.setInt(1, pre.getNum_ejem());
            ps.setInt(2, pre.getId_usuario());
            ps.execute();
            return true;
        } catch (SQLException e){
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
    
    public boolean modificar(prestamos pre) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();
        String sql = "UPDATE reserva_libro SET id_usuario = ? WHERE num_ejem = ?)";
        try {
            ps = conexion.prepareStatement(sql);
            ps.setInt(1, pre.getId_usuario());
            ps.setInt(2, pre.getNum_ejem());
            ps.execute();
            return true;
        } catch (SQLException e){
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
    
    public boolean eliminar(prestamos pre) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();
        String sql = "DELETE FROM reserva_libro WHERE num_ejem = ?)";
        try {
            ps = conexion.prepareStatement(sql);
            ps.setInt(1, pre.getNum_ejem());
            ps.execute();
            return true;
        } catch (SQLException e){
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
    
    public boolean buscar(prestamos pre) {

        PreparedStatement ps = null;
        ResultSet rs = null;
        Connection conexion = getConexion();
        
        String sql = "SELECT * FROM reserva_libro WHERE num_ejem = ?)";
        
        try {
            ps = conexion.prepareStatement(sql);
            ps.setInt(1, pre.getNum_ejem());
            rs = ps.executeQuery();
            if (rs.next()) {
                pre.setNum_ejem(Integer.parseInt(rs.getString("num_ejem")));
                pre.setId_usuario(Integer.parseInt(rs.getString("id_usuario")));
                return true;
            }
            return false;
        } catch (SQLException e){
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
