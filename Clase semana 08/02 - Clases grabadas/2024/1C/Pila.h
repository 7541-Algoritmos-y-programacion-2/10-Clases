/*
 * Pila.h
 *
 *  Created on: 29/04/2024
 *      Author: algo2
 */

#ifndef PILA_H_
#define PILA_H_

#include "Nodo.h"

template<typename T>
class Pila {

private:
	Nodo<T>* tope;
	unsigned int tamanio;

public:

    /**
     * pre:
     * post: inicializa la pila vacia para su uso
     */
	Pila();

    /**
     * pre:
     * post: elimina la pila, no el contenido
     */
	virtual ~Pila();

    /*
     * post: indica si la cola tiene algún elemento.
     */
	bool estaVacia();

    /*
     * pre: el elemento no es vacio
     * post: agrega el elemento a la pila
     */
	void apilar(const T& elemento);

	void apilar(Lista<T> * lista);

    /*
     * pre :
     * post: devuelve el elemento en el tope de la pila y achica la pila en 1.
     */
	T& desapilar();

	/**
	 * pre: -
	 * post: devuelve el elemento en el tope de la pila (solo lectura)
	 */
	T& obtener();

    /*
	* post: devuelve la cantidad de elementos que tiene la cola.
	*/
    unsigned int contarElementos();
};

template<typename T> Pila<T>::Pila() {
    this->tope = NULL;
    this->tamanio = 0;
}

template<typename T> Pila<T>::~Pila() {
    while (!this->estaVacia()) {
        this->desapilar();
    }
}

template<typename T> bool Pila<T>::estaVacia() {
    return (this->tamanio == 0);
}

template<typename T> void Pila<T>::apilar(const T& elemento) {
	Nodo<T>* nuevo = new Nodo<T>(elemento);
	nuevo->cambiarSiguiente(this->tope);
	this->tope = nuevo;
}

template<typename T> void Pila<T>::apilar(Lista<T> * lista) {
	//validar
	lista->iniciarCursor();
	while (!lista->avanzarCursor()) {
		this->apilar(lista->obtenerCursor());
	}
}

template<typename T> T& Pila<T>::desapilar() {
    T elemento;
    if (!this->estaVacia()) {
    	elemento = this->tope->obtenerDato();
    	Nodo<T>* aBorrar = this->tope;
    	this->tope = this->tope->getSiguiente();
    	delete aBorrar;
    }
    return elemento;
}

template<typename T> T& Pila<T>::obtener() {
    T elemento;
    if (!this->estaVacia()) {
    	elemento = this->tope->obtenerDato();
    }
    return elemento;
}

template<typename T> unsigned int Pila<T>::contarElementos() {
    return this->tamanio;
}

#endif /* PILA_H_ */
