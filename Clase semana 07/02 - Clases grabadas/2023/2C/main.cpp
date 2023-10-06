
#include "Tablero.h"
#include <iostream>

int main() {
	{ //Caso de tablero con listas
		Tablero * tablero = new Tablero(3,3);
		tablero->getCasillero(2, 2)->setFicha('A');

		for( unsigned int i = 1; i<= tablero->getAncho(); i++) {
			for( unsigned int j = 1; j<= tablero->getAlto(); j++) {
				std::cout << tablero->getCasillero(i, j)->getFicha();
			}
		}

		delete tablero;
	}

	//Terminar el TDA Tablero, Casillero y main
	//Hacerlo para 3 dimensiones
}
