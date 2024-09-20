class Item:

    __slots__ = ["_nome", "_preco"]

    def __init__(self, nome, preco):
        self._nome = nome
        self._preco = preco

    @property
    def nome(self):
        return self._nome
    
    @property
    def preco(self):
        return self._preco

    @nome.setter
    def nome(self, nome):
        self._nome = nome

    @preco.setter
    def preco(self, preco):
        if(preco > 0):
            self._preco = preco
    
    def exibir(self):
        print(f"Nome: {self._nome} | Preço: R${self._preco:.2f}")
        return True, "Item exibidos com sucesso"

class Pedido:

    __slots__ = ["_itens"]

    def __init__(self, itens = []):
        self._itens = itens

    @property
    def itens(self):
        return self._itens
    
    @itens.setter
    def itens(self, itens):
        self._itens = itens

    def addItem(self, item):
        self._itens.append(item)
        return True, "Item adicionado com sucesso"

    def removerItem(self, nomeItem):
        for item in self._itens:
            if(nomeItem == item.nome):
                self._itens.remove(item)
                return True, "Item removido com sucesso"
        return False, "Item não encontrado"

    def calcularTotal(self):
        total = 0
        for item in self._itens:
            total += item.preco
        return True, "Preço calculado com sucesso", total

    def exibir(self):
        for item in self._itens:
            item.exibir()
        return True, "Pedido exibidos com sucesso"
    
pedido = Pedido()

pedido.addItem(Item("Hamburguer", 15))
pedido.addItem(Item("Refrigerante", 7))
pedido.addItem(Item("Batata", 5))

print(f"Valor total do pedido: R${pedido.calcularTotal()[2]:.2f}:")

print()
print(pedido.removerItem("Batata")[1])
print()

print(f"Valor total do pedido: R${pedido.calcularTotal()[2]:.2f}:")