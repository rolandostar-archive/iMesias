#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

lista myList;

int main(){
   int n,i,pos;
   CANCION song,newSong;

   //Meter/Sacar contrarios, cola :D
   //Meter/Sacar iguales, pila :D

   create(&myList);
   printf("El size de la lista recien creada es %d\n",size(myList));
   printf("Numero de elementos a pushear: "); scanf("%d",&n);

   for(i=0; i<n; i++){
      printf("Nombre Cancion [Sin Espacio]: "); scanf("%s",song.nombre);
      printf("Nombre Artista [Sin Espacio]: "); scanf("%s",song.artista);
      printf("Nombre Album   [Sin Espacio]: "); scanf("%s",song.album);
      printf("Duracion       [Sin Espacio]: "); scanf("%s",song.duracion);
      printf("Estoy metiendo en N, primero damelo: "); scanf("%d",&pos);
      push_pos(myList, pos, song);
      //printf("Estoy metiendo por Izquierda\n");
      //push_izq(myList,song);
      //printf("Estoy metiendo por Derecha\n");
      //push_der(myList,song);
      printf("----------------------------------------------------------\n");
   }
   printf("\n\n La lista quedo con %d elementos\n\n",size(myList));

   /*
   printf("Edita uno, dame pos: "); scanf("%d",&pos);
   printf("Data para la modificacion: ");
   printf("Nombre Artista [Sin Espacio]: "); scanf("%s",newSong.artista);
   printf("Nombre Cancion [Sin Espacio]: "); scanf("%s",newSong.nombre);
   printf("Nombre Album   [Sin Espacio]: "); scanf("%s",newSong.album);
   printf("Duracion       [Sin Espacio]: "); scanf("%s",newSong.duracion);
   edit(myList,pos,newSong);

   data(myList);
   */

   //char text[70];
   //printf("Elemento de NOMBRE CANCION a buscar: ");
   //printf("Elemento de NOMBRE ARTISTA a buscar: ");
   //printf("Elemento de NOMBRE ALBUM a buscar: ");
   //scanf("%s",text);

   // 0 para canciones  1 para Artistas y  2 para Album
      //lista test = Search(myList,0,text);
   //lista test = search(myList,2,text);

   //if(!empty(test))
   //data(test);

   sort(myList,0);
   data(myList);
   return 0;
}
