a = float(input("Lado A: "))
b = float(input("Lado B: "))
c = float(input("Lado C: "))

if((a > b+c) or (b > a+c) or (c > a+b)):
    print('\nNão é um triângulo')
else:
    print('\nÉ um triângulo ', end='')
    if(a == b == c):
        print('equilátero')
    elif(a != b and a != c and b != c):
        print('escaleno')
    else:
        print('isósceles')