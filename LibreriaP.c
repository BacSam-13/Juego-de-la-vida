#include "LibreriaP.h"

// Autor: Baruc Samuel Cabrera Garcia

//////////////////////////
void gotoxy(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//////////////////////////////////

/////////////////////////////////
void clearScreen(void){
int r, c;

    for(r = 0; r < SCREEN_NR; r++)
        for(c = 0; c < SCREEN_NC; c++){
        	
            gotoxy(c,r);//Se va a dicha coordenada
            
            printf(" ");//Se imprime un espacio
            
        }
}
///////////////////////////////// 

/////////////////////////////////////////
void setColor(int n){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//Si se ingresa un numero que no tenga un color asignado, se asignara uno al azar
	if(n > 7)
		n = 1 + rand()% 7;
	
    switch (n) {
        case 0:
        	SetConsoleTextAttribute(hConsole, n+1);
            break;
            
        case 1:
        	SetConsoleTextAttribute(hConsole, n+1);
            break;
            
        case 2:        	        	
		    SetConsoleTextAttribute(hConsole, n+1);
            break;
            
        case 3:
            SetConsoleTextAttribute(hConsole, n+1);
            break;
            
        case 4:
        	SetConsoleTextAttribute(hConsole, n+1);
            break;
            
        case 5:
        	SetConsoleTextAttribute(hConsole, n+1);
            break;
            
        case 6:
        	SetConsoleTextAttribute(hConsole, n+1);
            break;
            
        case 7:
        	SetConsoleTextAttribute(hConsole, n+1);
            break;
    }

}
///////////////////////////////////////

//////////////////////////////
void freeMatrix(int ** mat, int r){

int i;

for(i = 0; i < r; i++)
	free(mat[i]);

free(mat);
	
}
//////////////////////////////

/////////////////////////////
void delay(void){
	getch();	
}
/////////////////////////

///////////////////////////////////
int** start(int r, int c){
	
	int **mat = create(r, c);
	
	int i, j;

	for(i = 0; i < r; i++){	
		for(j = 0; j < c; j++){
			
			mat[i][j] = rand()%2;//Valores aleotorios de vida
			
		}	
	}

	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			
			if(mat[i][j] == 1){
				
				gotoxy(j, i);
				
				setColor(0);
				
				printf("*");
				
				setColor(6);
				
			}else{
				
				gotoxy(j, i);
				
				printf(" ");
				
			}	
		}
	}
	
	return mat;
}
//////////////////////////////////

//////////////////////////////
int **create(int r, int c){
	
	int **Mat = (int**)malloc(r*sizeof(int*));
	
	int i;
	for(i = 0; i < r; i++)
		Mat[i] = (int*)malloc(c*sizeof(int));
	
	return Mat;
}
/////////////////////////////////

//////////////////////////////////////////
int vecinos(int **Mapa, int x, int y, int Filas, int Columnas){

	/*Consideraremos los siquientes espacios
	1  2  3
	8  *  4
	7  6  5
	*/
	
	//Nota: Los ciclos if verifican que la celula no se este en algun borde del mapa
	//para asi no llegar a invadir memoria
		
int v = 0;//Contador de vecinos

//Verificar si hay celulas en 1
if(y-1 >= 0  && x-1 >= 0)
    if(Mapa[y-1][x-1] == 1)
        v++;

//Verificar si hay celulas en 2
if(y-1 >= 0)
    if(Mapa[y-1][x] == 1)
        v++; 

//Verificar si hay celulas en 3
if(y-1 >= 0  && x+1 < Columnas)
    if(Mapa[y-1][x+1] == 1)
        v++; 

//Verificar si hay celulas en 4
if(x+1 < Columnas)
    if(Mapa[y][x+1] == 1)
        v++;

//Verificar si hay celulas en 5
if(x+1 < Columnas && y+1 < Filas)
    if(Mapa[y+1][x+1] == 1)
        v++;

//Verificar si hay celulas en 6
if(y+1 < Filas)
    if(Mapa[y+1][x] == 1)
        v++;

//Verificar si hay celulas en 7
if(y+1 < Filas && x-1 >= 0)
    if(Mapa[y+1][x-1] == 1)
        v++;

//Verificar si hay celulas en 8
if(x-1 >= 0)
    if(Mapa[y][x-1] == 1)
        v++; 
            
    return v;	
}
////////////////////////////////////////

//////////////////////////////////////
void newf(int** M, int r, int c){
	
	int i, j;
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			
			if(M[i][j] == 1){
				
				gotoxy(j, i);
				
				setColor(0);
				
				printf("*");
				
				setColor(6);
				
			}else{
				
				gotoxy(j, i);
				
				printf(" ");
				
			}
		}
	} 
}
//////////////////////////////////////

////////////////////////////////////
void juego(int **Vidas, int **Aux, int r, int c){
	
	//Ciclo infintio hasta que el usuario presione alguna tecla
		while(!kbhit()){
		
		int i, j;
		
		//Ciclo for para contar los vecinos y crear la matriz nueva y asi imprimir el nuevo
		//mapa de celulas
		
		for(i = 0; i < r; i++){
		    for(j = 0; j < c; j++){
			    if(vecinos(Vidas, j, i, r, c) >= 2 && vecinos(Vidas, j, i, r , c) <= 3){
			    	
				    Aux[i][j] = 1;
				    
			    }else{
			    	
				    Aux[i][j] = 0;
				    
			    }
		    }
	    }

	newf(Aux, r, c);//Se imprime la nueva matriz
	
	Vidas = Aux;//Se actualiza la matriz original
	
    }
	
}
//////////////////////////////////////
