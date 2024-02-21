class lim_con:
    def __init__(self, tamano, limite):
        self._tamano = tamano
        self._limite = limite

    def f(self, tamano_gen, cromosoma):
        f = 0
        for i in range(len(cromosoma)):
            if cromosoma[i]:
                f = f + self._tamano[i]
        if f < self._limite:
            return f
        else:
            return 0

