name "mycode"   ; 
org  100h	; 

mov ax, 1003h  
mov bx, 0        
int 10h

mov dx, 0705h     
mov bx, 0         
mov bl, 10011111b 
mov cx, msg1_size  
mov al, 01b       
mov bp, msg1
mov ah, 13h       
int 10h           

 mov ax, 10 ;AX=10
 mov bx, 00F9h ;BX=0xF9
 inc bx ;BX++
 add ax, 4 ;AX=AX+4
 mov cx,45 ;CX=45
 sub cx,cx ;CX=CX-CX

mov dx, 0705h      
mov bx, 0         
mov bl, 10011111b 
mov cx, msg2_size  
mov al, 01b        
mov bp, msg2
mov ah, 13h        
int 10h           

mov ah, 0          
int 10110b        

ret   

msg1:         db "ejecutando..."
msg2:         db "pulsa una tecla"
msg_tail:
msg1_size = msg2 - msg1
msg2_size = msg_tail - msg2                  





