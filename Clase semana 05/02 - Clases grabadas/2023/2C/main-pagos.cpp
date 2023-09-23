
#include <iostream>;
#include "Vector.h"
#include "Pago.h"
using namespace std;


int main() {
	Vector<Pago *> * pagos = new Vector<Pago *>(100);
	{ //Opcion 1
		//Inicializo opcion 1
		//DEJO COMO ESTA EN NULL
		pagos->setDato(1, new Pago(100.2));
		pagos->setDato(2, new Pago(104.2));
		pagos->setDato(3, new Pago(140.2));
		pagos->getDato(3)->setMonto(145.2);
	}

	{ //Opcion 2
		//Inicializo opcion 2
		for(int i = 1; i < pagos->getLongitud(); i++) {
			pagos->setDato(i, new Pago(0));
		}
		pagos->getDato(3)->setMonto(145.2);
	}

	{ //Opcion 3
		pagos->getDato(1)->setMonto(145.2);
		pagos->getDato(2)->setMonto(155.2);
		pagos->getDato(3)->setMonto(165.2);
		pagos->getDato(4)->setMonto(175.2);
	}

	//Imprimo todos los pagos
	for(int i = 1; i <= pagos->getLongitud(); i++ ) {
		if (pagos->getDato(i)->getMonto() > 0) {
			std::cout << pagos->getDato(i)->getMonto() << std::endl;
		}
	}

	//Sumar todos los montos
	double total = 0;
	for(int i = 1; i <= pagos->getLongitud(); i++ ) {
		total += pagos->getDato(i)->getMonto();
	}

	//Sumar todos los pagos
	Pago * pagoTotal = new Pago(0);
	for(int i = 1; i <= pagos->getLongitud(); i++ ) {
		pagoTotal->sumar(pagos->getDato(i));
	}

	//Imprimir promedio
	std::cout << (pagoTotal->getPromedio(pagos->getLongitud()) << std::endl;
	std::cout << (pagoTotal->getPromedio() << std::endl;

	//Otro promedio
	pagoTotal->sumar(10);
	pagoTotal->sumar(20);
	pagoTotal->getPromedio()



	delete pagoTotal;
	delete pagos;

	return 0;
}
