#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 8
#define F 25

void imprimirMatText(int mat[F][C]){
	printf("Matriz: \n");
	int i=0,j=0;
	while(i<F-1 && mat[i][j]!=999){
		while(j<C && mat[i][j]!=999){
			printf("%d,",mat[i][j]);
			j++;
		}
		j=0;
		i++;
		printf("\n");
	}
	printf("\n");
}

void completarDiferenciaGoles(int mat[F][C]){
	int i=0,j=0;
	while(i<F-1 && mat[i][j]!=999){
		mat[i][C-1]= mat[i][5] - mat[i][6];
		i++;
	}
}
void cargarMatNumDeArch(int mat[F][C], char archivo[]){
	int i=0,j=0,r;
	FILE* arch;
	int num;
	arch = fopen(archivo,"r");
	if(arch==NULL)                    
		return;         
	r=fscanf(arch,"%d,",&num);
	while((r!=EOF) && i<F){
		while(j<C-1 && r!=EOF){
			mat[i][j]=num;
			j++;
			if(j<C-1){
				r=fscanf(arch,"%d,",&num);
			}
		}
		j=0;
		i++;
		r=fscanf(arch,"%d,",&num);
	}
	mat[i][0]=999;
	completarDiferenciaGoles(mat);
}

int main(){
	int matI[F][C] = {0};
	char archivo[] = "puntos.txt";
	int matI[F][C] = {0};
	cargarMatNumDeArch(matI,archivo);
	imprimirMatText(matI);
	return 0;
}
