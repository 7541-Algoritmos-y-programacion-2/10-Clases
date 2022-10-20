/*
 * AdministradorDeGen.h
 *
 *  Created on: 30/09/2022
 *      Author: algo2
 */

#ifndef ADMINISTRADORDEGEN_H_
#define ADMINISTRADORDEGEN_H_

class AdministradorDeGen {

private:
	unsigned int maximoDeCargaGentica;

public:
	/**
	 * pre:
	 * pos:
	 */
	AdministradorDeGen(unsigned int maximoDeCargaGentica);

	/**
	 * pre: -
	 * pos: -
	 */
	virtual ~AdministradorDeGen();

	/**
	 * pre: que los genes no sean nulos
	 * pos: devuelve un gen con maximoDeCargaGentica en "maximoDeCargaGentica" y cargaGentica como el promedio
	 */
	Gen * generar(Gen * gen1, Gen * gen2, Gen * gen3);
};

#endif /* ADMINISTRADORDEGEN_H_ */
