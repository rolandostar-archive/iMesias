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

int printlist(char file[20],int offset){
   char ch;
   FILE *fp;
 
   fp = fopen(file,"r"); // read mode
   if( fp == NULL ) return -1;
  //printf("The contents of %s file are :\n", file_name);
 
   while( ( ch = fgetc(fp) ) != EOF )
      printf("%c",ch);
 
   fclose(fp);
   return 1;
}

void append(char* s, char c)
{
  char temp[2]; 
  temp[0] = c; 
  temp[1] = '\0'; 
  strcat( s, temp );
}

void parselist(char file[20],lista myList,int offset){
  int done=0;
   char ch;
   char aux[70]="";
   FILE *fp;
   CANCION cancion;
 
   fp = fopen(file,"r"); // read mode
   if( fp == NULL ) return;

  do{
    while( (ch=fgetc(fp)) != 95 ){
      append(aux,ch);
    }
    //printf("NOMBRE: %s\n",aux);
      strcpy(cancion.nombre,aux);
    memset(aux,0,strlen(aux));
    while( (ch=fgetc(fp)) != 95 ){
      append(aux,ch);
    }
     // printf("ARTISTA: %s\n",aux);
      strcpy(cancion.artista,aux);
      memset(aux,0,strlen(aux));
    while( (ch=fgetc(fp)) != 95 ){
      append(aux,ch);
    }
    //printf("ALBUM: %s\n",aux);
      strcpy(cancion.album,aux);
      memset(aux,0,strlen(aux));
    while( (ch=fgetc(fp)) != '\n' ){
      append(aux,ch);
    }
    //printf("DUYRACION: %s\n\n",aux);
      strcpy(cancion.duracion,aux);
      memset(aux,0,strlen(aux));
      push_der(myList,cancion);
    if (ch=='\n'&&(ch=fgetc(fp)) == EOF ){
      return;
    }else{
      append(aux,ch);
    }
  }while(ch!=EOF);
   fclose(fp);
  return;
}

int main(int argc, char *argv[]) {
  int op,mode=0;
  SetConsoleTitle("Practica 5 - iMesias");
  char vmenu[6][11] = {
    "Biblioteca","Tus Listas","Agregar","Eliminar","Editar","Salir"
  };
  lista myList;
  create(&myList);
  
  //Imprime archivo general
    system("COLOR 0F");
    printf("Hola");
  parselist("Biblioteca2.txt",myList,0); //Parsea Lista a myList

  //drawUI(0); // Inicializar UI
  //printlist(myList); // Imprime Lista
  gotoxy(80,22);
  _setcursortype(_NOCURSOR);
  do {
    op = menu(vmenu,mode);
    switch(op) {
      case 1: // Biblioteca
        mode=0;
        break;
      case 2: // Tus Listas
        mode=1;
        break;
      case 3: // Agregar
        break;
      case 4: //Eliminar
        break;
      case 5: // Editar
        break;
      case 6: return doexit(1); //Hacer [ESC]
      case 27: return doexit(1);
      default: break;
    }
  } while (op!=6); // Salir
  return doexit(0);
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

  textcolor(WHITE); textbackground(LIGHTBLUE);
  drawUI(mode+1);
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
    gotoxy(4,9); printf("Biblioteca");
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

