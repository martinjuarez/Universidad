#ifndef RECETA_H
#define RECETA_H

class ingrediente{
    punlic:
        int cantidad; /* Hice una clase ingredinte ya que ingredinete contiene tanto la cantidad como el nombre */
        string nombre;
        void agregar_ingrediente(){
        }/*Con este metodo se registrara un nuevo ingredinete*/
        void modificar_cantidad_ingrediente(){
        }/*Con este metodo se modificara la cantidad de un ingrdiente*/
        void eliminar_ingrediente(){
        }/*Con este metodo se eliminara un ingrediente de una receta*/
        void elimiar_todos_ingredinetes(){
        }/*Con este metodo se eliminan todos los ingrdientes de una receta*/
};
class receta{ /*Hice una clase receta que contendra los atributos de una receta*/
    public:
        string nombre; /*Un string para darle un nombre a la receta*/
        float tiempo_prep; /*Un flotante para ingresar el tiempo de la preparacion*/
        string proced; /*Un string para guardar el procedimiento de la receta*/
        string clasificacion; /*Un string que me diga la clasificaion de la receta si es de verano a invierno o si es desayuno o cena*/
        ingrediente ing[10]; /*Un arreglo de la clase ingrediente para utilizarlo en la clase receta*/
        void capturar_receta(){ /*Un metodo que capture los datos de una receta*/
        }
        void mostrar_receta(){/*Un metodo que muestre el contenido de una receta*/
        }
        void modificar procedimiento(){
        }/*Un metodo que modifique el procedimento de una receta*/
};
class recetario{ /*La clase recetario que contendra a las recetas*/
    public:
        receta rec[50]; /*Un arreglo de la clace receta*/
        void agregar_receta(){/*Un metodo que con ayuda del metodo capturar de la clase receta agreguen una receta en el recetario*/
        }
        void ordenar_recetas(){ /*Un metodo que ordene las recetas por su nombre o tiempo de preparacion*/
        }
        void mostrar_todas_recetas(){ /*Un metodo que con ayuda del metodo mostrar de la clase recta muestre todas las recetas */
        }
        void bucar_receta(string nombre){/*Un metodo que busque una receta por su nombre*/
        }
        void eliminar_receta(string nombre){/*Un metodo que elimine por su nombre a una receta*/
        }
        void eliminar_todas_recetas(){ /*Un metodo que elimine a todas la recetas del recetario*/
        }
        void menu(){/*El metodo menu que me ayudara a que el usuario eliga la opciones disponibles que desea*/
        }
};
