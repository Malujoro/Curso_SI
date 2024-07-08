# Aluno: Mateus da Rocha Sousa

class Usuario:

    __slots__ = ['_nome', '_cpf']

    def __init__(self, nome, cpf):
        self._nome = nome
        self._cpf = cpf

    @property
    def nome(self):
        return self._nome

    @property
    def cpf(self):
        return self._cpf

    def exibir(self):
        print(f"Nome: {self._nome} | CPF: {self._cpf}")
        return True, "Usuário exibido com sucesso"

class Livro:

    __slots__ = ['_nome', '_issn', '_quant']

    def __init__(self, nome, issn, quant):
        self._nome = nome
        self._issn = issn
        self._quant = quant

    @property
    def nome(self):
        return self._nome

    @property
    def issn(self):
        return self._issn

    def existeEstoque(self):
        return self._quant > 0
    
    def aumentar(self):
        self._quant += 1
        return True, "Quantidade de livros aumentada com sucesso"

    def diminuir(self):
        if(self._quant > 0):
            self._quant -= 1
            return True, "Quantidade de livros diminuída com sucesso"
        return False, "Não é possível diminuir quantidade de livros"

    def exibir(self):
        print(f"Nome: {self._nome} | ISSN: {self._issn} | Quantidade: {self._quant}")
        return True, "Livro exibido com sucesso"

class Biblioteca:

    __slots__ = ['_livros', '_emprestimos', '_usuarios']

    def __init__(self):
        self._livros = {}
        self._emprestimos = {}
        self._usuarios = {}

    def cadastrarUsuario(self, nome, cpf):
        if(cpf in self._usuarios.keys()):
            return False, "Usuário já cadastrado"
        self._usuarios[cpf] = Usuario(nome, cpf)
        return True, "Usuário cadastrado com sucesso"

    def cadastrarLivro(self, nome, issn, quant):
        if(issn in self._livros.keys()):
            return False, "Livro já cadastrado"

        self._livros[issn] = Livro(nome, issn, quant)
        return True

    def fazerEmprestimo(self, cpf, issn):
        if(cpf in self._usuarios.keys()):
            if(issn in self._livros.keys()):
                if(self._livros[issn].existeEstoque()):
                    aux = Emprestimo(self._usuarios[cpf], self._livros[issn])
                    if(cpf in self._emprestimos.keys()):
                        self._emprestimos[cpf].append(aux)
                    else:
                        self._emprestimos[cpf] = [aux]
                    return True, "Empréstimo feito com sucesso"
                return False, "Livro não está em estoque"
            return False, "Livro não existe"
        return False, "Usuário não existe"

    def fazerDevolucao(self, cpf, issn):
        if(cpf in self._usuarios.keys()):
            if(issn in self._livros.keys()):
                if(cpf in self._emprestimos.keys()):
                    for i in self._emprestimos[cpf]:
                        if(i.livro == self._livros[issn] and i.status):
                            i.devolver()
                            return True, "Devolução feita com sucesso"
                    return False, "Cliente não pegou o livro com esse código"
                return False, "Cliente não fez empréstimos"
            return False, "Livro não existe"
        return False, "Usuário não existe"

    def exibirUsuarios(self):
        if(self._usuarios):
            for i in self._usuarios.values():
                i.exibir()
            return True, "Usuários exibidos com sucesso"
        return False, "Não há usuários cadastrados"

    def exibirLivros(self):
        if(self._livros):
            for i in self._livros.values():
                i.exibir()
            return True, "Livros exibidos com sucesso"
        return False, "Não há livros cadastrados"
    
    def exibirEmprestimos(self):
        if(self._emprestimos):
            for i in self._emprestimos.values():
                for j in i:
                    j.exibir()
            return True, "Empréstimos exibidos com sucesso"
        return False, "Não há empréstimos realizados"

class Emprestimo:

    __slots__ = ['_usuario', '_livro', '_status']

    def __init__(self, usuario, livro):
        self._usuario = usuario
        self._livro = livro
        self._livro.diminuir()
        self._status = True

    @property
    def status(self):
        return self._status

    @property
    def livro(self):
        return self._livro

    def devolver(self):
        self._livro.aumentar()
        self._status = False
    
    def exibir(self):
        if(self._status == True):
            palavra = "Emprestado"
        else:
            palavra = "Devolvido"
        print(f"Usuário: {self._usuario.nome} | CPF: {self._usuario.cpf} | Livro: {self._livro.nome} | ISSN: {self._livro.issn} | Status: {palavra}")


bib = Biblioteca()

bib.cadastrarUsuario("Mateus", "123")
bib.cadastrarUsuario("Lucas", "456")
bib.cadastrarUsuario("Alef", "899")

bib.cadastrarLivro("A", "111", 4)
bib.cadastrarLivro("Ebook", "222", 22)
bib.cadastrarLivro("C", "333", 5)

bib.exibirLivros()
print()

bib.fazerEmprestimo("123", "333")
bib.fazerEmprestimo("899", "222")

bib.exibirEmprestimos()
print()
bib.exibirLivros()
print()

bib.fazerDevolucao("899", "222")

bib.exibirEmprestimos()
print()
bib.exibirLivros()
print()
bib.exibirUsuarios()