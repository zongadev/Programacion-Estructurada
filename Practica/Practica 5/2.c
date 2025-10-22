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
	printf("Nombre: %s , Apellido: %s , DNI: %d \n",p->nombre,p->apellido,p->dni);
}

void crear(p_persona p){
	char c;
	int i=0;
	printf("Ingrse su dni: ");
	scanf(" %d",&p->dni);
	
	while (p->dni !=0) {
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
		
		
		p->sig = malloc(sizeof *p);     // tamaño del nodo, no del puntero
		p = p->sig;
		p->sig=NULL;
		printf("\nIngrese su dni: ");
		scanf(" %d", &p->dni);         
	}
}
	
	
	
void crearuno(p_persona aux){
	char c;
	int i=0;
	printf("\n------------Nuevo------------\n");
	printf("\nIngrese su dni: ");
	scanf(" %d", &aux->dni);    
	getchar();
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

}
	
void insertarOrdeApe(p_persona p){ /*ACA HABRIA QUE PASAR UN PUNTERO DE PUNTERO
	Eso es pq hay chances de modificar el puntero P que es el que tiene el head
	Siempre que se modifiquie el head hay que pasar el *P  */
	p_persona nuevo = malloc(sizeof(v_persona));
	crearuno(nuevo);
	p_persona anterior;
	p_persona actual;
	
	if (p == NULL || nuevo->dni < p->dni) {
		nuevo->sig = p;
		p = nuevo;
		return;
	}
	anterior =p;
	actual = p->sig;
	if(nuevo->dni > p->dni){
		while(actual->sig != NULL&& actual->dni < nuevo->dni){
			anterior =actual;
			actual=actual->sig;
		}
		if(p->sig!=NULL){
			nuevo->sig = actual;
			anterior->sig = nuevo;
		}else{/*es el ultimo*/
			actual->sig = nuevo;
			nuevo->sig = NULL;
		}
	}
}
	
void mostrarTodo(p_persona p){
	while(p->sig != NULL && p->dni!=0){
		mostrar(p);
		p=p->sig;
	}
}

int main() {
	v_persona perso={0};
	crear(&perso);
	insertarOrdeApe(&perso);
	mostrarTodo(&perso);
	return 0;
}

