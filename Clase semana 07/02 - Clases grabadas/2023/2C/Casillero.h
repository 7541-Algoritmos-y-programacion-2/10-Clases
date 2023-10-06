/*
 * Casillero.h
 *
 *  Created on: 05/10/2023
 *      Author: algo2
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_

class Casillero {
private:
	char ficha;
	unsigned int x;
	unsigned int y;

public:
	/**
	 * pre:
	 * post:
	 */
	Casillero(unsigned int x, unsigned int y);

	/**
	 * pre:
	 * post:
	 */
	virtual ~Casillero();

	/**
	 * pre:
	 * post:
	 */
	unsigned int getX();

	/**
	 * pre:
	 * post:
	 */
	unsigned int getY();

	/**
	 * pre:
	 * post:
	 */
	char getFicha();

	/**
	 * pre:
	 * post:
	 */
	void setFicha(char ficha);
};

#endif /* CASILLERO_H_ */
