#include "lista.c"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

lista myList;

int main(int argc, char *argv[]) {
   int n,i;
   CANCION song;

   //Meter/Sacar contrarios, cola :D
   //Meter/Sacar iguales, pila :D

   create(&myList);
   printf("El size de la lista recien creada es %d\n",size(myList));
   printf("Numero de elementos a pushear: "); scanf("%d",&n);

   for(i=0; i<n; i++){
      printf("Nombre Artista [Sin Espacio]: "); scanf("%s",song.artista);
      printf("Nombre Cancion [Sin Espacio]: "); scanf("%s",song.nombre);
      printf("Nombre Album   [Sin Espacio]: "); scanf("%s",song.album);
      printf("Duracion       [Sin Espacio]: "); scanf("%s",song.duracion);
      //printf("Estoy metiendo por Izquierda\n");
      //push_izq(myList,song);
      printf("Estoy metiendo por Derecha\n");
      push_der(myList,song);
      printf("----------------------------------------------------------\n");
   }
   printf("\n\n La lista quedo con %d elementos\n\n",size(myList));

   while( !empty(myList) ){
      song = pop_der(myList);
      printf("-------------------------------------\n");
      printf("Saque de IZQ, size: %d \n",size(myList));
      //printf("Saque de DER, size: %d \n",size(myList));
      printf("Nombre : %s \n",song.nombre);
      printf("Artista : %s \n",song.artista);
      printf("Album : %s \n",song.album);
      printf("Duracion : %s \n",song.duracion);
   }
   //system("PAUSE");
   return 0;
}
