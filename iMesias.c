#include "lista.h"
#include <conio.h>
#include <conio2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Funciones Prototipo
int printc(const char *s);
void ShowConsoleCursor(int showFlag);

lista myList;

int main(int argc, char *argv[]) {

/*SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
                                                            FOREGROUND_GREEN | 
                                                            FOREGROUND_INTENSITY | 
                                                            BACKGROUND_BLUE);*/

  printf("  _  __  __             _              \n (_)|  \\/  |  ___  ___ (_)  __ _  ___  \n | || |\\/| | / _ \\/ __|| | / _` |/ __| \n | || |  | ||  __/\\__ \\| || (_| |\\__ \\ \n |_||_|  |_| \\___||___/|_| \\__,_||___/ \n");
  gotoxy(4,7); printf("Opciones");
  gotoxy(3,8); system("COLOR 14");SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); printf("Lorep ipsum dolo sit amet"); system("COLOR 14");
  
  
   /*
   
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
   
   */
   system("PAUSE");
   return 0;
}

void ShowConsoleCursor(int showFlag) { // set the cursor visibility
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; 
    SetConsoleCursorInfo(out, &cursorInfo);
}

int printc(const char *s) {
  int n = strlen(s); int width = 80; // Ancho de la consola. Por defecto: 80
  int pad = (n >= width) ? 0 : (width - n) / 2;
  printf("%*.*s%s", pad, pad, " ", s);
  //printf("%d\n",pad); // Debug
  return pad; // En caso de necesitar coordenadas.
}
