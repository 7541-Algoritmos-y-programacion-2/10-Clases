
#include <iostream>
#include <Lista.h>
#include <Cola.h>

class Turno {

public:
	/* post: Turno no ocupado entre la horas desde y
	 * hasta.
	 */
	Turno(unsigned int desde, unsigned int hasta)
/* post: devuelve la hora de inicio del turno.
 */
unsigned int obtenerHoraDesde();
	/* post: devuelve la hora de fin del turno.
	 */
	unsigned int obtenerHoraHasta();
	/* post: indica si el turno está ocupado.
	 */
	bool estaOcupado();
	/* post: marca el turno como ocupado.
	 */
	void ocupar();
};


class Taller {

public:

	Taller();

	/* post: devuelve todas las especialidades que atiende.
	 */
	Lista<std::string>* obtenerEspecialidades();

	/* post: devuelve todos los Turnos que tiene.
	 */
	Lista<Turno*>* obtenerTurnos();

	/* post: libera todos los Turnos.
	 */
	~Taller();
};



class Mecanico {

private:

	void validar(Taller *taller) {
		if (taller == NULL) {
			throw "El taller no puede ser nulo";
		}
	}

public:

	/**
	 * pre:
	 * pos:
	 */
	bool tieneLaEspecialidad(Taller * taller, std::string especialidad) {
		validar(taller);
		taller->obtenerEspecialidades()->iniciarCursor();
		while(taller->obtenerEspecialidades()->avanzarCursor()) {
			std::string epecialidadActual = taller->obtenerEspecialidades()->obtenerCursor();
			if (especialidad == epecialidadActual) {
				return true;
			}
		}
		return false;
	}

	/**
	 * pre:
	 * pos:
	 */
	bool tieneTurnoDisponible(Taller * taller, unsigned int horaDesde, unsigned int horaHasta) {
		validar(taller);
		taller->obtenerTurnos()->iniciarCursor();
		while (taller->obtenerTurnos()->avanzarCursor()) {
			Turno * turno = taller->obtenerTurnos()->obtenerCursor();
			if (!turno->estaOcupado() &&
				(turno->obtenerHoraDesde() <= horaDesde) &&
				(turno->obtenerHoraHasta() >= horaHasta)) {
				return true;
			}
		}
		return false;
	}

	/*
	 * pre: talleresDisponibles no puede ser null
	 * post: devuelve una nueva Lista (reserva memoria) con todos aquellos Talleres existentes en ‘talleresDisponibles’ que atiendan
	 *	la especialidad indicada y que tengan al  menos un Turno no ocupado entre ‘horaDesde’ y ‘horaHasta’.
	 */
	Lista<Taller*>* filtrarTaller(Cola<Taller*>* talleresDisponibles,
				std::string especialidad,
				unsigned int horaDesde,
				unsigned int horaHasta) {
		if (talleresDisponibles == NULL) {
			throw std::string("Talleres disponibles no puede ser null");
		}
		if (especialidad == NULL) {
			throw "La especialidad no puede ser null";
		}
		Lista<Taller*>* resultado = new Lista<Taller *>();
		while (!talleresDisponibles->estaVacia()) {
			Taller * taller = talleresDisponibles->desacolar();
			if (this->tieneLaEspecialidad(taller, especialidad) &&
				this->tieneTurnoDisponible(taller, horaDesde, horaHasta)) {
				resultado->agregar(taller);
			}
		}
		return resultado;
	}
};



int main(){
	try {
		Cola<Taller*>* talleresDisponibles = new Cola<Taller *>();
		//cargamos la cola

		Mecanico * mecanico = new Mecanico();
		Lista<Taller*>* resultado = mecanico->filtrarTaller(talleresDisponibles, "chapa", 13, 15);
		//usar el resultado
		delete resultado;
	} catch (...) {

	} catch (std::string e) {
		std::cout << e << std::endl;
	} catch (const char* e) {
		std::cout << e << std::endl;
	}

}


