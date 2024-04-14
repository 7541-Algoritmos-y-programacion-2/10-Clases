/*
 * Complejo.cpp
 *
 *  Created on: 08/04/2024
 *      Author: algo2
 */

#include "Complejo.h"
#include <iostream>

Complejo::Complejo() {
	this->parteReal = 0.0;
	this->parteImaginaria = 0.0;
	cantidadDeComplejos++;
}

Complejo::Complejo(Complejo &complejo) {
	this->parteReal = complejo.parteReal;
	this->parteImaginaria = complejo.parteImaginaria;
}

Complejo * Complejo::sumar(Complejo *&termino1, Complejo *&termino2) {
	Complejo * total = new Complejo(termino1->getParteReal(), termino1->getParteImaginaria());
	return total->sumar(termino2);
}

Complejo::Complejo(double parteReal, double parteImaginaria) {
	this->setParteReal(parteReal);
	this->parteImaginaria = parteImaginaria;
	cantidadDeComplejos++;
}

Complejo::~Complejo() {}

double Complejo::getParteImaginaria() {
	return this->parteImaginaria;
}

double Complejo::getParteReal() {
	return this->parteReal;
}

void Complejo::setParteImaginaria(double parteImaginaria) {
	this->parteImaginaria = parteImaginaria;
}

void Complejo::setParteReal(double parteReal) {
	this->parteReal = parteReal;
}

Complejo * Complejo::sumar(Complejo * complejo) {
	validar(complejo);
	this->parteReal += complejo->parteReal;
	this->parteImaginaria += complejo->parteImaginaria;
	return this;
}

void Complejo::validar(Complejo * &complejo) {
	if (complejo == NULL) {
		throw "EL parametro no puede ser nulo";
	}
}
