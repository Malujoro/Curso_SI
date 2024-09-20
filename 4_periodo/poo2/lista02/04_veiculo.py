class Veiculo:

    __slots__ = ["_marca", "_modelo", "_ano"]

    def __init__(self, marca, modelo, ano):
        self._marca = marca
        self._modelo = modelo
        self._ano = ano


    @property
    def marca(self):
        return self._marca
    
    @property
    def modelo(self):
        return self._modelo
    
    @property
    def ano(self):
        return self._ano


    @marca.setter
    def marca(self, marca):
        self._marca = marca

    @modelo.setter
    def modelo(self, modelo):
        self._modelo = modelo

    @ano.setter
    def ano(self, ano):
        if(ano >= 0):
            self._ano = ano


    def exibir(self):
        print(f"Marca: {self._marca}")
        print(f"Modelo: {self._modelo} ")
        print(f"Ano: {self._ano} ")
        return True, "Veiculo exibido com sucesso"


class Carro(Veiculo):

    __slots__ = ["_marca", "_modelo", "_ano", "_numeroPortas"]

    def __init__(self, marca, modelo, ano, numeroPortas):
        super().__init__(marca, modelo, ano)
        self._numeroPortas = numeroPortas

    def exibir(self):
        super().exibir()
        print(f"Número de portas: {self._numeroPortas} ")
        return True, "Carro exibido com sucesso"


class Moto(Veiculo):

    __slots__ = ["_marca", "_modelo", "_ano", "_cilindradas"]

    def __init__(self, marca, modelo, ano, cilindradas):
        super().__init__(marca, modelo, ano)
        self._cilindradas = cilindradas

    def exibir(self):
        super().exibir()
        print(f"Cilindradas: {self._cilindradas} ")
        return True, "Moto exibida com sucesso"


veiculo = Veiculo("MarcaV", "ModeloV", 2020)
veiculo.exibir()
print()

carro = Carro("MarcaC", "ModeloC", 2015, 4)
carro.exibir()
print()

moto = Moto("MarcaC", "ModeloC", 2017, 50)
moto.exibir()