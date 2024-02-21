import Lim_con
import AG

def main():
    tamano = [13, 8, 25, 4, 18, 6, 33, 22, 45, 11, 76, 10, 1]   
    limite = 211
    subconjunto = Lim_con.lim_con(tamano, limite)
    alelos = len(tamano)
    individuos = 10
    tamano_gen = 1 #cada bit representa a un artículo de la subconjunto
    generaciones = 2000
    factor_mutacion = 0.01
    ag = AG.AG(individuos, alelos, tamano_gen, generaciones, factor_mutacion, subconjunto)
    ag.run()

if __name__ == '__main__':
    main()
