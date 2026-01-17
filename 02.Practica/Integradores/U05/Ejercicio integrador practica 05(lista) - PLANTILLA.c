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

void imprimirLista(t_nodo ls){

}

void insertarEnListaUltimo(t_nodo *c,t_dato d)
{
     
}

void cargarLista(t_nodo* ls,char* nomArch){
 
	
}

void eliminarEnListaPorValor(t_nodo *c,int sinf, int ssup)
{
  
	
}

int main() {
	t_nodo ls=NULL;

	cargarLista(&ls,"productos.txt");

	printf("LISTA original de Productos\n");
	imprimirLista(ls);
	printf("\nLista despues de eliminar productos con stock entre 200 y 300\n");
    eliminarEnListaPorValor(&ls,200,300);
    imprimirLista(ls);
	return 0;
}

