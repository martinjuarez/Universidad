package entidades;

public class Colonia {
    int id;
    String nombre;
    int municipio_id;

    public Colonia(int id, String nombre, int municipio_id) {
        this.id = id;
        this.nombre = nombre;
        this.municipio_id = municipio_id;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getMunicipio_id() {
        return municipio_id;
    }

    public void setMunicipio_id(int municipio_id) {
        this.municipio_id = municipio_id;
    }
}
