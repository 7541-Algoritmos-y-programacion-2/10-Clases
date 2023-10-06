/*
 * Tablero.cpp
 *
 *  Created on: 05/10/2023
 *      Author: algo2
 */

#include "Tablero.h"

Tablero::Tablero(unsigned int ancho, unsigned int alto) {
	//VALIDAR!!!!!!!!!!!!!!
	this->casilleros = new Lista<Lista<Casillero *> *>();
	this->alto = alto;
	this->ancho = ancho;
	for(unsigned int i=1; i <= ancho; i++) {
		Lista<Casillero *> * fila = new Lista<Casillero *>();
		for(unsigned int j=1; j <= alto; j++) {
			fila->agregar(new Casillero(i, j));
		}
		this->casilleros->agregar(fila);
	}
}

Tablero::~Tablero() {
	this->casilleros->iniciarCursor();
	while (this->casilleros->avanzarCursor()) {
		Lista<Casillero *> * fila = this->casilleros->obtenerCursor();
		fila->iniciarCursor();
		while (fila->avanzarCursor()) {
			delete fila->obtenerCursor();
		}
		delete fila;
	}
	delete this->casilleros;
}

Casillero * Tablero::getCasillero(unsigned int x, unsigned int y) {
	//validar
	return this->casilleros->obtener(x)->obtener(y);
}

unsigned int Tablero::getAncho() {
	return this->ancho;
}

unsigned int Tablero::getAlto() {
	return this->alto;
}

