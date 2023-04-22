/*
 * Estudiante.h
 *
 *  Created on: 14/04/2023
 *      Author: algo2
 */

#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

#include <string>

class Estudiante {
private:
	std::string nombre;
	std::string apellido;
	unsigned int padron;

public:
	/**
	 * pre: el apellido no puede ser vacio, el nombre no puede ser vacio, el padron debe ser mayor a 0
	 * post:el estudiante queda creado con este nombre, apellido y padron
	 */
	Estudiante(std::string apellido, std::string nombre, unsigned int padron);
	//virtual ~Estudiante();

	/**
	 * pre:-
	 * post: devuelve el nombre del estudiante
	 */
	std::string getNombre();

	/**
	 * pre:-
	 * post: devuelve el apellido del estudiante
	 */
	std::string getApellido();

	/**
	 * pre:-
	 * post: devuelve el padron del estudiante
	 */
	unsigned int getPadron();

	/**
	 * pre: -
	 * post: devuelve el apelido " " nombre
	 */
	std::string getNombreCompleto();
};

#endif /* ESTUDIANTE_H_ */
