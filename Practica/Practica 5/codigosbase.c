
(*str)[i]=c;

remalloc() lleva siempre i+1
(*str) = realloc((*str),(i+1)*(sizeof(char)));
	
todo lo que lleva un * antes, puede ser el inicio de una lista, es mas
asi vienen las listas dinamicas.

char *s = "Hola";
/*Esto guarda el primer lugar del string.
    *(s+1) es el segundo y asi.*/

/*---------------------------------------------------*/

void agregarFinal(p_num* p,p_num nuevo){
	if(*p == NULL){
		*p = nuevo;
	}else{
		agregarFinal(&((*p)->sig),nuevo);
	}
}

/*--------------------------PILAS--------------------------------*/
void push(t_nodo *p,t_dato n){
	t_nodo nuevo = malloc(sizeof(t_nodo));
	nuevo->sig=(*p);
	*p = nuevo;
}
t_dato pop(t_nodo *p){
	t_dato dato={0};
	if((*p)!=NULL){
		dato = (*p)->dato;
		t_nodo aux =(*p);
		(*p)=(*p)->sig;
		free(aux);
	}
	return dato;
}
	
void eliminar_en_rango(t_nodo *pp, int sinf, int ssup)
	while (*pp) {
		t_nodo nodo = *pp;
		if (nodo->dato.stock >= sinf && nodo->dato.stock <= ssup) {
			// borrar este nodo
			*pp = nodo->sig;        // desvincular
			free(nodo->dato.nomprod);
			free(nodo);
		} else {
			// conservar: avanzar pp al puntero 'sig' del nodo actual
			pp = &nodo->sig;
		}
	}
/*-----------------COLA CON DOS PUNTEROS-----------------------------*/
		
		/*Usamos los siguientes structs*/
		
		struct s_cola{
			tNodo frente; //head (primero)
			tNodo final;  //tail (ultimo )
		};
		typedef struct s_cola t_cola;
		
		struct sNodo{
			int valor;
			struct sNodo *sig;
		};
		typedef struct sNodo* tNodo;
		
		void queue(t_cola* cola, int valor){
			// con dos punteros (frente y final)
			tNodo aux = (tNodo) malloc(sizeof(struct sNodo));
			aux->valor = valor;
			aux->sig = NULL;
			if (cola->frente == NULL && cola->final == NULL){
				cola->frente = aux;
				cola->final = aux;
			}
			else {
				cola->final->sig = aux;
				cola->final = aux;
			}
		}
			
		int dequeue(t_cola* cola){
			int valor;
			tNodo aux = cola->frente;
			cola->frente = cola->frente->sig;
			valor = aux->valor;
			free(aux);
			if (cola->frente == NULL) {
				cola->final = NULL;
			}
			return valor;
		}

		
		
		
/*--------------------------------------------------------------------*/
			
/*Funcion utilizada para crear LA LISTA, no el nodo.
  La funcion se encarga de pedirte los datos y pasar estos datos
  a la fucion crearNodo, que simplemente rellena el nodo y le asigna espacio*/

void crear(p_num * lis){
	int n;
	printf("\nIngese un numero: ");
	scanf("%d",&n);
	while(n!=0){
		agregarFinal(lis,crearNodo(n));/*ACA VAS AGREGANDO AL FINAL*/
			printf("\nIngese un numero: ");
				scanf("%d",&n);
	}
}
	

	p_num crearNodo(int num){ 
		/*ACA PASA POR PARAMETRO TODO LO QUE TENGA EL struct
		TAMBIEN PODES CARGARLO ACA MISMO PERO CAMBIA LA FUNCION CREAR*/
		p_num nodo = malloc(sizeof(struct num));
		if(nodo !=NULL){
			nodo->n=num;
			nodo->sig=NULL;
		}
		return nodo;
	}
		
	void agregarFinal(p_num* p,p_num nuevo){ /*Esto incluye la cabeza*/
		if(*p == NULL){
			*p = nuevo;
		}else{
			agregarFinal(&((*p)->sig),nuevo);
		}
	}
/*-----------------------------------------------------------------------------------------------*/
/*Los dos codigos de aca abajo son para eliminar si se es igual a cierto parametro*/
	
	void eliminarUnNodo(p_persona* pp, char val[]){
		if(strcmp((*pp)->apellido,val)==0){
			p_persona tmp = (*pp);
			*pp = (*pp)->sig;
			free(tmp);
		}else{
			p_persona actual = (*pp)->sig;
			p_persona anterior = *pp;
			while(strcmp(actual->apellido,val)){
				anterior = actual;
				actual = actual->sig;
			}
			if(actual->sig !=NULL ||strcmp(actual->apellido,val)==0 ){
				anterior->sig=actual->sig;
			}
		}
	}
		
		void eliminarTodos(p_persona* pp, char val[]){
			while(strcmp((*pp)->apellido,val)==0){
				p_persona tmp = (*pp);
				*pp = (*pp)->sig;
				free(tmp);
			}
			
			if((*pp)->sig != NULL){
				p_persona actual = (*pp)->sig;
				p_persona anterior = *pp;
				while (actual!=NULL) {
					if(strcmp(actual->apellido,val)==0){
						anterior->sig=actual->sig;
						free(actual);
						actual=anterior->sig;
						
					}else{
						anterior = actual;
						actual = actual->sig;
					}
				}
			}
		}
			
