/*
 * Tablero.cpp
 *
 *  Created on: 20/10/2022
 *      Author: algo2
 */

#include "Tablero.h"

Tablero::Tablero(unsigned int filas, unsigned int columnas) {
	this->tablero = new Lista<Lista<Casillero *> *>();

	for(int i = 0; i < filas; i++) {
		Lista<Casillero *> * temp = new Lista<Casillero *>();
		for(int j = 0; j < columnas; j++) {
			temp->agregar(new Casillero());
		}
		this->tablero->agregar(temp);
	}
}

Tablero::~Tablero() {
	this->tablero->iniciarCursor();
	while (this->tablero->avanzarCursor()) {
		Lista<Casillero *> * temp = this->tablero->obtenerCursor();
		temp->iniciarCursor();
		while (temp->avanzarCursor()) {
			delete temp->obtenerCursor();
		}
		delete temp;
	}
	delete this->tablero;
}

int Tablero::getCantidadDeFilas() {
	this->tablero->contarElementos();
}

int Tablero::getCantidadDeColumnas() {
	this->tablero->obtener(1)->contarElementos();
}

Casillero * Tablero::getCasillero(unsigned int i, unsigned int j) {
	return this->tablero->obtener(i)->obtener(j);
}

