/*
 * Polinomio.h
 *
 *  Created on: 27/04/2023
 *      Author: algo2
 */

#ifndef POLINOMIO_H_
#define POLINOMIO_H_

#include "Vector.h"

class Polinomio {
private:
	Vector<Termino *> * terminos;

public:
	/**
	 * pre: cantidadMaximaDeTerminos debe ser mayor a 0
	 * pos: crea el polinomio 1.
	 */
	Polinomio(unsigned int cantidadMaximaDeTerminos);

	/**
	 * pre:
	 * pos:
	 */
	virtual ~Polinomio();

	/**
	 * pre:
	 * pos:
	 */
	double evaluar(double valor);

	/**
	 * pre: el grado del termino no tiene que existir y no puede ser nulo
	 * pos: agregar el termino al polinomio
	 */
	void agregarTermino(Termino * termino);

	/**
	 * pre:
	 * pos: el grado y el coeficiente deben existir en el polinomio
	 */
	void removerTermino(unsigned int grado);

	/**
	 * pre: el termino con grado grado debe existir
	 * pos: devuelve el primer termino con grado grado
	 */
	Termino * getTermino(unsigned int grado);

	/**
	 * pre:
	 * pos: si grado existe, devuelve true o false en caso contrario.
	 */
	bool existeElTermino(unsigned int grado);

private:

	void validarGrado(unsigned int grado);
};

#endif /* POLINOMIO_H_ */
