#include "lista.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	typedef struct nodo CANCION;
	typedef CABECERA * lista;
	mensaje create(lista *);
	boolean empty(lista);
	void destroy(lista *);
	void clean(lista);
	void data(lista);
	int size(lista);
	CANCION pop_izq(lista);
	CANCION pop_der(lista);
	CANCION pop_pos(lista, int);
	mensaje push_izq(lista, CANCION);
	mensaje push_der(lista, CANCION);
	mensaje push_pos(lista, int, CANCION);
*/

// 		Funciones Basicas

int size(lista l){
	return l->size;
}

mensaje create( lista * q ){
	lista temp = NULL;
	temp = (lista) malloc(sizeof(CABECERA));
	if(temp == NULL)
		return NO_MEMORY;
	temp -> I = temp -> F = NULL;
	temp -> size = 0;
	*q = temp;
	return OK;
}

void clean( lista q ){
	if( q == NULL)
		return;
	if( empty(q) )
		return;
	while( !empty(q) )
		pop_der(q);
	q-> I = q->F = NULL;
}	

void destroy( lista * q ){
	clean(*q);
	free(*q);
	*q = NULL;
}

boolean empty( lista q ){
	if( q-> F == q-> I && q-> F == NULL)
		return TRUE;
	return FALSE;
}

void data(lista l){
	//Si vacia, hago nada
	if(l->I == NULL)
		return;
	//Si no, recorro desde el inicio ( aux ) hasta el final
	CANCION * aux = l->I;
	//Esto no entra cuando aux = fin
	while( aux != l->F){
		printf("********************************\n");
		printf("Artista : %s\n",aux->artista);
		printf("Cancion : %s\n",aux->nombre);
		printf("Album   : %s\n",aux->album);
		printf("Duracion: %s\n",aux->duracion);
		aux = aux->sig;
	}
	//Falta el ultimo, plt, lo imprimo
	printf("********************************\n");
	printf("Artista : %s\n",aux->artista);
	printf("Cancion : %s\n",aux->nombre);
	printf("Album   : %s\n",aux->album);
	printf("Duracion: %s\n",aux->duracion);
	printf("********************************\n");
	return;
}


// 		Funciones Pop

CANCION pop_der(lista l){
	CANCION temp;
	//cancion que voy a regresar
	temp = *(l->F);
	free(l->F);
	
	//si solo era un elemento, ptrs a NULL y resto al tamaño
	if( l->I == l->F){
		l->I = l->F = NULL;
		l->size = l->size - 1;
	}
	//si no, como es por la derecha digo que el final es el anterior del que acabo de quitar
	// y pongo el ultimo en null [Porque es lineal]
	else{
		l->F = temp.ant;
		l->F->sig = NULL;
		//Como saque un elemento, quito uno al tamaño
		l-> size = l->size - 1;
	}
	temp.sig = temp.ant = NULL;
	return temp;
}

CANCION pop_izq(lista l){
	CANCION temp;
	//cancion que voy a regresar
	temp = *(l->I);
	free(l->I);
	
	//si solo era un elemento, ptrs a NULL y resto al tamaño
	if( l->I == l->F){
		l->I = l->F = NULL;
		l->size = l->size - 1;
	}
	//si no, como es por la derecha digo que el final es el anterior del que acabo de quitar
	// y pongo el ultimo en null [Porque es lineal]
	else{
		l->I = temp.sig;
		l->I->ant = NULL;
		//Como saque un elemento, quito uno al tamaño
		l->size = l->size - 1;
	}
	temp.sig = temp.ant = NULL;
	return temp;
}

CANCION pop_pos(lista l, int pos){
	//Si la posicion es mayor al num de elementos de la lista, quita el ultimo
	//O si me dice que la quite el ultimo, pos lo quito xD
	if(pos >= size(l))
		//pop_der quita el ultimo (derecha) y me regresa un temp, entonces, eso regreso
		return pop_der(l);
	//Si quiero quitar el 1ro
	else if(pos==1)
		//pop_izq quita el primero (izquierda) y me regresa un temp, entonces, eso regreso
		return pop_izq(l);
	else{
		//Pos -- poque lo manejamos de 0 a N - 1
		pos--;
		int k = 0;
		//Inicialmente apunto al primer elemento
		CANCION * aux = l->I;
		// Si no he llegado a destino, me muevo
		while(k<pos){
			aux = aux->sig;
			k++;
		}
		
		//Temp es el nodo que voy a regresar
		CANCION temp;
		//Y es en donde se quedo el apuntador aux
		temp = *aux;
		//Muevo el anterior de temp, para que apunte al sig de temp y viceversa
		(temp.ant)->sig = temp.sig;
		(temp.sig)->ant = temp.ant;
		//modifico los apuntadores de temp para no poder acceder a ellos desde afuera
		temp.sig = temp.ant = NULL;
		
		//Como saque un elemento, quito uno al tamaño
		l->size = l->size - 1;
		return temp;		
	}
}

// 		Funciones Push

mensaje push_der(lista l, CANCION song){
	//Creo el espacio para el nodo y veo si hay memoria
	CANCION * temp = (CANCION*) malloc(sizeof(CANCION));
	if(temp == NULL)
		return NO_MEMORY;
	
	//Copio los elementos al temporal
	strcpy(temp->artista,song.artista);
	strcpy(temp->nombre,song.nombre);
	strcpy(temp->album,song.album);
	strcpy(temp->duracion,song.duracion);
	
	//Si vacio, ini y fin apuntan a temp, y no tiene ni ant, ni sig.
	if(empty(l)){
		l->I = temp;
		l->F = temp;
		temp->sig = temp->ant = NULL;
	}
	//Si no, el sig de temp va a ser null por ser el ultimo
	//Hago que el ultimo apunte a temp y viceversa y ahora fin apunta a temp
	else{
		temp->sig = NULL;
		temp->ant = l->F;
		l->F->sig = temp;
		l->F = temp;
	}
	//Sumo uno al tamaño de la lista
	l->size = l->size + 1;
	return OK;
}

mensaje push_izq(lista l, CANCION song){
	//Creo el espacio para el nodo y veo si hay memoria
	CANCION * temp = (CANCION*) malloc(sizeof(CANCION));
	if(temp == NULL)
		return NO_MEMORY;
		
	//Copio los elementos al temporal
	strcpy(temp->artista,song.artista);
	strcpy(temp->nombre,song.nombre);
	strcpy(temp->album,song.album);
	strcpy(temp->duracion,song.duracion);
	
	//Si vacio, ini y fin apuntan a temp, y no tiene ni ant, ni sig.
	if(empty(l)){
		l->I = temp;
		l->F = temp;
		temp->sig = temp->ant = NULL;
	}
	//Si no, el ant de temp va a ser null por ser el primero
	//Hago que el primero apunte a temp y viceversa y ahora ini apunta a temp
	else{
		temp->ant = NULL;
		temp->sig = l->I;
		l->I->ant = temp;
		l->I = temp;
	}
	//Sumo uno al tamaño de la lista
	l->size = l->size + 1;
	return OK;
}

mensaje push_pos(lista l, int pos, CANCION song){
	//Si mi lista esta vacia, lo pongo al final
	//Si no vacia y la posicion es mayor al num de elementos de la lista, lo pone al final
	//O si me dice que la meta a l final, pos al final xD
	if(pos >= size(l))
		push_der(l,song);
		
	//Si quiero meter al inicio
	else if(!pos)
		push_izq(l,song);
		
	//Si quiero meter en N y si se puede
	else{
		//Pos -- poque lo manejamos de 0 a N - 1
		pos--;
		int k = 0;
		//Inicialmente apunto al primer elemento
		CANCION * aux = l->I;
		// Si no he llegado a destino, me muevo
		while(k<pos){
			aux = aux->sig;
			k++;
		}
		
		//Creo el espacio para el nodo y veo si hay memoria
		CANCION * temp = (CANCION*) malloc(sizeof(CANCION));
		if(temp == NULL)
			return NO_MEMORY;
			
		//Copio los elementos al temporal
		strcpy(temp->artista,song.artista);
		strcpy(temp->nombre,song.nombre);
		strcpy(temp->album,song.album);
		strcpy(temp->duracion,song.duracion);
		
		//el sig del temporal, es el sig de el aux
		temp->sig = aux->sig;
		// El nodo al que apunta el temp, en siguiente. Éste en anterior apunta a temp
		(temp->sig)->ant = temp;
		//El ant de temp es aux
		temp->ant = aux;
		//el nodo (donde esta aux) en sig, es temp
		(temp->ant)->sig = temp;
		
		//sumo uno a la lista
		l->size = l->size + 1;
		return OK;
	}
}
