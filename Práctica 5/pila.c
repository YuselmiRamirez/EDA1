#include <stdio.h>
#include <stdlib.h>

#define max_tam 5

typedef struct{
    int arr[max_tam];
    int tope;
} Pila;

void inicializarPila(Pila *p){
    p->tope=-1;
    printf("Pila inicializada vacia (tope = %d)\n", p->tope);
}

void push(Pila *p, int dato){
    if(p->tope == max_tam - 1){
        printf("Pila llena %d.\n", dato);
        return;
    }

    p->tope++;
    p->arr[p->tope] = dato;

    printf("Elemento insertado %d. Estado de la pila: [", dato);
    for(int i = 0; i <= p->tope; i++){
        printf("%d", p->arr[i]);
    }
    printf("] (tope = %d)\n", p->tope);
}

int pop(Pila *p){
    if(p->tope == -1){
        printf("Error: la pila esta vacia, no se puede desapilar.\n");
        return -1;
    }

    int eliminado = p->arr[p->tope];
    p->tope--;
    return eliminado;
}

int main(){
    Pila laPila;
    int tope, eliminado;
    inicializarPila(&laPila);
    
    printf("¿Cuantos elementos deseas apilar? (Maximo 5)");
    scanf("%d", &tope);
    
    if(tope<=5){
        int dato;
        for(int i=0; i<tope; i++){
            printf("Ingresa el elemento %d: ", i+1);
            scanf("%d", &dato);
            push(&laPila, dato);
        }
    }else{
        printf("Numero invalido. Maximo: 5.");
    }

    printf("¿Cuantos elementos deseas desapilar?");
    scanf("%d", &eliminado);
    
    if(eliminado<=5){
        for(int i=0; i<eliminado; i++){
            int x = pop(&laPila);
            printf("Elemento desapilado: %d\n", x);
        }
    }

    return 0;
}