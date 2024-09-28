from abc import abstractmethod, ABC

class Pagamento(ABC):
    """
    Classe abstrata que representa o pagamento

    Métodos
    ---------
    processarPagamento():
        Processa o pagamento

    emitirRecibo()
        Exibe o valor final da transação
    """

    @abstractmethod
    def processarPagamento(self) -> None:
        """
        Processa o pagamento
        """
        pass

    @abstractmethod
    def emitirRecibo(self) -> None:
        """
        Exibe o valor final da transação
        """
        pass


class PagamentoCredito(Pagamento):
    """
    Classe que representa o pagamento por crédito (implementa Pagamento)

    Atributos
    ---------
    valor: float

    juros: float

    valorFinal: float

    Métodos
    ---------
    processarPagamento():
        Processa o pagamento (com juros)

    emitirRecibo()
        Exibe o valor final da transação
    """

    __slots__ = ["_valor", "_juros", "_valorFinal"]

    def __init__(self, valor: float, juros: float) -> None:
        self._valor = valor
        self._juros = juros
        self._valorFinal = 0

    @property
    def valor(self) -> float:
        return self._valor
    
    @valor.setter
    def valor(self, valor: float) -> None:
        if(valor > 0):
            self._valor = valor

    @property
    def juros(self) -> float:
        return self._juros
    
    @juros.setter
    def juros(self, juros: float) -> None:
        if(juros > 0):
            self._juros = juros

    @property
    def valorFinal(self) -> float:
        return self._valorFinal
    
    @valorFinal.setter
    def valorFinal(self, valorFinal: float) -> None:
        if(valorFinal > 0):
            self._valorFinal = valorFinal

    def processarPagamento(self) -> None:
        """
        Processa o pagamento (com juros)
        """
        self.valorFinal = self.valor + (self.valor * self.juros / 100)

    def emitirRecibo(self) -> None:
        """
        Exibe o valor final da transação
        """
        print(f"Valor final da transação: R${self.valorFinal:.2f}")


class PagamentoBoleto(Pagamento):
    """
    Classe que representa o pagamento por boleto (implementa Pagamento)

    Atributos
    ---------
    valor: float

    valorFinal: float

    Métodos
    ---------
    processarPagamento():
        Processa o pagamento

    emitirRecibo()
        Exibe o valor final da transação
    """

    __slots__ = ["_valor", "_valorFinal"]

    def __init__(self, valor: float) -> None:
        self._valor = valor
        self._valorFinal = 0

    @property
    def valor(self) -> float:
        return self._valor
    
    @valor.setter
    def valor(self, valor: float) -> None:
        if(valor > 0):
            self._valor = valor

    @property
    def valorFinal(self) -> float:
        return self._valorFinal
    
    @valorFinal.setter
    def valorFinal(self, valorFinal: float) -> None:
        if(valorFinal > 0):
            self._valorFinal = valorFinal

    def processarPagamento(self) -> None:
        """
        Processa o pagamento
        """
        self.valorFinal = self.valor

    def emitirRecibo(self) -> None:
        """
        Exibe o valor final da transação
        """
        print(f"Valor final da transação: R${self.valorFinal:.2f}")


credito = PagamentoCredito(1000, 10)
credito.processarPagamento()
credito.emitirRecibo()

boleto = PagamentoBoleto(500)
boleto.processarPagamento()
boleto.emitirRecibo()