/*
 * Piso.h
 *
 *  Created on: 26/10/2023
 *      Author: algo2
 */

#ifndef PISO_H_
#define PISO_H_

class Piso {
private:
	unsigned int cantidadDeVecesVisitado;
	unsigned int cantidadDeVecesLlamado;
	unsigned int numero;

public:
	/**
	 *
	 */
	Piso(unsigned int numero);

	/**
	 *
	 */
	virtual ~Piso();

	/**
	 *
	 */
	unsigned int getNumero();

	/**
	 *
	 */
	unsigned int getCantidadDeVecesVisitado();

	/**
	 *
	 */
	unsigned int getCantidadDeVecesLlamado();

	/**
	 *
	 */
	void incrementarCantidadDeVecesVisitado();

	/**
	 *
	 */
	void incrementarCantidadDeVecesLlamado();
};

#endif /* PISO_H_ */
