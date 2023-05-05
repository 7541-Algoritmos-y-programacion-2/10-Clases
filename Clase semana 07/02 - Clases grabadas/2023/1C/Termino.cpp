/*
 * Termino.cpp
 *
 *  Created on: 27/04/2023
 *      Author: algo2
 */

#include "Termino.h"
#include <math.h>

Termino::Termino(double coeficiente, unsigned int grado) {
	this->coeficiente = coeficiente;
	this->grado = grado;
}

Termino::~Termino() {}

unsigned int Termino::getGrado() {
	return this->grado;
}

double Termino::getCoeficiente() {
	return this->coeficiente;
}

void Termino::setGrado(unsigned int grado) {
	this->grado = grado;
}

void Termino::setCoeficiente(double coeficiente) {
	this->coeficiente = coeficiente;
}

double Termino::evaluar(double valor) {
	if (this->grado == 0) {
		return this->coeficiente;
	}
	return this->coeficiente * pow(valor, this->grado);
}

static  Termino * Termino::crearTermino(double coeficiente, unsigned int grado) {
	Termino * termino = new Termino(coeficiente, grado);
	termino->evaluar(3);
	return termino;
}
