/*
 * Complejo.h
 *
 *  Created on: 08/04/2024
 *      Author: algo2
 */

#ifndef COMPLEJO_H_
#define COMPLEJO_H_


class Complejo {
public:
	static double cantidadDeComplejos;
	static Complejo * sumar(Complejo *&termino1, Complejo *&termino2);

private:
	double parteReal;
	double parteImaginaria;

	void validar(Complejo * &complejo);

public:
	/**
	 * pre: -
	 * post: deja el objeto con la parte real e imaginaria en el valor 0
	 */
	Complejo();

	/**
	 * pre: -
	 * post: deja el objeto con la copia de la parte real y parte imaginaria del parametro complejo
	 */
	Complejo(Complejo &complejo);

	/**
	 * pre: -
	 * post: deja el objeto con la parte real como parteReal y parte imaginaria como parteImaginaria
	 */
	Complejo(double parteReal, double parteImaginaria);

	/**
	 * pre:
	 * post:
	 */
	virtual ~Complejo();

	/**
	 * pre:
	 * post:
	 */
	double getParteImaginaria();

	/**
	 * pre:
	 * post:
	 */
	double getParteReal();

	/**
	 * pre: -
	 * post:
	 */
	void setParteImaginaria(double parteImaginaria);

	/**
	 * pre:
	 * post:
	 */
	void setParteReal(double parteReal);

	/**
	 * pre: complejo debe estar creado
	 * post: sumar en el objeto las partes real e imaginaria y lo devuelve
	 */
	Complejo * sumar(Complejo * complejo);

	/**
	 * pre:
	 * post:
	 */
	Complejo &sumar(Complejo &complejo1, Complejo &complejo2);

	/**
	 * pre:
	 * post:
	 */
	Complejo &restar(Complejo &complejo);

};

#endif /* COMPLEJO_H_ */
