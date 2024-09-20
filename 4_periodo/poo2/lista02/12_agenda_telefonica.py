class Contato:

    __slots__ = ["_nome", "_telefone"]

    def __init__(self, nome, telefone):
        self._nome = nome
        self._telefone = telefone
    
    @property
    def nome(self):
        return self._nome

    @property
    def telefone(self):
        return self._telefone

    @nome.setter
    def nome(self, nome):
        self._nome = nome
    
    @telefone.setter
    def telefone(self, telefone):
        self._telefone = telefone
    
    def exibir(self):
        print(f"Nome: {self._nome} | Telefone: {self._telefone}")
    

class AgendaTelefonica:

    __slots__ = ["_contatos"]

    def __init__(self, contatos = []):
        self._contatos = contatos
    
    @property
    def contatos(self):
        return self._contatos

    @contatos.setter
    def contatos(self, contatos):
        self._contatos = contatos
    
    def addContato(self, contato):
        self._contatos.append(contato)
        return True, "Contato adicionado com sucesso"

    def removerContato(self, nomeContato):
        for contato in self._contatos:
            if(nomeContato == contato.nome):
                self._contatos.remove(contato)
                return True, "Contato removido com sucesso"
        return False, "Contato não encontrado"

    def buscarContato(self, nomeContato):
        for contato in self._contatos:
            if(nomeContato == contato.nome):
                return True, "Contato encontrado com sucesso", contato.telefone
        return False, "Contato não encontrado", ""
    
    def exibir(self):
        for contato in self._contatos:
            contato.exibir()

agenda = AgendaTelefonica()

agenda.addContato(Contato("Antônia", "123"))
agenda.addContato(Contato("Maria", "234"))
agenda.addContato(Contato("Sérgio", "345"))
agenda.addContato(Contato("Clóvis", "456"))

agenda.exibir()

print()
print(agenda.removerContato("Antônia")[1])
print()

agenda.exibir()

print("\nBuscando por Clóvis")
print(agenda.buscarContato("Clóvis"))