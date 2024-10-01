from cadastro import *

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QPushButton, QTableWidget, QTableWidgetItem, QLabel, QLineEdit, QDialog, QFormLayout
from PyQt5.QtGui import QFont
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QHeaderView

# Tela principal para exibir os clientes
class TelaClientes(QWidget):
    def __init__(self, cadastro: Cadastro):
        super().__init__()
        self._cadastro = cadastro

        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Clientes Cadastrados')  # Título da janela
        self.setGeometry(100, 100, 600, 400)  # Tamanho e posição da janela

        layout_principal = QVBoxLayout()  # Layout principal vertical

        # Cria a tabela para listar os clientes
        self.tabela = QTableWidget()
        self.tabela.setRowCount(0)  # Nenhuma linha inicialmente
        self.tabela.setColumnCount(5)  # 5 Colunas
        
        self.tabela.setHorizontalHeaderLabels(["Nome", "CPF", "Endereço", "CEP", "Telefone"])  # Cabeçalhos da tabela

        for cliente in self._cadastro.clientes.values():
            self.adicionar_cliente(cliente)

        # Aumenta a fonte do cabeçalho
        header = self.tabela.horizontalHeader()  # Obtém o cabeçalho horizontal
        fonte = QFont("Arial", 25, QFont.Bold)  # Define a fonte e o tamanho
        header.setFont(fonte)

        # Define que as colunas devem esticar para ocupar toda a largura da tabela
        header.setSectionResizeMode(QHeaderView.Stretch)

        layout_principal.addWidget(self.tabela)  # Adiciona a tabela ao layout

        # Botão para cadastrar novos clientes
        botao_cadastrar = QPushButton('Cadastrar Cliente')
        botao_cadastrar.setMinimumSize(200, 100)

        # Aumenta o tamanho da fonte do botão
        fonte_botao = QFont("Arial", 16)
        botao_cadastrar.setFont(fonte_botao)

        botao_cadastrar.clicked.connect(self.abrir_tela_cadastro)  # Conecta o clique do botão ao método de cadastro
        layout_principal.addWidget(botao_cadastrar)

        self.setLayout(layout_principal)  # Define o layout na janela

    # Função para abrir a janela de cadastro de clientes
    def abrir_tela_cadastro(self):
        dialogo = TelaCadastro(self)  # Passa a tela principal para o diálogo
        dialogo.exec_()  # Exibe o diálogo de forma modal

    # Função para adicionar um novo cliente à tabela
    def adicionar_cliente(self, cliente: Cliente):
        self._cadastro.cadastrar(cliente)

        # Adiciona uma nova linha na tabela
        num_linhas = self.tabela.rowCount()
        self.tabela.insertRow(num_linhas)
        atributos = [cliente.nome, cliente.cpf, cliente.endereco, cliente.cep, cliente.telefone]

        fonte = QFont("Arial", 22)

        for indice, atributo in enumerate(atributos):
            item = QTableWidgetItem(atributo)
            item.setFont(fonte)  # Aplica a fonte ao item
            self.tabela.setItem(num_linhas, indice, item)

# Tela de cadastro de cliente (um diálogo separado)
class TelaCadastro(QDialog):
    def __init__(self, tela_principal):
        super().__init__()
        self.tela_principal = tela_principal  # Referência à tela principal
        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Cadastrar Cliente')  # Título da janela
        self.setGeometry(150, 150, 500, 300)  # Tamanho e posição da janela
        
        layout = QFormLayout()  # Layout de formulário

        # Define a fonte maior para os textos e caixas de texto
        fonte_label = QFont("Arial", 14)  # Fonte para os rótulos
        fonte_input = QFont("Arial", 14)  # Fonte para as caixas de texto

        atributos = ["Nome: ", "CPF: ", "Endereço: ", "CEP: ", "Telefone: "]
        quant_atributos = len(atributos)
        
        self.inputs = []

        for i in range(quant_atributos):
            self.inputs.append(QLineEdit(self))
            self.inputs[i].setFont(fonte_input)  # Aplica fonte ao campo de texto
            self.inputs[i].setFixedSize(250, 30)  # Define o tamanho da caixa de texto
            label = QLabel(atributos[i], self)
            label.setFont(fonte_label)
            layout.addRow(label, self.inputs[i])

        # Botão para salvar o cliente
        botao_salvar = QPushButton('Salvar')
        botao_salvar.clicked.connect(self.salvar_cliente)
        layout.addWidget(botao_salvar)

        self.setLayout(layout)

    # Função para salvar o cliente e adicionar à tabela
    def salvar_cliente(self):
        # Adiciona o cliente à tela principal
        cliente = Cliente(self.inputs[0].text(), self.inputs[1].text(), self.inputs[2].text(), self.inputs[3].text(), self.inputs[4].text())
        self.tela_principal.adicionar_cliente(cliente)

        self.close()  # Fecha a janela de cadastro


# Função principal para iniciar a aplicação
def iniciar_aplicacao(cadastro):
    app = QApplication(sys.argv)
    tela = TelaClientes(cadastro)  # Instancia a tela principal
    tela.show()
    sys.exit(app.exec_())


# Executa a aplicação
if __name__ == '__main__':
    cadastro = Cadastro()

    cadastro.cadastrar(Cliente("mateus", "cpf", "end", "cep", "tel"))
    cadastro.cadastrar(Cliente("lucas", "cpf2", "end2", "cep2", "tel2"))
    cadastro.cadastrar(Cliente("joão", "cpf3", "end3", "cep3", "tel3"))
    iniciar_aplicacao(cadastro)