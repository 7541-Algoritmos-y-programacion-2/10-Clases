/*
 * Mesa.cpp
 *
 *  Created on: 14/10/2022
 *      Author: algo2
 */

#include "Mesa.h"

Mesa::Mesa(unsigned int numero, unsigned int cantidadMaximaDeComensales) {
	if (numero <= 0) {
		throw "El numero de la mesa no puede ser 0";
	}
	if (cantidadMaximaDeComensales <= 0) {
		throw "La cantidad maxima de comensales no puede ser 0";
	}
	this->numero = numero;
	this->cantidadMaximaDeComensales = cantidadMaximaDeComensales;
	inicializar();
}

Mesa::~Mesa() {}

unsigned int Mesa::getNumero() {
	return this->numero;
}

unsigned int Mesa::getCantidadMaximaDeComensales(){
	return this->cantidadMaximaDeComensales;
}

unsigned int Mesa::getCantidadActualDeComensales() {
	return this->cantidadActualDeComensales;
}

unsigned int Mesa::adicionarComensales(unsigned int cantidadAAdicionar) {
	if (cantidadAAdicionar <= 0) {
		throw "La cantidad debe ser mayor a 0";
	}
	if (this->getCantidadDeLugaresLibres() < cantidadAAdicionar) {
		throw "No hay lugar para " + cantidadAAdicionar + " lugares en la mesa";
	}
	this->cantidadActualDeComensales += cantidadAAdicionar;
}

unsigned int Mesa::getCantidadDeLugaresLibres() {
	return this->cantidadMaximaDeComensales - this->cantidadActualDeComensales;
}

void Mesa::adicionarMonto(double monto) {
	if (monto <= 0) {
		throw "El monto debe ser mayor a 0";
	}
	if (this->estaVacia()) {
		throw "La mesa esta vacia y no se puede abrir";
	}
	this->montoActualConsumido += monto;
	this->estado = Abierta;
}

bool Mesa::estaVacia() {
	return this->cantidadActualDeComensales == 0;
}

double Mesa::cerrarMesa() {
	if (!this->estaAbierta()) {
		throw "La mesa debe estar abierta";
	}
	double monto = this->montoActualConsumido;
	inicializar();
	return monto;
}

bool Mesa::estaAbierta() {
	return this->estado == Abierta;
}

void Mesa::inicializar() {
	this->estado = Cerrada;
	this->montoActualConsumido = 0;
	this->cantidadActualDeComensales = 0;
}
