#include <stdio.h>
#include<string.h>

#define T 6
typedef struct equipo{
	char nombre[25];
	int PG;
	int PP;
	int PE;
	int GF;
	int GC;
}equipo;

void cargarMatrizStruct(equipo mat[T], char archivo1[],char archivo2[]){
	int i =0;
	FILE* arch1 = fopen(archivo1, "r");
	FILE* arch2 = fopen(archivo2, "r");
	int r=fscanf(arch1, "%d,%d,%d,%d,%d",&mat[i].PG,&mat[i].PP,&mat[i].PE,&mat[i].GF,&mat[i].GC);
	int rr=(int)fgets(mat[i].nombre,10,arch2);
	while(r!=EOF && rr!=EOF){
		i++;
		r=fscanf(arch1, "%d,%d,%d,%d,%d",&mat[i].PG,&mat[i].PP,&mat[i].PE
				 ,&mat[i].GF,&mat[i].GC);
		rr=(int)fgets(mat[i].nombre,10,arch2);
		
	}
}

void mostrar(equipo mat[T], char archivo[]){
	int i=0;
	FILE* arch = fopen(archivo, "r");
	char c=getc(arch);
	while(c!=EOF){
		printf("%c", c);
		c=getc(arch);
		if(c=='\n'){
			printf("\t");
			c=getc(arch);
		}
	}
	printf("\n");
	while(i<T-1){
		printf("\n%s \t%d\t%d\t%d\t%d\t%d\n",mat[i].nombre,mat[i].PG,mat[i].PP,mat[i].PE,mat[i].GF,mat[i].GC);
		i++;
	}
}

int main(){
	equipo matI[T];

	char archivo1[]="items.txt";
	char archivo2[]="cabeceras.txt";
	char archivo3[]="datos.txt";
	cargarMatrizStruct(matI,archivo3,archivo1);
	mostrar(matI,archivo2);
	return 0;
}
