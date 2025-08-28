#include <stdio.h>

int main(void) {
    int n;
    int a[25]; 
    int suma = 0;
    int resta;
    float promedio;
    
    printf("Ingrese una cantidad (Mínimo 1. Máximo 25): ");
    scanf("%d", &n);
    
    if(n < 1 || n > 25) {
        printf("Cantidad no válida.");
    } 
    else {
        printf("Ingrese %d números:\n", n);
        for (int i = 0; i < n; i++) {
            printf("Elemento %d: ", i);
            scanf("%d", &a[i]);
        }
        
        printf("\nLos elementos del array son:\n");
        for(int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }

        for(int i = 0; i < n; i++) {
            suma = suma + a[i];
        }
        
            resta = a[0];
        for(int i = 1; i < n; i++) {
            resta = resta - a[i];
        }

        promedio = (float)suma / n;
        
        for(int i = 0; i < n/2; i++) {
            int tempo = a[i];
            a[i] = a [n - i - 1];
            a[n - i - 1] = tempo;
        }
        int maximo = a[0];
        int minimo = a [0];
        for(int i = 1; i < n; i++) {
            if(a[i] > maximo) {
                maximo = a[i];
            }
            if(a[i] < minimo) {
                minimo = a[i];
            }
        }

        printf("\nLa suma de los elementos del array es: %d\n", suma);
        printf("\nLa resta de los elementos del array es: %d\n", resta);
        printf("\nEl promedio de los elementos del array es: %.2f\n", promedio);
        printf("\nEl valor maximo de los elementos es: %d\n", maximo);
        printf("\nEl valor minimo de los elementos es: %d\n", minimo);
        printf("El arreglo invertido es: \n");
        for(int i = 0; i < n; i++) {
            printf("%d", a[i]);
        }
    }

    printf("\n");
    return 0;
}
