/*
 * Tablero.h
 *
 *  Created on: 05/10/2023
 *      Author: algo2
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Lista.h"
#include "Casillero.h"

class Tablero {
private:
	Lista<Lista<Casillero *> *> * casilleros;
	unsigned int ancho;
	unsigned int alto;

public:
	/**
	 * pre:
	 * post:
	 */
	Tablero(unsigned int ancho, unsigned int alto);

	/**
	 * pre:
	 * post:
	 */
	virtual ~Tablero();

	/**
	 * pre:
	 * post:
	 */
	unsigned int getAlto();

	/**
	 * pre:
	 * post:
	 */
	unsigned int getAncho();


	Casillero * getCasillero(unsigned int x, unsigned int y);
};

#endif /* TABLERO_H_ */
