#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Bienvenido.\n");
    printf("Â¿Cuantos enteros desea guardar?: ");
    scanf("%d", &n);

    int *arr=(int*)malloc(n*sizeof(int));

    printf("\nValores en la memoria:\n");
    for (int i=0; i<n; i++){
        printf("%d", arr[i]);
        printf("\n");
    }
    free(arr);

    return 0;
}
