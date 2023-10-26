/*
 * Ascensor.h
 *
 *  Created on: 26/10/2023
 *      Author: algo2
 */

#ifndef ASCENSOR_H_
#define ASCENSOR_H_

#include "Vector.h"
#include "Piso.h"

enum EstadoDeAscensor {
	FUNCIONANDO,
	ROTO
};

class Ascensor {
private:
	Vector<Piso *> * pisos;
	EstadoDeAscensor estado;
	unsigned int cantidadDePisosRecorridos;
	Piso * pisoActual;

	/**
	 * pre: valida el rango de numeroDePiso entre 0 y la cantidad de pisos
	 * pos: tira excepcion si esta fuera de rango
	 */
	void validarRangoDePiso(unsigned int numeroDePiso);

	/**
	 * pre:
	 * pos: tira excepcion si el ascensor no esta en funcionamiento
	 */
	void validarFuncionamiento();

	/**
	 * pre:
	 * pos: suma el valor absoluto de cantidad a cantidadDePisosRecorridos
	 */
	unsigned int incrementarCantidadDePisosRecorridos(unsigned int cantidad);

public:

	/**
	 * pre: el ascensor se usa desde 0 (PB) hasta cantidadDePisos inclusive
	 * pos: deja creado el ascensor con todos los pisos solicitados y agrega la PB,
	 *      el ascensor queda en la PB
	 */
	Ascensor(unsigned int cantidadDePisos);

	/**
	 * pre: -
	 * pos: elimina el ascensor y los pisos
	 */
	virtual ~Ascensor();

	/**
	 * pre: -
	 * pos: devuelve el piso actual del ascensor
	 */
	Piso * getPisoActual();

	/**
	 * pre: que el ascensor este en funcionamiento y numeroDePiso este
	 * 		en el rango 0 - cantidad de pisos.
	 * pos: mueve el ascensor al piso solicitado
	 */
	unsigned int mover(unsigned int numeroDePiso);

	/**
	 *
	 */
	unsigned int getCantidadDePisosRecorridos();

	/**
	 * pre: que el ascensor este en funcionamiento y numeroDePiso este
	 * 		en el rango 0 - cantidad de pisos.
	 * pos: mueve el ascensor al piso solicitado
	 */
	unsigned int llamar(unsigned int numeroDePiso);

	/**
	 *
	 */
	Piso * getPisoMasLlamado();

	/**
	 * pre: -
	 * pos: devuelve true si el ascensor esta en funcionamiento o false en caso contrario
	 */
	bool estaEnFuncionamiento();
};

#endif /* ASCENSOR_H_ */
