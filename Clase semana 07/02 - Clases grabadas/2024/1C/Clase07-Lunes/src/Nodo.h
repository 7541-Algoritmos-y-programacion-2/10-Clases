/*
 * Nodo.h
 *
 *  Created on: 22/04/2024
 *      Author: algo2
 */

#ifndef NODO_H_
#define NODO_H_

template <typename T>
class Nodo {
private:
	T dato;
	Nodo<T> * siguiente;
	Nodo<T> * anterior;

public:
	/**
	 * pre: -
	 * pos: el Nodo resulta inicializado con el dato dado
     *       y sin un Nodo siguiente.
	 */
	Nodo(T dato);

	/**
	 * pre:
	 * pos: elimina la memoria
	 */
	virtual ~Nodo(); //no hago delete

	/**
	 * pre:
	 * pos: devuelve el dato del nodo
	 */
	T getDato();

	/**
	 * pre:
	 * pos: cambia el dato del nodo
	 */
	void setDato(T dato);

	/**
	 * pre:
	 * pos: devuelve el siguiente nodo
	 */
	Nodo<T>* getSiguiente();

	/**
	 * pre:
	 * pos: cambia el nodo siguiente
	 */
	void setSiguiente(Nodo<T>* siguiente);
};

template <typename T> Nodo<T>::Nodo(T dato) {
	this->dato = dato;
	this->siguiente = NULL;
}

template <typename T> Nodo<T>::~Nodo() {}


template <typename T> T Nodo<T>::getDato() {
	return this->dato;
}

template <typename T> void Nodo<T>::setDato(T dato) {
	this->dato = dato;
}

template <typename T> Nodo<T>* Nodo<T>::getSiguiente() {
	return this->siguiente;
}

template <typename T> void Nodo<T>::setSiguiente(Nodo<T>* siguiente) {
	this->siguiente = siguiente;
}

#endif /* NODO_H_ */
