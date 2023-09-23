/*
 * Pago.h
 *
 *  Created on: 22/09/2023
 *      Author: algo2
 */

#ifndef PAGO_H_
#define PAGO_H_

class Pago {
private:
	double monto;
	unsigned int cantidadDeTerminos;
	void validarMonto(double monto);

public:

	Pago();

	/**
	 * pre: el monto debe ser 0 o positivo
	 * post: inicializa el pago y deja el monto cargado
	 */
	Pago(double monto);

	/**
	 * pre: -
	 * post: -
	 */
	virtual ~Pago();

	/**
	 * pre: -
	 * post: devuelve el monto del pago
	 */
	double getMonto();

	/**
	 * pre: el monto debe ser positivo
	 * post: cambia el valor del pago
	 */
	void setMonto(double monto);

	/**
	 * pre: pago debe estar inicializado
	 * post: suma el pago pago al monto actual
	 */
	void sumar(Pago * pago);

	/**
	 * pre: -
	 * post: devuelve el promedio de los terminos sumados o 0 sino hay terminos
	 */
	double getPromedio();

};

#endif /* PAGO_H_ */
