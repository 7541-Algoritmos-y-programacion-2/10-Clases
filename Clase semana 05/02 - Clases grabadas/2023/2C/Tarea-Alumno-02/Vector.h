/*
 * Vector
 *
 *  Created on: 23 sep. 2023
 *      Author: gonzalo
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

template <class T> class Vector
{
	private:
		unsigned int longitud;
		T * valores;

		void validarIndice(unsigned int indice)
		{
			if(indice < 1)
			{
				throw "El indice debe ser 1 o mayor";
			}
			else if(indice > this->longitud)
			{
				throw "El indice debe ser longitud o menor";
			}
		}

	public:
		/*
		 * pre: La longitud debe ser mayor a 0
		 * post: Crea el vector de tipo T con el tamaño longitud
		 */
		Vector(unsigned int longitud)
		{
			if(longitud <= 0)
			{
				throw "La longitud debe ser mayor a 0";
			}

			this->longitud = longitud;
			this->valores = new T[this->longitud];

			for(unsigned int i = 0; i < this->longitud; i++)
			{
				this->valores[i] = NULL;
			}
		}

		/*
		 * pre: -
		 * post: Elimina el vector correctamente
		 */
		virtual ~Vector()
		{
			for(unsigned int i = 0; i < this->longitud; i++)
			{
				if(this->valores[i] != NULL)
				{
					delete this->valores[i];
				}
			}
			delete [] this->valores;
		}

		/*
		 * pre: indice debe estar entre 1 y el tamaño del vector
		 * post: devuelve el valor del vector en la posicion indice
		 */
		T getDato(unsigned int indice)
		{
			validarIndice(indice);
			return this->valores[indice - 1];
		}

		/*
		 * pre: indice debe estar entre 1 y longitud del vector
		 * post: deja el valor valor en la posicion del indice del vector
		 */
		void setDato(unsigned int indice, T valor)
		{
			validarIndice(indice);
			this->valores[indice - 1] = valor;
		}

		/*
		 * pre: -
		 * post: devuelve la longitud del vector
		 */
		unsigned int getLongitud()
		{
			return this->longitud;
		}

};
#endif /* VECTOR_H_ */
