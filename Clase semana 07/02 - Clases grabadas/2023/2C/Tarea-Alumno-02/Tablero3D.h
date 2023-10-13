/*
 * Tablero3D.h
 *
 *  Created on: 11 oct. 2023
 *      Author: gonzalo
 */

#ifndef TABLERO3D_H_
#define TABLERO3D_H_
#include "Lista.h"
#include "Casillero3D.h"

class Tablero3D {
private:
	Lista<Lista<Lista<Casillero3D *> * > *> *tablero3D;
	unsigned int ancho;
	unsigned int alto;
	unsigned int profundidad;

	/*
	 * pre: -
	 * post: Valida el ancho, largo y la profundidad del tablero.
	 */
	void validarAnchoLargoYProfundidad(unsigned int ancho, unsigned int alto, unsigned int profundidad);

	/*
	 * pre: -
	 * post: Valida las coordenadas x, y, z.
	 */
	void validarCoordenadaCasillero(unsigned int x, unsigned int y, unsigned int z);

public:
	/*
	 * pre: El ancho, largo y la profundidad deben ser mayor o igual a 1.
	 * post: Crea un tablero de dimensiones ancho*alto*profundidad.
	 */
	Tablero3D(unsigned int ancho, unsigned int alto, unsigned profundidad);

	/*
	 * pre: -
	 * post: Elimina el tablero de manera correcta.
	 */
	virtual ~Tablero3D();

	/*
	 * pre: -
	 * post: Devuelve el alto del tablero.
	 */
	unsigned int getAlto();

	/*
	 * pre: -
	 * post: Devuelve el ancho del tablero.
	 */
	unsigned int getAncho();

	/*
	 * pre: -
	 * post: Devuelve la profundidad del tablero.
	 */
	unsigned int getProfundidad();

	/*
	 * pre: Las 3 variables deben ser mayores o iguales a 1,
	 * 		x debe ser menor o igual al ancho,
	 * 		y debe ser menor o igual al alto y
	 * 		z debe ser menor o igual a la profundidad.
	 * post: Devuelve el casillero en la coordenada pasada por parametro.
	 */
	Casillero3D *getCasillero(unsigned int z, unsigned int x, unsigned int y);
};

#endif /* TABLERO3D_H_ */
