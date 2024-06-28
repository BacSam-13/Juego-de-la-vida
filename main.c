#include "LibreriaP.h"

// Autor: Baruc Samuel Cabrera Garcia

int main(int argc, char **argv[]) {
	
	srand(time(NULL));
	int r, c;
	
	if(argc >= 3){
		
		r = atoi(argv[1]);
	
	    c = atoi(argv[2]);
		
	}else{

		r = 15;
		
		c = 50;
	}
	
	
	gotoxy(40,0);

    printf("Bienvenido al juego de la vida");

    delay();

    gotoxy(40,3);

    printf("Las reglas son las siguientes:\n\n");

    printf("1. Hay celulas vivas y muertas, las vivas estan representadas como '*', mientras que las muestras son espacios vacios\n\n");

    printf("2. Si una celula esta rodeada por menos de 2 celulas o mas de 3 muere, \nen otro caso, la celula se mantiene con vida o revive");

    delay();

    clearScreen();

    gotoxy(55, 0);

    printf("Comenzemos");

    delay();

    clearScreen();

	int ** Vidas = start(r, c);
	
	int ** Aux = create(r, c);
	
	printf("\n\n\n\t\t\t\tPresione cualquier tecla para terminar el ciclo");
	
    juego( Vidas, Aux, r, c);
    
	clearScreen();

    gotoxy(50, 10);
    
    printf("Gracias por jugar\n\n");
    
    gotoxy(37, 11);
    
    printf("Codigo hecho por Baruc Samuel Cabrera Garcia\n\n\n");
	
	freeMatrix(Vidas, r);
	
	freeMatrix(Aux, r);	
	
	return 0;
}
