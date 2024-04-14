//============================================================================
// Name        : Clase05-Lunes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Complejo.h"
using namespace std;

int main() {
	Complejo totalEstatico;  //llama al constructor
	totalEstatico.setParteReal(2.0);
	totalEstatico.setParteImaginaria(3.3);

	totalEstatico = totalEstatico + totalEstatico;

	cout << "Parte real: " << totalEstatico.getParteReal() << endl;
	cout << "Parte imaginaria: " << totalEstatico.getParteReal() << endl;

	if (totalEstatico.getParteReal() != 2.0) {
		throw "No guardo el valor";
	}

	//Complejo complejo2(10, 2);
	//totalEstatico.sumar(complejo2);

	Complejo * total = new Complejo(2, 3);
	Complejo * total2 = new Complejo(1, 7);
	total->sumar(total2);

	delete total;
	delete total2;

	total = new Complejo(2, 3);
	total->sumar(NULL);
	delete total;

	cout << "Cantidad de complejos: " << Complejo::cantidadDeComplejos << endl;
	cout << "Cantidad de complejos: " << Complejo::sumar(total, total2) << endl;


	return 0;
}
