#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif /* NULL*/

template<class T> class Nodo {

private:

	T dato;
	Nodo<T> *siguiente;

public:

	/*
	 * pre : -
	 * post: Inicializa el Nodo con un dato dado y sin Nodo siguiente.
	 */
	Nodo(T dato) {

		this->dato = dato;
		this->siguiente = NULL;
	}

	/*
	 * pre : -
	 * post: Libera los recursos asociados al Nodo.
	 */
	virtual ~Nodo() {
	}

	/*
	 * pre : -
	 * post: Devuelve el dato del Nodo.
	 */
	T obtenerDato() const {

		return this->dato;
	}

	/*
	 * pre : -
	 * post: Devuelve el puntero al siguiente Nodo.
	 */
	Nodo<T>* obtenerSiguiente() const {

		return this->siguiente;
	}

	/*
	 * pre : -
	 * post: Reemplaza el valor del dato por nuevoDato.
	 */
	void reemplazarDato(T nuevoDato) {

		this->dato = nuevoDato;
	}

	/*
	 * pre : -
	 * post: Reemplaza el siguiente Nodo por nuevoSiguiente.
	 */
	void reemplazarSiguiente(Nodo<T> *nuevoSiguiente) {

		this->siguiente = nuevoSiguiente;
	}

};

#endif /* NODO_H_ */
