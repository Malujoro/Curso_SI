from datetime import date

class Pessoa():

    __slots__ = ["_nome", "_dataNascimento", "_altura"]

    def __init__(self, nome, dataNascimento, altura):
        self._nome = nome
        self._dataNascimento = dataNascimento
        self._altura = altura

    @property
    def nome(self):
        return self._nome
    
    @property
    def dataNascimento(self):
        return self._dataNascimento
    
    @property
    def altura(self):
        return self._altura

    @nome.setter
    def nome(self, nome):
        self._nome = nome
    
    @dataNascimento.setter
    def dataNascimento(self, dataNascimento):
        if(len(dataNascimento) < 10 or dataNascimento[2] != '/' or dataNascimento[5] != '/'):
            print("Erro! Insira uma data válida (dd/mm/aaaa)")
            return False, "Data de nascimento inválida"
        
        self._dataNascimento = dataNascimento
        return True, "Data de nascimento alterada com sucesso"
    
    @altura.setter
    def altura(self, altura):
        if(altura > 0):
            self._altura = altura
            return True, "Altura alterada com sucesso"
        
        print("Erro! Altura deve ser maior que 0")
        return False, "Altura inválida"

    def imprimir(self):
        print(f"Nome: {self._nome}")
        print(f"Data de nascimento: {self._dataNascimento}")
        print(f"Altura: {self._altura}")

    def idade(self):
        ## [0] = Dia | [1] = Mês | [2] = Ano
        data = self._dataNascimento.split('/')
        idade = date.today().year - int(data[2])
        
        mes = int(data[1])
        mesAtual = date.today().month
        if(mesAtual < mes or (mesAtual == mes and date.today().day < int(data[0]))):
            idade -= 1

        return idade



p1 = Pessoa("Mateus", "01/01/2001", 1.78)
p2 = Pessoa("Lucas", "12/12/2012", 1.80)
print(p1.idade())
print(p2.idade())