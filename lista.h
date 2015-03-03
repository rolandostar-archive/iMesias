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
typedef enum bool{FALSE, TRUE} myBoolean;
typedef enum men{NO_MEMORY,OK} mensaje;


void destroy(lista *);
void clean(lista);
void data(lista);
void edit(lista, int, CANCION);
int size(lista);

myBoolean empty(lista);
lista search(lista, int, char *);

CANCION * find (lista, int);
CANCION pop_izq(lista);
CANCION pop_der(lista);
CANCION pop_pos(lista, int);

mensaje create(lista *);
mensaje push_izq(lista, CANCION);
mensaje push_der(lista, CANCION);
mensaje push_pos(lista, int, CANCION);

#endif
