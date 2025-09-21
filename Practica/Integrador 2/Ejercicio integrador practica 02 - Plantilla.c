/**
Ejercicio integrador practica 02

Se tiene un archivo con la primera linea de titulos (PRODUCTO, STOCK y PRECIO)
 y el resto de las lineas con los datos de los productos. 
Se puede tener un maximo de 100 productos. 
Definir struct para cargar los titulos y los datos en un arreglo estatico, 
imprimir una tabla incluyendo titulos  y datos, ordenar los productos 
alfabeticamente de menor a mayor, imprimir nuevamente la tabla con
los datos de los productos cuyo stock este comprendido dentro 
de un rango determinado.
*/
#include<stdio.h>
#include<string.h>
#define F 100
#define C 50

struct s_titu{
    char prod[C];
	char stock[C];
	char prec[C];
};
typedef struct s_titu t_titu;

struct s_dato{
    char nomprod[C];
	int stock;
	float precio;
	
};
typedef struct s_dato t_dato;

struct s_contenido{
    t_titu titulo;
	t_dato dato[F];
};
typedef struct s_contenido t_contenido;

int cargarDatosDeArch(char [],t_contenido []);
void imprimirTabla(t_contenido []);
void ordenarPorProd(t_contenido []);
void imprimirTablaConFiltro(t_contenido [],int,int);

int main(){
    int res=0;
	t_contenido contenido[1];
	cargarDatosDeArch("productos2.txt",contenido);
	imprimirTabla(contenido);
    ordenarPorProd(contenido);
	imprimirTablaConFiltro(contenido,100,250);
    return res;
}

int cargarDatosDeArch(char nom[],t_contenido content[1]){
    int res=0;
	int r,i=0,j=0;
	char c;
	FILE* arch = fopen(nom,"r");
	if (arch != NULL) {
		r= (int) fscanf(arch,"%49[^,],%49[^,],%49[^,\n]\n",content[0].titulo.prod,content[0].titulo.stock,content[0].titulo.prec);
		c=getc(arch);
		while (i<F-1 && c!=EOF) {
			while(c!= ',' && c!=EOF && j<C-1){
				content[0].dato[i].nomprod[j]=c;
				j++;
				c=getc(arch);
			}
			content[0].dato[i].nomprod[j]='\0';
			j=0;
			r=fscanf(arch,"%d,%f\n",&content[0].dato[i].stock,&content[0].dato[i].precio);
			i++;
			c=getc(arch);
		}
		content[0].dato[i].precio=-1;
	}
    return res;
}
	

void imprimirTabla(t_contenido content[1]){
	int i=0;
	
	printf("%5s\t%5s\t\t%5s\n",content[0].titulo.stock,content[0].titulo.prec,content[0].titulo.prod);
	while(i<F && content[0].dato[i].precio !=-1){
		printf("%6d\t%8.2f\t %s\n", content[0].dato[i].stock, content[0].dato[i].precio,content[0].dato[i].nomprod);
		i++;
	}
	
}

void ordenarPorProd(t_contenido content[1]){
	int i=0;
	int j=i+1;
	t_dato aux;
	while (content[0].dato[i].precio !=-1){
		while(content[0].dato[j].precio !=-1){
			if(strcmp(content[0].dato[i].nomprod,content[0].dato[j].nomprod)<0){
				aux = content[0].dato[i];
				content[0].dato[i] = content[0].dato[j];
				content[0].dato[j] = aux;
			}
			j++;
		}
		i++;
		j=0;
	}
	printf("\n===========================\n");
	imprimirTabla(content);
}

void imprimirTablaConFiltro(t_contenido content[1],int stinf,int stsup){
	int i=0;
	printf("\n =======================\n");
	printf("%5s\t%5s\t\t%5s\n",content[0].titulo.stock,content[0].titulo.prec,content[0].titulo.prod);
	while(i<F && content[0].dato[i].precio !=-1){
		if(content[0].dato[i].stock >=stinf && content[0].dato[i].stock<=stsup){
			printf("%6d\t%8.2f\t %s\n", content[0].dato[i].stock, content[0].dato[i].precio,content[0].dato[i].nomprod);
		}	
		i++;
	}
	
}


