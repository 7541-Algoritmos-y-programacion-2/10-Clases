/*
 * VectorDeEnteros.h
 *
 *  Created on: 15/09/2023
 *      Author: algo2
 */

#ifndef VECTORDEENTEROS_H_
#define VECTORDEENTEROS_H_

class VectorDeEnteros {

private:
		unsigned int longitud;
		int * valores;

		void validarIndice(unsigned int indice);
public:

	/**
	 * pre: la longitud sea mayor a 0.
	 * post: crea el vector de enteros con el tamaño longitud. Inicializa todo en 0
	 */
	VectorDeEnteros(unsigned int longitud);

	/**
	 * pre: -
	 * post: eliminar el vector correctamente
	 */
	virtual ~VectorDeEnteros();

	/**
	 * pre: indice debe estar entre 1 y longitud del vector.
	 * post: deja el valor valor en la posicion indice del vector
	 */
	void setDato(unsigned int indice, int valor);

	/**
	 * pre: indice debe estar entre 1 y longitud del vector.
	 * post: devuelve el valor del vector en la posicion indice
	 */
	int getDato(unsigned int indice);

	/**
	 * pre: -
	 * post: devuelve la longitud del vector
	 */
	unsigned int getLongitud();
};

#endif /* VECTORDEENTEROS_H_ */
