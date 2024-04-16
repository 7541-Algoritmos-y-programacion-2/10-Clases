/*
 * Lista.cpp
 *
 *  Created on: 15/04/2024
 *      Author: algo2
 */

#include "Lista.h"

Lista::Lista() {
	this->tope = 0;
}

Lista::~Lista() {}

void Lista::insertar(char dato) {
	if (!this->estaLlena()) {
		this->datos[this->tope++] = dato;
	}
}

bool Lista::estaLlena() {
	return this->tope == MAX;
}

bool Lista::estaVacia() {
	return this->tope == 0;
}

char Lista::obtenerDato(int posicion) {
	//validar
	return this->datos[posicion];
}

