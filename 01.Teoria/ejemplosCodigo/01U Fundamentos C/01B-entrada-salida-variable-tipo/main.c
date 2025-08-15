// 01B-entrada-salida-variable-tipo

#include <stdio.h>                  /** Librer�a: https://es.wikipedia.org/wiki/Stdio.h */
#include <stdlib.h>                 /** Librer�a: https://es.wikipedia.org/wiki/Stdlib.h */
//#include <conio.h>          // para mac  o linux eliminar esta linea


int main()                         
{          
	// definicion SIN inicializaci�n 
	int num;                      /** definci�n variable tipo entera*/
	float real;                   /** definci�n variable tipo real "float"*/
	double real2;                 /** definci�n variable tipo real "double"*/
	// definicion CON inicializaci�n 
	//int diasLaborables = 0;       /** definci�n variable tipo entero "int"*/
	char caracter =' ';           /** definci�n variable tipo caracter "char"*/
	char msj[10] = "hola";        /** arreglo de caracteres ...AMPLIAREMOS LA INFO*/
	                              /** OJO msj[10] una vez definida no se pude asignar con el igual*/
	//asignaci�n
	num = 10;
	real = 3.1418;
	real2 = 1234.231418;
	//diasLaborables = 22;
	caracter = 'x';
	
	printf("\n---------------------------------------\n");
	printf("Cadena: %s, caracter: %c, entero: %d, flotante: %4.2lf ",
		   msj,caracter, num,real2);
	printf("\n---------------------------------------\n");
	
	printf("\n Ingresar valor entero: ");       
	scanf("%d",&num);  // equiv python -> num=input()
	//printf("entero: %d", num);
	
	printf("\n Ingresar valor Real: ");       
	scanf("%f",&real); 
	//printf("Real: %f", real);
	
	//LIMPIEZA DE BUfFER DE ENTRADA. (VER NOTA_01 ABAJO).
	//fflush(stdin);                                          // S�lo windows
	while((caracter = getchar()) != '\n' && caracter != EOF); // muliplataforma
	printf("\n Ingresar valor Caracter: "); 
	caracter = getchar();              //getche(); 
	
	/**
	*******************************
	Soluci�n MAC y Linux para reemplazar a getche
	Colocar fflush(stdin); antes del getchar para limpiar buffer de entrada
	
	*/
	
	/**
	La carga de una cadena de caracteres queda pendiente
	para cuando sepamos ciclos
	*/	
	
	printf("\n---------------------------------------\n");
	printf("caracter: %c, entero: %d, flotante: %4.2f ",caracter, num,real);
	printf("\n---------------------------------------\n");
	

    return 0;                       
}                                  

/**
******************************** NOTA_01 *******************************
Previamente a la lectura de "caracteres" desde teclado hay que LIMPIAR el
BUFFER de ENTRADA, es decir el archivo donde se almacena los datos de ENTRADA que
son ingresados desde el teclado. Si esto no se hace, entonces falla la lectura.

(1)Se propone una soluci�n multiplataforma, es decir funciona en Windows, linux y 
mac. (preferentemente usar esta soluci�n).

(2)Se propone una soluci�n s�lo para windows.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
(1) Soluci�n multiplataforma: para Windows, Linux y Mac, para LIMPIAR 
BUFFER de ENTRADA:
Se debe colocar la siguiente l�nea de c�digo antes de ejecutar un lectura 
de entrada de caracteres con 'getchar()':

while((caracter = getchar()) != '\n' && caracter != EOF);

Aclaraci�n: 'caracter' es una variable que almacena el caracter le�do 
del BUFFER. Debe ser creada por el programador.
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
(2) Soluci�n s�lo para Windows: para LIMPIAR BUFFER de ENTRADA:
Se debe colocar la siguiente l�nea de c�digo antes de ejecutar un lectura 
de entrada de caracteres con 'getchar()':

fflush(stdin); 

'stdin' es el nombre con el cual C conoce al archivo de ENTRADA estandar.

*************************** F I N   NOTA_01 *******************************
*/



// casteo -> transformar de un tipo a otro
/*
int a;
double b;
a = 3;
b = (double)a;
*/
