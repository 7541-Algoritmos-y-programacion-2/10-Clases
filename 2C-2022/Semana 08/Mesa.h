/*
 * Mesa.h
 *
 *  Created on: 14/10/2022
 *      Author: algo2
 */

#ifndef MESA_H_
#define MESA_H_

enum EstadoDeMesa {
	Abierta,
	Cerrada
};

class Mesa {

private:
	unsigned int numero;
	unsigned int cantidadMaximaDeComensales;
	unsigned int cantidadActualDeComensales;
	double montoActualConsumido;
	EstadoDeMesa estado;

public:
	/**
	 * pre:numero debe ser mayor a 0. cantidadMaximaDeComensales debe ser mayor a 0.
	 * pos: deja una mesa Cerrada con el numero indico y su maximo lista para su uso.
	 */
	Mesa(unsigned int numero, unsigned int cantidadMaximaDeComensales);

	/**
	 * pre:-
	 * pos: destruye la instancia de la mesa
	 */
	virtual ~Mesa();

	/**
	 * pre: -
	 * pos: devuelve el numero de la mesa
	 */
	unsigned int getNumero();

	/*
	 * pre: -
	 * pos: devuelve la cantidad maxima de comensales
	 */
	unsigned int getCantidadMaximaDeComensales();

	/**
	 * pre: -
	 * pos: devuelve la cantidad actual de comensales
	 */
	unsigned int getCantidadActualDeComensales();

	/**
	 * pre: cantidadAAdicionar debe ser mayor a 0
	 * pos: agrega los comensales a la mesa, si hay capacidad. Devuelve la cantidad libre de lugares
	 */
	unsigned int adicionarComensales(unsigned int cantidadAAdicionar);

	/**
	 * pre: -
	 * pos: devuelve la cantidad de lugares libres de la mesa
	 */
	unsigned int getCantidadDeLugaresLibres();

	/**
	 * pre: monto debe ser mayor a 0.
	 * pos: acumula monto en la cuenta de la mesa
	 */
	void adicionarMonto(double monto);

	/**
	 * pre: -
	 * pos: devuelve verdadero si la cantidad de comensales es 0
	 */
	bool estaVacia();

	/**
	 * pre: la mesa debe estar abierta.
	 * pos: cierra la mesa y devuelve el monto acumulado. Deja la mesa para su proximo uso.
	 */
	double cerrarMesa();

	/**
	 * pre: -
	 * pos: devuelve verdadero si la mesa esta en estado Abierta
	 */
	bool estaAbierta();


private:

	/**
	 * pre: -
	 * pos: inicializa los atributos de la mesa en 0 y estado Cerrado
	 */
	void inicializar();
};

#endif /* MESA_H_ */
