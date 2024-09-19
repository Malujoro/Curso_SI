class Livro:

    __slots__ = ["_titulo", "_autor", "_preco"]

    def __init__(self, titulo, autor, preco):
        self._titulo = titulo
        self._autor = autor
        self._preco = preco


    @property
    def titulo(self):
        return self._titulo
    
    @property
    def autor(self):
        return self._autor
    
    @property
    def preco(self):
        return self._preco
    

    @titulo.setter
    def titulo(self, titulo):
        self._titulo = titulo
    
    @autor.setter
    def autor(self, autor):
        self._autor = autor

    @preco.setter
    def preco(self, preco):
        if(preco > 0):
            self._preco = preco

    
    def descontoPorcentagem(self, porcentagem):
        if(porcentagem <= 0 or porcentagem > 100):
            return False, "Porcentagem inválida"

        self._preco -= self._preco * porcentagem / 100
        return True, "Desconto aplicado com sucesso"

    def descontoValor(self, valor):
        if(valor <= 0 or valor > self._preco):
            return False, "Valor inválido"

        self._preco -= valor
        return True, "Desconto aplicado com sucesso"

    def exibir(self):
        print(f"Título: {self._titulo}")
        print(f"Autor: {self._autor}")
        print(f"Preço: R${self._preco:.2f}")


livros = []
livros.append(Livro("Como treinar seu dragão", "Soluço", 30))
livros.append(Livro("Dragon Ball", "Toriyama", 50))
livros.append(Livro("Naruto", "Kishimoto", 15))
livros.append(Livro("One Piece", "Oda", 20))
livros.append(Livro("Redes de Computadores", "Tanenbaum", 20))

livros[1].descontoPorcentagem(10)
livros[0].descontoValor(1)

print("Livros acima de R$25.00 reais:\n")
for livro in livros:
    if(livro.preco > 25):
        livro.exibir()
        print()