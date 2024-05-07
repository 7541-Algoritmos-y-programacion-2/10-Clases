/*
 * Principal2.cpp
 *
 *  Created on: 06/05/2024
 *      Author: algo2
 */
#include "Lista.h"

class Comentario {

public:
	  /* post: inicializa el Comentario con el contenido * y calificación 0.
	   */
		Comentario(std::string contenido);
		std::string obtenerContenido();
	    /* post: devuelve la calificación [1 a 10] asociada, * o 0 si el Comentario no tiene calificación. */
		int obtenerCalificacion();
	    /* pre : calificacion está comprendido entre 1 y 10 * post: cambia la calificación del Comentario. */
		void calificar(int calificacion);

		/**
		 * pre:
		 * pos: devuelve verdadero si el valor esta entre 1 y 10
		 */
		bool tieneCalificacionValida();
};

class Imagen {

	public:
	/* post: inicializa la Imagen alojada en la URL indicada.      */
	    Imagen(std::string url);
	    /* post: devuelve la URL en la que está alojada.
	     */
	    std::string obtenerUrl();
	    /* post: devuelve los comentarios asociados.
	     */
	    Lista<Comentario*>* obtenerComentarios();
	    ~Imagen();
};


class Editor {
  public:

	/**
	 * pre: la imagen no puede ser vacia
	 * pos: devuelve la cantidad de comentario
	 */
	int getCantidadDeComentariosValidos(Imagen * imagen) {
		//validar
		int resultado = 0;
		imagen->obtenerComentarios()->iniciarCursor();
		while (imagen->obtenerComentarios()->avanzarCursor()) {
			Comentario * comentario = imagen->obtenerComentarios()->obtenerCursor();
			if (comentario->tieneCalificacionValida()) {
				resultado++;
			}
		}
		return resultado;
	}

	/**
	 * pre:
	 * pos:
	 */
	double getPromedioDeCalificaciones(Imagen* imagen) {
		//validar
		double suma = 0;
		double cantidadDeComentarios = 0;
		imagen->obtenerComentarios()->iniciarCursor();
		while(imagen->obtenerComentarios()->avanzarCursor()) {
			Comentario * comentario = imagen->obtenerComentarios()->obtenerCursor();
			if (comentario->tieneCalificacionValida()) {
				cantidadDeComentarios++;
				suma += comentario->obtenerCalificacion();
			}
		}
		if (cantidadDeComentarios <= 0) {
			return 0;
		}
		return suma / cantidadDeComentarios;
	}

	/**
	 * pre: imagen2 no pude ser vacio
	 * pos: devuelve la imagen con mejor comentario, o imagen2 si imagen1 es vacio
	 */
	Imagen * getImagenDeMejorPromedioDeCalificaciones(Imagen* imagen1, Imagen* imagen2) {
		if (imagen2 == NULL) {
			throw "La imagen 2 no puede ser vacia";
		}
		if (imagen1 == NULL) {
			return imagen2;
		}
		if (getPromedioDeCalificaciones(imagen1) >= getPromedioDeCalificaciones(imagen2)) {
			return imagen1;
		}
		return imagen2;
	}

    /*
     * pre:
     * post: selecciona de ‘imagenesDisponibles’ aquella que tenga por lo menos tantos Comentarios como los indicados y
     * el promedio de calificaciones sea máximo. Ignora los Comentarios sin calificación.
     */
	Imagen * seleccionarImagen(Lista<Imagen*>* imagenesDisponibles,
								int cantidadDeComentarios) {
		//Validar
		Imagen * resultado = NULL;
		imagenesDisponibles->iniciarCursor();
		while(imagenesDisponibles->avanzarCursor()) {
			Imagen * imagen = imagenesDisponibles->obtenerCursor();
			if (getCantidadDeComentariosValidos(imagen) >= cantidadDeComentarios) {
				resultado = getImagenDeMejorPromedioDeCalificaciones(resultado, imagen);
			}
		}
		return resultado;
	}
};

int main(int argc, char **argv) {
	//Tarea:
	// terminar el ejercicio
	// que compile
	// main de prueba
}
