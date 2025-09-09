#include <stdio.h>

int main(void) {
    int a[5] = {2, 4, 6, 8, 10};
    int *p = a; // p apunta a a[0]
    
    printf("1) a[1] = %d\n", a[1]); // ComentAlu: Printf imprimirá 4    Código Impresión: 4
    printf("2) *(a+3) = %d\n", *(a+3)); // CA: Se cree que la impresión será 8    CI: 8
    printf("3) *p++ = %d\n", *p++); // CA: En este caso, printf imprime 4    CI: 2
    printf("4) *++p = %d\n",*++p); // CA: Se cree que imprime 2    CI: 6
    printf("5) p[1] = %d\n", p[1]); // CA: Ya que p apunta hacia a[0], la impresion será 4    CI: 8
    printf("6) *(p+=2) = %d\n", *(p+=2)); // CA: Este printf indica una suma del elemento p+2, por lo que se cree que imprimirá 4    CI: 10
    printf("7) p-a = %ld\n", p-a); // CA: Ya que p apunta a a[0], imprime un 4    CI: 4

    return 0;
}