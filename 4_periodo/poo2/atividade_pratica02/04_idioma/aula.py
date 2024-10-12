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

    def exibir_palavras_chave(self):
        pass


class AulaIngles(Aula):
    def __init__(self, titulo, nivel_dificuldade):
        super().__init__(titulo, nivel_dificuldade)

    def exibir_palavras_chave(self):
        if(self._nivel_dificuldade == "Iniciante"):
            return ["hello", "world", "programming", "class", "snake"]
        elif(self._nivel_dificuldade == "Intermediário"):
            return ["function", "variable", "loop", "conditional", "parameter"]
        elif(self._nivel_dificuldade == "Difícil"):
            return ["recursion", "algorithm", "polymorphism", "inheritance", "abstraction"]
        else:
            return ["Language", "Programming"]


class AulaEspanhol(Aula):
    def __init__(self, titulo, nivel_dificuldade):
        super().__init__(titulo, nivel_dificuldade)

    def exibir_palavras_chave(self):
        if(self._nivel_dificuldade == "Iniciante"):
            return ["hola", "mundo", "programación", "clase", "serpiente"]
        elif(self._nivel_dificuldade == "Intermediário"):
            return ["función", "variable", "bucle", "condicional", "parámetro"]
        elif(self._nivel_dificuldade == "Difícil"):
            return ["recursión", "algoritmo", "polimorfismo", "herencia", "abstracción"]
        else:
            return ["Lenguaje", "Programación"]

    
if(__name__ == "__main__"):
    aulas = {"ingles": [],
             "espanhol": []}
    
    aulas["ingles"].append(AulaIngles("Introduction to Programming", "Iniciante"))
    aulas["ingles"].append(AulaIngles("Intermediate Programming", "Intermediário"))
    aulas["ingles"].append(AulaIngles("Advanced Programming", "Difícil"))
    
    aulas["espanhol"].append(AulaEspanhol("Introducción a la Programación", "Iniciante"))
    aulas["espanhol"].append(AulaEspanhol("Programación Intermedia","Intermediário"))
    aulas["espanhol"].append(AulaEspanhol("Programación Avanzada", "Difícil"))

    for dicio in aulas.values():
        for aula in dicio:
            print(aula.exibir_palavras_chave())