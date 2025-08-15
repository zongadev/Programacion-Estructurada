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


void imprimirArrDin(t_dato arr){

	
}
	
void cargarArrDin(t_dato* arr,char* nomArch){

	
}
					
void eliminarEnArr(t_dato* arr,int sinf, int ssup){

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
				
