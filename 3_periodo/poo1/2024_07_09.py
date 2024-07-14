class Funcionario():

    def __init__(self, nome, cpf):
        self._nome = nome
        self._cpf = cpf

    def imprimir(self):
        print(self._nome, self._cpf)

class Gerente(Funcionario):
    
    def __init__(self, nome, cpf, telefone):
        super().__init__(nome, cpf)
        self._telefone = telefone
        
    def imprimir(self):
        print("Estou no gerente!")
        super().imprimir()


f = Funcionario("mateus", "123")
g = Gerente("flavio", "111", "555555")

f.imprimir()
g.imprimir()