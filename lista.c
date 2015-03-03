#include "lista.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
   typedef struct nodo CANCION;
   typedef struct cab CABECERA;
   typedef CABECERA * lista;

   mensaje create(lista *);
   boolean empty(lista);
   void destroy(lista *);
   void clean(lista);
   CANCION pop_izq(lista);
   CANCION pop_der(lista);
   mensaje push_izq(lista, CANCION);
   mensaje push_der(lista, CANCION);
   mensaje push_pos(lista, int, CANCION);
*/
/*
CANCION * find (lista myList, int place){
	CANCION * aux = myList->I;
	int m,k=0;
	
	m = myList->size;
	
	if(m>pos)
		while(k++ < place)
			aux = aux->sig;
	else{
		aux = myList->F;
		k = myList->size;
		while(k-- > place)
			aux = aux->ant;
	}
	
	return aux;
}*/
/*
void edit(lista myList, int place, CANCION song){
	if(place == 0){
		strcpy(myList->I,song.artista);
		strcpy(myList->I,song.nombre);
		strcpy(myList->I,song.album);
		strcpy(myList->I,song.duracion);
	}
	else if(place >= myList->size - 1){
		strcpy(myList->F,song.artista);
		strcpy(myList->F,song.nombre);
		strcpy(myList->F,song.album);
		strcpy(myList->F,song.duracion);
	}
	else{
		CANCION * mod = NULL;
		mod = find(myList, place);
		strcpy(mod->artista,song.artista);
		strcpy(mod->nombre,song.nombre);
		strcpy(mod->album,song.album);
		strcpy(mod->duracion,song.duracion);
	}
}
*/
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
   q-> I = NULL;
   q-> F = NULL;
}

void destroy( lista * q ){
   clean(*q);
   free(*q);
   *q = NULL;
}

myBoolean empty( lista q ){
   if( q-> F == q-> I && q-> F == NULL)
      return TRUE;
   return FALSE;
}

void data(lista l,int offset){
  //contador (final)
int i,j;
  //ofseet es el inicio, (empieza en cero)
  
	//Si vacia, hago nada
	if(l->I == NULL)
		return;
	//Si no, recorro desde el inicio ( aux ) hasta el final
	CANCION * aux = l->I;
	for(j=0;j<offset-1;j++){
	 aux = aux->sig;
	}
	int x=19,y=8;
	//Esto no entra cuando aux = fin
  for (i=0;i<15;i++){
    gotoxy(x,y);
    
		/*printf("********************************\n");
		printf("Artista : %s\n",aux->artista);
		printf("Cancion : %s\n",aux->nombre);
		printf("Album   : %s\n",aux->album);
		printf("Duracion: %s\n",aux->duracion);*/
	  printf("%.*s", 20, aux->nombre);
	  gotoxy(x+20,y); printf("|");
	  printf("%.*s", 20, aux->artista);
	  gotoxy(x+40,y); printf("|");
	  printf("%.*s", 15, aux->album);
	  gotoxy(x+55,y); printf("|");
	  printf("%.*s", 5, aux->duracion);
	  gotoxy(x,++y);
		aux = aux->sig;
	}
	
	//Falta el ultimo, plt, lo imprimo
	/*
	printf("********************************\n");
	printf("Artista : %s\n",aux->artista);
	printf("Cancion : %s\n",aux->nombre);
	printf("Album   : %s\n",aux->album);
	printf("Duracion: %s\n",aux->duracion);
	printf("********************************\n");*/
	return;
}

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
      l->size = l->size - 1;
   }
   temp.sig = temp.ant = NULL;
   return temp;
}


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
   l->size = l->size + 1;
}

/*
    A B C D
         X
    0 1 2 3
    1 2 3 4
    3
    pos = 2

*/

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
      int k = 1;
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

