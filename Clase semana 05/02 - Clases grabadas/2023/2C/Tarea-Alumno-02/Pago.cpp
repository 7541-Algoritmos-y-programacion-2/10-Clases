/*
 * Pago.cpp
 *
 *  Created on: 23 sep. 2023
 *      Author: gonzalo
 */

#include "Pago.h"

Pago::Pago(double monto)
{
	this->validarMonto(monto);
	this->monto = monto;
	this->cantidadDePagos = 0;
}

Pago::~Pago() {}

double Pago::getMonto()
{
	return this->monto;
}

void Pago::setMonto(double monto)
{
	this->validarMonto(monto);
	this->monto = monto;
}

void Pago::sumar(Pago *pago)
{
	this->monto += pago->getMonto();
	this->cantidadDePagos++;
}

double Pago::getPromedio()
{
	if(this->cantidadDePagos > 0)
	{
		return  this->monto / this->cantidadDePagos;
	}
	else
	{
		return 0;
	}
}

void Pago::validarMonto(double monto)
{
	if(monto < 0)
	{
		throw "El monto debe ser positivo o 0";
		monto = 50;
	}
}

