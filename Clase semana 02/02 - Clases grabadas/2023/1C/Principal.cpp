
#include <iostream>
#include "Tablero.h"
#include <rand>


void funcion3() {
	char * terreno3;
	char terreno4 = 'A';
	terreno3 = &terreno4;
	terreno3 = new char;
	*terreno3 = 'B';
	delete terreno3;
}

void funcion1() {
	char terreno;
	int numero;
}

void funcion2() {
	char terreno1 = '1';
	int numero1;
}

int main(){
	char tablero1 = 'A';
	char * tablero2;
	tablero2 = &tablero1;
	char **tablero4;
	tablero4 = &tablero2;

	tablero2[0] = 'B';
	*tablero2 = 'C';
	**tablero4 = 'D';



	for(int i = 0; i < 20; i++) {
		tablero2[i] = 'A'; // *tablero2 + i
	}
	char **tablero3 = new char[ancho][alto];
	char **tablero9;
	tablero9 = tablero3;
	delete [][] tablero3;

	char tablero6[20][20];
	char tablero8[20][20];

	tablero8 = tablero6;

	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			tablero6[i][j] = 'B'; // **tablero3;
		}
	}


	BatallaDigital batallaDigital
	inicializar(batallaDigital);
	jugar(batallaDigital);
	terminar(batallaDigital);
}


