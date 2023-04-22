/*
 * Curso.cpp
 *
 *  Created on: 21/04/2023
 *      Author: algo2
 */

#include "Curso.h"
#include "Estudiante.h"

Curso::Curso(std::string codigo, std::string nombre, unsigned int cupoMaximo) {
	if (codigo == "") {
		throw "El codigo no puede ser vacio";
	}
	if (nombre == "") {
		throw "El nombre no puede ser vacio";
	}
	if (cupoMaximo < 1) {
		throw "El cupo maximo no puede ser 0";
	}
	this->cupoMaximo = cupoMaximo;
	this->codigo = codigo;
	this->nombre = nombre;
	this->inscriptos = new Estudiante*[this->cupoMaximo];
	for(int i = 0; i < this->cupoMaximo; i++) {
		this->inscriptos[i] = NULL;
	}
}

Curso::~Curso() {
	delete [] this->inscriptos;
}

std::string Curso::getNombre() {
	return this->nombre;
}

std::string Curso::getCodigo() {
	return this->codigo;
}

unsigned int Curso::getCupoMaximo() {
	return this->cupoMaximo;
}


Estudiante * Curso::getInscripto(unsigned int numero) {
	validarPosicion(numero);
	return this->inscriptos[numero - 1];
}

int Curso::inscribir(Estudiante * estudiante) {
	if (estudiante == NULL) {
		throw "EL estudiante es invalido";
	}
	this->inscriptos[getCantidadDeInscriptos()] = estudiante;
	return getCantidadDeInscriptos();
}

void Curso::desinscribir(unsigned int numero) {
	validarPosicion(numero);
	this->inscriptos[numero - 1] = NULL;
}

unsigned int Curso::getCantidadDeInscriptos() {
	for(int i = 0; i < this->cupoMaximo; i++) {
		if (this->inscriptos[i] == NULL) {
			return i;
		}
	}
	return this->cupoMaximo;
}

void Curso::validarPosicion(int numero) {
	if (numero < 1) {
		throw "No puede ser menor a 1";
	}
	if (numero > getCantidadDeInscriptos()) {
		throw "No puede ser mayor a cantidad de inscriptos";
	}
}
