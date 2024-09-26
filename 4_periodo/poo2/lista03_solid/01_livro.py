# É uma classe que representa um livro
class Livro:

    __slots__ = ["_titulo", "_autor", "_numeroPaginas"]

    def __init__(self, titulo: str, autor: str, numeroPaginas: int):
        self._titulo = titulo
        self._autor = autor
        self._numeroPaginas = numeroPaginas

    @property
    def titulo(self):
        return self._titulo
    
    @property
    def autor(self):
        return self._autor
    
    @property
    def numeroPaginas(self):
        return self._numeroPaginas
    
    @titulo.setter
    def titulo(self, titulo: str):
        self._titulo = titulo
    
    @autor.setter
    def autor(self, autor: str):
        self._autor = autor
    
    @numeroPaginas.setter
    def numeroPaginas(self, numeroPaginas: int):
        if(numeroPaginas > 0):
            self._numeroPaginas = numeroPaginas

# É uma classe responsável por  o estoque de livros
class ControleEstoque:

    def __init__(self, livros: Livro = []):
        self._livros = livros

    @property
    def livros(self):
        return self._livros
    
    @livros.setter
    def livros(self, livros: Livro):
        self._livros = livros

    def exibir(self):
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