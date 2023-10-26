/*
 * Ascensor.cpp
 *
 *  Created on: 26/10/2023
 *      Author: algo2
 */

#include "Ascensor.h"

#include <cstddef>
#include <cstdlib>

Ascensor::Ascensor(unsigned int cantidadDePisos) {
	this->pisos = new Vector<Piso *>(cantidadDePisos +1, NULL);
	for(int i = 1; i <= this->pisos->getLongitud(); i++) {
		this->pisos->agregar(i, new Piso(i-1));
	}
	this->pisoActual = this->pisos->obtener(1);
	this->estado = FUNCIONANDO;
	this->cantidadDePisosRecorridos = 0;
}

Ascensor::~Ascensor() {
	for(int i = 1; i <= this->pisos->getLongitud(); i++) {
		delete this->pisos->obtener(i);
	}
	delete this->pisos;
}

Piso * Ascensor::getPisoActual() {
	return this->pisoActual;
}

void Ascensor::validarRangoDePiso(unsigned int numeroDePiso) {
	if (numeroDePiso >= this->pisos->getLongitud()) {
		throw "El numero de piso supera al edificio";
	}
}

void Ascensor::validarFuncionamiento() {
	if (!this->estaEnFuncionamiento()) {
		throw "El ascensor no esta en funcionamiento";
	}
}

unsigned int Ascensor::incrementarCantidadDePisosRecorridos(unsigned int cantidad) {
	this->cantidadDePisosRecorridos += abs(cantidad); //modulo o valor absoluto
	return cantidad;
}

unsigned int Ascensor::mover(unsigned int numeroDePiso) {
	validarRangoDePiso(numeroDePiso);
	validarFuncionamiento();
	Piso * pisoAnterior = this->pisoActual;
	this->pisoActual = this->pisos->obtener(numeroDePiso + 1);
	this->pisoActual->incrementarCantidadDeVecesVisitado();
	return incrementarCantidadDePisosRecorridos(this->pisoActual->getNumero() - pisoAnterior->getNumero());
}

unsigned int Ascensor::llamar(unsigned int numeroDePiso){
	unsigned int resultado = mover(numeroDePiso);
	this->pisos->obtener(numeroDePiso + 1)->incrementarCantidadDeVecesLlamado();
	return resultado;
}

bool Ascensor::estaEnFuncionamiento() {
	return (this->estado == FUNCIONANDO);
}
