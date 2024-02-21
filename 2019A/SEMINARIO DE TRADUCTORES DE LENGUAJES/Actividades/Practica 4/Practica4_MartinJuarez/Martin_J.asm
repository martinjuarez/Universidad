name "Martin Juarez Practica 4"
org 100h
        
mov dh,b;mueve lo que hay en la variable b al registro de 8 bits dh 
mov dl,e;mueve lo que hay en la variable e al registro de 8 bits dl        

mov [170h],dh;movemos el numero 5 a la direccion de memoria 170h que sera la base
mov [175h],dl;movemos el numero 2 a la direccion de memoria 175h que sera el exponente
 
mov al, [170h];movemos el mumero base al registro al
mov cl, [175h];movemos el numero exponente al registro cl
cmp cl,0 ;verificamos si el exponente es 0 para no ejecutar todo el proceso
je cero ; si es 0 brinca a la rutina cero
mov bl, [170h];movemos el numero base al registro bl
sub cl, 1; le resto uno al exponente porque se realiza una multiplicacion que no se cuenta en la funcion multiplicar 

multiplicar:; creacion de la subrutina multiplicacion
    cmp ah,0; verificamos que ah se menor a 0, esto para saber si ya sobrepaso el rango de los 8 bits(255) del registro al
    ja alm; hace que salte a la funcion si se cumple lo de arriba
    mul bl;multiplica bl x al y almacena el resultado en al 
    loop multiplicar;creamos un bucle, este decrementa lo que este en CX y salta de nuevo a multiplicar si es distinto de 0
mov dh,ah;el resultado de la parte alta se mueve a dh
mov dl,al;el resultado de la parte baja se mueve a dl
;y la respuesta final esta en el registro dx
int 20h;finaliza el programa    
                     
multiplicar2:
    mov al,dh; esta funcion mueve los registros de ax a dx para poder realizar las operaciones; 
    mul bl   ; de 8 bits parte por parte, mover ah a dh y luego moverlo a "al" para hacer la
    mov dh,al; multiplicacion y lo mismo con dl y sacar el resultado
    mov al,dl
    mul bl
    cmp ah,0
    ja sum   ; en caso de que exista acarreo se mueve a la funcion sum para sumar al resultado
    mov dl,al
    loop multiplicar2
;la respuesta final esta en el registro dx
int 20h;finaliza el programa    
                     
cero:; en caso del exponente ser cero pone directamente que el resultado es 01
    mov dl,01
    mov dh,00
;y la respuesta final esta en el registro dx                     
int 20h;finaliza el programa

sum:         ;realiza la suma si existe acarreo
    mov dl,al
    adc dh,ah 
    loop multiplicar2
;y la respuesta final esta en el registro dx                     
int 20h;finaliza el programa

b db ?;crea una variable que contiene el valor ? "db" para byte(8 bits) o "dw" para word(16 bits)
e db ?;crea una variable que contiene el valor ? "db" para byte(8 bits) o "dw" para word(16 bits)

alm:           ;esta funcion mueve lo que hayen ax a dx
    mov dh,ah
    mov dl,al
    jmp multiplicar2