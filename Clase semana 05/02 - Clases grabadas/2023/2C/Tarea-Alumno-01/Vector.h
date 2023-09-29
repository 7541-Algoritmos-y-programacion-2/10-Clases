#ifndef EJERCICIOSALGOIIPARTE1_VECTOR_H
#define EJERCICIOSALGOIIPARTE1_VECTOR_H

#include <iostream>

template <class T> class Vector {
private:
    T *datos;
    unsigned int longitud;
    /*
     * Pre: 0 <= indice < longitud
     * Pos: -
     */
    void validarIndice(unsigned int indice) {
        if (indice >= this->longitud) {
            throw std::invalid_argument("El indice debe ser menor a la longitud del vector");
        }
    }
public:
    /*
     * Pre: longitud > 0
     * Pos: Crea un vector de tamaño longitud
     */
    Vector(unsigned int longitud) {
        if (longitud <= 0) {
            throw std::invalid_argument("La longitud del vector debe ser mayor a 0");
        }
        this->longitud = longitud;
        this->datos = new T[longitud];

        // Inicializo los valores en NULL
        for (int i = 0; i < longitud; ++i) {
            this->datos[i] = NULL;
        }
    }

    /*
     * Pre: -
     * Pos: Obtiene la longitud del vector
     */
    virtual ~Vector() {
        delete [] this->datos;
    }

    /*
     * Pre: -
     * Pos: Obtiene la longitud del vector
     */
    unsigned int getLongitud() {
        return this->longitud;
    }

    /*
     * Pre: 0 <= indice < longitud
     * Pos: Obtiene el dato en la posicion indice
     */
    T getDato(unsigned int indice) {
        validarIndice(indice);
        return this->datos[indice];
    }

    /*
     * Pre: 0 <= indice < longitud
     * Pos: Setea el dato en la posicion indice
     */
    void setDato(unsigned int indice, T dato) {
        validarIndice(indice);
        if (this->datos[indice] != NULL) {
            throw std::invalid_argument("La posicion ya esta ocupada");
        }
        this->datos[indice] = dato;
    }
};


#endif //EJERCICIOSALGOIIPARTE1_VECTOR_H
