 #include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct lista_s{
	int num;
	struct lista_s* sig;
};

typedef struct lista_s *t_lista;
typedef struct lista_s d_lista;

void imprimir(t_lista p){
	while(p && p->num !=0){
		printf("%d\n",p->num);
		p=p->sig;
	}
}
	
void crear(t_lista p){

	printf("Ingrese un numero: ");
	scanf("%d",&p->num);
	while(p->num != 0){
		p->sig = malloc(sizeof(d_lista));
		p = p->sig;
		printf("\nIngrese un numero: ");
		scanf("%d",&p->num);
		if(p->num == 0){
			p->sig = NULL;
		}
	}
}

void inv(t_lista p){
	if(p->sig->sig != NULL){
		inv(p->sig);
	}
	printf("%d\n",p->num);
}
int main() {
	d_lista lista = {0};
	crear(&lista);
	imprimir(&lista);
	printf("---------------\n");
	inv(&lista);
	printf("---------------\n");
	/*generalizado para otra estructura usas el mismo que el inv, lo unico que cambias 
	el printf por una funcion que imprima el struct personalizado.
	*/
	
	return 0;
}

