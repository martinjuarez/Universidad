# -*- coding: utf-8 -*-
"""
Created on Thu Mar 18 10:57:02 2021

@author: marti
"""

#Comenzamos importando los módulos necesarios para graficar y el módulo numpy
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm

#Creamos una figura
fig = plt.figure()
#Definimos los ejes para que sean una proyección 3d
ax = fig.gca(projection = '3d')

#Generamos el rango para la función según los valores indicados por la función. Como tercer parámetro definimos cada cuanto queremos que haya un punto, mientras más pequeño el valor más fina la gráfica.
#Para graficar en volumen necesitamos dos dimensiones x, y 
X = np.arange(-5.12, 5.12, 0.1)
Y = np.arange(-5.12, 5.12, 0.1)
#Generamos una maya con los valores de x, y
X, Y = np.meshgrid(X, Y)
#Calculamos el valor de la altura (la tercer dimensión) según lo descrito por la función esfera, es decir la suma del cuadrado de cada dimensión
Z = X**2 + Y**2

#Creamos la superficie a graficar
surf = ax.plot_surface(X, Y, Z, cmap = cm.coolwarm, linewidth = 1)
#Agregamos una barra de color como indicativo de los valores en la función
fig.colorbar(surf)

#Graficamos el resultado
plt.show()

#Creamos una figura
fig = plt.figure()
#Definimos los ejes para que sean una proyección 3d
ax = fig.gca(projection = '3d')

#Generamos el rango para la función según los valores indicados por la función. Como tercer parámetro definimos cada cuanto queremos que haya un punto, mientras más pequeño el valor más fina la gráfica.
#Para graficar en volumen necesitamos dos dimensiones x, y 
X = np.arange(-2.048, 2.048, 0.1)
Y = np.arange(-2.048, 2.048, 0.1)
#Generamos una maya con los valores de x, y
X, Y = np.meshgrid(X, Y)
#Calculamos el valor de la altura (la tercer dimensión) según lo descrito por la función esfera, es decir la suma del cuadrado de cada dimensión
Z = 100 * (Y - X**2)**2 + (X - 1)**2

#Creamos la superficie a graficar
surf = ax.plot_surface(X, Y, Z, cmap = cm.coolwarm, linewidth = 1)
#Agregamos una barra de color como indicativo de los valores en la función
fig.colorbar(surf)

#Graficamos el resultado
plt.show()

#Creamos una figura
fig = plt.figure()
#Definimos los ejes para que sean una proyección 3d
ax = fig.gca(projection = '3d')

#Generamos el rango para la función según los valores indicados por la función. Como tercer parámetro definimos cada cuanto queremos que haya un punto, mientras más pequeño el valor más fina la gráfica.
#Para graficar en volumen necesitamos dos dimensiones x, y 
X = np.arange(-5.12, 5.12, 0.1)
Y = np.arange(-5.12, 5.12, 0.1)
#Generamos una maya con los valores de x, y
X, Y = np.meshgrid(X, Y)
#Calculamos el valor de la altura (la tercer dimensión) según lo descrito por la función esfera, es decir la suma del cuadrado de cada dimensión
Z = X**2 - 10 * np.cos(2 * np.pi * X) + Y**2 - 10 * np.cos(2 * np.pi * Y) + 10

#Creamos la superficie a graficar
surf = ax.plot_surface(X, Y, Z, cmap = cm.coolwarm, linewidth = 1)
#Agregamos una barra de color como indicativo de los valores en la función
fig.colorbar(surf)

#Graficamos el resultado
plt.show()

#Creamos una figura
fig = plt.figure()
#Definimos los ejes para que sean una proyección 3d
ax = fig.gca(projection = '3d')

#Generamos el rango para la función según los valores indicados por la función. Como tercer parámetro definimos cada cuanto queremos que haya un punto, mientras más pequeño el valor más fina la gráfica.
#Para graficar en volumen necesitamos dos dimensiones x, y 
X = np.arange(-1.28, +1.28, 0.1)
Y = np.arange(-1.28, +1.28, 0.1)
#Generamos una maya con los valores de x, y
X, Y = np.meshgrid(X, Y)
#Calculamos el valor de la altura (la tercer dimensión) según lo descrito por la función esfera, es decir la suma del cuadrado de cada dimensión
Z = 1 * X**4 + 2 * Y**4

#Creamos la superficie a graficar
surf = ax.plot_surface(X, Y, Z, cmap = cm.coolwarm, linewidth = 1)
#Agregamos una barra de color como indicativo de los valores en la función
fig.colorbar(surf)

#Graficamos el resultado
plt.show()