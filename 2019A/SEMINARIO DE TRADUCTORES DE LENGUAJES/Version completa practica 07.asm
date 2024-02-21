name 'practi07'
org 100h
jmp pedir   

arreglo db 30 dup(0)   
buffer db 99 dup(0)
buffer2 db 99 dup(0)
tam_buffer db ?
handle dw ?     
handle2 dw ? 
varbuff dw 0       
varbuff2 dw 0 
contador dw 0
resta dw 0
band db 0   
band2 db 0 
msg1 db "Bla bla algo por aqui", 0
msg2 db "Nombre del archivo: ", 0
filename db "contado.txt", 0 
msg_tail db "", 0

pedir:
    mov al, 1
    mov bh, 0
    mov bl, 0000_1011b
    mov cx, msg2 - offset msg1 ; calculate message size. 
    mov dl, 10
    mov dh, 6
    push cs
    pop es
    mov bp, offset msg1
    mov ah, 13h
    int 10h
    mov cx, filename - offset msg2 ; calculate message size. 
	mov dl, 10
	mov dh, 7
	push cs
	pop es
	mov bp, offset msg2
	mov ah, 13h
	int 10h
	mov bx, 0
	adc dl, cl
    jmp capturar
    
capturar:
    mov ah, 2
    int 10h
    mov ah, 0
    int 16h
    cmp al, 08h
    je regresar
    mov cx, 1
    mov ah, 0Ah
    int 10h 
    mov arreglo[bx], al
    cmp al, 0Dh
    je create 
    cmp bx, 29  
    inc bx
    inc dl
    jb capturar
    ja regresar

regresar:
    cmp bx, 0
    je capturar
    dec bx
    dec dl
    mov ah, 2
    int 10h
    mov al, 20h
    mov cx, 1
    mov ah, 0Ah
    int 10h
    jmp capturar 
    
create:
	mov ah, 3ch
	mov cx, 0
	mov dx, offset filename
	mov ah, 3ch
	int 21h  ; create file... 
	mov handle2, ax
	jmp open
	
open:
    mov al, 00h
    mov arreglo[bx], al
    mov al, 2
	lea dx, arreglo
	mov ah, 3dh
	int 21h
	jc end
	mov handle, ax
	jmp read
	
read:
    mov bx, [handle]
    mov cx, 99
    lea dx, buffer
    mov ah, 3Fh
    int 21h
    mov tam_buffer, al
    cmp ax, 99
    je leer
    mov band, 0
    cmp ax, 0
    ja analizar1 
    je close
    
write:
    mov cx, varbuff2 
    mov bx, [handle2]
    lea dx, buffer2
    mov ah, 40h
    int 21h   
    sub cl, 6
    mov resta, cx
    mov varbuff2, 0
    cmp band, 1
    je  read
    cmp band2, 1
    je  close
    mov al, tam_buffer
    cmp varbuff, ax 
    je  terminar
    jmp analizar1

close:
    lea bx, [handle2]
    mov ah, 3Eh
    int 21h
    lea bx, [handle]
    mov ah, 3Eh
    int 21h
    jmp end
		    
end:
    int 20h
    
analizar1:             ;Verifica cuanto es el contador
    mov ax, resta 
    mov dx, contador
    add dx, ax
    mov contador, dx
    cmp dx, 9
    ja mayor9
    jbe menor9
    cmp dx, 99
    ja mayor99

analizar2:
    cmp band2, 1
    je write
    mov bx, varbuff 
    mov al, buffer[bx]
    inc bx
    mov varbuff, bx
    mov bx, varbuff2
    mov buffer2[bx], al
    inc bx
    mov varbuff2, bx
    cmp al, 0Ah
    je write
    mov al,tam_buffer
    cmp ax, varbuff
    je write
    jmp analizar2

menor9:                 ; escribe lo que hay en Contador
    mov bx, varbuff2
    mov buffer2[bx], 30h
    inc bx
    mov buffer2[bx], 30h
    inc bx
    add dl, 30h
    mov buffer2[bx], dl
    inc bx
    mov buffer2[bx], 20h
    inc bx
    mov varbuff2, bx
    mov ax, 0
    jmp analizar2

mayor9:                 ; escribe lo que hay en Contador
    mov bx, varbuff2
    mov buffer2[bx], 30h
    inc bx
    mov al, dl
    mov dh, 10
    div dh
    add al, 30h 
    mov buffer2[bx], al
    inc bx
    add ah,30h
    mov buffer2[bx], ah
    inc bx
    mov buffer2[bx], 20h
    inc bx
    mov varbuff2, bx
    mov ax, 0
    jmp analizar2

mayor99:                ; escribe lo que hay en Contador
    mov bx, varbuff2 
    mov al, dl
    mov dh, 100
    idiv dh
    add al, 30h
    mov buffer2[bx], al
    inc bx
    mov al, ah
    mov ah, 0
    mov dh, 10
    idiv dh
    add al, 30h 
    mov buffer2[bx], al
    inc bx
    add ah,30h
    mov buffer2[bx], ah
    inc bx
    mov buffer2[bx], 20h
    inc bx
    mov varbuff2, bx
    mov ax, 0
    jmp analizar2
    
leer:                   ; activa la bandera de si aun no se llego al fin de cadena
    mov band, 1
    jmp analizar1
                        
terminar:               ; activa la bandera de terminar
    mov band2, 1
    mov buffer2[0], 0Dh
    mov buffer2[1], 0Ah 
    mov buffer2[6], 0
    mov varbuff2, 2
    add resta, 2 
    jmp analizar1