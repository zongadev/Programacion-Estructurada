#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C 9
#define F 10

void imprimirMatText(char mat[F][C]){
	int i=0;
	printf("Matriz:\n");
	while(mat[i][0]!= '\0'){
		printf("%s\n",mat[i]);
		i++;
	}
}
	
	void imprimirMatInt(int mat[F][C]){
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
	}
		void completarDiferenciaGoles(int mat[F][C]){
			int i=0,j=0;
			while(i<F-1 && mat[i][j]!=999){
				mat[i][C-1]= mat[i][5] - mat[i][6];
				i++;
			}
		}
void cargarMatrizChar(char mat[F][C], char archivo[]){
	
	int i=0;
	FILE* arch = fopen(archivo,"r");
	char text[C];
	int r=fscanf(arch,"%s",text);
	while (r!=EOF && i<F-1){
		strcpy(mat[i],text);
		i++;
		r=fscanf(arch,"%s",text);
	}
	mat[i][0]='\0';
}

	void cargarMatNumDeArch(int mat[F][C], char archivo[]){
		int i=0,j=0,r;
		char c;
		FILE* arch;
		int num;
		arch = fopen(archivo,"r");
		if(arch==NULL)                    
			return;         
		r=fscanf(arch,"%d",&num);
		c=getc(arch);
		
		while((r!=EOF) && i<F-1){
			while(j<C-1 && r!=EOF && c!='\n'){
				mat[i][j]=num;
				printf("%d",mat[i][j]);
				j++;
				if(j<C-1 && c!='\n'){ 
					r=fscanf(arch,"%d",&num);
					c=getc(arch);
				}
			}
			mat[i][j]=num;
			j=0;
			i++;
			r=fscanf(arch,"%d",&num);
			c=getc(arch);
		}
		mat[i][0]=999;
		completarDiferenciaGoles(mat);
	}


int main() {
	char matI[F][C]={0};
	char matC[F][C]={0};
	int matP[F][C]={0};
	cargarMatrizChar(matI,"items.txt");
	cargarMatrizChar(matC,"cabeceras.txt");
	cargarMatNumDeArch(matP,"datos.txt");
	imprimirMatText(matI);
	imprimirMatText(matC);
	imprimirMatInt(matP);
	return 0;
}

