# C para petesss



#### Lista de cosas que no se tendrian que olvidar:



1-Scanf de int con \&

2-char con getchar o fgetc en archivo

3-definir constantes arriba con el terminador Tambien (seguro mariano ya da la estrctura igual con esto incluido ya)

4-Cuando cargas un string por teclado (con while y getchar) acordarse de 

&nbsp; cerrar el string con '\\0', lo mismo al cargar matrices de char en cada fila

5-La distancia entre las mayusculas y minusculas es de 32. Las mayusuculas estan antes (son mas chicas) que las minusculas.

6-w para escribir sobreescribir archivos, a para agregar al final

7-El strcmpr y el strcpy es lo mismo que: parametron 1 \*operador\* parametron 2, no le erres pajin.

8-El strcmpr es como una resta, si el primero es mas chico que el segundo, entonces da negativo. Igual chequeenlo ejecutando y viendo que les da.

9-Los structs vienen definidos por mariano, el nombre que tenes que usar para crear una variable struct es el ultimo que aparece:

typedef struct fulano fulano2. (Seria fulano2)

10-Cuando leen un archivo, tengan cuidado con usar todo fscanf de una, a veces te lee una linea de mas, siempre chequeen que el ultimo que se agrega sea realmente el ultimo.

11-(Lo siguiente es si el archivo tiene mezcla de string y int)

Lo que tiene que tener de condicion el ciclo del while es lo primero que aparece en el archivo, esto tambien es, lo ultimo que tenes que tomar al final del while para que lo siguiente que haga es chequear si eso es EOF o no. 

Siempre tenes que agarrar la primera linea del archivo fuera del while, no importa por cuantas partes lo hagas. Para mi, lo mas comodo y seguro es separar el primer valor de los otros, para poder hacer lo que dice el parrafo de arriba, chequear bien el EOF.

12- cierren el archivo

13- pongan el if(arch!=NULL)

14- Uno pasa por parametros VALORES, por eso mismo si uno quiere modificar una lista enlazada, no puede pasar el puntero al primer elemento, pq lo estas pasando como una COPIA. Tenes que pasar un puntero a el puntero del primer elemento, asi, el puntero, que esta un nivel mas adentro, no es una copia y puede ser modificado


