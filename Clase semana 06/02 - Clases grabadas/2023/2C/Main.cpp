/*
 * Vector.cpp
 *
 *  Created on: 23 sep. 2023
 *      Author: gonzalo
 */

#include <iostream>
#include "Examen.h"

int main() {
	Examen * examen = new Examen(3);

	examen->getEjercicio(1)->puntuar(10);
	examen->getEjercicio(2)->puntuar(7);
	examen->getEjercicio(3)->setPorcentajeDeCorreccion(50);

	std::cout << examen->getPorcentajeDeCorreccion() << std::endl;

	try {
		std::cout << examen->getPuntaje() << std::endl;
	} catch (...) {
		std::cout << "No se puede obtener el puntaje";
	}

	examen->getEjercicio(3)->puntuar(5);
	std::cout << examen->getPuntaje() << std::endl;

	std::cout << examen->getPorcentajeDeCorreccion() << std::endl;

	delete examen;
	return 0;
}

