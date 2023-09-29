/*
 * Deuda.h
 *
 *  Created on: 24 sep. 2023
 *      Author: gonzalo
 */

#ifndef DEUDA_H_
#define DEUDA_H_

#include "Vector.h"
#include "Pago.h"

class Deuda
{
	private:
		double importe;
		unsigned int cantidadMaximaDePagos;
		Vector<Pago *> *vectorDePagos;
		unsigned int cantidadDePagosEfectivos;

	public:
		/*
		 * pre: El importe debe ser 0 o positivo y la cantidadMaximaDePagos debe ser mayor a 1
		 * post: Crea la deuda y deja el importe y la cantidadMaximaDePagos cargados
		 */
		Deuda(double importe, unsigned int cantidadMaximaDePagos);

		/*
		 * pre: -
		 * post: Destruye la deuda de forma correcta
		 */
		virtual ~Deuda();

		/*
		 * pre: -
		 * post: Devuelve el importe inicial de la deuda
		 */
		double getImporte();

		/*
		 * pre: -
		 * post: Devuelve la cantidad maxima de pagos
		 */
		unsigned int getCantidadMaximaDePagos();

		/*
		 * pre: El indice debe estar entre 1 y la cantidad maxima de pagos
		 * 		El monto del pago debe ser 0 o mayor
		 * post: Cambia el monto del vector de pagos en el indice indicado
		 */
		void pagar(unsigned int indice, double montoDePago);

		/*
		 * pre: El pago debe estar inicializado
		 * post: Devuelve el saldo restante de la deuda restando el importe con el monto del pago total
		 */
		double obtenerSaldo(Pago *pagoTotal);

		/*
		 * pre: -
		 * post: Devuelve la cantidad de pagos efectivos(distintos de 0)
		 */
		unsigned int cantidadDePagos();

		/*
		 * pre: El pago total debe estar inicializado
		 * post: Devuelve el promedio de los pagos realiados
		 */
		double promedioPagos(Pago *pagoTotal);

};

#endif /* DEUDA_H_ */
