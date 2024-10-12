class Aula:

    __slots__ = ["_titulo", "_nivel_dificuldade"]

    def __init__(self, titulo: str, nivel_dificuldade: str) -> None:
        self._titulo = titulo
        self._nivel_dificuldade = nivel_dificuldade

    @property
    def titulo(self) -> str:
        return self._titulo
    
    @titulo.setter
    def titulo(self, titulo: str) -> None:
        self._titulo = titulo

    @property
    def nivel_dificuldade(self) -> str:
        return self._nivel_dificuldade
    
    @nivel_dificuldade.setter
    def nivel_dificuldade(self, nivel_dificuldade: str) -> None:
        self._nivel_dificuldade = nivel_dificuldade


class AulaIngles(Aula):

    def __init__(self, titulo: str, nivel_dificuldade: str) -> None:
        super().__init__(titulo, nivel_dificuldade)

    def exibir_palavras_chave(self) -> list[str]:
        return ["hello", "world", "snake", "programming", "class"]
    
class AulaEspanhol(Aula):

    def __init__(self, titulo: str, nivel_dificuldade: str) -> None:
        super().__init__(titulo, nivel_dificuldade)

    def exibir_palavras_chave(self) -> list[str]:
        return ["hola", "mundo", "serpiente", "programación", "clase"]
    
if(__name__ == "__main__"):
    print(AulaIngles("Introduction to Programming", "Iniciante").exibir_palavras_chave())
    print(AulaEspanhol("Introducción a la Programación", "Iniciante").exibir_palavras_chave())