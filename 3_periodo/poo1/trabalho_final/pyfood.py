import abc

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


class Item:

    __slots__ = ["_nome", "_preco", "_quant_estoque"]

    def __init__(self, nome, preco, quant_estoque):
        self._nome = nome.capitalize()
        self._preco = preco
        self._quant_estoque = quant_estoque

    @property
    def nome(self):
        return self._nome
    
    @property
    def preco(self):
        return self._preco

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
    
    @property
    def calorias(self):
        return self._calorias
            
    def __str__(self):
        return super().__str__() + f" | Calorias: {self._calorias} cal"


class Bebida(Item):

    __slots__ = ["_nome", "_preco", "_quant_estoque", "_capacidade"]

    def __init__(self, nome, preco, quant_estoque, capacidade):
        super().__init__(nome, preco, quant_estoque)
        self._capacidade = capacidade

    @property
    def capacidade(self):
        return self._capacidade

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

    def existe(self, nome):
        nome = nome.capitalize()
        if(nome in self._itens.keys()):
            return True, "Item existe"
        return False, "Item não existe"

    def add_item(self, item):
        if(isinstance(item, Item)):
            if(self.existe(item.nome)[0]):
                return False, "Item já cadastrado"
            self._itens[item.nome] = item
            return True, "Item cadastrado com sucesso"
        return False, "Item inválido"

    def remover_item(self, nome):
        nome = nome.capitalize()
        suc, msg = self.existe(nome)
        if(suc):
            self._itens.pop(nome)
            msg = "Item removido com sucesso"
        return suc, msg

    def buscar_item(self, nome):
        nome = nome.capitalize()
        suc, msg = self.existe(nome)
        obj = None
        if(suc):
            obj = self._itens[nome]
        return suc, msg, obj
    
    def add_estoque(self, nome, quant):
        nome = nome.capitalize()
        suc, msg, obj = self.buscar_item(nome)
        if(suc):
            suc, msg = obj.add_estoque(quant)
        return suc, msg

    def sub_estoque(self, nome, quant):
        nome = nome.capitalize()
        suc, msg, obj = self.buscar_item(nome)
        if(suc):
            suc, msg = obj.sub_estoque(quant)
        return suc, msg

    def disponivel(self, nome):
        nome = nome.capitalize()
        suc, msg = self.existe(nome)
        if(suc):
            return self._itens[nome].disponivel()
        return suc, msg
    
    def exibir_itens(self, disponivel=False):
        if(self._itens):
            for i in self._itens.values():
                if(not disponivel or (disponivel and i.disponivel()[0])):
                    print(i)
            return True, "Itens exibidos com sucessos"
        msg = "Não há itens cadastrados"
        print(msg)
        return False, msg


class Cliente:

    __slots__ = ["_nome", "_cpf", "_data_nascimento"]

    def __init__(self, nome, cpf, data_nascimento):
        self._nome = nome.capitalize()
        self._cpf = cpf
        self._data_nascimento = data_nascimento

    @property
    def cpf(self):
        return self._cpf

    def __str__(self):
        return f"Nome: {self._nome} | CPF: {self._cpf} | Data de nascimento: {self._data_nascimento}"


class ControleClientes:

    __slots__ = ["_clientes"]

    def __init__(self, clientes={}):
        self._clientes = clientes

    @property
    def clientes(self):
        return self._clientes
    
    @clientes.setter
    def clientes(self, clientes):
        if(isinstance(clientes, dict)):
            self._clientes = clientes
        else:
            raise ValueError("Cliente deve ser um dicionário")

    def existe(self, cpf):
        if(cpf in self._clientes.keys()):
            return True, "Cliente existe"
        return False, "Cliente não existe"

    def add_cliente(self, cliente):
        if(isinstance(cliente, Cliente)):
            if(self.existe(cliente.cpf)[0]):
                return False, "Cliente já cadastrado"
            self._clientes[cliente.cpf] = cliente
            return True, "Cliente cadastrado com sucesso"
        return False, "Cliente inválido"
    
    def remover_cliente(self, cpf):
        suc, msg = self.existe(cpf)
        if(suc):
            self._clientes.pop(cpf)
            msg = "Cliente removido com sucesso"
        return suc, msg

    def buscar_cliente(self, cpf):
        suc, msg = self.existe(cpf)
        obj = None
        if(suc):
            obj = self._clientes[cpf]
        return suc, msg, obj
        
    def exibir_clientes(self):
        if(self._clientes):
            for i in self._clientes.values():
                print(i)
            return True, "Clientes exibidos com sucessos"
        msg = "Não há clientes cadastrados"
        print(msg)
        return False, msg


class Pedido:

    __id = 0

    __slots__ = ["_id", "_itens", "_cpf", "_pago"]

    def __init__(self, cpf):
        Pedido.__id += 1
        self._id = Pedido.__id
        self._itens = {}
        self._cpf = cpf
        self._pago = False

    @property
    def id(self):
        return self._id
    
    @property
    def cpf(self):
        return self._cpf
    
    @property
    def pago(self):
        return self._pago

    def item_existe(self, item):
        item = item.capitalize()
        if(item in self._itens.keys()):
            return True, "Item existe"
        return False, "Item não existe"
    
    def add_quant(self, nome, quant):
        suc, msg = self.item_existe(nome)
        if(suc):
            suc, msg = self._itens[nome][0].sub_estoque(quant)
            if(suc):
                self._itens[nome][1] += quant
                msg = "Quantidade adicionada com sucesso"
        return suc, msg

    def sub_quant(self, nome, quant):
        suc, msg = self.item_existe(nome)
        if(suc):
            if(quant <= 0 or quant > self._itens[nome][1]):
                return False, "Quantidade inválida"
            self._itens[nome][0].add_estoque(quant)
            self._itens[nome][1] -= quant
            if(self._itens[nome][1] == 0):
                self._itens.pop(nome)
            msg = "Quantidade removida com sucesso"
        return suc, msg

    def add_item(self, item, quant):
        if(isinstance(item, Item)):
            if(self.item_existe(item.nome)[0]):
                return False, "Item já adicionado"

            self._itens[item.nome] = [item, 0]
            suc, msg = self.add_quant(item.nome, quant)
            if(suc):
                msg = "Item adicionado com sucesso"
            else:
                self.remover_item(item.nome)
            return suc, msg
        
        return False, "Item inválido"
    
    def remover_item(self, nome):
        suc, msg = self.item_existe(nome)
        if(suc):
            if(not self._pago):
                self.sub_quant(nome, self._itens[nome][1])
                self._itens.pop(nome)
                return True, "Item removido com sucesso"
            return False, "Não é possível remover item de pedido pago"
        return suc, msg

    def calcular_preco(self):
        preco = 0
        if(self._itens):
            for lista in self._itens.values():
                preco += lista[0].preco * lista[1]
            return True, "Preço calculado com sucesso", preco
        return False, "Não há itens cadastrados", preco

    def calcular_calorias(self):
        calorias = 0
        if(self._itens):
            for lista in self._itens.values():
                if(isinstance(lista[0], Comida)):
                    calorias += lista[0].calorias * lista[1]
            return True, "Calorias calculadas com sucesso", calorias
        return False, "Não há itens cadastrados", calorias

    def calcular_capacidade(self):
        capacidade = 0
        if(self._itens):
            for lista in self._itens.values():
                if(isinstance(lista[0], Bebida)):
                    capacidade += lista[0].capacidade * lista[1]
            return True, "Capacidade calculada com sucesso", capacidade
        return False, "Não há itens cadastrados", capacidade

    def alterar_status(self):
        self._pago = not self._pago

    def exibir_itens(self):
        cont = 1
        if(self._itens):
            for key, value in self._itens.items():
                print(f"{cont}º: {key}, Quantidade: {value[1]}")
                cont += 1
            return True, "Itens impressos com sucesso"
        msg = "Não há itens no pedido"
        print(msg)
        return False, msg

    def exibir(self):
        print(f"ID: {self._id} | Pago: {self._pago} | Cliente: {self._cpf}")
        return self.exibir_itens()


class ControlePedidos:

    __slots__ = ["_pedidos"]

    def __init__(self, pedidos={}):
        self._pedidos = pedidos

    @property
    def pedidos(self):
        return self._pedidos
    
    @pedidos.setter
    def pedidos(self, pedidos):
        if(isinstance(pedidos, dict)):
            self._pedidos = pedidos
        else:
            raise ValueError("Pedido deve ser um dicionário")
        
    def existe(self, id):
        if(id in self._pedidos.keys()):
            return True, "Pedido existe"
        return False, "Pedido não existe"

    def add_pedido(self, cpf):
        pedido = Pedido(cpf)
        self._pedidos[pedido.id] = pedido

    def remover_pedido(self, id):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            if(not obj.pago):
                self._pedidos.pop(id)
                return True, "Pedido removido com sucesso"
            return False, "Não é possível remover pedido pago"
        return suc, msg
    
    def buscar_pedido(self, id):
        suc, msg = self.existe(id)
        obj = None
        if(suc):
            obj = self.pedidos[id]
        return suc, msg, obj
    
    def pagar_pedido(self, id):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            if(obj.pago):
                return False, "Pedido já foi pago"
            obj.alterar_status()
            return True, "Pedido pago com sucesso"
        return suc, msg
    
    def add_item(self, id, item, quant):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.add_item(item, quant)
        return suc, msg

    def remover_item(self, id, nome):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.remover_item(nome)
        return suc, msg

    def add_quant(self, id, nome, quant):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.add_quant(nome, quant)
        return suc, msg

    def sub_quant(self, id, nome, quant):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.sub_quant(nome, quant)
        return suc, msg

    def calcular_preco(self, id):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.calcular_preco()
        return suc, msg

    def calcular_capacidade(self, id):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.calcular_capacidade()
        return suc, msg

    def calcular_calorias(self, id):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.calcular_calorias()
        return suc, msg

    def exibir_pedidos(self, cpf=None, pago=None):
        if(self._pedidos):
            for i in self._pedidos.values():
                if((cpf == None or i.cpf == cpf) and (pago == None or i.pago == pago)):
                    i.exibir()
                    print()
            return True, "Pedidos exibidos com sucessos"
        msg = "Não há Pedidos cadastrados"
        print(msg)
        return False, msg


class Restaurante:

    __slots__ = ["_estoque", "_clientes", "_pedidos"]

    def __init__(self, estoque=None, clientes=None, pedidos=None):
        self._estoque = estoque
        self._clientes = clientes
        self._pedidos = pedidos

    @property
    def estoque(self):
        return self._estoque

    @estoque.setter
    def estoque(self, estoque):
        if(isinstance(estoque, ControleEstoque)):
            self._estoque = estoque
        else:
            raise ValueError("Estoque deve ser do tipo ControleEstoque")
        
    @property
    def clientes(self):
        return self._clientes
    
    @clientes.setter
    def clientes(self, clientes):
        if(isinstance(clientes, ControleClientes)):
            self._clientes = clientes
        else:
            raise ValueError("Clientes deve ser do tipo ControleClientes")
    
    @property
    def pedidos(self):
        return self._pedidos
    
    @pedidos.setter
    def pedidos(self, pedidos):
        if(isinstance(pedidos, ControlePedidos)):
            self._pedidos = pedidos
        else:
            raise ValueError("Pedidos deve ser do tipo ControlePedidos")

    def exibir_itens(self, disponivel=False):
        self.estoque.exibir_itens(disponivel)

    def exibir_clientes(self):
        self.clientes.exibir_clientes()

    def exibir_pedidos(self, cpf, pago):
        self.pedidos.exibir_pedidos(cpf, pago)



Produto.register(Item)

estoque = ControleEstoque()

item1 = Item("Item1", 10, 0)
comida1 = Comida("Hamburguer", 14.00, 7, 112)
bebida1 = Bebida("Refrigerante", 7.00, 4, 500)

estoque.add_item(item1)
estoque.add_item(comida1)
estoque.add_item(bebida1)

print("[Estoque]")
estoque.exibir_itens()

pedidos = ControlePedidos()
pedidos.add_pedido("123")
pedido = pedidos.buscar_pedido(1)[2]
pedidos.add_item(1, item1, 3)

pedidos.add_pedido("321")
pedido = pedidos.buscar_pedido(2)[2]
pedidos.add_item(2, comida1, 4)


pedidos.add_pedido("321")
pedido = pedidos.buscar_pedido(3)[2]
# pedidos.add_item()
pedidos.add_item(3, bebida1, 2)

print()
print("[Todos os pedidos]")
pedidos.exibir_pedidos()


# clientes = ControleClientes()
# clientes.add_cliente(Cliente("João da silva", "98765432100", "04/11/1958"))
# clientes.add_cliente(Cliente("Mateus da Rocha Sousa", "12345678900", "02/07/2004"))
# clientes.add_cliente(Cliente("Roger santos", "12300000", "13/02/2014"))

# print(clientes.buscar_cliente("12345678900"))
# print(clientes.buscar_cliente("12312312312"))

# clientes.exibir_clientes()