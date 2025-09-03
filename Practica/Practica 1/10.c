#include <stdio.h>
#include <stdlib.h>

#define C 25
#define F 25

void imprimirMatText(char mat[F][C]){
	printf("Matriz: \n");
	for(int i =0; i<F;i++){
		printf("%s",mat[i]);
	}
}

void cargarMatTextDeArch(char mat[F][C],FILE* arch){
	int i=0;
	int r= (int)fgets(mat[i], C-1,arch);
	while(r!=0){
		i++;
		r=(int)fgets(mat[i], C-1,arch);
	}
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
	return 0;
}

