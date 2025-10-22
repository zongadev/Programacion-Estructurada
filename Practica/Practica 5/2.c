#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*hago directamente el 2.1*/

struct persona{
	char nombre[50];
	char apellido[50];
	int dni;
	struct persona* sig;
};

typedef struct persona* p_persona;
typedef struct persona v_persona;

void mostrar(p_persona p){
	printf("Nombre: %s , Apellido: %s , DNI: %d",p->nombre,p->apellido,p->dni);
}

void crear(p_persona p){
	char c;
	int i=0;
	printf("Ingrse su dni: ");
	scanf(" %d",&p->dni);
	
	while (p->dni !=0) {
/*		printf("\nIngrese su nombre: ");*/
/*		while((c=getchar())!= '\n'){*/
/*			p->nombre[i] =c;*/
/*			i++;*/
/*		}*/
/*		i=0;*/
/*		p->nombre[i] ='\0';*/
		
/*		printf("\nIngrese su apellido: ");*/
/*		while((c=getchar())!= '\n'){*/
/*			p->apellido[i] =c;*/
/*			i++;*/
/*		}*/
/*		p->nombre[i] ='\0';*/
/*		i=0;*/
/*		mostrar(p);*/
/*		p->sig = malloc(sizeof(v_persona));*/
/*		p=p->sig;*/
		
/*		printf("\nIngrse su dni: ");*/
/*		scanf(" %d",&p->dni);*/
		getchar();
		printf("\nIngrese su nombre: ");
		i = 0;
		while ((c = getchar()) != '\n' && c != EOF) {
			p->nombre[i++] = c;
		}
		p->nombre[i] = '\0';
		
		
		printf("\nIngrese su apellido: ");
		i = 0;
		while ((c = getchar()) != '\n' && c != EOF) {
			p->apellido[i++] = c;
		}
		p->apellido[i] = '\0';
		
		mostrar(p);
		
		p->sig = malloc(sizeof *p);     // tamaño del nodo, no del puntero
		p = p->sig;
		
		printf("\nIngrese su dni: ");
		scanf(" %d", &p->dni);         
	}
	p->sig=NULL;
}
	
p_persona crearuno(p_persona aux){
	char c;
	*aux = {0};
	int i=0;
	printf("\nIngrese su nombre: ");
	i = 0;
	while ((c = getchar()) != '\n' && c != EOF) {
		aux->nombre[i++] = c;
	}
	aux->nombre[i] = '\0';
	
	
	printf("\nIngrese su apellido: ");
	i = 0;
	while ((c = getchar()) != '\n' && c != EOF) {
		aux->apellido[i++] = c;
	}
	aux->apellido[i] = '\0';
	return &aux;
}
	
void insertarOrdeApe(p_persona p){
	p_persona nuevo = crearuno();
	p_persona anterior;
	
	if (p == NULL || nuevo->dni < p->dni) {
		nuevo->sig = p;
		p = nuevo;
		return;
	}
	
	if(nuevo->dni > p->dni){
		while(p->sig != NULL&& p->dni < nuevo->dni){
			p= anterior;
			p=p->sig;
		}
		if(p->sig!=NULL){
			nuevo->sig = p;
			anterior->sig = nuevo;
		}else{/*es el ultimo*/
			p->sig = nuevo;
			nuevo->sig = NULL;
		}
	}
}

int main() {
	v_persona perso={0};
	crear(&perso);
	insertarOrdeApe(&perso);
	return 0;
}

