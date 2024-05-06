/*
 * Principal.cpp
 *
 *  Created on: 29/04/2024
 *      Author: algo2
 */

#include "Pila.h"
#include "Cola.h"

	enum Unidad {
		KILO; LITRO;
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
		Solucion(std::string codigo);

		std::string obtenerCodigo();
		/* post: devuelve los Compuestos requeridos para
preparar
		 * la Solución
		 */
		Lista<Compuesto*>* obtenerCompuestos()
	};


	class IngenieroQuimico {
	public:

		/**
		 * pre:
		 * pos:
		 */
		bool estaContenido(Compuesto *compuesto, Compuesto *compuestoDisponible) {
			//Tarea
		}

		/**
		 * pre:
		 * pos:
		 */
		bool estaContenido(Compuesto *compuesto, Solucion* solucionDisponible) {
			//validarlo
			solucionDisponible->obtenerCompuestos()->iniciarCursor();
			while (solucionDisponible->obtenerCompuestos()->avanzarCursor()) {
				Compuesto *compuestoDisponible = solucionDisponible->obtenerCompuestos()->obtenerCursor();
				if (!estaContenido(compuesto, compuestoDisponible)) {
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
			//validar
			solucionRequerida->obtenerCompuestos()->iniciarCursor();
			while (solucionRequerida->obtenerCompuestos()->avanzarCursor()) {
				Compuesto * compuesto = solucionRequerida->obtenerCompuestos()->obtenerCursor();
				if (!estaContenido(compuesto, solucionDisponible)) {
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
			//validar parametros
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
	{
		Pila<int> * pila = new Pila<int>();
		pila->apilar(6);
		pila->apilar(7);
		pila->apilar(8);

		std::cout << "Longitud: " << pila->contarElementos();

		while (!pila->estaVacia()) {
			std::cout << "Numero: " << pila->desapilar() << std::endl;
			//La salida sera: 8 7 6
		}
	}

	{ //Como invertir una lista con dato atomico
		Lista<int> * lista = new Lista<int>();
		lista->agregar(6);
		lista->agregar(7);
		lista->agregar(8);


		Pila<int> * pila = new Pila<int>();

		lista->iniciarCursor();
		while(lista->avanzarCursor()) {
			int dato = lista->obtenerCursor();
			pila->apilar(dato);
		}

		Lista<int> * listaInvertida = new Lista<int>();
	    while (!pila->estaVacia()) {
	    	int dato = pila->desapilar();
	    	listaInvertida->agregar(dato);
	    }
	    //Pila vacia
	    //lista llena
	    //listaInvertida llena

	    listaInvertida->iniciarCursor();
		while(listaInvertida->avanzarCursor()) {
			std::cout << "El valor es: " << listaInvertida->obtenerCursor();
		}

	    delete lista;
	    delete pila;
	    delete listaInvertida;
	}

	{ //Como invertir una lista con dato puntero
		Lista<int*> * lista = new Lista<int*>();
		int * entero = new int;
		*entero = 6;
		lista->agregar(entero);

		entero = new int;
		*entero = 7;
		lista->agregar(entero);

		entero = new int;
		*entero = 8;
		lista->agregar(entero);


		Pila<int> * pila = new Pila<int>();

		lista->iniciarCursor();
		while(lista->avanzarCursor()) {
			int dato = lista->obtenerCursor();
			pila->apilar(dato);
		}

		Lista<int> * listaInvertida = new Lista<int>();
		while (!pila->estaVacia()) {
			int dato = pila->desapilar();
			listaInvertida->agregar(dato);
		}
		//Pila vacia
		//lista llena
		//listaInvertida llena

		listaInvertida->iniciarCursor();
		while(listaInvertida->avanzarCursor()) {
			std::cout << "El valor es: " << listaInvertida->obtenerCursor();
		}

		*entero = 10;

		delete lista;
		delete pila;

		listaInvertida->iniciarCursor();
		while(listaInvertida->avanzarCursor()) {
			delete listaInvertida->obtenerCursor();
		}

		delete listaInvertida;
	}
	{ //Como invertir una lista con dato atomico
		Lista<int> * lista = new Lista<int>();
		lista->agregar(6);
		lista->agregar(7);
		lista->agregar(8);

		Lista<int> * listaInvertida = new Lista<int>();
		lista->iniciarCursor();
		while (!lista->avanzarCursor()) {
			listaInvertida->agregarAlInicio(lista->obtenerCursor());
		}

		delete lista;
		delete listaInvertida;
	}

	{//Ejemplo de cola
		Lista<int> * lista = new Lista<int>();
		lista->agregar(6);
		lista->agregar(7);
		lista->agregar(8);

		Cola<int> * cola = new Cola<int>();
		Pila<int> * pila = new Pila<int>();
		pila->apilar(lista);
		cola->acolar(lista);

		while (!cola->estaVacia()) {
			std::cout << "El valor es: " << cola->obtener();
		}
		while (!pila->estaVacia()) {
			std::cout << "El valor es: " << pila->obtener();
		}
	}





}



