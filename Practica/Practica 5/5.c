#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_num{
	int num;
	struct s_num* sig;
};
typedef s_num* p_num;

struct s_per{
	int num;
	char nom[50];
	char ape[50];
	struct s_per* sig;
};
typedef s_per* p_per;

void pushI(p_num* p, p_num n){
	n->sig = (*p);
	(*p) = n;
}
	
void pushS(s_per* p, p_per pe){
	pe->sig = (*p);
	(*p) = pe;
}

p_num popI(p_num *p){
	if ((*p) != NULL) {
		p_num aux = (*p);
		int valor = aux->num;
		free(aux);
		(*p)=(*p)->sig;
		return aux;
	}
}

p_num popI(p_num *p){
	if ((*p) != NULL) {
		int aux = (*p)->num;
		(*p)=(*p)->sig;
		return aux;
	}
}
		
	
int main(int argc, char *argv[]) {
	
	return 0;
}

