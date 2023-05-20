
#include <iostream>
#include <Lista.h>
#include <Cola.h>


class Comentario {
public:
	/* post: inicializa el Comentario con el contenido
	 * y calificación 0.
	 */
	Comentario(std::string contenido);
	std::string obtenerContenido();
	/* post: devuelve la calificación [1 a 10] asociada,
	 * o 0 si el Comentario no tiene calificación.
	 */
	int obtenerCalificacion();
	/* pre : calificacion está comprendido entre 1 y 10
	 * post: cambia la calificación del Comentario.
	 */
	void calificar(int calificacion);
};

class Imagen {
private:
	double * promedioDeComentarios;

public:
	/* post: inicializa la Imagen alojada en la URL indicada.
	 */
	Imagen(std::string url) {
		this->promedioDeComentarios == NULL;
	}
	/* post: devuelve la URL en la que está alojada.
	 */
	std::string obtenerUrl();
	/* post: devuelve los comentarios asociados.
	 */
	Lista<Comentario*>* obtenerComentarios();
	~Imagen() {
		if (promedioCalculado()) {
			delete this->promedioDeComentarios;
		}
	}

	double obtenerPromedioDeComentarios();

	bool promedioCalculado() {
		return this->promedioDeComentarios != NULL;
	}

	void cambiarPromedioDeComentarios(double promedio) {
		if (!promedioCalculado()) {
			this->promedioDeComentarios = new double;
		}
		*this->promedioDeComentarios = promedio;
	}
};




class Editor {
public:

	/**
	 * pre
	 * pos
	 */
	double getPromedio(Imagen * imagen) {
		//validar
		if (imagen == NULL) {
			throw "La imagen no puede ser nula";
		}
		if (imagen->promedioCalculado()) {
			return imagen->obtenerPromedioDeComentarios();
		}
		double cantidad = 0;
		double suma = 0;
		imagen->obtenerComentarios()->iniciarCursor();
		while (imagen->obtenerComentarios()->avanzarCursor()) {
			Comentario * comentario = imagen->obtenerComentarios()->obtenerCursor();
			if (comentario->obtenerCalificacion() > 0) {
				cantidad++;
				suma += comentario->obtenerCalificacion();
			}
		}
		double resultado = 0;
		if (cantidad != 0) {
			resultado = suma / cantidad;
		}
		imagen->cambiarPromedioDeComentarios(resultado);
		return resultado;
	}

	/*
	 * pre:
	 * post: selecciona de ‘imagenesDisponibles’ aquella que tenga por lo menos tantos Comentarios como los indicados y
	 * el promedio de calificaciones sea máximo. Ignora los Comentarios sin calificación.
	 */
	Imagen* seleccionarImagen(Lista<Imagen*>* imagenesDisponibles,
								int cantidadDeComentarios) {
		//validar;
		Imagen * imagenResultado = NULL;
		imagenesDisponibles->iniciarCursor();
		while (imagenesDisponibles->avanzarCursor()) {
			Imagen * imagen = imagenesDisponibles->obtenerCursor();
			if (this->getCantidadDeComentariosCalificados(imagen) >= cantidadDeComentarios) {
				if ((imagenResultado == NULL) ||
					(this->getPromedio(imagenResultado) < this->getPromedio(imagen)){
					imagenResultado = imagen;
				}
			}
		}
	}
};

int main(){


}


