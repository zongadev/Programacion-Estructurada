#include <stdio.h>
int T=100;

int cargarText(char text[T]);
void imprimirText(char text[T]);
void normalizar(char text[T],int len);

int cargarText(char text[T]){
	printf("Ingrece un texto: ");
	char c;
	int i=0;
	while(i<T && ((c=getchar())!='\n')){
		text[i]=c;
		i++;
	}
	text[i]='\0';
	return i;
}

void imprimirText(char text[T]){
	printf("\n Texto: \t %s",text);
}
	
void normalizar(char text[T], int len){
	char temp;
	int newlen;
	if(text[0]>=97 && text[0]<=122){
		text[0]=text[0]-32;
	}
	for(int i=0; text[i]!= '\0';i++){ //el ciclo I es el que recorre la palabra
		for(int j = i+1; text[j]==' '; j++){ //el ciclo J es el que itera dentro de los espacios
			if(j>0){
				
				for(int k =j; text[k]!='\0';k++){//el ciclo K es para desplazar
					text[k]= text[k+1];
				}
		}
			}
	
	if(text[i+1]=='\0' && text[i]!='.'){
		text[i+1]='.';
		text[i+2]='\0';
}}
}
	
int main(){
	char text[T];
	int l;
	l=cargarText(text);
	imprimirText(text);
	normalizar(text,l);
	imprimirText(text);
}
