import functools as ft

class Jogo:

    __slots__ = ["_titulo", "_genero", "_avaliacao"]

    def __init__(self, titulo: str, genero: str, avaliacao: float) -> None:
        self._titulo = titulo
        self._genero = genero
        self.avaliacao = avaliacao

    @property
    def titulo(self) -> str:
        return self._titulo
    
    @titulo.setter
    def titulo(self, titulo: str) -> None:
        self._titulo = titulo

    @property
    def genero(self) -> str:
        return self._genero
    
    @genero.setter
    def genero(self, genero: str) -> None:
        self._genero = genero

    @property
    def avaliacao(self) -> float:
        return self._avaliacao
    
    @avaliacao.setter
    def avaliacao(self, avaliacao: float) -> None:
        if(avaliacao < 0 or avaliacao > 10):
            avaliacao = 0
        self._avaliacao = avaliacao

    def __str__(self) -> str:
        return f"Título: {self._titulo} | Gênero: {self._genero} | Avaliação: {self._avaliacao:.1f}"


class BibliotecaJogos:

    __slots__ = ["_jogos"]

    def __init__(self, jogos: list[Jogo] = []):
        self._jogos = jogos

    @property
    def jogos(self) -> list[Jogo]:
        return self._jogos
    
    @jogos.setter
    def jogos(self, jogos: list[Jogo]) -> None:
        self._jogos = jogos
    
    def add_jogo(self, jogo: Jogo) -> None:
        self._jogos.append(jogo)

    def listar_jogos_genero(self) -> list[Jogo]:
        return sorted(self._jogos, key = lambda jogo: jogo.genero)
    
    def filtrar_jogos_genero(self, genero: str = "") -> list[Jogo]:

        if(genero == ""):
            jogos_genero = self._jogos.copy()
        else:
            jogos_genero = []
            for jogo in self._jogos:
                if(jogo.genero.upper() == genero.upper()):
                    jogos_genero.append(jogo)

        return jogos_genero

    def calcular_media_genero(self, genero: str = ""):
        jogos_genero = self.filtrar_jogos_genero(genero)
        tamanho = len(jogos_genero)
        media = 0

        if(tamanho > 0):
            for jogo in jogos_genero:
                media += jogo.avaliacao

            media /= tamanho

        return media


if(__name__ == "__main__"):
    def exibir_jogos(jogos: list[Jogo]):
        for jogo in jogos:
            print(jogo)

    biblioteca = BibliotecaJogos()
    biblioteca.add_jogo(Jogo("Csgo", "FPS", 11))
    biblioteca.add_jogo(Jogo("Lol", "Moba", 1.2))
    biblioteca.add_jogo(Jogo("Dota 2", "Moba", 5))
    biblioteca.add_jogo(Jogo("Roblox", "Sandbox", 9))

    exibir_jogos(biblioteca.jogos)
    print()
    exibir_jogos(biblioteca.listar_jogos_genero())
    print()

    genero = "Moba"
    exibir_jogos(biblioteca.filtrar_jogos_genero(genero))
    print()

    print(f"Média de avaliações dos jogos {genero}: {biblioteca.calcular_media_genero(genero):.1f}")