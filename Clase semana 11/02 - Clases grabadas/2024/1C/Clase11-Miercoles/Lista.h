/*
 * listas.h
 *
 *  Created on: 18/05/2024
 *      Author: algo2
 */

#ifndef LISTA_H_
#define LISTA_H_


#include "Nodo.h"

template <typename T>
class Lista{

private:

	Nodo<T> * cursor;
	Nodo<T> * primero;
	unsigned int longitud;

	 /*
	  *  pre: La posicion esta en el intervalo (1 a getLongitud() + 1]
	  *  pos: Retorna la direccion de memoria del puntero Nodo<T> en la posicion indicada
	  */
	Nodo<T> * obtenerNodo(unsigned int posicion);

	/*
	 * pre: La posicion existe
	 * pos: Devuelve un error throw si la posicion no cumple las condiciones y en caso contrario no hace nada
	 */
	void validarPosicion(unsigned int posicion);

public:

	/*
	 * pre:-
	 * pos:se crea una Lista vacia
	 */
	Lista();

	/*
	 * pre:-
	 * pos:libera la memoria reservada en por Lista, no elimina los datos
	 */

	virtual ~Lista();

	/*
	 * pre:-
	 * post: devuelve true si la Lista ESta vacia o false de lo contrario
	 */
	bool estaVacia();

	/*
	 * pre:-
	 * pos:Devuelve el tamaño de la Lista
	 */
	unsigned int getLongitud();

	/*
	 * pre:-
	 * pos: Agrega el elemento al final de la Lista en la posicion getLongitud() + 1
	 */
	void agregar(T elemento);

	/*
	* pre: La posicion esta en el intervalo (1 a getLongitud() + 1]
	* pos: Agrega un elemento en la posicion indicada
	**/
	void agregar(T elemento, unsigned int posicion);

	/*
	 * pre: La posicion esta en el intervalo (1 a getLongitud() + 1]
	 * pos: Retorna el dato de la posicion
	 */

	T obtener(unsigned int posicion);

	/*
	 * pre: La posicion pertenece al intervalo [1,contarElementos()]
	 * pos: Remueve de la lista en elemento en la posicion indicada.
	 */
	void remover(unsigned int posicion);

	/*
	 * pre: Posicion pertenece al intervalo [1,contarElementos()]
	 * pos: Cambia el elemento en la posicion.
	 *
	 */
	void cambiar(T elemento, unsigned int posicion);

	/*
	 * pre:
	 * pos: Asigna NULL al cursor.
	 */
	void iniciarCursor();

	/*
	 * pre: Se invoca un recorrido
	 * pos: Asigna al cursor el siguiente del elemento actual y retorna verdadero si el cursor es distinto de NULL.
	 */
	bool avanzarCursor();

	/*
	 * pre: El cursor el distinto de NULL.
	 * pos: Devuelve el elemento del cursor actual.
	 */
	T obtenerCursor();



};


template <typename T>
Lista<T>::Lista(){
	this->cursor=NULL;
	this->primero=NULL;
	this->longitud = 0;

}

template <typename T>
Lista<T>::~Lista(){

	while(this->primero != NULL){
		Nodo<T> *aBorrar = this->primero;
		this->primero = aBorrar->getSiguiente();
		delete aBorrar;
	}

}


template <typename T>
bool Lista<T>::estaVacia(){

	return this->longitud == 0;
}

template <typename T>
unsigned int Lista<T>::getLongitud(){

	return this->longitud;
}



template <typename T>
void Lista<T>::agregar(T elemento){
	this->agregar(elemento,this->getLongitud() + 1);
}

template <typename T>
void Lista<T>::agregar(T elemento, unsigned int posicion){
	validarPosicion(posicion);

	Nodo<T> *nuevo = new Nodo<T>(elemento);

	if(posicion == 1){
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
	}
	else{
		Nodo<T> *anterior = this->obtenerNodo(posicion - 1);
		nuevo->setSiguiente(anterior->getSiguiente());
		anterior->setSiguiente(nuevo);
	}
	this->longitud++;
}

template <typename T>
Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion){
	validarPosicion(posicion);
	Nodo<T> *actual = this->primero;
	for(unsigned int i = 1; i < posicion; i++){
		actual = actual->getSiguiente();
	}
	return actual;
}


template <typename T>
void Lista<T>::validarPosicion(unsigned int posicion){

	if((posicion < 1) || (posicion > this->getLongitud() + 1)){
		throw "La posicion debe estar entre 1 y getLongitud() + 1";
	}
}

template <typename T>
void Lista<T>::remover(unsigned int posicion){

	validarPosicion(posicion);

	Nodo<T> *aBorrar;

	if(posicion == 1){
		aBorrar = this->primero;
		this->primero = primero->getSiguiente();
	}
	else{
		Nodo<T> *anterior = obtenerNodo(posicion - 1);
		aBorrar = anterior->getSiguiente();
		anterior->setSiguiente(aBorrar->getSiguiente());

	}

	delete aBorrar;
	this->longitud--;
}


template <typename T>
void Lista<T>::cambiar(T elemento, unsigned int posicion){

	validarPosicion(posicion);
	this->obtenerNodo(posicion)->setDato(elemento);
}

template <typename T>
void Lista<T>::iniciarCursor(){
	this->cursor = NULL;
}

template <typename T>
bool Lista<T>::avanzarCursor(){
	if(this->cursor == NULL){
		this->cursor = this->primero;
	}
	else{
		this->cursor = cursor->getSiguiente();
	}

	return (this->cursor != NULL);
}

template <typename T>
T Lista<T>::obtenerCursor(){
	T elemento;
	if(this->cursor != NULL){
		elemento = this->cursor->getDato();
	}
}


template <typename T>
T Lista<T>::obtener(unsigned int posicion){
	validarPosicion(posicion);
	return this->obtenerNodo(posicion)->getDato();
}



#endif /* LISTA_H_ */
