/*
 * Examen.cpp
 *
 *  Created on: 29/09/2023
 *      Author: algo2
 */

#include "Examen.h"

Examen::Examen(unsigned int cantidadDeEjercicios) {
	this->ejercicios = new Vector<Ejercicio *>(cantidadDeEjercicios);
	for(int i = 1; i <= cantidadDeEjercicios; i++ ) {
		this->ejercicios->setDato(i, new Ejercicio());
	}
}

Examen::~Examen() {
	//El vector eliminar los Ejercicios en el destructor
	//Cuidado, la version del git para el parcial hay que recorrer y eliminar
	delete this->ejercicios;
}

void Examen::validarIndice(unsigned int indice) {
	if (indice < 1) {
		throw "El indice debe ser mayor o igual a 1";
	}
	if (indice > this->ejercicios->getLongitud()) {
		throw "El indice debe ser menor o igual a longitud";
	}
}

int Examen::getCantidadDeEjercicios() {
	return this->ejercicios->getLongitud();
}

int Examen::getCantidadDeEjerciciosCorregidos() {
	int resultado = 0;
	for(int i = 1; i <= this->ejercicios->getLongitud(); i++) {
		if (this->ejercicios->getDato(i)->estaCorregido()) {
			resultado++;
		}
	}
	return resultado;
}

Ejercicio * Examen::getEjercicio(int indice) {
	validarIndice(indice);
	return this->ejercicios->getDato(indice);
}

bool Examen::estaCorregido() {
	for(int i = 1; i <= this->ejercicios->getLongitud(); i++) {
		if (!this->ejercicios->getDato(i)->estaCorregido()) {
			return false;
		}
	}
	return true;
}

double Examen::getPuntaje() {
	if (!this->estaCorregido()) {
		throw "Falta corregir el ejercicio";
	}
	double resultado = 0.0;
	for(int i = 1; i <= this->ejercicios->getLongitud(); i++) {
		resultado += this->ejercicios->getDato(i)->getPuntaje();
	}
	return resultado;
}

double Examen::getPuntajePromedio() {
	return this->getPuntaje() / this->getCantidadDeEjercicios();
}

double Examen::getPorcentajeDeCorreccion() {
	if (!this->estaCorregido()) {
		throw "Falta corregir el ejercicio";
	}
	double resultado = 0.0;
	for(int i = 1; i <= this->ejercicios->getLongitud(); i++) {
		resultado += this->ejercicios->getDato(i)->getPorcentajeDeCorreccion();
	}
	return resultado / this->getCantidadDeEjercicios();
}
