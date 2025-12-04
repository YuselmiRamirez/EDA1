#include <stdio.h>
#define LIM 95

typedef unsigned long long entero;
entero tabla[LIM]={0};
entero fibonacci(int n){
    if(n<=1){
        return n;
}
    if(tabla[n]!= 0){
        return tabla[n];
}
    tabla[n]=fibonacci(n - 1)+fibonacci(n - 2);
    return tabla[n];
}

int main(){
    int posiciones[]={7, 21, 40, 71, 94};
    int total=sizeof(posiciones)/sizeof(posiciones[0]);

    printf("Valor de Fibonacci:\n");

    for (int i=0; i<total; i++){
        entero valor=fibonacci(posiciones[i]);
        printf("Posicion %d = %llu\n", posiciones[i], valor);
    }
    printf("Notar que: \n");
    printf("Los valores desde la posición 93 hacia arriba ya no entran, por lo que Fibonacci(94) se imprime incorrectamente.\n");
    return 0;
}
