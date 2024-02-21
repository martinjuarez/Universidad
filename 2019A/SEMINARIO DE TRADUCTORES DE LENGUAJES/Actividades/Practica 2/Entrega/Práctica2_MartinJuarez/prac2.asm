name "Martin Juarez Plascencia"   ;Nombre del programa 
org  100h	; 

mov ax, 1003h     ;Esta asignando 1003h al registro ax
mov bx, 0         ;Esta asignando 0 al registro bx
int 10h           ;Llama a la interrupcion 10h

mov dx, 0705h     ;Esta asignando 0705h al registro dx  
mov bx, 0         ;Esta asignando 0 al registro bx
mov bl, 00101110b ;Esta asignando 00101110b al registro bl
mov cx, msg1_size ;Esta asignando el valor de msg1_size al registro cx
mov al, 01b       ;Esta asignando 01b al registro al
mov bp, msg1      ;Esta asignando el valor de msg1 al registro bp
mov ah, 13h       ;Esta asignando 13h al registro ah
int 10h           ;Llama a la interrupcion 10h

 mov ax, 10 ;AX=10
 mov bx, 00F9h ;BX=0xF9
 inc bx ;BX++
 add ax, 4 ;AX=AX+4
 mov cx,45 ;CX=45
 sub cx,cx ;CX=CX-CX           

mov dx, 0812h     ;Esta asignando 0812h al registro dx 
mov bx, 0         ;Esta asignando 0 al registro bx
mov bl, 11100000b ;Esta asignando 11100000b al registro bl
mov cx, msg2_size ;Esta asignando el valor de msg2_size al registro cx
mov al, 01b       ;Esta asignando 01b al registro al 
mov bp, msg2      ;Esta asignando el valor de msg2 al registro bp
mov ah, 13h       ;Esta asignando 13h al registro ah 
int 10h           ;Llama a la interrupcion 10h

mov dx, 0923h     ;Esta asignando 0923h al registro dx  
mov bx, 0         ;Esta asignando 0 al registro bx
mov bl, 01001111b ;Esta asignando 01001111b al registro bl
mov cx, msg3_size ;Esta asignando el valor de msg3_size al registro cx 
mov al, 01b       ;Esta asignando 01b al registro al 
mov bp, msg3      ;Esta asignando el valor de msg3 al registro bp
mov ah, 13h       ;Esta asignando 13h al registro ah  
int 10h           ;Llama a la interrupcion 10h

mov ah, 0         ;Esta asignando 0 al registro ah            
int 10110b        ;Llama a la interrupcion 10110b

ret               ;Retorno

msg1:         db "ejecutando..."  ;Guarda la cadena ejecutando... 
msg2:         db "mi prueba.exe... "  ;Guarda la cadena mi prueba.exe...  
msg3:         db "Probando... Martin Juarez Plascencia"   ;Guarda la cadena Probando probando uno dos tres

msg_tail:
msg1_size = msg2 - msg1           ;Calcula el tamano del msg1_size
msg2_size = msg3 - msg2           ;Calcula el tamano del msg2_size
msg3_size = msg_tail - msg3       ;Calcula el tamano del msg3_size