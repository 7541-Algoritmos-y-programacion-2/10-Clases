/*
 * VectorDeEnteros.cpp
 *
 *  Created on: 15/09/2023
 *      Author: algo2
 */

#include "VectorDeEnteros.h"

VectorDeEnteros::VectorDeEnteros(unsigned int longitud) {
	if (longitud <= 0) {
		throw "La longitud debe ser mayor a 0";
	}

	this->longitud = longitud;
	this->valores = new int[this->longitud];

	//Inicializo los valores en 0
	for(int i = 0; i < this->longitud; i++) {
		this->valores[i] = 0;
	}
}

VectorDeEnteros::~VectorDeEnteros() {
	delete [] this->valores;
}

void VectorDeEnteros::setDato(unsigned int indice, int valor) {
	validarIndice(indice);
	this->valores[indice-1] = valor;
}

int VectorDeEnteros::getDato(unsigned int indice) {
	validarIndice(indice);
	return this->valores[indice-1];
}

unsigned int VectorDeEnteros::getLongitud() {
	return this->longitud;
}

void VectorDeEnteros::validarIndice(unsigned int indice) {
	if (indice < 1) {
		throw "El indice debe ser 1 o mayor";
	}
	if (indice > this->longitud) {
		throw "El indice debe ser longitud o menor";
	}
}

