/*
 * Examen.h
 *
 *  Created on: 29/09/2023
 *      Author: algo2
 */

#ifndef EXAMEN_H_
#define EXAMEN_H_
#include "Vector.h"
#include "Ejercicio.h"

class Examen {
private:
	Vector<Ejercicio *> * ejercicios;

	/**
	 * pre: -
	 * post: devuelve error si indice no esta en el rango del vector
	 */
	void validarIndice(unsigned int indice);

public:

	/**
	 * pre: cantidadDeEjercicios debe ser mayor a 0
	 * post: deja creado un Examen con cantidadDeEjercicios en estado sin corregir
	 */
	Examen(unsigned int cantidadDeEjercicios);

	/**
	 * pre: -
	 * post: libera la memoria de Examen
	 */
	virtual ~Examen();

	/**
	 * pre: -
	 * post: devuelve la cantidad de ejercicios del examen, esten o no corregidos
	 */
	int getCantidadDeEjercicios();

	/**
	 * pre: -
	 * post: devuelve la cantidad de ejercicios corregidos del examen
	 */
	int getCantidadDeEjerciciosCorregidos();

	/**
	 * pre: indice debe estar entre 1 y la cantidad de ejercicios
	 * post: devuelve el ejercicio indicado o error en caso contrario
	 */
	Ejercicio * getEjercicio(int indice);

	/**
	 * pre: -
	 * post: devuelve la suma de los puntajes de los ejercicios o error si falta
	 * 		 corregir algun ejercicio
	 */
	double getPuntaje();

	/**
	 * pre: -
	 * post: devuelve el promedio de los puntajes de los ejercicios o error si falta
	 *       corregir algun ejercicio
	 */
	double getPuntajePromedio();

	/**
	 * pre: -
	 * post: devuelve verdadero si todos los ejercicios estan corregidos
	 */
	bool estaCorregido();

	/**
	 * pre: -
	 * post: devuelve el porcentaje de correccion actual del examen
	 */
	double getPorcentajeDeCorreccion();
};

#endif /* EXAMEN_H_ */
