import abc
from datetime import datetime



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

    def __init__(self, nome: str, preco: float, quant_estoque: int):
        self._nome = nome.capitalize()
        self._preco = preco
        self._quant_estoque = quant_estoque

    @property
    def nome(self):
        return self._nome
    
    @property
    def preco(self):
        return self._preco

    def add_estoque(self, quant: int):
        if(quant <= 0):
            return False, "Quantidade inválida! Não pode ser adicionada"
        
        self._quant_estoque += quant
        return True, "Quantidade adicionada com sucesso"

    def sub_estoque(self, quant: int):
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

    def __init__(self, nome: str, preco: float, quant_estoque: int, calorias: int):
        super().__init__(nome, preco, quant_estoque)
        self._calorias = calorias
    
    @property
    def calorias(self):
        return self._calorias
            
    def __str__(self):
        return super().__str__() + f" | Calorias: {self._calorias} cal"


class Bebida(Item):

    __slots__ = ["_nome", "_preco", "_quant_estoque", "_capacidade"]

    def __init__(self, nome: str, preco: float, quant_estoque: int, capacidade: int):
        super().__init__(nome, preco, quant_estoque)
        self._capacidade = capacidade

    @property
    def capacidade(self):
        return self._capacidade

    def __str__(self):
        return super().__str__() + f" | Capacidade: {self._capacidade} ml"


class ControleEstoque:

    __slots__ = ["_itens"]

    def __init__(self, itens: dict={}):
        self._itens = itens

    @property
    def itens(self):
        return self._itens
    
    @itens.setter
    def itens(self, itens: dict):
        if(isinstance(itens, dict)):
            self._itens = itens
        else:
            raise ValueError("Item deve ser um dicionário")

    def existe(self, nome: str):
        nome = nome.capitalize()
        if(nome in self._itens.keys()):
            return True, "Item existe"
        return False, "Item não existe"

    def add_item(self, item: Item):
        if(isinstance(item, Item)):
            if(self.existe(item.nome)[0]):
                return False, "Item já cadastrado"
            self._itens[item.nome] = item
            return True, "Item cadastrado com sucesso"
        return False, "Item inválido"

    def remover_item(self, nome: str):
        nome = nome.capitalize()
        suc, msg = self.existe(nome)
        if(suc):
            self._itens.pop(nome)
            msg = "Item removido com sucesso"
        return suc, msg

    def buscar_item(self, nome: str):
        nome = nome.capitalize()
        suc, msg = self.existe(nome)
        obj = None
        if(suc):
            obj = self._itens[nome]
        return suc, msg, obj
    
    def add_estoque(self, nome: str, quant: int):
        nome = nome.capitalize()
        suc, msg, obj = self.buscar_item(nome)
        if(suc):
            suc, msg = obj.add_estoque(quant)
        return suc, msg

    def sub_estoque(self, nome: str, quant: int):
        nome = nome.capitalize()
        suc, msg, obj = self.buscar_item(nome)
        if(suc):
            suc, msg = obj.sub_estoque(quant)
        return suc, msg

    def disponivel(self, nome: str):
        nome = nome.capitalize()
        suc, msg = self.existe(nome)
        if(suc):
            return self._itens[nome].disponivel()
        return suc, msg
    
    def exibir_itens(self, disponivel: bool=False):
        if(self._itens):
            for i in self._itens.values():
                if(not disponivel or (disponivel and i.disponivel()[0])):
                    print(i)
            return True, "Itens exibidos com sucessos"
        return False, "Não há itens cadastrados"


class Cliente:

    __slots__ = ["_nome", "_cpf", "_data_nascimento"]

    def __init__(self, nome: str, cpf: str, data_nascimento: str):
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

    def __init__(self, clientes: dict={}):
        self._clientes = clientes

    @property
    def clientes(self):
        return self._clientes
    
    @clientes.setter
    def clientes(self, clientes: dict):
        if(isinstance(clientes, dict)):
            self._clientes = clientes
        else:
            raise ValueError("Cliente deve ser um dicionário")

    def existe(self, cpf: str):
        if(cpf in self._clientes.keys()):
            return True, "Cliente existe"
        return False, "Cliente não existe"

    def add_cliente(self, cliente: Cliente):
        if(isinstance(cliente, Cliente)):
            if(self.existe(cliente.cpf)[0]):
                return False, "Cliente já cadastrado"
            self._clientes[cliente.cpf] = cliente
            return True, "Cliente cadastrado com sucesso"
        return False, "Cliente inválido"
    
    def remover_cliente(self, cpf: str):
        suc, msg = self.existe(cpf)
        if(suc):
            self._clientes.pop(cpf)
            msg = "Cliente removido com sucesso"
        return suc, msg

    def buscar_cliente(self, cpf: str):
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

    def __init__(self, cpf: str):
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
    def itens(self):
        return self._itens
    
    @property
    def pago(self):
        return self._pago

    def item_existe(self, nome: str):
        nome = nome.capitalize()
        if(nome in self._itens.keys()):
            return True, "Item existe"
        return False, "Item não existe"
    
    def add_quant(self, nome: str, quant: int):
        suc, msg = self.item_existe(nome)
        if(suc):
            if(self._pago):
                return False, "Não é possível alterar pedido pago"
            suc, msg = self._itens[nome][0].sub_estoque(quant)
            if(suc):
                self._itens[nome][1] += quant
                msg = "Quantidade adicionada com sucesso"
        return suc, msg

    def sub_quant(self, nome: str, quant: int):
        suc, msg = self.item_existe(nome)
        if(suc):
            if(self._pago):
                return False, "Não é possível alterar pedido pago"
            if(quant <= 0 or quant > self._itens[nome][1]):
                return False, "Quantidade inválida"
            self._itens[nome][0].add_estoque(quant)
            self._itens[nome][1] -= quant
            if(self._itens[nome][1] == 0):
                self._itens.pop(nome)
            msg = "Quantidade removida com sucesso"
        return suc, msg

    def add_item(self, item: Item, quant: int):
        if(isinstance(item, Item)):
            if(self.item_existe(item.nome)[0]):
                return False, "Item já adicionado"
            if(self._pago):
                return False, "Não é possível adicionar item em pedido pago"
            self._itens[item.nome] = [item, 0]
            suc, msg = self.add_quant(item.nome, quant)
            if(suc):
                msg = "Item adicionado com sucesso"
            else:
                self.remover_item(item.nome)
            return suc, msg
        
        return False, "Item inválido"
    
    def remover_item(self, nome: str):
        suc, msg = self.item_existe(nome)
        if(suc):
            if(self._pago):
                return False, "Não é possível remover item de pedido pago"
            self.sub_quant(nome, self._itens[nome][1])
            return True, "Item removido com sucesso"
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
        return False, "Não há itens no pedido"

    def exibir(self):
        print(f"ID: {self._id} | Pago: {self._pago} | Cliente: {self._cpf}")
        return self.exibir_itens()


class ControlePedidos:

    __slots__ = ["_pedidos"]

    def __init__(self, pedidos: dict={}):
        self._pedidos = pedidos

    @property
    def pedidos(self):
        return self._pedidos
    
    @pedidos.setter
    def pedidos(self, pedidos: dict):
        if(isinstance(pedidos, dict)):
            self._pedidos = pedidos
        else:
            raise ValueError("Pedido deve ser um dicionário")
        
    def existe(self, id: int):
        if(id in self._pedidos.keys()):
            return True, "Pedido existe"
        return False, "Pedido não existe"

    def existe_pessoa(self, cpf: str):
        for ped in self._pedidos.values():
            if(ped.cpf == cpf):
                return True, "Há um pedido com esse cliente"
        return False, "Cliente não fez nenhum pedido"
    
    def existe_item(self, nome: str):
        for ped in self._pedidos.values():
            if(ped.item_existe(nome)):
                return True, "Há um pedido com esse item"
        return False, "Item não está em nenhum pedido"

    def add_pedido(self, cpf: str):
        pedido = Pedido(cpf)
        self._pedidos[pedido.id] = pedido
        return True, "Pedido adicionado com sucesso"

    def remover_pedido(self, id: int):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            if(not obj.pago):
                self._pedidos.pop(id)
                return True, "Pedido removido com sucesso"
            return False, "Não é possível remover pedido pago"
        return suc, msg
    
    def buscar_pedido(self, id: int):
        suc, msg = self.existe(id)
        obj = None
        if(suc):
            obj = self.pedidos[id]
        return suc, msg, obj
    
    def pagar_pedido(self, id: int):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            if(not obj.itens):
                return False, "Não é possível pagar pedido sem itens"
            if(obj.pago):
                return False, "Pedido já foi pago"
            obj.alterar_status()
            return True, "Pedido pago com sucesso"
        return suc, msg
    
    def add_item(self, id: int, item: Item, quant: int):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.add_item(item, quant)
        return suc, msg

    def remover_item(self, id: int, nome: str):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            suc, msg = obj.item_existe(nome)
            if(suc):
                return obj.remover_item(nome)
        return suc, msg

    def add_quant(self, id: int, nome: str, quant: int):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            suc, msg = obj.item_existe(nome)
            if(suc):
                return obj.add_quant(nome, quant)
        return suc, msg

    def sub_quant(self, id: int, nome: str, quant: int):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            suc, msg = obj.item_existe(nome)
            if(suc):
                return obj.sub_quant(nome, quant)
        return suc, msg

    def calcular_preco(self, id: int):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.calcular_preco()
        return suc, msg

    def calcular_capacidade(self, id: int):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.calcular_capacidade()
        return suc, msg

    def calcular_calorias(self, id: int):
        suc, msg, obj = self.buscar_pedido(id)
        if(suc):
            return obj.calcular_calorias()
        return suc, msg

    def exibir_pedidos(self, cpf: str=None, pago: bool=None):
        if(self._pedidos):
            for i in self._pedidos.values():
                if((cpf == None or i.cpf == cpf) and (pago == None or i.pago == pago)):
                    i.exibir()
                    print()
            return True, "Pedidos exibidos com sucessos"
        msg = "Não há Pedidos cadastrados"
        print(msg)
        return False, msg


def leia_nome(txt="Nome: "):
    while True:
        try:
            nome = input(txt).capitalize()
            assert(nome)
            return nome
        except:
            print("\nErro! Digite um nome válido\n")

def leia_int(txt):
    while True:
        try:
            num = int(input(txt))
            assert(num > 0)
            return num
        except AssertionError:
            print("\nErro! Digite um número positivo\n")
        except:
            print("\nErro! Digite um valor inteiro\n")

def leia_float(txt="Preço: R$"):
    while True:
        try:
            num = float(input(txt))
            assert(num > 0)
            return num
        except AssertionError:
            print("\nErro! Digite um número positivo\n")
        except:
            print("\nErro! Digite um valor decimal\n")

def calcular_idade(data):
    data_atual = datetime.now().date()
    data_atual = str(data_atual).split("-")
    data = str(data).split("-")
    
    data_atual = [int(data_atual[0]), int(data_atual[1]), int(data_atual[2])]
    data = [int(data[0]), int(data[1]), int(data[2])]

    idade = data_atual[0] - data[0]

    if((data_atual[1] < data[1]) or ((data_atual[1] == data[1]) and (data_atual[2] < data[2]))):
       idade -= 1

    return idade

def leia_data(txt="Data de nascimento: ", formato="%d/%m/%Y"):
    while True:
        try:
            entrada = input(txt)
            data = str(datetime.strptime(entrada, formato)).split()[0]
            idade = calcular_idade(data)
            assert(idade >= 18)
            return data
        except AssertionError:
            print("\nErro! Cliente deve possuir 18 anos ou mais\n")
        except:
            print("\nErro! Digite uma data válida (dd/mm/aaaa)\n")

def leia_cpf(txt="CPF: "):
    while True:
        try:
            entrada = (input(txt))
            assert(len(entrada) == 14 and entrada[3] == "." and entrada[7] == "." and entrada[11] in "-/.")
            cpf = ""
            for i in entrada:
                if(i in "/"):
                    cpf += "-"
                else:
                    cpf += i
            return cpf
        except:
            print("\nErro! Digite um cpf válido (123.456.789-00)\n")

def menu_estoque():
    while True:
        print("GERENCIAMENTO DE ESTOQUE")
        print("[1] | Adicionar item")
        print("[2] | Adicionar comida")
        print("[3] | Adicionar bebida")
        print("[4] | Remover item")
        print("[5] | Buscar item")
        print("[6] | Adicionar estoque")
        print("[7] | Diminuir estoque")
        print("[8] | Exibir itens disponíveis")
        print("[9] | Exibir todos os itens")
        print("[0] | Voltar")
        op = input("Opção: ")
        print()

        if(op == "1"):
            _, msg = estoque.add_item(Item(leia_nome(), leia_float(), leia_int("Quantidade em estoque: ")))

        elif(op == "2"):
            _, msg = estoque.add_item(Comida(leia_nome(), leia_float(), leia_int("Quantidade em estoque: "), leia_int("Calorias: ")))

        elif(op == "3"):
            _, msg = estoque.add_item(Bebida(leia_nome(), leia_float(), leia_int("Quantidade em estoque: "), leia_int("Capacidade: ")))

        elif(op == "4"):
            nome = input("Nome: ")
            suc, msg = pedidos.existe_item(nome)
            if(not suc):
                _, msg = estoque.remover_item()

        elif(op == "5"):
            suc, msg, obj = estoque.buscar_item(input("Nome: "))
            if(suc):
                print()
                print(obj)

        elif(op == "6"):
            _, msg = estoque.add_estoque(leia_nome(), leia_int("Quantidade: "))

        elif(op == "7"):
            _, msg = estoque.sub_estoque(leia_nome(), leia_int("Quantidade: "))

        elif(op == "8" or op == "9"):
            print("[Itens em estoque]")
            _, msg = estoque.exibir_itens(op == "8")

        elif(op == "0"):
            print("Voltando ao menu...")
            return
        else:
            msg = "Erro! Opção inválida"
        print(f"\n[{msg}]\n")

def menu_clientes():
    while True:
        print("GERENCIAMENTO DE CLIENTES")
        print("[1] | Adicionar cliente")
        print("[2] | Remover cliente")
        print("[3] | Buscar cliente")
        print("[4] | Exibir todos os clientes")
        print("[0] | Voltar")
        op = input("Opção: ")
        print()

        if(op == "1"):
            _, msg = clientes.add_cliente(Cliente(leia_nome(), leia_cpf(), leia_data()))

        elif(op == "2"):
            cpf = leia_cpf()
            suc, msg = pedidos.existe_pessoa(cpf)
            if(not suc):
                _, msg = clientes.remover_cliente(cpf)

                    
        elif(op == "3"):
            suc, msg, obj = clientes.buscar_cliente(leia_cpf())
            if(suc):
                print()
                print(obj)

        elif(op == "4"):
            print("[Clientes cadastrados]")
            _, msg = clientes.exibir_clientes()
            

        elif(op == "0"):
            print("Voltando ao menu...")
            return
        else:
            msg = "Erro! Opção inválida"
        print(f"\n[{msg}]\n")

def menu_pedidos():
    while True:
        print("GERENCIAMENTO DE PEDIDOS")
        print(" [1] | Adicionar pedido")
        print(" [2] | Remover pedido")
        print(" [3] | Buscar pedido")
        print(" [4] | Pagar pedido")
        print(" [5] | Adicionar item no pedido")
        print(" [6] | Remover item do pedido")
        print(" [7] | Aumentar quantidade de item no pedido")
        print(" [8] | Diminuir quantidade de item no pedido")
        print(" [9] | Calcular preço do pedido")
        print("[10] | Calcular capacidade do pedido")
        print("[11] | Calcular calorias do pedido")
        print("[12] | Exibir todos os pedidos")
        print("[13] | Exibir pedidos pagos")
        print("[14] | Exibir pedidos pendentes")
        print("[15] | Exibir pedidos por cliente")
        print(" [0] | Voltar")
        op = input("Opção: ")
        print()

        if(op == "1"):
            cpf = leia_cpf()
            suc, msg, obj = clientes.buscar_cliente(cpf)
            if(suc):
                _, msg = pedidos.add_pedido(cpf)

        elif(op == "2"):
            _, msg = pedidos.remover_pedido(leia_int("ID: "))
                    
        elif(op == "3"):
            suc, msg, obj = pedidos.buscar_pedido(leia_int("ID: "))
            if(suc):
                print()
                obj.exibir()

        elif(op == "4"):
            _, msg = pedidos.pagar_pedido(leia_int("ID: "))

        elif(op == "5"):
            suc, msg, obj = estoque.buscar_item(leia_nome())
            if(suc):
                _, msg = pedidos.add_item(leia_int("ID: "), obj, leia_int("Quantidade: "))

        elif(op == "6"):
            _, msg = pedidos.remover_item(leia_int("ID: "), leia_nome())

        elif(op == "7"):
            _, msg = pedidos.add_quant(leia_int("ID: "), leia_nome(), leia_int("Quantidade: "))

        elif(op == "8"):
            _, msg = pedidos.sub_quant(leia_int("ID: "), leia_nome(), leia_int("Quantidade: "))

        elif(op == "9"):
            _, msg, result = pedidos.calcular_preco(leia_int("ID: "))
            print(f"Preço: R${result}")

        elif(op == "10"):
            _, msg, result = pedidos.calcular_capacidade(leia_int("ID: "))
            print(f"Capacidade: {result} ml")

        elif(op == "11"):
            _, msg, result = pedidos.calcular_calorias(leia_int("ID: "))
            print(f"Calorias: {result} cal")

        elif(op == "12" or op == "13" or op == "14" or op == "15"):
            cpf = None
            pago = None

            if(op == "13"):
                pago = True
            elif(op == "14"):
                pago = False
            if(op == "15"):
                cpf = leia_cpf()

            print("[Pedidos cadastrados]")

            _, msg = pedidos.exibir_pedidos(cpf, pago)

        elif(op == "0"):
            print("Voltando ao menu...")
            return
        else:
            msg = "Erro! Opção inválida"
        print(f"\n[{msg}]\n")

def menu_principal():
    while True:
        print("SEJA BEM-VINDO AO RESTAURANTE PYFOOD")
        print("[1] | Gerenciar estoque")
        print("[2] | Gerenciar clientes")
        print("[3] | Gerenciar pedidos")
        print("[0] | Sair do programa")
        op = input("Opção: ")
        print()

        if(op == "1"):
            menu_estoque()

        elif(op == "2"):
            menu_clientes()

        elif(op == "3"):
            menu_pedidos()

        elif(op == "0"):
            print("Finalizando programa...")
            return
        
        else:
            print("Erro! Opção inválida")

        print()


Produto.register(Item)
estoque = ControleEstoque()
clientes = ControleClientes()
pedidos = ControlePedidos()

# estoque.add_item(Comida("Maçã", 10, 30, 20))
# estoque.add_item(Comida("Banana", 7, 15, 15))
# estoque.add_item(Bebida("Coca-cola", 10, 20, 500))

# clientes.add_cliente(Cliente("Mateus da rocha sousa", "123.123.123-11", "02/07/2004"))
# clientes.add_cliente(Cliente("Lucas", "111.222.333-44", "12/12/1212"))

# pedidos.add_pedido("123.123.123-11")
# pedidos.add_pedido("111.222.333-44")

menu_principal()