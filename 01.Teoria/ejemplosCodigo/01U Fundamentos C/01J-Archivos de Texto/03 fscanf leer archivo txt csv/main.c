/**
03 fscanf leer archivo txt csv
*/

#include <stdio.h>
#include <stdlib.h>
/**
    Prototipo de la funci�n fscanf:
        int fscanf(FILE *stream, const char *format, set de variables....)

    FILE*: Es el archivo a leer
    *format: es el patr�n de formato de lectura (eg. "%d,%d,%d\n")
    set de variables: son las variables donde se guardar� los datos leidos

   Comentarios:
        fscanf retona la cantidad de elementos leidos. " %d es un elemento "
        fscanf retona -1 cuando encuentra el fin del archivo
        La constante EOF (End Of File) es -1

   \brief Lectura de un archivo csv que contiene tres numeros enteros
           separados por coma, por cada linea del archivo.

marianotrigila@gmail.com
*/
int main()
{
    int a,b,c;                                  /** variables donde se guarda lo leido por fscanf*/
    int r;                                      /** en r guardo lo que retorna fscanf*/

    FILE* arch;                                 /** Declaro la variable arch com tipo de dato FILE*  */
    arch=fopen("arch2.txt","r");                 /** Abrir el archivo "arch.txt" de lectura. En arch queda el puntero que refrerenci al archivo*/

    if(arch==NULL)                              /** Si el arch contiene NULL es porque el archivo no pudo ser abierto*/
        return -1;                              /** Termina el programa */

    r=fscanf(arch,"%d,%d,%d\n",&a,&b,&c);       /** LEER archivo. (antes del while) */
    while(r!=EOF)                               /** Mientras no sea fin de archivo*/
    {
        //printf("%d:%d%d,%d\n",r,a,b,c);   /** Imprimir en pantalla las variables que contienen la informaci�n leida del archivo*/
		printf("%5d%5d%5d\n",a,b,c);
        r=fscanf(arch,"%d,%d,%d\n",&a,&b,&c);   /** LEER archivo. (al final del while)  */
    }
    //printf("EOF= %d\n",r);
    //printf("EOF= %d\n",EOF);                    /** La constante EOF es -1 */
    fclose(arch);                               /** cerrar el archivo arch" */
    return 0;
}
