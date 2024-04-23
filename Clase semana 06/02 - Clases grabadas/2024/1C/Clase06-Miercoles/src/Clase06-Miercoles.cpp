//============================================================================
// Name        : Clase06-Miercoles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Vector.h"
#include "Valor.h"

int main() {
	int * vector4 = new int[10];
	int vector1[10];
	sizeof(vector1);
	vector1[0] = 1;
	int valor = vector1[0];
	char vector2[10];

	{ //Vector de int
		Vector<int> * vector = new Vector<int>(10, 0);
		try {
			vector->agregar(1, 10);
			vector->agregar(10, 10);
			vector->agregar(0, 10); //Da error
		} catch (...) {
			cout << "Error";
		}

		cout << "La primer posicion es: " << vector->obtener(1);
		cout << "La longitud es " << vector->getLongitud() << endl; // prints !!!Hello World!!!


		delete vector;
	}

	{//Vector de valores
		Valor * miValor = new Valor();
		Vector<Valor *> * vectorDeValores = new Vector<Valor *>(10, NULL);
		vectorDeValores->agregar(1, miValor);
		cout << "La primer posicion es: " << vectorDeValores->obtener(1);
		cout << "La longitud es " << vectorDeValores->getLongitud() << endl;

		for(int i = 0; i < 100000; i++) {
			vectorDeValores->agregar(miValor);
		}

		vectorDeValores->ordenar();
	}
	return 0;
}
