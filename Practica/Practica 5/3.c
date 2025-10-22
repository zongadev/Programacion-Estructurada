#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_lista{
	int num;
	struct s_lista* sig;
};
typedef struct s_lista* p_lista;

void cargarCabeza(p_lista *p){
	int aux;
	printf("Ingrese numeros: \n");
	scanf("%d",&aux);
	if(*p==NULL){
		(*p)= malloc(sizeof(struct s_lista));
		(*p)->num = aux;
		(*p)->sig = NULL;
	}
}

void cargarLista(p_lista u){
	int aux;
	scanf("%d",&aux);
	while(aux!=0){
		u->sig=malloc(sizeof(struct s_lista));
		if (!u->sig) { perror("malloc"); exit(1); }
		u=u->sig;
		u->num = aux;
		u->sig = NULL; 
		scanf("%d",&aux);
	}
}
	
void eliminarUnNodo(p_lista* pp, int val){
	if((*pp)->num == val){
		p_lista tmp = (*pp);
		*pp = (*pp)->sig;
		free(tmp);
	}else{
		p_lista actual = (*pp)->sig;
		p_lista anterior = *pp;
		while(actual->num!=val){
			anterior = actual;
			actual = actual->sig;
		}
		if(actual->sig !=NULL ||actual->num==val ){
			anterior->sig=actual->sig;
		}
	}
}
	
void eliminarTodos(p_lista* pp, int val){
	while((*pp)->num == val){
		p_lista tmp = (*pp);
		*pp = (*pp)->sig;
		free(tmp);
	}
	
	if((*pp)->sig != NULL){
		p_lista actual = (*pp)->sig;
		p_lista anterior = *pp;
		while (actual!=NULL) {
			if(actual->num == val){
				anterior->sig=actual->sig;
				free(actual);
				actual=anterior->sig;
				
			}else{
				anterior = actual;
				actual = actual->sig;
			};
		}
	}
}


void mostrar(p_lista p){
	printf("\n------------------\n");
	while(p!=NULL){
		printf("%d\n",p->num);
		p=p->sig;
	}
	printf("\n------------------");
}
int main() {
	p_lista p=NULL;
	cargarCabeza(&p);
	cargarLista(p);
	mostrar(p);
	/*eliminarUnNodo(&p,5);*/
	eliminarTodos(&p,5);
	mostrar(p);
	return 0;
}

