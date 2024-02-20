import time	# Importa el modulo tiempo
from Tkinter import *	# Importa el modulo
import os
ven = Tk()	# Tk() Es la ventana principal
ven2 = Toplevel(ven)	# Crea una ventana hija
ven3 = Toplevel(ven)	# crea una ventana hija
ven4 = Toplevel(ven)	# crea una ventana hija
ven5 = Toplevel(ven)	# crea una ventana hija
def ocultar(ventana):	#oculta una ventana
	ventana.withdraw() 
def mostrar(ventana):	#muestra una ventana
	ventana.deiconify()
def ejecutar(f):	# Una forma de ejecutar las funciones
	ven.after(200,f) 
def salida(event):
	print(codigo_entry.get())
def imprimir_fecha():
	return str(time.localtime()[2]) + "/" + str(time.localtime()[1]) + "/" + str(time.localtime()[0]) + ", " + str(time.localtime()[3]) + ":" + str(time.localtime()[4]) + ":" + str(time.localtime()[5])		
def recuperar():
	codigo = 0
	archivo = open("archivo.txt","w")
	archivo.close
	archivo = open("archivo.txt","r")
	cont = 1
	suma = 0
	flag = False 
	linea=archivo.readline()
	while linea != '':
		if cont != 6:
			linea=archivo.readline()
			cont = cont + 1
		if cont == 6:
			codigo=linea
			linea=archivo.readline()
			cont = cont + 1
		if cont == 7:
			linea=archivo.readline()
			cont = 1
			suma = suma + 1
	archivo.close()
	registro = int(codigo) - (int(codigo)-suma) 
	return registro
def guardar_materias(codigo,materia1,materia2,materia3,materia4,materia5,materia6):
	archivo = open("materias.txt","a")
	archivo.write(codigo)
	archivo.write(materia1+"\n")
	archivo.write(materia2+"\n")
	archivo.write(materia3+"\n")
	archivo.write(materia4+"\n")
	archivo.write(materia5+"\n")
	archivo.write(materia6+"\n")
	archivo.close
	
def menu_agendar(nombre,apellidoP,apellidoM,carrera,grado,codigo):
	nombre_label = Label(ven3,text = "	Nombre: ",bg = 'yellow')
	nombre_label.grid(row = 1,column = 1)
	nombre_label = Label(ven3,text = nombre ,bg = 'blue')
	nombre_label.grid(row = 1,column = 2)
	apellidoP_label = Label(ven3,text = " Apellido Paterno: ",bg = 'yellow')
	apellidoP_label.grid(row = 2,column = 1)
	apellidoP_label = Label(ven3,text = apellidoP ,bg = 'blue')
	apellidoP_label.grid(row = 2,column = 2)
	apellidoM_label = Label(ven3,text = " Apellido Materno: ",bg = 'yellow')
	apellidoM_label.grid(row = 3,column = 1)
	apellidoM_label = Label(ven3,text = apellidoM ,bg = 'blue')
	apellidoM_label.grid(row = 3,column = 2)
	carrera_label = Label(ven3,text = "	  Carrera: ",bg = 'yellow')
	carrera_label.grid(row = 4, column = 1)
	carrera_label = Label(ven3,text = carrera ,bg = 'blue')
	carrera_label.grid(row = 4, column = 2)
	grado_label = Label(ven3,text = "	  Grado: ",bg = 'yellow')
	grado_label.grid(row = 5, column = 1)
	grado_label = Label(ven3,text = grado,bg = 'blue')
	grado_label.grid(row = 5, column = 2)
	codigo_label = Label(ven3,text = "	  Codigo: ",bg = 'yellow')
	codigo_label.grid(row = 6,column = 1)
	codigo_label = Label(ven3,text = codigo ,bg = 'blue')
	codigo_label.grid(row = 6,column = 2)
	salide=Button(ven3,text = "Salir",relief = FLAT, command = lambda: ven.destroy())
	salide.grid(row = 7,column = 1)
	if carrera == "Computacion\n":
		Malla=Button(ven3,text = "Malla curricular inco",relief = FLAT, command = lambda: ejecutar(mostrar(ven4)))
		Malla.grid(row = 7,column = 2)
	if carrera == "Informatica\n":
		Malla1=Button(ven3,text = "Malla curricular info",relief = FLAT, command = lambda: ejecutar(mostrar(ven5)))
		Malla1.grid(row = 7,column = 2)
	
	Malla=Button(ven4,text = "Salir",relief = FLAT, command = lambda: ejecutar(ocultar(ven4)))
	Malla.grid(row = 1,column = 1)
	def cambiar_stringvar(nuevotexto,stringvar):
		stringvar.set(nuevotexto)
	mitexto=StringVar()
	textoentry=StringVar()
	entry1=Entry(ven3,textvar=textoentry)
	entry1.grid(row=2, column= 3)
	mitexto2=StringVar()
	textoentry2=StringVar()
	entry1=Entry(ven3,textvar=textoentry2)
	entry1.grid(row=2, column= 5)
	mitexto3=StringVar()
	textoentry3=StringVar()
	entry1=Entry(ven3,textvar=textoentry3)
	entry1.grid(row=2, column= 7)
	mitexto4=StringVar()
	textoentry4=StringVar()
	entry1=Entry(ven3,textvar=textoentry4)
	entry1.grid(row=5, column= 3)
	mitexto5=StringVar()
	textoentry5=StringVar()
	entry1=Entry(ven3,textvar=textoentry5)
	entry1.grid(row=5, column= 5)
	mitexto6=StringVar()
	textoentry6=StringVar()
	entry1=Entry(ven3,textvar=textoentry6)
	entry1.grid(row=5, column= 7)
	g = Button(ven3,text = "Guardar",relief = FLAT, command = lambda: guardar_materias(codigo,textoentry.get(),textoentry2.get(),textoentry3.get(),textoentry4.get(),textoentry5.get(),textoentry6.get()))
	g.grid(row = 9,column = 5)
	
def guardar():
	if os.stat("archivo.txt").st_size == 0:
		registro = 0
	else:
		registro = recuperar()
	codigo = str(registro)+str(time.localtime()[0])
	archivo = open("archivo.txt","a")
	archivo.write(nombre_entry.get()+"\n")
	archivo.write(apellidoP_entry.get()+"\n")
	archivo.write(apellidoM_entry.get()+"\n")
	archivo.write(carrera_str.get()+"\n")
	archivo.write("1\n")
	archivo.write(codigo+"\n")
	archivo.write(nip_entry2.get()+"\n")
	archivo.close
	registro = registro + 1
def validacion():
	key=codigo_entry.get()+"\n"
	key2=nip_entry.get()+"\n"
	print "Codigo recibido:",key
	print "Nip recibido:",key2
	archivo = open("archivo.txt","r")
	door = False
	door2 = False
	cont = 1
	linea=archivo.readline()
	while linea != '' and door == False:
		if cont == 1:
			nombre=linea
			linea=archivo.readline()
			cont = cont + 1
		if cont == 2:
			apellidoP=linea
			linea=archivo.readline()
			cont = cont + 1
		if cont == 3:
			apellidoM=linea
			linea=archivo.readline()
			cont = cont + 1
		if cont == 4:
			carrera=linea
			linea=archivo.readline()
			cont = cont + 1
		if cont == 5:
			grado=linea
			linea=archivo.readline()
			cont = cont + 1
		if cont == 6:
			codigo=linea
			linea=archivo.readline()
			if codigo == key:
				door = True
				print "exito!"
			cont = cont + 1
			print "codigo:",codigo
		if cont == 7:
			linea=archivo.readline()
			cont = 1
			print "endline"
	archivo.close()
	archivo = open("archivo.txt","r")
	cont = 1
	linea=archivo.readline()
	while linea != '' and door2 == False:
		if cont != 7:
			cont = cont + 1
			linea=archivo.readline()
		if cont == 7:
			nip=linea
			print "Nip:",nip
			linea=archivo.readline()
			if nip == key2:
				door2 = True
				print "exito!!"
			cont = 1
		print "endline"
	archivo.close()
	if door == True and door2 == True:
		print "Exito"
		menu_agendar(nombre,apellidoP,apellidoM,carrera,grado,codigo)
	else:
		error_label=Label(ven3,text="Error uno de los espacios requeridos esta en blanco o esta mal escrito",bg='yellow')
		error_label.grid(row=5,column=1)
		print "Fallo"
ven.title('Proyecto Menu siiau')	# Le da el titulo a la ventana
ven2.title('Proyecto Registro siiau')
ven3.title('Proyecto Siiau')
ven4.title('Malla curricular')
ven5.title('Malla curricular')
ven.config(bg = "blue")	# Le da color al fondo
ven2.config(bg = "blue")
ven3.config(bg = "blue")
ven4.config(bg = "blue")
ven5.config(bg = "blue")
ven.geometry("250x100")	# Cambia el tamano de la ventana
ven2.geometry("500x500")
ven3.geometry("1000x400")
ven4.geometry("4000x2133")
ven5.geometry("4000x2133")
#Malla curricular inco
imagen=PhotoImage(file="Malla-Computacion.gif")
imagen_label=Label(ven4,image=imagen).place(x=0,y=0)
#Malla curricular info
imagen1=PhotoImage(file="malla_inni_2017a.gif")
imagen1_label= Label(ven5,image=imagen1).place(x=0,y=0) 
# Codigo
codigo_label = Label(ven,text = "Codigo: ",bg = 'blue')
codigo_label.grid(row = 1,column = 1)
codigo_str = StringVar()
codigo_entry = Entry(ven,textvariable = codigo_str)
codigo_entry.grid(row = 1,column = 2)
"""codigo_entry.bind('<Key-Return>', salida)"""
# Codigo_Registro
def actualizar():
	if os.stat("archivo.txt").st_size == 0:
		registro = 0
	else:
		registro = recuperar()
	codigo = str(registro)+str(time.localtime()[0])
	codigo_label2 = Label(ven2,text = "Codigo: ",bg = 'blue')
	codigo_label2.grid(row = 6, column = 1)
	codigo2_label2 = Label(ven2,text = codigo ,bg = 'blue')
	codigo2_label2.grid(row = 6, column = 2)
# Nip_Incial 
nip_label= Label(ven,text = "       Nip: ",bg = 'blue')
nip_label.grid(row = 2,column = 1)
nip_str = StringVar()
nip_entry = Entry(ven,textvariable = nip_str)
nip_entry.grid(row = 2,column = 2)
# ingresar
finish = Button(text = "Ingresar",relief = FLAT, command = lambda: ejecutar(ocultar(ven)) or ejecutar(mostrar(ven3)) or validacion())  
finish.grid(row = 3,column = 1)
# Registrar
nuevo = Button(text = "Registrar",relief = FLAT, command = lambda: ejecutar(ocultar(ven)) or ejecutar(mostrar(ven2)) or ejecutar(actualizar()))
nuevo.grid(row = 3,column = 2)
adios = Button(text = "Salir",relief = FLAT, command = lambda: ven.destroy())
adios.grid(row = 3,column = 4)
# Nombre
nombre_str = StringVar()
nombre_label = Label(ven2,text = "	Nombre: ",bg = 'blue')
nombre_label.grid(row = 1,column = 1)
nombre_entry = Entry(ven2,textvariable = nombre_str)
nombre_entry.grid(row = 1,column = 2)
# Apellido Paterno
apellidoP_label = Label(ven2,text = " Apellido Paterno: ",bg = 'blue')
apellidoP_label.grid(row = 2,column = 1)
apellidoP_str = StringVar()
apellidoP_entry = Entry(ven2,textvariable = apellidoP_str)
apellidoP_entry.grid(row = 2,column = 2)
# Apellido Materno
apellidoM_label = Label(ven2,text = "Apellido Materno: ",bg = 'blue')
apellidoM_label.grid(row = 3,column = 1)
apellidoM_str = StringVar()
apellidoM_entry = Entry(ven2,textvariable = apellidoM_str)
apellidoM_entry.grid(row = 3,column = 2)
# Carrera
carrera_label = Label(ven2,text = "	  Carrera: ",bg = 'blue')
carrera_label.grid(row = 4, column = 1)
carrera_str = StringVar()
boton = OptionMenu(ven2, carrera_str, 'Computacion', 'Informatica')
boton.grid(row = 4, column = 2)
# Nip_Registro
nip_label = Label(ven2,text = "	        Nip: ",bg = 'blue')
nip_label.grid(row = 5,column = 1)
nip_str = StringVar()
nip_entry2 = Entry(ven2,textvariable = nip_str)
nip_entry2.grid(row = 5,column = 2)
# Guardar y salir
gs = Button(ven2,text = "Guardar y salir",relief = FLAT, command = lambda: ejecutar(mostrar(ven)) or ejecutar(ocultar(ven2)) or guardar())  
gs.grid(row = 7,column = 2)

print imprimir_fecha()
ven2.withdraw()
ven3.withdraw()
ven4.withdraw()
ven5.withdraw()
recuperar()
ven.mainloop()	# Es el evento que llama al inicio de nuestro programa. Siempre lo lleva la ventana principal.
