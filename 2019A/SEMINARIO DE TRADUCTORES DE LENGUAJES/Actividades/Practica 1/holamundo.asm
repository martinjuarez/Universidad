name "holamundo"

; este programa imprime dos mensajes en la pantall
; escribiendo directamente en la memoria de video.
; en la memoria vga: el primer byte es el caracter ascii,
; el siguiente byte son los atributos del caracter.
; los atributos del caracter es un valor de 8 bits,
; los 4 bits altos ponen el color del fondo
; y los 4 bits bajos ponen el color de la letra.

; hex    bin        color
; 
; 0      0000      black
; 1      0001      blue
; 2      0010      green
; 3      0011      cyan
; 4      0100      red
; 5      0101      magenta
; 6      0110      brown
; 7      0111      light gray
; 8      1000      dark gray
; 9      1001      light blue
; a      1010      light green
; b      1011      light cyan
; c      1100      light red
; d      1101      light magenta
; e      1110      yellow
; f      1111      white
 


org 100h

	mov al, 1
	mov bh, 0
	mov bl, 1001_1111b
	mov cx, msg2 - offset msg1 ; calcula el tama�o del mensaje. 
	mov dl, 7
	mov dh, 11
	push cs
	pop es
	mov bp, offset msg1
	mov ah, 13h
	int 10h
	mov cx, msgend - offset msg2  
	mov dl, 36
	mov dh, 13
	mov bp, offset msg2
	mov ah, 13h
	int 10h
	jmp msgend
	
msg1    db "Hola, seminario de soluci�n de problemas de traductores de lenguaje 1"
msg2    db "seccion D04"

msgend:
        mov ah,0
        int 16h
        int 20h
        
