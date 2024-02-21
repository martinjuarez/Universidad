#Garibay Gamero Raúl Jared Alberto D02
#Gómez Mendoza Luis Gustavo D02
#Juárez Plascencia Martín D02
#Ramírez Rodríguez Karla Lizette D02
#Rubio Gutiérrez Leonel D02
from colorama import *
import disenio
import proceso
import datos
import os
import errores
import itertools

def main():
    init(autoreset=False)
    mensaje()
    cantPro=18
    idP=1
    fil=6
    op=0
    procesos=[]
    maxDur=0
    
    disenio.marco()
    disenio.cabeceraDatos()
    print(Cursor.POS(32,6)+"Procesos restantes:")
    print(Cursor.POS(52,6)+str(cantPro)+" ")
    while op!=5:
        tam=len(procesos)
        disenio.menu(tam)
        while op<1 or op>5:
            try:
                print(Cursor.POS(65,11)+"Resp: ",end="")
                op=int(input())
                if op<1 or op>5:
                    errores.error1(1,5)
                    disenio.limpiarResp()
                elif (op==3 and tam==0) or (op==4 and tam==0):
                    errores.error2()
                    disenio.limpiarResp()
                    op=0
                elif (op==1 and tam==18) or (op==2 and tam==18):
                    errores.error3()
                    disenio.limpiarResp()
                    op=0
            except:
                errores.error1(1,5)
                disenio.limpiarResp()
                op=0
        if op==1 or op==2:
            pro,temp=agregar(op,fil,idP)
            if temp>maxDur:
                maxDur=temp
            procesos.append(pro)
            fil=fil+2
            idP=idP+1
            cantPro=cantPro-1
            print(Cursor.POS(52,6)+str(cantPro)+" ")
            op=0
        elif op==3:
            disenio.limpiarMenu()
            pos,ini,dur=datos.modificar(len(procesos))
            if pos!=-1:
                procesos[pos-1].inicio=ini
                procesos[pos-1].duracion=dur
                procesos[pos-1].colB=46+ini
                actualizarT(procesos[pos-1])
            op=0
        elif op==4:
            disenio.limpiarMenu()
            comenzar(procesos,maxDur)
            cantPro=18
            idP=1
            fil=6
            op=0
            procesos=[]
            maxDur=0
            print(Cursor.POS(52,6)+str(cantPro)+" ")  

def mensaje():
    print(Cursor.POS(1,1)+Fore.WHITE+Style.BRIGHT+"Antes de comenzar, maximize el tamaño de su ventana,")
    print(Cursor.POS(1,2)+"para el correcto funcionamiento del programa.")
    print(Cursor.POS(1,4)+"Una vez que haya hecho eso, presione enter para comenzar.")
    print(Cursor.POS(58,4)+"",end="")
    input()
    os.system("cls")

def agregar(op,fil,idP):
    if op==1:
        disenio.limpiarMenu()
        ini,dur,barra=datos.agregarM()
    else:
        ini,dur,barra=datos.agregarA()
        disenio.limpiarResp()

    pro=proceso.Proceso("P"+str(idP),ini,dur,4,fil+2,barra)
    disenio.crearFilaDatos(fil,pro)
    return pro,ini+dur

def actualizarT(pro):
    col=pro.colT+6
    while col<14:
        print(Cursor.POS(col,pro.filT)+" ")
        col=col+1

    col=pro.colT+14
    while col<23:
        print(Cursor.POS(col,pro.filT)+" ")
        col=col+1

    print(Cursor.POS(pro.colT+6,pro.filT)+str(pro.inicio))
    print(Cursor.POS(pro.colT+14,pro.filT)+str(pro.duracion))

def comenzar(procesos,maxDur):
    print(Cursor.POS(32,6)+"                      ")
    disenio.cabeceraEjec()
    fil=6
    procesos=sorted(procesos)
    j=14
    for pro in procesos: #Actualiza las posiciones para mostrar los procesos en la segunda tabla
        pro.colT=28
        pro.filT=fil+2
        disenio.crearFilaEjec(fil,pro)
        fil=fil+2
    fil=procesos[len(procesos)-1].filT+3
    disenio.contador(fil)
    disenio.marcoEjec((len(procesos)*2)+7,maxDur+47,maxDur)
    for pro in procesos:
        print(Cursor.POS(pro.colB,pro.filB-1)+Fore.WHITE+Style.BRIGHT+pro.id)
    datos.ejecucion(procesos,maxDur,fil)
    print(Cursor.POS(45,fil+2)+Fore.WHITE+Style.BRIGHT+"Presione enter para continuar (se limpiarán todos los procesos)",end="")
    input()
    reinicio(fil+3)

def reinicio(fil):
    disenio.limpiarPantalla(fil)
    disenio.cabeceraDatos()
    print(Cursor.POS(32,6)+Fore.WHITE+Style.BRIGHT+"Procesos restantes:")

if __name__=='__main__':
    main()
