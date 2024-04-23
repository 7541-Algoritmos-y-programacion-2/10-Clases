/*
 * Nodo.cpp
 *
 *  Created on: 22/04/2024
 *      Author: algo2
 */

#include "Nodo.h"
#include <iostream>

Nodo::Nodo(int dato) {
	this->dato = dato;
	this->siguiente = NULL;
}

Nodo::~Nodo() {}


int Nodo::getDato() {
	return this->dato;
}

void Nodo::setDato(int dato) {
	this->dato = dato;
}

const Nodo* Nodo::getSiguiente() {
	return this->siguiente;
}

void setSiguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}

