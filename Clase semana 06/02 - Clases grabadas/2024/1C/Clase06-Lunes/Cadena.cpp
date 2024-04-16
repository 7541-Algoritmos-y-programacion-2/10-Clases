/*
 * Cadena.cpp
 *
 *  Created on: 15/04/2024
 *      Author: algo2
 */

#include "Cadena.h"
#include <iostream>

#include "Eslabon.h"

Cadena::Cadena(unsigned int cantidadMaximaDeEslabones, double ancho, ModoDeTrabajo modoDeTrabajo) {
	if (cantidadMaximaDeEslabones < 1) {
		throw "Debe tener al menos 1 eslabon";
	}
	if (ancho > 0) {
		throw "Debe tener ancho mayor a 0";
	}
	this->eslabones = new Eslabon*[cantidadMaximaDeEslabones];
	for(unsigned int i = 0; i < cantidadMaximaDeEslabones; i++) {
		this->eslabones[i] = NULL;
	}
	this->eslabones[0] = new Eslabon(1, ancho, modoDeTrabajo);
	this->cantidadMaximaDeEslabones = cantidadMaximaDeEslabones;
	this->modoDeTrabajo = modoDeTrabajo;
}

Cadena::~Cadena() {
	int cantidad = getCantidadDeEslabones();
	for(int i = 0; i < cantidad; i++) {
		delete this->eslabones[i];
	}
	delete [] this->eslabones;
}

double Cadena::getAncho() {
	return this->eslabones[0]->getAncho();
}

double Cadena::getLongitud() {
	double resultado = 0;
	for(unsigned int i = 0; i < this->getCantidadDeEslabones(); i++) {
		resultado += this->eslabones[i]->getLargo();
	}
	return resultado;
}

unsigned int Cadena::getCantidadDeEslabones() {
	for(unsigned int i = 0; i < this->cantidadMaximaDeEslabones; i++) {
		if (this->eslabones[i] == NULL) {
			return i;
		}
	}
	return this->cantidadMaximaDeEslabones;
}

void Cadena::agregar(Eslabon * eslabon) {
	if (eslabon == NULL) {
		throw "El eslabon no es valido";
	}
	if (eslabon->getModoDeTrabajo() != this->modoDeTrabajo) {
		throw "El eslabon tiene un modo de trabajo distinto";
	}
	if (eslabon->getAncho() != this->getAncho()) {
		throw "El ancho no puede ser distinto";
	}
	if (!this->hayLugar()) {
		throw "La cadena esta llena";
	}
	this->eslabones[getCantidadDeEslabones()] = eslabon;
}

bool Cadena::hayLugar() {
	return this->getCantidadDeEslabones() < this->cantidadMaximaDeEslabones;
}

Eslabon * Cadena::retirar() {
	if (this->getCantidadDeEslabones() <= 1) {
		throw "No se puede quitar el ultimo eslabon";
	}
	Eslabon * resultado = this->eslabones[getCantidadDeEslabones() - 1];
	this->eslabones[getCantidadDeEslabones() - 1] = NULL;
	return resultado;
}

Eslabon * Cadena::getEslabon(unsigned int posicion) {
	if (posicion < 1) {
		throw "La posicion debe ser mayor a 1";
	}
	if (posicion > getCantidadDeEslabones()) {
		throw "La posicion no debe superar la cantidad de eslabones de la cadena";
	}
	return this->eslabones[posicion-1];
}
