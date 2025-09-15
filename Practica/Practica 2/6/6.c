#include <stdio.h>
#include <string.h>

typedef struct persona{
	char nombre[20];
	char pais[20];
	int dni;
}persona;

void cargarMatriz(FILE* arch){
	int r = (int) fscanf(arch,"%19[^,],%19[^,],%d\n",nombre,pais,&dni);
	while(r!=EOF){
		printf("%s\t %s \t%d\n",nombre,pais,dni);
		r = (int) fscanf(arch,"%19[^,],%19[^,],%d\n",nombre,pais,&dni);
	}
}

void imprimir(char archivo[],int orden){
	FILE* arch = fopen(archivo,"r");
	char nombre[20],pais[20];
	int dni;
	printf("Nombre\t Pais \t DNI\n");
	printf("=========================================")
	
}
	
int main(){
	char archivo[]="personas.txt";
	int op;
	printf("Selecciones una opcion: \n \t1: Ordenar por nombre\n \t2: Ordenar por documento \n \t3: Ordenar por pais\n \t4: Salir");
	scanf("%d",&op);
	while(op!=3){
		while(op<1 && op>4){
			printf("\nIngrese una opcion valida. \n");
			scanf("%d",&op);
		}
		imprimir(archivo,op);
	}
}
