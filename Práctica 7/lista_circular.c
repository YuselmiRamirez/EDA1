#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo *siguiente;
} Nodo;

void insertarInicio(struct Nodo **cabeza,struct Nodo **ultimo,int valor){
	struct Nodo *n=(struct Nodo*)malloc(sizeof(struct Nodo));
	n->dato=valor;

	if(*cabeza==NULL){
		*cabeza=n;
		*ultimo=n;
		n->siguiente=n;
	}
	else{
		n->siguiente=*cabeza;
		(*ultimo)->siguiente=n;
		*cabeza=n;
	}
}

void recorrer(struct Nodo *cabeza){
	if(cabeza==NULL){
		printf("NULL\n");
		return;
	}
	struct Nodo *a=cabeza;
	do{
		printf("%d-> ",a->dato);
		a=a->siguiente;
	}while(a!=cabeza);
	printf("cabeza\n");
}

void eliminarCircular(struct Nodo **cabeza,struct Nodo **ultimo,int valor){
	if(*cabeza==NULL) return;

	struct Nodo *p=*cabeza;
	struct Nodo *ant=*ultimo;

	do{
		if(p->dato==valor){
			if(p==*cabeza){
				if(*cabeza==*ultimo){
					free(p);
					*cabeza=NULL;
					*ultimo=NULL;
					return;
				}
				*cabeza=p->siguiente;
				(*ultimo)->siguiente=*cabeza;
				free(p);
				return;
			}
			ant->siguiente=p->siguiente;
			if(p==*ultimo){
				*ultimo=ant;
			}
			free(p);
			return;
		}
		ant=p;
		p=p->siguiente;
	}while(p!=*cabeza);
}

void liberar(struct Nodo *cabeza){
	if(cabeza==NULL)return;
	struct Nodo *p=cabeza->siguiente;
	struct Nodo *sig;
	while(p!=cabeza){
		sig=p->siguiente;
		free(p);
		p=sig;
	}
	free(cabeza);
}

int main(){
	struct Nodo *cabeza=NULL;
	struct Nodo *ultimo=NULL;
	int valor, n, eli, i;

	printf("Cuantos valores desea insertar? ");
	scanf("%d", &valor);

	for(i=0; i<valor; i++){
		printf("Ingrese el elemento para el valor %d:",i+1);
		scanf("%d", &n);
		insertarInicio(&cabeza, &ultimo, n);
		printf("Lista despues de insertar %d:\n",n);
		recorrer(cabeza);
	}

	printf("\nLista actual:");
	recorrer(cabeza);

	printf("Que valor desea eliminar?");
	scanf("%d", &eli);

	eliminarCircular(&cabeza, &ultimo, eli);

	printf("Lista despues de eliminar:\n");
	recorrer(cabeza);

	liberar(cabeza);
	printf("Memoria liberada correctamente.");

	return 0;
}
