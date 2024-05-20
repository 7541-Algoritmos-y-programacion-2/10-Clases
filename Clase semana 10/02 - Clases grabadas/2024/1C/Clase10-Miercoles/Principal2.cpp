/*
 * Principal2.cpp
 *
 *  Created on: 15/05/2024
 *      Author: algo2
 */

//#include <iostream>
#include <string>
#include "Lista.h"
using namespace std;


class Categoria {
public:
	/* post: inicializa la categoria con el nombre y la * descripciÃ³n indicadas.
	 */
	Categoria(string nombre, string descripcion); /* post: devuelve el nombre que la identifica. */
	string getNombre();
	/* post: devuelve la descripciÃ³n de la categoria. */
	string getDescripcion();
};

class Noticia {
public:

	/* post: inicializa la noticia con el título y cuerpo
	 * indicados, sin categorias asociadas.
	 */
	Noticia(string titulo, string cuerpo);
	/* post: devuelve el título de la noticia.
	 */
	string getTitulo();
	/* post: devuelve el cuerpo de la noticia.
	 */
	string getCuerpo();
	/* post: devuelve las categorias asociadas a la noticia. */
	Lista<Categoria*>* getCategorias();
};

class BuscadorDeNoticias {
public:
	/*
	 * pre:
	 * post: busca en noticias aquellas Noticias que tengan asociada alguna de las categorÃ­as dadas en conCategorias y que en el resultado no se repitan categorÃ­as en las diferentes noticias
	 * */
	Lista<Noticia*>* buscarNoticias(
					Lista<Noticia*>* noticias,
					Lista<Categoria*>* conCategorias) {
		//VALIDAR
		Lista<Noticia*>* resultado = new Lista<Noticia*>();
		noticias->iniciarCursor();
		while(noticias->avanzarCursor()) {
			Noticia * noticia = noticias->obtenerCursor();
			if (tieneAlgunaCategoria(noticia, conCategorias) &&
				!coincidenCategorias(noticia, resultado)) {
				resultado->agregar(noticia);
			}
		}
		return resultado;
	}
};
