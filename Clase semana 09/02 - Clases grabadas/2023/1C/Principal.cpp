
#include <iostream>
#include <Lista.h>
#include <Cola.h>

class Atraccion {
public:
	/* post: Atracción identificada por ‘nombre’,
	 * cuya duración es ‘minutos’
	 */
	Atraccion(std::string nombre, unsigned int minutos);

	/* post: devuelve el nombre de la atracción.
	 */
	std::string obtenerNombre();

	/* post: devuelve la duración en minutos.
	 */
	unsigned int obtenerDuracion();
};

class Lugar {
public:
	/* post: Lugar identificado por ‘nombre’ y sin Atracciones.
	 */
	Lugar(std::string nombre);
	/* post: devuelve el nombre del Lugar.
	 */
	std::string obtenerNombre();
	/* post: devuelve todas las Atracciones que tiene.
	 */
	Lista<Atraccion*>* obtenerAtracciones();
	/* post: libera todas las Atracciones del Lugar.
	 */
	~Lugar();
};

class AgenteDeViajes {
public:

	/**
	 * pre: lugar no puede ser vacio ni tampoco nombresDeLugaresYaVisitados
	 * pos: devuelve verdadero si el nombre de lugar esta en nombresDeLugaresYaVisitados
	 */
	bool esLugarVisitado(Lugar * lugar, Lista<std::string>* nombresDeLugaresYaVisitados) {
		if (lugar == NULL) {
			throw "EL lugar no puede ser vacio";
		}
		validarNombresDeLugares(nombresDeLugaresYaVisitados);
		nombresDeLugaresYaVisitados->iniciarCursor();
		while(nombresDeLugaresYaVisitados->avanzarCursor()){
			if (nombresDeLugaresYaVisitados->obtenerCursor() == lugar->obtenerNombre()) {
				return true;
			}
		}
		return false;
	}

	/**
	 * pre: lugar y resultado no pueden ser NULOS
	 * pos: busca atracciones de menor duracion a minutosDisponibles y las agrega a resultado
	 */
	unsigned int buscarAtracciones(Lugar* lugar,
					  Lista<Atraccion*>* resultado,
					  unsigned int minutosDisponibles) {
		validarLugar(lugar);
		validarAtracciones(resultado);
		lugar->obtenerAtracciones()->iniciarCursor();
		while(lugar->obtenerAtracciones()->avanzarCursor()) {
			Atraccion * atraccion = lugar->obtenerAtracciones()->obtenerCursor();
			if (atraccion->obtenerDuracion() < minutosDisponibles) {
				resultado->agregar(atraccion);
				minutosDisponibles -= atraccion->obtenerDuracion();
			}
		}
		return minutosDisponibles;
	}

	/*
	 * pre: lugaresDisponibles y nombresDeLugaresYaVisitados no puede ser NULL.
	 * post: busca en ‘lugaresDisponibles’ aquellas Atracciones que estén en lugares
	 * 			no visitados y cuya duración total (la suma de las duraciones de todos
	 * 			las Atracciones) no supere ‘minutosDisponibles’.
	 */
	Lista<Atraccion*>* buscarAtracciones(
							Lista<Lugar*>* lugaresDisponibles,
							Lista<std::string>* nombresDeLugaresYaVisitados,
							unsigned int minutosDisponibles) {
		if (lugaresDisponibles == NULL) {
			throw "Lugares disponibles no puede ser Nulo";
		}
		validarNombresDeLugares(nombresDeLugaresYaVisitados);
		Lista<Atraccion*>* resultado = new Lista<Atraccion*>();

		lugaresDisponibles->iniciarCursor();
		while (lugaresDisponibles->avanzarCursor()) {
			Lugar* lugar = lugaresDisponibles->obtenerCursor();
			if (!this->esLugarVisitado(lugar, nombresDeLugaresYaVisitados)) {
				minutosDisponibles = buscarAtracciones(lugar, resultado, minutosDisponibles);
			}
		}
		return resultado;
	}

private:

	/*
	 * pre: -
	 * pos: da error si nombresDeLugaresYaVisitados es NULO
	 */
	void validarNombresDeLugares(Lista<std::string>* nombresDeLugaresYaVisitados) {
		if (nombresDeLugaresYaVisitados == NULL) {
			throw "Nombres de lugares no puede ser Nulo";
		}
	}

};

int main(){


}


