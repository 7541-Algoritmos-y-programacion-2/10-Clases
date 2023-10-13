/*
 * Lista.h
 *
 *  Created on: 7 oct. 2023
 *      Author: gonzalo
 */

#ifndef LISTA_H_
#define LISTA_H_
#include "Nodo.h"

template<class T> class Lista {
private:
	Nodo<T> *primero;
	unsigned int longitud;
	Nodo<T> *cursor;

	/*
	 * pre: Posicion pertenece al intervalo [1, contarElementos()].
	 * post: Devuelve el nodo en la posicion indicada.
	 */
	Nodo<T> *obtenerNodo(unsigned int posicion);

	/*
	 * pre: -
	 * post: Valida el valor de la posicion pasado por parametro.
	 */
	void validarPosicion(unsigned int posicion);

public:
	/*
	 * pre: -
	 * post: Lista vacia.
	 */
	Lista();

	/*
	 * pre: -
	 * post: Lista identica a la Lista pasada por argumento.
	 */
	Lista(Lista<T> &otraLista);

	/*
	 * pre: -
	 * post: Indica si la Lista tiene algun elemento.
	 */
	bool estaVacia();

	/*
	 * pre: -
	 * post: Devuelve la cantidad de elementos que tiene la Lista
	 */
	unsigned int contarElementos();

	/*
	 * pre: -
	 * post: Agrega elemento al final de la Lista, posicion contarElemento + 1.
	 */
	void agregarElemento(T elemento);

	/*
	 * pre: Posicion pertenece al intervalo: [1, contarElementos() + 1].
	 * post: Agrega el elemento el la posicion indicada.
	 */
	void agregarElemento(T elemento, unsigned int posicion);

	/*
	 * pre: -
	 * post: Agrega todos los elementos de otra Lista a partir de la posicion contarElemento + 1.
	 */
	void agregarElemento(Lista<T> &otraLista);

	/*
	 * pre: Posicion pertenece al intervalo: [1, contalElementos()].
	 * post: Devuelve el elemento en la posicion indicada
	 */
	T obtenerElemento(unsigned int posicion);

	/*
	 * pre: Posicion pertenece al intervalo: [1, contarElementos()].
	 * post: Cambia el elemento de posicion indicada por el elemento pasado por parametro.
	 */
	void asignarElemento(T elemento, unsigned int posicion);

	/*
	 * pre: Posicion pertene al intervalo: [1, contarElementos()].
	 * post: Remueve de la Lista el elemento en la posicion indicada.
	 */
	void removerElemento(unsigned int posicion);

	/*
	 * pre: -
	 * post: Deja cursor de la Lista preparada para hacer nuevo recorrido.
	 */
	void iniciarCursor();

	/*
	 * pre:
	 * post:
	 */
	bool avanzarCursor();

	/*
	 * pre: El cursor esta posicionado sobre un elemento de la Lista.
	 * post: Devuelve el elemento en la posicion del cursor.
	 */
	T obtenerCursor();

	/*
	 * pre: -
	 * post: Libera los recursos asociados de la Lista.
	 */
	~Lista();
};

template<class T> Lista<T>::Lista() {
	this->primero = NULL;
	this->longitud = 0;
	this->cursor = NULL;
}
template<class T> Lista<T>::Lista(Lista<T> &otraLista) {
	this->primero = NULL;
	this->longitud = 0;
	this->cursor = NULL;

	//Copia los elementos de la otra lista
	this->agregarElemento(otraLista);
}

template<class T> void Lista<T>::validarPosicion(unsigned int posicion) {
	if(posicion < 1 || posicion > this->longitud + 1) {
		throw "La posicion esta fuera de rango";
	}
}

template<class T> bool Lista<T>::estaVacia() {
	return (this->longitud == 0);
}

template<class T> unsigned int Lista<T>::contarElementos() {
	return this->longitud;
}

template<class T> void Lista<T>::agregarElemento(T elemento) {
	this->agregarElemento(elemento, this->longitud + 1);
}

template<class T> void Lista<T>::agregarElemento(T elemento, unsigned int posicion) {
	this->validarPosicion(posicion);
	if((posicion > 0) && posicion <= this->longitud + 1) {
		Nodo<T> *nuevo = new Nodo<T>(elemento);
		if(posicion == 1) {
			nuevo->cambiarSiguiente(this->primero);
			this->primero = nuevo;
		}
		else {
			Nodo<T> *anterior = this->obtenerNodo(posicion - 1);
			nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
			anterior->cambiarSiguiente(nuevo);

		}
		this->longitud++;

		//Se reinicia el cursor
		this->iniciarCursor();
	}
}

template<class T> void Lista<T>::agregarElemento(Lista<T> &otraLista) {
	otraLista.iniciarCursor();
	while(otraLista.avanzarCursor()) {
		this->agregarElemento(otraLista.obtenerCursor());
	}
}

template<class T> T Lista<T>::obtenerElemento(unsigned int posicion) {
	this->validarPosicion(posicion);
	T elemento;
	if((posicion > 0) && posicion <= this->longitud) {
		elemento = this->obtenerNodo(posicion)->obtenerDato();
	}
	return elemento;
}

template<class T> void Lista<T>::asignarElemento(T elemento, unsigned int posicion) {
	this->validarPosicion(posicion);
	if((posicion > 0) && posicion <= this->longitud) {
		this->obtenerNodo(posicion)->cambiarDato(elemento);
	}
}

template<class T> void Lista<T>::removerElemento(unsigned int posicion) {
	this->validarPosicion(posicion);
	if((posicion > 0) && (posicion <= this->longitud)) {
		Nodo<T> *removido;
		if(posicion == 1) {
			removido = this->primero;
			this->primero->cambiarSiguiente(removido->obtenerSiguiente());
		}
		else {
			Nodo<T> *anterior = this->obtenerNodo(posicion - 1);
			removido = anterior->obtenerSiguiente();
			anterior->cambiarSiguiente(removido->obtenerSiguiente());
		}
		delete removido;
		this->longitud--;
		//Se reinicia el cursor
		this->iniciarCursor();
	}
}

template<class T> void Lista<T>::iniciarCursor() {
	this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzarCursor() {
	if(this->cursor == NULL) {
		this->cursor = this->primero;
	}
	else {
		this->cursor = this->cursor->obtenerSiguiente();
	}
	return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtenerCursor() {
	T elemento;
	if(this->cursor != NULL) {
		elemento = this->cursor->obtenerDato();
	}
	return elemento;
}

template<class T> Lista<T>::~Lista() {
	while(this->primero != NULL) {
		Nodo<T> *aBorrar = this->primero;
		this->primero = this->primero->obtenerSiguiente();
		delete aBorrar;
	}
}

template<class T> Nodo<T> *Lista<T>::obtenerNodo(unsigned int posicion) {
	this->validarPosicion(posicion);
	Nodo<T> *actual = this->primero;
	for(unsigned int i = 1; i < posicion; i++) {
		actual = actual->obtenerSiguiente();
	}
	return actual;
}
#endif /* LISTA_H_ */
