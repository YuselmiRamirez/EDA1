#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Bienvenido.\n");
    printf("¿Cuantos enteros desea guardar?: ");
    scanf("%d", &n);

    int *arr=(int*)malloc(n*sizeof(int));
    int *arr2=(int*)calloc(n, sizeof(int));
    
    printf("¿Cuales son tus %d valores a guardar?:\n", n);
    for (int i=0; i<n; i++){
        scanf("%d", &arr2[i]);
    }
    
    printf("\nValores en la memoria (malloc):\n");
    for (int i=0; i<n; i++){
        printf("%d", arr[i]);
        printf("\n");
    }
    
    printf("Tus valores en memoria (calloc) son:\n");
    for (int i=0; i<n; i++){
        printf("%d", arr2[i]);
        printf("\n");
    }
    
    free(arr);
    free(arr2);

    return 0;
}
