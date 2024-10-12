from bicicleta import *

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QListWidget, QListWidgetItem, QMessageBox, QHBoxLayout, QLabel, QDialog, QFormLayout, QLineEdit, QPushButton
from PyQt5.QtGui import QFont
from PyQt5.QtCore import Qt


class TelaBicicletas(QWidget):
    def __init__(self, bicicletas: list[Bicicleta] = []):
        super().__init__()
        self._bicicletas = bicicletas
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle("Aluguel de Bicicletas")
        self.setGeometry(650, 250, 700, 500)

        layout = QVBoxLayout()

        self._lista = QListWidget()

        self.atualizar_lista()

        self._lista.itemClicked.connect(self.abrir_tela_horas)

        layout.addWidget(self._lista)

        self.setLayout(layout)

    def criar_item_personalizado(self, bicicleta: Bicicleta):
        widget = QWidget()
        layout = QHBoxLayout()

        fonte_lista = QFont("Arial", 18)

        textos = [f"{bicicleta.modelo}",
                  f"R$ {bicicleta.tarifa_hora:.2f} / Hora",
                  f"Alugada? [{bicicleta.alugada}]"]
        
        labels = []

        for text in textos:
            labels.append(QLabel(text))
            labels[-1].setFont(fonte_lista)
            layout.addWidget(labels[-1])
        
        widget.setLayout(layout)
        return widget

    def adicionar_item_lista(self, bicicleta: Bicicleta):
        item_widget = self.criar_item_personalizado(bicicleta)
        item = QListWidgetItem(self._lista)
        item.setSizeHint(item_widget.sizeHint())
        self._lista.setItemWidget(item, item_widget)
        item.setData(Qt.UserRole, bicicleta)

    def atualizar_lista(self):
        self._lista.clear()
        for bike in self._bicicletas:
            self.adicionar_item_lista(bike)

    def abrir_tela_horas(self, item):
        bicicleta = item.data(Qt.UserRole)
        dialogo = TelaHora(self, bicicleta)
        if(not bicicleta.alugada):
            dialogo.exec_()
        else:
            msg_box = QMessageBox(self)
            msg_box.setWindowTitle("Indisponível")

            texto = (f"<font size='10'>Bicicleta já está alugada</font><br>")
            msg_box.setText(texto)

            botao_alugar = msg_box.addButton('Desalugar', QMessageBox.ActionRole)
            msg_box.addButton('Fechar', QMessageBox.RejectRole)

            msg_box.exec_()

            if msg_box.clickedButton() == botao_alugar:
                dialogo.desalugar()


class TelaHora(QDialog):

    def __init__(self, tela_principal: TelaBicicletas, bicicleta: Bicicleta):
        super().__init__()
        self._tela_principal = tela_principal
        self._bicicleta = bicicleta
        self.iniciar_ui()

    def iniciar_ui(self):
        self.setWindowTitle('Calcular tarifa total')
        self.setGeometry(500, 150, 500, 100)
        
        layout = QFormLayout()

        fonte_padrao = QFont("Arial", 25)
        fonte_label = fonte_padrao
        fonte_input = fonte_padrao

        atributos = ["Horas: "]
        
        self._inputs = []

        for nome in atributos:
            self._inputs.append(QLineEdit(self))
            self._inputs[-1].setFont(fonte_input)
            self._inputs[-1].setFixedSize(250, 50)

            label = QLabel(nome, self)
            label.setFont(fonte_label)
            layout.addRow(label, self._inputs[-1])

        botao_salvar = QPushButton('Calcular')
        botao_salvar.clicked.connect(self.validar_campo)
        layout.addWidget(botao_salvar)

        self.setLayout(layout)

    def validar_campo(self):
        erro = ""

        for input in self._inputs:
            if(input.text() == ""):
                erro = "Preencha todos os campos."
                break

        if(erro == ""):
            try:
                valor = float(self._inputs[0].text())
                if(valor <= 0):
                    erro = "Digite uma quantidade de horas positiva."
            except:
                erro = "Digite uma quantidade numérica de horas."

        if(erro != ""):
            mensagem = (f"<font size='10'>{erro}</font><br>")
            QMessageBox.warning(self, "Erro", mensagem, QMessageBox.Ok)
            return
        
        self.exibir_total()

    def exibir_total(self):
        msg_box = QMessageBox(self)
        msg_box.setWindowTitle("Informações da Bicicleta")

        horas = int(self._inputs[0].text())
        texto = (f"<font size='10'>Total: R$ {self._bicicleta.custo_aluguel(horas):.2f}</font><br>")
        msg_box.setText(texto)

        botao_alugar = msg_box.addButton('Alugar', QMessageBox.ActionRole)
        botao_fechar = msg_box.addButton('Fechar', QMessageBox.RejectRole)

        msg_box.exec_()

        if msg_box.clickedButton() == botao_alugar:
            self.alugar()
            self.fechar_janela()
        elif msg_box.clickedButton() == botao_fechar:
            self.fechar_janela()

        
    def alugar(self):
        self._bicicleta.alugar()
        self._tela_principal.atualizar_lista()
        texto = (f"<font size='10'>Bicicleta alugada com sucesso!</font><br>")
        QMessageBox.information(self, "Alugada", texto)

    def desalugar(self):
        self._bicicleta.desalugar()
        self._tela_principal.atualizar_lista()
        texto = (f"<font size='10'>Bicicleta desalugada com sucesso!</font><br>")
        QMessageBox.information(self, "Desalugada", texto)

    def fechar_janela(self):
        self.close()


def iniciar_programa(bicicletas: list[Bicicleta] = []):
    app = QApplication(sys.argv)
    tela = TelaBicicletas(bicicletas)
    tela.show()
    sys.exit(app.exec_())

if(__name__ == "__main__"):
    bicicletas = []
    bicicletas.append(Bicicleta("Modelo 1", 10, False))
    bicicletas.append(Bicicleta("Modelo 2", 20, False))
    bicicletas.append(Bicicleta("Modelo 3", 30, False))
    iniciar_programa(bicicletas)