#ifndef LISTA_H
#define LISTA_H

struct nodo{
	//Para el campo Artista de la cancion
	char artista[70];
	//Para el campo Artista de la cancion
	char nombre[70];
	//Para el campo Artista de la cancion
	char album[70];
	//Para el campo Artista de la cancion
	char duracion[5];
	//Apuntadores para conectar la cancion con otras canciones
	struct nodo * sig;
	struct nodo * ant;
};

//Lista en sí, apuntadores a nodos, en inicio y fin. Además
//de un campo size que lleva el tamaño de la lista
struct cab{
	struct nodo *I, *F;
	int size;
};

typedef struct nodo CANCION;
typedef struct cab CABECERA;
typedef CABECERA * lista;
typedef enum bool{FALSE, TRUE} myBoolean;
typedef enum men{NO_MEMORY,OK} mensaje;

//Funcion que inicializa la lista, dice que esta vacia y que el size = 0
mensaje create(lista *);

//Funcion que regresa 1 si la lista esta vacia, 0 si no
myBoolean empty(lista);

//Funcion que borra TODOS los datos de la lista, la deja como nueva
void destroy(lista *);

//Funcion que deja la lista vacia
void clean(lista);

//Funcion que imprime CADA elemento en la lista
void data(lista,int offset);

//Funcion que regresa el tamaño de la lista
int size(lista);

//Funcion que regresa SIEMPRE LA CANCION MÁS  A LA IZQUIERDA [Inicio]
CANCION pop_izq(lista);

//Funcion que regresa SIEMPRE LA CANCION MÁS  A LA DERECHA [Fin]
CANCION pop_der(lista);

//Funcion que regresa LA CANCION NUMERO POS [2do parametro]. Ejemplo
/*
	lista tiene:          A B C D E F
	y son los elementos   1 2 3 4 5 6
	si digo 'pos_pop(lista,4)'
	me va a regresar el elemento D
	y la lista quedará    A B C E F
								 1 2 3 4 5
*/
CANCION pop_pos(lista, int);

//Funcion que mete datos SIEMPRE A LA IZQUIERDA [Inicio]
mensaje push_izq(lista, CANCION);

//Funcion que mete datos SIEMPRE A LA DERECHA [Fin]
mensaje push_der(lista, CANCION);

//Funcion que mete datos en POS+1 [2do parametro]. Ejemplo
/*
	lista tiene: 			A B C D E
	y son los elementos  1 2 3 4 5
	si digo 'push_pos(lista,3,rola)'
	va a meter 'rola' en el elemento 4
	y la lista quedaría  A B C rola D E
								1 2 3   4  5 6
*/ 
mensaje push_pos(lista, int, CANCION);


#endif
