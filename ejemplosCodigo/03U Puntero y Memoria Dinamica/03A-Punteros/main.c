#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/** 03A-Punteros */

/**

*/

void CASO01(){
	printf("CASO 01\n");
	int i;
	printf("Ejemplo Punteros_01 de la hoja de calculo \n");
	// https://docs.google.com/spreadsheets/d/1HwOD_lkcWdPO4Cf3FQVFDbs0E-yc8DdrPEOwVGMgtkA/edit#gid=0
	char car = 'A';
		
	int num2 = 0;
	int num1 = 20;
	
	printf("\n car   = %4c\n",car);
	printf("&car   = %4p\n",&car);
	printf(" num1  = %4d\n",num1);
	printf("&num1  = %4p\n",&num1);
	printf("\n");
	
}

void CASO02(){	
	printf("CASO 02\n");
	printf("Ejemplo Punteros_02 de la hoja de calculo \n");
	
	char car = 'A';
	char* pCar = NULL;
	
	printf("\n car   = %4c\n",car);
	printf("&car   = %4p\n",&car);
	pCar =  &car;
	printf("pCar    = %4p\n",pCar);
	printf("*pCar   = %4c\n",*pCar);
	printf("\n");
}
	
void CASO04(){
	
	printf("CASO 04\n");
	printf("Los arreglos y los punteros\n");	
	printf("Hoja de planilla de cálculo Punteros_04(*) \n");	

	int arrI[4]={10,22,13,40};	
	int i;
	
	printf("dirección de memoria del arreglo %p\n",arrI);

	i=0;
	
	printf("1) %p\n",arrI);
	printf("2) %p\n",&(arrI[0]));
	printf("3) %p\n", arrI+ 0);
	printf("\n");
	
	printf("4) %d\n",&(arrI[1]));
	printf("5) %d\n", arrI+ 1);
	printf("\n");
	
	printf("%p | %d  \n", &(arrI[2]) ,  arrI[2] );
	printf("%p | %d  \n", arrI+ 2   ,   *(arrI+2) );
	
	
	/**
	printf("\nElemento arrI[%d]  -> %d  (acceso por indice)\n",i,arrI[i]);
	printf("Elemento *(arrI+i)  -> %d  (acceso por puntero)\n",i,*(arrI+i));
	printf("Dir. Mem. (arrI+i) -> %p\n",i,(arrI+i)); // arrI
	
	i=1;
	printf("\nElemento arrI[%d]  -> %d  (acceso por indice)\n",i,arrI[i]);
	printf("Elemento arrI[%d]  -> %d  (acceso por puntero)\n",i,*(arrI+i));
	printf("Dir. Mem. arrI[%d] -> %p\n",i,(arrI+i)); // arrI + 1
	
	i=2;
	printf("\nElemento arrI[%d]  -> %d  (acceso por indice)\n",i,arrI[i]);
	printf("Elemento arrI[%d]  -> %d  (acceso por puntero)\n",i,*(arrI+i));
	printf("Dir. Mem. arrI[%d] -> %p\n",i,(arrI+i)); // arrI + 2
	*/
}
	
void cargarArrC(char arrC[]){
strcpy(arrC,"chau" );
}
void cargarArrC2(char* arrC){
	strcpy(arrC,"Buenas" );
}
void CASO05(){
	
	printf("CASO 05\n");
	printf("Los arreglos y los punteros, copia\n");
	char arr_02[30];
	cargarArrC(arr_02);
	printf("%s\n",arr_02);
	cargarArrC2(arr_02);
	printf("%s\n",arr_02);
	
}


			//20     30       #123
void sumar(int a, int b, int* total){
	*total = a+b;
   //*(#123)       = 20+30
	
}
	
void CASO03(){
	int num;
	printf("CASO 03\n");
	printf("Los arreglos y los punteros\n");
	printf("Hoja de planilla de cálculo Punteros_03(*) \n");
	
	char msj[8]="hola";	
	char* pMsj = msj;
	
	printf("msj -> %p\n",msj);
	//printf("&msj -> %p\n",&msj);   // ****** VER LUEGO
	printf("pMsj -> %p\n",pMsj);
	
	
	
	
}

int main(){		
	CASO01();
	CASO02();
	CASO04();
	CASO03();
	CASO05();

	// falta pasar este ejemplo a un caso por separado.
	/**
	char arrCori[30];
	char* arrC = arrCori;
	
	strcpy(arrC,"hola" );
	printf("%s\n",arrC);
	
	cargarArrC(arrC);
	printf("%s\n",arrC);
	
	cargarArrC2(arrC); 
	printf("%s\n",arrC);
	
	int suma;   //#123
	sumar(20,30,&suma);		
	printf("la suma es: %d",suma);
	*/
	
				
	return 0;		
}	
		
		
			
/*void* pTodo;*/
/*char car = '@';*/
/*char* pCar;*/
/*char *pAux;*/
/*int num1, num2=0;*/
/*num1 = 20;*/
/*printf("\n car    = %4c\n",car);*/
/*printf("@car    = %4p\n",&car);*/
/*pCar =  &car;*/
/*pTodo =  &car;*/
/*printf("pCar    = %4p\n",pCar);*/
/*printf("*pCar   = %4c\n",*pCar);*/
/*pAux = pTodo;*/
/*printf("*pCar   = %4c\n",*pAux);*/
/*printf("*pCar   = %4c\n",*((char*)pTodo));*/


//printf(" num1  = %4d\n",num1);
//printf("@num1  = %4p\n",&num1);
// printf(" num2  = %4d\n",num2);




/*
int main()
{
char msj[8]="hola";
char* pMsj;

printf("\n%s\n",msj);
printf("@msj    = %4p\n",msj);
pMsj = msj;
printf("pMsj    = %4p\n",pMsj);
printf("\n");
printf("[0][1]    = %c%c\n", msj[0],msj[1] );
printf("[0][1]    = %c%c\n", *(pMsj+0),*(pMsj+1));
printf("[0][1]    = %c%c\n", *(msj+0),*(msj+1) );
printf("\n@[0][1]    = %u | %u\n", (msj+0),(msj+1) );


return 0;
}
*/
