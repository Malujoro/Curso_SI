from estoque import *

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QListWidget, QListWidgetItem, QMessageBox, QHBoxLayout, QLabel, QDialog, QFormLayout, QLineEdit, QPushButton
from PyQt5.QtGui import QFont
from PyQt5.QtCore import Qt

class TelaEstoque(QWidget):

    def __init__(self, estoque: list[EstoqueMedicamentos] = []):
        super().__init__()
        self._estoque = estoque
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle("Estoque de Medicamentos")
        self.setGeometry(650, 250, 700, 500)

        layout = QVBoxLayout()

        self._lista = QListWidget()

        self.atualizar_lista()

        self._lista.itemClicked.connect(self.abrir_tela_quantidade)

        layout.addWidget(self._lista)

        
        linha_botoes = QHBoxLayout()

        botoes = {"Medicamentos próximo\ndo vencimento": self.abrir_tela_vencimento,
                  "Notificar Reposição": self.abrir_tela_reposicao}
        
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


        self.setLayout(layout)

    def criar_item_personalizado(self, estoque: EstoqueMedicamentos):
        widget = QWidget()
        layout = QHBoxLayout()

        fonte_lista = QFont("Arial", 18)

        textos = [f"{estoque.nome}",
                  f"Estoque: {estoque.quantidade}",
                  f"Validade: [{estoque.data_validade}]"]
        
        labels = []

        for text in textos:
            labels.append(QLabel(text))
            labels[-1].setFont(fonte_lista)
            layout.addWidget(labels[-1])
        
        widget.setLayout(layout)
        return widget

    def adicionar_item_lista(self, estoque: EstoqueMedicamentos):
        item_widget = self.criar_item_personalizado(estoque)
        item = QListWidgetItem(self._lista)
        item.setSizeHint(item_widget.sizeHint())
        self._lista.setItemWidget(item, item_widget)
        item.setData(Qt.UserRole, estoque)

    def atualizar_lista(self):
        self._lista.clear()
        for medic in self._estoque:
            self.adicionar_item_lista(medic)

    def abrir_tela_quantidade(self, item):
        estoque = item.data(Qt.UserRole)
        dialogo = TelaQuantidade(self, estoque)
        dialogo.exec_()

    def abrir_tela_vencimento(self):
        mensagem = ""
        
        for medic in self._estoque:
            diferenca = medic.data_validade - datetime.now().date()
            if(diferenca.days < 30):
                texto = (f"<font size='10'>{medic.nome} | {medic.data_validade}</font><br>")
                mensagem += texto

        if(mensagem == ""):
            mensagem += "<font size='10'>Nenhum</font><br>"
            
        QMessageBox.information(self, "Próximos do vencimento", mensagem, QMessageBox.Ok)

    def abrir_tela_reposicao(self):
        mensagem = ""
        
        for medic in self._estoque:
            if(medic.quantidade == 0):
                texto = (f"<font size='10'>{medic.nome} | {medic.quantidade}</font><br>")
                mensagem += texto
        
        if(mensagem == ""):
            mensagem += "<font size='10'>Nenhum</font><br>"

        QMessageBox.information(self, "Reposição", mensagem, QMessageBox.Ok)

class TelaQuantidade(QDialog):

    def __init__(self, tela_principal: TelaEstoque, estoque: EstoqueMedicamentos):
        super().__init__()
        self._tela_principal = tela_principal
        self._estoque = estoque
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle("Gerenciamento de Quantidade")
        self.setGeometry(500, 150, 500, 100)
        
        layout = QFormLayout()

        fonte_padrao = QFont("Arial", 25)
        fonte_label = fonte_padrao
        fonte_input = fonte_padrao

        atributos = ["Quantidade: "]
        
        self._inputs = []

        for nome in atributos:
            self._inputs.append(QLineEdit(self))
            self._inputs[-1].setFont(fonte_input)
            self._inputs[-1].setFixedSize(250, 50)

            label = QLabel(nome, self)
            label.setFont(fonte_label)
            layout.addRow(label, self._inputs[-1])

        botoes = {"Adicionar": "+",
                  "Subtrair": "-"}

        for texto, sinal in botoes.items():
            botao = QPushButton(texto)
            botao.clicked.connect((lambda _, x = sinal: self.validar_campo(x)))
            layout.addWidget(botao)

        self.setLayout(layout)

    def validar_campo(self, sinal):
        erro = ""

        for input in self._inputs:
            if(input.text() == ""):
                erro = "Preencha todos os campos."
                break

        if(erro == ""):
            try:
                valor = int(self._inputs[0].text())
                if(valor <= 0):
                    erro = "Digite uma quantidade positiva."
            except:
                erro = "Digite uma quantidade numérica."

        if(erro != ""):
            mensagem = (f"<font size='10'>{erro}</font><br>")
            QMessageBox.warning(self, "Erro", mensagem, QMessageBox.Ok)
            return
        
        if(sinal == "+"):
            self.add()
        else:
            self.sub()
        self.close()
        
    def add(self):
        quant = int(self._inputs[0].text())
        ret, msg = self._estoque.add(quant)
        if(ret):
            self._tela_principal.atualizar_lista()
        exibir_box(self, msg, msg)

    def sub(self):
        quant = int(self._inputs[0].text())
        ret, msg = self._estoque.sub(quant)
        if(ret):
            self._tela_principal.atualizar_lista()
        exibir_box(self, msg, msg)


def iniciar_programa(bicicletas: list[EstoqueMedicamentos] = []):
    app = QApplication(sys.argv)
    tela = TelaEstoque(bicicletas)
    tela.show()
    sys.exit(app.exec_())

def exibir_box(widget, titulo, texto):
    texto = (f"<font size='10'>{texto}</font><br>")
    QMessageBox.information(widget, titulo, texto)

if(__name__ == "__main__"):
    medicamentos = []
    medicamentos.append(EstoqueMedicamentos("Medic 1", 10, datetime(2024, 11, 1).date()))
    medicamentos.append(EstoqueMedicamentos("Medic 2", 0, datetime(2025, 2, 12).date()))
    medicamentos.append(EstoqueMedicamentos("Medic 3", 5, datetime(2025, 3, 12).date()))
    medicamentos.append(EstoqueMedicamentos("Medic 4", 0, datetime(2024, 10, 30).date()))
    iniciar_programa(medicamentos)