#include <stdio.h>
#include <string.h>

typedef struct tres{
	int a,b,c;
} t_tres;

void ordenar(t_tres *p){
	int aux;
	if(p->a > p->b){
		aux = p->a;
		p->a = p->b;
		p->b = aux;
		
	}
	if(p->a > p->c){
		aux = p->a;
		p->a = p->c;
		p->c = aux;
	}
	
	if(p->b > p->c){
		aux = p->b;
		p->b = p->c;
		p->c = aux;
	}
}

int main(){
	t_tres t;
	t.a = 3;
	t.c = 1;
	t.b = 8;
	ordenar(&t);
	printf("%d,%d,%d",t.a,t.b,t.c);
	return 0;
}
