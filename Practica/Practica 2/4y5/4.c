#include <stdio.h>
#include <string.h>
#define N 5
typedef struct persona{
	char nombre[20];
	char pais[20];
	int dni;
}persona;

void imprimir(char archivo[]){
	FILE* arch = fopen(archivo,"r");
	char nombre[20],pais[20];
	int dni;
	printf("Nombre\t Apellido \tEdad\n");
	int r = (int) fscanf(arch,"%19[^,],%19[^,],%d\n",nombre,pais,&dni);
	while(r!=EOF){
		printf("%s\t %s \t%d\n",nombre,pais,dni);
		r = (int) fscanf(arch,"%19[^,],%19[^,],%d\n",nombre,pais,&dni);
	}
}
	
void cargarArchivo(char archivo[]){
	FILE* arch =fopen(archivo, "w");
	int i=0;
	int j =1,dni,k=0;
	char nombre[20],pais[20],c;
	while(i<N && j==1){
		printf("-------------------------------------");
		printf("\nIngrese Nombre:\n");
		while((c=getchar())!='\n' && k<20){
			nombre[k]=c;
			k++;
		}
		
		nombre[k]='\0';
		k=0;
		printf("\nIngrese Apellido:\n");
		while((c=getchar())!='\n' && k<20){
			pais[k]=c;
			k++;
		}
		pais[k]='\0';
		k=0;
		printf("\nIngrese Edad:\n");
		scanf("%d",&dni);
		getchar();
		if(dni!=-1){
			fprintf(arch,"%s,%s,%d\n",nombre,pais,dni);
			i++;
			
		}else{
			j=0;
		}
		
	}
	fclose(arch);
}

int main(){
	char archivo[] = "personas.txt";
	cargarArchivo(archivo);
	imprimir(archivo);
	return 0;
}
