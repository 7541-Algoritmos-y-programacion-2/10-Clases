/*
 * Vector.h
 *
 *  Created on: 06/05/2022
 *      Author: algo2
 */

#ifndef VECTOR_H_
#define VECTOR_H_

template<class T> class Vector {
private:
		T * datos;
		int longitud;

public:

	/**
	 * pre:
	 * post:
	 */
	Vector(int longitud, T datoInicial) {
		this->datos = new T[longitud];
		this->longitud = longitud;
		for(int i = 0; i < this->longitud; i++){
			this->datos[i] = datoInicial;
		}
	}

	/**
	 * pre:
	 * post: libera la memoria
	 */
	virtual ~Vector() {
		delete [] this->datos;
	}

	/**
	 * pre:
	 * post: devuelve la longitud actual del vector
	 */
	int getLongitud() {
		return this->longitud;
	}

	/**
	 * pre: la posicion esta entre 1 y n (inclusive)
	 * pos: guarda el dato en la posicion indicada, sino devuelve error
	 */
	void agregar(int posicion, T dato) {
		if ((posicion < 1) ||
		   (posicion > this->longitud)) {
			throw "La " + posicion + " no esta en el rango 1 y " + this->longitud + " inclusive";
		}
		this->datos[posicion - 1] = dato;
	}

	/**
	 * pre: la posicion esta entre 1 y n (inclusive)
	 * pos: guarda el dato en la posicion indicada, sino devuelve error
	 */
	T& obtener(int posicion) {
		if ((posicion < 1) ||
		   (posicion > this->longitud)) {
			throw "La " + posicion + " no esta en el rango 1 y " + this->longitud + " inclusive";
		}
		return this->datos[posicion - 1];
	}
};

#endif /* VECTOR_H_ */
