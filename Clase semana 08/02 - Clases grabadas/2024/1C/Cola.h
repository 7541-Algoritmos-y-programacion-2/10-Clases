/*
 * Cola.h
 *
 *  Created on: 29/04/2024
 *      Author: algo2
 */

#ifndef COLA_H_
#define COLA_H_
#include "Nodo.h"

template<typename T>
class Cola {

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

    /**
     * pre:
     * post: elimina la cola
     */
	virtual ~Cola();

    /*
     * post: indica si la cola tiene algún elemento.
     */
    bool estaVacia();

    /*
     * pre: el elemento no es vacio
     * post: agrega el elemento a la cola
     */
    void acolar (const T& elemento);

    void acolar(Lista<T> * lista);

    /*
     * pre :
     * post: devuelve el elemento en el frente de la cola quitandolo.
     */
    T& desacolar();

    /*
     * pre :
     * post: devuelve el elemento en el frente de la cola. Solo lectura
     */
    T& obtener();

    /*
	* post: devuelve la cantidad de elementos que tiene la cola.
	*/
    unsigned int contarElementos();
};

template<typename T> Cola<T>::Cola() {
    this->frente = NULL;
    this->ultimo = NULL;
    this->tamanio = 0;
}

template<typename T> Cola<T>::~Cola() {
    while (!this->estaVacia()) {
        this->desacolar();
    }
}

template<typename T> bool Cola<T>::estaVacia() {
    return (this->tamanio == 0);
}


template<typename T> void Cola<T>::acolar(const T& elemento) {
	Nodo<T>* nuevo = new Nodo<T>(elemento);
	if (!this->estaVacia()) {
        nuevo->cambiarSiguiente(this->ultimo);
        this->ultimo = nuevo;
	} else {
		this->frente = nuevo;
		this->ultimo = nuevo;
	}
}

template<typename T> void Cola<T>::acolar(Lista<T> * lista) {
	//validar
	lista->iniciarCursor();
	while (!lista->avanzarCursor()) {
		this->acolar(lista->obtenerCursor());
	}
}

template<class T> T& Cola<T>::desacolar() {
    T elemento;
    if (!this->estaVacia()) {
        elemento = this->frente->obtenerDato();
        Nodo<T> * aBorrar = this->frente;
        this->frente = this->frente->getSiguiente();
        delete aBorrar;
    }
    return elemento;
}

template<class T> T& Cola<T>::obtener() {
    T elemento;
    if (!this->estaVacia()) {
        elemento = this->frente->obtenerDato();
    }
    return elemento;
}

template<class T> unsigned int Cola<T>::contarElementos() {

    return this->tamanio;
}

#endif /* COLA_H_ */
