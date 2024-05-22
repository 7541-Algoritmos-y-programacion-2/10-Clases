/*
 * Nodo.h
 *
 *  Created on: 18/05/2024
 *      Author: algo2
 */

#ifndef NODO_H_
#define NODO_H_


#define NULL 0

template <typename T>
class Nodo{

private:

	T dato;
	Nodo<T> *siguiente;

public:

	/*
	 * pre:
	 * pos: Se crea un Nodo con el dato pasado por parametro y su siguiente en NULL.
	 */
	Nodo(T dato);

	/*
	 * pre:
	 * pos: Libera la memoria
	 */
	virtual ~Nodo();

	/*
	 * pre:
	 * pos: Devuelve el dato del Nodo.
	 */
	T getDato();

	/*
	 * pre:
	 * pos: Cambia el dato del Nodo
	 */
	void setDato(T dato);

	/*
	 * pre:
	 * pos: Devuelve el siguiente del Nodo.
	 *
	 */
	Nodo<T>* getSiguiente();

	/*
	 * pre:
	 * pos: Cambia el siguiente del Nodo.
	 */
	void setSiguiente(Nodo<T> *siguiente);

};

template <typename T>
Nodo<T>::Nodo(T dato){

	this->dato = dato;
	this->siguiente = NULL;
}

template <typename T>
Nodo<T>::~Nodo(){
}


template <typename T>
T Nodo<T>::getDato(){
	return this->dato;
}

template <typename T>
void Nodo<T>::setDato(T dato){
	this->dato = dato;
}


template <typename T>
Nodo<T>* Nodo<T>::getSiguiente(){
	return this->siguiente;
}


template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente){

	this->siguiente = siguiente;
}


#endif /* NODO_H_ */
