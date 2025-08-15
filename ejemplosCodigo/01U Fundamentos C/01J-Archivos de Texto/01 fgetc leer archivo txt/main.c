/**
01 fgetc leer archivo txt
*/

#include <stdio.h>
#include <stdlib.h>
/**
    Prototipo de la funci�n fgetc:
        int fgetc(FILE *stream)

        FILE*: Es el archivo a leer

    Comentarios:
        fgetc lee de a 1 (un) caracter
        fgetc retona el caracter leido del archivo
        fgetc retona -1 cuando encuentra el fin del archivo
        La constante EOF (End Of File) es -1

    link ejemplo: https://www.tutorialspoint.com/c_standard_library/c_function_fgetc.htm

    \brief Lectura de un archivo txt (caracter a caracter) que contiene nombres
           (simples o compuestos) uno por cada linea del archivo.

marianotrigila@gmail.com
*/

int main()
{
    int  c=0;                       /** variable donde se guarda lo leido por fgetc*/
	int res = 0;

    FILE* arch;                     /** Declaro la variable arch como tipo de dato FILE*  */
    arch=fopen("arch.txt","r");     /** Abrir el archivo "arch.txt" de lectura. En arch queda el puntero que refrerencia al archivo*/

    if(arch!=NULL){                  /** Si el arch contiene NULL es porque el archivo no pudo ser abierto*/

		c=fgetc(arch);                  /** LEER archivo. - (antes del while) */
		while (c!= EOF)                 /** Mientras no sea fin de archivo*/
		{
			printf("%c", c);            /** Proceso - Imprimir en pantalla la variables que contiene la informacion leida del archivo */
			c=fgetc(arch);              /** LEER archivo. - (al final del while)  */
		}

		printf("EOF= %d\n",c);
		printf("EOF= %d\n",EOF);        /** La constante EOF es -1 */
		fclose(arch);                   /** cerrar el archivo arch" */
    }else{
		res =  -1;                      /** Termina el programa con un error -1*/
	}
    return res;
}
