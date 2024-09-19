class ContaCorrente:

    __slots__ = ["_saldo", "_limite"]

    def __init__(self, saldo, limite):
        self._saldo = saldo
        self._limite = limite

    @property
    def saldo(self):
        return self._saldo
    
    @property
    def limite(self):
        return self._limite
    
    @saldo.setter
    def saldo(self, valor):
        if(valor >= (-self._limite)):
            self._saldo = valor

    @limite.setter
    def limite(self, valor):
        if(valor >= 0):
            self._limite = valor

    def depositar(self, valor):
        if(valor <= 0):
            return False, "Valor inválido"
        self._saldo += valor
        return True, "Depósito realizado com sucesso"
    
    def sacar(self, valor):
        if(valor <= 0 or valor > self._saldo + self._limite):
            return False, "Valor inválido"
        self._saldo -= valor
        return True, "Saque realizado com sucesso"
    
    def verificarSaldo(self):
        print(f"Saldo: R${self._saldo:.2f}")
    

conta = ContaCorrente(500, 100)
conta.verificarSaldo()
conta.sacar(600)
conta.verificarSaldo()
conta.sacar(1)
conta.verificarSaldo()
conta.limite = 200
conta.sacar(100)
conta.verificarSaldo()
conta.depositar(1000)
conta.verificarSaldo()