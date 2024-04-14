/*
 * Cadena.h
 *
 *  Created on: 10/04/2024
 *      Author: algo2
 */

#ifndef CADENA_H_
#define CADENA_H_

#include <iostream>

#include "Eslabon.h"

class Cadena {

private:
	Eslabon ** eslabones1;
	unsigned int largoMaximo;

public:
	/**
	 * pre:
	 * post:
	 */
	Cadena(unsigned int largoMaximo, double ancho, double largoPrimerEslabon) {
		//validar: largoMaximo > 0, ancho > 0
		this->largoMaximo = largoMaximo;
		this->eslabones = new Eslabon*[largoMaximo];
		for(int i = 0; i< largoMaximo; i++) {
			this->eslabones[i] = NULL;
		}
		this->eslabones[0] = new Eslabon(ancho, largoPrimerEslabon, true);
	}

	virtual ~Cadena() {
		//arreglar con un for
		delete this->eslabones;
	}

	void setAncho(double ancho) {
		for(int i = 0; i< largoMaximo; i++) {
			if (this->eslabones[i] != NULL) {
				Eslabon * temp = this->eslabones[i];
				this->eslabones[i] = new Eslabon(ancho, temp->getAlto(), true);
				delete temp;
			}
		}
	}

	double getLongitud() {
		double resultado = 0;
		for(int i = 0; i< largoMaximo; i++) {
			if (this->eslabones[i] != NULL) {
				resultado += this->eslabones[i]->getLargo();
			}
		}
		return resultado;
	}
};

#endif /* CADENA_H_ */
