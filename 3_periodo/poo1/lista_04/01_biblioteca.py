import abc

class Emprestavel(abc.ABC):

    @abc.abstractmethod
    def obter_info(self):
        """
            Método abstrato que retorna informações básicas sobre a mídia
        """
        pass

    @abc.abstractmethod
    def verificar_disponibilidade(self):
        """
            Método abstrato que verifica se a mídia está disponível para empréstimo
        """
        pass


class Midia(abc.ABC):

    def __init__(self, titulo, autor, disponivel=True):
        self._titulo = titulo
        self._autor = autor
        self._disponivel = disponivel

    @property
    def titulo(self):
        return self._titulo

    @property
    def autor(self):
        return self._autor

    @property
    def disponivel(self):
        return self._disponivel

    def mudar_disponibilidade(self):
        if(self._disponivel):
            self._disponivel = False
        else:
            self._disponivel = True


class EBook(Midia):

    def __init__(self, titulo, autor, formato, disponivel=True):
        super().__init__(titulo, autor, disponivel)
        self._formato = formato

    @property
    def formato(self):
        return self._formato

    def obter_info(self):
        return f"Título: {self.titulo} | Autor: {self.autor} | Formato: {self._formato}"

    def verificar_disponibilidade(self):
        return self.disponivel


class AudioBook(Midia):

    def __init__(self, titulo, autor, duracao, disponivel=True):
        super().__init__(titulo, autor, disponivel)
        self._duracao = duracao

    @property
    def duracao(self):
        return self._duracao

    def obter_info(self):
        return f"Título: {self.titulo} | Autor: {self.autor} | Duração: {self._duracao}"

    def verificar_disponibilidade(self):
        return self.disponivel


class RevistaDigital(Midia):

    def __init__(self, titulo, edicao, ano_publicacao, disponivel=True):
        super().__init__(titulo, edicao, disponivel)
        self._edicao = edicao
        self._ano_publicacao = ano_publicacao

    @property
    def ano_publicacao(self):
        return self._ano_publicacao

    @property
    def edicao(self):
        return self._edicao

    def obter_info(self):
        return f"Título: {self.titulo} | Edição: {self.edicao} | Ano de publicação: {self._ano_publicacao}"

    def verificar_disponibilidade(self):
        return self.disponivel


class Biblioteca:

    def __init__(self):
        self._itens_emprestados = []

    def emprestar_midia(self, midia):
        if(not isinstance(midia, Emprestavel)):
            return False, "Mídia não emprestável"
        
        if(not midia.verificar_disponibilidade()):
            return False, "Mídia não disponível"
        
        self._itens_emprestados.append(midia)
        midia.mudar_disponibilidade()
        return True, "Mídia emprestada"

    def devolver_midia(self, midia):
        if(not isinstance(midia, Emprestavel)):
            return False, "Mídia não emprestável"
        
        if(midia.verificar_disponibilidade()):
            return False, "Mídia não foi emprestada"

        self._itens_emprestados.remove(midia)
        midia.mudar_disponibilidade()
        return True, "Mídia devolvida"

    def listar_itens_emprestados(self):
        if(not self._itens_emprestados):
            return False, "Não há mídias emprestadas"
        
        print("Mídias emprestadas:")
        for item in self._itens_emprestados:
            print(item.obter_info())
        return True, "Mídias exibidas com sucesso"
        

Emprestavel.register(EBook)
Emprestavel.register(AudioBook)
Emprestavel.register(RevistaDigital)

biblioteca = Biblioteca()

ebook1 = EBook("Como treinar seu Dragão", "Soluço", "PDF")
audiobook1 = AudioBook("O Rei Leão", "Disney", 120)
revista1 = RevistaDigital("Recreio", 121, 2024)

print(biblioteca.emprestar_midia(ebook1)[1])
print(biblioteca.emprestar_midia(audiobook1)[1])
print(biblioteca.emprestar_midia(revista1)[1])
print()

print(biblioteca.listar_itens_emprestados()[1])
print()

print(biblioteca.devolver_midia(ebook1)[1])
print()

print(biblioteca.listar_itens_emprestados()[1])