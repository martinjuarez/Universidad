#Proyecto final
import pygame, sys
from pygame.locals import *

ancho = 1300
alto = 650
listaEnemigo = []


class Marco(pygame.sprite.Sprite):
	
	def __init__(self):
		pygame.sprite.Sprite.__init__(self)
	
		self.ImagenMarco = pygame.image.load("marco.png")
		self.ImagenMuerte = pygame.image.load("muerte.png")
		
		self.rect = self.ImagenMarco.get_rect()
		self.rect.centerx = ancho/2
		self.rect.centery = alto-50
		
		self.listaDisparo = []
		
		self.vida = True
		self.ganador = 0
		self.velocidad = 20
		
		self.sonidoMuerte = pygame.mixer.Sound("Fuckyou.wav")
		
	def movimientoDerecha(self):
			self.rect.right += self.velocidad
			self.__movimiento()
			
	def movimientoIzquierda(self):
			self.rect.left -= self.velocidad
			self.__movimiento()
			
		
	
	def __movimiento(self):
		if self.vida == True:
			if self.rect.left <=0:
				self.rect.left = 0
			elif self.rect.right > 1270:
				self.rect.right = 1240
				
	def disparar(self, x, y):
		miProyectil = Proyectil(x,y)
		self.listaDisparo.append(miProyectil)
		
	def detruccion(self):
		self.sonidoMuerte.play(0)
		self.vida = False
		self.velocidad = 0
		self.ImagenMarco = self.ImagenMuerte
	
	def dibujar(self, superficie):
		superficie.blit(self.ImagenMarco, self.rect)
	
class Proyectil(pygame.sprite.Sprite):
	def __init__(self, posx, posy):
		pygame.sprite.Sprite.__init__(self)
		
		self.imageProyectil = pygame.image.load("bala.jpg")
		
		self.rect = self.imageProyectil.get_rect()
		
		self.velocidadDisparo = 5
		
		self.rect.top = posy
		self.rect.left = posx
	def trayectoria(self):
		self.rect.top = self.rect.top - self.velocidadDisparo
		
	def dibujar(self, superficie):
		superficie.blit(self.imageProyectil, self.rect)

class Basura(pygame.sprite.Sprite):
	def __init__(self, posx, posy,distancia, imagenUno,imagenDos):
		pygame.sprite.Sprite.__init__(self)	
		self.imagenA = pygame.image.load(imagenUno)
		self.imagenB = pygame.image.load(imagenDos)
		
		self.rect = self.imagenA.get_rect()
		self.velocidad = 20
		self.rect.top = posy
		self.rect.left = posx
		self.conquista = False
		self.derecha = True
		self.contador = 0
		self.Maxdescenso = self.rect.top + 40
		self.limiteDerecha = posx + distancia
		self.limiteIzquierda = posx - distancia
	
	def dibujar(self, superficie):
		superficie.blit(self.imagenA, self.rect)
	
	def comportamiento(self):
		if self.conquista == False:
			self.__movimientos()
	
		
	
	def __movimientos(self):
		if self.contador <3:
			self.__movimientoLateral()
		else:
			self.__descenso()
	
	def __descenso(self):
		if self.Maxdescenso == self.rect.top:
			self.contador=0
			self.Maxdescenso = self.rect.top + 40
		else:
			self.rect.top += 1	
				
	
	def __movimientoLateral(self):
		if self.derecha == True:
			self.rect.left = self.rect.left+ self.velocidad
			if self.rect.left > self.limiteDerecha:
				self.derecha = False
				
				self.contador +=1
		else:
			self.rect.left = self.rect.left - self.velocidad
			if self.rect.left <self.limiteIzquierda:
				self.derecha = True

def detenerTodo():
	for enemigo in listaEnemigo:
		enemigo.conquista = True
		
def cargarEnemigos():
	enemigo = Basura(0,0,1000,"basuraA.png","basuraA.png")
	listaEnemigo.append(enemigo)
	enemigo = Basura(600,0,1000,"basuraA.png","basuraA.png")
	listaEnemigo.append(enemigo)
	enemigo = Basura(1200,0,1000,"basuraA.png","basuraA.png")
	listaEnemigo.append(enemigo)
	enemigo = Basura(1800,0,1000,"basuraA.png","basuraA.png")
	listaEnemigo.append(enemigo)
	enemigo = Basura(300,200,1000,"basuraB.png","basuraB.png")
	listaEnemigo.append(enemigo)
	enemigo = Basura(900,200,1000,"basuraB.png","basuraB.png")
	listaEnemigo.append(enemigo)
	enemigo = Basura(1500,200,1000,"basuraB.png","basuraB.png")
	listaEnemigo.append(enemigo)
	enemigo = Basura(0,350,1000,"basuraC.png","basuraC.png")
	listaEnemigo.append(enemigo)
	enemigo = Basura(600,350,1000,"basuraC.png","basuraC.png")
	listaEnemigo.append(enemigo)
	enemigo = Basura(1200,350,1000,"basuraC.png","basuraC.png")
	listaEnemigo.append(enemigo)
	enemigo = Basura(1800,350,1000,"basuraC.png","basuraC.png")
	listaEnemigo.append(enemigo)
		
def Exterminador_de_basura(): 
	pygame.init()
	venta = pygame.display.set_mode((ancho,alto))
	pygame.display.set_caption("Exterminador de basura")

	ImagenFondo = pygame.image.load("ciudad.jpg")

	pygame.mixer.music.load("Zz Top - La Grange.mp3")
	pygame.mixer.music.play(3)
	
	miFuenteSistema = pygame.font.SysFont("Arial",30)
	Texto = miFuenteSistema.render("Fin del Juego",0,(120,120,40))

	jugador = Marco()

	cargarEnemigos()
		
	enJuego = True


	reloj= pygame.time.Clock()
	while True:
		


		reloj.tick(60)
		
		#jugador.movimiento()
		
		tiempo = pygame.time.get_ticks()/1000
		for event in pygame.event.get():
			if event.type == QUIT:
				pygame.quit()
				sys.exit()
				
			if enJuego == True:
				if event.type == pygame.KEYDOWN:
					if event.key == K_LEFT:
						jugador.movimientoIzquierda()
					elif event.key == K_RIGHT:
						jugador.movimientoDerecha()
					elif event.key == K_m:
						x,y = jugador.rect.center
						jugador.disparar(x,y)
		
		venta.blit(ImagenFondo, (0,0))
		
		
		jugador.dibujar(venta)
		
		if len(listaEnemigo)>0:
			for enemigo in listaEnemigo:
				enemigo.comportamiento()
				enemigo.dibujar(venta)
				
				if enemigo.rect.colliderect(jugador.rect):
					jugador.detruccion()
					enJuego = False
					detenerTodo()		
		
		if len(jugador.listaDisparo)>0:
			for x in jugador.listaDisparo:
				x.dibujar(venta)
				x.trayectoria()
				
				if x.rect.top < -10:
					jugador.listaDisparo.remove(x)
				else:
					for enemigo in listaEnemigo:
						if x.rect.colliderect(enemigo.rect):
							listaEnemigo.remove(enemigo)
							jugador.listaDisparo.remove(x)
							jugador.ganador = jugador.ganador + 1
							if jugador.ganador == 11:
								enJuego = False
								
		
		if enJuego == False:
			pygame.mixer.music.fadeout(3000)
			venta.blit(Texto,(300,300))
		
		pygame.display.update()
		
Exterminador_de_basura()
