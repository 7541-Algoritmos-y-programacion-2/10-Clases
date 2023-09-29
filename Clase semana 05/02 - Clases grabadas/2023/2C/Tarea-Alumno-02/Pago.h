/*
 * Pago.h
 *
 *  Created on: 23 sep. 2023
 *      Author: gonzalo
 */

#ifndef PAGO_H_
#define PAGO_H_

class Pago
{
	private:
		double monto;
		double cantidadDePagos;

		void validarMonto(double monto);

	public:
		/*
		 * pre: El monto debe ser mayor a 0
		 * post: Crea el pago y deja el monto cargado
		 */
		Pago(double monto);

		/*
		 * pre: -
		 * post: Destruye el pago de forma correcta
		 */
		virtual ~Pago();

		/*
		 * pre: -
		 * post: Devuelve el monto del pago
		 */
		double getMonto();

		/*
		 * pre: El monto debe ser mayor a 0
		 * post: Cambio el valor del monto
		 */
		void setMonto(double monto);

		/*
		 * pre: El pago debe estar inicializado
		 * post: Suma el monto de pago al monto actual
		 */
		void sumar(Pago *pago);

		/*
		 * pre: -
		 * post: Devuelve el promedio de los pagos o 0 si no hay pagos
		 */
		double getPromedio();
};

#endif /* PAGO_H_ */
