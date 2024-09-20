class Jogador:

    __slots__ = ["_nome", "_posicao", "_idade"]

    def __init__(self, nome, posicao, idade):
        self._nome = nome
        self._posicao = posicao
        self._idade = idade
    
    @property
    def nome(self):
        return self._nome
    
    @property
    def posicao(self):
        return self._posicao
    
    @property
    def idade(self):
        return self._idade
    
    @nome.setter
    def nome(self, nome):
        self._nome = nome

    @posicao.setter
    def posicao(self, posicao):
        self._posicao = posicao

    @idade.setter
    def idade(self, idade):
        if(idade >= 0):
            self._idade = idade
        
    def exibir(self):
        print(f"Nome: {self._nome} | Posição: {self._posicao} | Idade: {self._idade}")
        return True, "Jogador exibido com sucesso"


class Time:

    __slots__ = ["_jogadores"]

    def __init__(self, jogadores = []):
        self._jogadores = jogadores

    @property
    def jogadores(self):
        return self._jogadores
    
    @jogadores.setter
    def jogadores(self, jogadores):
        self._jogadores = jogadores

    def addJogador(self, jogador):
        self._jogadores.append(jogador)
        return True, "Jogador adicionado com sucesso"

    def removerJogador(self, nomeJogador):
        for jogador in self._jogadores:
            if(nomeJogador == jogador.nome):
                self._jogadores.remove(jogador)
                return True, "Jogador removido com sucesso"
        return False, "Jogador não encontrado"
    
    def exibirJogadorMaior30(self):
        for jogador in self._jogadores:
            if(jogador.idade > 30):
                jogador.exibir()
        return True, "Time exibido com sucesso"
    

time = Time()

time.addJogador(Jogador("João", "Atacante", 22))
time.addJogador(Jogador("Marcelo", "Goleiro", 34))
time.addJogador(Jogador("Pedro", "Meio-Campo", 25))
time.addJogador(Jogador("César", "Zagueiro", 35))

print("Jogadores com idade maior que 30:")
time.exibirJogadorMaior30()

print()
print(time.removerJogador("César")[1])
print()

print("Jogadores com idade maior que 30:")
time.exibirJogadorMaior30()