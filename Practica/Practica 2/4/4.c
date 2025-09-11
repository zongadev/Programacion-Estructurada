#include <stdio.h>
#include <string.h>

typedef struct persona{
	char nombre[20];
	char apellido[20];
	int edad;
}persona;

void cargarArchivo(){
	printf("Ingrese Nombre:\n");
	char nombre[20],apellido[20],c;
	int i =0;
	while((c=getchar())!='\n' && i<20){
		nombre[i]=c;
		i++;
	}
	nombre[i]='\0';
	printf("\nIngrese Apellido:\n");
	while((c=getchar())!='\n' && i<20){
		apellido[i]=c;
		i++;
	}
	apellido[i]='\0';
	printf("\nIngrese Edad:\n");
	scanf("%d",edad);
	
	fscanf()
}

int main(){
	cargarArchivo();
	return 0;
}
