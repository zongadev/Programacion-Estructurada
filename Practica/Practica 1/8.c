#include <stdio.h>

#define TAM_C 5
#define TAM_F 5

#define MAX_C 5
#define MAX_F 5

#define TERM 0

void tranasponer(int mat[TAM_F][TAM_C]);
void cargarMat(int mat[MAX_F][MAX_C]);
void imprimirMat(int mat[MAX_F][MAX_C]);

void cargarMat(int mat[MAX_F][MAX_C]){
	int i=0, j=0;
	int c;
	printf("Ingrese los valores de la matriz: \n \t");
	printf("\t[%d][%d]:",i,j);
	scanf("%d",&c);
	while(i <MAX_F-1&& c!=0){
		
		while(j<MAX_C-1 && c!=0){
			mat[i][j]=c;
			j++;
			if(j<MAX_C-1){
				printf("\t[%d][%d]:",i,j);
				scanf("%d",&c);
			}
		}
		mat[i][j]=TERM;
		i++;
		j=0;
		if(i<MAX_F-1){
			printf("\t[%d][%d]:",i,j);
			scanf("%d",&c);
		}
	}
	mat[i][j]=0;
}
	
	void imprimirMat(int mat[MAX_F][MAX_C]){
		int i=0,j=0;
		printf("Matriz: \n");
		while(i<MAX_F && mat[i][j]!=0){
			while(j<MAX_C && mat[i][j]!=0){
				printf("[%d]",mat[i][j]);
				j++;
			}
			j=0;
			i++;
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
	for(int i =0; i<MAX_F-1;i++){
		for(int j=0;j<MAX_C-1;j++){
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
