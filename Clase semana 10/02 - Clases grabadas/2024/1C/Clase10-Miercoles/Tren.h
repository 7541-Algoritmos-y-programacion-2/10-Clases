/*
 * Tren.h
 *
 *  Created on: 15/05/2024
 *      Author: algo2
 */

#ifndef TREN_H_
#define TREN_H_

#include "Vector.h"
#include "Vagon.h"

static const unsigned int CantidadMaximaDeLocomotoras = 3;
static const unsigned int CantidadMaximaDeVagonesPorLocomotora = 10;

enum EstadoDeTren {
	EN_MOVIMIENTO,
	DETENIDO
};
class Tren {
private:
	Vector<Vagon *> * vagones;
	unsigned int cantidadDeLocomotoras;
	EstadoDeTren estadoDeTren;

public:
	/**
	 * pre: cantidadDeLocomotoras debe ser mayor a 0 y menor o igual a 3
	 * pos: crea un tren con cantidadDeLocomotoras y ningun vagon
	 */
	Tren(unsigned int cantidadDeLocomotoras);

	/**
	 * pre:
	 * pos:
	 */
	virtual ~Tren();

	/**
	 * pre: vagon no puede ser NULO y no tiene que tener carga
	 * pos:
	 */
	void agregarVagon(Vagon * vagon);

	/**
	 * pre:
	 * pos:
	 */
	bool estaDetenido();

	/**
	 * pre: carga debe ser mayor a 0 y menor a la capacidad restante del tren
	 * pos: si hay un sobrante que no se puede cargar, se devuelve.
	 */
	double agregarCarga(double carga);
};

#endif /* TREN_H_ */
