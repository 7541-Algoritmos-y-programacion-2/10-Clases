/*
 * Clase06-Lunes.cpp
 *
 *  Created on: 15/04/2024
 *      Author: algo2
 */

#include "PlantillaUno.h"
#include "Cadena.h"
#include "Eslabon.h"
#include <iostream>
#include "Vector.h"

int main(int argc, char **argv) {

	Cadena * cadena = new Cadena(100, 2, ANCHO_FIJO);
	cadena->agregar( new Eslabon(10, 2, ANCHO_FIJO));
	try {
		delete cadena->retirar();
		delete cadena->retirar();
		delete cadena->retirar();
	} catch (...) {
		std::cout << "No se puede retirar el ultimo";
	}

	cadena->agregar( new Eslabon(10, 2, ANCHO_FIJO));
	cadena->agregar( new Eslabon(10, 2, ANCHO_FIJO));
	cadena->agregar( new Eslabon(10, 2, ANCHO_FIJO));

	for(unsigned int i = 1; i <= cadena->getCantidadDeEslabones(); i++) {
		std::cout << i << cadena->getEslabon(i)->getAncho()<< std::endl;
	}

	std::cout << "La longitud es: " << cadena->getLongitud() << std::endl;
	std::cout << "La cantidad de eslabones es: " << cadena->getCantidadDeEslabones() << std::endl;

	int i = 1;
	while( cadena->hayLugar()) {
		Eslabon * eslabon = cadena->retirar();
		std::cout << i++ << eslabon->getAncho() << std::endl;
		delete eslabon;
	}

	try {
		cadena->getEslabon(1000);
	} catch (...) {
		std::cout << "No se puede obtener el eslabon 1000";
	}
	delete cadena;

	/**
	 * Tarea:
	 * 1) Terminar el diseño y la estrategia.
	 * 2) Terminar el TDA Cadena y Eslabon
	 * 3) Agregar el metodo setAncho de cadena
	 * 4) Terminar el main de test
	 */

	Vector<Eslabon *> * vector = new Vector<Eslabon *>(10, NULL);
	vector->agregar(1, new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(2, new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(3, new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(4, new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(5, new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(6, new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(7, new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(8, new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(9, new Eslabon(10, 10, MODIFICABLE));


	vector->agregar(new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(11, new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(18, new Eslabon(10, 10, MODIFICABLE));
	vector->agregar(new Eslabon(10, 10, MODIFICABLE));
	std::cout << vector->getLongitud() << std::endl;

	for(int i = 0; i < vector->getLongitud(); i++ ) {
		std::cout << vector->obtener(i+1)->getLargo() << std::endl;
	}

	for(int i = 1; i <= vector->getLongitud(); i++ ) {
		vector->remover(i);
	}

	delete vector;

	//Lista
	Lista * lista = new Lista();
	lista->insertar('A');
	lista->insertar('H');
	lista->insertar('C');
	lista->insertar('F');

}


