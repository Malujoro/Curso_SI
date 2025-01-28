def calculo(num):
    return (num - 900) // 61 + 1

valores = [1000, 1050, 1075, 1110, 1300, 1350, 1400, 1440, 1480, 1600, 1700, 1800, 1850, 1900, 1950, 1975, 2000, 2200, 2400, 2430, 2450, 2500, 2600, 2700, 2950, 3100, 3150]

for item in valores:
    print(f"{item}: {calculo(item)}")