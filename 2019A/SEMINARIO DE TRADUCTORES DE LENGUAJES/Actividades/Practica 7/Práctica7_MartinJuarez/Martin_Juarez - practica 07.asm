NAME 'practi07'
ORG 100h
jmp main

main:
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
    mov cx, msg_tail - offset msg2 ; calculate message size. 
	mov dl, 10
	mov dh, 7
	push cs
	pop es
	mov bp, offset msg2
	mov ah, 13h
	int 10h
	mov bx,0
	adc dl,cl
    jmp capturar
    
arreglo db 30 dup(0)
msg1 db "Bla bla algo por aqui", 0
msg2 db "Nombre del archivo: ", 0
msg_tail:

capturar:
    MOV AH,2
    INT 10h
    MOV AH,0
    INT 16h
    CMP AL,08h
    JE regresar
    MOV CX,1
    MOV AH,0Ah
    INT 10h 
    MOV arreglo[BX],AL
    CMP AL,0Dh
    JE create 
    CMP BX,29  
    INC BX
    INC DL
    JB capturar
    JA regresar

regresar:
    CMP BX,0
    JE capturar
    DEC BX
    DEC DL
    MOV AH,2
    INT 10h
    MOV AL,20h
    MOV CX,1
    MOV AH,0Ah
    INT 10h
    JMP capturar
    
open:
    mov al, 00h
    mov arreglo[BX],AL
    mov al, 2
	lea dx, arreglo
	mov ah, 3dh
	int 21h
	jc end
	mov handle, ax
	jmp read
	handle dw ?

create:
	mov ah, 3ch
	mov cx, 0
	mov dx, offset filename
	mov ah, 3ch
	int 21h  ; create file... 
	mov handle2, ax
	jmp open
	filename db "contado.txt", 0
	handle2 dw ?

read:
    mov bx,[handle]
    mov cx, 80
    lea dx, buffer
    mov ah, 3Fh
    int 21h
    cmp ax, 0
    je end 
    ja analizar1 
           
buffer db 99 dup(0)

analizar1:
    mov bx,0
    mov buffer2[bx],30h
    inc bx 
    mov buffer2[bx],30h
    inc bx
    mov buffer2[bx],30h
    inc bx
    mov buffer2[bx],20h
    inc bx
    jmp analizar2
    
band db 1

analizar2:
    mov varbuff2,bx
    mov bx,varbuff 
    mov al, buffer[bx]
    cmp al, 00h
    je tail
    inc bx
    mov varbuff,bx
    mov bx,varbuff2
    mov buffer2[bx],al
    inc bx
    cmp al, 0Ah
    je analizar3
    jmp analizar2

varbuff2 dw 0
      
analizar3:
    mov cl,band
    cmp cl,1
    ja med
    mov varbuff2,bx
    mov dx,var3
    mov bx,varbuff
    sub bx,2
    add dx,bx
    mov var3,dx
    cmp dx, 9
    jb analizar6
    cmp dx, 99
    jb analizar7
    med:
    mov varbuff2,bx
    mov dx,var3
    mov bx,varbuff
    mov al,2
    mul cl
    sub bx,ax
    mov dx,bx
    mov var3,dx
    cmp dx, 9
    jb analizar6
    cmp dx, 99
    jb analizar7
    analizar5:
        mov bx,varbuff2 
        mov al,dl
        mov dh,100
        idiv dh
        add al,30h
        mov buffer2[bx],al
        inc bx
        mov al,ah
        mov ah,0
        mov dh,10
        idiv dh
        add al,30h 
        mov buffer2[bx],al
        inc bx
        add ah,30h
        mov buffer2[bx],ah
        inc bx
        mov buffer2[bx],20h
        inc bx
        inc cl
        mov band,cl
        mov cl,band2
        cmp cl,1
        je write
        jmp analizar2
    analizar6:
        mov bx,varbuff2
        mov buffer2[bx],30h
        inc bx 
        mov buffer2[bx],30h
        inc bx
        add dl,30h
        mov buffer2[bx],dl
        inc bx
        mov buffer2[bx],20h
        inc bx
        inc cl
        mov band,cl
        mov cl,band2
        cmp cl,1
        je write
        jmp analizar2
    analizar7:
        mov bx,varbuff2
        mov buffer2[bx],30h
        inc bx
        mov al,dl
        mov dh,10
        idiv dh
        add al,30h 
        mov buffer2[bx],al
        inc bx
        add ah,30h
        mov buffer2[bx],ah
        inc bx
        mov buffer2[bx],20h
        inc bx
        inc cl
        mov band,cl
        mov cl,band2
        cmp cl,1
        je write
        jmp analizar2
          
var3 dw 0    
    
buffer2 db 99 dup(0)
varbuff dw 0
band2 db 0


tail:
    mov bx,varbuff2
    mov buffer2[bx],0Dh
    inc bx
    mov buffer2[bx],0Ah
    inc bx
    mov varbuff2,bx 
    mov band2,1
    jmp analizar3
    
         
write:
    mov cx,varbuff2 
    mov bx,[handle2]
    lea dx, buffer2
    mov ah, 40h
    int 21h
    jmp close

close:
    lea bx,[handle2]
    mov ah,3Eh
    int 21h
    lea bx,[handle]
    mov ah,3Eh
    int 21h
    jmp end
		    
end:
    int 20h