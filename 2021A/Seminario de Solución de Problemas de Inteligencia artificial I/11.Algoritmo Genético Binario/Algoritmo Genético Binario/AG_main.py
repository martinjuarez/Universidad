import knapsack
import AG

def main():
    pesos = [22, 14, 16, 23, 12, 15, 22, 6, 19, 20, 40, 8, 16, 6, 15, 21, 16]
    valores = [55, 34, 28, 30, 80, 3, 28, 24, 21, 43, 54, 12, 21, 11, 6, 21, 28]
    capacidad = 80
    mochila = knapsack.Knapsack(pesos, valores, capacidad)
    alelos = len(pesos)
    individuos = 32
    tamano_gen = 1 #cada bit representa a un artículo de la mochila
    generaciones = 2000
    factor_mutacion = 0.01
    ag = AG.AG(individuos, alelos, tamano_gen, generaciones, factor_mutacion, mochila)
    ag.run()

if __name__ == '__main__':
    main()
