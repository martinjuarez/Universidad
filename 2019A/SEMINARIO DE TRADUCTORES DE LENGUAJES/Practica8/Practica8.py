"""
<nombre> = open(<ruta del archivo>, <modo>)
Por el tipo de acceso.
'r' es el modo de lectura.
'w' es un modo de escritura. En caso de existir un archivo, éste es sobreescrito.
'a' es un modo de escritura. En caso de existir un archivo, comienza a escribir al final de éste.
'x' es un modo de escritura para crear un nuevo archivo. En caso de que el archivo exista se emitirá un error de tipo FileExistsError.
'+' es un modo de escritura/lectura.

read().
Si el archivo se encuentra en modo de lectura, leerá y regresará el contenido del archivo desde la posición en la que se encuentre hasta el final del archivo. Si se ingresa un número como argumento, leerá el número de posiciones indicadas en el argumento.

write().
Si el archivo se encuentra en modo de escritura, añadirá al archivo el contenido ingresado como argumento a partir de la posición en donde se encuentre, sobreescribiendo el texto ta existente. Una vez terminada la operación, regresará la nueva posición del puntero.

tell().
Regresará la posición en la que se encuentra el puntero dentro del archivo.

seek().
Moverá el puntero a la posición indicad
"""

# Crear y escribir en un archivo
f = open ('holamundo.txt','w')
f.write('hola chavales')
f.close()

# Leer en un archivo
g = open ('arch2.asm','r')
mensaje = g.read()
print(mensaje)
g.close()

# Añadir texto al final en un archivo
h = open('holamundo.txt','a')
h.write('\n' + 'Hola Mundo')
h.close()