#include <stdio.h>
typedef struct
{
	int n, o , p;
	char p1[26], p2[50];
	double a, b, c;
}
t_varios;

void intercambio(t_varios* a, t_varios* b){
	t_varios aux = *a;
	*a = *b;
	*b=aux;
}

