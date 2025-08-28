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
    }
    printf("\n");
    return 0;
}