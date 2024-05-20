/*
 * Vagon.cpp
 *
 *  Created on: 15/05/2024
 *      Author: algo2
 */

#include "Vagon.h"

Vagon::Vagon(double capacidadMaximaDeCarga) {
	//validar
	if (capacidadMaximaDeCarga <=0) {
		throw "Error";
	}
	this->capacidadMaximaDeCarga = capacidadMaximaDeCarga;
	this->cargaActual = 0;
}

Vagon::~Vagon() {}

double Vagon::getCapacidadMaximaDeCarga(){
	return capacidadMaximaDeCarga;
}

double Vagon::getCargaActual(){
	return cargaActual;
}

double Vagon::getCargaRestante() {
	return this->capacidadMaximaDeCarga - this->cargaActual;
}

double Vagon::cargar(double carga) {
	double restante = 0;
	if (getCargaRestante() < carga) {
		restante = carga - getCargaRestante();
		this->cargaActual = this->capacidadMaximaDeCarga;
	} else {
		this->cargaActual += carga;
	}
	return restante;
}

void Vagon::descargar(double carga) {
	if (getCargaActual() < carga) {
		throw "No hay esa carga";
	}
	this->cargaActual -= carga;
}

bool Vagon::estaVacio() {
	return (this->getCargaActual() == 0);
}
