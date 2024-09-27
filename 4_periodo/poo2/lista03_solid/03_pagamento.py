from abc import abstractmethod, ABC

class Pagamento(ABC):

    @abstractmethod
    def processarPagamento(self):
        pass

    @abstractmethod
    def emitirRecibo(self):
        pass


class PagamentoCredito(Pagamento):

    __slots__ = ["_valor", "_juros", "_valorFinal"]

    def __init__(self, valor: float, juros: float):
        self._valor = valor
        self._juros = juros
        self._valorFinal = 0

    @property
    def valor(self):
        return self._valor
    
    @valor.setter
    def valor(self, valor: float):
        if(valor > 0):
            self._valor = valor

    @property
    def juros(self):
        return self._juros
    
    @juros.setter
    def juros(self, juros: float):
        if(juros > 0):
            self._juros = juros

    @property
    def valorFinal(self):
        return self._valorFinal
    
    @valorFinal.setter
    def valorFinal(self, valorFinal: float):
        if(valorFinal > 0):
            self._valorFinal = valorFinal

    def processarPagamento(self):
        self.valorFinal = self.valor + (self.valor * self.juros / 100)
        return True, "Pagamento processado com sucesso"

    def emitirRecibo(self):
        print(f"Valor final da transação: R${self.valorFinal:.2f}")


class PagamentoBoleto(Pagamento):

    __slots__ = ["_valor", "_valorFinal"]

    def __init__(self, valor: float):
        self._valor = valor
        self._valorFinal = 0

    @property
    def valor(self):
        return self._valor
    
    @valor.setter
    def valor(self, valor: float):
        if(valor > 0):
            self._valor = valor

    @property
    def valorFinal(self):
        return self._valorFinal
    
    @valorFinal.setter
    def valorFinal(self, valorFinal: float):
        if(valorFinal > 0):
            self._valorFinal = valorFinal

    def processarPagamento(self):
        self.valorFinal = self.valor
        return True, "Pagamento processado com sucesso"

    def emitirRecibo(self):
        print(f"Valor final da transação: R${self.valorFinal:.2f}")


credito = PagamentoCredito(1000, 10)
credito.processarPagamento()
credito.emitirRecibo()

boleto = PagamentoBoleto(500)
boleto.processarPagamento()
boleto.emitirRecibo()