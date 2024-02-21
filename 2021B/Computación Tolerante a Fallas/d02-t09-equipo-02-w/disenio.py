from colorama import *

def marco():
    col=2
    fil=4
    print(Cursor.POS(1,1)+Fore.CYAN+Style.BRIGHT+"╔")
    print(Cursor.POS(1,2)+"║");
    print(Cursor.POS(1,3)+"╠")
    print(Cursor.POS(1,49)+"╚")
    print(Cursor.POS(168,1)+"╗")
    print(Cursor.POS(168,2)+"║")
    print(Cursor.POS(168,3)+"╣")
    print(Cursor.POS(168,49)+"╝")
    while col<168:
        print(Cursor.POS(col,1)+Fore.YELLOW+Style.BRIGHT+"═")
        print(Cursor.POS(col,3)+"═")
        print(Cursor.POS(col,49)+"═")
        col=col+1

    while fil<49:
        print(Cursor.POS(1,fil)+Fore.CYAN+Style.BRIGHT+"║");
        print(Cursor.POS(168,fil)+"║");
        fil=fil+1
    print(Cursor.POS(73,2)+Fore.WHITE+Style.BRIGHT+"Task Manager")

def cabeceraDatos():
    col=4
    print(Cursor.POS(3,5)+Fore.RED+Style.BRIGHT+"╔")
    print(Cursor.POS(3,6)+"║")
    print(Cursor.POS(3,7)+"╚")
    print(Cursor.POS(23,5)+"╗")
    print(Cursor.POS(23,6)+"║")
    print(Cursor.POS(23,7)+"╝")
    while col<23:
        print(Cursor.POS(col,5)+"═")
        print(Cursor.POS(col,7)+"═")
        col=col+1
    print(Cursor.POS(7,5)+"╦")
    print(Cursor.POS(7,6)+"║")
    print(Cursor.POS(7,7)+"╩")

    print(Cursor.POS(14,5)+"╦")
    print(Cursor.POS(14,6)+"║")
    print(Cursor.POS(14,7)+"╩")
    
    print(Cursor.POS(3,4)+Fore.WHITE+Style.BRIGHT+"Datos de los procesos")
    print(Cursor.POS(4,6)+"ID ")
    print(Cursor.POS(8,6)+"Inicio")
    print(Cursor.POS(15,6)+"Duración")

def crearFilaDatos(fil,pro):
    col=4
    print(Cursor.POS(3,fil+1)+Fore.RED+Style.BRIGHT+"╠")
    print(Cursor.POS(3,fil+2)+"║")
    print(Cursor.POS(3,fil+3)+"╚")
    print(Cursor.POS(23,fil+1)+"╣")
    print(Cursor.POS(23,fil+2)+"║")
    print(Cursor.POS(23,fil+3)+"╝")
    while col<23:
        print(Cursor.POS(col,fil+3)+"═")
        col=col+1

    print(Cursor.POS(7,fil+1)+"╬")
    print(Cursor.POS(7,fil+2)+"║")
    print(Cursor.POS(7,fil+3)+"╩")

    print(Cursor.POS(14,fil+1)+"╬")
    print(Cursor.POS(14,fil+2)+"║")
    print(Cursor.POS(14,fil+3)+"╩")

    print(Cursor.POS(pro.colT,pro.filT)+Fore.WHITE+Style.BRIGHT+pro.id)
    print(Cursor.POS(pro.colT+6,pro.filT)+str(pro.inicio))
    print(Cursor.POS(pro.colT+14,pro.filT)+str(pro.duracion))

def cabeceraEjec():
    col=28
    print(Cursor.POS(27,5)+Fore.GREEN+Style.BRIGHT+"╔")
    print(Cursor.POS(27,6)+"║")
    print(Cursor.POS(27,7)+"╚")
    print(Cursor.POS(41,5)+"╗")
    print(Cursor.POS(41,6)+"║")
    print(Cursor.POS(41,7)+"╝")
    while col<41:
        print(Cursor.POS(col,5)+"═")
        print(Cursor.POS(col,7)+"═")
        col=col+1
    print(Cursor.POS(31,5)+"╦")
    print(Cursor.POS(31,6)+"║")
    print(Cursor.POS(31,7)+"╩")
    
    print(Cursor.POS(26,4)+Fore.WHITE+Style.BRIGHT+"Orden de ejecución")
    print(Cursor.POS(28,6)+"ID ")
    print(Cursor.POS(32,6)+"Ejecución")

def crearFilaEjec(fil,pro):
    col=28
    print(Cursor.POS(27,fil+1)+Fore.GREEN+Style.BRIGHT+"╠")
    print(Cursor.POS(27,fil+2)+"║")
    print(Cursor.POS(27,fil+3)+"╚")
    print(Cursor.POS(41,fil+1)+"╣")
    print(Cursor.POS(41,fil+2)+"║")
    print(Cursor.POS(41,fil+3)+"╝")
    while col<41:
        print(Cursor.POS(col,fil+3)+"═")
        col=col+1

    print(Cursor.POS(31,fil+1)+"╬")
    print(Cursor.POS(31,fil+2)+"║")
    print(Cursor.POS(31,fil+3)+"╩")

    print(Cursor.POS(pro.colT,pro.filT)+Fore.WHITE+Style.BRIGHT+pro.id)
    print(Cursor.POS(pro.colT+7,pro.filT)+str(pro.inicio))

def marcoEjec(filMax,colMax,dur):
    col=46
    fil=7
    print(Cursor.POS(45,6)+Fore.CYAN+Style.BRIGHT+"╔")
    print(Cursor.POS(45,filMax)+"╚")
    print(Cursor.POS(colMax,6)+"╗")
    print(Cursor.POS(colMax,filMax)+"╝")
    while col<colMax:
        print(Cursor.POS(col,6)+"═")
        print(Cursor.POS(col,filMax)+"═")
        col=col+1

    while fil<filMax:
        print(Cursor.POS(45,fil)+"║");
        print(Cursor.POS(colMax,fil)+"║");
        fil=fil+1
    mitad=int(dur/2)
    print(Cursor.POS(46,filMax+1)+Fore.WHITE+Style.BRIGHT+"0")
    print(Cursor.POS(colMax-1,filMax+1)+str(dur))
    print(Cursor.POS(mitad+46,filMax+1)+str(mitad))
    print(Cursor.POS(46,5)+"Ejecución de procesos")
    
def menu(tam):
    print(Cursor.POS(77,4)+Fore.WHITE+Style.BRIGHT+"Menú")
    if tam==18: #Verifica si la lista esta llena, si lo esta, la opción 3 y 4 no están disponibles
        print(Cursor.POS(65,6)+Fore.WHITE+Style.NORMAL+"1) Añadir proceso manualmente")
        print(Cursor.POS(65,7)+"2) Añadir proceso automáticamente")
    else:
        print(Cursor.POS(65,6)+"1) Añadir proceso manualmente")
        print(Cursor.POS(65,7)+"2) Añadir proceso automáticamente")

    if tam<1: #Verifica que la lista tenga elementos, si no los tiene, la opción 3 y 4 no están disponibles
        print(Cursor.POS(65,8)+Fore.WHITE+Style.NORMAL+"3) Modificar un proceso")
        print(Cursor.POS(65,9)+"4) Comenzar")
    else:
        print(Cursor.POS(65,8)+Fore.WHITE+Style.BRIGHT+"3) Modificar un proceso")
        print(Cursor.POS(65,9)+"4) Comenzar")
    print(Cursor.POS(65,10)+Fore.WHITE+Style.BRIGHT+"5) Salir")

def limpiarPantalla(fil):
    col=2
    f=4
    
    while f<=fil:
        while col<168:
            print(Cursor.POS(col,f)+" ")
            col=col+1
        f=f+1
        col=2
        
def limpiarMenu():
    col=65
    while col<98:
        print(Cursor.POS(col,4)+" ")
        print(Cursor.POS(col,6)+" ")
        print(Cursor.POS(col,7)+" ")
        print(Cursor.POS(col,8)+" ")
        print(Cursor.POS(col,9)+" ")
        print(Cursor.POS(col,10)+" ")
        print(Cursor.POS(col,11)+" ")
        col=col+1

def limpiarResp():
    col=71
    while col<168:
        print(Cursor.POS(col,11)+" ")
        col=col+1

def contador(fil):
    print(Cursor.POS(18,fil)+Fore.WHITE+Style.BRIGHT+"Contador")
    col=13
    print(Cursor.POS(12,fil+1)+Fore.BLUE+Style.BRIGHT+"╔")
    print(Cursor.POS(12,fil+2)+"║")
    print(Cursor.POS(12,fil+3)+"╚")
    print(Cursor.POS(32,fil+1)+"╗")
    print(Cursor.POS(32,fil+2)+"║")
    print(Cursor.POS(32,fil+3)+"╝")
    while col<32:
        print(Cursor.POS(col,fil+1)+"═")
        print(Cursor.POS(col,fil+3)+"═")
        col=col+1
    print(Cursor.POS(21,fil+2)+Fore.WHITE+Style.BRIGHT+"0")
