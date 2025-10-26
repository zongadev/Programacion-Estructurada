#include <stdio.h>

p_num crearNodo(int num){ /*ACA PASA POR PARAMETRO TODO LO QUE TENGA EL struct
	TAMBIEN PODES CARGARLO ACA MISMO PERO CAMBIA LA FUNCION CREAR*/
	p_num nodo = malloc(sizeof(struct num));
	if(nodo !=NULL){
		nodo->n=num;
		nodo->sig=NULL;
	}
	return nodo;
}
	
	
	void agregarFinal(p_num* p,p_num nuevo){ /*Esto incluye la cabeza*/
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
		agregarFinal(lis,crearNodo(n));/*ACA VAS AGREGANDO AL FINAL*/
			printf("\nIngese un numero: ");
				scanf("%d",&n);
	}
}
	

/*Los dos codigos de aca abajo son para eliminar si se es igual a cierto parametro*/
	
	void eliminarUnNodo(p_persona* pp, char val[]){
		if(strcmp((*pp)->apellido,val)==0){
			p_persona tmp = (*pp);
			*pp = (*pp)->sig;
			free(tmp);
		}else{
			p_persona actual = (*pp)->sig;
			p_persona anterior = *pp;
			while(strcmp(actual->apellido,val)){
				anterior = actual;
				actual = actual->sig;
			}
			if(actual->sig !=NULL ||strcmp(actual->apellido,val)==0 ){
				anterior->sig=actual->sig;
			}
		}
	}
		
		void eliminarTodos(p_persona* pp, char val[]){
			while(strcmp((*pp)->apellido,val)==0){
				p_persona tmp = (*pp);
				*pp = (*pp)->sig;
				free(tmp);
			}
			
			if((*pp)->sig != NULL){
				p_persona actual = (*pp)->sig;
				p_persona anterior = *pp;
				while (actual!=NULL) {
					if(strcmp(actual->apellido,val)==0){
						anterior->sig=actual->sig;
						free(actual);
						actual=anterior->sig;
						
					}else{
						anterior = actual;
						actual = actual->sig;
					}
				}
			}
		}
			
