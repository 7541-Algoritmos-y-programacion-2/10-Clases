/*
 * Vagon.h
 *
 *  Created on: 15/05/2024
 *      Author: algo2
 */

#ifndef VAGON_H_
#define VAGON_H_

class Vagon {
private:
	double capacidadMaximaDeCarga;
	double cargaActual;

public:
	/**
	 * pre: capacidadMaximaDeCarga debe ser mayor a 0.
	 * pos:
	 */
	Vagon(double capacidadMaximaDeCarga);

	/**
	 * pre:
	 * pos:
	 */
	virtual ~Vagon();

	/**
	 * pre:
	 * pos:
	 */
	double getCapacidadMaximaDeCarga();

	/**
	 * pre:
	 * pos:
	 */
	double getCargaActual();

	/**
	 * pre:
	 * pos:
	 */
	double getCargaRestante();

	/**
	 * pre: carga debe ser mayor a 0, y menor a la capacidad restante de carga.
	 * pos: agrega la carga al vagon si es posible y devuelve el sobrante.
	 */
	double cargar(double carga);

	/**
	 * pre:
	 * pos:
	 */
	void descargar(double carga);

	/**
	 * pre:
	 * pos:
	 */
	bool estaVacio();
};

#endif /* VAGON_H_ */
