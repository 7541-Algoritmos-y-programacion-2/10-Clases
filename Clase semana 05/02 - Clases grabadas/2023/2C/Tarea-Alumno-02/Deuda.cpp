/*
 * Deuda.cpp
 *
 *  Created on: 24 sep. 2023
 *      Author: gonzalo
 */

#include <stdexcept>
#include "Deuda.h"

Deuda::Deuda(double importe, unsigned int cantidadMaximaDePagos)
{
	if(importe < 0 || cantidadMaximaDePagos < 1)
	{
		throw std::invalid_argument("Datos mal cargados");
	}
	this->importe = importe;
	this->cantidadMaximaDePagos = cantidadMaximaDePagos;
	this->vectorDePagos = new Vector<Pago *>(cantidadMaximaDePagos);
	this->cantidadDePagosEfectivos = 0;

	for(unsigned int i = 1; i <= this->vectorDePagos->getLongitud(); i++)
	{
		this->vectorDePagos->setDato(i, new Pago(0));
	}
}

Deuda::~Deuda()
{
	delete vectorDePagos;
}

double Deuda::getImporte()
{
	return this->importe;
}

unsigned int Deuda::getCantidadMaximaDePagos()
{
	return this->cantidadMaximaDePagos;
}

void Deuda::pagar(unsigned int indice, double montoDePago)
{
	if((indice < 1 || indice > this->cantidadMaximaDePagos) || montoDePago < 0)
	{
		throw std::invalid_argument("Datos mal cargados");
	}

	if(this->vectorDePagos->getDato(indice)->getMonto() == 0)
	{
		this->vectorDePagos->getDato(indice)->setMonto(montoDePago);
	}
}

double Deuda::obtenerSaldo(Pago *pagoTotal)
{
	for(unsigned int i = 1; i <= this->vectorDePagos->getLongitud(); i++)
	{
		pagoTotal->sumar(this->vectorDePagos->getDato(i));
	}

	if(this->importe > pagoTotal->getMonto())
	{
		return (this->importe - pagoTotal->getMonto());
	}
	else
	{
		return 0;
	}
}

unsigned int Deuda::cantidadDePagos()
{
	for(unsigned int i = 1; i <= this->vectorDePagos->getLongitud(); i++)
	{
		if(this->vectorDePagos->getDato(i)->getMonto() != 0)
		{
			this->cantidadDePagosEfectivos++;
		}
	}
	return this->cantidadDePagosEfectivos;
}

double Deuda::promedioPagos(Pago *pagoTotal)
{
	if(pagoTotal->getMonto() > this->importe)
	{
		throw std::invalid_argument("El pago total es mayor al importe");
	}
	else
	{
		if(this->cantidadDePagosEfectivos > 0)
		{
			return pagoTotal->getPromedio();
		}
		else
		{
			return 0;
		}
	}

}
