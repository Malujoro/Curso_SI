class Cliente:

    __slots__ = ["_nome", "_email"]

    def __init__(self, nome, email):
        self._nome = nome
        self._email = email
    
    @property
    def nome(self):
        return self._nome
    
    @property
    def email(self):
        return self._email
    
    @nome.setter
    def nome(self, nome):
        self._nome = nome

    @email.setter
    def email(self, email):
        self._email = email
    
    def exibir(self):
        print(f"Nome: {self._nome} | Email: {self._email}")
        return True, "Cliente exibido com sucesso"


class Produto:

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
        return True, "Produto exibido com sucesso"

class Pedido:

    __slots__ = ["_produtos", "_cliente"]

    def __init__(self, cliente, produtos = []):
        self._cliente = cliente
        self._produtos = produtos

    @property
    def produtos(self):
        return self._produtos
    
    @property
    def cliente(self):
        return self._cliente
    
    @produtos.setter
    def produtos(self, produtos):
        self._produtos = produtos
    
    @cliente.setter
    def cliente(self, cliente):
        self._cliente = cliente

    def addProduto(self, produto):
        self._produtos.append(produto)
        return True, "Produto adicionado com sucesso"

    def removerProduto(self, nomeProduto):
        for produto in self._produtos:
            if(nomeProduto == produto.nome):
                self._produtos.remove(produto)
                return True, "Produto removido com sucesso"
        return False, "Produto não encontrado"

    def calcularTotal(self):
        total = 0
        for produto in self._produtos:
            total += produto.preco
        return True, "Preço calculado com sucesso", total

    def exibir(self):
        self._cliente.exibir()
        for produto in self._produtos:
            produto.exibir()
        return True, "Pedido exibidos com sucesso"


pedido = Pedido(Cliente("Mateus", "Mateus@hotmail.com"))

pedido.addProduto(Produto("Batata", 7))
pedido.addProduto(Produto("Limão", 6))
pedido.addProduto(Produto("Cenoura", 9))

pedido.exibir()
print(f"Valor total do pedido: R${pedido.calcularTotal()[2]:.2f}:")

print()
print(pedido.removerProduto("Cenoura")[1])
print()

pedido.exibir()
print(f"Valor total do pedido: R${pedido.calcularTotal()[2]:.2f}:")