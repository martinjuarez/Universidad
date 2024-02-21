/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author marti
 */
public class Proceso {

    String Lote, operacion, numPrograma;
    int tiempoMax, pendientes;
    int res;
    boolean listo = false, medio = false;
    Proceso siguiente;
}
