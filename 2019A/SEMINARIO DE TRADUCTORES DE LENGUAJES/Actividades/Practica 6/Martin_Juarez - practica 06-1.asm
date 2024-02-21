NAME 'practica 06'
ORG 100H
              
MOV AL,1
MOV BH,0
MOV BL,0000_1111b
MOV CX,capturar - OFFSET msg1  
MOV DL,10                           
MOV DH,7
PUSH CS
POP ES
MOV BP, OFFSET msg1
MOV AH,13H
INT 10H
MOV BX,0
ADC DL,CL                          
JMP capturar
arreglo DB 30 DUP(00h)             
msg1 dw "Ingresa una ecuacion:"

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
    JE operadores 
    CMP BX,30  
    INC BX
    INC DL
    JB capturar

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
   
operadores:
    mov dh, 10
    mov dl, 20
    mov bh, 0
    mov ah, 2
    int 10h
     
numero:
    CMP arreglo[BX],48h
    JGE numero2

numero2:
    CMP arreglo[BX],57h
    JLE numero

end:
    INT 20H