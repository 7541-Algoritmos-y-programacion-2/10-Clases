//============================================================================
// Name        : Clase05-Miercoles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stddef.h>
#include <iostream>

#include "Complejo.h"

void mostrar(Complejo * &complejo) {
	std::cout << (*complejo).getParteReal();
	std::cout <<   complejo->getParteReal();
}

int main() {
	//Complejo complejoEstatico1();
	//complejoEstatico1.getParteReal();
	//Complejo complejoEstatico2(2, 3);
	int i = 2;

	if (i == 2) {
		Complejo * complejo1 = new Complejo();
		Complejo * complejo2 = new Complejo(3, 4);
		mostrar(complejo1);

		Complejo * complejo3 = new Complejo(complejo2);
		Complejo * complejo5 = complejo2->duplicar();
		bool cargaBien = false;
		while (!cargaBien) {
			try  {
				complejo3->sumar(NULL);
				std::cout << complejo3->imprimir();
			} catch(...) {

			}
		}

		Complejo * complejo7 = Complejo::sumarComplejos(complejo1, complejo2);
		complejo7 = complejo1 + complejo2;
		int entero = 0;
		complejo1->sumarse(complejo1, entero);
		complejo1->sumarse(complejo1, complejo2);

		delete complejo1;
		delete complejo2;
		delete complejo3;
		delete complejo5;
		delete complejo7;
	}
	return 0;
}
