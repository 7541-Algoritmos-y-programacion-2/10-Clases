/*
 * Ejercicio.cpp
 *
 *  Created on: 29/09/2023
 *      Author: algo2
 */

#include "Ejercicio.h"

Ejercicio::Ejercicio() {
	this->puntaje = 0;
	this->porcentajeDeCorreccion = 0;
	this->estado = NOCORREGIDO;
}

Ejercicio::~Ejercicio() {}

void Ejercicio::validarPuntaje(double puntaje) {
	if (this->puntaje < 0.0) {
		throw "El puntaje debe ser mayor o igual a 0";
	}
	if (this->puntaje > 10.0) {
		throw "El puntaje debe ser menor o igual a 10";
	}
}

void Ejercicio::validarPorcentaje(double porcentaje) {
	if (porcentaje < 0.0) {
		throw "El porcentaje debe ser mayor o igual a 0";
	}
	if (porcentaje > 100.0) {
		throw "El porcentaje debe ser menor o igual a 100";
	}
}

double Ejercicio::getPuntaje() {
	return this->puntaje;
}

double Ejercicio::getPorcentajeDeCorreccion() {
	return this->porcentajeDeCorreccion;
}

void Ejercicio::puntuar(double puntaje) {
	validarPuntaje(puntaje);
	this->puntaje = puntaje;
	this->porcentajeDeCorreccion = 100.0;
	this->estado = CORREGIDO;
}

void Ejercicio::setPorcentajeDeCorreccion(double porcentajeDeCorreccion) {
	validarPorcentaje(porcentajeDeCorreccion);
	this->porcentajeDeCorreccion = porcentajeDeCorreccion;
}

bool Ejercicio::estaCorregido() {
	return this->estado == CORREGIDO;
}
