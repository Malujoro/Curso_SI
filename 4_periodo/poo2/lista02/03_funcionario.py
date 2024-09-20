class Funcionario:

    slots = ["_nome", "_salario"]

    def __init__(self, nome, salario):
        self._nome = nome
        self._salario = salario
    
    @property
    def nome(self):
        return self._nome
    
    @property
    def salario(self):
        return self._salario
    
    @nome.setter
    def nome(self, nome):
        self._nome = nome

    @salario.setter
    def salario(self, salario):
        if(salario > 0):
            self._salario = salario

    def calcularAumento(self, porcentagem):
        if(porcentagem <= 0):
            return False, "Porcentagem Inválida"

        self._salario += self._salario * porcentagem / 100
        return True, "Aumento calculado com sucesso"

    def exibir(self):
        print(f"Nome: {self._nome} | Salário: R${self._salario:.2f}")
        return True, "Funcionário exibido com sucesso"
    
class Gerente(Funcionario):

    def __init__(self, nome, salario):
        super().__init__(nome, salario)

    def calcularAumento(self, porcentagem, bonus):
        if(porcentagem <= 0 or bonus <= 0):
            return False, "Valor inválido"

        retorno, msg = super().calcularAumento(porcentagem)

        if(retorno):
            self._salario += bonus

        return retorno, msg


func = Funcionario("João", 1000)
func.calcularAumento(10)
func.exibir()

ger = Gerente("Mateus", 1000)
ger.calcularAumento(10, 500)
ger.exibir()