class Item:

    __slots__ = ["_nome", "_preco", "_quantidade"]

    def __init__(self, nome: str, preco: float, quantidade: int) -> None:
        self._nome = nome
        self._preco = preco
        self._quantidade = quantidade

    @property
    def nome(self) -> str:
        return self._nome
    
    @nome.setter
    def nome(self, nome: str) -> None:
        self._nome = nome

    @property
    def preco(self) -> float:
        return self._preco
    
    @preco.setter
    def preco(self, preco: float) -> None:
        if(preco >= 0):
            self._preco = preco

    @property
    def quantidade(self) -> int:
        return self._quantidade
    
    @quantidade.setter
    def quantidade(self, quantidade: int) -> None:
        if(quantidade >= 0):
            self._quantidade = quantidade
            

class CarrinhoCompras:

    __slots__ = ["_itens"]

    def __init__(self, itens: list[Item] = []) -> None:
        self._itens = itens

    @property
    def itens(self) -> list[Item]:
        return self._itens
    
    @itens.setter
    def itens(self, itens: list[Item]):
        self._itens = itens

    def add(self, item: Item) -> None:
        self._itens.append(item)

    def remover(self, item: Item) -> tuple[bool, str]:
        if(item in self._itens):
            self._itens.remove(item)
            return True, "Removido com sucesso"
        return False, "Não foi possível remover"
    
    def calcular_total(self) -> float:
        total = 0
        for item in self._itens:
            total += item.preco * item.quantidade
        return total

    def aplicar_desconto(self, desconto: float, valor_minimo: float) -> float:
        total = self.calcular_total()
        if(total >= valor_minimo and desconto <= total):
            total -= desconto
        return total