class Nodo:
    def __init__(self):
        self.info = None
        self.siguiente = None

    def getInfo(self):
        return self.info

    def getSiguiente(self):
        return self.siguiente

    def setInfo(self, i):#i = entero
        self.info = i

    def setSiguiente(self, s):
        self.siguiente = s
