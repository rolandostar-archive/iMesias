/* ===================== LEGACY CODE ======================

MAIN:

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
   
*/// ======================================================

#include "lista.h"
#include <conio.h>
#include "conio2.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


// Funciones Prototipo
int printc(const char *s);

void drawUI();
int menu();
lista myList;

int main(int argc, char *argv[]) {

  SetConsoleTitle("Practica 5 - iMesias");
  

  drawUI(0); // Inicializar UI
  gotoxy(80,22);
  _setcursortype(_NOCURSOR);
  /*do {
    system("cls");
    op = menu(vmenu,0);
    switch(op) { 
      case 0:
        for(i=3;i>0;i--){
          if(jugar(i)<=0) break; // 3 es el mas facil
        }
        break;
      case 1: return 0;
      case 27: return 0;//Hacer [ESC]
      default: system("PAUSE"); break;
    }
  } while ((op!=3)&&(op!=0));*/
  getch();
  //system("PAUSE");
  return 0;
} // Fin de Main

int menu(){
  
}

void drawUI(int mode){
  int i;
  
  if (mode == 0){
    int x,y;
    system("COLOR 0F");
    switchbackground(BLACK);
    // Logo
    textcolor(LIGHTCYAN);
    printf("  _  __  __             _              \n (_)|  \\/  |  ___  ___ (_)  __ _  ___  \n | || |\\/| | / _ \\/ __|| | / _` |/ __| \n | || |  | ||  __/\\__ \\| || (_| |\\__ \\ \n |_||_|  |_| \\___||___/|_| \\__,_||___/ \n");
    // Backgrounds
    textbackground(LIGHTBLUE);
    for (y=0;y<=14;y++)
      for(x=0;x<=15;x++){
        gotoxy(x+2,y+8); printf(" ");
      }
    for (y=0;y<=14;y++)
      for(x=0;x<=60;x++){
        gotoxy(x+19,y+8); printf(" ");
      }
  }
  
  
  //Text Options
  textcolor(WHITE);
  gotoxy(3,9); printf("[Biblioteca]");
  gotoxy(16,9); printf("%c",16);
  //Play Icon
  gotoxy(4,11); printf("Tus Listas");
  gotoxy(2,13); for(i=0;i<=15;i++) printf("=");
  gotoxy(4,15); printf("Agregar");
  gotoxy(4,17); printf("Eliminar");
  gotoxy(4,19); printf("Editar");
  gotoxy(4,21); printf("Salir");
  
  // Text Info
  textcolor(LIGHTGRAY); textbackground(BLACK);
  gotoxy(3,7); printf("Opciones");
  gotoxy(19,7); printf("Lista");
  
  //Footer Text
  textcolor(YELLOW);
  gotoxy(1,24);
  char *string;
  asprintf(&string,"%c%c: Navegaci%cn       ESC: Salir",30,31,162);
  printc(string);
}

int printc(const char *s) {
  int n = strlen(s); int width = 80; // Ancho de la consola. Por defecto: 80
  int pad = (n >= width) ? 0 : (width - n) / 2;
  printf("%*.*s%s", pad, pad, " ", s);
  //printf("%d\n",pad); // Debug
  return pad; // En caso de necesitar coordenadas.
}
