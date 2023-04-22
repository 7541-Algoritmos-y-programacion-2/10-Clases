/*
 * Curso.h
 *
 *  Created on: 21/04/2023
 *      Author: algo2
 */

#ifndef CURSO_H_
#define CURSO_H_

#include "Estudiante.h"

static const int CUPOMAXIMO = 100;

class Curso {
private:
	std::string nombre;
	std::string codigo;
	unsigned int cupoMaximo;
	Estudiante ** inscriptos;

public:
	/**
	 * pre: codigo y nombre no puede ser vacio. CupoMaximo debe ser mayor a 1
	 * pos: crea un curso con el codigo, nombre y cupo maximo dado
	 */
	Curso(std::string codigo, std::string nombre, unsigned int cupoMaximo);

	/**
	 * pre: -
	 * pos:
	 */
	virtual ~Curso();

	/**
	 * pre: -
	 * pos: devuelve el nombre del curto
	 */
	std::string getNombre();

	/**
	 * pre:
	 * pos:
	 */
	std::string getCodigo();

	/**
	 * pre:
	 * pos:	 *
	 */
	unsigned int getCupoMaximo();

	/**
	 * pre:
	 * pos:
	 */
	unsigned int getCantidadDeInscriptos();

	/**
	 * pre: numero debe ser un numero entre 1 y MAX
	 * pos: devuelve el estudiante en esa posicion
	 */
	Estudiante * getInscripto(unsigned int numero);

	/**
	 * pre: un estudiante valido
	 * pos: queda inscripto en el curso si hay cupo, devuelve el cupo ocupado
	 */
	int inscribir(Estudiante * estudiante);

	void desinscribir(unsigned int numero);

private:
	void validarPosicion(int numero);

};

#endif /* CURSO_H_ */
