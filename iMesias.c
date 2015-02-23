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
#include <conio2.h> //Conio 2.1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//Definiciones
#define KEY_UP 72
#define KEY_DOWN 80

#define AV_PAG 81
#define RE_PAG 73

// Funciones Prototipo
int printc(const char *s);
int doexit(int code);
void drawUI();
int menu(char vmenu[][11], int);
lista myList;

int main(int argc, char *argv[]) {
  int op;
  SetConsoleTitle("Practica 5 - iMesias");
  char vmenu[6][11] = {
    "Biblioteca","Tus Listas","Agregar","Eliminar","Editar","Salir"
  };

  drawUI(0); // Inicializar UI
  gotoxy(80,22);
  _setcursortype(_NOCURSOR);
  do {
    op = menu(vmenu,0);
    switch(op) {
      case 1: // Biblioteca
        break;
      case 2: // Tus Listas
        menu(vmenu,1);
        break;
      case 3: // Agregar
        break;
      case 4: //Eliminar
        break;
      case 5: // Editar
        break;
      case 27: return doexit(0); //Hacer [ESC]
      default: break;
    }
  } while (op!=6); // Salir
  return doexit(1);
} // Fin de Main

int doexit(int code){ // Formateo mamon
  textcolor(WHITE); textbackground(BLACK);
  gotoxy(1,24); clreol();
  gotoxy(80,22); return code;
}

int menu(char vmenu[][11],int mode){
  // Mode: 0 para biblioteca, 1 para Tus listas
  int key=0,op=1,i=mode;
  // key: Tecla presionada
  // op: Opcion
  // i: contador de posicion (cursor)
  int Y[6]={9,11,15,17,19,21};
  // Y: Coordenadas

  drawUI(mode+1);
  textcolor(WHITE); textbackground(LIGHTBLUE);
  while((key = _getch()) != 27){
    if (key == 0 || key == 224){ // Si getch() es tecla especial
      switch(key = getch()){ // Obetener segundo getch.
        case KEY_DOWN:
          gotoxy(3,Y[i]); printf(" %s ",vmenu[i]);
          if (i<5) i++;
          gotoxy(3,Y[i]); printf("[%s] ",vmenu[i]);
          break;
        case KEY_UP:
          gotoxy(3,Y[i]); printf(" %s ",vmenu[i]);
          if (i>0) i--;
          gotoxy(3,Y[i]); printf("[%s] ",vmenu[i]);
          break;
        case AV_PAG:
          break;
        case RE_PAG:
          break;
        default: break;
      }
    } else if(key==13) return i+1;
  }
  return 27;
}

void drawUI(int mode){
  // Mode: 0 commun, 1 Biblioteca, 2 Tus listas.
  if(mode == 1){
    //Text Options
    textcolor(WHITE); textbackground(LIGHTBLUE);
    gotoxy(3,9); printf("[Biblioteca]");
    gotoxy(16,9); printf("%c",16); //Play Icon
    gotoxy(16,11); printf(" ",16); //Play Icon
  }
  
  if(mode == 2){
    //Text Options
    textcolor(WHITE); textbackground(LIGHTBLUE);
    gotoxy(3,11); printf("[Tus Listas]");
    gotoxy(16,9); printf(" ",16); //Play Icon
    gotoxy(16,11); printf("%c",16); //Play Icon
  }
  
  if (mode == 0){
    int x,y,i;
    system("COLOR 0F"); // Color estandar de consola
    switchbackground(BLACK); // Color por conio

    // Imprime Logo
    textcolor(LIGHTCYAN);
    printf("  _  __  __             _              \n (_)|  \\/  |  ___  ___ (_)  __ _  ___  \n | || |\\/| | / _ \\/ __|| | / _` |/ __| \n | || |  | ||  __/\\__ \\| || (_| |\\__ \\ \n |_||_|  |_| \\___||___/|_| \\__,_||___/ \n");

    // Imprime Backgrounds
    textbackground(LIGHTBLUE);
    for (y=0;y<=14;y++) for(x=0;x<=15;x++){
      gotoxy(x+2,y+8); printf(" ");
    }
    for (y=0;y<=14;y++) for(x=0;x<=60;x++){
      gotoxy(x+19,y+8); printf(" ");
    }

    //Imprime opciones
    textcolor(WHITE);
    gotoxy(2,13); for(i=0;i<=15;i++) printf("=");
    gotoxy(4,11); printf("Tus Listas");
    gotoxy(3,9); printf("Biblioteca");
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
    asprintf(&string,"%c%c: Navegaci%cn     ESC: Salir     RePag/AvPag: Navegaci%cn (Lista)",30,31,162,162);
    printc(string);
  } // Fin de if(mode==0)
}

int printc(const char *s) {
  int n = strlen(s); int width = 80; // Ancho de la consola. Por defecto: 80
  int pad = (n >= width) ? 0 : (width - n) / 2;
  printf("%*.*s%s", pad, pad, " ", s);
  //printf("%d\n",pad); // Debug
  return pad; // En caso de necesitar coordenadas.
}
