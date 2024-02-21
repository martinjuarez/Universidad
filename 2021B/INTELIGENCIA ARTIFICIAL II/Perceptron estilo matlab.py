# -*- coding: utf-8 -*-
"""
Created on Thu Nov 11 12:44:40 2021

@author: marti
"""
import numpy as np
import random
#Patron de aprendizaje y objetivos
entradas_equis = np.array([[0,0], [0,1], [1,0], [1,1]])
salidas_deseadas = np.array([-1,1,1,-1]) 
numero_entradas = len(entradas_equis)
print("Entradas =", entradas_equis)
print("Salidas_d =",salidas_deseadas)
print("Longitud =", numero_entradas)

neuronas_capa_oculta = 2
rango_pesos = 1


peso_w_1 = rango_pesos*(2*np.random.rand(neuronas_capa_oculta,2)-1)
theta_1 = rango_pesos*(2*np.random.rand(neuronas_capa_oculta,1)-1)
peso_w_2 = rango_pesos*(2*np.random.rand(1,neuronas_capa_oculta)-1)
theta_2 = rango_pesos*(2*random.random()-1)
print(peso_w_2)
alfa = 0.001

for epocas in range(10000):
    print("")