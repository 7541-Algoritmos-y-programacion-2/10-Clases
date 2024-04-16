/*
 * PlantillaUno.h
 *
 *  Created on: 15/04/2024
 *      Author: algo2
 */

#ifndef PLANTILLAUNO_H_
#define PLANTILLAUNO_H_

template<class T>
class PlantillaUno {
private:
	T dato;
public:
	PlantillaUno() {}
	virtual ~PlantillaUno() {}

	T getDato() {
		return this->dato;
	}
};

#endif /* PLANTILLAUNO_H_ */
