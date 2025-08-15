/**
05 fprintf escribir archivo txt csv
*/

#include <stdio.h>
#include <stdlib.h>
/**

  \brief Lectura de un archivo csv que contiene campos con nombres
      (simples o compuestos) mexclados con numeros por cada linea del archivo.
   formato: "%d,%S,%d,%lf\n"

    En este caso se utiliza ciclo "for" para recorrer el archivo
    y la funci�n feof() que retorna si es el fin del archivo pasado por par�metro.

   marianotrigila@gmail.com

*/
void cargarArchivo(char* );
void imprimirArchivo(char* );

int main()
{
    //char *cadena="arch.txt"; //MALMAL "NO USAR TENGO" 29/4/2021 (Mariano)
	char cadena[20]={"arch.txt"};
    cargarArchivo(cadena);
    imprimirArchivo(cadena);
    return 0;
}

void cargarArchivo(char* cadena)
{
    FILE *arch;

    arch=fopen(cadena, "w");

    fprintf(arch ,"%d,%s,%d\n", 1,"Jose", 123);
    fprintf(arch ,"%d,%s,%d\n", 2,"Roberto", 456);
    fprintf(arch ,"%d,%s,%d\n", 3,"Fernando", 789);

    fclose(arch);
}

void imprimirArchivo(char *cadena)
{
    FILE *arch;
    int num, i=0;
    char nombre[30], caracter;
    int sueldo;

    arch=fopen(cadena, "r");

    if (arch!=NULL) /** Si arch es null, etonces no pudo abrirse el archivo */
    {
        while (!feof(arch)) /** mientras no se termine el archvio*/
        {
            num=0;
            sueldo=0;
            /*-------------------------------------------------------------------------------------------*/
            /*parte 1*/
            fscanf(arch, "%d,", &num);

             /*-------------------------------------------------------------------------------------------*/

             /*-------------------------------------------------------------------------------------------*/
            /*parte 2*/ /** �Tambi�n se podr�a hacer con un while!*/
            i=0;
            for (caracter=fgetc(arch); caracter!=',' && !feof(arch);caracter=fgetc(arch))
            {
                nombre[i]=caracter;
                i++;
            }
            nombre[i]='\0';
            /*-------------------------------------------------------------------------------------------*/

            /*-------------------------------------------------------------------------------------------*/
            /*parte 3*/
            if (!feof(arch))
                fscanf(arch, "%d\n", &sueldo);
            /*-------------------------------------------------------------------------------------------*/

            printf("Valores Leidos: %d,%s,%d\n", num, nombre, sueldo);
        }
        fclose(arch);
    }
}
