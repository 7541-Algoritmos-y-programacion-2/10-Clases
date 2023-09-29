/*
 * Vector.cpp
 *
 *  Created on: 23 sep. 2023
 *      Author: gonzalo
 */

#include <iostream>
#include <stdexcept>
#include "Deuda.h"

int main()
{
	try
	{
		double importe = 1000;
		unsigned int cantidadMaximaDePagos = 5;

		Deuda *deuda = NULL;
		deuda = new Deuda(importe, cantidadMaximaDePagos);

		//Realiar pagos forma 1
		for(unsigned int i = 1; i <= deuda->getCantidadMaximaDePagos(); i++)
		{
			deuda->pagar(i, i * 100);
		}

		//Realizar pagos forma 2
		deuda->pagar(1, 200);
		deuda->pagar(2, 300);
		deuda->pagar(3, 100);
		deuda->pagar(4, 100);
		deuda->pagar(5, 100);

		Pago *pagoTotal = new Pago(0);

		std::cout << "Deuda inicial: " << deuda->getImporte() << std::endl;

		std::cout << "Saldo: " << deuda->obtenerSaldo(pagoTotal) << std::endl;

		std::cout << "Cantidad de pagos efectivos: " << deuda->cantidadDePagos() << std::endl;

		std::cout << "Promedio de los pagos: " << deuda->promedioPagos(pagoTotal) << std::endl;

		delete pagoTotal;

		delete deuda;
	} catch(const std::invalid_argument& e)
	{
		std::cout << "Datos mal cargados" << std::endl;
	} catch(const std::invalid_argument& e)
	{
		std::cout << "Datos mal cargados" << std::endl;
	} catch(const std::invalid_argument& e)
	{
		std::cout << "Pago total mayor a deuda" << std::endl;
	}



	return 0;
}

