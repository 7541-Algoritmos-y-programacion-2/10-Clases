/*
 * Casillero3D.h
 *
 *  Created on: 11 oct. 2023
 *      Author: gonzalo
 */

#ifndef CASILLERO3D_H_
#define CASILLERO3D_H_

class Casillero3D {
private:
	char ficha;
	unsigned int x;
	unsigned int y;
	unsigned int z;

	/*
	 * pre: -
	 * post: Valida las coordenadas x, y, z.
	 */
	void validarXYyZ(unsigned int x, unsigned int y, unsigned int z);

public:
	/*
	 * pre: Las coordenadas x, y, z deben ser mayores a 0.
	 * post: Crea un casillero con las coordenadas que se pasaron por parametro.
	 */
	Casillero3D(unsigned int z, unsigned int x, unsigned int y);

	/*
	 * pre:
	 * post:
	 */
	virtual ~Casillero3D();

	/*
	 * pre: -
	 * post: Devuelve el valor de la ficha.
	 */
	char getFicha();

	/*
	 * pre: Ficha debe ser un caracter.
	 * post: Cambia el valor de la ficha por el pasado por parametro.
	 */
	void setFicha(char ficha);
};

#endif /* CASILLERO3D_H_ */
