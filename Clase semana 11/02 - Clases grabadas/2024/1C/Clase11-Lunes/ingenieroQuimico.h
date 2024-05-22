/*
 * ingenieroQuimico.h
 *
 *  Created on: 18/05/2024
 *      Author: algo2
 */

#ifndef INGENIEROQUIMICO_H_
#define INGENIEROQUIMICO_H_




class IngenieroQuimico{

	private:


	public:

	/*
	 * pos: busca en 'solucionesDisponibles' las Soluciones que tengan los mismos Compuestos
	 * que 'SolucionRequerida''con cantidades iguales o superiores pero menores o igual al doble.
	 */
	Lista<Solucion*>* busarSolucionesEquivalente(Solucion* solucionRequerida, Lista<Solucion*>* solucionesDisponibles);


};


#endif /* INGENIEROQUIMICO_H_ */
