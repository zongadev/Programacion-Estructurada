#include <stdio.h>

#define TAM_C 3
#define TAM_F 3

#define MAX_C 3
#define MAX_F 3


void tranasponer(int mat[TAM_F][TAM_C]);
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
void igualar(int original[TAM_F][TAM_C],int copia[TAM_F][TAM_C]){
	for(int i =0; i<MAX_F;i++){
		for(int j=0;j<MAX_C;j++){
			copia[i][j]=original[i][j];
		}
	
	}
}
void transponer(int mat[TAM_F][TAM_C]){
	int auxMat[TAM_F][TAM_C];
	igualar(mat,auxMat);
	for(int i =0; i<MAX_F;i++){
		for(int j=0;j<MAX_C;j++){
			mat[j][i]=auxMat[i][j];
		}
	}
}
int main(){
	int matI[MAX_F][MAX_C];
	cargarMat(matI);
	imprimirMat(matI);
	transponer(matI);
	imprimirMat(matI);
	return 0;
}
