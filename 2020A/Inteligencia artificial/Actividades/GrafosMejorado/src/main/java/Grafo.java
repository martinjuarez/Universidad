
import java.util.Scanner;

public class Grafo {

    Nodo nodoP, nodoT, nodoAnt;
    Arista aristaP, aristaT, aristaAnt;
    boolean band, band2;
    char tmp, tmp2;
    Scanner scan = new Scanner(System.in);

    void insertar_nodo() {
        Nodo nuevo = new Nodo();
        System.out.println("Ingrese una variable o nombre para el vertice: ");
        nuevo.nombre = scan.nextLine().charAt(0);
        nuevo.siguiente = null;
        nuevo.adyacencia = null;
        if (nodoP == null) {
            nodoP = nuevo;
            System.out.println("Primer Vertice ingresado");
        } else {
            nodoT = nodoP;
            while (nodoT.siguiente != null) {
                nodoT = nodoT.siguiente;
            }
            nodoT.siguiente = nuevo;
            System.out.println("Vertice ingresado");
        }
    }

    void agregar_arista(Nodo aux1, Nodo aux2, Arista nuevo) {
        Arista Q;
        if (aux1.adyacencia == null) {
            aux1.adyacencia = nuevo;
            nuevo.destino = aux2;
            System.out.println("Primer arista agregada");
        } else {
            Q = aux1.adyacencia;
            while (Q.siguiente != null) {
                Q = Q.siguiente;
            }
            nuevo.destino = aux2;
            Q.siguiente = nuevo;
            System.out.println("Arista agregada");
        }
    }

    void insertar_arista() {
        Arista nuevo = new Arista();
        Nodo aux1, aux2;
        band = true;
        band2 = true;
        if (nodoP == null) {
            System.out.println("Error no hay vertices");
        } else {
            nuevo.siguiente = null;
            System.out.println("Ingrese Vertice de inicio: ");
            tmp = scan.nextLine().charAt(0);
            System.out.println("Ingrese Vertice final: ");
            tmp2 = scan.nextLine().charAt(0);
            aux1 = nodoP;
            aux2 = nodoP;
            while (aux1 != null && band == true) {
                if (aux1.nombre == tmp) {
                    band = false;
                    break;
                }
                aux1 = aux1.siguiente;
            }
            while (aux2 != null && band2 == true) {
                if (aux2.nombre == tmp2) {
                    band2 = false;
                    break;
                }
                aux2 = aux2.siguiente;
            }
            if (band == true) {
                System.out.println("Vertice inicio no encontrado");
            } else if (band2 == true) {
                System.out.println("Vertice final no encontrado");
            } else {
                agregar_arista(aux1, aux2, nuevo);
            }
        }
    }

    void eliminar_nodo() {
        band = true;
        if (nodoP == null) {
            System.out.println("Error no hay vertices");
        } else {
            System.out.println("Ingrese el nombre o variable: ");
            tmp = scan.nextLine().charAt(0);
            nodoT = nodoP;
            while (nodoT != null && band == true) {
                if (nodoT.nombre == tmp) {
                    band = false;
                } else {
                    nodoAnt = nodoT;
                    nodoT = nodoT.siguiente;
                }
            }
            if (nodoT == nodoP) {
                nodoP = nodoT.siguiente;
                eliminar_aristasNodo(nodoT);
                nodoT = null;
                System.out.println("Vertice eliminado");
            } else if (nodoT == null) {
                System.out.println("Vertice no encontrado");
            } else {
                nodoAnt.siguiente = nodoT.siguiente;
                eliminar_aristasNodo(nodoT);
                nodoT = null;
                System.out.println("Vertice eliminado");
            }
        }
    }

    void eliminar_arista() {
        band = true;
        band2 = true;
        if (nodoP == null) {
            System.out.println("Error no hay vertices");
        } else {
            System.out.println("Ingrese el vertice inicio: ");
            tmp = scan.nextLine().charAt(0);
            System.out.println("Ingresar el vertice final: ");
            tmp2 = scan.nextLine().charAt(0);
            nodoT = nodoP;
            while (nodoT != null && band == true) {
                if (nodoT.nombre == tmp) {
                    band = false;
                } else {
                    nodoT = nodoT.siguiente;
                }
            }
            nodoT = nodoP;
            while (nodoT != null && band2 == true) {
                if (nodoT.nombre == tmp2) {
                    band2 = false;
                } else {
                    nodoT = nodoT.siguiente;
                }
            }
            if (band == true) {
                System.out.println("El vertice inicio no existe");
            } else if (band2 == true) {
                System.out.println("El vertice final no existe");
            } else {
                aristaP = nodoT.adyacencia;
                aristaT = nodoT.adyacencia;
                band = true;
                while (aristaT != null && band == true) {
                    if (aristaT.destino.nombre == tmp2) {
                        band = false;
                    } else {
                        aristaAnt = aristaT;
                        aristaT = aristaT.siguiente;
                    }
                }
                if (aristaT == aristaP) {
                    nodoT.adyacencia = aristaT.siguiente;
                    aristaT = null;
                    System.out.println("Arista eliminada");
                } else {
                    aristaAnt.siguiente = aristaT.siguiente;
                    aristaT = null;
                    System.out.println("Arista eliminada");
                }
            }
        }
    }

    void mostrar_grafo() {
        nodoT = nodoP;
        if (nodoT == null) {
            System.out.println("Error no hay vertices");
        } else {
            System.out.println("Nodos: ");
            System.out.print('\n');
            while (nodoT != null) {
                System.out.print("Vertice: " + "|" + nodoT.nombre + "|");
                aristaT = nodoT.adyacencia;
                while (aristaT != null) {
                    System.out.print("--->" + aristaT.destino.nombre);
                    aristaT = aristaT.siguiente;
                }
                System.out.print("/");
                System.out.println('\n');
                nodoT = nodoT.siguiente;
            }
        }
    }

    void mostrar_aristas() {
        band = true;
        char tmp;
        nodoT = nodoP;
        if (nodoT == null) {
            System.out.println("Error no hay vertices");
        } else {
            System.out.println("Ingrese el vertice inicio: ");
            tmp = scan.nextLine().charAt(0);
            while (nodoT != null && band == true) {
                if (nodoT.nombre == tmp) {
                    band = false;
                } else {
                    nodoT = nodoT.siguiente;
                }
            }
            if (nodoT == null) {
                System.out.println("Error vertice no encontrado");
            } else {
                aristaT = nodoT.adyacencia;
                System.out.print("Vertice: " + "|" + nodoT.nombre + "|");
                while (aristaT != null) {
                    System.out.print("--->" + aristaT.destino.nombre);
                    aristaT = aristaT.siguiente;
                }
                System.out.print("/");
                System.out.print('\n');
            }
        }
    }

    void eliminar_aristasNodo(Nodo N) {
        nodoT = nodoP;
        while (nodoT != null) {
            aristaP = nodoT.adyacencia;
            aristaT = nodoT.adyacencia;
            band = true;
            while (aristaT != null && band == true) {
                if (aristaT.destino.nombre == N.nombre) {
                    band = false;
                } else {
                    aristaAnt = aristaT;
                    aristaT = aristaT.siguiente;
                }
            }
            if (band == false) {
                if (aristaT == aristaP) {
                    nodoT.adyacencia = aristaT.siguiente;
                    aristaT = null;
                } else {
                    aristaAnt.siguiente = aristaT.siguiente;
                    aristaT = null;
                }
            }
            nodoT = nodoT.siguiente;
        }
    }

    boolean buscar_nodos(char tmp) {
        nodoT = nodoP;
        band = false;
        if (nodoT == null) {
            System.out.println("Error no hay vertices");
        } else {
            while (nodoT != null && band == false) {
                if (nodoT.nombre == tmp) {
                    band = true;
                } else {
                    nodoT = nodoT.siguiente;
                }
            }
        }
        return band;
    }

    void editar_nodo() {
        nodoT = nodoP;
        if (nodoT == null) {
            System.out.println("Error no hay vertices");
        } else {
            System.out.println("Nombre del vertice a editar");
            tmp = scan.nextLine().charAt(0);
            if (buscar_nodos(tmp) == false) {
                System.out.println("Error vertice no encontrado");
            } else {
                System.out.println("Nombre del nuevo vertice");
                tmp2 = scan.nextLine().charAt(0);
                while (nodoT != null) {
                    if (nodoT.nombre == tmp) {
                        nodoAnt = nodoT;
                    }
                    aristaT = nodoT.adyacencia;
                    while (aristaT != null) {
                        if (aristaT.destino.nombre == tmp) {
                            aristaT.destino.nombre = tmp2;
                        } else {
                            aristaT = aristaT.siguiente;
                        }
                    }
                    nodoT = nodoT.siguiente;
                }
                nodoAnt.nombre = tmp2;
            }
        }
    }

    void menu() {
        char opc;
        do {
            System.out.println("1.............Insertar nodo");
            System.out.println("2.............Insertar arista");
            System.out.println("3.............Elimnar Nodo");
            System.out.println("4.............Elimanar arista");
            System.out.println("5.............Mostrar grafo");
            System.out.println("6.............Mostrar arista de un grafo");
            System.out.println("7.............Buscar Nodo");
            System.out.println("8.............Editar Nodo");
            System.out.println("9.............Salir");
            System.out.println("Eliga una opcion: ");
            opc = scan.nextLine().charAt(0);
            switch (opc) {
                case '1':
                    insertar_nodo();
                    break;
                case '2':
                    insertar_arista();
                    break;
                case '3':
                    eliminar_nodo();
                    break;
                case '4':
                    eliminar_arista();
                    break;
                case '5':
                    mostrar_grafo();
                    break;
                case '6':
                    mostrar_aristas();
                    break;
                case '7':
                    System.out.println("Nombre del vertice a editar");
                    tmp = scan.nextLine().charAt(0);
                    System.out.print("Vertice = ");
                    System.out.print(buscar_nodos(tmp));
                    System.out.print('\n');
                    break;
                case '8':
                    editar_nodo();
                    break;
                default:
                    System.out.println("Opcion incorrecta");
                    break;
            }
        } while (opc != '9');
    }

    public static void main(String[] args) {
        Grafo a = new Grafo();
        a.menu();
    }
}
