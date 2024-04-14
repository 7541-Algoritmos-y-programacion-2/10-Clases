/*
 * ComplejoEnC.cpp
 *
 *  Created on: 03/04/2024
 *      Author: algo2
 */

#include "ComplejoEnC.h"

ComplejoEnC construirComplejoEnC() {
	ComplejoEnC complejoEnC;
	complejoEnC.imaginaria = 2;
	complejoEnC.real = 2;
	return complejoEnC;
}

ComplejoEnC sumar(ComplejoEnC complejo1, ComplejoEnC complejo2) {
	ComplejoEnC resultado;
	resultado.real = complejo1.real + complejo2.real;
	resultado.imaginaria = complejo1.imaginaria + complejo2.imaginaria;
	return resultado;
}


void setParteReal(ComplejoEnC &complejo, double real) {
	complejo.real = real;
}


