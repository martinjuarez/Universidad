from colorama import *
import random
import errores
import time

def colorRandom():
    e=random.randint(0,6)
    barra=[Back.MAGENTA+Style.BRIGHT,Back.YELLOW+Style.BRIGHT,Back.BLUE+Style.BRIGHT,Back.GREEN+Style.BRIGHT,
           Back.RED+Style.BRIGHT,Back.WHITE+Style.BRIGHT,Back.CYAN+Style.BRIGHT]
    return barra[e]

def limpOpc(col,fil):
    col=col
    while col<168:
        print(Cursor.POS(col,fil)+" ")
        col=col+1

def ini_dur():
    ini=-1
    while ini<0 or ini>118:
        try:
            print(Cursor.POS(65,6)+"Inicio (0-118): ",end="")
            ini=int(input())
            if ini<0 or ini>118:
                errores.error1(0,118)
                limpOpc(80,6)
        except:
            errores.error1(0,118)
            limpOpc(80,6)
            ini=-1
    d=119-ini
    dur=0
    while dur<1 or dur>d:
        try:
            print(Cursor.POS(65,8)+"Duración (1-"+str(d)+"): ",end="")
            dur=int(input())
            if dur<1 or dur>d:
                errores.error1(1,d)
                limpOpc(82,8)
        except:
            errores.error1(1,d)
            limpOpc(82,8)
            dur=0
    return ini,dur
            
def agregarM():
    barra=colorRandom()
    print(Cursor.POS(75,4)+"Agregar")
    ini,dur=ini_dur()
    print(Cursor.POS(75,4)+"       ")
    return ini,dur,barra

def agregarA():
    barra=colorRandom()
    ini=random.randint(0,117)
    d=119-ini
    dur=random.randint(1,d)
    return ini,dur,barra

def modificar(idP):
    op=0
    print(Cursor.POS(75,4)+"Modificar")
    print(Cursor.POS(65,6)+"1) Ingresar id del proceso")
    print(Cursor.POS(65,7)+"2) Cancelar")
    while op<1 or op>2:
        try:
            print(Cursor.POS(65,8)+"Resp: ",end="")
            op=int(input())
            if op<1 or op>2:
                errores.error1(1,2)
                limpOpc(71,8)
        except:
            errores.error1(1,2)
            limpOpc(71,8)
            op=0
    if op==1:
        idM=0
        print(Cursor.POS(65,6)+"                          ")
        print(Cursor.POS(65,7)+"           ")
        limpOpc(65,8)

        while idM<1 or idM>idP:
            try:
                print(Cursor.POS(65,6)+"ID: P",end="")
                idM=int(input())
                if idM<1 or idM>idP:
                    errores.error1(1,idP)
                    limpOpc(70,6)
            except:
                errores.error1(1,idP)
                limpOpc(70,3)
                idM
        ini,dur=ini_dur()
        print(Cursor.POS(75,4)+"         ")
        return idM,ini,dur
    print(Cursor.POS(75,4)+"         ")
    return -1,-1,-1

def ejecucion(pro,dur,fil):
    cont=0
    while cont<=dur:
        for p in pro:
            if cont>=p.inicio and p.tt<=p.duracion:
                 print(Cursor.POS(p.colB,p.filB)+p.colorB+" ")
                 print(Cursor.POS(p.colT+7,p.filT)+Back.BLACK+Fore.WHITE+Style.BRIGHT+str(p.inicio))
                 p.inicio=p.inicio+1
                 p.colB=p.colB+1
                 p.tt=p.tt+1
        print(Cursor.POS(21,fil+2)+Back.BLACK+Fore.WHITE+Style.BRIGHT+str(cont))
        cont=cont+1
        time.sleep(0.5)
            
