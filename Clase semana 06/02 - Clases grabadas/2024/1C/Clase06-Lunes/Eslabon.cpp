/*
 * Eslabon.cpp
 *
 *  Created on: 15/04/2024
 *      Author: algo2
 */

#include "Eslabon.h"

Eslabon::Eslabon(double largo, double ancho, ModoDeTrabajo modoDeTrabajo) {
	this->modoDeTrabajo = modoDeTrabajo;
	this->largo = largo;
	this->ancho = ancho;
}

Eslabon::~Eslabon() {}


double Eslabon::getAncho(){
	return ancho;
}

void Eslabon::setAncho(double ancho) {
	if (this->modoDeTrabajo != MODIFICABLE) {
		throw "No se puede modificar el ancho";
	}
	this->ancho = ancho;
}

double Eslabon::getLargo(){
	return largo;
}

void Eslabon::setLargo(double largo) {
	this->largo = largo;
}

ModoDeTrabajo Eslabon::getModoDeTrabajo() {
	return this->modoDeTrabajo;
}
