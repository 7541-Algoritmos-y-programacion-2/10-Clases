
#include "Mesa.h"


int main(){
	/*
	Mesa * mesa = new Mesa(1, 4);
	mesa->adicionarComensales(2);
	mesa->adicionarComensales(2);
	mesa->adicionarComensales(1);

	mesa->adicionarMonto(10);
	mesa->adicionarMonto(20);

	mesa->cerrarMesa();
	delete mesa;
	*/

	try {
		Restaurante * restaurante = new Restaurante(4);

		restaurante->adicionarMesa(7);
		restaurante->adicionarMesa(3);
		restaurante->adicionarMesa(2);
		restaurante->adicionarMesa(2);

		std::cout << restaurante->getCapacidadTotalDelRestaurante();

		restaurante->adicionarComensal(1, 2);
		restaurante->adicionarComensal(2, 3);
		restaurante->adicionarComensal(3, 2);
		restaurante->adicionarComensal(4, 2);

		std::cout << restaurante->getCantidadDeComesalesActuales();
		std::cout << restaurante->getCantidadDeComesalesActuales(3);

		restaurante->adicionarMonto(1, 2000);
		restaurante->adicionarMonto(1, 500);
		restaurante->adicionarMonto(2, 700);
		restaurante->adicionarMonto(3, 200);

		restaurante->cerrarMesa(3);

		restaurante->adicionarMonto(4, 250);
		restaurante->adicionarMonto(4, 250);

		restaurante->cerrarMesa(2);
		restaurante->cerrarMesa(1);
		restaurante->cerrarMesa(4);

	} catch (...) {

	}
}


