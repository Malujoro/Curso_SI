from abc import ABC, abstractmethod

class Notificacao(ABC):
    """
    Classe abstrata que representa uma notificação

    Métodos
    ---------
    enviarNotificacao(mensagem: str):
        Envia uma notificação com a mensagem como conteúdo
    """

    @abstractmethod
    def enviarNotificacao(self, mensagem: str) -> None:
        """
        Envia uma notificação com a mensagem como conteúdo

        Parâmetro
        ---------
        mensagem: str
        """
        pass

class NotificacaoEmail(Notificacao):
    """
    Classe que representa uma notificação por email (implementa Notificacao)

    Métodos
    ---------
    enviarNotificacao(mensagem: str):
        Envia uma notificação por email com a mensagem como conteúdo
    """

    def enviarNotificacao(self, mensagem: str) -> None:
        """
        Envia uma notificação por email com a mensagem como conteúdo

        Parâmetro
        ---------
        mensagem: str
        """
        print(f"Enviando notificação [{mensagem}] por Email")

class NotificacaoSMS(Notificacao):
    """
    Classe que representa uma notificação por sms (implementa Notificacao)

    Métodos
    ---------
    enviarNotificacao(mensagem: str):
        Envia uma notificação por sms com a mensagem como conteúdo
    """

    def enviarNotificacao(self, mensagem: str) -> None:
        """
        Envia uma notificação por sms com a mensagem como conteúdo

        Parâmetro
        ---------
        mensagem: str
        """
        print(f"Enviando notificação [{mensagem}] por SMS")


class Usuario:
    """
    Classe que representa um usuário

    Atributos
    ---------
    notificacao: Notificacao

    mensagem: str

    Métodos
    ---------
    enviarNotificacao():
        Envia uma notificação com a mensagem como conteúdo
    """

    __slots__ = ["_notificacao", "_mensagem"]

    def __init__(self, notificacao: Notificacao) -> None:
        self._notificacao = notificacao
        self._mensagem = ""
    
    @property
    def mensagem(self) -> str:
        return self._mensagem
    
    @mensagem.setter
    def mensagem(self, mensagem) -> None:
        self._mensagem = mensagem

    def enviarNotificacao(self) -> None:
        """
        Envia uma notificação com a mensagem como conteúdo
        """
        self._notificacao.enviarNotificacao(self._mensagem)
    

usuarioSms = Usuario(NotificacaoSMS())
usuarioSms.mensagem = "Mensagem1"
usuarioSms.enviarNotificacao()

usuarioEmail = Usuario(NotificacaoEmail())
usuarioEmail.mensagem = "Mensagem2"
usuarioEmail.enviarNotificacao()