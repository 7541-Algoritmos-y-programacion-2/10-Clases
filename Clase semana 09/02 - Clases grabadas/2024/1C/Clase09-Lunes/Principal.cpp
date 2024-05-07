/*
 * Principal.cpp
 *
 *  Created on: 29/04/2024
 *      Author: algo2
 */

#include "Lista.h"

enum Unidad {
	KILO,
	LITRO
};

class Compuesto {
public:
	/* post: crea el Compuesto, identificado por 'nombre',
	 * con cantidad 0 de la Unidad 'unidadDeMedida'
	 */
	Compuesto(std::string nombre, Unidad unidadDeMedida);
	/* post: devuelve el nombre que identifica el Compuesto
	 */
	std::string obtenerNombre();
	/* post: devuelve la Unidad en la que se mide la
cantidad.
	 */
	Unidad obtenerUnidad();
	float obtenerCantidad();


	class Solucion {

		public:
			/* post: crea la solución con el código especificado, sin
			 * compuestos asociados
			 */
			Solucion(std::string codigo) {}

			std::string obtenerCodigo();
			/* post: devuelve los Compuestos requeridos para preparar
			 * la Solución
			 */
			Lista<Compuesto*>* obtenerCompuestos();

	};


class IngenieroQuimico {

private:
		void validarSolucion(Solucion* solucion) {
			solucion->obtenerCompuestos()->iniciarCursor();
			while(solucion->obtenerCompuestos()->avanzarCursor()) {
				Compuesto * compuesto = solucion->obtenerCompuestos()->obtenerCursor();
				if (compuesto->obtenerCantidad() <= 0) {
					throw "La solucion no es valida";
				}
			}
		}

public:

	/**
	 * pre: compuesto y compuestoDisponible no pueden ser vacios
	 * pos: devuelve verdadero si el compuesto esta contenido en el rango de compuestoDisponible
	 */
	bool estaContenidoEnRango(Compuesto *compuesto, Compuesto * compuestoDisponible, unsigned int rango) {
		if (compuesto == NULL) {
			throw "El compuesto no puede ser vacio";
		}
		if (compuestoDisponible == NULL) {
			throw "El compuestoDisponible no puede ser vacio";
		}
		if (compuesto->obtenerNombre() != compuestoDisponible->obtenerNombre()) {
			return false;
		}
		if ((compuesto->obtenerCantidad() > compuestoDisponible->obtenerCantidad()) ||
			(compuesto->obtenerCantidad() > (compuestoDisponible->obtenerCantidad() * rango))) {
			return false;
		}
		return true;
	}

	/**
	 * pre:
	 * pos:
	 */
	bool estaContenidoEnRango(Compuesto *compuesto, Solucion* solucionDisponible, unsigned int rango) {
		if (compuesto == NULL) {
			throw "El compuesto no puede ser vacio";
		}
		if (solucionDisponible == NULL) {
			throw "La solucionDisponible no puede ser vacio";
		}
		solucionDisponible->obtenerCompuestos()->iniciarCursor();
		while (solucionDisponible->obtenerCompuestos()->avanzarCursor()) {
			Compuesto *compuestoDisponible = solucionDisponible->obtenerCompuestos()->obtenerCursor();
			if (!estaContenidoEnRango(compuesto, compuestoDisponible, rango)) {
				return false;
			}
		}
		return true;
	}

	/**
	 * pre:
	 * pos:
	 */
	bool esSolucionEquivalente(Solucion* solucionRequerida, Solucion* solucionDisponible) {
		if (solucionRequerida == NULL) {
			throw "La solucionRequerida no puede ser vacia";
		}
		if (solucionDisponible == NULL) {
			throw "La solucionDisponible no puede ser vacia";
		}
		if (solucionRequerida->obtenerCodigo() != solucionDisponible->obtenerCodigo()) {
			return false;
		}

		//Opcion 0:
		if (solucionRequerida->obtenerCompuestos()->getTamanio() != solucionDisponible->obtenerCompuestos()->getTamanio()) {
			return false;
		}
		//Opcion 6:
		validarSolucion(solucionRequerida);
		validarSolucion(solucionDisponible);
		if (solucionRequerida->obtenerCompuestos()->getTamanio() != solucionDisponible->obtenerCompuestos()->getTamanio()) {
			return false;
		}

		solucionRequerida->obtenerCompuestos()->iniciarCursor();
		while (solucionRequerida->obtenerCompuestos()->avanzarCursor()) {
			Compuesto * compuesto = solucionRequerida->obtenerCompuestos()->obtenerCursor();
			if (!estaContenidoEnRango(compuesto, solucionDisponible, 2)) {
				return false;
			}
		}
		return true;
	}

	/*
	 * pre: falta definir
	 * post: busca en 'solucionesDisponibles' las Soluciones que tenga los mismos Compuestos
	 *       que 'solucionRequerida', con cantidades iguales o superiores
	 *       pero menores (o igual) al doble en una nueva lista
	 */
	Lista<Solucion*>* buscarSolucionesEquivalente(
							Solucion* solucionRequerida,
							Lista<Solucion*> * solucionesDisponibles) {
		if (solucionRequerida == NULL) {
			throw "La solucion requerida no puede ser vacia";
		}
		if (solucionesDisponibles == NULL) {
			throw "La soluciones disponibles no pueden ser vacia";
		}
		Lista<Solucion*>* resultado = new Lista<Solucion *>();

		solucionesDisponibles->iniciarCursor();
		while (solucionesDisponibles->avanzarCursor()) {
			Solucion * solucionDisponible = solucionesDisponibles->obtenerCursor();
			if (esSolucionEquivalente(solucionRequerida, solucionDisponible)) {
				resultado->agregar(solucionDisponible);
			}
		}
		return resultado;
	}
};

	//Tarea:
	//1) implementar el metodo bool estaContenido(Compuesto *compuesto, Compuesto *compuestoDisponible)
	//2) terminar pre, pos y validaciones
	//3) hacer el main de prueba

int main(int argc, char **argv) {
	IngenieroQuimico * ingenieroQuimico = new IngenieroQuimico();

	Solucion * solucionRequerida = new Solucion();
	//Cargar solucionRequerida
	Lista<Solucion *> * solucionesDisponibles = new Lista<Solucion *>();
	//Cargar solucionesDisponibles

	Lista<Solucion*>* resultado = ingenieroQuimico->buscarSolucionesEquivalente(solucionRequerida, solucionesDisponibles);


	ingenieroQuimico->esSolucionEquivalente(solucionRequerida, solucionesDisponibles->obtener(1));

	//Eliminar resultado
	delete resultado;
}



