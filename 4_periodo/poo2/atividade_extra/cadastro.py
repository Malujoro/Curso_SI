class Cliente:

    __slots__ = ["_nome", "_cpf", "_endereco", "_cep", "_telefone"]

    def __init__(self, nome: str, cpf: str, endereco: str, cep: str, telefone: str) -> None:
        self._nome = nome
        self._cpf = cpf
        self._endereco = endereco
        self._cep = cep
        self._telefone = telefone

    @property
    def nome(self) -> str:
        return self._nome
    
    @nome.setter
    def nome(self, nome: str) -> None:
        self._nome = nome

    @property
    def cpf(self) -> str:
        return self._cpf
    
    @cpf.setter
    def cpf(self, cpf: str) -> None:
        self._cpf = cpf

    @property
    def endereco(self) -> str:
        return self._endereco
    
    @endereco.setter
    def endereco(self, endereco: str) -> None:
        self._endereco = endereco

    @property
    def cep(self) -> str:
        return self._cep
    
    @cep.setter
    def cep(self, cep: str) -> None:
        self._cep = cep

    @property
    def nome(self) -> str:
        return self._nome
    
    @nome.setter
    def nome(self, nome: str) -> None:
        self._nome = nome

    @property
    def telefone(self) -> str:
        return self._telefone
    
    @telefone.setter
    def telefone(self, telefone: str) -> None:
        self._telefone = telefone


class Cadastro:

    __slots__ = ["_clientes"]

    def __init__(self, clientes: list[Cliente] = []) -> None:
        self._clientes = clientes

    @property
    def clientes(self) -> list[Cliente]:
        return self._clientes
    
    @clientes.setter
    def clientes(self, clientes: list[Cliente]) -> None:
        self._clientes = clientes

    def cadastrar(self, cliente: Cliente) -> tuple[bool, str]:
        ret, msg, _ = self.verifica_cadastro(cliente.cpf)
        if(not ret):
            self._clientes.append(cliente)
            msg = "Cliente cadastrado com sucesso"
        return (not ret), msg
    
    def get_total(self) -> int:
        return len(self._clientes)

    def verifica_cadastro(self, cpf: str) -> tuple[bool, str, Cliente]:
        for cliente in self._clientes:
            if(cpf == cliente.cpf):
                return True, "Cliente existe", cliente
        return False, "Cliente não existe", None