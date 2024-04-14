//============================================================================
// Name        : Clase04-Miercoles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "ComplejoEnC.h"
#include "Complejo.h"

int main() {
	ComplejoEnC complejo1 = construirComplejoEnC();

	ComplejoEnC complejo2;
	setParteReal(complejo2, 2);

	ComplejoEnC suma = sumar(complejo1, complejo2);

	std::cout << "!!!Hello World!!!" << std::endl;


		Complejo complejo(2, 3);
		complejo.setParteReal(2);
		complejo.setParteImaginaria(2);

		complejo.getParteImaginaria();

		Complejo complejo3(2, 3);
		complejo.sumarse(complejo3);

		//Correcto
		Complejo::sumar1(&complejo3);
		Complejo::id = 1;

		//Funciona
		complejo.sumar1(&complejo3);

		//Objeto estatico
		Complejo complejoEstatico(2, 3);

		//Objeto dinamico
		Complejo * complejoDinamico = new Complejo(2, 3);
		delete complejoDinamico;

	return 0;
}
