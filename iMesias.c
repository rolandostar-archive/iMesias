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
		printf("Nombre Album [Sin Espacio]: "); scanf("%s",song.album);
		printf("Duracion [Sin Espacio]: "); scanf("%s",song.duracion);
		//printf("Estoy metiendo por Izquierda\n");
		//push_izq(myList,song);
		//printf("Estoy metiendo por Derecha\n");
		//push_der(myList,song);
		//printf("Estoy metiendo siempre al final, probando PushPos(N)\n");
		//push_pos(myList,n,song); // si sirve :'D
		//printf("Estoy metiendo siempre al inicoi, probando PushPos(0)\n");
		//push_pos(myList,0,song); //A huevo, así tambien sirve.. Viene el bueno D:
		int pos; 
		printf("En que pos de la lista lo quieres\n [Si tienes A B C y metes en 2 D, queda A B D C\n");
		scanf("%d",&pos);
		push_pos(myList,pos,song);
		// A HUEVO *-* Si Sirve
		printf("----------------------------------------------------------\n");
	}
	printf("\n\n La lista quedo con %d elementos\n\n",size(myList));
	
	while( !empty(myList) ){
		//song = pop_der(myList);
		song = pop_izq(myList);
		printf("-------------------------------------\n");
		printf("Saque de IZQ, quede con: %d elementos\n",size(myList));
		//printf("Saque de DER, size: %d \n",size(myList));
		printf("Nombre : %s \n",song.nombre);
		printf("Artista : %s \n",song.artista);
		printf("Album : %s \n",song.album);
		printf("Duracion : %s \n",song.duracion);
	}
	//system("PAUSE");
	return 0;
}
