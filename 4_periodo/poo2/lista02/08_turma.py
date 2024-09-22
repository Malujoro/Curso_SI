class Estudante:

    __slots__ = ["_nome", "_nota"]

    def __init__(self, nome, nota):
        self._nome = nome
        self._nota = nota

    @property
    def nome(self):
        return self._nome

    @property
    def nota(self):
        return self._nota
    
    @nome.setter
    def nome(self, nome):
        self._nome = nome

    @nota.setter
    def nota(self, nota):
        if(nota >= 0 and nota <= 10):
            self._nota = nota
    
    def exibir(self):
        print(f"Nome: {self._nome} | Nota: {self._nota:.1f}")


class Turma:

    __slots__ = ["_estudantes"]

    def __init__(self, estudantes = []):
        self._estudantes = estudantes

    @property
    def estudantes(self):
        return self._estudantes
    
    @estudantes.setter
    def estudantes(self, estudantes):
        self._estudantes = estudantes

    def addEstudante(self, estudante):
        self._estudantes.append(estudante)
        return True, "Estudante adicionado com sucesso"

    def removerEstudante(self, nomeEstudante):
        for estudante in self._estudantes:
            if(nomeEstudante == estudante.nome):
                self._estudantes.remove(estudante)
                return True, "Estudante removido com sucesso"
        return False, "Estudante não encontrado"

    def calcularMediaTurma(self):
        tam = len(self._estudantes)
        if(tam == 0):
            return False, "Lista de estudantes vazia"
        
        media = 0
        for estudante in self._estudantes:
            media += estudante.nota
        return True, "Média calculada com sucesso", media / tam

    def exibirAcimaMedia(self):
        retorno, msg, media = self.calcularMediaTurma()
        if(retorno):
            msg = "Estudantes exibidos com sucesso"
            for estudante in self._estudantes:
                if(estudante.nota > media):
                    estudante.exibir()
        return retorno, msg

turma = Turma()

turma.addEstudante(Estudante("João", 2))
turma.addEstudante(Estudante("Marcelo", 3))
turma.addEstudante(Estudante("Pedro", 4))
turma.addEstudante(Estudante("Mateus", 5))

print(f"Estudantes com nota maior que a média ({turma.calcularMediaTurma()[2]:.1f}):")
turma.exibirAcimaMedia()

print()
print(turma.removerEstudante("Mateus")[1])
print()

print(f"Estudantes com nota maior que a média ({turma.calcularMediaTurma()[2]:.1f}):")
turma.exibirAcimaMedia()