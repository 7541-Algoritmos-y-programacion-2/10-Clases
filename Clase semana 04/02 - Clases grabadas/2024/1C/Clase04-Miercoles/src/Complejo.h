/*
 * Complejo.h
 *
 *  Created on: 03/04/2024
 *      Author: algo2
 */

#ifndef COMPLEJO_H_
#define COMPLEJO_H_

class Complejo {
public:
	static int id;
	static Complejo * sumar1(Complejo * c1);

private:
	double parteReal;
	double parteImaginaria;
	char * letra;

public:

	/**
	 * Pre: -
	 * Post: construye el complejo y deja el complejo en el valor (0,0)
	 */
	Complejo();

	Complejo(Complejo &complejo);

	/**
	 * Pre: -
	 * Post: construye el complejo y deja el complejo en el valor
	 *       (parteReal,parteImaginaria)
	 */
	Complejo(double parteReal, double parteImaginaria);

	/**
	 * Pre: -
	 * Post: libera la memoria
	 */
	virtual ~Complejo();

	/**
	 * Pre: -
	 * Post: suma el valor del complejo actual y complejo, y los devuelve como resultado
	 */
	Complejo sumar(Complejo &complejo);

	/**
	 * Pre: -
	 * Post: suma al valor del complejo actual el complejo pasado por parametro
	 */
	void sumarse(Complejo complejo1);

	/**
	 * Pre: -
	 * Post: Devuelve la parte imaginaria del complejo
	 */
	double getParteImaginaria();

	/**
	 * Pre: -
	 * Post: Devuelve la parte real del complejo
	 */
	double getParteReal();

	/**
	 * Pre: -
	 * Post: cambia la parte imaginaria del complejo
	 */
	void setParteImaginaria(double imaginaria);

	/**
	 * Pre: -
	 * Post: cambia la parte real del complejo
	 */
	void setParteReal(double real);
};

#endif /* COMPLEJO_H_ */
