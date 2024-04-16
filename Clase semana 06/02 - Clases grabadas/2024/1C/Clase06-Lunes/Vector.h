/*
 * Vector.h
 *
 *  Created on: 15/04/2024
 *      Author: algo2
 */

#ifndef VECTOR_H_
#define VECTOR_H_

template <typename T>
class Vector {
	T * datos;
	unsigned int longitud;
	T datoInicial;

public:

	/**
	 * pre: la longitud es mayor o igual a 1. Y
	 *      Y el dato inicial puede ser NULL si es un puntero
	 * pos: deja un vector con las posiciones solicitadas
	 */
	Vector(unsigned int longitud, T datoInicial);

	/**
	 * pre:
	 * post: libera la memoria
	 */
	virtual ~Vector();

	/**
	 * pre:
	 * post: devuelve la longitud actual del vector
	 */
	int getLongitud();

	/**
	 * pre: la posicion esta entre 1 y n (inclusive)
	 * pos: guarda el dato en la posicion indicada, sino devuelve error
	 */
	void agregar(int posicion, T dato);

	/**
	 * pre: la posicion esta entre 1 y n (inclusive)
	 * pos: guarda el dato en la posicion indicada, sino devuelve error
	 */
	T& obtener(int posicion);

	/**
	 * pre: la posicion esta entre 1 y n (inclusive)
	 * pos: hace el delete de la posicion dada
	 */
	void remover(int posicion);

	/**
	 * pre: -
	 * pos: agregamos el dato en la primer posicion vacia, o sino hay mas espacio
	 *      agrandamos el vector en longitud. Luego devolvemos la posicion entre 1 y maximo
	 */
	int agregar(T dato);
};

template<typename T> Vector<T>::Vector(unsigned int longitud, T datoInicial) {
	if (longitud < 1) {
		throw "La longitud debe ser mayor o igual a 1";
	}
	this->datoInicial = datoInicial;
	this->datos = new T[longitud];
	this->longitud = longitud;
	for(int i = 0; i < this->longitud; i++){
		this->datos[i] = datoInicial;
	}
}

template<typename T> Vector<T>::~Vector() {
	delete [] this->datos;
}

template<typename T> int Vector<T>::getLongitud() {
	return this->longitud;
}

template<typename T> void Vector<T>::agregar(int posicion, T dato) {
	if ((posicion < 1) ||
	   (posicion > this->longitud)) {
		throw "La " + posicion + " no esta en el rango 1 y " + this->longitud + " inclusive";
	}
	this->datos[posicion - 1] = dato;
}

template<typename T> T& Vector<T>::obtener(int posicion) {
	if ((posicion < 1) ||
	   (posicion > this->longitud)) {
		throw "La " + posicion + " no esta en el rango 1 y " + this->longitud + " inclusive";
	}
	return this->datos[posicion - 1];
}

template<typename T> void Vector<T>::remover(int posicion) {
	if ((posicion < 1) ||
	   (posicion > this->longitud)) {
		throw "La " + posicion + " no esta en el rango 1 y " + this->longitud + " inclusive";
	}
	delete this->datos[posicion - 1];
	this->datos[posicion - 1] = NULL;
}

template<typename T> int Vector<T>::agregar(T dato)  {
	//validar dato;
	for(int i = 0; i < this->longitud; i++) {
		if (this->datos[i] == this->datoInicial) {
			this->datos[i] = dato;
			return i + 1;
		}
	}
	T * temp = new T[this->longitud * 2];
	for(int i = 0; i < this->longitud; i++) {
		temp[i] = this->datos[i];
	}
	delete [] this-datos;
	this->datos = temp;
	this->datos[this->longitud + 1] = dato;
	this->longitud *= 2;
	return (this->longitud / 2) + 1;
}

#endif /* VECTOR_H_ */
