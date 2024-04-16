/*
 * Cadena.h
 *
 *  Created on: 15/04/2024
 *      Author: algo2
 */

#ifndef CADENA_H_
#define CADENA_H_

#include "Eslabon.h"

enum ModoDeTrabajo {
	MODIFICABLE,
	ANCHO_FIJO
};

class Cadena {
private:
	Eslabon ** eslabones;
	unsigned int cantidadMaximaDeEslabones;
	ModoDeTrabajo modoDeTrabajo;

public:
	/**
	 * pre: cantidadMaximaDeEslabones debe ser mayor a 0, y el ancho en cm (mayor a 0)
	 * pos: crea la cadena con 1 eslabon, de ancho ancho y largo 1
	 */
	Cadena(unsigned int cantidadMaximaDeEslabones, double ancho, ModoDeTrabajo modoDeTrabajo);

	/**
	 * pre:
	 * pos: elimina todos los eslabones de la cadena, inclusive los agregados por el usuario
	 */
	virtual ~Cadena();

	/**
	 * pre:
	 * pos:
	 */
	void agregar(Eslabon * eslabon);

	/**
	 * pre:
	 * pos:
	 */
	Eslabon * retirar();

	/**
	 * pre: posicion entre 1 y cantidad de eslabones
	 * pos:
	 */
	Eslabon * getEslabon(unsigned int posicion);

	/**
	 * pre:
	 * pos: el largo de la cadena: suma los largos de los eslabones
	 */
	double getLongitud();

	/**
	 * pre:
	 * pos: va en el rango de 1 a cantidadMaximaDeEslabones
	 */
	unsigned int getCantidadDeEslabones();

	/**
	 * pre:
	 * pos:
	 */
	double getAncho();

	/**
	 *
	 */
	void setAncho(double ancho);

	/**
	 * pre:
	 * pos:
	 */
	bool hayLugar();
};

#endif /* CADENA_H_ */
