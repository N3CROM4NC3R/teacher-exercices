#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo{
	int elemento;
	struct Nodo *siguiente;
	struct Nodo *anterior;
}Nodo;
typedef struct{
	struct Nodo* cabeza;
	struct Nodo* final;
}Pila;
void menu();
void mostrar(Pila *,int*);
void insertar(Pila*,int*);
void eliminar(Pila *,int*);
void invertir(Pila *,int*);


int main(int argc,char *argv[]){
	menu();
	return 0;
}

void menu(){
	int tamanio=0;	
	Pila pila;
	pila.cabeza = (struct Nodo*)malloc(sizeof (struct Nodo));
	pila.cabeza->siguiente = NULL;
	pila.cabeza->anterior = NULL;
	pila.final = pila.cabeza;
	int salir=0;
	int opcion=0;
	while(salir==0){		
		printf("Bienvenido a nuestro programa de pila\n");
		printf("1)Mostrar pila\n");
		printf("2)Insertar elemento en pila\n");
		printf("3)Eliminar elemento en pila\n");
		printf("4)Invertir pila\n");
		printf("5)Salir\n");
		printf("Ingrese su opcion:");
		scanf("%i",&opcion);
		switch(opcion){			
			case 1:
				mostrar(&pila,&tamanio);
				break;
			case 2:
				insertar(&pila,&tamanio);
				break;
			case 3:
				eliminar(&pila,&tamanio);
				break;
			case 4:
				invertir(&pila,&tamanio);
				break;
			case 5:
				salir=1;
				printf("Saliendo...");
			default:
				printf("Opcion incorrecta\n");
		}
	}
}

//Desarrollar la funcion de mostrar
void mostrar(Pila *pila,int *tamanio){
	if(*tamanio == 0){
		printf("La pila esta vacia\n");
	}
	else{
		struct Nodo *apuntador;
		apuntador = pila->cabeza;
		while(apuntador != NULL){
			printf("%i -",apuntador->elemento);
			apuntador = apuntador->siguiente;
		}
		printf("\n");
	}
}

//Desarrollar la funcion de insertar
void insertar(Pila *pila,int *tamanio){
	int elemento;
	printf("Inserte el nuevo elemento:");
	scanf("%i",&elemento);
	if(*tamanio == 0){
		pila->cabeza->elemento=elemento;
		pila->cabeza->siguiente = NULL;
		pila->cabeza->anterior = NULL;
	}
	else{
		struct Nodo *nuevo;
		nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
		nuevo->elemento = elemento;
		nuevo->siguiente = pila->cabeza;
		pila->cabeza->anterior = nuevo;
		pila->cabeza = nuevo;
	}
	printf("%i\n",*tamanio);
	(*tamanio)++;
}

void eliminar(Pila *pila,int *tamanio){
	if(*tamanio == 0){
		printf("La pila esta vacia\n");
	}
	else{
		Nodo *apuntador;
		apuntador = pila->cabeza;
		pila->cabeza = pila->cabeza->siguiente;
		pila->cabeza->anterior = NULL;
		free(apuntador);
		(*tamanio)--;
	}
	return ;
}

//Pila invertida rompiendo su funcionamiento
void invertir(Pila *pila,int *tamanio){
	if(*tamanio == 0){
		printf("La pila esta vacia\n");
	}
	else{	
		int	aux;
		struct Nodo *cabeza,*final;
		cabeza = pila->cabeza;
		final = pila->final;
		int i=0;
		for(i=0;i<*tamanio/2;i++){
			aux = cabeza->elemento;
			cabeza->elemento = final->elemento;
			final->elemento = aux;
			cabeza = cabeza->siguiente;
			final = final->anterior;
		}
	}
	return ;
}
