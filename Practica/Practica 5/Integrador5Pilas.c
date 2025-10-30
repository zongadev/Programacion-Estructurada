/**
Se carga una pila desde un archivo
Elimina de a pila aquellos productos cuyo stock esté entre 
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

void push(t_nodo *p,t_dato n)
{
	 
}

t_dato pop(t_nodo *p)
{
	t_dato dato;
 
	
	return dato;
}
void cargarPila(t_nodo* p,char* nomArch){
	FILE* arch;
	arch = fopen(nomArch,"r");     
	t_dato nuevo = NULL;
	while(arch != EOF){
		nuevo = malloc(sizeof(t_dato));
		leerArch();
		fscanf(arch,"%d,",nuevo->stock);
		fscanf(archm"%f\n",nuevo->stock);
		
	}
	
}





void eliminar(t_nodo *p,int sinf, int ssup)
{
     
	
}

int main() {
	t_nodo pila=NULL;
    t_dato dato;
	cargarPila(&pila,"productos.txt");
	printf("\nPila despues de eliminar productos con stock entre 200 y 300\n");
    eliminar(&pila,200,300);
    while(pila!=NULL)
    {
        dato=pop(&pila);
        printf("%-35s%-10d%-10.2f\n",dato.nomprod,dato.stock,dato.precio);
    }
	return 0;
}


