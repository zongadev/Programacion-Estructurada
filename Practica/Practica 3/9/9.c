#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * subcadena (char * p, int i, int n);

char * subcadena(char * p, int i, int n){
	char * x;
	int j=0;
	x= (char *) malloc(sizeof(char));
	while(j<=n){
		*(x+j)= *(p+i+j);
		printf("%c,%d,%d\n",*(p+i+j),j,i);
		x = (char *) realloc(x,(j+2)*sizeof(char));
		j++;
	}
	*(x+j)='\0';
	return x;
}

char * leerArch(char nom[]){
	char c;
	int i=0;
	char *arr;
	arr= (char *) malloc(sizeof(char));
	FILE* arch=fopen(nom,"r");
	if (arch ==NULL) return NULL;
	while((c=getc(arch))!=EOF){
		*(arr+i)=c;
		i++;
		arr=(char *) realloc(arr,(i+1)*sizeof(char));
	}
	return arr;
}

int main() {
	char* str=NULL;
	char* subStr=NULL;
	int i=1, n=20;
	str = leerArch("frase.txt");
    subStr = subcadena (str, i, n);
	printf("Para i = %d y n = %d ,Se encontro el substring: ", i,n);
	printf("%s", subStr);
	return 0;
}

