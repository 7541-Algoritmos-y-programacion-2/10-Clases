/*
 * Deuda.h
 *
 *  Created on: 22/09/2023
 *      Author: algo2
 */

#ifndef DEUDA_H_
#define DEUDA_H_

class Deuda {
private:
	double total;
	Vector<Pago *> * pagos;

public:
	/**
	 * Tarea terminar el TDA, Esto incluye:
	 * 	 pre y pos
	 * 	 validar
	 * 	 completar el total de operaciones
	 * 	 hacer el main de prueba
	 *
	 */

	Deuda(double totalDeDeuda, unsigned int cantidadMaximaDePago);

	virtual ~Deuda();

	//validar monto > 0
	void pagar(Pago * pago);

	//completar operaciones
};

#endif /* DEUDA_H_ */
