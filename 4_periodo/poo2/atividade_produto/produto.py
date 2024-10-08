class Produto:

    __slots__ = ["_nome", "_codigo", "_preco", "_quant_estoque", "_descricao"]

    def __init__(self, nome: str, codigo: str, preco: float, quant_estoque: int, descricao: str):
        self._nome = nome
        self._codigo = codigo
        self._preco = preco
        self._quant_estoque = quant_estoque
        self._descricao = descricao

    @property
    def nome(self) -> str:
        return self._nome
    
    @nome.setter
    def nome(self, nome: str) -> None:
        self._nome = nome

    @property
    def codigo(self) -> str:
        return self._codigo
    
    @codigo.setter
    def codigo(self, codigo: str) -> None:
        self._codigo = codigo

    @property
    def preco(self) -> float:
        return self._preco
    
    @preco.setter
    def preco(self, preco: float) -> None:
        if(self._preco >= 0):
            self._preco = preco

    @property
    def quant_estoque(self) -> int:
        return self._quant_estoque
    
    @quant_estoque.setter
    def quant_estoque(self, quant_estoque: int) -> None:
        self._quant_estoque = quant_estoque

    @property
    def descricao(self) -> str:
        return self._descricao
    
    @descricao.setter
    def descricao(self, descricao: str) -> None:
        self._descricao = descricao


class CadastroProdutos:

    __slots__ = ["_produtos"]

    def __init__(self, produtos: list[Produto] = []) -> None:
        self._produtos = produtos
    
    def adicionar_produto(self, produto: Produto) -> None:
        self._produtos.append(produto)
    
    def buscar_produto(self, codigo: str) -> tuple[bool, str, Produto]:
        for produto in self._produtos:
            if(codigo == produto.codigo):
                return True, "Produto existe", produto
        return False, "Produto não existe", None

    def remover_produto(self, codigo: str) -> tuple[bool, str, Produto]:
        ret, msg, produto = self.buscar_produto(codigo)
        if(ret):
            self._produtos.remove(produto)
            msg = "Produto removido com sucesso"
        return ret, msg, produto

    def listar_produtos(self) -> list[Produto]:
        return self._produtos