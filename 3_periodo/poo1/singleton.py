class Configuracoes:
    __instance = None

    def __new__(cls):
        if Configuracoes.__instance is None:
            Configuracoes.__instance = super().__new__(cls)
        return Configuracoes.__instance
    

    @staticmethod
    def get_instance():
        if Configuracoes.__instance is None:
            Configuracoes()
        return Configuracoes.__instance
    
    def __init__(self):
        if not hasattr(self, '_initialized'):
            self._volume = 75
            self.dificuldade = "Médio"
            self._initialized = True

    @property
    def volume(self):
        return self._volume
    
    @volume.setter
    def volume(self, vol):
        self._volume = vol


config1 = Configuracoes.get_instance()
config2 = Configuracoes.get_instance()

# assert config1 is config2

print("Original")
print(f"Config 1 = {config1.volume}")
print(f"Config 2 = {config2.volume}")

config1.volume = 90

print("Após alterar")
print(f"Config 1 = {config1.volume}")
print(f"Config 2 = {config2.volume}")

print("Instâncias")
print(f"Config 1 = {config1}")
print(f"Config 2 = {config2}")