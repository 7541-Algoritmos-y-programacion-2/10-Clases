/*
 * Tablero3D.cpp
 *
 *  Created on: 11 oct. 2023
 *      Author: gonzalo
 */

#include "Tablero3D.h"

Tablero3D::Tablero3D(unsigned int ancho, unsigned int alto, unsigned int profundidad) {
	this->validarAnchoLargoYProfundidad(ancho, alto, profundidad);
	this->tablero3D = new Lista<Lista<Lista<Casillero3D *> *> *>();
	this->ancho = ancho;
	this->alto = alto;
	this->profundidad = profundidad;
	for(unsigned int i = 1; i <= profundidad; i++) {
		Lista<Lista<Casillero3D *> *> *capa = new Lista<Lista<Casillero3D *> *>();
		for(unsigned int j = 1; j <= ancho; j++) {
			Lista<Casillero3D *> *fila = new Lista<Casillero3D *>();
			for(unsigned int k = 1; k <= alto; k++) {
				fila->agregarElemento(new Casillero3D(i, j, k));
			}
			capa->agregarElemento(fila);
		}
		this->tablero3D->agregarElemento(capa);
	}
}

Tablero3D::~Tablero3D() {
	this->tablero3D->iniciarCursor();
	while(this->tablero3D->avanzarCursor()) {
		Lista<Lista<Casillero3D *> *> *capa = this->tablero3D->obtenerCursor();
		capa->iniciarCursor();
		while(capa->avanzarCursor()) {
			Lista<Casillero3D *> *fila = capa->obtenerCursor();
			fila->iniciarCursor();
			while(fila->avanzarCursor()) {
				delete fila->obtenerCursor();
			}
			delete fila;
		}
		delete capa;
	}
	delete this->tablero3D;
}

void Tablero3D::validarAnchoLargoYProfundidad(unsigned int ancho, unsigned int alto, unsigned int profundidad) {
	if(ancho < 1) {
		throw "El ancho ingresado es un numero no valido";
	}
	if(alto < 1) {
		throw "El alto ingresado es un numero no valido";
	}
	if(profundidad < 1) {
		throw "La profundidad ingresada es un numero no valido";
	}
}

void Tablero3D::validarCoordenadaCasillero(unsigned int x, unsigned int y, unsigned int z){
	if(x < 1 || x > this->ancho) {
		throw "La coordenada x esta mal ingresada";
	}
	if(y < 1 || y > this->alto) {
		throw "La coordenada y esta mal ingresada";
	}
	if(z < 1 || z > this->profundidad) {
		throw "La coordenada z esta mal ingresada";
	}
}

unsigned int Tablero3D::getAncho() {
	return this->ancho;
}

unsigned int Tablero3D::getAlto() {
	return this->alto;
}

unsigned int Tablero3D::getProfundidad() {
	return this->profundidad;
}

Casillero3D *Tablero3D::getCasillero(unsigned int z, unsigned int x, unsigned int y) {
	this->validarCoordenadaCasillero(x, y, z);
	return this->tablero3D->obtenerElemento(z)->obtenerElemento(x)->obtenerElemento(y);
}

