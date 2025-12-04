from string import ascii_letters, digits
from itertools import product
from time import time
import os

caracteres=ascii_letters+digits

def buscador_longitud(n):
    try:
        archivo=open(f"combinaciones_{n}.txt", "w")
    except Exception as e:
        print("Error al crear el archivo: {e}")
        return

    print("Buscando combinaciones de longitud {n}...")

    for comb in product(caracteres, repeat=n):
        prueba="".join(comb)
        archivo.write(prueba + "\n")

    archivo.close()
    print("Archivo generado: combinaciones_{n}.txt")

if __name__ == "__main__":
    print("Fuerza bruta")

    t0=time()
    buscador_longitud(4)
    buscador_longitud(8)
    buscador_longitud(10)
    print("Tiempo total:", round(time() - t0, 6))
    
