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
            print("\nCliente não cadastrado! Cadastre ele agora: ")
            self.cadastrarCliente(input("Nome: "), cpf)

        if(self.clientePossuiConta(cpf)):
            return False, "Erro! Cliente já possui uma conta"
        
        self._contas[cpf] = Conta(numero, self._clientes[cpf])
        return True, "Conta cadastrada com sucesso"
        
    def clienteExiste(self, cpf):
        return cpf in self._clientes.keys()

    def clientePossuiConta(self, cpf):
        return cpf in self._contas.keys()

    def sacar(self, cpf, valor):
        if(self.clientePossuiConta(cpf)):
            return self._contas[cpf].sacar(valor)
        return "Cliente não possui conta"

    def depositar(self, cpf, valor):
        if(self.clientePossuiConta(cpf)):
            return self._contas[cpf].depositar(valor)
        return "Cliente não possui conta"
    
    def transferir(self, origem, valor):
        if(not self.clientePossuiConta(origem)):
            return "Cliente não possui conta"

        ## Verifica se as operações ocorreram corretamente
        resposta, msg = self.sacar(origem, valor)
        if(resposta):
            self._contas[origem].historico.removerOperacao()
            resposta, destino = self.escolherConta("CPF da conta de destino: ", False)
            if(resposta):
                resposta, msg = self.depositar(destino, valor)
                if(resposta):
                    self._contas[destino].historico.removerOperacao()
                    self._contas[origem].historico.addOperacao(f"Transferido R${valor:.2f} para {destino}")
                    self._contas[destino].historico.addOperacao(f"Transferência de R${valor:.2f} recebida de {origem}")
                    msg = f"Transferência de R${valor:.2f} de {origem} para {destino}"

            ## Devolve o dinheiro "sacado" caso a operação falhe após o saque
            if(not resposta):
                self.depositar(origem, valor)
                self._contas[origem].historico.removerOperacao()
        return resposta, msg

    def exibirClientes(self):
        print()
        for i in self._clientes.values():
            i.exibir()

    def exibirContas(self):
        print()
        for i in self._contas.values():
            i.exibir()

    def exibirHistorico(self, cpf):
        return self._contas[cpf].exibirHistorico()
    
    ## Exibe as contas (clientes) disponíveis e permite a escolha
    ## Recebe o texto a ser exibido e um booleano para indicar se a conta escolhida deverá exibir suas informações
    def escolherConta(self, txt="CPF: ", exibir=True):
        self.exibirClientes()
        print()
        cpf = input(txt)
        if(self.clientePossuiConta(cpf)):
            if(exibir):
                self._contas[cpf].exibir()
            return True, cpf
        return False, "Conta inválida"


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

    @property
    def historico(self):
        return self._historico

    def sacar(self, valor):
        if(valor > 0 and valor <= self._saldo):
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

    def exibirHistorico(self):
        print()
        self._historico.exibir()
        return True, "Histórico exibido"

    def exibir(self):
        print(f"\nNúmero da conta: {self._numero} | Saldo: R${self._saldo:.2f}")


class Historico():

    __slots__ = ["_historico"]

    def __init__(self):
        self._historico = []
        self.addOperacao("Criação da conta")

    def addOperacao(self, operacao):
        ## Retira os milissegundos
        data = (str(datetime.now())).split(".")
        self._historico.append(f"{data[0]} - {operacao}")
        return True, "Operacao realizada com sucesso"

    def removerOperacao(self):
        self._historico.pop(-1)
        return True, "Operacao removida com sucesso"

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
    print()
    return op


banco = Banco()
while True:
    op = menu()

    if(op == "1"):
        _, msg = banco.cadastrarCliente(input("Nome: "), input("CPF: "))

    elif(op == "2"):
        _, msg = banco.cadastrarConta(input("CPF: "), int(input("Número da conta: ")))

    elif(op == "3"):
        resposta, msg = banco.escolherConta()
        if(resposta):
            _, msg = banco.sacar(msg, float(input("Valor do saque: R$")))

    elif(op == "4"):
        resposta, msg = banco.escolherConta()
        if(resposta):
            _, msg = banco.depositar(msg, float(input("Valor do depósito: R$")))
    
    elif(op == "5"):
        resposta, msg = banco.escolherConta("CPF da conta de origem: ")
        if(resposta):
            _, msg = banco.transferir(msg, float(input("Valor da transferência: R$")))

    elif(op == "6"):
        resposta, msg = banco.escolherConta()
        if(resposta):
            _, msg = banco.exibirHistorico(msg)

    elif(op == ""):
        print("Fechando execução...")
        break
    else:
        msg = "Opção inválida"
    
    print(f"\n{msg}\n")
