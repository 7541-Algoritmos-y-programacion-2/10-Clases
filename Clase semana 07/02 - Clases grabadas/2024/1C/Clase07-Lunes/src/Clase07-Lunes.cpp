//============================================================================
// Name        : Clase07-Lunes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Lista.h"
#include "TDADato.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

/*
	Lista * lista = new Lista();

	lista->agregar(2, 1);
	lista->agregar(4, 2);

	lista->agregar(6, 2);
	lista->agregar(7, 4);

	lista->cambiar(4, 5);

	for (int i = 1; i <= lista->getTamanio(); i++ ) {
		std::cout << lista->obtener(i);
	}

	//Mejorar el recorrido
	//Lista de char
*/
	//Lista con template
	{
		Lista<int> * lista = new Lista<int>();
		lista->agregar(2, 1);
		for (int i = 1; i <= lista->getTamanio(); i++ ) {
			std::cout << lista->obtener(i);
		}
	}
	{
		Lista<char> * lista = new Lista<char>();
		lista->agregar('a', 1);
		for (int i = 1; i <= lista->getTamanio(); i++ ) {
			std::cout << lista->obtener(i);
		}
	}
	{
		TDADato * dato = new TDADato();
		Lista<TDADato *> * lista = new Lista<TDADato *>();
		lista->agregar(dato, 1);

		//NO INCORRECTO
		for (int i = 1; i <= lista->getTamanio(); i++ ) {
			std::cout << lista->obtener(i);
		}

		//Recorrido correcto
		lista->iniciarCursor();
		while (lista->avanzarCursor()) {
			TDADato * dato = lista->obtenerCursor();
			std::cout << dato;
		}
	}
	return 0;
}
