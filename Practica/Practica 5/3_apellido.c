#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona{
	char nombre[50];
	char apellido[50];
	int dni;
	struct persona* sig;
};

struct s_lista{
	int num;
	struct s_lista* sig;
};
typedef struct s_lista* p_lista;


typedef struct persona* p_persona;
typedef struct persona v_persona;

void cargarCabeza(p_persona *p){
	int dni,i;
	char c;
	printf("Ingrese su dni: \n");
	scanf("%d",&dni);
	if(*p==NULL && dni!=0){
		(*p)= malloc(sizeof(v_persona));
		(*p)->dni = dni;
		(*p)->sig = NULL;
		
		getchar();
		printf("\nIngrese su nombre: ");
		i=0;
		while((c=getchar())!= '\n'){
			(*p)->nombre[i]=c;
			i++;
		}
		(*p)->nombre[i]='\0';
		
		
		printf("\nIngrese su apellido: ");
		i=0;
		while((c=getchar())!= '\n'){
			(*p)->apellido[i]=c;
			i++;
		}
		(*p)->apellido[i]='\0';
	}
}
	
void cargarLista(p_persona u){
	int dni,i;
	char c;
	printf("Ingrese un dni: ");
	scanf("%d",&dni);
	while(dni!=0){
		u->sig=malloc(sizeof(v_persona));
		if (!u->sig) { perror("malloc"); exit(1); }
		u=u->sig;
		u->dni = dni;
		u->sig = NULL; 
		
		getchar();
		printf("\nIngrese su nombre: ");
		i=0;
		while((c=getchar())!= '\n'){
			u->nombre[i]=c;
			i++;
		}
		u->nombre[i]='\0';
		
		
		printf("\nIngrese su apellido: ");
		i=0;
		while((c=getchar())!= '\n'){
			u->apellido[i]=c;
			i++;
		}
		u->apellido[i]='\0';
		printf("\n Ingrese un dni: ");
		scanf("%d",&dni);
		}
	}
	
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
				
void mostrar(p_persona p){
	printf("\n------------------\n");
	while(p!=NULL){
		printf("%s,%s,%d\n",p->nombre,p->apellido,p->dni);
		p=p->sig;
	}
	printf("\n------------------");
	}
int main() {
	p_persona p=NULL;
	cargarCabeza(&p);
	cargarLista(p);
	mostrar(p);
	/*eliminarUnNodo(&p,"moy");*/
	eliminarTodos(&p,"moy");
	mostrar(p);
	return 0;
}


