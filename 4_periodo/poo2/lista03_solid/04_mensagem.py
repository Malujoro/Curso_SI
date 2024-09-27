from abc import ABC, abstractmethod

class Notificacao(ABC):

    @abstractmethod
    def enviarNotificacao(self, mensagem: str):
        pass

class NotificacaoEmail(Notificacao):

    def enviarNotificacao(self, mensagem: str):
        print(f"Enviando notificação [{mensagem}] por Email")
        return True, "Mensagem enviada com sucesso"

class NotificacaoSMS(Notificacao):

    def enviarNotificacao(self, mensagem: str):
        print(f"Enviando notificação [{mensagem}] por SMS")
        return True, "Mensagem enviada com sucesso"


class Usuario:

    __slots__ = ["_notificacao", "_mensagem"]

    def __init__(self, notificacao: Notificacao):
        self._notificacao = notificacao
        self._mensagem = ""
    
    @property
    def mensagem(self):
        return self._mensagem
    
    @mensagem.setter
    def mensagem(self, mensagem):
        self._mensagem = mensagem

    def enviarNotificacao(self):
        return self._notificacao.enviarNotificacao(self._mensagem)
    

usuarioSms = Usuario(NotificacaoSMS())
usuarioSms.mensagem = "Mensagem1"
usuarioSms.enviarNotificacao()

usuarioEmail = Usuario(NotificacaoEmail())
usuarioEmail.mensagem = "Mensagem2"
usuarioEmail.enviarNotificacao()