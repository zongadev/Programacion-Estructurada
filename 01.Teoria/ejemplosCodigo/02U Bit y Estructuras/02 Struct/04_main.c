#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 02 Struct */

/**
Aclaración : Se utiliza strcpy, que es una función que se encuentra
dentro de la librería <string.h>.
strcpy: Copia el contenido de una variable arreglo de char (string) en
otra variable arreglo de char (string).



*/
/***Definicion de un struct****************/
struct s_fecha{
	int dd,mm,aa;
};
typedef struct s_fecha t_fecha; /** Aleas*/

struct s_punto{
	int x;
	int y;
	char nom[20];
	t_fecha fecha;

};
typedef struct s_punto t_punto; /** Aleas*/
/*****************************************/

struct s_coord{
	int x,y,z;	
};
typedef struct s_coord  t_coord; 
//typedef juan   ignacio  juani 
int main()
{
	t_punto p;
	
	t_punto p1,p2;
	//double b;
	char c;
	t_coord puntoEspeacio,hw;
	
	hw.x=10;
	hw.y=12;
	hw.z=-1;
	
	
	
	
	
	
    t_punto a,b; /** definir dos variables del tipo t_punto*/
    a.x=10;      /** Asignar un valor a un elemento de un struct*/
    a.y=12;

			
    strcpy(a.nom,"pico truncado"); /***/

    printf("-Stuct 'a' cargado previamente-\n");
    printf("---------------------------------------\n");
    printf("a.x=%d , a.y=%d, nom= %s\n",a.x,a.y, a.nom);

    b.y=a.x;  /** Asignacion de una parte de struct */

    printf("\n-Stuct 'b' con elementos NO cargadoS-\n");
    printf("Observar que tiene contenido 'basura'--\n");
    printf("---------------------------------------\n");
    printf("b.x=%d , b.y=%d, nom= %s\n\n",b.x,b.y, b.nom);

	
    b=a;      /** Asignacion de un struct COMPLETO */
    // printf("a.x=%d , a.y=%d\n",a.x,a.y);
    printf("\n-stuct 'b' cargado con el contenido de 'a' -\n");
    printf("---------------------------------------\n");
    printf("b.x=%d , b.y=%d, nom= %s\n\n",b.x,b.y, b.nom);

    /**######################################################*/

    t_punto arr[4]; /** definir un arreglo de 4 elemnto del tipo t_punto*/

    arr[0].x=10;
    arr[0].y=12;
    strcpy(arr[0].nom,"Primero");

    arr[1].x=1;
    arr[1].y=12;
    strcpy(arr[1].nom,"Segundo");


    arr[2].x=100;
    arr[2].y=16;
    strcpy(arr[2].nom,"Tercero");
	
	//printf("%c",arr[2].nom[2]);

    arr[3].x=0;
    arr[3].y=0;
    strcpy(arr[2].nom,"\0");

    printf("--Arreglo de t_punto");

    int i;

    for(i=0;i<4;i++){
        printf("--Arreglo de t_punto");
        /**Falta imprimir el erreglo*/

    }
	
	unsigned char x =1000;
	printf("\n***  %d   **\n",x);
	
    return 0;
}
