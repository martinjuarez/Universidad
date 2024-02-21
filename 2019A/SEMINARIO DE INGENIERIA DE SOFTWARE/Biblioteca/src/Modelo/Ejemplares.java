package Modelo;

public class Ejemplares {
    private int num_ejem; 
    private String disponibilidad;
    private String fecha_disponibildad;
    private int id_usuario;
    private int isbn;

    public int getNum_ejem() {
        return num_ejem;
    }

    public void setNum_ejem(int num_ejem) {
        this.num_ejem = num_ejem;
    }

    public String getDisponibilidad() {
        return disponibilidad;
    }

    public void setDisponibilidad(String disponibilidad) {
        this.disponibilidad = disponibilidad;
    }

    public String getFecha_disponibildad() {
        return fecha_disponibildad;
    }

    public void setFecha_disponibildad(String fecha_disponibildad) {
        this.fecha_disponibildad = fecha_disponibildad;
    }

    public int getId_usuario() {
        return id_usuario;
    }

    public void setId_usuario(int id_usuario) {
        this.id_usuario = id_usuario;
    }

    public int getIsbn() {
        return isbn;
    }

    public void setIsbn(int isbn) {
        this.isbn = isbn;
    }
}
