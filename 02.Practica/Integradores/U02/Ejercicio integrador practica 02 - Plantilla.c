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
};
typedef struct s_titu t_titu;

struct s_dato{
	char nomprod[C];
	int stock;
	float precio;
	
};
typedef struct s_dato t_dato;

struct s_contenido{
	t_titu titulo[3];
	t_dato datos[F];
	
};
typedef struct s_contenido t_contenido;

int cargarDatosDeArch(char [],t_contenido []);
void imprimirTabla(t_contenido []);
void ordenarPorProd(t_contenido []);
void imprimirTablaConFiltro(t_contenido [],int,int);

int main(){
	t_contenido contenido[1];
	cargarDatosDeArch("productos2.txt",contenido);
	imprimirTabla(contenido);
	ordenarPorProd(contenido);
	printf("\n==========================\n");
	imprimirTabla(contenido);
	return 0;
}
	
	int cargarDatosDeArch(char nom[],t_contenido content[1]){
		int res=1,i=0;
		FILE* arch = fopen(nom,"r");
		if (arch!=NULL) {
			int r=fscanf(arch,"%15[^,],%15[^,],%15[^,\n]\n",content[0].titulo[0].prod,content[0].titulo[1].prod,content[0].titulo[2].prod);
			/*printf("%s,%s,%s",content[0].titulo[0].prod,content[0].titulo[1].prod,content[0].titulo[2].prod);*/
			while((r= fscanf(arch,"%49[^,],%d,%f\n",content[0].datos[i].nomprod,&content[0].datos[i].stock,&content[0].datos[i].precio))!=EOF && i<F){
				i++;
			}
			content[0].datos[i].nomprod[0] = '\0';
			fclose(arch);
		}
		
		return res;
	}
		
		void imprimirTabla(t_contenido content[1]){
			printf("%s\t\t\t%s\t\t%s",content[0].titulo[0].prod,content[0].titulo[1].prod,content[0].titulo[2].prod);
			int i=0;
			while(content[0].datos[i].nomprod[0]!='\0'){
				printf("\n%25s\t%d \t%f",content[0].datos[i].nomprod,content[0].datos[i].stock,content[0].datos[i].precio);
				i++;
			}
		}
		
		void ordenarPorProd(t_contenido content[1]){
			t_dato aux;
			int i=0,j=1;
			while(i<F &&content[0].datos[i].nomprod[0]!='\0'){
				while(j<F && content[0].datos[i].nomprod[0]!='\0'){
					if(strcmp(content[0].datos[j].nomprod,content[0].datos[i].nomprod)>0){
						aux=content[0].datos[i];
						content[0].datos[i]=content[0].datos[j];
						content[0].datos[j]=aux;
					}
					j++;
				}
				i++;
				j=0;
			}
		}
		
		void imprimirTablaConFiltro(t_contenido content[1],int stinf,int stsup){
			// CODIFICAR AQUI
			
		}
		
		
		
