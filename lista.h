#ifndef LISTA_H
#define LISTA_H

struct nodo{
    char artista[70];
    char nombre[70];
    char album[70];
    char duracion[5];
    struct nodo * sig;
    struct nodo * ant;
};

struct cab{
    struct nodo *I, *F;
    int size;
};

typedef struct nodo CANCION;
typedef struct cab CABECERA;
typedef CABECERA * lista;
typedef enum bool{FALSE, TRUE} boolean;
typedef enum men{NO_MEMORY,OK} mensaje;

mensaje create(lista *);
boolean empty(lista);
void destroy(lista *);
void clean(lista);
int size(lista);
CANCION pop_izq(lista);
CANCION pop_der(lista);
mensaje push_izq(lista, CANCION);
mensaje push_der(lista, CANCION);
mensaje push_pos(lista, int, CANCION);

#endif
