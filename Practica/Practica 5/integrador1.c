/**
Se carga un arreglo dinámico desde un archivo
Elimina del arreglo dinamico aquellos productos cuyo stock esté entre 
200 y 300 (extremos inclusive). Luego de eliminar, el arreglo dinámico debe quedar 
constituido sin desperdicio de memoria.
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
typedef struct s_dato* t_dato;
typedef struct s_dato v_dato;


void leerCadenaArch(FILE* arch, char** str, char sep){
	int i =0;
	char c;
	(*str)=malloc(sizeof (char));
	c=fgetc(arch);
	while(c!=EOF && c!=sep){
		(*str)[i]=c;
		
		i++;
		(*str) = realloc((*str),(i+1)*sizeof(char));
		c = fgetc(arch);
	}
	(*str)[i]='\0';
}

void cargarArrDin(t_dato* arr,const char* nomArch){
	FILE* arch= NULL;
	v_dato aux;
	int i=0;
	arch = fopen(nomArch,"r");

	(*arr)= malloc(sizeof(v_dato));
	while(!feof(arch)){
		leerCadenaArch(arch,&(aux.nomprod),',');
		fscanf(arch,"%d,",&aux.stock);
		fscanf(arch,"%f\n",&aux.precio);
		(*arr)[i] = aux;
		i++;
		(*arr) = realloc(*arr,(i+1)*sizeof(v_dato));
	}
	(*arr)[i].stock =-1;
	fclose(arch);
	return;
}


	
void eliminarEnArr(t_dato* arr,int sinf, int ssup){
	for (int i =0 ; (*arr)[i].stock=-1; i++){
		if((*arr)[i].stock>=ssup || (*arr)[i].stock<=sinf){
			while((*arr)[i].stock != ){
				
			}
		}
	}
	
}
void imprimirArrDin(t_dato arr){
	int i =0;
	while((arr)[i].stock!=-1){
		printf("%s,%d \n",(arr)[i].nomprod,(arr)[i].stock);
		i++;
	}
}
	
int main() {
	t_dato arr=NULL;
	
	cargarArrDin(&arr,"productos.txt");
	printf("ARREGLO original de Productos\n");
	imprimirArrDin(arr);
	printf("\nARREGLO despues de eliminar productos con stock entre 200 y 300\n");
	eliminarEnArr(&arr,200,300);
	imprimirArrDin(arr);
	return 0;
}

