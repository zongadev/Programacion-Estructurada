
/** 03B.1-MemoriaDinamica */

/**
FUNCIONA TANTO PARA WINDOWS COMO PARA MAC
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** 03 Punteros */
int aleatorio(int inf, int sup){
	return inf + (rand() % (sup-inf+1));
}
	
char* cargarStrDin(){
	int i=0;
	char letra;
	char* arr=NULL;
	
	arr = (char *) malloc(sizeof(char)); //malloc(1)
	if (arr==NULL){return NULL;}
	
	//putchar(letra); // guarda todos caracteres para el getchar
	letra=getchar();       // letra = getche();
	while (letra!='\n')    //(letra!='\r')
	{
		*(arr+i)=letra;
		i++;
		arr=(char *) realloc(arr,(i+1)*sizeof(char));
		if (arr==NULL){return NULL;}
		letra=getchar();
	}
	arr[i]='\0'; // *(arr+i)='\0'
	printf("\n");
	return arr;
}

void CASO01(){
	
	printf("CASO 01\n");
	printf("Cargar un arreglo dinámico de caracteres desde el teclado\n");	
	
	printf("%s\n",cargarStrDin());	
}

void CASO02(){
	printf("CASO 02\n");
	printf("Cargar un arreglo dinámico de enteros\n");
	printf("Se fija un tamaño (len) y se pide memoria\n");
	printf("Se carga con valores aleatorios\n");
	
	
	int* arrID = NULL;
	int len = 10, i=0;
	arrID =(int*) malloc (sizeof(int) * len);// el * es una multiplicacion sizeof(int) * len
	 //                   4           * 10   (40) 
	// ciclo de carga
	for (i=0;i<len;i++){
		*(arrID+i)=aleatorio(10,100); // arrID[i]
	}
	printf("\n");
	// ciclo de impresion
	for (i=0;i<len;i++){
		printf("%d - ", *(arrID+i));		
	}			
}

void CASO03(){
	printf("CASO 03\n");
	printf("Cargar un arreglo dinámico de enteros\n");
	printf("hasta que en forma aleatoria se obtenga l número 0\n");
	printf("Se carga con valores aleatorios\n");
	printf("y se le coloca un elemento que indica el fin de datos util (que es el cero)\n");
	
	int* arrID = NULL;
	int sigue , i=0,tamMax=10;
	arrID =(int*) malloc (sizeof(int));
	                      //4
	
    
	*(arrID+i)=aleatorio(10,100);		
	sigue = aleatorio(0,10)!=0;
	while (sigue && i<tamMax-1){
		i++;
		arrID=(int *) realloc(arrID , (i+1)*sizeof(int));		
		*(arrID+i)=aleatorio(10,100);				
		sigue = aleatorio(0,10)!=0;			
	}
	*(arrID+i)=0;
	
	printf("\n");
	for (i=0;*(arrID+i)!=0;i++){
		printf("%d - ", *(arrID+i));	
	}	
	printf("\n Cantidad de elementos: %d",i);
	
}
	
int* memoDinA(int cant){	
	int* arrID =(int*) malloc (sizeof(int) * cant);
	return 	arrID;
}
	               //#132
void memoDinB(int** arrID , int cant){	
	 *arrID =(int*) malloc (sizeof(int) * cant); 
   //* #132
}
	 
void memoDinC_conCarga(int** arrID , int cant){	
	 (*arrID) =(int*) malloc (sizeof(int) * cant);
	 /** printf("\n ####   %p \n ", (*arrID));*/
	 //*((*arrID) + 0) = 999;  //(*arrID)[0] = 999;
	 //*((*arrID) + 1) = 888;
	 //*((*arrID) + 2) = 0;		
	 int i;
	 for (i=0;i<cant;i++){
		 *((*arrID) + i) = 0;//(*arrID)[i] = 0;
	 }
}
		 
		
void CASO04(){
	printf("CASO 04\n");
	int i; //&i -> #190
	//int* a = &i;
	int*  arrIDA = NULL;
	//int** aa=&arrIDA;
	int*  arrIDB = NULL; //&arrIDB -> #132 || *(&arrIDB )=10
	int*  arrIDC = NULL;
	
	printf("\n A.Pedido memoria por retorno ...(puntero)\n");
	arrIDA = memoDinA(3); //int* arrID =(int*) malloc (sizeof(int) * cant);	
	*(arrIDA + 0) = 10; //arrIDA[0] = 10;
	*(arrIDA + 1) = 20; //arrIDA[1] = 20;
	*(arrIDA + 2) = 0;	//arrIDA[2] = 0;	
	for (i=0;*(arrIDA+i)!=0;i++){
		printf("%d - ", *(arrIDA+i));	
	}	
	
	printf("\nB. Pedido memoria por parametro ...(puntero de puntero)\n");
	memoDinB(&arrIDB,3);	
	*(arrIDB + 0) = 100;
	*(arrIDB + 1) = 200;
	*(arrIDB + 2) = 0;	
	for (i=0;*(arrIDB+i)!=0;i++){
		printf("%d - ", *(arrIDB+i));	
	}	
	
	printf("\n C. Pedido memoria por parametro ...(puntero de puntero)\n");
	printf("Y carga el arreglo en la función\n");
	memoDinC_conCarga(&arrIDC,3);
	/**
	*(arrIDC + 0) = 777;
	*(arrIDC + 1) = 666;
	*(arrIDC + 2) = 0;	
	*/
	/** printf("\n ****   %p \n ", arrIDC);*/
	for (i=0;*(arrIDC+i)!=0;i++){
		printf("%d - ", *(arrIDC+i));	
	}	
	
	
}
		
int main()
{
	srand(time(NULL));

	//CASO01();
	//printf("\n------------------------------------------------\n");
	//CASO02();
	//printf("\n------------------------------------------------\n");
	//CASO03();
	printf("\n------------------------------------------------\n");
	
	CASO04();
	
	
	
	return 0;
}
