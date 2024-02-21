# -*- coding: utf-8 -*-
"""
Created on Tue Apr 27 10:46:27 2021

@author: marti
"""

import copy
import numpy as np

class Individuo:
    def __init__(self, alelos, longitud_gen, cromosoma):
        self._alelos = alelos
        self._longitud_gen = longitud_gen
        self._cromosoma = cromosoma
        self._fitness = 0

class AG:
    def __init__(self, cantidad_individuos, alelos, tamano_gen, generaciones, p, problema):
        self._cantidad_individuos = cantidad_individuos
        self._alelos = alelos
        self._tamano_gen = tamano_gen
        self._generaciones = generaciones
        self._p = p
        self._problema = problema
        self._individuos = np.array([])

    def run(self):
        self.crearIndividuos()
        self._mejor_historico = self._individuos[0]
        generacion = 1
        while generacion <= self._generaciones:
            self.evaluaIndividuos()
            hijos = np.array([])
            while len(hijos) < len(self._individuos):
                padre1 = self.ruleta()
                padre2 = self.ruleta()
                while padre1 == padre2:
                    padre2 = self.ruleta()
                h1, h2 = self.cruza(self._individuos[padre1], self._individuos[padre2])
                hijos = np.append(hijos, [h1])
                hijos = np.append(hijos, [h2])
            self.mutacion(hijos)
            self._individuos = np.copy(hijos)
            self._individuos[np.random.randint(len(self._individuos))] = copy.deepcopy(self._mejor_historico)
            if generacion % 100 == 0:
                print("Generación: ", generacion, 'Mejor Histórico: ', self._mejor_historico._cromosoma, self._mejor_historico._fitness)
            generacion += 1

    def crearIndividuos(self):
        for i in range(self._cantidad_individuos):
            cromosoma = np.random.randint(2, size = self._alelos)
            individuo = Individuo(self._alelos, self._tamano_gen, cromosoma)
            self._individuos = np.append(self._individuos, [individuo])

    def evaluaIndividuos(self):
        for i in self._individuos:
            i._fitness = self._problema.f(self._tamano_gen, i._cromosoma)
            if i._fitness > self._mejor_historico._fitness:
                self._mejor_historico = copy.deepcopy(i)

    def ruleta(self):
        f_sum = np.sum([i._fitness for i in self._individuos])
        if f_sum < 0:
            f_sum *= -1
        if f_sum == 0:
            return np.random.randint(len(self._individuos))
        else:
            r = np.random.randint(f_sum + 1)
            k = 0
            F = self._individuos[k]._fitness
            if F < 0:
                F *= -1
            while F < r and k < len(self._individuos):
                k += 1
                if self._individuos[k]._fitness < 0:
                    F += self._individuos[k]._fitness * -1
                else:
                    F += self._individuos[k]._fitness
            return k

    def cruza(self, i1, i2):
        h1 = copy.deepcopy(i1)
        h2 = copy.deepcopy(i2)

        s = self._alelos - 1
        punto_cruza = np.random.randint(s) + 1
        h1._cromosoma[punto_cruza:], h2._cromosoma[punto_cruza:] = h2._cromosoma[punto_cruza:], h1._cromosoma[punto_cruza:]
        return h1, h2

    def mutacion(self, hijos):
        for h in hijos:
            for bit in range(len(h._cromosoma)):
                if np.random.rand() < self._p:
                    h._cromosoma[bit] = int(not h._cromosoma[bit])
                    
class Knapsack:
    def __init__(self, pesos, valores, capacidad):
        self._pesos = pesos
        self._valores = valores
        self._capacidad = capacidad

    def f(self, tamano_gen, cromosoma):
        f = 0
        peso = 0
        for i in range(len(cromosoma)):
            if cromosoma[i]:
                f = f + self._valores[i]
                peso = peso + self._pesos[i]
        if peso < self._capacidad:
            return f
        else:
            return 0

def main():
    pesos = [22, 14, 16, 23, 12, 15, 22, 6, 19, 20, 40, 8, 16, 6, 15, 21, 16]
    valores = [55, 34, 28, 30, 80, 3, 28, 24, 21, 43, 54, 12, 21, 11, 6, 21, 28]
    capacidad = 80
    mochila = Knapsack(pesos, valores, capacidad)
    alelos = len(pesos)
    individuos = 32
    tamano_gen = 1 #cada bit representa a un artículo de la mochila
    generaciones = 2000
    factor_mutacion = 0.01
    ag = AG(individuos, alelos, tamano_gen, generaciones, factor_mutacion, mochila)
    ag.run()