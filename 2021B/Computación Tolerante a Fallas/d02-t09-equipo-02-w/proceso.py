class Proceso:
    def __init__(self,idP,inicio,duracion,colT,filT,barra):
        self.id=idP
        self.inicio=inicio
        self.duracion=duracion
        self.tt=0
        self.colT=colT
        self.filT=filT
        self.colB=46+inicio
        self.filB=filT
        self.colorB=barra

    def __gt__(self,pro):
        return self.inicio>pro.inicio
