/*
 * Lista.h
 *
 *  Created on: 22/04/2024
 *      Author: algo2
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"

class Lista {

private:
	Nodo * primero;
	unsigned int tamanio;

public:

	/**
	 * pre:
	 * pos: crea una lista vacia
	 */
	Lista();

	/**
	 * pre:
	 * pos: elimina la memoria de la lista, no de los datos
	 */
	virtual ~Lista();

	/**
	 * pre:
	 * pos: indica si la Lista tiene algún elemento.
	 */
	bool estaVacia();

    /*
	 * post: devuelve la cantidad de elementos que tiene la Lista.
	 */
	unsigned int getTamanio();

	/**
	 * pre: -
	 * pos: agrega el elemento al final de la Lista, en la posición:
     *       contarElementos() + 1.
	 */
	void agregar(int elemento);

	/**
	 * pre: posición pertenece al intervalo: [1, contarElementos() + 1]
	 * pos: agrega el elemento en la posición indicada.
	 */
	void agregar(int elemento, unsigned int posicion);

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: remueve de la Lista el elemento en la posición indicada.
     */
	void remover(unsigned int posicion);

	/**
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * pos: devuelve el dato de la posicion
	 */
	int obtener(unsigned int posicion);

	/**
	 * pre : posición pertenece al intervalo: [1, contarElementos()]
	 * pos: cambia el elemento de la posicion
	 */
	void cambiar(int elemento, unsigned int posicion);

private:

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: devuelve el nodo en la posición indicada.
     */
	Nodo * obtenerNodo(unsigned int posicion);

	void validarPosicion(unsigned int posicion);
};

#endif /* LISTA_H_ */
