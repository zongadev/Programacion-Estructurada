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
	int i=0;
	int j=0;
	printf("Ingrese los valroes de la matris \n");
	printf("\t [%d]: ",i);
	c=getchar();
	while(c!='\n' && i<F-1){
		while(j<C-1&& c!='\n'){
			mat[i][j]=c;
			c=getchar();
			j++;
	}
		mat[i][j]='\0';
		i++;
		j=0;
		if(i<F-1){
			printf("\t [%d]: ",i);
			c=getchar();
		}
	}
	mat[i][0]='\0';
}	
	
void ordenarMatText(char mat[F][C]){
	char aux[C];
	
	for(int i=0;i<F-1;i++){
		for(int j = i+1;j<F; j++){
			if(mat[j][0]!='\0' && strcmp(mat[i],mat[j])>0){
				strcpy(aux,mat[i]);
				strcpy(mat[i],mat[j]);
				strcpy(mat[j],aux);
			}
		}
		
	}
}

int main(){
	char matI[F][C]= {0};
	cargarMatText(matI);
	imprimirMatText(matI);
	ordenarMatText(matI);
	imprimirMatText(matI);
	return 0;
}
