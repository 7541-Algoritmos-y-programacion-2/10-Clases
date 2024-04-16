/*
 * Eslabon.h
 *
 *  Created on: 15/04/2024
 *      Author: algo2
 */

#ifndef ESLABON_H_
#define ESLABON_H_


class Eslabon {
private:

	double ancho;
	double largo;
	ModoDeTrabajo modoDeTrabajo;

public:
	/**
	 * pre: largo en cm, ancho en cm > 0
	 * pos:
	 */
	Eslabon(double largo, double ancho, ModoDeTrabajo modoDeTrabajo);

	/**
	 * pre:
	 * pos:
	 */
	virtual ~Eslabon();

	/**
	 * pre:
	 * pos:
	 */
	double getAncho();

	/**
	 * pre:
	 * pos:
	 */
	void setAncho(double ancho);

	/**
	 * pre:
	 * pos:
	 */
	double getLargo();

	/**
	 * pre:
	 * pos:
	 */
	void setLargo(double largo);

	ModoDeTrabajo getModoDeTrabajo();
};

#endif /* ESLABON_H_ */
