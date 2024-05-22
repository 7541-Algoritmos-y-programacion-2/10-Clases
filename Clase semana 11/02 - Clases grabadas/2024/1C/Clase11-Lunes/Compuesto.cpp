/*
 * Compuesto.cpp
 *
 *  Created on: 18/05/2024
 *      Author: algo2
 */


#include "Compuesto.h"


Compuesto::Compuesto(std::string nombre, Unidad unidadDeMedida){
	this->nombre = nombre;
	this->unidadDeMedida = unidadDeMedida;
	this->cantidad = 0;
}


std::string Compuesto::obtenerNombre(){
	return this->nombre;
}


Unidad Compuesto::obtenerUnidad(){
	return this->unidadDeMedida;
}


float Compuesto::obtenerCantidad(){
	return this->cantidad;
}


void Compuesto::cambiarCantidad(float cantidad){
	this->cantidad = cantidad;
}
