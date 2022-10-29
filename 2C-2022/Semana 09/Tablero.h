/*
 * Tablero.h
 *
 *  Created on: 20/10/2022
 *      Author: algo2
 */

#ifndef TABLERO_H_
#define TABLERO_H_

/**
 * Checklist de TDA:
 * Encapsular (ok)
 * PRE Y POS (falta)
 * Validar los parametros (falta)
 * Consistencia - incompleto (falta)
 */
class Tablero {
private:
	Lista<Lista<Casillero *> *> * tablero;

public:
	/**
	 * pre:
	 * pos:
	 */
	Tablero(unsigned int filas, unsigned int columnas);

	/**
	 * pre:
	 * pos:
	 */
	virtual ~Tablero();

	int getCantidadDeFilas();
	int getCantidadDeColumnas();

	Casillero * getCasillero(unsigned int i, unsigned int j);
};

#endif /* TABLERO_H_ */
