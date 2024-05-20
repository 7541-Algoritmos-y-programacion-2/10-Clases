/*
 * Principal1.cpp
 *
 *  Created on: 13/05/2024
 *      Author: algo2
 */
#include "Lista.h"
#include <iostream>

class Mensaje {
public:
	/* post: 'usuario' es el autor del mensaje con 'texto'
	 * como contenido, sin votos asociados.
	 */
	Mensaje(std::string usuario, std::string texto);
	/* post: devuelve el nombre del usuario autor del Mensaje.
	 */
	List<std::string> * obtenerAutores();
	/* post: devuelve el contenido del Mensaje.
	 */
	std::string obtenerContenido();
	/* post: suma un voto al Mensaje.
	 */
	void votar();
	/* post: devuelve la cantidad del Ingrediente.
	 */
	unsigned contarVotos();
};
class Foro {
public:
	/* post: inicializa el Foro sin Mensajes asignados.
	 */
	Foro(std::string nombre);
	/* post: elimina todos los Mensajes del Foro
	 */
	~Foro();
	/* post: devuelve el nombre del Foro.
	 */
	std::string obtenerNombre();
	/* post: devuelve todos los Mensajes del Foro.
	 */
	Lista<Mensaje*>* obtenerMensajes();
	/* post: devuelve las temáticas del Foro
	 */
	Lista<std::string>* obtenerTematicas();
	bool estaActivo();
};

class Moderador {
public:

	/**
	 * pre: foro no puede ser vacio....
	 * pos: busca el mensaje mas votado del autor en el foro
	 */
	Mensaje * buscarMensajeMasVotadoDelUsuario(Foro * foro, std::string autorBuscado) {
		//validar
		Mensaje * resultado = NULL;
		foro->obtenerMensajes()->iniciarCursor();
		while (foro->obtenerMensajes()->avanzarCursor()) {
			Mensaje * mensaje = foro->obtenerMensajes()->obtenerCursor();
			if (tieneElAutor(mensaje, autorBuscado)) {
				resultado = buscarMensajeMasVotado(resultado, mensaje);
			}
		}
		return resultado;
	}

	/* pre:
	 * post: busca en la lista 'foros' el Mensaje más votado que tenga el autor 'autorBuscado' dentro de un Foro que no
	 * incluya la temática 'tematicaBuscada'y el foro este activo.
	 */
	Mensaje* buscarMensajeMasVotadoDelUsuarioSegunTematica(
							Lista<Foro*>* foros,
							std::string autorBuscado,
							std::string tematicaBuscada) {
		//validar
		Mensaje * resultado = NULL;
		foros->iniciarCursor();
		while (foros->avanzarCursor()) {
			Foro * foro = foros->obtenerCursor();
			if (foro->estaActivo() &&
			    !tieneLaTematica(foro, tematicaBuscada)) {
				resultado = buscarMensajeMasVotado(resultado,
										buscarMensajeMasVotadoDelUsuario(foro, autorBuscado));
			}
		}
		return resultado;
	}
};
