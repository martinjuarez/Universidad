name "Martin Juarez Plascencia"
org 100h          

; Ejemplo de suma
; Dec |  Hex
; 16  |  10
; 15  |  0F
; 14  |  0E
; 13  |  0D
; 12  |  0C
;____________
; 70     46
                                                                    
; Ejecutar el programa paso a paso                                                                    
; Cargar con un numero las direcciones de memoria 114h hasta la 118h
; El resultado estara en el registro de 8 bits "cl"                

mov cl, [114h]     
add cl, [115h]
add cl, [116h]
add cl, [117h]
add cl, [118h]
