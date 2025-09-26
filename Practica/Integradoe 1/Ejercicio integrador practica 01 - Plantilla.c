/**
Ejercicio integrador practica 01

Se tiene un archivo de titulos (PRODUCTO, STOCK y PRECIO) 
y un archivo con los datos de los productos. 
Se puede tener un maximo de 100 productos. 
Cargar los titulos y los datos en arreglos estaticos, 
imprimir una tabla incluyendo titulos y datos, 
ordenar los productos por stock de mayor a menor, 
imprimir nuevamente la tabla con los datos ordenados.
*/
#include<stdio.h>
#include<string.h>
#define F 100
#define C 50
int cargarDatosDeArch(char [],char [F][C],int [],float []);
int cargarTitulosDeArch(char [],char[F][C]);
void ordenarPorStock(char [F][C],int[],float[]);
void imprimirTabla(char[F][C],char[F][C],int[],float[]);
int main(){
	int retorno=0;
    char titulos[F][C] = {'\0'} , nom[F][C];
	int stock[F];
	float precio[F];
	cargarTitulosDeArch("titulo.txt",titulos);
	cargarDatosDeArch("productos.txt",nom,stock,precio);
	imprimirTabla(titulos,nom,stock,precio);
	return retorno;
}


int cargarDatosDeArch(char nom[],char prod[F][C],int st[],float p[]){
    int res=0, i=0,j=0,r=0;
	char c;
	FILE* arch;
	arch = fopen(nom,"r");
	if(arch!=NULL){
		c=fgetc(arch);
		while(c!=',' && j<C-1){
			prod[i][j]=c;
			c=fgetc(arch);
			j++;
		}
		prod[i][j]='\0';
		j=0;
		r=fscanf(arch,"%d,%f\n",&st[i],&p[i]);
		i++;
		c=fgetc(arch);
		while(c!=EOF){
			while(c!=',' && j<C-1 &&c!=EOF){
				prod[i][j]=c;
				c=fgetc(arch);
				j++;
				
			}
			prod[i][j]='\0';
			
			j=0;
			
			r=fscanf(arch,"%d,%f\n",&st[i],&p[i]);
			i++;
			c=fgetc(arch);
		}
	}
    return res;
}

int cargarTitulosDeArch(char nom[],char tit[F][C]){
    int res=0,i=0,r;
	FILE* arch;
	arch = fopen(nom,"r");
	if (arch != NULL) {
		r = fscanf(arch,"%s[^\n]\n",tit[i]);
		while(r!=EOF){
			i++;
			r = fscanf(arch,"%s[^\n]\n",tit[i]);
		}
		fclose(arch);
	}
	
    return res;
}
void ordenarPorStock(char prod[F][C],int st[],float p[]){
	// CODIFICAR AQUI
	
}
void imprimirTabla(char tit[F][C],char prod[F][C],int st[],float p[]){
	int i =0,j=0;
	while(tit[i][0]!='\0' && i<F){
		printf("%12s",tit[i]);
		i++;
	}
	printf("\n");
	while(prod[j][0]!='\0' && j<F){
		printf("%12d %12.2f %s\n",st[j],p[j],prod[j]);
		j++;
	}
	
}
