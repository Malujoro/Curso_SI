from cadastro import *

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QPushButton, QTableWidget, QTableWidgetItem, QLabel, QLineEdit, QDialog, QFormLayout


# Tela principal para exibir os clientes
class TelaClientes(QWidget):
    def __init__(self, cadastro, clientes = []):
        super().__init__()
        self._cadastro = cadastro
        self.clientes = clientes  # Lista para armazenar os clientes
        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Clientes Cadastrados')  # Título da janela
        self.setGeometry(100, 100, 600, 400)  # Tamanho e posição da janela

        layout_principal = QVBoxLayout()  # Layout principal vertical

        # Cria a tabela para listar os clientes
        self.tabela = QTableWidget()
        self.tabela.setRowCount(0)  # Nenhuma linha inicialmente
        self.tabela.setColumnCount(5)  # Duas colunas: Nome e Idade
        
        self.tabela.setHorizontalHeaderLabels(["nome", "cpf", "endereco", "cep", "telefone"])  # Cabeçalhos da tabela
        layout_principal.addWidget(self.tabela)  # Adiciona a tabela ao layout

        # Botão para cadastrar novos clientes
        botao_cadastrar = QPushButton('Cadastrar Cliente')
        botao_cadastrar.clicked.connect(self.abrir_tela_cadastro)  # Conecta o clique do botão ao método de cadastro
        layout_principal.addWidget(botao_cadastrar)

        self.setLayout(layout_principal)  # Define o layout na janela

    # Função para abrir a janela de cadastro de clientes
    def abrir_tela_cadastro(self):
        dialogo = TelaCadastro(self)  # Passa a tela principal para o diálogo
        dialogo.exec_()  # Exibe o diálogo de forma modal

    # Função para adicionar um novo cliente à tabela
    def adicionar_cliente(self, nome, cpf, endereco, cep, telefone):
        self._cadastro.cadastrar(Cliente(nome, cpf, endereco, cep, telefone))

        # Adiciona uma nova linha na tabela
        num_linhas = self.tabela.rowCount()
        self.tabela.insertRow(num_linhas)
        self.tabela.setItem(num_linhas, 0, QTableWidgetItem(nome))
        self.tabela.setItem(num_linhas, 1, QTableWidgetItem(cpf))
        self.tabela.setItem(num_linhas, 2, QTableWidgetItem(endereco))
        self.tabela.setItem(num_linhas, 3, QTableWidgetItem(cep))
        self.tabela.setItem(num_linhas, 4, QTableWidgetItem(telefone))


# Tela de cadastro de cliente (um diálogo separado)
class TelaCadastro(QDialog):
    def __init__(self, tela_principal):
        super().__init__()
        self.tela_principal = tela_principal  # Referência à tela principal
        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Cadastrar Cliente')  # Título da janela
        self.setGeometry(150, 150, 300, 150)  # Tamanho e posição da janela

        layout = QFormLayout()  # Layout de formulário

        # Campos para nome e idade
        self.nome_input = QLineEdit(self)
        self.cpf_input = QLineEdit(self)
        self.endereco_input = QLineEdit(self)
        self.cep_input = QLineEdit(self)
        self.telefone_input = QLineEdit(self)

        layout.addRow('Nome:', self.nome_input)
        layout.addRow('CPF:', self.cpf_input)
        layout.addRow('Endereço:', self.endereco_input)
        layout.addRow('CEP:', self.cep_input)
        layout.addRow('Telefone:', self.telefone_input)

        # Botão para salvar o cliente
        botao_salvar = QPushButton('Salvar')
        botao_salvar.clicked.connect(self.salvar_cliente)
        layout.addWidget(botao_salvar)

        self.setLayout(layout)

    # Função para salvar o cliente e adicionar à tabela
    def salvar_cliente(self):
        nome = self.nome_input.text()
        cpf = self.cpf_input.text()
        endereco = self.endereco_input.text()
        cep = self.cep_input.text()
        telefone = self.telefone_input.text()

        # Adiciona o cliente à tela principal
        self.tela_principal.adicionar_cliente(nome, cpf, endereco, cep, telefone)

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
    # iniciar_aplicacao(cad.clientes)
    iniciar_aplicacao(cadastro)