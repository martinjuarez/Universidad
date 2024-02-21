from colorama import *

def marcoError():
    col=67
    fil=15
    print(Cursor.POS(66,14)+Fore.WHITE+Style.BRIGHT+"╔")
    print(Cursor.POS(66,19)+"╚")
    print(Cursor.POS(96,14)+"╗")
    print(Cursor.POS(96,19)+"╝")
    while col<96:
        print(Cursor.POS(col,14)+"═",end="")
        print(Cursor.POS(col,19)+"═",end="")
        col=col+1

    while fil<19:
        print(Cursor.POS(66,fil)+"║");
        print(Cursor.POS(96,fil)+"║");
        fil=fil+1

def error1(n,n1):
    marcoError()
    print(Cursor.POS(78,15)+Fore.RED+Style.BRIGHT+"ERROR")
    print(Cursor.POS(70,17)+"Debe ingresar un número")
    print(Cursor.POS(75,18)+"entre "+str(n)+" y "+str(n1))
    limpiarError()

def error2():
    marcoError()
    print(Cursor.POS(78,15)+Fore.RED+Style.BRIGHT+"ERROR")
    print(Cursor.POS(69,17)+"Aún no hay ningún proceso")
    print(Cursor.POS(76,18)+"registrado")
    limpiarError()

def error3():
    marcoError()
    print(Cursor.POS(78,15)+Fore.RED+Style.BRIGHT+"ERROR")
    print(Cursor.POS(69,17)+"Ya ha registrado la máxima")
    print(Cursor.POS(72,18)+"cantidad de procesos")
    limpiarError()
    
def limpiarError():
    print(Cursor.POS(67,21)+Fore.WHITE+Style.BRIGHT+"Presione enter para continuar",end="")
    input()
    col=66
    while col<97:
        print(Cursor.POS(col,14)+" ")
        print(Cursor.POS(col,15)+" ")
        print(Cursor.POS(col,16)+" ")
        print(Cursor.POS(col,17)+" ")
        print(Cursor.POS(col,18)+" ")
        print(Cursor.POS(col,19)+" ")
        print(Cursor.POS(col,21)+" ")
        col=col+1
