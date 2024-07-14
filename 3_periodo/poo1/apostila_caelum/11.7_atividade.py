class Conta:

    def __init__(self, numero, titular, saldo=0):
        self._numero = numero
        self._titular = titular
        self._saldo = saldo

    @property
    def saldo(self):
        return self._saldo
    
    def atualiza(self, taxa):
        if(taxa > 0):
            self._saldo += self._saldo * taxa

    def deposita(self, valor):
        if(valor >= 0):
            self._saldo += valor

    def __str__(self):
        return f"Número da conta: {self._numero} | Titular: {self._titular} | Saldo: R${self._saldo:.2f}"

class ContaCorrente(Conta):

    def __init__(self, numero, titular, saldo=0):
        super().__init__(numero, titular, saldo)

    def atualiza(self, taxa):
        if(taxa > 0):
            super().atualiza(taxa*2)

    def deposita(self, valor):
        if(valor > 0.10):
            super().deposita(valor - 0.10)

class ContaPoupanca(Conta):

    def __init__(self, numero, titular, saldo=0):
        super().__init__(numero, titular, saldo)

    def atualiza(self, taxa):
        if(taxa > 0):
            super().atualiza(taxa*3)

class AtualizadorDeContas():

    def __init__(self, selic, saldoTotal=0):
        self._selic = selic
        self._saldoTotal = saldoTotal

    def roda(self, conta):
        print(f"Saldo da Conta: R${conta.saldo}")
        conta.atualiza(self._selic)
        self._saldoTotal += conta.saldo
        print(f"Saldo Final: R${self._saldoTotal}")

if(__name__ == '__main__'):
    conta = Conta("111", "mateus", 100)
    corrente = ContaCorrente("222", "lucas", 100)
    poupanca = ContaPoupanca("333", "joaquim", 100)

    # conta.deposita(10)
    # corrente.deposita(10.10)
    # poupanca.deposita(10)

    atualizador = AtualizadorDeContas(0.1)
    atualizador.roda(conta)
    print()
    atualizador.roda(corrente)
    print()
    atualizador.roda(poupanca)
    print()

    # conta.atualiza(0.10)
    # corrente.atualiza(0.10)
    # poupanca.atualiza(0.10)

    print(conta)
    print(corrente)
    print(poupanca)