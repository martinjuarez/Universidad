# -*- coding: utf-8 -*-
"""
Created on Sun Mar 14 12:59:21 2021

@author: marti
"""

#importamos módulos para operaciones numéricas y para graficar
import numpy as np
import matplotlib.pyplot as plt

#definimos el polinomio que se desea resolver.
#el polinomio se escribe con el mayor exponente al inicio, en este caso x³
#polinomio = [1, -4, 1, 6]
polinomio = [2, 9, 12, -13]
#convertimos a un objeto polinomial y resolvemos
poly = np.poly1d(polinomio)
primer_derivada = np.polyder(poly, 1)
segunda_derivada = np.polyder(poly, 2)
raices = np.roots(primer_derivada)
valores = np.polyval(poly, raices) #evaluamos el polinomio en las raíces
valores2d = np.polyval(segunda_derivada, raices) #evaluamos la seunda derivada en las raíces

#rango para x
mayor = np.max(raices) + 0.5 
menor = np.min(raices) - 0.5
#100 puntos en x para evaluar
x = np.linspace(menor, mayor, 100)
#valores de en la función
y = np.polyval(poly, x)

#mostramos la gráfica
plt.title("x^3-4x^2+x+6")
plt.plot(x, y, 'r')
plt.plot(raices, valores, '*g')
if valores2d[0] > 0:
    plt.text(raices[0],valores[0] ,"Minimo(" + str(raices[0]) + ',' + str(valores[0]))
else:
    plt.text(raices[0],valores[0] ,"Maximo(" + str(raices[0]) + ',' + str(valores[0]))
if valores2d[1] > 0:
    plt.text(raices[1],valores[1] ,"Minimo(" + str(raices[1]) + ',' + str(valores[1]))
else:
    plt.text(raices[1],valores[1] ,"Maximo(" + str(raices[1]) + ',' + str(valores[1]))    
plt.show()

#definimos el polinomio que se desea resolver.
#el polinomio se escribe con el mayor exponente al inicio, en este caso x³
polinomio = [6, -12, 5, -2]
#convertimos a un objeto polinomial y resolvemos
poly = np.poly1d(polinomio)
primer_derivada = np.polyder(poly, 1)
segunda_derivada = np.polyder(poly, 2)
raices = np.roots(primer_derivada)
valores = np.polyval(poly, raices) #evaluamos el polinomio en las raíces
valores2d = np.polyval(segunda_derivada, raices) #evaluamos la seunda derivada en las raíces

#rango para x
mayor = np.max(raices) + 0.5 
menor = np.min(raices) - 0.5
#100 puntos en x para evaluar
x = np.linspace(menor, mayor, 100)
#valores de en la función
y = np.polyval(poly, x)

#mostramos la gráfica
plt.title("6x^3-12x^2+5x-2")
plt.plot(x, y, 'r')
plt.plot(raices, valores, '*g')
if valores2d[0] > 0:
    plt.text(raices[0],valores[0] ,"Minimo(" + str(raices[0]) + ',' + str(valores[0]))
else:
    plt.text(raices[0],valores[0] ,"Maximo(" + str(raices[0]) + ',' + str(valores[0]))
if valores2d[1] > 0:
    plt.text(raices[1],valores[1] ,"Minimo(" + str(raices[1]) + ',' + str(valores[1]))
else:
    plt.text(raices[1],valores[1] ,"Maximo(" + str(raices[1]) + ',' + str(valores[1]))
plt.show()

#definimos el polinomio que se desea resolver.
#el polinomio se escribe con el mayor exponente al inicio, en este caso x³
polinomio = [1/3, 8, 63, 7]
#convertimos a un objeto polinomial y resolvemos
poly = np.poly1d(polinomio)
primer_derivada = np.polyder(poly, 1)
segunda_derivada = np.polyder(poly, 2)
raices = np.roots(primer_derivada)
valores = np.polyval(poly, raices) #evaluamos el polinomio en las raíces
valores2d = np.polyval(segunda_derivada, raices) #evaluamos la seunda derivada en las raíces

#rango para x
mayor = np.max(raices) + 0.5 
menor = np.min(raices) - 0.5
#100 puntos en x para evaluar
x = np.linspace(menor, mayor, 100)
#valores de en la función
y = np.polyval(poly, x)

#mostramos la gráfica
plt.title("(1/3)x^3+8x^2+63x+7")
plt.plot(x, y, 'r')
plt.plot(raices, valores, '*g')
if valores2d[0] > 0:
    plt.text(raices[0],valores[0] ,"Minimo(" + str(raices[0]) + ',' + str(valores[0]))
else:
    plt.text(raices[0],valores[0] ,"Maximo(" + str(raices[0]) + ',' + str(valores[0]))
if valores2d[1] > 0:
    plt.text(raices[1],valores[1] ,"Minimo(" + str(raices[1]) + ',' + str(valores[1]))
else:
    plt.text(raices[1],valores[1] ,"Maximo(" + str(raices[1]) + ',' + str(valores[1])) 
plt.show()