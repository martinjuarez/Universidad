;Daniela Isordia Calixto
;practica 5
;215861533

include 'emu8086.inc'

org 100h
mov ax, 1003h  
mov bx, 0        
int 10h

mov dx, 0705h         ;en esta parte imprimimos que el usuario ingrese el numero en hexadecimal
mov bx, 0         
mov bl, 00001111b 
mov cx, msg1_size  
mov al, 01b       
mov bp, msg1
mov ah, 13h       
int 10h
call obtener
mov dx, 0A0Ah      
mov bx, 0         
mov bl, 00001111b 
mov cx, msg2_size  
mov al, 01b        
mov bp, msg2
mov ah, 13h        
int 10h
 
mov al,n16           ;aqui guardamos el valor del segundo digito hexadecimal 
aam
mov uni,al           ;respaldo de la unidad
mov al,ah
aam
mov cen,ah           ;respaldo las centenas
mov dece,al          ;respaldo las decenas 

mov al,cen
call print_resul:
mov al,dece
call print_resul:
mov al,uni
call print_resul:           
     
int 20h
  
print_resul:
        mov ah,0Eh
        add al,30h
        int 10h
        ret

  
obtener proc
        xor ax,ax
        lea     di,cadnum
        lea     si,n16
        mov     dx,9
        call    get_string

        mov     al,[di]
        call    numbyte
        mov     al,[b]
        mov     [si],al
        inc     si
        inc     di
        mov     al,[di]
        call    numbyte
        mov     al,[b]
        mov     [si],al
        inc     si
        inc     di
        mov     al,[di]
        call    numbyte
        mov     al,[b]
        mov     [si],al
        inc     si
        inc     di
        mov     al,[di]
        call    numbyte
        mov     al,[b]
        mov     [si],al
        
        lea     di,n16
        
        
        ret

numbyte:
        call    asc2num
        mov     bl,16
        mul     bl
        mov     [b],al
        inc     di
        mov     al,[di]
        call    asc2num
        add     al,[b]
        mov     [b],al
        ret
        
asc2num:
        sub     al,48
        cmp     al,9
        jle     f_asc
        sub     al,7
        cmp     al,15
        jle     f_asc
        sub     al,32
f_asc:  ret

obtener endp

 

cadnum  db      "000000000"
n16     db      ?
b       db      ?

cen     db      0          ;aqui guardamos el resultado en decimal
dece    db      0
uni     db      0

msg1:   db "Introduce un numero Hexadecimal: "
msg2:   db "El valor en decimal es: "
msg_tail:
msg1_size = msg2 - msg1
msg2_size = msg_tail - msg2 

DEFINE_GET_STRING
        END                   ; para el compilador
