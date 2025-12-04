#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **inicio,int valor){
    struct Nodo *nuevo=malloc(sizeof(struct Nodo));
    nuevo->dato=valor;

    if(*inicio==NULL){
        nuevo->anterior=nuevo;
        nuevo->siguiente=nuevo;
        *inicio=nuevo;
        return;
    }

    struct Nodo *ultimo=(*inicio)->anterior;

    nuevo->siguiente=*inicio;
    nuevo->anterior=ultimo;

    ultimo->siguiente=nuevo;
    (*inicio)->anterior=nuevo;

    *inicio=nuevo;
}

void insertarFinal(struct Nodo **inicio,int valor){
    struct Nodo *nuevo=malloc(sizeof(struct Nodo));
    nuevo->dato=valor;

    if(*inicio==NULL){
        nuevo->anterior=nuevo;
        nuevo->siguiente=nuevo;
        *inicio=nuevo;
        return;
    }

    struct Nodo *ultimo=(*inicio)->anterior;

    nuevo->siguiente=*inicio;
    nuevo->anterior=ultimo;

    ultimo->siguiente=nuevo;
    (*inicio)->anterior=nuevo;
}

void recorrerAdelante(struct Nodo *inicio){
    printf("Adelante: ");
    if(inicio==NULL){
        printf("Lista vacia");
        return;
    }
    struct Nodo *actual=inicio;
    do{
        printf("%d -> ",actual->dato);
        actual=actual->siguiente;
    }while(actual!=inicio);
    printf("INICIO");
}

void recorrerAtras(struct Nodo *inicio){
    if(inicio==NULL){
        printf("Lista vacia.");
        return;
    }
    struct Nodo *actual=inicio->anterior;
    printf("Atras: ");
    do{
        printf("%d <- ",actual->dato);
        actual=actual->anterior;
    }while(actual!=inicio->anterior);
    printf("INICIO");
}

void eliminar(struct Nodo **inicio,int valor){
    if(*inicio==NULL){
        printf("\nno encontrado.\n");
        return;
    }

    struct Nodo *actual=*inicio;

    do{
        if(actual->dato==valor)break;
        actual=actual->siguiente;
    }while(actual!=*inicio);

    if(actual->dato!=valor){
        printf("\nno encontrado.\n");
        return;
    }

    if(actual->siguiente==actual){
        free(actual);
        *inicio=NULL;
        return;
    }

    actual->anterior->siguiente=actual->siguiente;
    actual->siguiente->anterior=actual->anterior;

    if(actual==*inicio)*inicio=actual->siguiente;

    free(actual);
}

void liberar(struct Nodo **inicio){
    if(*inicio==NULL)return;

    struct Nodo *actual=*inicio;
    struct Nodo *fin=(*inicio)->anterior;

    fin->siguiente=NULL;

    struct Nodo *temp;
    while(actual!=NULL){
        temp=actual;
        actual=actual->siguiente;
        free(temp);
    }

    *inicio=NULL;
    printf("\nMemoria liberada correctamente.\n");
}

int main(){
    struct Nodo *inicio=NULL;
    int n, valor, eliminarValor;

    printf("\nCuantos valores desea insertar?(inicio) ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nValor %d: ",i+1);
        scanf("%d",&valor);
        insertarInicio(&inicio, valor);
        printf("Lista hacia adelante:\n");
        recorrerAdelante(inicio);
    }

    printf("\nCuantos valores desea insertar?(final) ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nValor %d: ", i+1);
        scanf("%d",&valor);
        insertarFinal(&inicio,valor);
    }

    printf("Lista finalizada hacia adelante:\n");
    recorrerAdelante(inicio);

    printf("\nLista finalizada hacia atras:\n");
    recorrerAtras(inicio);

    printf("\nQue valor desea eliminar?: ");
    scanf("%d", &eliminarValor);
    eliminar(&inicio, eliminarValor);

    printf("\nLista actual hacia adelante:\n");
    recorrerAdelante(inicio);

    printf("\nLista actual hacia atras:\n");
    recorrerAtras(inicio);

    liberar(&inicio);
    return 0;
}
