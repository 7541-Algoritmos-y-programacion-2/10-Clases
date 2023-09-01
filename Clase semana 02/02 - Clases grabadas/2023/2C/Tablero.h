/*
 * Tablero.h
 *
 *  Created on: 31/08/2023
 *      Author: algo2
 */

#ifndef TABLERO_H_
#define TABLERO_H_

//static const int ANCHO = 10;
//static const int ALTO = 10;

typedef struct {
	Registro ** matriz;
	int ancho;
	int alto;
} Tablero;

Tablero * inicializarTablero(int ancho, int alto);


#endif /* TABLERO_H_ */
