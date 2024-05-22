/*
 * Principal.cpp
 *
 *  Created on: 22/05/2024
 *      Author: algo2
 */

#include <iostream>
#include "Lista.h"

using namespace std;

class Mensaje {
public:
	/* post: 'usuario' es el autor del mensaje con 'texto'
	 *       como contenido, sin votos asociados.
	 */
	Mensaje(string usuario, string texto);

	/* post: devuelve el nombre del usuario autor del Mensaje.
	 */
	string obtenerAutor();

	/* post: devuelve el contenido del Mensaje.
	 */
	string obtenerContenido();

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
	Foro(string nombre);

	/* post: elimina todos los Mensajes del Foro
	 */
	~Foro();

	/* post: devuelve el nombre del Foro.
	 */
	string obtenerNombre();

	/* post: devuelve todos los Mensajes del Foro.
	 */
	Lista<Mensaje*>* obtenerMensajes();

	/* post: devuelve las temáticas del Foro
	 */
	Lista<string>* obtenerTematicas();

};


class Moderador {
public:
	/*
	 * pre: completar
	 * post: busca en la lista 'foros' el Mensaje más votado del autor 'usuarioBuscado' dentro de un Foro que incluya la
	 *       temática 'tematicaBuscada'.
	 */
	Mensaje* buscarMensajeMasVotadoDelUsuarioSegunTematica(
								Lista<Foro*>* foros,
								string usuarioBuscado,
								string tematicaBuscada) {
		//Validar
		Mensaje * resultado = NULL;
		foros->iniciarCursor();
		while(foros->avanzarCursor()) {
			Foro * foro = foros->obtenerCursor();
			if (tieneLaTematica(foro->obtenerTematicas(), tematicaBuscada)) {
				Lista<Mensaje *> * mensajes = buscarMensajesDeUsuario(foro, usuarioBuscado);
				resultado = buscarMasVotado(resultado, mensajes);
			}
		}
		return resultado;
	}
};


