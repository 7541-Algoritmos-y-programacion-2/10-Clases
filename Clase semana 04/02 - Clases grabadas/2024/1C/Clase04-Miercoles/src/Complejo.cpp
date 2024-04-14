/*
 * Complejo.cpp
 *
 *  Created on: 03/04/2024
 *      Author: algo2
 */

#include "Complejo.h"
#include <iostream>

Complejo::Complejo() {
	this->parteReal = 0;
	this->parteImaginaria = 0;
	this->letra = new char;
}

//Complejo Complejo::sumar1(Complejo c1, Complejo c2) {
Complejo * Complejo::sumar1(Complejo * c1) {
	return NULL;
}

Complejo::Complejo(Complejo &complejo) {
	this->parteReal = complejo.parteReal;
	this->parteImaginaria = complejo.parteImaginaria;
}

Complejo::Complejo(double parteReal, double parteImaginaria) {
	this->parteReal += parteReal;
	this->setParteImaginaria(parteImaginaria);
}


Complejo::~Complejo() {
	delete letra;
}

double Complejo::getParteImaginaria() {
	return parteImaginaria;
}

void Complejo::setParteImaginaria(double imaginaria) {
	if (imaginaria <= 0) {
		throw "No puede ser negativa";
	}
	this->parteImaginaria = imaginaria;
}

double Complejo::getParteReal() {
	return parteReal;
}

void Complejo::setParteReal(double parteReal) {
	this->parteReal = parteReal;
}

Complejo Complejo::sumar(Complejo &complejo) {
	Complejo resultado(0,0);
	resultado.parteReal = this->parteReal + complejo.parteReal;
	resultado.parteImaginaria = this->parteImaginaria + complejo.parteImaginaria;
	return resultado;
}

void Complejo::sumarse(Complejo complejo1)  {
	this->parteReal += complejo1.parteReal;
	this->parteImaginaria += complejo1.parteImaginaria;
}
