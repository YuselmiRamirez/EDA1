#include <stdio.h>
#include <stdlib.h>

#define max_tam 5

typedef struct{
    int arr[max_tam];
    int frente, final;
} Cola;

void inicializarCola(Cola *c){
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacia (frente = %d, final = %d)\n", c->frente, c->final);
}

void mostrarCola(Cola *c){
    printf("[");
    if(c->frente<=c->final){
        for(int i=c->frente; i<=c->final; i++){
            printf("%d", c->arr[i]);
            if(i<c->final){
                printf(", ");  
            }
        }
    }
    printf("] (frente = %d, final = %d)\n", c->frente, c->final);
}

void enqueue(Cola *c, int dato){
    if(c->final==max_tam - 1){
        printf("Cola llena, no se puede encolar %d.\n", dato);
        return;
    }

    c->final++;
    c->arr[c->final] = dato;

    printf("Elemento encolado: %d.\n Estado de la cola: ", dato);
    mostrarCola(c);
}

int dequeue(Cola *c){
    if(c->frente>c->final){
        printf("Error: la cola está vacía, no se puede desencolar.\n");
        return -1;
    }

    int eliminado=c->arr[c->frente];
    c->frente++;
    return eliminado;
}

int main(){
    Cola laCola;
    int cantidad, eliminar;
    inicializarCola(&laCola);
    
    printf("¿Cuántos elementos deseas encolar? (Máximo 5) ");
    scanf("%d", &cantidad);
    if(cantidad<=5){
        int dato;
        for(int i=0; i<cantidad; i++){
            printf("Ingresa el elemento %d: ", i + 1);
            scanf("%d", &dato);
            enqueue(&laCola, dato);
        }
    }else{
        printf("Número inválido. Máximo 5.\n");
    }

    printf("¿Cuántos elementos deseas desencolar? ");
    scanf("%d", &eliminar);
    if(eliminar<=5){
        for(int i=0; i<eliminar; i++){
            int x=dequeue(&laCola);
            if(x!=-1){
                printf("Elemento desencolado: %d. \nEstado de la cola: ", x);
                mostrarCola(&laCola);
            }
        }
    }

    return 0;
}