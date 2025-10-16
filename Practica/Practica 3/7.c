#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cargarStrDin(){
	int i=0;
	char letra;
	char *arr=NULL;
	arr = (char *) malloc(sizeof(char));
	if(arr==NULL) return NULL;
	
	letra=getchar();
	while(letra!= '\n'){
		*(arr+i) = letra;
		i++;
		arr= (char *) realloc(arr,(i+1)*sizeof(char));
		if(arr==NULL) return NULL;
		letra=getchar();
	}
	arr[i]='\0';
	return arr;
}
int main() {
	char *arr;
	printf("Ingrese una sentencia \n");
	arr= cargarStrDin();
	printf("Leido: \"%s\"\n", arr);
	return 0;
}

