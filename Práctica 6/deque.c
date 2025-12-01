#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct{
    int datos[MAX];
    int front, size; 
} Deque;

void inicializarDeque(Deque *d){
    d->front=0;
    d->size=0;
    printf("Deque inicializado (front: %d, size: %d)\n", d->front, d->size);
}

int isEmpty(Deque *d){
    return d->size == 0;
}

int isFull(Deque *d){
    return d->size == MAX;
}

int rearIndex(Deque *d){
    return (d->front + d->size - 1 + MAX) % MAX;
}

void insert_front(Deque *d, int valor){
    if(isFull(d)){
        printf("Deque lleno, no se puede insertar front %d\n", valor);
        return;
    }

    d->front=(d->front - 1 + MAX) % MAX;
    d->datos[d->front]=valor;
    d->size++;
    printf("\nInsertar front: %d\n", valor);
}

void insert_rear(Deque *d, int valor){
    if(isFull(d)){
        printf("Deque lleno, no se puede insertar rear %d\n", valor);
        return;
    }

    int rear=(d->front + d->size) % MAX;
    d->datos[rear]=valor;
    d->size++;
    printf("\nInsertar rear: %d\n", valor);
}

int delete_front(Deque *d){
    if(isEmpty(d)){
        printf("Deque vacio, no se puede eliminar front.\n");
        return -1;
    }

    int eliminado=d->datos[d->front];
    d->front=(d->front + 1) % MAX;
    d->size--;
    return eliminado;
}

int delete_rear(Deque *d){
    if(isEmpty(d)){
        printf("Deque vacio, no se puede eliminar rear.\n");
        return -1;
    }

    int rear=rearIndex(d);
    int eliminado=d->datos[rear];
    d->size--;
    return eliminado;
}

int peek_front(Deque *d){
    if(isEmpty(d)){
        printf("Deque vacio.\n");
        return -1;
    }
    return d->datos[d->front];
}

int peek_rear(Deque *d){
    if(isEmpty(d)){
        printf("Deque vacio.\n");
        return -1;
    }
    return d->datos[rearIndex(d)];
}

void printDeque(Deque *d){
    printf("Deque (front: %d, size: %d): [", d->front, d->size);
    if(isEmpty(d)){
        printf(" ] (Deque vacio)\n");
        return;
    }

    for(int i=0; i<d->size; i++){
        int idx=(d->front + i) % MAX;
        printf(" %d", d->datos[idx]);
    }
    printf(" ]");
}

int main(){

    Deque dq;
    inicializarDeque(&dq);

    insert_front(&dq, 10);
    printDeque(&dq);

    insert_rear(&dq, 15);
    insert_rear(&dq, 20);
    printDeque(&dq);

    insert_front(&dq, 30);
    printDeque(&dq);

    insert_rear(&dq, 40);
    printDeque(&dq);

    int f=delete_front(&dq);
    int r=delete_rear(&dq);
    printf("\nEliminar front: %d", f);
    printf("\nEliminar rear: %d\n", r);
    printDeque(&dq);

    insert_front(&dq, 99);
    insert_rear(&dq, 77);
    printDeque(&dq);

    return 0;
}
