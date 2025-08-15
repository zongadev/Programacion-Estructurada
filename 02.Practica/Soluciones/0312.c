// EJERCICIO 03.12
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct s_texto{
	char * txt;
	int lon;
};
typedef struct s_texto t_texto;
int cargarTexto(t_texto* p){
	int i=0;
	int c;
	p->txt=NULL;
	c = getchar();
	if(c!='\n'){
		p->txt=malloc(sizeof(char)*1);
		
		while(c!='\n'){
			p->txt[i]=c;
			i+=1;
			p->txt=realloc(p->txt,sizeof(char)*(i+1));
			c = getchar();
		}
		p->txt[i]='\0';
		p->lon=i;
	}
	return i;
}
void cargarFrase(t_texto** arrT){
	int i=0,lon=0;
	*arrT=malloc(sizeof(t_texto)*1);
	lon=cargarTexto((*arrT)+i);
	while(((*arrT)+i)->txt!=NULL){
		i+=1;
		*arrT=(t_texto*)realloc((*arrT),sizeof(t_texto)*(i+1));
		lon=cargarTexto((*arrT)+i);
	}
	
}
void imprimirFrase(t_texto* arrT){
	int i=0;
	if (arrT!=NULL){
		while((arrT+i)->txt!=NULL){
			printf("<%d> (%d): %s\n",(arrT+i),(arrT+i)->lon,(arrT+i)->txt);
			i+=1;
		}       
	}
}
	
void ordenar(t_texto* arrT){
	
	t_texto aux;
	aux.txt;
	int i=0,j=0,len=0;
	for (len=0;(arrT+len)->txt!=NULL;len++)
	for (i=0;i<len-1;i++){
		for (j=i+1;j<len;j++){
			if (strcmp((arrT+i)->txt,(arrT+j)->txt)){
				aux.lon=(arrT+i)->lon;
				aux.txt=(arrT+i)->txt;
				
				(arrT+i)->lon=(arrT+j)->lon;
				(arrT+i)->txt=(arrT+j)->txt;
				
			    (arrT+j)->lon=aux.lon;
				(arrT+j)->txt=aux.txt;
				
			}
		}	
	}
}
int main() {
	t_texto* arrT=NULL; 
	cargarFrase(&arrT);
	printf("ORIGINAL\n");
	imprimirFrase(arrT);
	ordenar(arrT);
	printf("ORDENADO\n");
	imprimirFrase(arrT);
	return 0;
}


/*
// ejercicio 10 

#include <stdio.h>
#include <stdlib.h>
struct s_texto{
char * txt;
int lon;
};
typedef struct s_texto t_texto;
int cargarTexto(t_texto* p){
int i=0;
int c;
p->txt=malloc(sizeof(char)*1);
c = getchar();
while(c!='\n'){
p->txt[i]=c;
i+=1;
p->txt=realloc(p->txt,sizeof(char)*(i+1));
c = getchar();
}
p->txt[i]='\0';
p->lon=i;
return i;
}
int main() {
t_texto t;
cargarTexto(&t);
printf("<%d>: %s\n",t.lon,t.txt);   
return 0;
}
*/

