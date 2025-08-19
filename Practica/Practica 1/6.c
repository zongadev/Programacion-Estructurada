#include <stdio.h>
int T=100;
void cargarText(char text[T]);


void cargarText(char text[T]){
	printf("Ingrece un texto: \n");
	char c;
	int i=0;
	c=getchar();
	while (c!='\n' && i<T){
		text[i]=c;
	}
	printf("%s",text);
}


int main(){
	char text[T];
	cargarText(text);
}
