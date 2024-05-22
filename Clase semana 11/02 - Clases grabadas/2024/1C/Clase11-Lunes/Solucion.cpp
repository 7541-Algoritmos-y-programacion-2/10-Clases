/*
 * Solucion.cpp
 *
 *  Created on: 18/05/2024
 *      Author: algo2
 */



#include "Solucion.h"

Solucion::Solucion(std::string codigo){
	this->codigo = codigo;

	Lista<Compuesto*> *compuestos = new Lista<Compuesto*>();
	this->compuestos = NULL;
}



std::string Solucion::obtenerCodigo(){
	return codigo;
}



void Solucion::agregarCompuesto(Compuesto *compuesto){


	this->compuestos->agregar(compuesto);
}



//Lista<Compuesto*>* Solucion::obtenerCompuestos(){

	//Lista<Compuesto*> *compuestos;
	//return this->compuestos;
//}
