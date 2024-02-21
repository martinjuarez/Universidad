package com.sistemas;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DBase {

    ResultSet rs;

    public void Maxid(Connection conn, Clientes ct) throws SQLException {
        PreparedStatement stmt1 = conn.prepareStatement("SELECT MAX(id) AS id FROM clientes");
        rs = stmt1.executeQuery();
        if (rs.next()) {
            ct.setId(rs.getInt(1) + 1);
        }
    }

    public void insert(Connection conn, Clientes ct) throws SQLException {
        PreparedStatement stmt1 = conn.prepareStatement("INSERT INTO clientes(id,nombre,direccion,telefono)VALUES(?,?,?,?)");
        stmt1.setInt(1, ct.getId());
        stmt1.setString(2, ct.getNombre());
        stmt1.setString(3, ct.getDireccion());
        stmt1.setString(4, ct.getTelefono());
        stmt1.executeUpdate();
    }

    public void Select(Connection conn, Clientes ct, int id) throws SQLException {
        PreparedStatement stmt1 = conn.prepareStatement("SELECT * FROM clientes WHERE id='" + id + "'");
        rs = stmt1.executeQuery();
        if (rs.next()) {
            ct.setId(rs.getInt(1));
            ct.setNombre(rs.getString(2));
            ct.setDireccion(rs.getString(3));
            ct.setTelefono(rs.getString(4));
        }
    }

    public void Update(Connection conn, Clientes ct, int id) throws SQLException {
        PreparedStatement stmt1 = conn.prepareStatement("UPDATE clientes SET nombre = ?, direccion = ?, telefono = ? WHERE id='" + id + "'");
        stmt1.setString(1, ct.getNombre());
        stmt1.setString(2, ct.getDireccion());
        stmt1.setString(3, ct.getTelefono());
        stmt1.executeUpdate();        
    }

    public void Delete(Connection conn, int id) throws SQLException {
        PreparedStatement stmt1 = conn.prepareStatement("DELETE FROM clientes WHERE id='" + id + "'");
        stmt1.executeUpdate();
    }
}
