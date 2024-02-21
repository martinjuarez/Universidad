import time
import os

class simulacion():
    def __init__(self):
        super(simulacion,self).__init__()
        self.procesos=[]
        self.contG=0
        self.lon=0
    
    def setProcesos(self,lista):
        self.procesos=list(lista)
        self.lon=len(lista)
            
    def Inicio(self):
        time.sleep(1)
        os.system ("cls")
        ultimo=False
        
        while(self.lon!=0):
            self.imprimir_tabla()
            self.imprimir_regla()
            #print("\nContador:",self.contG,"\n")
            
            for elem in self.procesos:
                inicio=elem["inicio"]
                fin=elem["fin"]
                tt=int(elem["tt"])
                du=int(elem["duracion"])
                
                if(self.contG>=inicio):
                    for i in range (tt):
                        if(i<inicio):
                            print(' ',end='')
                        else:
                            #print('.',end='')
                            print(chr(9607),end='')
                    print(tt)
                    
                    if(elem["terminado"]==False):
                        tt+=1
                        du+=1
                        elem["tt"]=tt
                        elem["duracion"]=du

                    if(tt==fin):
                        if(elem["terminado"]==False):
                            self.lon-=1
                        elem["terminado"]=True
                else:
                    print()
                    
            self.contG+=1
            time.sleep(0.5)
            
            
            if(ultimo==True):
                input()
                break
                
            if(self.lon==0):
                ultimo=True
                self.lon=1
                
            os.system ("cls")
            
    def imprimir_tabla(self):
        print("{:<20}{:<20}{:<20}{:<10}contador:{:<10}".format("Datos de los Procesos"," ","informacion adicional","",self.contG))
        print("{:<10}{:<10}{:<10} {:<10}{:<10}{:<20}".format("proceso","inicio","duracion"," ","proceso","tiempo"))

        for elem in self.procesos:
            if(elem["tt"]!=elem["inicio"]):
                print("{:<10}{:<10}{:<10} {:10}{:<10}{:<20}".format(elem["id"],elem["inicio"],elem["fin"]-elem["inicio"]," ",elem["id"],elem["duracion"]))
            else:
                print("{:<10}{:<10}{:<10} {:10}{:<10}{:<20}".format(elem["id"],elem["inicio"],elem["fin"]-elem["inicio"]," ",elem["id"]," "))

    def imprimir_regla(self):
        print('\n')
        
        for i in range(98):
            if((i%50)== 0):
                print(i,end='')
            else:
                print(' ',end='')
        print("100")

        for i in range(99):
            if((i%50)== 0):
                print('v',end='')
            else:
                print('.',end='')
        print("v\n")
        

