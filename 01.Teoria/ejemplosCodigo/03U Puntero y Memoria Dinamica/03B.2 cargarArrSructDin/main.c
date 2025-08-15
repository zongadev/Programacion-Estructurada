#include <stdio.h>
#include <stdlib.h>


/**

Carga un arreglo din�mico de estructura struct s_txt
dentro de la estructura se encuentra un arreglo din�mico de char

marianotrigila@gmail.com
*/

struct s_txt{               /** Estructura */
    char* txt;
    int lon;
};
typedef struct s_txt t_txt; /** Alias */

char* cargarStrDin(){       /** Carga un arreglo dinamico de char (string) y retorna la direccion*/
    int i=0;
    char letra;
    char* arr=NULL;                             /** lo inicalizo en null*/

	letra = getchar();
    if (letra!='\n'){
        arr = (char *) malloc(sizeof(char));    /** Asignar memoria Puntero a char: es un arreglo din�mico de punteros a char*/
        if (arr==NULL){return NULL;}            /** Sale de la funcion si no tiene memoria*/

        while (letra!='\n')                     /** mientras no sea un ENTER ('\n') el valor ingresado desde el teclado*/
        {
            *(arr+i)=letra;                     /** asignar la letra (caracter) ingresada a una posicion del arreglo*/
            i++;                                /** incrementar variable de desplazamiento de direcion */
            arr=(char *) realloc(arr,(i+1)*sizeof(char)); /** Ampliar memoria*/
            if (arr==NULL){return NULL;}
				letra = getchar();
        }
        arr[i]='\0';                            /** Asignar '\0' determina el fin de un string */
    }

    return arr;                                 /** retorna la direccion de */

}

char* cargarStrDin2(char** arr){       /** Carga un arreglo dinamico de char (string) y retorna la direccion*/
    int i=0;
    char letra;
    *(arr) = NULL;                                 /** lo inicalizo en null*/
	
	letra = getchar();
    if (letra!='\n'){
        *(arr) = (char *) malloc(sizeof(char));    /** Asignar memoria Puntero a char: es un arreglo din�mico de punteros a char*/
        if (*(arr)==NULL){return NULL;}            /** Sale de la funcion si no tiene memoria*/

        while (letra!='\n')                        /** mientras no sea un ENTER ('\r') el valor ingresado desde el teclado*/
        {
            *((*(arr))+i)=letra;                   /** asignar la letra (caracter) ingresada a una posicion del arreglo*/
            //(*arr)[i]=letra;                      /**expresion equivalente a la anterior*/

            i++;                                   /** incrementar variable de desplazamiento de direcion */
            *(arr)=(char *) realloc(*(arr),(i+1)*sizeof(char)); /** Ampliar memoria*/
            if (*(arr)==NULL){return NULL;}
				letra = getchar();
        }
        *((*(arr))+i)='\0';                        /** Asignar '\0' determina el fin de un string */
        //(*arr)[i]='\0';                          /** expresi�n equivalente a la anterior*/
    }

	return (char*)0;
}


void imprimirTextDin(t_txt* text){  /** imprime un arreglo dinamico de text*/
    int i=0;
    if((text)!=NULL&&(text+i)->txt!=NULL){
        printf("text       text+i\ti\tlon\ttxt\n");
        printf("------------------------------------------------------\n");
        while((text+i)->txt!=NULL){//(((text+i)->txt)[0]!='\0'){
            printf("<%p> <%p>\t%d\t%d\t%s\n",(void*)text,(void*)(text+i),i,(text+i)->lon,(text+i)->txt);
            i++;
        }
    }
}

t_txt cargarUnText(){       /** Carga una estructura del tip t_txt*/

    int pos=0;
    t_txt text;                                 /**  */

    /**VER las dos formas de cargar el arreglo de caracterres, retornando el puntero,
    o pasandole el doble puntero. Mantener comentada siempre una para probar.*/
    /**  - - - - - - - - - - - - - - - - - - - */
    //text.txt=cargarStrDin();                  /** Cargar un string din�mico con retorno */
    cargarStrDin2(&(text.txt));                 /** Cargar un string din�mico con puntero de puntero */
    /**  - - - - - - - - - - - - - - - - - - - */

    for(pos=0;text.txt!=NULL&&*((text.txt)+pos)!='\0';pos++);   /** determinar el tama�o del string cargado */
    if (text.txt!=NULL){
        pos++;                                  /** incrementa para contar al '\0'*/
    }
    text.lon=pos;                               /** asignar el tama�o */
    return text;                                /** retornar la estructura cargada */
}

t_txt* cargarTextDin(){     /** Carga un arreglo dinamico de text y retorna la direccion*/
    int i=0;
    
    t_txt* text=NULL;
    t_txt auxText;
    auxText=cargarUnText();                         /** cargar una estructura text  - */

    text=(t_txt*)malloc(sizeof(struct s_txt));      /** Asignar memoria Puntero a text: es un arreglo din�mico de punteros a text*/
    if (text==NULL){return NULL;}

    while(auxText.txt!=NULL){                       /** Mientras no sea nula txt (esto sucede cuando no se cargo dato, solo un enter)*/
        *(text+i)=auxText;                          /** asigna el el valor de la estructura en laposicon i del arreglo*/
        i++;                                        /** incrementar variable de desplazamiento de direcion */
        text=(t_txt*)realloc(text,sizeof(struct s_txt)*(i+1));  /** Ampliar memoria */
        if (text==NULL){return NULL;}

        auxText=cargarUnText();                     /** cargar una estructura text  - */
    }
    *(text+i)=auxText;                              /** asigna el el valor de la estructura en laposicon i del arreglo*/
    return text;
}

void cargarTextDinPP(t_txt** text){ /** Carga un arreglo dinamico de text pasandole doble puntero*/

    *text=cargarTextDin();
}

int main()
{  /**VER las dos formas de cargar el arreglo, retornando el puntero,
    o pasandole el doble puntero. Mantener comentada siempre una para probar.*/
    t_txt* text=NULL;
    //text=cargarTextDin();  // retorna puntero (direccion con estructura cargada)
	
    cargarTextDinPP(&text);  // se pasa la direccion del puntero (doble puntero)
    imprimirTextDin(text);

    return 0;
}
