class Bicicleta:

    __slots__ = ["_modelo", "_tarifa_hora", "_alugada"]

    def __init__(self, modelo: str, tarifa_hora: float, alugada: bool):
        self._modelo = modelo
        self._tarifa_hora = tarifa_hora
        self._alugada = alugada

    @property
    def modelo(self) -> str:
        return self._modelo
    
    @modelo.setter
    def modelo(self, modelo: str):
        self._modelo = modelo

    @property
    def tarifa_hora(self) -> float:
        return self._tarifa_hora
    
    @tarifa_hora.setter
    def tarifa_hora(self, tarifa_hora: float):
        if(tarifa_hora > 0):
            self._tarifa_hora = tarifa_hora

    @property
    def alugada(self) -> bool:
        return self._alugada
    
    @alugada.setter
    def alugada(self, alugada: bool):
        self._alugada = alugada

    def custo_aluguel(self, horas: float) -> float:
        return horas * self._tarifa_hora

    def alugar(self):
        self._alugada = True

    def desalugar(self):
        self._alugada = False
    
if(__name__ == "__main__"):
    bicicletas = []
    bicicletas.append(Bicicleta("Modelo 1", 10, False))
    bicicletas.append(Bicicleta("Modelo 2", 20, False))
    bicicletas.append(Bicicleta("Modelo 3", 30, False))
    for bike in bicicletas:
        print(bike.custo_aluguel(5))