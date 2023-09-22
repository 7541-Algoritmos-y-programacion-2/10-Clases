/*
 * Vector.h
 *
 *  Created on: 22/09/2023
 *      Author: algo2
 */

#ifndef VECTOR_H_
#define VECTOR_H_

template<class T> class Vector {
private:
	unsigned int longitud;
	T * valores;

	void validarIndice(unsigned int indice){
		if (indice < 1) {
			throw "El indice debe ser 1 o mayor";
		}
		if (indice > this->longitud) {
			throw "El indice debe ser longitud o menor";
		}
	}

public:

	/**
	 * pre: la longitud sea mayor a 0.
	 * post: crea el vector de enteros con el tamaño longitud. Inicializa todo en 0
	 */
	Vector(unsigned int longitud) {
		if (longitud <= 0) {
			throw "La longitud debe ser mayor a 0";
		}

		this->longitud = longitud;
		this->valores = new T[this->longitud];

		//Inicializo los valores en 0
		for(int i = 0; i < this->longitud; i++) {
			this->valores[i] = 0; //NULL
		}
	}

	/**
	 * pre: -
	 * post: eliminar el vector correctamente
	 */
	virtual ~Vector(){
		delete [] this->valores;
	}

	/**
	 * pre: indice debe estar entre 1 y longitud del vector.
	 * post: deja el valor valor en la posicion indice del vector
	 */
	void setDato(unsigned int indice, T valor){
		validarIndice(indice);
		this->valores[indice-1] = valor;
	}

	/**
	 * pre: indice debe estar entre 1 y longitud del vector.
	 * post: devuelve el valor del vector en la posicion indice
	 */
	T getDato(unsigned int indice){
		validarIndice(indice);
		return this->valores[indice-1];
	}

	/**
	 * pre: -
	 * post: devuelve la longitud del vector
	 */
	unsigned int getLongitud(){
		return this->longitud;
	}
};

#endif /* VECTOR_H_ */
