
//#include <iostream>

#include <iostream>
#include <string>

#include "Cola.h"
#include "Lista.h"

using namespace std;

class Producto {

public:

	/* post: Producto con el nombre y la categoría
	 *	indicados.
	 */
	Producto(string nombre, string categoria)

/* post: devuelve el nombre del Producto.
 */
	string obtenerNombre();

	/* post: devuelve la categoría del Producto.
	 */
	string obtenerCategoria();
};

class Sucursal {

public:

	Sucursal();

	/* post: devuelve las categorias de productos que vende.
	 */
	Lista<string>* obtenerCategorias();

	/* post: devuelve todos los Productos que tiene la sucursal.
	 */
	Lista<Producto*>* obtenerProductos();

	/* post: libera todos los Productos.
	 */
	~Sucursal();
};

class Distribuidor {

public:

	/**
	 * pre: categorias no puede ser nula, categoria no puede ser nula
	 * post: devuelve verdadero si categoria esta en categorias, o falso en caso contrario
	 */
	bool tieneLaCategoria(Lista<string>* categorias, string categoria) {
		if (categorias == NULL) {
			throw "Categorias no puede ser NULO";
		}
		if (categoria == NULL) {
			throw "Categoria no puede ser NULO";
		}
		categorias->iniciarCursor();
		while (categorias->avanzarCursor()) {
			string categoriaActual = categorias->obtenerCursor();
			if (categoriaActual == categoria) {
				return true;
			}
		}
		return false;
	}

	/*
	 * pre: producto no puede ser NULO, sucursalesExistentes no puede ser NULA.
	 * post: devuelve verdadero si se pudo agregar el producto a alguna sucursal (si coincide la categoria) o
	 *       falso en caso contrario.
	 */
	bool distribuirProductoEnSucursales(Producto* producto, Lista<Sucursal*>* sucursalesExistentes) {
		if (producto == NULL) {
			throw "Producto no puede ser NULO";
		}
		if (sucursalesExistentes == NULL) {
			throw "Sucursales no puede ser NULO";
		}

		sucursalesExistentes->iniciarCursor();
		while( sucursalesExistentes->avanzarCursor()) {
			Sucursal * sucursal = sucursalesExistentes->obtenerCursor();
			if (this->tieneLaCategoria(sucursal->obtenerCategorias(), producto->obtenerCategoria())) {
				sucursal->obtenerProductos()->agregar(producto);
				return true;
			}
		}
		return false;
	}

	/*
	 * pre: productosDisponibles no puede ser NULO, sucursalesExistentes no puede ser NULO
	 * post: remueve los Productos de la cola ‘productosDisponibles’ y los agrega a alguna Sucursal de
	 *	‘sucursalesExistentes’ que tenga la categoria del Producto.
	 *	Aquellos Productos que no pueden ser agregados a ninguna Sucursal se devuelven a la cola
	 *	‘productosDisponibles’.
	 */
	void distribuirProductosEnSucursales(Cola<Producto*>* productosDisponibles,
										 Lista<Sucursal*>* sucursalesExistentes) {
		if (productosDisponibles == NULL) {
			throw "Productos no puede ser NULO";
		}
		if (sucursalesExistentes == NULL) {
			throw "Sucursales no puede ser NULO";
		}

		if (!sucursalesExistentes->estaVacia()) {
			Cola<Producto*>* colaTemporal = new Cola<Producto *>();
			while (!productosDisponibles->estaVacia()) {
				Producto * producto = productosDisponibles->desacolar();
				if (!this->distribuirProductoEnSucursales(producto, sucursalesExistentes)) {
					colaTemporal->acolar(producto);
				}
			}
			productosDisponibles->acolarTodos(colaTemporal);
			delete colaTemporal;
		}
	}
};



int main(){
	string miTexto = NULL;
	cout << miTexto << endl;
}


