/*
 * Compuesto.h
 *
 *  Created on: 18/05/2024
 *      Author: algo2
 */

#ifndef COMPUESTO_H_
#define COMPUESTO_H_

#include <iostream>




enum Unidad{

	KILO,LITRO

};


class Compuesto{

	private:

		std::string nombre;
		Unidad unidadDeMedida;
		float cantidad;



	public:

		/*
		 *pos: crea el Compuesto , identificado por 'nombre' con cantidad 0 de la Unidad 'unidadDeMedida'
		 */
		Compuesto(std::string nombre, Unidad unidadDeMedida);


		/*
		 * pos: devuelve el nombre que identifia el Compuesto
		 */

		std::string obtenerNombre();

		/*
		 * pos: devuelve la Unidad en la que se mide la cantidad
		 */
		Unidad obtenerUnidad();

		/*
		 * pos: devuelve la cantidad de la Unidad
		 */

		float obtenerCantidad();

		/*pre:
		 * pos: se actualiza la nueva cantidad
		 */

		void cambiarCantidad(float cantidad);
};


#endif /* COMPUESTO_H_ */
