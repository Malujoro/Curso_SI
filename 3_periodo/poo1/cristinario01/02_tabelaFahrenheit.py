inicial = float(input("Temperatura inicial em Celsius: "))
final = float(input("Temperatura final em Celsius: "))

c = inicial
while c <= final:
    print(f"{c}ºC - {(c * 9 / 5) + 32}ºF")
    c += 5