/*
 * Tren.cpp
 *
 *  Created on: 15/05/2024
 *      Author: algo2
 */

#include "Tren.h"

#include <iostream>

Tren::Tren(unsigned int cantidadDeLocomotoras) {
	if (cantidadDeLocomotoras > CantidadMaximaDeLocomotoras) {
		throw "Error";
	}
	if (cantidadDeLocomotoras == 0) {
		throw "Error";
	}
	this->cantidadDeLocomotoras = cantidadDeLocomotoras;
	this->estadoDeTren = DETENIDO;
	this->vagones = new Vector<Vagon *>(this->cantidadDeLocomotoras * CantidadMaximaDeVagonesPorLocomotora, NULL);
}

Tren::~Tren() {
	for(int i = 1; i <= this->vagones->getLongitud(); i++) {
		if (this->vagones->obtener(i) != NULL) {
			delete this->vagones->obtener(i);
		}
	}
	delete this->vagones;
}

bool Tren::estaDetenido() {
	return (this->estadoDeTren == DETENIDO);
}

void Tren::agregarVagon(Vagon * vagon) {
	if (!vagon->estaVacio()) {
		throw "Error";
	}
	if (!estaDetenido()) {
		throw "Error";
	}
	for(int i = 1; i <= this->vagones->getLongitud(); i++) {
		if (this->vagones->obtener(i) != NULL) {
			this->vagones->agregar(i, vagon);
			return;
		}
	}
	throw "No hay mas lugar";
}

double Tren::agregarCarga(double carga) {
	if (!estaDetenido()) {
		throw "Error";
	}
	double restante = carga;
	for(int i = 1; i <= this->vagones->getLongitud(); i++) {
		if (this->vagones->obtener(i) == NULL) {
			return restante;
		}
		restante = this->vagones->obtener(i)->cargar(restante);
	}
	return restante;
}

