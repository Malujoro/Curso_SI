class Produto:

    __slots__ = ["_nome", "_preco", "_quantidadeEstoque"]

    def __init__(self, nome, preco, quantidadeEstoque):
        self._nome = nome
        self._preco = preco
        self._quantidadeEstoque = quantidadeEstoque

    @property
    def nome(self):
        return self._nome
    
    @property
    def preco(self):
        return self._preco
    
    @property
    def quantidadeEstoque(self):
        return self._quantidadeEstoque
    
    @nome.setter
    def nome(self, nome):
        self._nome = nome
    
    @preco.setter
    def preco(self, preco):
        if(preco > 0):
            self._preco = preco
    
    @quantidadeEstoque.setter
    def quantidadeEstoque(self, quantidadeEstoque):
        if(quantidadeEstoque >= 0):
            self._quantidadeEstoque = quantidadeEstoque

    def addEstoque(self, quant):
        if(quant <= 0):
            return False, "Quantidade inválida"

        self.quantidadeEstoque += quant
        return True, "Quantidade adicionada com sucesso"
    
    def subEstoque(self, quant):
        if(quant <= 0 or quant > self._quantidadeEstoque):
            return False, "Quantidade inválida"

        self._quantidadeEstoque -= quant
        return False, "Quantidade removida com sucesso"

    def exibir(self):
        print(f"Nome: {self._nome} | Preço: R${self._preco:.2f} | Quantidade em Estoque: {self._quantidadeEstoque}")


class Estoque:

    __slots__ = ["_produtos"]

    def __init__(self, produtos = []):
        self._produtos = produtos

    @property
    def produtos(self):
        return self._produtos

    @produtos.setter
    def produtos(self, produtos):
        self._produtos = produtos

    def exibirAbaixo(self, quant):
        if(quant <= 0):
            return False, "Quantidade inválida"

        for produto in self.produtos:
            if(produto.quantidadeEstoque < quant):
                produto.exibir()
        return True, "Estoque exibido com sucesso"


produto = Produto("Banana", 7, 2)
produto.exibir()
produto.addEstoque(10)
produto.exibir()
produto.subEstoque(2)
produto.exibir()
print()
produtos = [produto]
produtos.append(Produto("Maçã", 5, 3))
produtos.append(Produto("Goiaba", 4, 4))
estoque = Estoque(produtos)
print("Produtos com estoque abaixo de 5")
estoque.exibirAbaixo(5)