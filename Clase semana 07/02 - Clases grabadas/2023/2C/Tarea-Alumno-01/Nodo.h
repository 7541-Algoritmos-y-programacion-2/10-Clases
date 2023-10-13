#ifndef UNTITLED4_NODO_H
#define UNTITLED4_NODO_H
#include <cstddef>
template<class T> class Nodo {

private:

    T dato;
    Nodo<T>* siguiente;

public:

    /*
     * post: el Nodo resulta inicializado con el dato dado
     *       y sin un Nodo siguiente.
     */
    Nodo(T dato) {

        this->dato = dato;
        this->siguiente = NULL;
    }

    /*
     * post: devuelve el valor del dato.
     */
    T obtenerDato() {

        return this->dato;
    }

    /*
     * post: cambia el valor del dato.
     */
    void cambiarDato(T nuevoDato) {

        this->dato = nuevoDato;
    }

    /*
     * post: devuelve el siguiente Nodo.
     */
    Nodo<T>* obtenerSiguiente() {

        return this->siguiente;
    }

    /*
     * post: cambia el siguiente Nodo por nuevoSiguiente.
     */
    void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {

        this->siguiente = nuevoSiguiente;
    }
};


#endif //UNTITLED4_NODO_H