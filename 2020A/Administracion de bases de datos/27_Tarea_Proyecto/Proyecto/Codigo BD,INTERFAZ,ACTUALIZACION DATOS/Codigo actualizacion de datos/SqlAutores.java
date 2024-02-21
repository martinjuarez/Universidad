
package controlador;

import Modelo.ConexionPostgreSQL;
import Modelo.autores;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class SqlAutores extends ConexionPostgreSQL{
    public boolean registrar(autores au) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();

        String sql = "INSERT INTO autor (nombre, nacionalidad) VALUES (?, ?)";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setString(1, au.getNombre());
            ps.setString(2, au.getNacionalidad());
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
    
    public boolean modificar(autores au) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();

        String sql = "UPDATE autor SET nombre = ?, nacionalidad = ? WHERE id_autor = ?";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setString(1, au.getNombre());
            ps.setString(2, au.getNacionalidad());
            ps.setInt(3,au.getId_autor());
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
    
    public boolean eliminar(autores au) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();

        String sql = "DELETE FROM autor WHERE id_autor = ?";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setInt(1,au.getId_autor());
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
    
    public boolean buscar(autores au) {

        PreparedStatement ps = null;
        ResultSet rs = null;
        Connection conexion = getConexion();

        String sql = "SELECT * FROM autor WHERE nombre = ?";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setString(1, au.getNombre());
            rs = ps.executeQuery ();
            
            if (rs.next()) {
                au.setId_autor(Integer.parseInt(rs.getString("id_autor")));
                au.setNombre(rs.getString("nombre"));
                au.setNacionalidad(rs.getString("nacionalidad"));
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
