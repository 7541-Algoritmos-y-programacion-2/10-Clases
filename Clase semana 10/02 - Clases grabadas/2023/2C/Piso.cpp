/*
 * Piso.cpp
 *
 *  Created on: 26/10/2023
 *      Author: algo2
 */

#include "Piso.h"

Piso::Piso(unsigned int numero) {
	this->numero = numero;
}

Piso::~Piso() {}

unsigned int Piso::getNumero() {
	return this->numero;
}

unsigned int Piso::getCantidadDeVecesVisitado() {
	return this->cantidadDeVecesVisitado;
}

unsigned int Piso::getCantidadDeVecesLlamado() {
	return this->cantidadDeVecesLlamado;
}

void Piso::incrementarCantidadDeVecesVisitado() {
	this->cantidadDeVecesVisitado++;
}

void Piso::incrementarCantidadDeVecesLlamado() {
	this->cantidadDeVecesLlamado++;
}

