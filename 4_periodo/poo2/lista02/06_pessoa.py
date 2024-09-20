class Pessoa:

    __slots__ = ["_nome", "_idade"]

    def __init__(self, nome, idade):
        self._nome = nome
        self._idade = idade

    @property
    def nome(self):
        return self._nome
    
    @property
    def idade(self):
        return self._idade
    
    @nome.setter
    def nome(self, nome):
        self._nome = nome
    
    @idade.setter
    def idade(self, idade):
        if(idade >= 0):
            self._idade = idade

    def maiorIdade(self):
        return self._idade >= 18
    
    def exibir(self):
        print(f"Nome: {pessoa.nome} | Idade: {pessoa.idade}")
        return True, "Pessoa exibida com sucesso"

def PessoasMaiorIdade(pessoas):
    return [pessoa for pessoa in pessoas if(pessoa.maiorIdade())]

pessoas = []
pessoas.append(Pessoa("João", 15))
pessoas.append(Pessoa("Mateus", 20))
pessoas.append(Pessoa("Sophia", 19))
pessoas.append(Pessoa("Kaio", 17))
pessoas.append(Pessoa("Fernanda", 18))

print("Pessoas maiores de idade:")
for pessoa in PessoasMaiorIdade(pessoas):
    pessoa.exibir()