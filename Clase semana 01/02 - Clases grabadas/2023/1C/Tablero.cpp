/*
 * Tablero.cpp
 *
 *  Created on: 17/03/2023
 *      Author: algo2
 */

#include "Tablero.h"

void inicializarTablero(TipoDeCasillero tablero[ANCHODELTABLERO][ALTODELTABLERO]) {
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			tablero[i][j] = BLANCO;
		}
	}
}



