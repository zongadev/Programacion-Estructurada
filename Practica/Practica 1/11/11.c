#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 25
#define F 25

void ordenarTexto(char mat[F][C]){
	int i=0,j=1;
	char aux[C];
	while(mat[i][0]!='\0' && i<F-1){
		while(mat[j][0]!='\0' && j<C-1){
			if(strcmp(mat[i],mat[j])<0){
				strcpy(aux,mat[i]);
				strcpy(mat[i],mat[j]);
				strcpy(mat[j],aux);
			}
			j++;
		}
		j=0;
		i++;
		
	}
}

void imprimirMatText(char mat[F][C]){
	printf("Matriz: \n");
	for(int i =0; i<F;i++){
		printf("%s\n",mat[i]);
	}
}
	
void cargarMatTextDeArch(char mat[F][C],FILE* arch){
	int i=0;
	int aux;
	int r= (int)fgets(mat[i], C-1,arch);
	while(r!=0 && i<F-1){
		i++;
		r=(int)fgets(mat[i], C-1,arch);
	}
	mat[i+1][0]='\0';
}
		
int main() {
	char matI[F][C] = {0};
	FILE* arch;
	arch = fopen("equipos.txt", "r");
	if(arch != NULL){
		cargarMatTextDeArch(matI,arch);
		fclose(arch);
imprimirMatText(matI);
	}
	ordenarTexto(matI);
	imprimirMatText(matI);
	return 0;
	}
		
		
