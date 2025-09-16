#include <stdio.h>
#include<string.h>
#include <math.h>
#define C 11
#define TERM -999
typedef struct punto{
	int x;
	int y;
} punto;

void cargarMatriz(punto mat[C], char archivo[]){
	int i=0,pyaux,pxaux;
	FILE* file = fopen(archivo,"r");
	int r= (int) fscanf(file,"%d,%d",&pxaux,&pyaux);
	while(r!=EOF && i<C){
		mat[i].x=pxaux;
		mat[i].y=pyaux;
		r= (int) fscanf(file,"%d,%d",&pxaux,&pyaux);
		i++;
	}
	mat[i].x=TERM;
}

float distanciaMinima(punto pa, punto pb){
	return ( sqrt( pow((pa.x-pb.x),2)+ pow((pa.y-pb.y),2) ) );
}

void DMConsecutivos(punto mat[C]){
	int i =0, j=1;
	while(mat[j].x != TERM){
		printf("\n Distancia minima entre los puntos (%d,%d) y (%d,%d) es: %f"
			   ,mat[i].x,mat[i].y,mat[j].x,mat[j].y,distanciaMinima(mat[i],mat[j]));
		i++;
		j++;
	}
}
	
void DMCualesquieras(punto mat[C]){
	punto paux;
	float aux=0;
	int i =0, j=1;
	float dist=distanciaMinima(mat[i],mat[j]);
	aux = dist;
	while(mat[i].x != TERM){
		while(mat[j].x != TERM){
			if(i!=j && aux>dist){
				paux=mat[j];
				aux=dist;
			}
			j++;
			dist=distanciaMinima(mat[i],mat[j]);
		}
		printf("\n La distancia minima para el punto (%d,%d) es el punto: (%d,%d)",mat[i].x,mat[i].y,paux.x,paux.y);
		j=0;
		i++;
		dist=distanciaMinima(mat[i],mat[j]);
		aux = dist;
	}
}

int main(){
	punto matI[C];
	cargarMatriz(matI,"puntos.csv");
	DMConsecutivos(matI);
	printf("\n------------------------\n");
	DMCualesquieras(matI);
	return 0;
}
