from datos import RegDatos
import time

def main():
    reg = RegDatos()
    bandera = 0
    print("---------menu---------")
    print("1.Registrar Procesos")
    print("2.Generar Procesos")
    print(">",end="")
    op=input()
    
    bandera=reg.validaInput(op)
    
    if(bandera==1):
        main()
    else:
        opc=int(op)
    if(opc>2):
        main()
    

    if(opc==1):
        print("\nIngresa la cantidad de procesos que deseas registrar")
        print(">",end="")
        tope=input()
        bandera=reg.validaInput(tope)

        while(bandera==1):
            print("\nError - Debes escribir un numero entero")
            print("Ingresa la cantidad de procesos que deseas registrar")
            print(">",end="")
            tope=input()
            bandera=reg.validaInput(tope)
        
        reg.setTope(int(tope))
        reg.registrar()

    elif(opc==2):
        print("\nIngresa la cantidad de procesos que deseas generar")
        print(">",end="")
        tope=input()
        bandera=reg.validaInput(tope)

        while(bandera==1):
            print("\nError - Debes escribir un numero entero")
            print("Ingresa la cantidad de procesos que deseas generar")
            print(">",end="")
            tope=input()
            bandera=reg.validaInput(tope)
        
        reg.setTope(int(tope))
        reg.Generador()


if __name__=='__main__':
    main()
    
    '''i=600
    time.sleep(0.5)
    print(chr(9924))
    print(chr(9607))    
    while(i<650):
        print(i,chr(i))
        i+=1
        time.sleep(0.5)'''

