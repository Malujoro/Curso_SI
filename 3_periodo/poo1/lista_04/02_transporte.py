import abc

class Veiculo(abc.ABC):

    @abc.abstractmethod
    def calcular_custo_viagem(self, distancia):
        """
            Método abstrato que deve ser implementado para calcular o custo da viagem de acordo com a distância percorrida
        """
        pass


class Carro:

    def __init__(self, consumo_combustivel):
        self._consumo_combustivel = consumo_combustivel

    def calcular_custo_viagem(self, distancia):
        return distancia * (distancia / self._consumo_combustivel)


class Moto:

    def __init__(self, consumo_combustivel):
        self._consumo_combustivel = consumo_combustivel

    def calcular_custo_viagem(self, distancia):
        return distancia * (distancia / self._consumo_combustivel)


class Caminhao:

    def __init__(self, consumo_combustivel):
        self._consumo_combustivel = consumo_combustivel
    
    def calcular_custo_viagem(self, distancia):
        return distancia * (distancia / self._consumo_combustivel) + 200


class CalculadoraCustoViagem:
    
    def __init__(self):
        self._custo_total = 0

    def calcular_e_armazenar_custo(self, veiculo, distancia):
        if(not isinstance(veiculo, Veiculo)):
            return False, "Não é um veículo"
        
        if(distancia < 0):
            return False, "Distância não pode ser negativa"

        custo = veiculo.calcular_custo_viagem(distancia)
        self._custo_total += custo
        return True, f"Custo calculado: R${custo:.2f}"

    def get_custo_total(self):
        return self._custo_total


Veiculo.register(Carro)
Veiculo.register(Moto)
Veiculo.register(Caminhao)

calculadora = CalculadoraCustoViagem()

carro = Carro(7)
moto = Moto(5)
caminhao = Caminhao(10)

print(calculadora.calcular_e_armazenar_custo(carro, 14)[1])
print(calculadora.calcular_e_armazenar_custo(moto, 10)[1])
print(calculadora.calcular_e_armazenar_custo(moto, -10)[1])
print(calculadora.calcular_e_armazenar_custo(caminhao, 30)[1])

print(f"Custo total das viagens: R${calculadora.get_custo_total():.2f}")