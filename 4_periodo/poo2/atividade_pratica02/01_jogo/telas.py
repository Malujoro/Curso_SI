from jogos import *
import sys

from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QHBoxLayout, QTableWidget, QTableWidgetItem, QHeaderView, QAbstractItemView, QDialog, QFormLayout, QLineEdit, QLabel, QMessageBox
from PyQt5.QtGui import QFont

class TelaJogos(QWidget):

    def __init__(self, biblioteca: BibliotecaJogos):
        super().__init__()
        self._biblioteca = biblioteca
        self._reverse = False
        self._genero = ""
        self._labels = []
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle("Gerenciador de jogos")
        self.setGeometry(650, 250, 700, 500)

        layout = QVBoxLayout()
        
        colunas = ["Título", "Gênero", "Avaliação"]

        self._tabela = QTableWidget()
        self._tabela.setRowCount(0)
        self._tabela.setColumnCount(len(colunas))

        self._tabela.setHorizontalHeaderLabels(colunas)

        self.atualizar_tabela(self._biblioteca.jogos, updateText=False)

        header = self._tabela.horizontalHeader()
        fonte_header = QFont("Arial", 25, QFont.Bold)
        header.setFont(fonte_header)
        
        header.setSectionResizeMode(QHeaderView.Stretch)

        self._tabela.setEditTriggers(QAbstractItemView.NoEditTriggers)
        layout.addWidget(self._tabela)


        linha_botoes = QHBoxLayout()

        botoes = {"Adicionar Jogo": self.abrir_tela_adicionar_jogo,
                  "Listar jogos\npor gênero": self.listar_jogos_genero,
                  "Filtrar jogos\npor gênero": self.abrir_tela_filtrar_genero}
        
        largura_botao = 200
        altura_botao = 100
        fonte_botao = QFont("Arial", 16)

        for nome, funcao in botoes.items():
            botao = QPushButton(nome)
            botao.clicked.connect(funcao)  
            botao.setMinimumSize(largura_botao, altura_botao)
            botao.setFont(fonte_botao)
            linha_botoes.addWidget(botao)
        
        layout.addLayout(linha_botoes)


        linha_textos = QHBoxLayout()

        textos = {"Gênero": self._genero,
                  "Média das classificações": f"{self._biblioteca.calcular_media_genero(self._genero):.1f}"}

        for indice, (key, value) in enumerate(textos.items()):
            self._labels.append(QLabel(f"{key}: {value}", self))
            self._labels[indice].setStyleSheet("font-size: 24px;")
            linha_textos.addWidget(self._labels[indice])

        layout.addLayout(linha_textos)

        self.setLayout(layout)

    def atualizar_tabela(self, jogos, updateText = True):
        self._tabela.setRowCount(0)
        for jogo in jogos:
            self.adicionar_jogo(jogo, new = False)

        if(updateText):
            self.atualizar_texto()

    def abrir_tela_adicionar_jogo(self):
        dialogo = TelaCadastroJogos(self)
        dialogo.exec_()

    def adicionar_jogo(self, jogo: Jogo, new = True):
        if(new):
            self._biblioteca.add_jogo(jogo)

        num_linhas = self._tabela.rowCount()
        self._tabela.insertRow(num_linhas)

        atributos = [jogo.titulo, jogo.genero, f"{jogo.avaliacao:.1f}"]
        fonte = QFont("Arial", 22)

        for indice, atributo in enumerate(atributos):
            item = QTableWidgetItem(atributo)
            item.setFont(fonte)
            self._tabela.setItem(num_linhas, indice, item)
    
    def listar_jogos_genero(self):
        self._genero = ""
        jogos = self._biblioteca.listar_jogos_genero(self._reverse)
        self.atualizar_tabela(jogos)
        self._reverse = not self._reverse

    def abrir_tela_filtrar_genero(self):
        dialogo = TelaGenero(self)
        dialogo.exec_()

    def filtrar_jogo(self, genero):
        self._genero = genero
        jogos = self._biblioteca.filtrar_jogos_genero(genero)
        self.atualizar_tabela(jogos)

    def atualizar_texto(self):
        textos = {"Gênero": self._genero,
                  "Média das classificações": f"{self._biblioteca.calcular_media_genero(self._genero):.1f}"}

        for indice, (key, value) in enumerate(textos.items()):
            self._labels[indice].setText(f"{key}: {value}")

    def printar(self):
        print("Clicado")


class TelaCadastroJogos(QDialog):
    
    def __init__(self, tela_principal: TelaJogos):
        super().__init__()
        self._tela_principal = tela_principal
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle('Cadastrar Jogo')
        self.setGeometry(500, 150, 500, 200)
        
        layout = QFormLayout()

        fonte_padrao = QFont("Arial", 25)
        fonte_label = fonte_padrao
        fonte_input = fonte_padrao

        atributos = ["Título: ", "Gênero: ", "Avaliação: "]
        
        self.inputs = []

        for indice, nome in enumerate(atributos):
            self.inputs.append(QLineEdit(self))
            self.inputs[indice].setFont(fonte_input)
            self.inputs[indice].setFixedSize(250, 50)

            label = QLabel(nome, self)
            label.setFont(fonte_label)
            layout.addRow(label, self.inputs[indice])

        botao_salvar = QPushButton('Salvar')
        botao_salvar.clicked.connect(self.validar_campos)
        layout.addWidget(botao_salvar)

        self.setLayout(layout)

    def validar_campos(self):
        erro = ""

        for input in self.inputs:
            if(input.text() == ""):
                erro = "Preencha todos os campos."
                break

        if(erro == ""):
            try:
                valor = float(self.inputs[2].text())
                if(valor < 0 or valor > 10):
                    erro = "Digite uma avaliação entre 0 e 10."
            except:
                erro = "Digite um valor numérico para Avaliação."

        if(erro != ""):
            mensagem = (f"<font size='10'>{erro}</font><br>")
            QMessageBox.warning(self, "Erro", mensagem, QMessageBox.Ok)
            return
        
        self.salvar_jogo()

    def salvar_jogo(self):
        atributos = []

        for input in self.inputs:
            atributos.append(input.text().capitalize())

        jogo = Jogo(atributos[0], atributos[1], float(atributos[2]))
        self._tela_principal.adicionar_jogo(jogo)
        self.close()


class TelaGenero(QDialog):

    def __init__(self, tela_principal: TelaJogos):
        super().__init__()
        self._tela_principal = tela_principal
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle('Filtrar Jogo por Gênero')
        self.setGeometry(500, 150, 500, 100)
        
        layout = QFormLayout()

        fonte_padrao = QFont("Arial", 25)
        fonte_label = fonte_padrao
        fonte_input = fonte_padrao

        atributos = ["Gênero: "]
        
        self.inputs = []

        for indice, nome in enumerate(atributos):
            self.inputs.append(QLineEdit(self))
            self.inputs[indice].setFont(fonte_input)
            self.inputs[indice].setFixedSize(250, 50)

            label = QLabel(nome, self)
            label.setFont(fonte_label)
            layout.addRow(label, self.inputs[indice])

        botao_salvar = QPushButton('Filtrar')
        botao_salvar.clicked.connect(self.filtrar_jogo)
        layout.addWidget(botao_salvar)

        self.setLayout(layout)

    def filtrar_jogo(self):
        genero = self.inputs[0].text().capitalize()
        self._tela_principal.filtrar_jogo(genero)
        self.close()

def iniciar_programa(biblioteca: BibliotecaJogos = BibliotecaJogos()):
    app = QApplication(sys.argv)
    tela = TelaJogos(biblioteca)
    tela.show()
    sys.exit(app.exec_())

if(__name__ == "__main__"):
    biblioteca = BibliotecaJogos()
    biblioteca.add_jogo(Jogo("Roblox", "Sandbox", 9))
    biblioteca.add_jogo(Jogo("Csgo", "FPS", 11))
    biblioteca.add_jogo(Jogo("Lol", "Moba", 1.2))
    biblioteca.add_jogo(Jogo("Dota 2", "Moba", 5))
    iniciar_programa(biblioteca)