/*
 * Ejercicio.h
 *
 *  Created on: 29/09/2023
 *      Author: algo2
 */

#ifndef EJERCICIO_H_
#define EJERCICIO_H_

enum EstadoDeEjercicio {
	NOCORREGIDO,
	CORREGIDO
};

class Ejercicio {
private:
	double puntaje;
	double porcentajeDeCorreccion;
	EstadoDeEjercicio estado;

	/**
	 * pre: -
	 * post: devuelve error si el puntaje esta fueran del rango 0-10
	 */
	void validarPuntaje(double puntaje);

	/**
	 * pre: -
	 * post: devuelve error si el puntaje esta fueran del rango 0-100
	 */
	void validarPorcentaje(double porcentaje);

public:
	/**
	 * pre: -
	 * post: deja el ejercicio en estado no corregido y porcentaje 0%
	 */
	Ejercicio();

	/**
	 * pre: -
	 * post: -
	 */
	virtual ~Ejercicio();

	/**
	 * pre: -
	 * post: devuelve el puntaje actual del ejercicio o error sino esta puntuado
	 */
	double getPuntaje();

	/**
	 * pre: -
	 * post: devuelve el porcentaje de correccion actual del ejercicio
	 */
	double getPorcentajeDeCorreccion();

	/**
	 * pre: puntaje debe estar entre 0 y 10 inclusivo.
	 * post: cambia el puntaje, marca el examen como corregido y
	 *       pone 100% en porcentaje de correccion.
	 */
	void puntuar(double puntaje);

	/**
	 * pre: porcentajeDeCorreccion debe estar entre 0 y 100 inclusivo.
	 * post: cambiar el porcentajeDeCorreccion del ejercicio.
	 */
	void setPorcentajeDeCorreccion(double porcentajeDeCorreccion);

	/**
	 * pre: -
	 * post: devuelve verdadero si esta corregido el ejercicio o falso en caso contrario
	 */
	bool estaCorregido();
};

#endif /* EJERCICIO_H_ */
