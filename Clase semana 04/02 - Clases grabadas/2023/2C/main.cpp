
#include <iostream>;
#include "Vector.h"

using namespace std;

void imprimir(Vector * vector) {
	for(int i = 1; i < vector->getLongitud(); i++) {
		std::cout << vector->getValor(i);
	}
}

int main() {
	int longitud = 10;
	{
		Vector vector1(longitud);
		vector1.setValor(4, 8);

		imprimir(&vector1);
	}

	bool ingresoCorrecto = true;
	while (ingresoCorrecto)
		try {
			ingresoCorrecto = true;
			Vector * vector2 = new Vector(longitud);
			vector2->setValor(100, 10);
			delete vector2;
		} catch (...) {
			ingresoCorrecto = false;
			std::cout << "Fuera de rango" << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;



    return 0;
}
