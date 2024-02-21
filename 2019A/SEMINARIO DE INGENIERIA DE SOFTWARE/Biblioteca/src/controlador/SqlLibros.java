package controlador;

import Modelo.ConexionPostgreSQL;
import Modelo.libros;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class SqlLibros extends ConexionPostgreSQL {

    public boolean registrar(libros lib) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();

        String sql = "INSERT INTO libro (nombre, genero, editorial) VALUES (?, ?, ?)";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setString(1, lib.getNombre());
            ps.setString(2, lib.getGenero());
            ps.setString(3, lib.getEditorial());
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

    public boolean modificar(libros lib) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();

        String sql = "UPDATE libro SET nombre = ?, genero = ?, editorial = ? WHERE isbn = ?";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setString(1, lib.getNombre());
            ps.setString(2, lib.getGenero());
            ps.setString(3, lib.getEditorial());
            ps.setInt(4, lib.getIsbn());
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

    public boolean eliminar(libros lib) {

        PreparedStatement ps = null;
        Connection conexion = getConexion();

        String sql = "DELETE FROM libro WHERE isbn = ?";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setInt(1, lib.getIsbn());
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

    public boolean buscar(libros lib) {

        PreparedStatement ps = null;
        ResultSet rs = null;
        Connection conexion = getConexion();

        String sql = "SELECT * FROM libro WHERE nombre = ?";

        try {

            ps = conexion.prepareStatement(sql);
            ps.setString(1, lib.getNombre());
            rs = ps.executeQuery();

            if (rs.next()) {
                lib.setIsbn(Integer.parseInt(rs.getString("Isbn")));
                lib.setNombre(rs.getString("Nombre"));
                lib.setGenero(rs.getString("Genero"));
                lib.setEditorial(rs.getString("Editorial"));
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
