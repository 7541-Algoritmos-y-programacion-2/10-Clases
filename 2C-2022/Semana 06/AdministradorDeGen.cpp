/*
 * AdministradorDeGen.cpp
 *
 *  Created on: 30/09/2022
 *      Author: algo2
 */

#include "AdministradorDeGen.h"

AdministradorDeGen::AdministradorDeGen(unsigned int maximoDeCargaGentica) {
	this->maximoDeCargaGentica = maximoDeCargaGentica;
}

AdministradorDeGen::~AdministradorDeGen() {
	// TODO Auto-generated destructor stub
}

Gen * AdministradorDeGen::generar(Gen * gen1, Gen * gen2, Gen * gen3) {
	//validar que los gen no sean nulos
	Gen * resultado = new Gen(this->maximoDeCargaGentica);
	resultado->setCargaGentica((gen1->getCargaGentica() + gen2->getCargaGentica() + gen3->getCargaGentica()) / 3);
	return resultado;
}
