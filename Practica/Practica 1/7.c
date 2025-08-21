#include <stdio.h>
#define MAX_C 3
#define MAX_F 3


void cargarMat(int mat[MAX_F][MAX_C]);
void imprimirMat(int mat[MAX_F][MAX_C]);

void cargarMat(int mat[MAX_F][MAX_C]){
	printf("Ingrese los valores de la matriz: \n \t");
	printf("[i][j]:n \n");
	for(int i =0; i<MAX_F;i++){
		for(int j=0;j<MAX_C;j++){
			printf("\t[%d][%d]:",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
}
	
void imprimirMat(int mat[MAX_F][MAX_C]){
	printf("Matriz: \n");
	for(int i =0; i<MAX_F;i++){
		for(int j=0;j<MAX_C;j++){
			printf("[%d]",mat[i][j]);
		}
		printf("\n");
	}
}
	
void promMat(int mat[MAX_F][MAX_C]){
	int sum=0;
	float prom;
	for(int i =0; i<MAX_F;i++){
		for(int j=0;j<MAX_C;j++){
			sum+=mat[i][j];
		}
	}
	prom = sum/(MAX_F*MAX_C);
	printf("\t \t Promedio: %.2f",prom);
}
int main() {
	int matI[MAX_F][MAX_C];
	cargarMat(matI);
	imprimirMat(matI);
	promMat(matI);
	return 0;
}

