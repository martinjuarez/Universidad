$entero=14; # Número entero
$real=0.1234; # Número real
$cadena="Ejemplo de Script\n"; # Cadena de caracteres
print $cadena; 

@notas=(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10); #array de enteros
@alumnos=("Segismundo", "Eustaquio", "Anastasia", "Bartolome"); # Array de cadenas de caracteres 
@array=("Mensaje", 14, 3.56, "Fin"); # Array de elementos distintos
print $alumnos[0], "\n"; # Los arrays se indexan empezando por 0, como en C 
#Como se imprime un solo elemento, se pone $ en vez de @

# Array asociativo. El primer elemento indexa al segundo, el tercero al cuarto ...
# Segismundo es el índice que corresponde a la nota 3, Anastasia al 8, etc
%finales=("Segismundo", 3, "Eustaquio", 7, "Anastasia", 8, "Bartolome", 4); 
# ¿Qué imprime esta línea?
print $finales{"Anastasia"}; 
# Y si tenemos una variable:
$nombre=("Anastasia");
print $finales{$nombre}; 
