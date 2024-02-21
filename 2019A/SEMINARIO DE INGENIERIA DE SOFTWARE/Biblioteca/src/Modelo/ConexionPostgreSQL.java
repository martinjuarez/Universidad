package Modelo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


public class ConexionPostgreSQL {
    private Connection conexion = null;
    
    public Connection getConexion(){
        try {
            Class.forName("org.postgresql.Driver"); //Driver de base de datos para JAVA y PostgreSQL
            conexion = DriverManager.getConnection("jdbc:postgresql://localhost:5432/biblioteca","postgres", "212575181");
        } catch (ClassNotFoundException | SQLException ex) {
            System.out.println("Ocurrio un error: " + ex.getMessage());
        }
        System.out.println("La conexión se realizo con exito!");
        return conexion;
    }
}
