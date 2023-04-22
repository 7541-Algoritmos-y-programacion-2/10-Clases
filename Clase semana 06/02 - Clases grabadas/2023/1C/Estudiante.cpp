/*
 * Estudiante.cpp
 *
 *  Created on: 14/04/2023
 *      Author: algo2
 */

#include "Estudiante.h"

//#include <string>

Estudiante::Estudiante(std::string apellido, std::string nombre, unsigned int padron) {
	if (apellido == "") {
		throw "El codigo no puede ser vacio";
	}
	this->apellido = apellido;
	this->nombre = nombre;
	this->padron = padron;
}

Estudiante::~Estudiante() {}

std::string Estudiante::getNombreCompleto() {
	return this->apellido + " " + this->nombre;
}

std::string Estudiante::getNombre() {
	return this->nombre;
}

std::string Estudiante::getApellido() {
	return this->apellido;
}

unsigned int Estudiante::getPadron() {
	return this->padron;
}
