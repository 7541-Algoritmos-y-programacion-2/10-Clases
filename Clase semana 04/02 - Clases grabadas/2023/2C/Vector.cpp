/*
 * Vector.cpp
 *
 *  Created on: 14/09/2023
 *      Author: algo2
 */

#include "Vector.h"

Vector::Vector(unsigned int longitud) {
	if (longitud <= 0) {
		throw "La longitud debe ser mayor a 0";
	}
	this->longitud = longitud;
	this->valores = new int[longitud];
	for(int i = 0; i < this->longitud; i++) {
		this->valores[i] = 0;
	}
}

Vector::~Vector() {
	delete [] this->valores;
}

void Vector::setValor(unsigned int indice, int valor) {
	validarLongitud(indice);
	this->valores[indice -1] = valor;
}

int Vector::getValor(unsigned int indice) {
	validarLongitud(indice);
	return this->valores[indice -1];
}

unsigned int Vector::getLongitud() {
	return this->longitud;
}

void Vector::validarLongitud(unsigned int longitud) {
	if (longitud < 1) {
		throw "El indice debe ser mayor o igual a 1";
	}
	if (longitud > this->longitud) {
		throw "El indice debe ser menor o igual a longitud";
	}
}

