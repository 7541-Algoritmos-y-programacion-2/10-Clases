/*
 * Casillero.cpp
 *
 *  Created on: 20/10/2022
 *      Author: algo2
 */

#include "Casillero.h"

Casillero::Casillero() {
	this->ficha = ' ';
}

Casillero::~Casillero() {}

char Casillero::getFicha() {
	return this->ficha;
}
char Casillero::setFicha(char ficha){
	this->ficha = ficha;
}

