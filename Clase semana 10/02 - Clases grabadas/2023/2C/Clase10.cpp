//============================================================================
// Name        : Clase10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Ascensor.h"
using namespace std;

class Libro {

  public:

    /* post: inicializa el Libro sin autores
     *       asociados y con el titulo indicado.
     */
    Libro(string titulo);

    ~Libro();

    /* post: devuelve el titulo del Libro.
     */
    string getTitulo();

    /* post: devuelve los nombres de los autores del Libro.
     */
    Lista<string>* getAutores();
};

class Estante {

  public:

    /* post: inicializa el Estante sin Libros asignados.
     */
    Estante();

    /* post: elimina todos los Libros que tiene el Estante.
     */
    ~Estante();

    /* post: devuelve todos los Libros asignados al Estante.
     */
    Lista<Libro*>* getLibros();

    /* post: devuelve aquellos Libros que fueron prestados,
     *       pero que están asignados al Estante.
     */
    Lista<Libro*>* getLibrosPrestados();
};


class Bibliotecario {
  public:

	/**
	 * pre:
	 * post: devuelve verdadero si el libro esta en el conjunto
	 */
	bool existe(Libro *libro, Lista<Libro *> * libros) {
		libros->iniciarCursor();
		while (libros->avanzarCursor()) {
			if (libros->obtenerCursor()->getTitulo() == libro->getTitulo()) {
				return true;
			}
		}
		return false;
	}

	/**
	 * pre:
	 * pos:
	 */
	bool existe(string autor, Lista<string> * autores) {
		autores->iniciarCursor();
		while (autores->avanzarCursor()) {
			if (autores->obtenerCursor() == autor) {
				return true;
			}
		}
		return false;
	}

	/**
	 * pre:
	 * pos: busca en estante aquellos Libros que no están prestados y que uno de sus autores es autorBuscado.
     *          Devuelve una nueva Lista con todos los Libros en esta condición
	 */
	Lista<Libro*>* buscarLibrosNoPrestadosPorAutor(Estante* estante,
	    												string autorBuscado) {
		//validar
		Lista<Libro*>* resultado = new Lista<Libro*>();
		estante->getLibros()->iniciarCursor();
		while (estante->getLibros()->avanzarCursor()) {
			Libro * libro = estante->getLibros()->obtenerCursor();
			if (!existe(libro, estante->getLibrosPrestados()) &&
				 existe(autorBuscado, libro->getAutores())) {
				resultado->agregarElemento(libro);
			}
		}
		return resultado;
	}

    /*
     * pre:
     * post: busca en estantes aquellos Libros que no están prestados y que uno de sus autores es autorBuscado.
     *          Devuelve una nueva Lista con todos los Libros en esta condición. */
    Lista<Libro*>* buscarLibrosNoPrestadosPorAutor(Lista<Estante*>* estantes,
    												string autorBuscado) {
    	//validar
    	Lista<Libro*>* resultado = new Lista<Libro*>();
    	estantes->iniciarCursor();
    	while (estantes->avanzarCursor()) {
    		Estante * estante = estantes->obtenerCursor();
    		Lista<Libro*> * resultadoParcial = buscarLibrosNoPrestadosPorAutor(estante, autorBuscado);
    		resultado->agregarElementos(resultadoParcial);
    		delete resultadoParcial;
    	}
    	return resultado;
    }
};



int main() {
	//Main Punto TDA
	Ascensor * ascensor = new Ascensor(11);
	ascensor->getPisoActual();


	//Main punto listas
	return 0;
}
