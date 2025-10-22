#include <stdio.h>


int maxima(int *p){
	if (p[1]==0){ //si la que le sigue al puntero es 0
		return p[0]; //retornas el valor actual
	}
	int m = maxima(p+1);//esto avanza hasta el final hasta encontrar el ultimo
	
	//una vez se carga el ultimo, se va a ir descolando y va a ir haciendo el
	//siguiente chequeo. El ultimo, va a chequear consigo mismo, el siguiente ya no
	//los siguientes m's van a ir cargandose en base a la condicion de abajo.
	//el unico que se carga en base a lo primero es el ultimo.
	if(p[0]>m){
		return p[0];
	}else{
		return m;
	}
}

	
	int* maximab(int *p){
		if (p[1]==0){ //si la que le sigue al puntero es 0
			return p; //retornas el valor actual
		}
		int* m = maximab(p+1);//esto avanza hasta el final hasta encontrar el ultimo
		
		//una vez se carga el ultimo, se va a ir descolando y va a ir haciendo el
		//siguiente chequeo. El ultimo, va a chequear consigo mismo, el siguiente ya no
		//los siguientes m's van a ir cargandose en base a la condicion de abajo.
		//el unico que se carga en base a lo primero es el ultimo.
		if(p[0]>*m){
			return p;
		}else{
			return m;
		}
	}
int main(int argc, char *argv[]) {
	int l[] = {5,8,12,4,6,32,13,2,8,0};
	printf("%d",maxima(l));
	printf("\n %d ",maximab(l));
	return 0;
}

