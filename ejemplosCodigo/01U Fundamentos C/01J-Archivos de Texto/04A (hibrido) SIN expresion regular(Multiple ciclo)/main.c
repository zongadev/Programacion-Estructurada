/**
04 (hibrido) fgetc y fscanf leer archivo csv con formatos variados
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**

  \brief Lectura de un archivo csv que contiene campos con nombres (simples o compuestos)
         mexclados con numeros por cada linea del archivo.
   formato: "%d,%S,%d,%lf\n"

   Estrategia de lectura: Dado que no se puede leer correctamente el patron de formato "%d,%S,%d,%lf\n"
   con fscanf, entoces se deber� leer cada linea del archivo en partes, los n�meros por un lado y
   los caracteres por otro. Para este caso especificamente en tres partes.

   PRIMERA: Con fscanf leer con formato "%d,"
   SEGUNDA: con fgetc leer (dentro de un while)los caracteres hasta encontrar una coma
   TERCERA: con fscanf leer con formato "%d,lf\n"

   Nota: la cantidad de partes a dividir la lectura, depender� de como est�n
   distribuidos los datos entre las comas.

marianotrigila@gmail.com
*/

int main()
{
    char c;                             /** variable donde se guarda lo leido por fgetc*/
    int r;                              /** en r guardo lo que retorna fscanf*/
    int i;                              /** variable que se utilizar� como indice del arreglo nom */

    int cod;                            /** variable entera que representa el primer elemento del archivo  */
    char nom[30];                       /** variable arreglo que representa el segundo elemento del archivo   */
    int obj;                            /** variable entera que representa el tercer elemento del archivo   */
    double sAnu;                        /** variable double que representa el cuarto elemento del archivo   */

    FILE* arch;                         /** Declaro la variable arch com tipo de dato FILE*  */
    arch=fopen("arch3.txt","r");         /** Abrir el archivo "arch.txt" de lectura. En arch queda el puntero que refrerencia al archivo*/

    if(arch==NULL)                      /** Si el arch contiene NULL es porque el archivo no pudo ser abierto*/
        return -1;                      /** Termina el programa */
/** PRIMERA */
    r=fscanf(arch,"%d,",&cod);          /** (1�)LEER archivo. (antes del 1� while) */
	
    while(r!=EOF)                       /** (1� while) Mientras no sea fin de archivo*/
    {
        i=0;                            /** inicializar el indice que se utilizara para el arreglo nom*/
/** SEGUNDA */
        c=fgetc(arch);                  /** (2�) LEER archivo. (antes del 2� while) */
        while(c!= EOF && c!=',')        /** (2� while) Mientras no sea fin de archivo y c no sea un coma*/
        {
            nom[i]=c;                   /** guardar c en el arreglo nom, en la correspondiente posici�n i*/
            i++;                        /** incrementar el indice del arreglo */
            c=fgetc(arch);              /** (2�) LEER archivo. (al final del 2� while)  */
        }
        nom[i]='\0';                    /** colocar un '\0' al final del arreglo */
/** TERCERA */
        r=fscanf(arch,"%d,%lf\n",&obj,&sAnu);           /** LEER archivo, la parte del registro que falta */
        //printf("%d,%s,%d,%6.2lf\n",cod,nom,obj,sAnu);   /** IMPRIMIR el contenido de las variables quevrepresentan el contenido del registro del archivo*/
		printf("%6d%12s%8d%8.2lf\n",cod,nom,obj,sAnu);   /** IMPRIMIR el contenido de las variables quevrepresentan el contenido del registro del archivo*/
		
/** PRIMERA */
        r=fscanf(arch,"%d,",&cod);      /** (1�) LEER archivo. (al final del 1� while)  */
    }

    fclose(arch);                   /** cerrar el archivo arch" */
	printf("%d",strcmp("Bsta","aleta"));
    return 0;
}
