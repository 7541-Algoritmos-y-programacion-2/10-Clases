/*
 * Termino.h
 *
 *  Created on: 27/04/2023
 *      Author: algo2
 */

#ifndef TERMINO_H_
#define TERMINO_H_

class Termino {
private:
	double coeficiente;
	unsigned int grado;

public:
	/**
	 * pre: -
	 * pos: crea un termino con el coeficiente y grado dados. Ej coeficiente . X grado
	 */
	Termino(double coeficiente, unsigned int grado);

	/**
	 * pre:
	 * pos: libera todos los recursos utilizados.
	 */
	virtual ~Termino();

	/**
	 * pre: -
	 * pos: devuelve el grado del termino
	 */
	unsigned int getGrado();

	/**
	 * pre: -
	 * pos: devuelve el coeficiente del termino
	 */
	double getCoeficiente();

	/**
	 * pre: -
	 * pos: cambia el coeficiente del termino
	 */
	void setCoeficiente(double coeficiente);

	/**
	 * pre: -
	 * pos: evalua el termino con X en valor valor
	 */
	double evaluar(double valor);

	static Termino * crearTermino(double coeficiente, unsigned int grado);
};

#endif /* TERMINO_H_ */
