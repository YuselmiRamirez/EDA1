def cambio(cantidad, denominaciones):
    resultado=[]

    while cantidad>0 and denominaciones:
        actual=denominaciones[0]

        if cantidad>=actual:
            num=cantidad
            cantidad=cantidad-(num * actual)
            resultado.append([actual, num])

        denominaciones=denominaciones[1:]
    return resultado

if __name__ == "__main__":
    print("Algoritmo Greedy")
    print("1000:", cambio(1000, [500, 200, 100, 50, 20, 5, 1]))
    print("500:",  cambio(500,  [500, 200, 100, 50, 20, 5, 1]))
    print("300:",  cambio(300,  [50, 20, 5, 1]))
    print("200:",  cambio(200,  [5]))
    print("98 :",  cambio(98,   [50, 20, 5, 1]))
    
