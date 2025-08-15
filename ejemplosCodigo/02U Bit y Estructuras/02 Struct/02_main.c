#include <stdio.h>
#include <stdlib.h>
 
 
#include <string.h>      // strcpy strcmp strlen
#include <math.h>        // pow sqrt

/** 02 Struct  BIS ... en clase*/

/***Definicion de un struct****************/

struct s_punto{// 28 bytes
	int x;           // 4 bytes
	int y;           // 4 bytes
	char nom[20];    //20 bytes (porque cada char es un byte y como hay 20 char => tiene 20 byte)
};
typedef struct s_punto t_punto;


//double distancia(int x1,int y1,int x2,int y2);
double distancia(t_punto p1,t_punto p2);

int main()
{
	t_punto punto1;
	t_punto punto2;
	
	double distancia12;
	int x1,y1,x2,y2;
	printf("\n\n");	
	//cargar el valor de coordenada del punto y su nombre
	punto1.x=10;     //x1=10;
	punto1.y=20;     //y1=20;
	strcpy(punto1.nom ,"Chacarita");
    
	punto2.x=100;    // x2=100;
	punto2.y=200;    // y2=200;
	strcpy(punto2.nom ,"Flores");
	
	printf("%s -> x1=%4d | y1=%4d \n",punto1.nom,punto1.x,punto1.y );
	printf("%s -> x2=%4d | y2=%4d \n",punto2.nom,punto2.x,punto2.y );
	
	distancia12 = distancia(punto1,punto2);
	printf("Distancia 1 a 2 -> %6.2lf \n",distancia12 );
	printf("\n\n");
    return 0;
}

double distancia(t_punto p1,t_punto p2){	
	 
	double res=0;
	// obtengo la distancia
	int x, y;
	x=p1.x-p2.x;
	y=p1.y-p2.y;	
	res = sqrt(pow(x,2) + pow(y,2));
	 
	return res;
}
