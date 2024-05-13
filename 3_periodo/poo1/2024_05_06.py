class Pessoa:

    def __init__(self, nome, matricula):
        self.nome = nome
        self.matricula = matricula

    def imprimir(self):
        print(f"Nome: {self.nome}")
        print(f"Matricula: {self.matricula}")

class Conta:

    def __init__(self, titular, saldo):
        self.titular = titular
        self.saldo = saldo
    
    def sacar(self, valor):
        if(valor <= self.saldo):
            self.saldo -= valor
            return True, "Saque feito com sucesso"
        return False, "Saldo insuficiente para Saque"

    def depositar(self, valor):
        if(valor > 0):
            self.saldo += valor
            return True, "Depósito feito com sucesso"
        return False, "Valor inválido"

    def extrato(self):
        print(f"Titular: {self.titular}")
        print(f"Saldo: R${self.saldo:.2f}")

    def transferir(self, conta, valor):
        sucesso, mensagem = self.sacar(valor)
        if(sucesso):
            conta.depositar(valor)
            return True, "Transferência feita com sucesso"
        return False, "Transferência não executada: " + mensagem


# p1 = Pessoa("Mateus", 123)
# p2 = Pessoa("Alef", 13)

c1 = Conta("Alef", 200)
c2 = Conta("Mateus", 0)

c1.transferir(c2, 50)
c1.extrato()
print()
c2.extrato()