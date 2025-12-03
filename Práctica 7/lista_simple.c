#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo *siguiente;
} Nodo;

void insertarInicio(struct Nodo **cabeza, int valor){
	struct Nodo *n=(struct Nodo*)malloc(sizeof(struct Nodo));
	n->dato=valor;
	n->siguiente=*cabeza;
	*cabeza=n;
}

void recorrer(struct Nodo *cabeza){
	struct Nodo *a=cabeza;
	while(a!=NULL){
		printf("%d-> ",a->dato);
		a=a->siguiente;
	}
	printf("NULL\n");
}

void eliminar(struct Nodo **cabeza,int valor){
	struct Nodo *p=*cabeza;
	struct Nodo *ant=NULL;

	if(p!=NULL && p->dato==valor){
		*cabeza=p->siguiente;
		free(p);
		return;
	}

	while(p!=NULL && p->dato!=valor){
		ant=p;
		p=p->siguiente;
	}

	if(p==NULL) return;

	ant->siguiente=p->siguiente;
	free(p);
}

void liberar(struct Nodo *cabeza){
	struct Nodo *p;
	while(cabeza!=NULL){
		p=cabeza;
		cabeza=cabeza->siguiente;
		free(p);
	}
}

int main(){
	struct Nodo *cabeza=NULL;
	int valor, n, eli, i;

	printf("Cuantos valores desea insertar? ");
	scanf("%d", &valor);

	for(i=0; i<valor; i++){
		printf("Ingrese el elemento para el valor %d:",i+1);
		scanf("%d", &n);
		insertarInicio(&cabeza, n);

		printf("Lista despues de insertar %d:\n",n);
		recorrer(cabeza);
	}

	printf("\nLista actual:");
	recorrer(cabeza);

	printf("Que valor desea eliminar?");
	scanf("%d", &eli);

	eliminar(&cabeza, eli);

	printf("Lista despues de eliminar:\n");
	recorrer(cabeza);

	liberar(cabeza);
	printf("Memoria liberada correctamente.");

	return 0;
}
