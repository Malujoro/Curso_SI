from aula import *

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QLabel, QComboBox, QPushButton, QProgressBar, QMessageBox, QMainWindow
from PyQt5.QtGui import QFont

idiomas = ["ingles", "espanhol"]

class TelaMenu(QMainWindow):

    def __init__(self, aulas: dict[Aula]):
        super().__init__()
        self._aulas = aulas
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle("Programação em outros idiomas")
        self.setGeometry(500, 150, 400, 250)

        central_widget = QWidget(self)

        botoes = {"Inglês": self.abrir_tela_ingles,
                  "Espanhol": self.abrir_tela_espanhol}

        largura_botao = 200
        altura_botao = 100
        fonte_botao = QFont("Arial", 25)

        layout = QVBoxLayout()

        for nome, funcao in botoes.items():
            botao = QPushButton(nome)
            botao.clicked.connect(funcao)   
            botao.setMinimumSize(largura_botao, altura_botao)
            botao.setFont(fonte_botao)
            layout.addWidget(botao)

        central_widget.setLayout(layout)

        self.setCentralWidget(central_widget)

    def abrir_tela_ingles(self):
        self._tela_ingles = TelaAulas(self._aulas[idiomas[0]])
        self._tela_ingles.show()

    def abrir_tela_espanhol(self):
        self._tela_espanhol = TelaAulas(self._aulas[idiomas[1]])
        self._tela_espanhol.show()

class TelaAulas(QWidget):
    def __init__(self, aulas: list[Aula]):
        super().__init__()
        self._aulas = aulas
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle("Programação em outros idiomas")
        self.setGeometry(500, 150, 800, 500)

        layout = QVBoxLayout()

        self._combo_aulas = QComboBox()
        fonte_combo = QFont("Arial", 20)

        label_titulo = QLabel("Escolha a aula:")
        label_titulo.setFont(fonte_combo)
        layout.addWidget(label_titulo)

        self._titulos = [aula.titulo for aula in self._aulas]
        self._titulosCompletos = [False for x in range(len(self._titulos))]

        self._combo_aulas.addItems(self._titulos)
        self._combo_aulas.setFont(fonte_combo)

        self._combo_aulas.currentIndexChanged.connect(self.atualizar_completo)

        layout.addWidget(self._combo_aulas)

        self._label_completo = QLabel("")
        self._label_completo.setFont(QFont("Arial", 16))
        layout.addWidget(self._label_completo)

        self.atualizar_completo()

        self._label_chave = QLabel("Palavras-chave: ")
        self._label_chave.setFont(QFont("Arial", 16))
        layout.addWidget(self._label_chave)

        botoes = {"Mostrar Palavras": self.mostrar_palavras,
                  "Concluir Aula": self.concluir_aula}

        largura_botao = 200
        altura_botao = 100
        fonte_botao = QFont("Arial", 16)

        for titulo, funcao in botoes.items():
            botao = QPushButton(titulo)
            botao.clicked.connect(funcao)
            botao.setMinimumSize(largura_botao, altura_botao)
            botao.setFont(fonte_botao)
            layout.addWidget(botao)

        self._progresso = QProgressBar()
        self._progresso.setValue(0)
        layout.addWidget(self._progresso)

        self.setLayout(layout)

        self._aulas_concluidas = 0
        self._total_aulas = len(self._aulas)

    def mostrar_palavras(self):
        palavras = []
        aula_selecionada = self._combo_aulas.currentText()

        for aula in self._aulas:
            if(aula.titulo == aula_selecionada):
                palavras = aula.exibir_palavras_chave()

        self._label_chave.setText(f"Palavras-chave: {palavras}")

    def concluir_aula(self):
        aula_selecionada = self._combo_aulas.currentText()
        indice = self._titulos.index(aula_selecionada)
        
        if(not self._titulosCompletos[indice]):
            if(self._aulas_concluidas < self._total_aulas):
                texto = ("<font size='10'>Deseja marcar a aula como concluída?</font><br>")
                resposta = QMessageBox.question(self, "Concluir Aula", texto,QMessageBox.Yes | QMessageBox.No, QMessageBox.No)

                if(resposta == QMessageBox.Yes):
                    self._aulas_concluidas += 1
                    progresso_atual = (self._aulas_concluidas / self._total_aulas) * 100
                    self._progresso.setValue(int(progresso_atual))

                    self._titulosCompletos[indice] = True
                    self.atualizar_completo()
                    exibir_box(self, "Aula Concluída", "Aula concluída com sucesso")

        else: 
            exibir_box(self, "Erro", "Você já marcou essa aula como concluída")

        if(self._aulas_concluidas == self._total_aulas):
            exibir_box(self, "Curso Concluído", "Você completou todas as aulas")

    def atualizar_completo(self):
        aula_selecionada = self._combo_aulas.currentText()
        indice = self._titulos.index(aula_selecionada)
        self._label_completo.setText(f"Completo? {self._titulosCompletos[indice]}")
        
def iniciar_programa(aulas: dict[Aula]):
    app = QApplication(sys.argv)
    tela = TelaMenu(aulas)
    tela.show()
    sys.exit(app.exec_())

def exibir_box(widget, titulo, texto):
    texto = (f"<font size='10'>{texto}</font><br>")
    QMessageBox.information(widget, titulo, texto)

if(__name__ == "__main__"):
    aulas = {idiomas[0]: [],
             idiomas[1]: []}
    
    aulas[idiomas[0]].append(AulaIngles("Introduction to Programming", "Iniciante"))
    aulas[idiomas[0]].append(AulaIngles("Intermediate Programming", "Intermediário"))
    aulas[idiomas[0]].append(AulaIngles("Advanced Programming", "Difícil"))
    
    aulas[idiomas[1]].append(AulaEspanhol("Introducción a la Programación", "Iniciante"))
    aulas[idiomas[1]].append(AulaEspanhol("Programación Intermedia","Intermediário"))
    aulas[idiomas[1]].append(AulaEspanhol("Programación Avanzada", "Difícil"))

    iniciar_programa(aulas)