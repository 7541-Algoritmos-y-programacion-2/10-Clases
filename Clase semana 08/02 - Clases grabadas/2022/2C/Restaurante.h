/*
 * Restaurante.h
 *
 *  Created on: 14/10/2022
 *      Author: algo2
 */

#ifndef RESTAURANTE_H_
#define RESTAURANTE_H_

class Restaurante {

private:
	Vector<Mesa *> * mesas;

public:
	/**
	 * pre: cantidadDeMesas debe ser mayor a 0
	 * pos: crea un restaurant con la cantidad de mesas indicadas.
	 */
	Restaurante(unsigned int cantidadDeMesas);

	/**
	 * pre: -
	 * pos: elimina la memoria de las mesas utilizada
	 */
	virtual ~Restaurante();

	/**
	 * pre: numero debe ser mayor a 0 y no repetirse. cantidadDeComensales debe ser mayor a 0.
	 * pos: agrega una mesa con la cantidad de comensales solicitada
	 */
	unsigned int adicionarMesa(unsigned int cantidadDeComensales);

	/**
	 * pre:cantidadDeComensales es mayor a 0
	 * pos: adicional comensales a la mesa indicada
	 */
	unsigned int adicionarComensal(unsigned int numeroDeMesa, unsigned int cantidadDeComensales);

	/**
	 * pre: numeroDeMesa debe existir en el restaurant, monto > 0
	 * pos: adiciona el monto a la mesa indicada
	 */
	void adicionarMonto(unsigned int numeroDeMesa, double monto);

	/**
	 * pre: numeroDeMesa debe existir en el restaurant
	 * pos: cierra la mesa indicada
	 */
	double cerrarMesa(unsigned int numeroDeMesa);

	/**
	 * pre: -
	 * pos: devuelve la cantidad de comensales que estan actualmente en el restaurant
	 */
	unsigned int getCantidadDeComesalesActuales();

	/**
	 * pre: numeroDeMesa debe existir en el restaurant
	 * pos: devuelve la cantidad de comensales que actualmente estan en la mesa numeroDeMesa
	 */
	unsigned int getCantidadDeComesalesActuales(unsigned int numeroDeMesa);

	/**
	 * pre: -
	 * pos: devuele la capacidad del restaurante
	 */
	unsigned int getCapacidadTotalDelRestaurante();

	/**
	 * pre: -
	 * pos: devuelve verdadero si no hay comensales
	 */
	bool estaVacio();
};

#endif /* RESTAURANTE_H_ */
