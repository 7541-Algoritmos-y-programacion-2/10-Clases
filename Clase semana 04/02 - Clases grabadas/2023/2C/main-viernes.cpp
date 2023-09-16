
#include <iostream>;
#include "VectorDeEnteros.h"
using namespace std;


int main() {

	{	//Estatico
		VectorDeEnteros vectorDeEnteros1(5);
		vectorDeEnteros1.setDato(1, 10);
		std::cout << "Paso 1" << std::endl;
	}

	{	//Dinamico
		VectorDeEnteros * vectorDeEnteros2 = new VectorDeEnteros(5);
		vectorDeEnteros2->setDato(1, 10);
		std::cout << "Paso 2" << vectorDeEnteros2->getDato(1) << std::endl;

		for(int i = 1; i <= vectorDeEnteros2->getLongitud(); i++) {
			std::cout << "Posicion " + i << " " << vectorDeEnteros2->getDato(i) << std::endl;
		}

		try {
			std::cout << "Indice en rango";
			vectorDeEnteros2->getDato(100);
			std::cout << "Indice en rango";  //no se ejecuta
		} catch (...) {
			std::cout << "Indice fuera de rango";
		}

		vectorDeEnteros2->getDato(100);

		delete vectorDeEnteros2;
	}

	return 0;
}
