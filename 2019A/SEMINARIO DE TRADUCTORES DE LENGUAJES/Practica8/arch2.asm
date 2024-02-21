        NAME    "arch2"
        ORG     0100H
        jmp     main

linea   DB      81 DUP (0)
n_arch  DB      30 DUP (0)
han_n_a DW      0
salir   DB      0
t_linea DB      0
error   DW      0
NvaLine DB      0ah,0dh 
msg1    DB      "Dame el nombre del archivo. usa el formato 8.3",0dH,0aH
msg2    DB      "Escribe una linea, maximo 80 caracteres",0dH,0aH
msg3    DB      "Presiona <ESC> PARA SALIR",0dH,0aH
msg4    DB      "s",0dH,0aH
msge01  DB      "Funcion No Valida",0dh,0aH
msge02  DB      "Archivo No Encontrado",0dH,0aH
msge03  DB      "Ruta No Valida",0dH,0aH
msge04  DB      "Handle No Disponible",0dH,0aH
msge05  DB      "Acceso Denegado",0dH,0aH
msge06  DB      "Handle no valido",0dH,0aH
msge07  DB      "s",0dH,0aH
msge08  DB      "s",0dh,0aH
msge09  DB      "s",0dH,0aH
msge0A  DB      "s",0dH,0aH
msge0B  DB      "s",0dH,0aH
msge0C  DB      "s",0dH,0aH
msge0D  DB      "s",0dH,0aH
msge0E  DB      "s",0dH,0aH
msge0F  DB      "s",0dH,0aH
msge10  DB      "Excede el número de caracteres",0dH,0aH
msge11  DB      "s",0dH,0aH
tmsge01 DW      msge02 - offset msge01
tmsge02 DW      msge03 - offset msge02
tmsge03 DW      msge04 - offset msge03
tmsge04 DW      msge05 - offset msge04
tmsge05 DW      msge06 - offset msge05
tmsge06 DW      msge07 - offset msge06
tmsge07 DW      msge08 - offset msge07
tmsge08 DW      msge09 - offset msge08
tmsge09 DW      msge0A - offset msge09
tmsge0A DW      msge0B - offset msge0A
tmsge0B DW      msge0C - offset msge0B
tmsge0C DW      msge0D - offset msge0C
tmsge0D DW      msge0E - offset msge0D
tmsge0E DW      msge0F - offset msge0E
tmsge0F DW      msge10 - offset msge0F

main:
    	mov     al,03h
    	mov     ah,0
    	int     10h
     	mov     ch,6
     	mov     cl,7
     	mov     ah,1
     	int     10h
        lea     di,msg1  ;Dame el nombre del archivo.
        mov     cx,msg2 - offset msg1
        mov     dh,0
        mov     dl,0
        call    imprime
        mov     dh,03
	    mov     dl,0
	    mov     bh,0
	    mov     ah,2
	    int     10h
        lea     si,n_arch
        mov     cx,30 
        call    lee_cad
        call    crea_arch
        lea     di,msg2 ;Escribe una linea, maximo 80 caracteres
        mov     cx,msg3 - offset msg2
        mov     dh,6
        mov     dl,0
        call    imprime
        lea     di,msg3 ;Presiona <ESC> PARA SALIR
        mov     cx,msg4 - offset msg3
        mov     dh,7
        mov     dl,0
        call    imprime
        mov     dh,9
	    mov     dl,0
	    mov     bh,0
	    mov     ah,2
	    int     10h
e_lin:  lea     si,linea
        mov     cx,81
        call    limpia
        lea     si,linea
        mov     cx,81       
        call    lee_cad
        call    esc_archivo
        mov     al,[salir]
        cmp     al,1
        je      FIN
        jmp     e_lin
FIN:    call    cerrar_archivo
        xor     ax,ax
        int     20H 
        
lee_cad:        
        push    di
        push    si
        push    cx
        push    ax
        mov     [t_linea],cl
ntecla: jcxz    enc
        mov     ah,0
        int     16H
        mov     [si],al
        inc     si
        dec     cx
        cmp     al,1BH
        jne     sigue
        mov     [salir],1
        jmp     FINCAD
sigue:  cmp     al,0DH
        je      FINCAD
        cmp     al,08H
        je      borra
        mov     ah,0EH
        int     10H
        jmp     ntecla
borra:  dec     si
        dec     si
        inc     cx
        inc     cx
        mov     ah,0eH
        int     10H
        mov     al,20H
        int     10H
        mov     al,08
        int     10H
        jmp     ntecla
enc:    lea     di,msge10  ;Excede el número de caracteres
        mov     cx,msge11 - offset msge10
        mov     dh,0
        mov     dl,0
        call    imprime
        mov     dh,03
	    mov     dl,0
	    mov     bh, 0
	    mov     ah, 2
	    int     10h
        lea     si,linea
        mov     cx,30
        call    limpia
        lea     di,msg2  ;Escribe una linea, maximo 80 caracteres
        mov     cx,msg3 - offset msg2
        mov     dh,1
        mov     dl,0
        call    imprime
        mov     dh,03
	    mov     dl,0
	    mov     bh, 0
	    mov     ah, 2
	    int     10h
	    call    BorraLinea
        mov     dh,03
	    mov     dl,0
	    mov     bh, 0
	    mov     ah, 2
	    int     10h
        lea     si,linea
        mov     cx,30
        jmp     ntecla
FINCAD: dec     si
        mov     [si],0
        mov     ah,0eH
        mov     al,0aH
        int     10H
        mov     al,0dH
        int     10H
        sub     [t_linea],cl
        pop     ax
        pop     cx
        pop     si
        pop     di 
        ret    
        
crea_arch:
        push    dx
        push    cx
        push    ax
        lea     dx,n_arch
        mov     cx,0
        mov     ah,3Ch
        int     21H
        jc      er_arc
        mov     [han_n_a],ax
        jmp     fca
er_arc: mov     [error],ax
        mov     dh,1
        mov     dl,0
        call    BorraLinea
        call    err_arch
fca:    pop     ax
        pop     cx
        pop     dx
        ret

abrir_arch:
        push    dx
        push    cx
        push    ax
        lea     dx,n_arch
        mov     cx,0
        mov     ah,3Dh
        int     21H
        jc      ea_arc
        mov     [han_n_a],ax
        jmp     faa
ea_arc: mov     [error],ax
        mov     dh,1
        mov     dl,0
        call    BorraLinea
        call    err_arch
faa:    pop     ax
        pop     cx
        pop     dx
        ret

cerrar_archivo:
        push    dx
        push    bx
        push    ax        
        mov     bx,[han_n_a]
        mov     ah,3eH                           
        int     21H
        jnc     fcra
        mov     [error],ax
        mov     dh,20
        mov     dl,0
        call    BorraLinea
        call    err_arch
fcra:   pop     ax
        pop     bx
        pop     dx
        ret

lee_archivo:
        push    dx
        push    cx
        push    bx
        push    ax
        mov     ah,3FH
        mov     bx,[han_n_a]
        xor     cx,cx
        mov     cl,[t_linea]
        dec     cx
        lea     dx,linea
        mov     bp,dx
        add     bp,cx
        mov     [bp],0dH
        inc     bp
        mov     [bp],0aH
        inc     cx
        inc     cx
        int     21H
        jnc     f_e_at
        mov     [error],ax
        mov     dh,20
        mov     dl,0
        call    BorraLinea
        call    err_arch
f_e_at: pop     ax
        pop     bx
        pop     cx
        pop     dx
        ret

esc_archivo:
        push    dx
        push    cx
        push    bx
        push    ax
        mov     ah,40H
        mov     bx,[han_n_a]
        xor     cx,cx
        mov     cl,[t_linea]
        dec     cx
        lea     dx,linea
        mov     bp,dx
        add     bp,cx
        mov     [bp],0dH
        inc     bp
        mov     [bp],0aH
        inc     cx
        inc     cx
        int     21H
        jnc     f_e_a
        mov     [error],ax
        mov     dh,20
        mov     dl,0
        call    BorraLinea
        call    err_arch
f_e_a:  pop     ax
        pop     bx
        pop     cx
        pop     dx
        ret
             
imprime:
       	push    bx
       	push    ax
       	push    es
       	mov     al,1
    	mov     bh,0
    	mov     bl,0011_1011b
    	push    cs
    	pop     es
    	mov     bp,di
    	mov     ah,13h
    	int     10h
    	pop     es
    	pop     ax
    	pop |   bx
    	ret
    	
BorraLinea:
        push    ax
        push    bx
        push    cx
        mov     cx,80
        mov     al,32
        mov     bh,0
        mov     ah,0aH
        int     10H
        pop     cx
        pop     bx
        pop     ax
        ret 
        
limpia: push    si
        push    cx
l_lim:  mov     [si],0
        inc     si
        loop    l_lim
        pop     cx
        pop     si
        ret	        

err_arch:
        push    di
        push    dx
        push    cx
        push    ax
        mov     ax,[error]
        dec     ax
        jnz     e2
e1:     lea     di,msge01
        mov     cx,tmsge01
        call    imprime
e2:     dec     ax
        jnz     e3
        lea     di,msge02
        mov     cx,tmsge02
        call    imprime
e3:     dec     ax
        jnz     e4
        lea     di,msge03
        mov     cx,tmsge03
        call    imprime
e4:     dec     ax
        jnz     e5
        lea     di,msge04
        mov     cx,tmsge04
        call    imprime
e5:     dec     ax
        jnz     e6
        lea     di,msge05
        mov     cx,tmsge05
        call    imprime
e6:     dec     ax
        jnz     e7
        lea     di,msge06
        mov     cx,tmsge06
        call    imprime
e7:     dec     ax
        jnz     e8
        lea     di,msge07
        mov     cx,tmsge08
        call    imprime
e8:     dec     ax
        jnz     e9
        lea     di,msge08
        mov     cx,tmsge08
        call    imprime
e9:     dec     ax
        jnz     eA
        lea     di,msge09
        mov     cx,tmsge09
        call    imprime
eA:     dec     ax
        jnz     eB
        lea     di,msge0A
        mov     cx,tmsge0A
        call    imprime
eB:     dec     ax
        jnz     eC
        lea     di,msge0B
        mov     cx,tmsge0B
        call    imprime
eC:     dec     ax
        jnz     eD
        lea     di,msge0C
        mov     cx,tmsge0C
        call    imprime
eD:     dec     ax
        jnz     eE
        lea     di,msge0D
        mov     cx,tmsge0D
        call    imprime
eE:     dec     ax
        jnz     eF
        lea     di,msge0E
        mov     cx,tmsge0E
        call    imprime
eF:
        pop     ax
        pop     cx
        pop     dx
        pop     di 
        ret 
        