/*
 * Solucion.h
 *
 *  Created on: 18/05/2024
 *      Author: algo2
 */

#ifndef SOLUCION_H_
#define SOLUCION_H_


#include <iostream>

#include "Compuesto.h"
#include "Lista.h"

class Solucion{

	private:
		std::string codigo;
		Lista<Compuesto*> *compuestos;



	public:

		/*
		 * pos: crea la solucion con el codigo especificado, sin compuestos asociados
		 */
		Solucion(std::string codigo);

		/*
		* pos: devuelve el codigo de la solucion
		*/
		std::string obtenerCodigo();


		/*
		* pos: Agrega un compuesto a la solucion
		*/
		void agregarCompuesto(Compuesto *compuesto);

		/*
		 * pos: devuelve los compuestos requeridos para preparar la solucion
		 */
		Lista<Compuesto*>* obtenerCompuestos();
};

/*enum Unidad{

	KILO,LITRO

};*/

#endif /* SOLUCION_H_ */
