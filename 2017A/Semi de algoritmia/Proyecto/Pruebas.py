from Tkinter import *

v0=Tk()
v0.geometry("200x60")

def cambiar_stringvar(nuevotexto,stringvar):
	stringvar.set(nuevotexto)

salida=StringVar()
cadena=StringVar()
entry1=Entry(v0,textvar=cadena).pack()
label1=Label(v0,textvar=salida).pack()
b1=Button(v0,text="Escribir",command=lambda: cambiar_stringvar(cadena.get(),salida)).pack()

v0.mainloop()
