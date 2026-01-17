#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct num{
	int n;
	struct num* sig;
};
typedef struct num* p_num;

p_num eliminarCabeza(p_num *pp){
	p_num aux = *pp;
	*pp = (*pp)->sig;
	free(aux);
	return *pp;
}

void eliminarNodoPos(p_num *p,int pos){
	p_num actual = (*p)->sig;
	p_num anterior =*p;
	pos--; 
	while((pos)>0 && actual->sig!=NULL){
		anterior =actual;
		actual = actual->sig;
		pos--;
	}
	if(pos==0){
		anterior->sig = actual->sig;
		free(actual);
	}
	
}
void eliminarNodo(p_num *p,int pos){
	if (*p!=NULL) {
		if(pos==0){
			*p=eliminarCabeza(&(*p));
		}else{
			eliminarNodoPos(p,pos);
		}
	}
}
void imprimir(p_num p){
	while(p && p->n !=0){
		printf("%d\n",p->n);
		p=p->sig;
	}
}
	
p_num crearNodo(int num){
	p_num nodo = malloc(sizeof(struct num));
	if(nodo !=NULL){
		nodo->n=num;
		nodo->sig=NULL;
	}
	return nodo;
}
	
void agregarFinal(p_num* p,p_num nuevo){
	if(*p == NULL){
		*p = nuevo;
	}else{
		agregarFinal(&((*p)->sig),nuevo);
	}
}

void crear(p_num * lis){
	int n;
	printf("\nIngese un numero: ");
	scanf("%d",&n);
	while(n!=0){
		agregarFinal(lis,crearNodo(n));
		printf("\nIngese un numero: ");
		scanf("%d",&n);
	}
}
	
int main() {
	p_num lista= NULL;
	crear(&lista);
	imprimir(lista);
	printf("\n");
	eliminarNodo(&lista,3);
	imprimir(lista);
	return 0;
}

