/*
 * Principal2.cpp
 *
 *  Created on: 22/05/2024
 *      Author: algo2
 */

#include <iostream>
#include "Lista.h"

using namespace std;

enum DiaDeLaSemana {
	LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, ...
};

class Funcion {
public:
	/* post: crea la Función del día
	 *       con la cantidad de espectadores indicados.
	 */
	Funcion(DiaDeLaSemana dia,
			unsigned int espectadores)

	/* post: devuelve el día en que se hizo.
	 */
	DiaDeLaSemana obtenerDia();

	/* post: devuelve la cantidad de espectadores.
	 */
	unsigned int obtenerEspectadores();
}



class Pelicula {
public:
	Pelicula(string titulo, string genero);

	/* post: devuelve el título que la identifica.
	 */
	string obtenerTitulo();

	/* post: devuelve el género al que pertenece.
	 */
	string obtenerGenero();

	/* post: devuelve todas las funciones disponibles.
	 */
	Lista<Funcion*>* obtenerFunciones();

	/* post: libera todas las Funciones de la Película.
	 */
	~Pelicula();
};

class AdministradorDeCine {
public:
	/* pre: completar
	 * post: Devuelve el título de aquella película de ‘peliculasEnCartel’ que haya tenido la máxima cantidad de
	 *       espectadores sumarizando las funciones del día ‘diaConsiderado’ y que sea de alguno de los géneros dados en
	 *       ‘generosConsiderados’.
	 */
	string buscarPeliculaMasTaquillera(
							Lista<Pelicula*>* peliculasEnCartel,
							DiaDeLaSemana diaConsiderado,
							Lista<string>* generosConsiderados) {
		//validar
		Pelicula * resultado = NULL;
		Funcion *  funcionMasTaquillera = NULL;
		peliculasEnCartel->iniciarCursor();
		while( peliculasEnCartel->avanzarCursor()) {
			Pelicula * pelicula = peliculasEnCartel->obtenerCursor();
			if (this->tieneElGenero(generosConsiderados, pelicula->obtenerGenero())) {
				Lista<Funcion *> * funciones = this->buscarFuncionesDelDia(pelicula, diaConsiderado);
				Funcion * funcionMasTaquilleraActual = this->buscarMasVotado(funcionMasTaquillera, funciones);
				if (funcionMasTaquilleraActual != funcionMasTaquillera) {
					resultado = pelicula;
					funcionMasTaquillera = funcionMasTaquilleraActual;
				}
			}
		}
		if (resultado != NULL) {
			return resultado->obtenerTitulo();
		}
		return NULL; //return "";
	}
}


