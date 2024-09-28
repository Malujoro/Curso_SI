class Livro:
    """
    Classe que representa um livro
    
    Atributos
    ---------
    titulo: str

    autor: str
    
    numeroPaginas: int
    """
    __slots__ = ["_titulo", "_autor", "_numeroPaginas"]

    def __init__(self, titulo: str, autor: str, numeroPaginas: int) -> None:
        self._titulo = titulo
        self._autor = autor
        self._numeroPaginas = numeroPaginas

    @property
    def titulo(self) -> str:
        return self._titulo

    @titulo.setter
    def titulo(self, titulo: str) -> None:
        self._titulo = titulo

    @property
    def autor(self) -> str:
        return self._autor

    @autor.setter
    def autor(self, autor: str) -> None:
        self._autor = autor

    @property
    def numeroPaginas(self) -> int:
        return self._numeroPaginas

    @numeroPaginas.setter
    def numeroPaginas(self, numeroPaginas: int) -> None:
        if(numeroPaginas > 0):
            self._numeroPaginas = numeroPaginas


class ControleEstoque:
    """
    Classe responsável por controlar o estoque de livros
    
    Atributos
    ---------
    livros: [Livro]
    
    Métodos
    -------
    exibir()
        Exibe a quantidade de livros no estoque
    """

    def __init__(self, livros: Livro = []) -> None:
        self._livros = livros

    @property
    def livros(self) -> Livro:
        return self._livros
    
    @livros.setter
    def livros(self, livros: Livro) -> None:
        self._livros = livros

    def exibir(self) -> None:
        """
        Exibe a quantidade de livros no estoque
        """
        quant = len(self._livros)
        if(quant > 0):
            print(f"Existem {quant} livros no estoque")
        else:
            print("Não existem livros no estoque")


livros = []
livros.append(Livro("Como treinar seu dragão", "Soluço", 30))
livros.append(Livro("Dragon Ball", "Toriyama", 50))
livros.append(Livro("Naruto", "Kishimoto", 15))

controleEstoque = ControleEstoque(livros)
controleEstoque.exibir()