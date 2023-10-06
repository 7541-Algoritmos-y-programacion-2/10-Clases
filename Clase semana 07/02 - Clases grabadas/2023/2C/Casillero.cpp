/*
 * Casillero.cpp
 *
 *  Created on: 05/10/2023
 *      Author: algo2
 */

#include "Casillero.h"

Casillero::Casillero(unsigned int x, unsigned int y) {
	//Validar
	this->x = x;
	this->y = y;
	this->ficha = ' ';
}

Casillero::~Casillero() {
	// TODO Auto-generated destructor stub
}


void Casillero::setFicha(char ficha) {
	this->ficha = ficha;
}

char Casillero::getFicha() {
	return this->ficha;
}
