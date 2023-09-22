
#include <iostream>;
#include "Vector.h"
using namespace std;


int main() {
	{
		Vector<int> vectorDeEnteros2(10);
		vectorDeEnteros2.setDato(1, 8);
		vectorDeEnteros2.setDato(1, 7);
	} //Facil de borrar


	Vector<int> * vectorDeEnteros3 = new Vector<int>(10);
	Vector<int *> * vectorDeEnteros4 = NULL;

	{
		vectorDeEnteros4 = new Vector<int *>(10);

		//Forma 1
		{
			int * valor = NULL;
			*valor = 8;
			valor = new int;
			delete valor;
			//vectorDeEnteros4->setDato(1, valor);
			//*valor = 7;
		}
		{
			//*(vectorDeEnteros4->getDato(1)) = 6;
		}



		//Forma 2
		vectorDeEnteros4->setDato(1, new int);
		*(vectorDeEnteros4->getDato(1)) = 8;

	}
	//Borrado de vectorDeEnteros4;
	for(int i = 1; i <= vectorDeEnteros4->getLongitud(); i++) {
		if (vectorDeEnteros4->getDato(i) != NULL) {
			delete vectorDeEnteros4->getDato(i);
		}
	}

	delete vectorDeEnteros4;
	delete vectorDeEnteros3;

	/*
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
	 */
	return 0;
}
