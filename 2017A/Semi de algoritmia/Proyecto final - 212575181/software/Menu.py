def Menu():
    """Funcion que Muestra el Menu"""
    print """************
************
Juego
Menu
1) Instrucciones
2) Jugar"""


def Menu_juego():
    """Funcion Para Calcular Operaciones Aritmeticas"""
    Menu()
    opc = int(input("Selecione Opcion\n"))
    while (opc >0 and opc <5):
        if (opc==1):
            print "Instrucciones"
            print " M = Disparo"
            print " Teclas de direccion = Movimiento " 
            opc = int(input("Selecione Opcion\n"))
        elif(opc==2):
            import ProyectoFinal
            opc = int(input("Selecione Opcion\n"))
        
Menu_juego()
