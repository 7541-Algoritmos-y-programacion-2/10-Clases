/*
 * Nodo.h
 *
 *  Created on: 7 oct. 2023
 *      Author: gonzalo
 */

#ifndef NODO_H_
#define NODO_H_
#ifndef NULL
#define NULL 0
#endif

template<class T> class Nodo {
private:
	T dato;
	Nodo<T> *siguiente;

public:
	/*
	 * pre: -
	 * post: Nodo inicializado con dato y siguiente apunta a nulo.
	 */
	Nodo(T dato) {
		this->dato = dato;
		this->siguiente = NULL;
	}

	/*
	 * pre: -
	 * post: Devuelve el valor del dato.
	 */
	T obtenerDato() {
		return this->dato;
	}

	/*
	 * pre: -
	 * post: Cambia el valor del dato por el nuevo dato.
	 */
	void cambiarDato(T nuevoDato) {
		this->dato = nuevoDato;
	}
	/*
	 * pre: -
	 * post: Devuelve el siguiente nodo.
	 */
	Nodo<T> *obtenerSiguiente() {
		return this->siguiente;
	}

	/*
	 * pre: -
	 * post: Cambia el siguiente Nodo por nuevoSiguiente.
	 */
	void cambiarSiguiente(Nodo<T> *nuevoSiguiente) {
		this->siguiente = nuevoSiguiente;
	}
};
#endif /* NODO_H_ */
