/*
 * Restaurante.cpp
 *
 *  Created on: 14/10/2022
 *      Author: algo2
 */

#include "Restaurante.h"
#include <iostream>

Restaurante::Restaurante(unsigned int cantidadDeMesas) {
	if (cantidadDeMesas<= 0) {
		throw "La cantidad de mesas debe ser mayor a 0";
	}
	this->mesas = new Vector<Mesa *>(cantidadDeMesas);
	for(int i = 1; i <= this->mesas->getLongitud(); i++) {
		this->mesas->agregar(i, NULL);
	}
}

Restaurante::~Restaurante() {
	delete this->mesas;
}

unsigned int Restaurante::adicionarMesa(unsigned int cantidadDeComensales) {
	for(unsigned int i = 1; i <= this->mesas->getLongitud(); i++) {
		if (this->mesas->obtener(i) == NULL) {
			this->mesas->agregar(i, new Mesa(i, cantidadDeComensales));
			return i;
		}
	}
	throw "No hay mas lugares para la mesa en este restaurante";
}

unsigned int Restaurante::adicionarComensal(unsigned int numeroDeMesa, unsigned int cantidadDeComensales) {
	return this->mesas->obtener(numeroDeMesa)->adicionarComensales(cantidadDeComensales);
}

void Restaurante::adicionarMonto(unsigned int numeroDeMesa, double monto) {
	return this->mesas->obtener(numeroDeMesa)->adicionarMonto(monto);
}

double Restaurante::cerrarMesa(unsigned int numeroDeMesa) {
	return this->mesas->obtener(numeroDeMesa)->cerrarMesa();
}

unsigned int Restaurante::getCantidadDeComesalesActuales() {
	unsigned int resultado = 0;
	for(unsigned int i = 1; i <= this->mesas->getLongitud(); i++) {
		resultado += this->mesas->obtener(i)->getCantidadActualDeComensales();
	}
	return resultado;
}

unsigned int Restaurante::getCantidadDeComesalesActuales(unsigned int numeroDeMesa) {
	return this->mesas->obtener(numeroDeMesa)->getCantidadActualDeComensales();
}

unsigned int Restaurante::getCapacidadTotalDelRestaurante() {
	unsigned int resultado = 0;
	for(unsigned int i = 1; i <= this->mesas->getLongitud(); i++) {
		resultado += this->mesas->obtener(i)->getCantidadMaximaDeComensales();
	}
	return resultado;
}

bool Restaurante::estaVacio() {
	//return getCantidadDeComesalesActuales() == 0;

	for(unsigned int i = 1; i <= this->mesas->getLongitud(); i++) {
		if (!this->mesas->obtener(i)->estaVacia()) {
			return false;
		}
	}
	return true;
}
