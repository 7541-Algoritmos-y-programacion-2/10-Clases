/*
 * Lista.h
 *
 *  Created on: 15/04/2024
 *      Author: algo2
 */

#ifndef LISTA_H_
#define LISTA_H_

const unsigned int MAX = 100;
class Lista {
private:
	char datos[MAX];
	unsigned int tope;

public:
	/**
	 *
	 */
	Lista();

	/**
	 *
	 */
	virtual ~Lista();

	/*
	 * pre: -
	 * pos: si la lista no esta llena, inserta el dato al final
	 */
	void insertar(char dato);

	/**
	 * pre: -
	 * pos: devuelve verdadero si la lista esta llena o falso en caso contrario
	 */
	bool estaLlena();

	/**
	 * pre: -
	 * pos: devuelve verdadero si la lista no tiene elementos
	 */
	bool estaVacia();

	/**
	 * pre:
	 * pos:
	 */
	char obtenerDato(int posicion);
};

#endif /* LISTA_H_ */
