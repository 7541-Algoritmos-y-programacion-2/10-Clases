/*
 * Nodo.h
 *
 *  Created on: 22/04/2024
 *      Author: algo2
 */

#ifndef NODO_H_
#define NODO_H_

class Nodo {
private:
	int dato;
	Nodo * siguiente;

public:
	/**
	 * pre: -
	 * pos: el Nodo resulta inicializado con el dato dado
     *       y sin un Nodo siguiente.
	 */
	Nodo(int dato);

	/**
	 * pre:
	 * pos: elimina la memoria
	 */
	virtual ~Nodo(); //no hago delete

	/**
	 * pre:
	 * pos: devuelve el dato del nodo
	 */
	int getDato();

	/**
	 * pre:
	 * pos: cambia el dato del nodo
	 */
	void setDato(int dato);

	/**
	 * pre:
	 * pos: devuelve el siguiente nodo
	 */
	const Nodo* getSiguiente();

	/**
	 * pre:
	 * pos: cambia el nodo siguiente
	 */
	void setSiguiente(Nodo* siguiente);
};

#endif /* NODO_H_ */
