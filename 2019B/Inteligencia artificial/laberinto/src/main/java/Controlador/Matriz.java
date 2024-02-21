package Controlador;

import java.io.File;

public class Matriz {
    //Creo la clase matriz para poder usar sus variables como parametros de otras funciones
    //por lo general una funcion solo puede pasar un parametro pero al crear un objeto puedo pasar todas sus variables
    private int columnas;
    private int filas;
    private int[][] Matriz;
    private File ruta;
    private int[] Colores;
    private int ids;
    private String terreno;
    
    //Sus respectivos metodos para obtener y enviar informacion a sus variables
    public int getColumnas() {
        return columnas;
    }

    public void setColumnas(int columnas) {
        this.columnas = columnas;
    }

    public int getFilas() {
        return filas;
    }

    public void setFilas(int filas) {
        this.filas = filas;
    }

    public int[][] getMatriz() {
        return Matriz;
    }

    public void setMatriz(int[][] Matriz) {
        this.Matriz = Matriz;
    }

    public File getRuta() {
        return ruta;
    }

    public void setRuta(File ruta) {
        this.ruta = ruta;
    }
    
    public int[] getColores() {
        return Colores;
    }

    public void setColores(int[] Colores) {
        this.Colores = Colores;
    }
    
    public int getIds() {
        return ids;
    }

    public void setIds(int ids) {
        this.ids = ids;
    }
    
    public String getTerreno() {
        return terreno;
    }

    public void setTerreno(String terreno) {
        this.terreno = terreno;
    }
}