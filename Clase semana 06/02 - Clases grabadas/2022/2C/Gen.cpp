/*
 * Gen.cpp
 *
 *  Created on: 30/09/2022
 *      Author: algo2
 */

#include "Gen.h"

Gen::Gen(unsigned int maximoDeCargaGentica) {
	verificar(maximoDeCargaGentica, 0);
	this->cargaGentica = 0;
	this->maximoDeCargaGentica = maximoDeCargaGentica;
}

Gen::Gen(unsigned int maximoDeCargaGentica, unsigned int cargaGentica) {
	verificar( maximoDeCargaGentica, cargaGentica);
	this->maximoDeCargaGentica = maximoDeCargaGentica;
	this->cargaGentica = cargaGentica;
}

Gen::~Gen() {}

unsigned int Gen::getMaximoDeCargaGentica(){
	return this->maximoDeCargaGentica;
}

unsigned int Gen::getCargaGentica() {
	return this->cargaGentica;
}

void Gen::setCargaGentica(unsigned int cargaGentica) {
	verificar(this->maximoDeCargaGentica, cargaGentica);
	this->cargaGentica = cargaGentica;
}

void Gen::verificar(unsigned int maximoDeCargaGentica, unsigned int cargaGentica) {
	if (maximoDeCargaGentica < 0) {
		//dar error con excepciones
	}
	if (cargaGentica < 0) {
		//dar error con excepciones
	}
	if (maximoDeCargaGentica < cargaGentica) {
		//dar error con excepciones
	}
}
