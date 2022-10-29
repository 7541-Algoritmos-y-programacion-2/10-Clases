
//#include <iostream>
#include <string>

#include "Lista.h"

using namespace std;

class Categoria {

  public:
    /* post: inicializa la categoria con el nombre y la
     *       descripción indicadas.
     */
    Categoria(string nombre, string descripcion);
    /* post: devuelve el nombre que la identifica.
     */
    string getNombre();
    /* post: devuelve la descripción de la categoria.
     */
    string getDescripcion();

    bool esIgual(Categoria * categoria) {
    	return this->getNombre() == categoria->getNombre();
    }
};


class Noticia {

  public:
    /* post: inicializa la noticia con el título y cuerpo
     *       indicados, sin categorias asociadas.
     */
    Noticia(string titulo, string cuerpo);
    /* post: devuelve el título de la noticia.
     */
    string getTitulo();
    /* post: devuelve el cuerpo de la noticia.
     */
    string getCuerpo();
    /* post: devuelve las categorias asociadas a la noticia.
     */
    Lista<Categoria*>* getCategorias();
};


class BuscadorDeNoticias {

  private:
	/**
	 * pre: -
	 * post: tira error si la noticia es vacia
	 */
	void validar(Noticia * noticia) {
		if (noticia == NULL) {
			throw "La noticia no puede ser vacia";
		}
	}

	/**
	 * pre: -
	 * post: tira error si la lista es NULL
	 */
	void validar(Lista<Categoria*>* categorias) {
		if (categorias == NULL) {
			throw "Las categorias no puede ser vacia";
		}
	}

  public:

	/**
	 * pre:
	 * post:
	 */
	bool contieneCategoriasCoincidentes(Noticia * noticia, Lista<Categoria*>* categorias, int cantidadMinimaAContener) {
		validar(noticia);
		validar(categorias);

		int contador = 0;
		noticia->getCategorias()->iniciarCursor();
		while(noticia->getCategorias()->avanzarCursor()) {
			Categoria * categoria = noticia->getCategorias()->obtenerCursor();
			if (contieneCategoria(categorias, categoria)) {
				contador++;
				if (contador >= cantidadMinimaAContener) {
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * pre: categorias no puede ser vacia ni categoriaABuscar
	 * pos: devuelve verdadero si categoriaABuscar esta en la lista
	 */
	bool contieneCategoria(Lista<Categoria*>* categorias, Categoria * categoriaABuscar) {
		validar(categorias);
		if (categoriaABuscar == NULL) {
			throw "CategoriaABuscar no puede ser vacio";
		}
		if (!categorias->estaVacia()) {
			categorias->iniciarCursor();
			while (categorias->avanzarCursor()) {
				Categoria * categoria = categorias->obtenerCursor();
				if (categoria->esIgual(categoriaABuscar)) {
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * pre: noticia no puede ser vacia ni categorias.
	 * pos: devuelve verdaderos si alguna categoria de noticia existe en categorias
	 */
	bool contieneAlgunaCategoria(Noticia * noticia, Lista<Categoria*>* categorias) {
		validar(noticia);
		if (categorias == NULL) {
			throw "Categorias no puede ser vacia";
		}
		if (!categorias->estaVacia()) {
			noticia->getCategorias()->iniciarCursor();
			while(noticia->getCategorias()->avanzarCursor()) {
				Categoria* categoria = noticia->getCategorias()->obtenerCursor();
				if (contieneCategoria(categorias, categoria)) {
				//if (categorias->contiene(categoria)) {
					return true;
				}
			}
		}
		return false;
	}

    /* post: busca en noticias aquellas Noticias que tengan asociada al menos 2 categorías dadas en conCategorias y
     *  que NO contengan ninguna de las categorías de sinCategorias,
     *  teniendo un mínimo de categorías
     *  Devuelve una nueva Lista con todas las Noticias encontradas. */
    Lista<Noticia*>* buscarNoticias(Lista<Noticia*>* noticias,
    								Lista<Categoria*>* conCategorias,
    								Lista<Categoria*>* sinCategorias,
    								int cantidadMinimaDeCategorias) {
    	if (noticias == NULL) {
    		throw "Noticias no puede ser vacio";
    	}
    	if ((conCategorias == NULL) ||
    		(conCategorias->contarElementos() < 2)) {
    		throw "conCategorias debe tener por lo menos 2 categorias";
    	}
    	if (sinCategorias == NULL) {
    		sinCategorias = new Lista<Categoria*>();
    	}

    	Lista<Noticia*> * resultado = new Lista<Noticia *>();
    	noticias->iniciarCursor();
    	while (noticias->avanzarCursor()) {
    		Noticia * noticia = noticias->obtenerCursor();
    		if ((noticia->getCategorias()->contarElementos() >= cantidadMinimaDeCategorias) &&
    		   (!contieneAlgunaCategoria(noticia, sinCategorias)) &&
    		   (contieneCategoriasCoincidentes(noticia, conCategorias, 2)) {
    			resultado->agregar(noticia);
    		}
    	}
    	return resultado;
    }
};




class IngenieroQuimico {

	bool tieneCompuestosEquivalentes(Solucion *solucionRequerida, Solucion *solucion, int minimo, int maximo) {
		solucionRequerida->getCompuestos()->iniciarCursor();
		while (solucionRequerida->getCompuestos()->avanzarCursor()) {
			Compuesto * compuesto1 = solucionRequerida->getCompuestos()->obtenerCursor();
			Compuesto * compuesto2 = obtenerElCompuestoSiExiste(solucion, compuesto1);
			if (compuesto2 != NULL) {
				if (!esCompuestoEquivalente(compuesto1, compuesto2, minimo, maximo)) {
					return false;
				}
			}
		}
		return true;
	}

	Lista<Solucion *> * buscarSolucionEquivalente(Solucion * solucionRequerida, Lista<Solucion *> * solucionesEquivalentes) {

		Lista<Solucion *> * resultado = new Lista<Solucion *>();
		solucionesEquivalentes->iniciarCursor();
    	while (solucionesEquivalentes->avanzarCursor()) {
    		Solucion * solucion = solucionesEquivalentes->obtenerCursor();
    		if ((solucion->getCompuestos()->contarElementos() == solucionRequerida->getCompuestos()->contarElementos()) &&
    		   (tieneCompuestosEquivalentes(solucionRequerida, solucion, 1, 2))) {
    			resultado->agregar(solucion);
    		}
    	}
	}

};






int main(){

}


