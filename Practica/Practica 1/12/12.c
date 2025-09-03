#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 25
#define F 25

void imprimirMatText(char mat[F][C]){
	printf("Matriz: \n");
	for(int i =0; i<F;i++){
		printf("%s\n",mat[i]);
	}
}

void cargarMatNumDeArch(int mat[F][C], char archivo[]){
	int i=0,j=0,r;
	FILE* arch;
	int num;
	arch = fopen(archivo,"r");
	r=fscanf(arch,"%d,",num);
	while((r!=EoF) && i<F && j<C){
		mat[i][j]=num;
		j++;
		if()
	}
	imprimirMatText(mat);
}

int main(){
	char archivo[] = "puntos.txt";
	return 0;
}
