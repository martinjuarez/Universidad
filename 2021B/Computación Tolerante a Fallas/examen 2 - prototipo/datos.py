import re
import random
from simulador import simulacion

class RegDatos():
    def __init__(self):
        super(RegDatos,self).__init__()
        self.tope=0
        self.cont=0
        self.miLista=[]
    
    def setTope(self,valor):
        self.tope=valor
    
    def registrar(self):
        i=0
        print()
        while(i<self.tope):
            self.registro()
            print()
            i+=1
        
        print("--------------Procesos Registrados---------------")
        self.imprimirRegistro()
        self.ventanaSimulacion()
    
    def registro(self):
        print("inicio:")
        inicio=input()
        bandera=self.validaInput(inicio)
        while(bandera==1):
            print("\nError - Debes escribir un numero entero")
            print("inicio:")
            inicio=input()
            bandera=self.validaInput(inicio)

        print("duracion:")
        duracion=input()
        bandera=self.validaInput(duracion)
        
        while(bandera==1):
            print("\nError - Debes escribir un numero entero")
            print("duracion:")
            duracion=input()
            bandera=self.validaInput(duracion)
            
        iden=len(self.miLista)+1
        fin=int(inicio)+int(duracion)
        self.miLista.append({"id":iden,"inicio":int(inicio),"duracion":0,"fin":fin,"tt":int(inicio),"terminado":False})

    def validaInput(self,valor):
        patron=re.compile(r'^\d+$')

        resultado=re.match(patron,valor)

        if(resultado is not None):
            return 0
        return 1
    
    def Generador(self):
        i=0
        while(i<self.tope):
            inicio=random.randint(0,20)
            duracion=random.randint(10,50)
            iden=len(self.miLista)+1
            self.miLista.append({"id":iden,"inicio":inicio,"duracion":0,"fin":inicio+duracion,"tt":inicio,"terminado":False})
            i+=1
        
        print("--------------Procesos Generados---------------")
        self.imprimirRegistro()
        self.ventanaSimulacion()
        
    def ventanaSimulacion(self):
        sim=simulacion()
        sim.setProcesos(self.miLista)
        sim.Inicio()
        
    def imprimirRegistro(self):
        for elem in self.miLista:
            print("{:<10} {:<10}".format(elem["inicio"],elem["fin"]-elem["inicio"]))
        



        
