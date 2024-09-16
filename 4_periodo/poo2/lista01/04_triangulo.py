a = float(input("Lado A: "))
b = float(input("Lado B: "))
c = float(input("Lado C: "))

if(a + b > c and b + c > a and c + a > b):
    if(a == b and b == c):
        print("Triângulo Equilátero")
    elif(a != b and b != c and c != a):
        print("Triângulo Escaleno")
    else:
        print("Triângulo Isósceles")

else:
    print("Não é um triângulo")