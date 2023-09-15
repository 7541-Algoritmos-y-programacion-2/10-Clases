/*
 * Vector.h
 *
 *  Created on: 14/09/2023
 *      Author: algo2
 */

#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
	private:
		int * valores;
		unsigned int longitud;

		/**
		 * pre: -
		 * post: valida que la longitud este en el rango 1-longitud o lanza excepcion
		 */
		void validarLongitud(unsigned int longitud);

	public:

		/**
		 * pre: longitud tiene que ser mayor a 0
		 * post: deja el vector creado con valores en 0 con la longitud longitud
		 */
		Vector(unsigned int longitud);


		/**
		 * pre: -
		 * post: elimina el vector y la memoria utilizada
		 */
		virtual ~Vector();

		/**
		 * pre: el indice debe ser entre 1 y longitud
		 * post: asigna el valor en la posicion indice
		 */
		void setValor(unsigned int indice, int valor);


		/**
		 * pre: el indice debe ser entre 1 y longitud
		 * post: devuelve el valor en la posicion indice
		 */
		int getValor(unsigned int indice);

		/**
		 * pre: -
		 * post: devuelve la longitud del vector
		 */
		unsigned int getLongitud();

};

#endif /* VECTOR_H_ */
