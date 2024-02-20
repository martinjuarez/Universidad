from Nodo import Nodo

class Lista:
    def __init__(self):
        self.primero = Nodo()

    def getPrimero(self):
        return self.primero

    def setPrimero(self, p):#p  de tipo Nodo
        self.primero = p

    def insertarInicio(self, ele):
        if self.primero.getInfo() == None:
            self.primero.setInfo(ele)
        else:
            temp = Nodo()
            temp.setInfo(ele)
            temp.setSiguiente(self.primero)
            self.primero = temp

    def insertarFinal(self):
        temp = Nodo()
        obj = Nodo()

        obj.info = input("Ingrese algo: ")

        if self.primero != None:
            temp = self.primero
            while temp.getSiguiente() != None:
                temp = temp.getSiguiente()
            temp.setSiguiente(obj)
        else:
            self.primero = obj

    def imprimir(self):
        temp = Nodo()
        temp = self.primero

        while temp != None:
            print(temp.getInfo())
            temp = temp.getSiguiente()
