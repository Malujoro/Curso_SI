class Agenda():
    
    __slots__ = ["_listaPessoas"]

    def __init__(self):
        self._listaPessoas = []

    def armazenaPessoa(self, pessoa):
        if(len(self._listaPessoas) <= 10):
            self._listaPessoas.append(pessoa)
            return True, "Pessoa armazenada com sucesso"
        
        return False, "A lista já está cheia"

    def removePessoa(self, nome):
        for i in self._listaPessoas:
            if(i.nome.lower() == nome.lower()):
                self._listaPessoas.remove(i)
                return True, "Pessoa removida com sucesso"
        return False, "Pessoa não removida"

    def buscaPessoa(self, nome):
        for i in self._listaPessoas:
            if(i.nome.lower() == nome.lower()):
                i.imprimir()
                return True, "Pessoa encontrada"
        return False, "Pessoa não encontrada"
    
    def imprimeAgenda(self):
        for cont, i in enumerate(self._listaPessoas):
            print(f"{cont+1}ª pessoa: ", end="")
            i.imprimir()


class Pessoa():

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
            return True, "Idade alterada com sucesso"
        return False, "Idade não pode ser negativa"
    
    def imprimir(self):
        print(f"Nome: {self._nome} | Idade: {self._idade}")


p1 = Pessoa("Mateus", 19)
p2 = Pessoa("Lucas", 12)
p3 = Pessoa("Marcio", 20)
p4 = Pessoa("Alef", 18)

a = Agenda()
a.armazenaPessoa(p1)
a.armazenaPessoa(p3)
a.armazenaPessoa(p4)
a.armazenaPessoa(p2)

a.imprimeAgenda()
print()
a.buscaPessoa("Marcio")

print()
a.buscaPessoa("Jonas")
a.removePessoa("Jonas")
a.buscaPessoa("Jonas")
a.imprimeAgenda()