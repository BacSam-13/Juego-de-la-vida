#ifndef LibreriaP
#define LibreriaP

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define SCREEN_NC 120//Numero de columnas
#define SCREEN_NR 29//Numero de renglones

// Autor: Baruc Samuel Cabrera Garcia

void gotoxy(int x,int y);
void clearScreen(void);
void setColor(int idxColor);
void freeMatrix(int ** mat, int r);
void delay(void);
int ** start(int r, int c);
int **create(int r, int c);
int vecinos(int **Mapa, int x, int y, int Filas, int Columnas);
void newf(int **M, int r, int c);
void juego(int **Aux, int **Vidas, int r, int c);

#endif
