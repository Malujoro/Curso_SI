## Cadastrar cliente - Nome, CPF (Não pode cadastrar 2 cpfs)

## Criar conta - Número, Saldo = 0, Cliente, Histórico

## Sacar
    ##  Exibir todas as pessoas
    ##  Pedir e verificar CPF
    ##  Exibir número e saldo da conta
    ##  Perguntar valor do saque

## Depositar
    ##  Parecido com sacar

## Transferir
    ##  Parecido com sacar
    ##  Depois de escolher a conta origem, exibir e escolher o cpf da Destino

## Imprimir Histórico
    ##  Mostrar Data de criação e as operações da conta
    ##  Exibir data e hora de cada operação

from datetime import datetime

class Banco():

    def __init__(self):
        self._clientes = {}
        self._contas = {}

    def cadastrarCliente(self, nome, cpf):
        if(self.clienteExiste(cpf)):
            return False, "Erro! CPF já foi cadastrado"
        
        self._clientes[cpf] = Cliente(nome, cpf)
        return True, "Cliente cadastrado com sucesso"
    
    def cadastrarConta(self, cpf, numero):
        if(not self.clienteExiste(cpf)):
            self.cadastrarCliente(input("Nome: "), cpf)

        if(self.clientePossuiConta(cpf)):
            return False, "Erro! Cliente já possui uma conta"
        
        self._contas[cpf] = Conta(numero, self._clientes[cpf])
        return True, "Conta cadastrada com sucesso"
        
    def clienteExiste(self, cpf):
        if(cpf in self._clientes.keys()):
            return True
        return False

    def clientePossuiConta(self, cpf):
        if(cpf in self._contas.keys()):
            return True
        return False

    def sacar(self, cpf):
        if(self.clientePossuiConta(cpf)):
            self._contas[cpf].exibir()
            return self._contas[cpf].sacar(float(input("Valor do saque: R$")))
        return False, "Cliente inválido"

    def depositar(self, cpf):
        if(self.clientePossuiConta(cpf)):
            self._contas[cpf].exibir()
            return self._contas[cpf].depositar(float(input("Valor do depósito: R$")))
        return False, "Cliente inválido"

    def exibirClientes(self):
        for i in self._clientes.values():
            i.exibir()

    def exibirContas(self):
        for i in self._contas.values():
            i.exibir()

    def exibirHistorico(self, cpf):
        if(self.clientePossuiConta(cpf)):
            self._contas[cpf].exibirHistorico()
            return True, "Histórico exibido"
        return False, "Cliente inválido"


class Cliente():

    __slots__ = ["_nome", "_cpf"]

    def __init__(self, nome, cpf):
        self._nome = nome
        self._cpf = cpf
    
    @property
    def cpf(self):
        return self._cpf

    def exibir(self):
        print(f"Nome: {self._nome} | CPF: {self._cpf}")

class Conta():

    __slots__ = ["_numero", "_saldo", "_cliente", "_historico"]

    def __init__(self, numero, cliente):
        self._numero = numero
        self._saldo = 0
        self._cliente = cliente
        self._historico = Historico()

    def sacar(self, valor):
        if(valor <= self._saldo):
            self._saldo -= valor
            msg = f"Saque de R${valor:.2f}"
            self._historico.addOperacao(msg)
            return True, msg
        return False, "Saque inválido"
    
    def depositar(self, valor):
        if(valor > 0):
            self._saldo += valor
            msg = f"Depósito de R${valor:.2f}"
            self._historico.addOperacao(msg)
            return True, msg
        return False, "Depósito inválido"
        
    # def transferir():

    def exibirHistorico(self):
        self._historico.exibir()

    def exibir(self):
        print(f"Número da conta: {self._numero} | Saldo: R${self._saldo}")


class Historico():

    __slots__ = ["_historico"]

    def __init__(self):
        self._historico = []
        self.addOperacao("Criação da conta")

    def addOperacao(self, operacao):
        self._historico.append(f"{datetime.now()} - {operacao}")
        return True, "Operacao realizada com sucesso"

    def exibir(self):
        for i in self._historico:
            print(i)



def menu():
    print("Menu")
    print("[1] - Cadastrar cliente")
    print("[2] - Criar conta")
    print("[3] - Sacar")
    print("[4] - Depositar")
    print("[5] - Transferir")
    print("[6] - Imprimir histórico de uma conta")
    print("[Enter] - Sair")
    op = input("Opção: ")
    return op


banco = Banco()
while True:
    op = menu()

    if(op == "1"):
        _, msg = banco.cadastrarCliente(input("Nome: "), input("CPF: "))

    elif(op == "2"):
        _, msg = banco.cadastrarConta(input("CPF: "), int(input("Número da conta: ")))

    elif(op == "3"):
        banco.exibirClientes()
        cpf = input("CPF: ")
        _, msg = banco.sacar(cpf)

    elif(op == "4"):
        banco.exibirClientes()
        cpf = input("CPF: ")
        _, msg = banco.depositar(cpf)
    
    elif(op == "5"):
        banco.exibirClientes()
        cpf = input("CPF: ")
        _, msg = banco.transferir(cpf)

    elif(op == "6"):
        banco.exibirClientes()
        cpf = input("CPF: ")
        _, msg = banco.exibirHistorico(cpf)

    elif(op == ""):
        print("Fechando execução...")
        break
    else:
        msg = "Opção inválida"
    
    print(f"\n{msg}\n")
