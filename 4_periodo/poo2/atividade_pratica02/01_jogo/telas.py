from jogos import *
import sys

from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QHBoxLayout, QMainWindow, QTableWidget, QTableWidgetItem, QHeaderView, QAbstractItemView, QDialog, QFormLayout, QLineEdit, QLabel, QMessageBox
from PyQt5.QtGui import QFont

class TelaJogos(QWidget):

    def __init__(self, biblioteca: BibliotecaJogos):
        super().__init__()
        self._biblioteca = biblioteca
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle("Gerenciador de jogos")
        self.setGeometry(650, 250, 500, 300)

        layout = QVBoxLayout()
        
        colunas = ["Título", "Gênero", "Avaliação"]

        self._tabela = QTableWidget()
        self._tabela.setRowCount(0)
        self._tabela.setColumnCount(len(colunas))

        self._tabela.setHorizontalHeaderLabels(colunas)

        for jogo in self._biblioteca.jogos:
            self.adicionar_jogo(jogo, new = False)


        header = self._tabela.horizontalHeader()
        fonte_header = QFont("Arial", 25, QFont.Bold)
        header.setFont(fonte_header)
        
        header.setSectionResizeMode(QHeaderView.Stretch)

        layout.addWidget(self._tabela)

        botoes = {"Adicionar Jogo": self.abrir_tela_adicionar_jogo,
                  "Listar jogos por gênero": self.printar,
                  "Filtrar jogos por gênero": self.printar}
        
        largura_botao = 200
        altura_botao = 100
        fonte_botao = QFont("Arial", 16)
        linha_botoes = QHBoxLayout()

        for nome, funcao in botoes.items():
            botao = QPushButton(nome)
            botao.clicked.connect(funcao)  
            botao.setMinimumSize(largura_botao, altura_botao)
            botao.setFont(fonte_botao)
            linha_botoes.addWidget(botao)
        
        layout.addLayout(linha_botoes)
        self.setLayout(layout)

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

    def printar(self):
        print("Clicado")


class TelaCadastroJogos(QDialog):
    
    def __init__(self, tela_principal: TelaJogos):
        super().__init__()
        self._tela_principal = tela_principal
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle('Cadastrar Jogo')
        self.setGeometry(500, 150, 500, 300)
        
        layout = QFormLayout()

        fonte_padrao = QFont("Arial", 25)
        fonte_label = fonte_padrao
        fonte_input = fonte_padrao

        atributos = ["Título: ", "Gênero: ", "Avaliação: "]
        
        self.inputs = []

        for indice, nome in enumerate(atributos):
            self.inputs.append(QLineEdit(self))
            self.inputs[indice].setFont(fonte_input)
            self.inputs[indice].setFixedSize(250, 30)

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
        jogo = Jogo(self.inputs[0].text(), self.inputs[1].text(), float(self.inputs[2].text()))
        self._tela_principal.adicionar_jogo(jogo)
        self.close()


def iniciar_programa(biblioteca: BibliotecaJogos = BibliotecaJogos()):
    app = QApplication(sys.argv)
    tela = TelaJogos(biblioteca)
    tela.show()
    sys.exit(app.exec_())

if(__name__ == "__main__"):
    biblioteca = BibliotecaJogos()
    biblioteca.add_jogo(Jogo("Roblox", "Sandbox", 9))
    iniciar_programa(biblioteca)