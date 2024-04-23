/*
 * Lista.cpp
 *
 *  Created on: 22/04/2024
 *      Author: algo2
 */

#include "Lista.h"
#include <iostream>

Lista::Lista() {
	this->primero = NULL;
	this->tamanio = 0;
}

Lista::~Lista() {
//hay delete del nodo, no del dato
}

bool Lista::estaVacia() {
	//return (this->primero == NULL);
	return (this->tamanio == 0);
}

unsigned int Lista::getTamanio() {
	return this->tamanio;
}

void Lista::agregar(int elemento) {
	this->agregar(elemento, this->getTamanio() + 1);
}

void Lista::agregar(int elemento, unsigned int posicion) {
	validarPosicion(posicion);
    Nodo * nuevo = new Nodo(elemento);
    if (posicion == 1) {
    	nuevo->setSiguiente( this->primero);
    	this->primero = nuevo;
    } else {
    	Nodo * anterior = this->obtenerNodo(posicion -1);
    	nuevo->setSiguiente( anterior->getSiguiente());
    	anterior->setSiguiente( nuevo );
    }
    this->tamanio++;
}

Nodo * Lista::obtenerNodo(unsigned int posicion) {
	//validarPosicion(posicion);
	Nodo * actual = this->primero;
	for(unsigned int i = 1; i < posicion; i++) {
		actual = actual->getSiguiente();
	}
	return actual;
}

void Lista::validarPosicion(unsigned int posicion) {
    if ((posicion < 1) ||
    	(posicion > this->tamanio + 1)) {
    	throw "La posicion debe estar entre 1 y tamaño + 1";
    }
}

void Lista::remover(unsigned int posicion) {
	validarPosicion(posicion);
	Nodo * removido;
	if (posicion == 1) {
		removido = this->primero;
		this->primero = removido->getSiguiente();
	} else {
		Nodo * anterior = this->obtenerNodo(posicion -1);
		removido = anterior->getSiguiente();
		anterior->setSiguiente( removido->getSiguiente());
	}
	delete removido;
	this->tamanio--;
}

int Lista::obtener(unsigned int posicion) {
	validarPosicion(posicion);
	return this->obtenerNodo(posicion)->getDato();
}

void Lista::cambiar(int elemento, unsigned int posicion) {
	validarPosicion(posicion);
	this->obtenerNodo(posicion)->setDato(elemento);
}

