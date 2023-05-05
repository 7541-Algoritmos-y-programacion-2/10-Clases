/*
 * Polinomio.cpp
 *
 *  Created on: 27/04/2023
 *      Author: algo2
 */

#include "Polinomio.h"

#include <stddef.h>
//#include <iostream>

#include "Termino.h"

Polinomio::Polinomio(unsigned int cantidadMaximaDeTerminos) {
	if (cantidadMaximaDeTerminos == 0) {
		throw "La cantidad de terminos debe ser mayor a 0";
	}
	this->terminos = new Vector<Termino *>(cantidadMaximaDeTerminos);
	agregarTermino( new Termino(1, 0));
}

Polinomio::~Polinomio() {
	for(int i = 1; i <= this->terminos->getLongitud(); i++) {
		delete this->terminos->obtener(i);
	}
	delete this->terminos;
}

double Polinomio::evaluar(double valor) {
	double resultado = 0;
	for(int i = 1; i <= this->terminos->getLongitud(); i++) {
		resultado += this->terminos->obtener(i)->evaluar(valor);
	}
	return resultado;
}

void Polinomio::agregarTermino(Termino * termino) {
	if (termino == NULL) {
		throw "El termino no puede ser vacio";
	}

	if (this->existeElTermino(termino->getGrado())) {
		throw "Ya existe el termino";
	}
	this->terminos->agregar(termino);
}

void Polinomio::removerTermino(unsigned int grado) {
	validarGrado(grado);
	for(int i = 1; i <= this->terminos->getLongitud(); i++) {
		if ((this->terminos->obtener(i) != NULL) &&
		    (this->terminos->obtener(i)->getGrado() == grado)) {
			delete this->terminos->obtener(i);
			this->terminos->agregar(i, NULL);
		}
	}
}

Termino * Polinomio::getTermino(unsigned int grado) {
	validarGrado(grado);
	for(int i = 1; i <= this->terminos->getLongitud(); i++) {
		if ((this->terminos->obtener(i) != NULL) &&
		    (this->terminos->obtener(i)->getGrado() == grado)) {
			return this->terminos->obtener(i);
		}
	}
}

bool Polinomio::existeElTermino(unsigned int grado) {
	for(int i = 1; i <= this->terminos->getLongitud(); i++) {
		if ((this->terminos->obtener(i) != NULL) &&
		    (this->terminos->obtener(i)->getGrado() == grado)) {
			return true;
		}
	}
	return false;
}

void Polinomio::validarGrado(unsigned int grado) {
	if (!this->existeElTermino(grado)) {
		throw "No existe el termino con el grado " + grado;
	}
}
