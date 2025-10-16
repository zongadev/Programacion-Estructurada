#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * cargarStrDin1(){
	int i=0;
	char c;
	char* arr = NULL;
	arr= (char *) malloc(sizeof(char));
	if(arr==NULL) return NULL;
	c = getchar();
	while(c!='\n'){
		*(arr+i) = c;
		i++;
		arr=(char *) realloc(arr,(i+1)*sizeof(char));
		if(arr==NULL) return NULL;
		c=getchar();
	}
	arr[i]='\0';
	return arr;
}
	
void cargarStrDin2(char** pp){
	/*   
	Un string es una secuencia de chars.
	El valor de un caracter dentro de un string es *char (puntero al caracter)
	Aca PP que es un puntero a puntero, es pq apunta a un *char,es decir, al primer caracter.
	Esto es pq el string lo lee hasta encontar un \0 asi que no importa, con tener el 
	primero alcanza. Normalmente un string es un puntero al primer caracter (como lo es PP).
	
	*PP es *char , es decir, el string (pq es el primero y busca hasta el final)
	(*p)[i] es char el i esimo char del string al que apunta *p
	
	
	
	pp contiene char **. Puntero al primer puntero de los */
	int i =0;
	char c;
	*pp= (char *) malloc (sizeof(char));
	if(*pp == NULL) return ;
	c=getchar();
	while(c!='\n'){
		(*pp)[i] =c;
		i++;
		*pp=(char *) realloc(*pp,(i+1)* sizeof(char));
		
		if(*pp == NULL) return;
		c=getchar();
	}
	
	(*pp)[i]='\0';

}
	
void escribirArch(char nom[],char** b){
	FILE* arch=NULL;
	arch = fopen(nom,"w");
	if(arch==NULL) return;
	fprintf(arch,"%s\n",*b);
	fclose(arch);
}
int main() {
	char* str=NULL;
	/*str = cargarStrDin1();
	printf("%s",str);*/
	cargarStrDin2(& str);
	escribirArch("frase.txt", &str);
/*	imprimirArch("frase.txt", &str;*/
	return 0;
}

