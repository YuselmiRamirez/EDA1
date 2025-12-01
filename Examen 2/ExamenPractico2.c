#include <stdio.h>
#include <stdlib.h>

int maximo_recursivo(int arr[], int in, int fin){

    if(in==fin){
        return arr[in];
    }

    int mid=(in+fin)/2;
    int maxizq=maximo_recursivo(arr, in, mid);
    int maxder=maximo_recursivo(arr, mid + 1, fin);
    
    if(maxizq>maxder){
        return maxizq;
    }else{
        return maxder;
    }
}

int main(){
    int n, i;
    int *lista;

    printf("Ingresa el tamaño de la lista:");
    scanf("%d", &n);

    lista=(int*)malloc(n*sizeof(int));
    printf("Ingresa los elementos:");
    for(i=0; i<n; i++){
        scanf("%d", &lista[i]);
    }

    int resultado=maximo_recursivo(lista, 0, n - 1);
    printf("El valor maximo es: %d\n", resultado);
    free(lista);
    return 0;
}
