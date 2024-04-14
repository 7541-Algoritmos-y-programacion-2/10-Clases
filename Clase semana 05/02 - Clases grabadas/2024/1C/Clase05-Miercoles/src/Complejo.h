/*
 * Complejo.h
 *
 *  Created on: 03/04/2024
 *      Author: algo2
 */

#ifndef COMPLEJO_H_
#define COMPLEJO_H_
#include <string>

class Complejo {
public:
	static int cantidadDeComplejos;
	static Complejo * sumarComplejos(Complejo * termino1, Complejo * termino2);

private:
	double parteReal;
	double parteImaginaria;

	/**
	 * pre: -
	 * post: valida que el complejo no sea vacio
	 */
	static void validar(Complejo * complejo);

public:

	/**
	 * Pre: -
	 * Post: construye el complejo y deja el complejo en el valor (0,0)
	 */
	Complejo();

	/**
	 * pre: complejo no puede ser vacio
	 * post: devuelve un complejo con los valores del complejo actual
	 */
	Complejo(Complejo * complejo);

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
	 * Pre: complejo no puede ser vacio
	 * Post: suma el valor del complejo actual y complejo, y los devuelve como resultado
	 */
	Complejo * sumar(Complejo *complejo);

	/**
	 * Pre: -
	 * Post: devuelve un Complejo con los mismo valores que este complejo
	 */
	Complejo * duplicar();

	/**
	 * Pre: -
	 * Post: suma al valor del complejo actual el complejo pasado por parametro
	 */
	void sumarse(Complejo *complejo);

	void sumarse(Complejo *complejo, Complejo *complejo1);

	void sumarse(Complejo *complejo, int *complejo1);

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

	std::string imprimir();
};

#endif /* COMPLEJO_H_ */
