import abc
from random import randint

class Produto(abc.ABC):

    @abc.abstractmethod
    def add_estoque(self, quant):
        pass

    @abc.abstractmethod
    def sub_estoque(self, quant):
        pass

    @abc.abstractmethod
    def disponivel(self):
        pass

    @abc.abstractmethod
    def exibir(self):
        pass


class Item:

    __slots__ = ["_nome", "_preco", "_quant_estoque"]

    def __init__(self, nome, preco, quant_estoque):
        self._nome = nome
        self._preco = preco
        self._quant_estoque = quant_estoque

    @property
    def nome(self):
        return self._nome

    def add_estoque(self, quant):
        if(quant <= 0):
            return False, "Quantidade inválida! Não pode ser adicionada"
        
        self._quant_estoque += quant
        return True, "Quantidade adicionada com sucesso"

    def sub_estoque(self, quant):
        if(quant <= 0):
            return False, "Quantidade inválida! Não pode ser adicionada"
        
        if(quant > self._quant_estoque):
            return False, "Quantidade inválida! maior do que o estoque"
        
        self._quant_estoque -= quant
        return True, "Quantidade retirada com sucesso"

    def disponivel(self):
        if(self._quant_estoque > 0):
            return True, "Produto está disponível"
        return False, "Produto não está disponível"

    def __str__(self):
        return f"Nome: {self._nome} | Preço: R${self._preco:.2f} | Quantidade em estoque: {self._quant_estoque}"
    

class Comida(Item):

    __slots__ = ["_nome", "_preco", "_quant_estoque", "_calorias"]

    def __init__(self, nome, preco, quant_estoque, calorias):
        super().__init__(nome, preco, quant_estoque)
        self._calorias = calorias

    def __str__(self):
        return super().__str__() + f" | Calorias: {self._calorias} kcal"


class Bebida(Item):

    __slots__ = ["_nome", "_preco", "_quant_estoque", "_capacidade"]

    def __init__(self, nome, preco, quant_estoque, capacidade):
        super().__init__(nome, preco, quant_estoque)
        self._capacidade = capacidade

    def __str__(self):
        return super().__str__() + f" | Capacidade: {self._capacidade} ml"


class ControleEstoque:

    __slots__ = ["_itens"]

    def __init__(self, itens={}):
        self._itens = itens

    @property
    def itens(self):
        return self._itens
    
    @itens.setter
    def itens(self, itens):
        if(isinstance(itens, dict)):
            self._itens = itens
        else:
            raise ValueError("Item deve ser um dicionário")

    def add_item(self, item):
        if(isinstance(item, Item)):
            if(self.existe(item.nome)[0]):
                return False, "Item já cadastrado"
            self._itens[item.nome] = item
            return True, "Item cadastrado com sucesso"
        return False, "Item inválido"

    def remover_item(self, nome):
        suc, msg = self.existe(nome)
        if(suc):
            self._itens.pop(nome)
            return True, "Item removido com sucesso"
        return suc, msg

    def buscar_item(self, nome):
        suc, msg = self.existe(nome)
        obj = None
        if(suc):
            obj = self._itens[nome]
        return suc, msg, obj
    
    def add_estoque(self, nome, quant):
        suc, msg, obj = self.buscar_item(nome)
        if(suc):
            suc, msg = obj.add_estoque(quant)
        return suc, msg

    def sub_estoque(self, nome, quant):
        suc, msg, obj = self.buscar_item(nome)
        if(suc):
            suc, msg = obj.sub_estoque(quant)
        return suc, msg

    def existe(self, nome):
        if(nome in self._itens.keys()):
            return True, "Item existe"
        return False, "Item não existe"

    def disponivel(self, nome):
        suc, msg = self.existe(nome)
        if(suc):
            return self._itens[nome].disponivel()
        return suc, msg
    
    def exibir_itens(self):
        if(self._itens):
            for i in self._itens.values():
                print(i)
            return True, "Itens exibidos com sucessos"
        return False, "Não há itens cadastrados"


# class Cliente:

#     __slots__ = ["_nome", "_cpf", "_data_nascimento"]

#     def __init__(self, nome, cpf, data_nascimento):
#         self._nome = nome
#         self._cpf = cpf
#         self._data_nascimento = data_nascimento

# class ControleClientes:

#     __slots__ = ["_clientes"]

#     def __init__(self, clientes={}):
#         self._clientes = clientes

# class Pedido:

#     id = 0

#     __slots__ = ["_id", "_itens", "_pago"]

#     def __init__(self):
#         id += 1
#         self._id = id
#         self._itens = []
#         self._pago = False

# class ControlePedidos:

#     __slots__ = ["_pedidos"]

#     def __init__(self, pedidos={}):
#         self._pedidos = pedidos

# class Restaurante:

#     def __init__(self, itens={}, clientes={}, pedidos={}):
#         self._itens = itens
#         self._clientes = clientes
#         self._pedidos = pedidos

#     def exibir_itens(self):
#         pass

#     def exibir_clientes(self):
#         pass

#     def exibir_pedidos(self, cliente, pago):
#         pass

Produto.register(Item)

estoque = ControleEstoque()

estoque.add_item(Item("Item1", 10, 5))
estoque.add_item(Comida("Hamburguer", 14.00, 7, 112))
estoque.add_item(Bebida("Refrigerante", 7.00, 4, 500))

estoque.exibir_itens()
print()

# estoque.remover_item("Item1")
# estoque.exibir_itens()
print()

for i in range(4):
    num = randint(-1, 5)
    
    print(f"Número: {num}")
    if(i % 2 == 0):
        _, imsg = estoque.sub_estoque("Item1", num)
        _, cmsg = estoque.sub_estoque("Hamburguer", num)
        _, bmsg = estoque.sub_estoque("Refrigerante", num)
    else:
        _, imsg = estoque.add_estoque("Item1", num)
        _, cmsg = estoque.add_estoque("Hamburguer", num)
        _, bmsg = estoque.add_estoque("Refrigerante", num)

    print(imsg)
    print(cmsg)
    print(bmsg)
    estoque.exibir_itens()
    print()