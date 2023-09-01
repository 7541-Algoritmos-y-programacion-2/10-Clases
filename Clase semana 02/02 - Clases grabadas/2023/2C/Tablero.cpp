/*
 * Tablero.cpp
 *
 *  Created on: 31/08/2023
 *      Author: algo2
 */

#include "Tablero.h"

Tablero * inicializarTablero(int ancho, int alto) {
	Tablero * tablero = new Tablero();
	tablero->matriz = new Registro[ancho][alto];
	for(int numeroDeFila = 0; numeroDeFila < tablero->ancho; numeroDeFila++) {
		for(int columna = 0; columna < tablero->alto; columna++) {
			//inicializar registro
		}
	}
	return tablero;
}

