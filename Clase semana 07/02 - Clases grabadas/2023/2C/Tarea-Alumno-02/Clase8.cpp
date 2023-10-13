/*
 * Main.cpp
 *
 *  Created on: 11 oct. 2023
 *      Author: gonzalo
 */
#include <iostream>
#include "Tablero3D.h"


int main() {
	unsigned int ancho = 2;
	unsigned int alto = 3;
	unsigned int profundidad = 2;

	Tablero3D *tablero = new Tablero3D(ancho, alto, profundidad);

	for(unsigned int i = 1; i <= tablero->getProfundidad(); i++) {
		for(unsigned int j = 1; j <= tablero->getAncho(); j++) {
			for(unsigned int k = 1; k <= tablero->getAlto(); k++) {
				tablero->getCasillero(i, j, k)->setFicha('B');
			}
		}
	}

	tablero->getCasillero(1, 1, 1)->setFicha('A');
	tablero->getCasillero(2, 2, 2)->setFicha('C');

	for(unsigned int i = 1; i <= tablero->getProfundidad(); i++) {
		for(unsigned int j = 1; j <= tablero->getAncho(); j++) {
			for(unsigned int k = 1; k <= tablero->getAlto(); k++) {
				std::cout << tablero->getCasillero(i, j, k)->getFicha();
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	delete tablero;

	return 0;
}


