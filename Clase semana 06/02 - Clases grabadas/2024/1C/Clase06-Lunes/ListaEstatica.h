/*
 * ListaEstatica.h
 *
 *  Created on: 15/04/2024
 *      Author: algo2
 */

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
// Tamaño máximo de la lista const int MAX_TAM = 10;
static const int MAX_TAM = 10;

/** Clase Lista_estatica Implementada con un vector de elementos
y un tamaño fijo (MAX_TAM)	*/

class ListaEstatica {
private:
	// Vector donde se iran agregando los elementos dato lista[MAX_TAM];
	// Tamaño lógico de la lista int tope;
	char datos[MAX_TAM];
	int tope;

public:
	// Constructor
	// PRE:	ninguna
	// POST: crea una lista vacía con tope = 0 Lista_estatica();
	ListaEstatica();

	// Destructor
	// PRE:	la lista fue creada
	// POST: nada (no tiene código ya que es estática)
	~ListaEstatica();

	// Inserta un dato
	// PRE:	lista creada
	// POST: Si la lista no está llena
	//	- se inserta al final el dato d
	//	- tope se incrementa en 1
	//	Si la lista está llena no hace nada void insert(dato d);

	// Indica si la lista está vacía o no
	// PRE:	lista creada
	// POST: Devuelve TRUE si la lista está vacía
	//	Sino devuelve FALSE bool lista_vacia();

	// Indica si la lista está llena o no
	// PRE:	lista creada
	// POST: Devuelve TRUE si la lista está llena
	//	Sino devuelve FALSE bool lista_llena();

	// Devuelve el dato que está en posicion
	// PRE:	- lista creada
	//	- no vacía
	//	- 0 < posicion <= tope
	// POST: devuelve el dato que está en posición
	//	Nota: se toma 1 como la primera posición dato get_dato(int posicion);

	// Borrado de un dato
	// PRE:	- lista creada
	//	- no vacía
	//	- 0 < posicion <= tope
	// POST: - se borra el dato que está en posición
	//	- tope se decrementa en 1
	//	Nota: se toma 1 como la primera posición void del_dato(int posicion);

	// Devuelve el tamaño lógico de la lista
	// PRE:	lista creada
	// POST: devuelve el valor de tope int get_tope();
	};
	// =====================================
	// Invariantes
	// tope >= 0
	// tope <= MAX_TAM

#endif
