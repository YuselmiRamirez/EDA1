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
    nuevo->anterior=NULL;
    nuevo->siguiente=*inicio;
    if(*inicio!=NULL)(*inicio)->anterior=nuevo;
    *inicio=nuevo;
}

void insertarFinal(struct Nodo **inicio,int valor){
    struct Nodo *nuevo=malloc(sizeof(struct Nodo));
    nuevo->dato=valor;
    nuevo->siguiente=NULL;
    if(*inicio==NULL){
        nuevo->anterior=NULL;
        *inicio=nuevo;
        return;
    }
    struct Nodo *temp=*inicio;
    while(temp->siguiente!=NULL)temp=temp->siguiente;
    temp->siguiente=nuevo;
    nuevo->anterior=temp;
}

void recorrerAdelante(struct Nodo *inicio){
    printf("Adelante: ");
    while(inicio!=NULL){
        printf("%d -> ",inicio->dato);
        inicio=inicio->siguiente;
    }
    printf("NULL");
}

void recorrerAtras(struct Nodo *inicio){
    if(inicio==NULL){
        printf("Lista vacia.\n");
        return;
    }
    while(inicio->siguiente!=NULL)inicio=inicio->siguiente;
    printf("Atras: ");
    while(inicio!=NULL){
        printf("%d <- ",inicio->dato);
        inicio=inicio->anterior;
    }
    printf("NULL");
}

void eliminar(struct Nodo **inicio,int valor){
    struct Nodo *actual=*inicio;
    while(actual!=NULL && actual->dato!=valor)actual=actual->siguiente;
    if(actual==NULL){
        printf("\nno encontrado.\n");
        return;
    }
    if(actual==*inicio){
        *inicio=actual->siguiente;
        if(*inicio!=NULL)(*inicio)->anterior=NULL;
    }else{
        actual->anterior->siguiente=actual->siguiente;
        if(actual->siguiente!=NULL)actual->siguiente->anterior=actual->anterior;
    }
    free(actual);
}

void liberar(struct Nodo **inicio){
    struct Nodo *temp;
    while(*inicio!=NULL){
        temp=*inicio;
        *inicio=(*inicio)->siguiente;
        free(temp);
    }
    printf("\nMemoria liberada correctamente.\n");
}

int main(){
    struct Nodo *inicio=NULL;
    int n,valor,eliminarValor;

    printf("\nCuantos valores desea insertar?(inicio) ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nValor %d: ",i+1);
        scanf("%d",&valor);
        insertarInicio(&inicio,valor);
        printf("Lista hacia adelante:\n");
        recorrerAdelante(inicio);
    }

    printf("Cuantos valores desea insertar?(final) ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nValor %d: ",i+1);
        scanf("%d",&valor);
        insertarFinal(&inicio,valor);
    }

    printf("Lista finalizada hacia adelante:\n");
    recorrerAdelante(inicio);

    printf("Lista finalizada hacia atras:\n");
    recorrerAtras(inicio);

    printf("\nQue valor desea eliminar?: ");
    scanf("%d",&eliminarValor);
    eliminar(&inicio,eliminarValor);

    printf("Lista actual hacia adelante:\n");
    recorrerAdelante(inicio);

    printf("Lista actual hacia atras:\n");
    recorrerAtras(inicio);

    liberar(&inicio);
    return 0;
}
