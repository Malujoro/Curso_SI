class Cliente:

    __slots__ = ["_nome", "_cpf", "_endereco", "_cep", "_telefone"]

    def __init__(self, nome: str, cpf: str, endereco: str, cep: str, telefone: str):
        self._nome = nome
        self._cpf = cpf
        self._endereco = endereco
        self._cep = cep
        self._telefone = telefone

    @property
    def nome(self):
        return self._nome
    
    @nome.setter
    def nome(self, nome: str):
        self._nome = nome

    @property
    def cpf(self):
        return self._cpf
    
    @cpf.setter
    def cpf(self, cpf: str):
        self._cpf = cpf

    @property
    def endereco(self):
        return self._endereco
    
    @endereco.setter
    def endereco(self, endereco: str):
        self._endereco = endereco

    @property
    def cep(self):
        return self._cep
    
    @cep.setter
    def cep(self, cep: str):
        self._cep = cep

    @property
    def nome(self):
        return self._nome
    
    @nome.setter
    def nome(self, nome: str):
        self._nome = nome

    @property
    def telefone(self):
        return self._telefone
    
    @telefone.setter
    def telefone(self, telefone: str):
        self._telefone = telefone

    def __str__(self):
        return f"{self._nome} | {self._cpf} | {self._endereco} | {self._cep} | {self._telefone}"


class Cadastro:

    __slots__ = ["_clientes", "_total"]

    def __init__(self, clientes: Cliente = {}):
        self._clientes = clientes
        self._total = 0

    @property
    def clientes(self):
        return self._clientes
    
    @clientes.setter
    def clientes(self, clientes: Cliente):
        self._clientes = clientes

    @property
    def total(self):
        return self._total
    
    @total.setter
    def total(self, total: int):
        if(total > 0):
            self._total = total

    def cadastrar(self, cliente: Cliente):
        ret, msg = self.verifica(cliente.cpf)
        if(not ret):
            self._clientes[cliente.cpf] = cliente
            self._total += 1
            msg = "Cliente cadastrado com sucesso"
        return ret, msg

    def verifica(self, cpf: str):
        if(cpf in self._clientes.keys()):
            return True, "Cliente existe"
        return False, "Cliente não existe"