/*
 * Tablero.h
 *
 *  Created on: 17/03/2023
 *      Author: algo2
 */

#ifndef TABLERO_H_
#define TABLERO_H_
using namespace std; //no se puede

static const int ANCHODELTABLERO = 20;
static const int ALTODELTABLERO = 20;

enum TipoDeCasillero {
	BLANCO,
	JUGADOR1,
	JUGADOR2,
	MINA,
	INACTIVA
};

void inicializarTablero(TipoDeCasillero tablero[ANCHODELTABLERO][ALTODELTABLERO]);

#endif /* TABLERO_H_ */
