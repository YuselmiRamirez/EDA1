#include <stdio.h> 
#include <stdlib.h> 

#define MAX 5 

typedef struct{
    int datos[MAX];
    int frente, final, tam;
    int *p; 
} ColaCircular;

int isEmpty(ColaCircular *c){
    return c->frente == c->final;
}

int isFull(ColaCircular *c){
    return (c->final + 1) % MAX == c->frente;
}

void inicializarColaCircular(ColaCircular *c){
    c->p = c->datos; 
    c->frente = 0; 
    c->final = 0;  
    c->tam = MAX;  
    
    printf("Cola circular inicializada. MAX= %d\n", MAX);
    printf("Datos vacios: frente: %d, final: %d, size: %d\n", c->frente, c->final, c->tam);
}

void enqueue(ColaCircular *c, int valor){
    if(isFull(c)){
        printf("Cola llena, no se puede encolar %d. (frente: %d, final: %d)\n", valor, c->frente, c->final);
        return;
    }
    
    c->datos[c->final] = valor;
    c->final=(c->final + 1) % MAX;
    
    printf("Elemento encolado: %d. ", valor);
}

int dequeue(ColaCircular *c){
    if(isEmpty(c)){
        printf("Cola vacia, no se puede desencolar.\n");
        return -1; 
    }

    int valor_desencolado=c->datos[c->frente];
    c->frente=(c->frente + 1) % MAX;
    return valor_desencolado;
}

int peek(ColaCircular *c){
    if(isEmpty(c)){
        printf("Cola vacia, no hay elemento al frente.\n");
        return -1;
    }
    return c->datos[c->frente];
}

void mostrarColaCircular(ColaCircular *c){
    printf("Estado actual (frente: %d, final: %d): [", c->frente, c->final);
    
    if(isEmpty(c)){
        printf(" ] (Cola vacia)\n");
        return;
    }

    int i=c->frente;
    do {
        printf(" %d", c->datos[i]);
        i=(i + 1) % MAX;
    } while(i!= c->final);
    
    printf(" ]\n");
}

int main()
{
    ColaCircular cc;
    int cantidad, eliminar, d;
    
    inicializarColaCircular(&cc);
    
    printf("Cuantos elementos deseas encolar? (Maximo %d) ", MAX - 1);
    scanf("%d", &cantidad);
    
    for(int i=0; i<cantidad; i++){
        printf("Ingresa el elemento %d: ", i + 1);
        scanf("%d", &d);
        enqueue(&cc, d);
        mostrarColaCircular(&cc);
    }
    
    int p=peek(&cc);
    if(p!= -1){
        printf("Elemento en el frente (peek): %d.\n", p);
    }
    
    printf("Cuantos elementos deseas desencolar? ");
    scanf("%d", &eliminar);
    
    for(int i=0; i<eliminar; i++){
        int c_dequeued=dequeue(&cc); 
        if(c_dequeued!= -1){
            printf("Elemento desencolado: %d. ", c_dequeued);
            mostrarColaCircular(&cc);
        } else{
            break;
        }
    }

    return 0;
}
