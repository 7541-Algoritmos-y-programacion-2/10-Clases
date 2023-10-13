/*
 * Casillero3D.cpp
 *
 *  Created on: 11 oct. 2023
 *      Author: gonzalo
 */

#include "Casillero3D.h"

Casillero3D::Casillero3D(unsigned int z, unsigned int x, unsigned int y) {
	this->validarXYyZ(z, x, y);
	this->x = x;
	this->y = y;
	this->z = z;
	this->ficha = ' ';
}

Casillero3D::~Casillero3D() {
	// TODO Auto-generated destructor stub
}

void Casillero3D::validarXYyZ(unsigned int x, unsigned int y, unsigned z) {
	if(x < 1 || y < 1 || z < 1) {
		throw "Coordenadas fuera de rango";
	}
}

char Casillero3D::getFicha() {
	return this->ficha;
}

void Casillero3D::setFicha(char ficha) {
	this->ficha = ficha;
}
