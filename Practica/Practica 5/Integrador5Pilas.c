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

void push(t_nodo *p,t_dato n){
	t_nodo nuevo = malloc(sizeof(t_nodo));
	nuevo->sig=(*p);
	*p = nuevo;
}

t_dato pop(t_nodo *p){
	t_dato dato;
	if((*p)!=NULL){
		dato = (*p)->dato;
		t_nodo aux =(*p);
		(*p)=(*p)->sig;
		free(aux);
	}
	return dato;
}

void leerArch(FILE* arch, char ** valor, char sep){
	char c;
	int i=0;
	(*valor) =malloc(sizeof(char));
	c=fgetc(arch);
	while(c!=sep && c!=EOF){
		printf("%c",c);
		(*valor)[i]=c;
		i++;
		(*valor) = realloc((*valor),(i+1)*sizeof(char));
		c=fgetc(arch);
	}
	(*valor)[i]= '\0';
	return;
}
void cargarPila(t_nodo* p,char* nomArch){
	FILE* arch;
	arch = fopen(nomArch,"r");     
	t_dato nuevo;
	while(!feof(arch)){
		leerArch(arch,&(nuevo.nomprod),',');
		fscanf(arch,"%d,",&nuevo.stock);
		fscanf(arch,"%f\n",&nuevo.precio);
		printf("%-35s%-10d%-10.2f\n",nuevo.nomprod,nuevo.stock,nuevo.precio);
		push(p,nuevo);
	}
	fclose(arch);
}





void eliminar(t_nodo *p,int sinf, int ssup){
	t_nodo anterior = NULL;
	t_nodo actual = (*p);
	while(actual != NULL){
		if((actual->dato.stock)> ssup || (actual->dato.stock)< sinf){
			if(anterior ==NULL){
				(*p)=actual->sig; /*Borra la cabeza*/
				free(actual);
			}else{
				actual=actual->sig;
				anterior = actual;
			}
			anterior->sig=actual->sig;
			free(actual);
			actual = anterior->sig;
		}
		anterior=actual;
		actual = actual->sig;
	}
}

int main() {
	t_nodo pila=NULL;
    t_dato dato;
	cargarPila(&pila,"productos.txt");
	printf("\nPila despues de eliminar productos con stock entre 200 y 300\n");
    eliminar(&pila,200,300);
    while(pila!=NULL){
        dato=pop(&pila);
        printf("%-35s%-10d%-10.2f\n",dato.nomprod,dato.stock,dato.precio);
    }
	return 0;
}


