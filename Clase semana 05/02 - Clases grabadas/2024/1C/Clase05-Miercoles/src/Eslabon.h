/*
 * Eslabon.h
 *
 *  Created on: 10/04/2024
 *      Author: algo2
 */

#ifndef ESLABON_H_
#define ESLABON_H_

class Eslabon {
private:
	double ancho;
	double alto;
	bool anchoFijo;
public:
	/**
	 * pre: -
	 * post:
	 */
	Eslabon(double ancho, double alto, bool anchoFijo) {
		this->ancho = ancho;
		this->alto = alto;
		this->anchoFijo = anchoFijo;
	}
	virtual ~Eslabon();

	double getAlto(){
		return alto;
	}

	void setAlto(double alto) {
		this->alto = alto;
	}

	double getAncho(){
		return ancho;
	}

	void setAncho(double ancho){
		if (this->anchoFijo) {
			throw "El ancho no se puede cambiar";
		}
		this->ancho = ancho;
	}
};

#endif /* ESLABON_H_ */
