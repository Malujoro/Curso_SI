import abc

class Funcionario(abc.ABC):

    def __init__(self, nome, cpf, salario, senha):
        self._nome = nome
        self._cpf = cpf
        self._salario = salario
        self._senha = senha

    @property
    def salario(self):
        return self._salario
    
    @abc.abstractmethod
    def get_bonificacao(self):
        pass

    @abc.abstractmethod
    def autenticacao(self, senha):
        pass


class Gerente(Funcionario):

    def __init__(self, nome, cpf, salario, senha):
        super().__init__(nome, cpf, salario, senha)

    def get_bonificacao(self):
        return 0.1 * self.salario

    def autenticacao(self, senha):
        return self._senha == senha

    def imprimir(self):
        print("Estou no gerente.")


class Secretario(Funcionario):

    def __init__(self, nome, cpf, salario, senha):
        super().__init__(nome, cpf, salario, senha)

    def get_bonificacao(self):
        return 0.05 * self.salario + 100

    def autenticacao(self, senha):
        return self._senha == senha

    def imprimir(self):
        print("Estou no secretario.")


class ControleBonificacao():

    def __init__(self):
        self._totalBonificacao = 0

    def calcularBonificacao(self, funcionario):
        if isinstance(funcionario, Funcionario):
            self._totalBonificacao += funcionario.get_bonificacao()

    def imprimirTotalBonificacao(self):
        print(f"A bonificação de todos os funcionários é: {self._totalBonificacao}")


class Cliente():

    def __init__(self, nome, cpf):
        self._nome = nome
        self._cpf = cpf

    def imprimir(self):
        print("Estou no cliente.")


class ControleAutenticacao():

    def __init__(self):
        pass

    def login(self, funcionario, senha):
        if(isinstance(funcionario, Funcionario)):
            if(funcionario.autenticacao(senha)):
                return True, "Login realizado com sucesso"
            return False, "Senha inválida"
        return False, "Usuário sem permissão"


# cb = ControleBonificacao()
controle = ControleAutenticacao()
g1 = Gerente("Flávio", "123", 1000, "1234")
g2 = Gerente("Henrique", "111", 500, "4321")
s1 = Secretario("José", "222", 1000, "0000")
c1 = Cliente("Maria", "331")

# cb.calcularBonificacao(g1)
# cb.calcularBonificacao(g2)
# cb.calcularBonificacao(s1)
# cb.calcularBonificacao(c1)

g1.imprimir()
print(controle.login(g1, "1234")[1])
print()

g2.imprimir()
print(controle.login(g2, "111")[1])
print()

s1.imprimir()
print(controle.login(s1, "111")[1])
print()

c1.imprimir()
print(controle.login(c1, "111")[1])

# cb.imprimirTotalBonificacao()
