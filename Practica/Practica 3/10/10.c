#include <stdio.h>
		#include <stdlib.h>
#include <string.h>

struct s_texto {
	char * txt;
	int longitud;
};
typedef struct s_texto t_texto;

void cargarTexto(t_texto* s){
	printf("Ingrese una variable: \n");
	int i =0;
	char c;
	char * arr;
	arr = (char *) malloc(sizeof(char));
	while((c=getchar())!='\n'){
		*(arr+i)=c;
		i++;
		arr=(char *) realloc(arr, (i+1)*sizeof(char));
	}
	*(arr+i)='\0';
	s->txt =arr;
	s->longitud = i;
}

void escribirArchTex(){
		
}

int main() {
	t_texto* s;
	cargarTexto(s);
	return 0;
}

