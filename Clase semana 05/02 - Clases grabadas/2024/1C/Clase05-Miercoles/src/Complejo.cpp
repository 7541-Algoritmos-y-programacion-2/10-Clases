/*
 * Complejo.cpp
 *
 *  Created on: 03/04/2024
 *      Author: algo2
 */

#include "Complejo.h"
#include <iostream>

Complejo::Complejo() {
	cantidadDeComplejos++;
	this->parteReal = 0;
	this->parteImaginaria = 0;
}

Complejo::Complejo(Complejo * complejo) {
	cantidadDeComplejos++;
	validar(complejo);
	this->parteReal = complejo->parteReal;
	this->parteImaginaria = complejo->parteImaginaria;
}

Complejo::Complejo(double parteReal, double parteImaginaria) {
	cantidadDeComplejos++;
	this->parteReal += parteReal;
	this->setParteImaginaria(parteImaginaria);
}

Complejo::~Complejo() {
}

double Complejo::getParteImaginaria() {
	return parteImaginaria;
}

void Complejo::setParteImaginaria(double imaginaria) {
	this->parteImaginaria = imaginaria;
}

double Complejo::getParteReal() {
	return parteReal;
}

void Complejo::setParteReal(double parteReal) {
	this->parteReal = parteReal;
}

void Complejo::validar(Complejo * complejo) {
	if (complejo == NULL) {
		throw "El complejo esta vacio";
	}
}

Complejo * Complejo::sumar(Complejo * complejo) {
	validar(complejo);
	Complejo * resultado = new Complejo();
	resultado->parteReal = this->parteReal + complejo->parteReal;
	resultado->parteImaginaria = this->parteImaginaria + complejo->parteImaginaria;
	return resultado;
}

Complejo * Complejo::duplicar() {
	Complejo * resultado = new Complejo();
	resultado->parteReal = this->parteReal;
	resultado->parteImaginaria = this->parteImaginaria;
	return resultado;

}

void Complejo::sumarse(Complejo * complejo)  {
	this->parteReal += complejo->parteReal;
	this->parteImaginaria += complejo->parteImaginaria;
}

std::string Complejo::imprimir() {
	std::string resultado = "Parte real: ";
	resultado += this->getParteReal();
	return resultado;
}

Complejo * Complejo::sumarComplejos(Complejo * termino1, Complejo * termino2) {
	Complejo * resultado = new Complejo();
	resultado->parteReal = termino1->parteReal + termino2->parteReal;
	resultado->parteImaginaria = termino1->parteImaginaria + termino2->parteImaginaria;
	return resultado;
}
