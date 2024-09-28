class Veiculo:
    """
    Classe que representa um veículo

    Atributos
    ---------
    valor: float
    
    Métodos
    ---------
    calcularIPVA():
        Calcula o IPVA do veículo
    """

    __slots__ = ["_valor"]

    def __init__(self, valor: float) -> None:
        self._valor = valor

    @property
    def valor(self) -> float:
        return self._valor
    
    @valor.setter
    def valor(self, valor: float) -> None:
        if(valor >= 0):
            self._valor = valor

    def calcularIPVA(self) -> float:
        pass


class Carro(Veiculo):
    """
    Classe que representa um carro (herda de veículo)

    Atributos
    ---------
    valor: float
    
    Métodos
    ---------
    calcularIPVA():
        Calcula o IPVA do carro
    """

    def __init__(self, valor: float) -> None:
        super().__init__(valor)
    
    def calcularIPVA(self) -> float:
        """
        Calcula o IPVA do carro

        Retorno
        -------
        O valor do IPVA (3% do valor do carro)
        """
        return self._valor * 0.03
    

class Moto(Veiculo):
    """
    Classe que representa uma moto (herda de veículo)

    Atributos
    ---------
    valor: float
    
    Métodos
    ---------
    calcularIPVA():
        Calcula o IPVA da moto
    """

    def __init__(self, valor: float) -> None:
        super().__init__(valor)
    
    def calcularIPVA(self) -> float:
        """
        Calcula o IPVA da moto

        Retorno
        -------
        O valor do IPVA (2.5% do valor da moto)
        """
        return self._valor * 0.025
    

class Caminhao(Veiculo):
    """
    Classe que representa um caminhão (herda de veículo)

    Atributos
    ---------
    valor: float
    
    Métodos
    ---------
    calcularIPVA():
        Calcula o IPVA do caminhão
    """

    def __init__(self, valor: float) -> None:
        super().__init__(valor)
    
    def calcularIPVA(self) -> float:
        """
        Calcula o IPVA do caminhão

        Retorno
        -------
        O valor do IPVA (1.5% do valor do caminhão)
        """
        return self._valor * 0.015


class SistemaImpostos:
    """
    Classe responsável por calcular IPVA dos veículos

    Atributos
    ---------
    veiculo: Veiculo
    
    Métodos
    ---------
    calcularIPVA():
        Calcula o IPVA do veículo
    """
    __slots__ = ["_veiculo"]

    def __init__(self, veiculo: Veiculo) -> None:
        self._veiculo = veiculo

    @property
    def veiculo(self) -> Veiculo:
        return self._veiculo
    
    @veiculo.setter
    def veiculo(self, veiculo: float) -> None:
        self._veiculo = veiculo
    
    def calcularIPVA(self) -> float:
        """
        Calcula o IPVA do veículo

        Retorno
        -------
        O valor do IPVA do veículo
        """
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
