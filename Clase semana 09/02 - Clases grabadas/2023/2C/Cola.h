/*
 * Cola.h
 *
 *  Created on: 28/10/2021
 *      Author: algo2
 */

#ifndef COLA_H_
#define COLA_H_

#include "Nodo.h"

template<class T> class Cola {

private:

    Nodo<T>* frente;

    Nodo<T>* ultimo;

    unsigned int tamanio;

public:
    /**
     * pre:
     * post: inicializa la cola vacia para su uso
     */
	Cola();

    /*
     * post: indica si la cola tiene algún elemento.
     */
    bool estaVacia();

    /*
     * pre :
     * post: devuelve el elemento en el frente de la cola.
     */
    T& desacolar();

    /*
     * pre: el elemento no es vacio
     * post: agrega el elemento a la cola
     */
    void acolar (const T& elemento);

    /*
     * pre: el elemento no es vacio
     * post: agrega todos los elementos a la cola
     */
    void acolarTodos (const Cola<T> * otraCola);

    /*
	* post: devuelve la cantidad de elementos que tiene la cola.
	*/
    unsigned int contarElementos();

    /**
     * pre:
     * post: elimina la cola
     */
	virtual ~Cola();
};

template<class T> Cola<T>::Cola() {
    this->frente = NULL;
    this->ultimo = NULL;
    this->tamanio = 0;
}

template<class T> Cola<T>::~Cola() {
    while (!this->estaVacia()) {
        Nodo<T>* aBorrar = this->desacolar();
        delete aBorrar;
    }
}

template<class T> bool Cola<T>::estaVacia() {
    return (this->tamanio == 0);
}

template<class T> T& Cola<T>::desacolar() {

    T elemento; //int elemento

    if (this->frente != NULL) {

        elemento = this->frente->obtenerDato();
    }

    return elemento;
}

template<class T> void Cola<T>::acolar(const T& elemento) {

	Nodo<T>* nuevo = new Nodo<T>(elemento);
	if (this->estaVacia()) {
        nuevo->cambiarSiguiente(this->frente);
        this->frente = nuevo;
	} else {
		this->frente = nuevo;
		this->ultimo = nuevo;
	}
}

template<class T> unsigned int Cola<T>::contarElementos() {

    return this->tamanio;
}

template<class T> void Cola<T>::acolarTodos (const Cola<T> * otraCola) {
	while (!otraCola->estaVacia()) {
		T elemento = otraCola->desacolar();
		this->acolar( elemento );
	}
}

#endif /* COLA_H_ */
