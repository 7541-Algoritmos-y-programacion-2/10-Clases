/*
 * Deuda.cpp
 *
 *  Created on: 22/09/2023
 *      Author: algo2
 */

#include "Deuda.h"

Deuda::Deuda(double totalDeDeuda, unsigned int cantidadMaximaDePago) {
	//completar y validar
	this->total = totalDeDeuda;
	this->pagos = new Vector<Pago *>(cantidadMaximaDePago);
}

Deuda::~Deuda() {
	delete this->pagos;
}

