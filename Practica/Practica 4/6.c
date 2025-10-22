#include <stdio.h>

void imprimir(int *p){
	
	for(int i=0;p[i]!=0;i++){
		printf("%d\n", p[i]);
	}
}
int *min(int *p){
	if(p[1]==0){
		return p;
	}
	
	int *m = min(p+1);
	if(*m<*p){
		return m;
	}else{
		return p;
	}
}
void ordenar(int *p){
	if(p[0]==0){
		return ;
	}
	int *m = min(p);
	
	if(m!=p){
		int aux = *p;
		*p = *m;
		*m = aux;
	}	
	ordenar(p+1);
	
}
	
int main(int argc, char *argv[]) {
	int l[] = {5,8,12,4,6,32,13,2,8,0};
	ordenar(l);
	imprimir(l);
	return 0;
}

