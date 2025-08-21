#include <stdio.h>
#include <string.h>
#define F 4
#define C 10


void imprimirMatText(char mat[F][C]){
	printf("Matriz: \n");
	for(int i =0; i<F && mat[i][0]!='\0';i++){
		for(int j=0;j<C && mat[i][j]!='\0';j++){
			printf("[%c]",mat[i][j]);
		}
		printf("\n");
	}
}

void cargarMatText(char mat[F][C]){
	char c;
	
	int j;
	for(int i=0; i<F-1; i++){
		j=0;
		while(j<C-1 && (c=getchar())!='\n'){
			mat[i][j]=c;
			j++;
		}
		for(j;j<C;j++){//como el anterior frena uno antes de C, si se pasa truncaria y pondira \0
			mat[i][j]='\0';
		}
	}
	mat[F-1][0]='\0';
}
	
void ordenarMatText(char mat[F][C]){
	char aux[C];
	for(int i=0;i<F-1;i++){
		if(mat[i+1][0]!='\0' && strcmp(mat[i],mat[i+1])>0){
			strcpy(aux,mat[i]);
			strcpy(mat[i],mat[i+1]);
			strcpy(mat[i+1],aux);
		}
	}//quedo sin andar el ordenar
}

int main(){
	char matI[F][C];
	cargarMatText(matI);
	imprimirMatText(matI);
	ordenarMatText(matI);
	imprimirMatText(matI);
	return 0;
}
