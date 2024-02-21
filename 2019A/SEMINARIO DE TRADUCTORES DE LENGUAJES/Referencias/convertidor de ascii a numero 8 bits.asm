
include 'emu8086.inc'

        org 0100h 
ini:    xor ax,ax
        lea     di,cadnum
        mov     dx,9
        call    get_string
        mov     al,[di]
        call    asc2num
        mov     bl,16
        mul     bl
        mov     [b0],al
        inc     di
        mov     al,[di]
        call    asc2num
        add     al,[b0] 
        ret
        
cadnum  db "000000000"
b0      db  0

asc2num:
        sub     al,48
        cmp     al,9
        jle     f_asc
        sub     al,7
f_asc:  ret

DEFINE_GET_STRING
        END        
        
      
