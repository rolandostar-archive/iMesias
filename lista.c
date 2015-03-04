#include "lista.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void destroy( lista * q ){
   clean(*q);
   free(*q);
   *q = NULL;
}

void edit(lista myList, int place, CANCION song){
	//Si es el primero
	if(place == 0){
		strcpy(myList->I->artista,song.artista);
		strcpy(myList->I->nombre,song.nombre);
		strcpy(myList->I->album,song.album);
		strcpy(myList->I->duracion,song.duracion);
	}
	//Si es el ultimo
	else if(place >= myList->size - 1){
		strcpy(myList->F->artista,song.artista);
		strcpy(myList->F->nombre,song.nombre);
		strcpy(myList->F->album,song.album);
		strcpy(myList->F->duracion,song.duracion);
	}
	//Si esta en medio
	else{
		CANCION * mod = find(myList, place);
		strcpy(mod->artista,song.artista);
		strcpy(mod->nombre,song.nombre);
		strcpy(mod->album,song.album);
		strcpy(mod->duracion,song.duracion);
	}
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

void data_full(lista l){
	if(l->I == NULL)
		return;
	CANCION * aux = l->I;
	while( aux != l->F){
		printf("********************************\n");
		printf("Cancion : %s\n",aux->nombre);
		printf("Artista : %s\n",aux->artista);
		printf("Album   : %s\n",aux->album);
		printf("Duracion: %s\n",aux->duracion);
		aux = aux->sig;
	}
	//Falta el ultimo
	printf("********************************\n");
   printf("Cancion : %s\n",aux->nombre);
   printf("Artista : %s\n",aux->artista);
	printf("Album   : %s\n",aux->album);
	printf("Duracion: %s\n",aux->duracion);
	printf("********************************\n");
	return;
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
	gotoxy(19,8);
	//Esto no entra cuando aux = fin
  for (i=0;i<15;i++){
	  clreol(); printf(" %.*s", 17, aux->nombre);
	  gotoxy(x+17,y); printf(" * ");
	  clreol(); printf(" %.*s", 17, aux->artista);
	  gotoxy(x+37,y); printf(" * ");
	  clreol(); printf(" %.*s", 12, aux->album);
	  gotoxy(x+52,y); printf(" * ");
	  clreol(); printf(" %.*s", 5, aux->duracion);
	  gotoxy(x,++y);
		aux = aux->sig;
	}
	return;
}

int compare(CANCION A, CANCION B, int element){
  if(element == 0 ){
   if( !strncmp(A.nombre,B.nombre,70) )
      if( !strncmp(A.artista,B.artista,70) )
         return strncmp(A.album,B.album,70);
      return strncmp(A.artista,B.artista,70);
   return strncmp(A.nombre,B.nombre,70);
  }
  else if(element == 1){
    if( !strncmp(A.artista,B.artista,70) )
      if( !strncmp(A.nombre,B.nombre,70) )
         return strncmp(A.album,B.album,70);
      return strncmp(A.nombre,B.nombre,70);
    return strncmp(A.artista,B.artista,70);
  }
  else if(element == 2){
    if( !strncmp(A.album,B.album,70) )
      if( !strncmp(A.artista,B.artista,70) )
         return strncmp(A.nombre,B.nombre,70);
      return strncmp(A.artista,B.artista,70);
   return strncmp(A.album,B.album,70);
  }
}

void sort(lista myList, int element){
  int ini, index;
  CANCION * aux, * lugar;
  CANCION temp;

  lugar = myList -> I;
  aux = lugar->sig;
  index = 0;

  while(lugar != myList->F){
    temp = *lugar;
    for(ini = index+1; ini < size(myList); ini++){
      if( compare(temp, *aux, element) ){
        temp = *aux;
        edit(myList,ini,*lugar);
        edit(myList,index, temp);
      }
      aux = aux->sig;
    }
    index++;
    lugar = lugar->sig;
    aux = lugar->sig;
  }
}

int size(lista l){
   return l->size;
}


myBoolean empty( lista q ){
   if( q-> F == q-> I && q-> F == NULL)
      return TRUE;
   return FALSE;
}

lista search(lista myList, int element, char * cad){

   //Primero que no esté vacía
   printf("*********************Si entre :D Funcion Search \n\n");

   CANCION * ptr = myList -> I;
   CANCION temp;

   lista result;
   create(&result);

   while( ptr != myList->F){
      switch(element){
         case 0:
            if( !strncmp(ptr->nombre,cad,70) ){
               temp = *ptr;
               temp.sig = temp.ant = NULL;
               push_der(result,temp);
            }
         break;

         case 1:
            if( !strncmp(ptr->artista,cad,70) ){
               temp = *ptr;
               temp.sig = temp.ant = NULL;
               push_der(result,temp);
            }
         break;

         case 2:
            if( !strncmp(ptr->album,cad,70) ){
               temp = *ptr;
               temp.sig = temp.ant = NULL;
               push_der(result,temp);
            }
         break;
      }
      ptr = ptr->sig;
   }
   if( !strncmp(myList->F->nombre,cad,70) && !element){
      temp = *(myList->F);
      temp.sig = temp.ant = NULL;
      push_der(result,temp);
   }
   else if( !strncmp(myList->F->artista,cad,70) && element == 1){
      temp = *(myList->F);
      temp.sig = temp.ant = NULL;
      push_der(result,temp);
   }
   else if( !strncmp(myList->F->album,cad,70) && element == 2){
      temp = *(myList->F);
      temp.sig = temp.ant = NULL;
      push_der(result,temp);
   }

   printf("--------------Hazta aqui todo bien\n");
   printf("De hecho, result queda con %d elementos\n",size(result));

   return result;
}

CANCION * find (lista myList, int place){
	//inicialmente mi apuntador ve al inicio
	CANCION * aux = myList->I;
	int m,k=0;
   //saco la mitad de la lista
	m = myList->size;

   //si estpy del lado izquierdo [Antes de la mitad]
	if(m>place)
      //Voy recorriendo aux
		while(k++ < place)
			aux = aux->sig;
   //De lo contrario, aux ve al final, y como se que estoy del lado derecho de la mitar [inclusivo]
	else{
		aux = myList->F;
		k = myList->size;
		//Recorro aux para atras, y ya
		while(k-- > place)
			aux = aux->ant;
	}
   //Regreso el apuntador
	return aux;
}

CANCION pop_der(lista l){
   CANCION temp;
   //cancion que voy a regresar
   temp = *(l->F);
   free(l->F);

   //si solo era un elemento, ptrs a NULL y resto al tama?o
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


   //si solo era un elemento, ptrs a NULL y resto al tamanio

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

CANCION pop_pos(lista l, int pos){
	//Si la posicion es mayor al num de elementos de la lista, quita el ultimo
	//O si me dice que la quite el ultimo, pos lo quito xD
	if(pos >= size(l))
		return pop_der(l);
	else if(pos==1)
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

		CANCION temp;
		temp = *aux;
		(temp.ant)->sig = temp.sig;
		(temp.sig)->ant = temp.ant;
		temp.sig = temp.ant = NULL;

		l->size = l->size - 1;
		return temp;
	}
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

      // El nodo al que apunta el temp, en siguiente. ?ste en anterior apunta a temp

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

