class Veiculo:

    __slots__ = ["_valor"]

    def __init__(self, valor: float):
        self._valor = valor

    @property
    def valor(self):
        return self._valor
    
    @valor.setter
    def valor(self, valor: float):
        if(valor >= 0):
            self._valor = valor

    def calcularIPVA(self):
        pass


class Carro(Veiculo):

    def __init__(self, valor: float):
        super().__init__(valor)
    
    def calcularIPVA(self):
        return self._valor * 0.03
    

class Moto(Veiculo):

    def __init__(self, valor: float):
        super().__init__(valor)
    
    def calcularIPVA(self):
        return self._valor * 0.025
    

class Caminhao(Veiculo):

    def __init__(self, valor: float):
        super().__init__(valor)
    
    def calcularIPVA(self):
        return self._valor * 0.015


class SistemaImpostos:

    __slots__ = ["_veiculo"]

    def __init__(self, veiculo: Veiculo):
        self._veiculo = veiculo

    @property
    def veiculo(self):
        return self._veiculo
    
    @veiculo.setter
    def veiculo(self, veiculo: float):
        self._veiculo = veiculo
    
    def calcularIPVA(self):
        return self._veiculo.calcularIPVA()
    

carro = Carro(10000)
moto = Moto(5000)
caminhao = Caminhao(50000)

impostos = SistemaImpostos(carro)
print(f"IPVA do Carro: R${impostos.calcularIPVA():.2f}")

impostos.veiculo = moto
print(f"IPVA da Moto: R${impostos.calcularIPVA():.2f}")

impostos.veiculo = caminhao
print(f"IPVA do Caminhão: R${impostos.calcularIPVA():.2f}")
