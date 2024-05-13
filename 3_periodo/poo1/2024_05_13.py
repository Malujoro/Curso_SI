class Conta:

    def __init__(self, titular, saldo):
        self.titular = titular
        self.saldo = saldo
        self.historico = Historico()
    
    def sacar(self, valor):
        if(valor <= self.saldo):
            self.saldo -= valor
            self.historico.add_transacao(f"Saque de R${valor} feito com sucesso")
            return True, "Saque feito com sucesso"
        self.historico.add_transacao(f"Saldo insuficiente para Saque")
        return False, "Saldo insuficiente para Saque"

    def depositar(self, valor):
        if(valor > 0):
            self.saldo += valor
            self.historico.add_transacao(f"Depósito de R${valor} feito com sucesso")
            return True, "Depósito feito com sucesso"
        self.historico.add_transacao(f"Valor inválido para depósito")
        return False, "Valor inválido"

    def extrato(self):
        self.titular.imprimir()
        print(f"Saldo: R${self.saldo:.2f}")
        self.historico.imprimir_transacoes()

    def transferir(self, conta, valor):
        sucesso, mensagem = self.sacar(valor)
        if(sucesso):
            conta.depositar(valor)
            # self.historico.add_transacao(f"Transferência de R${valor} feita com sucesso para {conta.titular.nome}")
            return True, "Transferência feita com sucesso"
        return False, "Transferência não executada: " + mensagem


class Titular: 

    def __init__(self, nome, cpf, idade):
        self.nome = nome
        self.cpf = cpf
        self.idade = idade

    def imprimir(self):
        print(f"Nome: {self.nome}")
        print(f"CPF: {self.cpf}")
        print(f"Idade: {self.idade}")
        return True, "Titular impresso com sucesso"


class Historico:

    def __init__(self):
        self.transacoes = []

    def add_transacao(self, t):
        self.transacoes.append(t)
        return True, "Transação adicionada com sucesso"

    def imprimir_transacoes(self):
        for pos, i in enumerate(self.transacoes):
            print(f"{pos+1}ª transação: {i}")



t1 = Titular("Flavio", 123, 33)
t2 = Titular("Henrique", 111, 34)

c1 = Conta(t1, 100)
c2 = Conta(t2, 0)

c1.depositar(50)
c1.transferir(c2, 25)
c2.sacar(10)

c1.extrato()
c2.extrato()