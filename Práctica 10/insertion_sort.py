def insertionSort(n_lista):
    for index in range(1, len(n_lista)):
        actual=n_lista[index]
        posicion=index
        
        print("valor a ordenar = {}".format(actual))

        while posicion>0 and n_lista[posicion-1]>actual:
            n_lista[posicion]=n_lista[posicion-1]
            posicion-=1
            print(n_lista)

        n_lista[posicion]=actual
        print(n_lista)
        print()

    return n_lista

if __name__ == "__main__":
    print("Insertion Sort")
    numeros = [8, 5, 2, 9, 1]
    print("Lista ordenada:", insertionSort(numeros))
    
