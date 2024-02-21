package com.sistemas;

import java.sql.Connection;
import java.sql.Statement;
import java.sql.*;
import javax.swing.JOptionPane;

public class Conexion {

    Connection conn;

    public Connection Conexion() {
        try {
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost/storage?useSSL=false&serverTimezone=UTC", "root", "");
            //con.createStatement();
            this.conn = con;
        } catch (Exception e) {
            //e.printStackTrace();
            JOptionPane.showMessageDialog(null, "Error en la conexion");
        }
        return this.conn;
    }
}
