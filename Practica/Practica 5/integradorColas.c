/**
Se carga una cola desde un archivo
Elimina de la lista aquellos productos cuyo stock esté entre 
200 y 300 (extremos inclusive)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C 60
struct s_dato{
	char *nomprod;
	int stock;
	float precio;
};
typedef struct s_dato t_dato;

struct s_nodo{
	t_dato dato;
	struct s_nodo* sig;
};
typedef struct s_nodo* t_nodo;
typedef struct s_nodo v_nodo;

typedef struct s_fila{
	t_nodo cabeza;
	t_nodo cola;
} *t_fila;

void imprimirLista(t_fila ls){
	t_nodo aux = ls->cabeza;
	while(aux!=NULL){
		printf("%-35s%-10d%-10.2f\n",aux->dato.nomprod,aux->dato.stock,aux->dato.precio);
		aux = aux->sig;
	}
}


void leerCadenaArch(FILE* arch, char ** str, char sep){
	char c;
	c=fgetc(arch);
	int i=0;
	*str = malloc(sizeof(char));
	while(c!=EOF && c!=sep){
		(*str)[i]=c;
		i++;
		(*str) = realloc((*str),(i+1)*(sizeof(char)));
		c=fgetc(arch);
	}
	(*str)[i]='\0';
}
void enqueue(t_fila fila, t_dato valor){
	t_nodo n = malloc(sizeof(v_nodo));
	n->dato = valor;
	n->sig= NULL;
	if((fila->cabeza)==NULL){
		fila->cabeza = n;
		fila->cola =n;
	}else{
		(fila)->cola->sig = n;
		(fila)->cola = n;
	}
	
}

t_dato dequeue(t_fila fila){	
	t_dato p ={0};
	if(fila->cabeza!=NULL){
		p = fila->cabeza->dato;
		t_nodo aux =fila->cabeza;
		fila->cabeza= fila->cabeza->sig;
		free(aux);
	}
	if(fila->cabeza==NULL) fila->cola = NULL;
	return p;
}

void cargarLista(t_fila* ls,char* nomArch){
	FILE* arch = fopen(nomArch,"r");
	t_dato nuevo = {0};
	while(!feof(arch)){
		leerCadenaArch(arch,&nuevo.nomprod,',');
		fscanf(arch,"%d,",&nuevo.stock);
		fscanf(arch,"%f\n",&nuevo.precio);
		
		enqueue(*ls,nuevo);
	}
	fclose(arch);
}
	
	t_fila crearCola(void){
		t_fila q = malloc(sizeof *q);
		if(!q) return NULL;
		q->cabeza = q->cola = NULL;
		return q;
	}

void eliminarEnListaPorValor(t_fila *c,int sinf, int ssup){
	t_fila c2=crearCola();
	t_dato dato = dequeue(*c);
	while((*c)->cabeza !=NULL){
		if(dato.stock<sinf || dato.stock>ssup){
			free(dato.nomprod);
		}else{
			enqueue(c2,dato);
		}
		dato = dequeue(*c);
	}
	t_dato aux;
	while(c2->cabeza!=NULL){
		aux = dequeue(c2);
		enqueue(*c,aux);
	}
}


	

int main() {
	t_fila fila=crearCola();

	cargarLista(&fila,"productos.txt");

	printf("LISTA original de Productos\n");
	imprimirLista(fila);
	printf("\nLista despues de eliminar productos con stock entre 200 y 300\n");
    eliminarEnListaPorValor(&fila,200,300);
    imprimirLista(fila);
	return 0;
}

